#!/usr/bin/env python3
"""Build a source-pinned, project-authored MEF capability taxonomy. No target execution."""
from __future__ import annotations

import argparse
import hashlib
import json
import subprocess
from collections import Counter
from pathlib import Path

BASE = '19005c9f8a8180e6f0deb00faf008a11ef98023f'
BINDINGS = 'kr-extra-roy/MEF-server-provided-capabilities-20261118/binding-offload-map.json'
PROFILES = 'kr-extra-roy/MEF-server-provided-capabilities-20261118/delivery-profiles/contracts.json'
HERE = Path(__file__).resolve().parent


def source(repo: Path, path: str):
    data = subprocess.check_output(['git', 'show', f'{BASE}:{path}'], cwd=repo)
    if (repo / path).read_bytes() != data:
        raise ValueError(f'Actual catalog input differs from pinned source: {path}')
    pin = {'commit': BASE, 'path': path,
           'git_blob': subprocess.check_output(['git', 'rev-parse', f'{BASE}:{path}'], cwd=repo).decode().strip(),
           'bytes': len(data), 'sha256': hashlib.sha256(data).hexdigest()}
    return json.loads(data), pin


def build(repo: Path):
    definitions = json.loads((HERE / 'type-definitions.json').read_text())
    bindings, binding_pin = source(repo, BINDINGS)
    profiles, profile_pin = source(repo, PROFILES)
    type_ids = {t['id'] for t in definitions['types']}
    assert len(type_ids) == len(definitions['types']) == 12
    assert set(definitions['binding_domain_primary_type']) == {d['id'] for d in bindings['domains']}
    binding_names = {r['name'] for r in bindings['records']}
    assert len(binding_names) == len(bindings['records']) == 121
    assert set(definitions['binding_name_primary_type_overrides']) <= binding_names
    routes = [
        {
            'id': 'SERVER_RULES', 'title': 'Server 執行的規則 MEF',
            'purpose': '生怪、戰鬥條件、波次、分支、機關、出口、獎勵與保存政策。',
            'status': 'EXISTING_TYPED_RUNTIME_AND_SERVICES_REUSED; NEW_RULE_EXTENSIONS_EXPLICIT',
            'condition': '沿用現有 scenario／MonsterBehavior 與服務；新語法另列編譯／adapter 工作。',
            'load_reduction': '少寫每關專用程式；事件索引等優化可減少求值；規則本身仍在 Server。'
        },
        {
            'id': 'Q_FINITE', 'title': 'Client 有限演出 MEF',
            'purpose': '一段有起點與終點的對話、鏡頭、動作、等待與既有點操作。',
            'status': next(x['status'] for x in profiles['profiles'] if x['id'] == 'Q_FINITE'),
            'condition': '選已發布內容，接受 Q 對輸入／UI 的影響；新版 seen 持久化及點換代約束照前輪補證。',
            'load_reduction': '可移走多步演出的中間計時與派送；單一點開關不保證更省。'
        },
        {
            'id': 'TUTORIAL_INTERACTIVE', 'title': 'Client 教學互動 MEF',
            'purpose': '教學提示、已映射操作與進區觀察、頁面與角色條件、串接有限演出。',
            'status': next(x['status'] for x in profiles['profiles'] if x['id'] == 'TUTORIAL_INTERACTIVE'),
            'condition': '使用真正 Tutorial field／controller／page；普通關卡不能直接套用同一觀察通路。',
            'load_reduction': '可移走已支持教學的提示監看、UI 順序及本地等待。'
        },
        {
            'id': 'NATIVE_CONTINUATION', 'title': '由 MEF 啟動的原生持續效果',
            'purpose': '已建立角色的更新，或音訊、鏡頭、圖片、淡幕等各自原生工作。',
            'status': next(x['status'] for x in profiles['profiles'] if x['id'] == 'NATIVE_CONTINUATION'),
            'condition': '每項各有 owner／gate／完成與回收條件；不是 End 後仍能任意排新 Lua 工作。',
            'load_reduction': '使用 Client 本來已有的逐幀更新，不重複在 Server 模擬；既有工作不全算本輪新增節省。'
        }
    ]
    route_ids = {r['id'] for r in routes}
    for t in definitions['types']:
        assert set(t['routes']) <= route_ids
        assert t['evidence']
    projected = []
    for r in bindings['records']:
        target = definitions['binding_name_primary_type_overrides'].get(r['name'], definitions['binding_domain_primary_type'][r['domain']])
        assert target in type_ids
        projected.append({
            'name': r['name'], 'primary_player_type': target,
            'source_domain': r['domain'], 'native': r['native'],
            'classification': r['classification'],
            'effect': r['bounded_native_effect'], 'limits': r['native_constraints'],
            'source_record': f'{BINDINGS}#{r["name"]}'
        })
    count = Counter(r['classification'] for r in projected)
    assert dict(sorted(count.items())) == dict(sorted(bindings['counts']['by_classification'].items()))
    types = []
    for t in definitions['types']:
        members = [r for r in projected if r['primary_player_type'] == t['id']]
        types.append({**t, 'primary_binding_count': len(members),
                      'binding_classifications': dict(sorted(Counter(x['classification'] for x in members).items()))})
    result = {
        'schema': 'MEF_COMPOSABLE_PLAYER_CATALOG_V1', 'base_commit': BASE,
        'classification_origin': definitions['classification_origin'],
        'types_can_be_composed': True, 'not_a_native_file_format_count': True,
        'server_development_includes_mef': True, 'official_format_recovery_required': False,
        'counts': {'player_types': 12, 'execution_routes': 4,
                   'source_native_domains': len(bindings['domains']),
                   'normal_binding_names': len(projected), 'binding_classifications': dict(sorted(count.items()))},
        'sources': [binding_pin, profile_pin],
        'execution_routes': routes,
        'optional_ordinary_background_profile': {
            **next(x for x in profiles['profiles'] if x['id'] == 'ORDINARY_BACKGROUND_B'),
            'counted_as_available_route': False,
            'latest_scope': '本輪普通 actor／技能／HP 證據不能自動補出持續 Lua producer/pump 或通用事件橋。'
        },
        'types': types, 'bindings': projected,
        'target_executed': False, 'new_server_implementation_claimed': False, 'new_deployment_claimed': False
    }
    lines = [
        '# 目前找出的 MEF 種類：用玩家功能分類', '',
        '**可整理成 12 類用途，同一份 MEF 可以組合多類。** 這是本專案依已證能力與現有 Server 服務整理的用途分類，不是宣稱原版存在 12 種不同 `.mef` 格式。Server 端執行的關卡／戰鬥／獎勵規則也屬 MEF 開發。', '',
        '## 各類負責什麼', '',
        '| 類型 | 玩家看到的用途 | 負責的工作 | 現況與界線 |',
        '|---|---|---|---|'
    ]
    for t in types:
        lines.append(f'| {t["id"]} {t["title"]} | {t["player_example"]} | {t["responsibility"]} | {t["current_capability"]} {t["limits"]} |')
    lines += ['', '## 內容在哪裡執行', '',
              '| 路線 | 負責的內容 | 適用條件 | Server 能少做什麼 |', '|---|---|---|---|']
    for r in routes:
        lines.append(f'| {r["title"]} | {r["purpose"]} | {r["condition"]} | {r["load_reduction"]} |')
    lines += ['', '**普通場景常駐 Lua 是另外一個尚未接完整的選用 profile。** 目標是在普通戰鬥保持操控時持續執行新背景腳本，仍需首次內容 producer、持續 pump、輸入 owner、取消／重入及所需事件橋。它不阻塞現有 Server 規則 MEF、有限 Q 或真正 Tutorial 路線。', '',
              '## 種類數與接口數如何理解', '',
              '- 已有來源的正常 binding 名稱共 121 個，跨 15 個技術功能域；116 個有可引用的有界作用／查詢，4 個是 stub，1 個不提供名稱暗示的 count。',
              '- 本表把這些名稱各映射到一個主要玩家用途，僅為查找；一項玩法可使用多個功能域，多個玩法也可共用同一接口。',
              '- NPC／商店、關卡分支、結算保存可透過 Server MEF 與既有服務承接；沒有直接 Client Lua binding 不代表沒有這一類 MEF 能力。',
              '- Q.CreateObject 的演出角色、lb.CreateObjectEx 的本地 world actor、Server 封包建立的戰鬥 actor 要分開。畫面數字、點光效與演出完成也不能代替 HP、碰撞或交易提交。',
              '- Q.DeleteObject、Q.BalloonTalk、Tutorial.InsertObject、lb.PrintCurrSceneID 保留 stub 判定；lb.GetObjectCount 保留無有效 count 的判定，沒有因重新分類升格。', '',
              '## 各類來源及接續工作', '']
    for t in types:
        lines += [f'### {t["id"]} {t["title"]}', '', t['remaining'], '',
                  '來源：' + '；'.join(f'[{Path(ref).name}]({ref})' for ref in t['evidence']) + '。', '']
    lines += ['機讀分類及逐 binding 的原作用／限制見 [mef-types.json](mef-types.json)。來源為固定 Git 版本；本頁可由 [build_catalog.py](build_catalog.py) 重建。分類與來源核對不代表新增 Client／Server 部署或遊玩驗收。', '']
    return result, '\n'.join(lines)


def main():
    p = argparse.ArgumentParser()
    p.add_argument('--repo', type=Path, default=HERE.parents[1])
    p.add_argument('--check', action='store_true')
    args = p.parse_args()
    catalog, markdown = build(args.repo.resolve())
    artifacts = {'mef-types.json': json.dumps(catalog, ensure_ascii=False, indent=2) + '\n', 'MEF-TYPES.md': markdown}
    for name, text in artifacts.items():
        if args.check:
            assert (HERE / name).read_text() == text, f'Derived catalog mismatch: {name}'
        else:
            (HERE / name).write_text(text)
    print(json.dumps({'status': 'PASS_COMPOSABLE_TYPE_CATALOG', **catalog['counts'],
                      'native_file_kind_count_claimed': False, 'target_executed': False}, ensure_ascii=False))


if __name__ == '__main__':
    main()
