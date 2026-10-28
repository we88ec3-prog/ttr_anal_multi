#!/usr/bin/env python3
"""Read-only frozen KR bulk index and referenced file integrity verifier."""
import argparse, collections, hashlib, json, pathlib, re, sys

HEX64 = re.compile(r'[0-9a-fA-F]{64}\\Z')
ADDRESS = re.compile(r'0[xX][0-9a-fA-F]+\\Z')

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
            if not isinstance(addr, str) or not ADDRESS.fullmatch(addr):
                issue(line_no, "invalid_address", value=str(addr))
                continue
            if addr in seen:
                previous_line, previous_row = seen[addr]
                issue(line_no, "duplicate_address", address=addr, previous_line=previous_line, identical=(row == previous_row))
            else:
                seen[addr] = (line_no, row)
            counts["status_" + str(row.get("status"))] += 1
            if row.get("source_sha256") != source_sha:
                issue(line_no, "source_sha_mismatch", address=addr)
            if row.get("status") != "ok":
                continue
            if "pseudocode_path" not in row:
                issue(line_no, "missing_pseudocode_reference", address=addr)
            if "batch_path" in row and "seed_evidence" in row:
                issue(line_no, "ambiguous_evidence_reference", address=addr)
            for key, digest_key, parent in (
                ("pseudocode_path", "pseudocode_sha256", base),
                ("batch_path", "batch_sha256", base),
                ("seed_evidence", "seed_evidence_sha256", root),
            ):
                if key not in row:
                    continue
                value, digest = row[key], row.get(digest_key)
                if not isinstance(value, str) or not isinstance(digest, str) or HEX64.fullmatch(digest) is None:
                    issue(line_no, "bad_reference", address=addr, field=key)
                    continue
                parent = parent.resolve()
                path = (parent / value).resolve()
                if pathlib.Path(value).is_absolute() or not path.is_relative_to(parent):
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
        "issues_total": sum(v for k,v in counts.items() if k.startswith("issue_")),
        "classification": "FILE_INTEGRITY_ONLY_NOT_SEMANTIC_OR_FULL_PASS",
    }

def main():
    p = argparse.ArgumentParser()
    p.add_argument("repository_root")
    p.add_argument("--sha", default="9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91")
    p.add_argument("--output", required=True)
    p.add_argument("--max-exceptions", type=int, default=100000)
    a = p.parse_args()
    if a.max_exceptions < 0 or not HEX64.fullmatch(a.sha):
        p.error("Invalid --max-exceptions or --sha")
    result = audit(a.repository_root, a.sha, max_exceptions=a.max_exceptions)
    pathlib.Path(a.output).write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"counts": result["counts"], "unique_addresses": result["unique_addresses"]}, ensure_ascii=False))
    return int(any(k.startswith("issue_") for k in result["counts"]))
if __name__ == "__main__":
    sys.exit(main())
