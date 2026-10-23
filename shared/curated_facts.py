"""Field/behavior level claims. Locations refer to unchanged captured source bytes."""
NATIVE=[
('T02','native-index/battle-input-transport-audit.json','/inputPacket','C2S000A前置6 bytes，row為5 bytes；F93944欄位正式語意仍未知。'),
('T08','native-index/monster-spawn-control-audit.json','/spawn','S2C0007前置2 bytes、row26 bytes；type1分支建立CMonster。這不證明波次、生成時機或AI。'),
('T08','native-index/monster-spawn-control-audit.json','/control','S2C000A有owner及actor/related欄位；控制槽登記不等於怪物決策接管。'),
('T12','native-index/battle-result-route-audit.json','/resultStride','S2C000E的row為13 bytes；這是結果消費端，未取得傷害計算公式。'),
('T12','native-index/battle-result-route-audit.json','/movementStride','S2C000B移動row為8 bytes，與000E結果row分開。'),
]
# Anchors are searched in the captured implementation, so line numbers follow this exact snapshot.
AI=[
('T04','login_protocol.py','900','初始900/900由本機fixture設定；不代表正式出生點或合法地形。'),
('T04','account_store.py','900','本機帳號預設角色、地圖與位置屬替代後端初始化。'),
('T04','new_expedition.py','BATTLE_SPAWN','固定戰鬥出生座標屬本機策略，正式座標來源未確認。'),
('T05','movement_position.py','900','初始位置與方向速度積分是服務端估計；不是客戶端位置回報，沒有碰撞驗證。'),
('T05','movement_simulation.py','Diagnostic','此模組為診斷用的服務端位移產生器，不是原生移動權威證明。'),
('T08','tutorial_battle.py','376','怪物固定位置由fixture設定；不能推論正式波次與出生資料。'),
('T08','tutorial_battle.py','60','fixture的怪物HP設定不是已確認的物種原生能力規則。'),
('T10','tutorial_skill_cast.py','CHAIN_WINDOW=.65','0.65秒連段窗口是本機實作選擇，正式連段/取消窗口仍待證據。'),
('T12','tutorial_battle.py','65','半徑45/65的命中規則屬fixture；非原生傷害/命中裁決。'),
('T13','tutorial_monster_ai.py','not','檔案自述不是官方AI/P2P還原；追逐、回家與攻擊均需隔離為替代規則。'),
('T14','tutorial_battle.py','.75','清怪後延遲完成的排程是本機策略，不能取代正式任務達成條件。'),
('T15','account_store.py','sqlite','本機SQLite持久化只證明目前替代後端的行為，不是原版伺服器存檔格式。')]
def add_claims(claims,byoriginal,source,artifacts):
    import json
    from inventory import TARGETS
    for i,(task,src,pointer,statement) in enumerate(NATIVE):
        if src not in byoriginal:continue
        obj=json.loads((source/src).read_text(encoding='utf-8-sig'));assert obj.get('sha256')==TARGETS['kr']
        value=obj
        for key in pointer.strip('/').split('/'):value=value[key]
        claims.append({'id':f'kr-native-{i:02}','version':'kr','task':task,'status':'原生已確認','statement':statement,'location':{'json_pointer':pointer,'value':value},'evidence_ids':[byoriginal[src]],'authority':'retained-native-audit; SHA checked, semantic checks not rerun this round','scope':'Only the stated field/behavior, not whole-method completeness'})
    for i,(task,src,anchor,statement) in enumerate(AI):
        if src not in byoriginal:continue
        lines=(source/src).read_text(encoding='utf-8-sig').splitlines();hits=[n+1 for n,line in enumerate(lines) if anchor.lower() in line.lower()]
        assert hits, 'Missing implementation anchor: '+src+' '+anchor
        claims.append({'id':f'kr-ai-field-{i:02}','version':'kr','task':task,'status':'AI 替代','statement':statement,'location':{'source':src,'anchor':anchor,'matching_lines':hits,'note':'Anchor is a navigation aid; read full captured source for context.'},'evidence_ids':[byoriginal[src]],'authority':'current implementation snapshot, not original game logic','scope':'specific behavior/field'})
