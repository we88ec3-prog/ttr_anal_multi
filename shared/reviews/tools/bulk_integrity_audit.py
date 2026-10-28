#!/usr/bin/env python3
"""Read-only frozen KR bulk index and referenced file integrity verifier."""
import argparse, collections, hashlib, json, pathlib, sys

def hash_file(path):
    h = hashlib.sha256()
    with path.open("rb") as f:
        for block in iter(lambda: f.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()

def audit(root, source_sha, max_exceptions=100000):
    root = pathlib.Path(root).resolve()
    base = root / "kr-bulk-roy" / source_sha
    counts, seen, exceptions = collections.Counter(), {}, []
    def issue(line, kind, **detail):
        counts["issue_" + kind] += 1
        if len(exceptions) < max_exceptions:
            exceptions.append(dict(line=line, kind=kind, **detail))
    with (base / "index.jsonl").open(encoding="utf-8") as stream:
        for line_no, line in enumerate(stream, 1):
            counts["lines"] += 1
            try:
                row = json.loads(line)
            except json.JSONDecodeError as error:
                issue(line_no, "invalid_json", message=str(error))
                continue
            if not isinstance(row, dict):
                issue(line_no, "non_object")
                continue
            counts["parsed_objects"] += 1
            addr = row.get("address")
            if not isinstance(addr, str):
                issue(line_no, "invalid_address", value=str(addr))
                continue
            if addr in seen:
                issue(line_no, "duplicate_address", address=addr, previous_line=seen[addr])
            else:
                seen[addr] = line_no
            counts["status_" + str(row.get("status"))] += 1
            if row.get("source_sha256") != source_sha:
                issue(line_no, "source_sha_mismatch", address=addr)
            if row.get("status") != "ok":
                continue
            for key, digest_key, parent in (
                ("pseudocode_path", "pseudocode_sha256", base),
                ("batch_path", "batch_sha256", base),
                ("seed_evidence", "seed_evidence_sha256", root),
            ):
                if key not in row:
                    continue
                value, digest = row[key], row.get(digest_key)
                if not isinstance(value, str) or not isinstance(digest, str) or len(digest) != 64:
                    issue(line_no, "bad_reference", address=addr, field=key)
                    continue
                parent = parent.resolve()
                path = (parent / value).resolve()
                if not path.is_relative_to(parent):
                    issue(line_no, "path_escape", address=addr, field=key)
                elif not path.is_file():
                    issue(line_no, "missing_file", address=addr, field=key, path=value)
                else:
                    counts["files_checked"] += 1
                    if hash_file(path) != digest.lower():
                        issue(line_no, "hash_mismatch", address=addr, field=key, path=value)
            if "batch_path" not in row and "seed_evidence" not in row:
                issue(line_no, "missing_evidence_reference", address=addr)
    return {
        "schema": "kr-bulk-integrity-audit-v1",
        "source_sha256": source_sha,
        "counts": dict(sorted(counts.items())),
        "unique_addresses": len(seen),
        "exceptions": exceptions,
        "exceptions_truncated": sum(v for k,v in counts.items() if k.startswith("issue_")) > len(exceptions),
        "classification": "FILE_INTEGRITY_ONLY_NOT_SEMANTIC_OR_FULL_PASS",
    }

def main():
    p = argparse.ArgumentParser()
    p.add_argument("repository_root")
    p.add_argument("--sha", default="9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91")
    p.add_argument("--output", required=True)
    a = p.parse_args()
    result = audit(a.repository_root, a.sha)
    pathlib.Path(a.output).write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"counts": result["counts"], "unique_addresses": result["unique_addresses"]}, ensure_ascii=False))
    return int(any(k.startswith("issue_") for k in result["counts"]))
if __name__ == "__main__":
    sys.exit(main())
