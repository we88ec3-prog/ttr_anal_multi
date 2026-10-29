from verify import *
import difflib
V=json.loads((D/'decisions.json').read_text(encoding='utf8'))
M=json.loads((D/'claim-matrix.json').read_text(encoding='utf8'))
P=json.loads((D/'return-proposals.json').read_text(encoding='utf8'))
changes={
69:{67:lambda s:s.replace('後端 queue count gate','欄位 A0A4 的 signed >300 gate（不是已確認的 queue count）')},
70:{50:lambda s:s.replace('首 16-bit 固定欄位 `0x1A68`、次 16-bit 為原長度','首 16-bit 為原長度、次 16-bit 固定欄位 `0x1A68`'),
54:lambda s:s.replace('connection 內部緩衝','embedded stream（基址為 connection+0x501C）內部緩衝').replace('`[edi+0x5004]`','`[edi+0x5004]`，即 `[connection+0xA020]`；上文 `[edi+0x500C]` 為 `[connection+0xA028]`'),
80:lambda s:s.replace('connection 的 `[+0x5004]`','embedded stream（connection+0x501C）的 `[+0x5004]`').replace('更新 `[+0x500C]`、`[+0x5004]`','更新 stream `[+0x500C]`、`[+0x5004]`（即 connection+0xA028、connection+0xA020）'),
116:lambda s:s.replace('807bdd:','807bd8:'),
143:lambda s:s.replace('connection buffer +5004/+500C','embedded stream +5004/+500C = connection +A020/+A028'),
168:lambda s:s.replace('[connection+0x5004/+0x500C]','[connection+0xA020/+0xA028]')},
71:{29:lambda s:s.replace('LPWSAOVERLAPPED','LPWSABUF（connection+0xA064）；OVERLAPPED 在 0x8068F3 push eax'),
36:lambda s:s.replace('806958:','80695a:'),
52:lambda s:s.replace('0x852D48','0x84FD48'),
134:lambda s:s.replace('807dad:','807dab:')+'\n807dad: call 0x8040a0               ; actual next queue helper, not mov edi,eax'}
}
patches=[]
for q in Q:
    original=(R/q['source']).read_text(encoding='utf8');lines=original.splitlines()
    for line,fn in changes[q['number']].items():
        old=lines[line-1];new=fn(old);assert old!=new,(q['number'],line);lines[line-1]=new
    corrected='\n'.join(lines)+'\n'
    diff=''.join(difflib.unified_diff(original.splitlines(keepends=True),corrected.splitlines(keepends=True),fromfile=q['source']+' (original '+q['git_blob_sha']+')',tofile=q['source']+' (T01 proposed errata; not author replacement)'))
    path=D/f'proposed-T16-{q["number"]}.diff';path.write_text(diff,encoding='utf8')
    patches.append(dict(number=q['number'],source=q['source'],source_sha256=q['sha256'],source_git_blob=q['git_blob_sha'],proposal_file=path.name,proposed_result_sha256=hashlib.sha256(corrected.encode()).hexdigest(),proposal_status='Unapplied T01 proposal; original preserved. No corrected-author-version acceptance.'))
audit.save(D/'proposed-patches.json',dict(patches=patches))
text=['# T16 README 退回通知草案','', '本檔供主整合者更新 Task README 的退回專區；本輪未修改 Task README、原稿、catalog 或 Git。保留原作者歷史版本，收到勘誤及新版 SHA 後複驗。','']
for p in P['items']:
    no=p['number'];lines=', '.join(map(str,p['lines']))
    text += [f'### T01-RETURN-T16-{no:03d}-CONT02-{p["id"].split("-")[-1]} — NEEDS_FIX',f'- 原稿：`{p["source"]}`；Git blob `{p["git_blob_sha"]}`；SHA256 `{p["sha256"]}`。',f'- 行號：{lines}；問題：{p["issue"]}。',f'- 第一手反證與影響：{p["counterevidence"]}',f'- 修正要求：參照 `proposed-T16-{no}.diff` 的精確修改；保留其他獨立成立的原生主張。',f'- 完成條件：{p["completion_condition"]}', '- 驗收來源：本資料夾 `claim-matrix.json`、`source-block-instruction-audit.json`、`native-evidence.json`、`pe-data-and-imports.json`。','']
(D/'return-notices-draft.md').write_text('\n'.join(text),encoding='utf8')

README='''# T16-69／70／71 全文驗收（接續第 02 批）

原始三篇均已全文閱讀；20 個碼塊（含資料流圖、C++ 偽碼、ASM）及 379 條列址指令逐項核對。結果為：**69 NEEDS_QUALIFICATION；70、71 FAILED；原稿全文 FULL-PASS 0 篇**。FAILED 不表示所有內容不成立；各項支持、反證、未知與作者自述已分開保存。

## 核對範圍

- `decisions.json`：三篇精確來源 SHA／Git blob、全文與碼塊閱讀狀態及原稿決議。`all_substantive_claims_reviewed=true` 表示所有實質主張已有處置，並非全部通過；作者過往 Git 操作、工具使用及研究輪次只按作者自述記錄，未冒充二進位證據。
- `claim-matrix.json`：41 組主張及原稿行號、證據和處置。`code-block-matrix.json`：20 個碼塊的完整起訖及逐塊裁決。379 條列址指令均有逐行原件紀錄，3 條指令座標錯配；另外兩處註解／標題及 PE 映射等錯誤見退回項。
- `native-evidence.json`：30 個相關函式的根 CFG、所有正常可達指令／邊、快取 Ghidra 原文與來源批次 SHA。根 CFG 不擴張到未宣稱的 CRT、異常處理或間接目標；本輪按每項主張所需的 caller/callee、ABI、欄位和上下游核對，不以保存 CFG 本身作為通過。
- `pe-data-and-imports.json`：獨立 PE section／IAT／vtable 原始資料、BIN／EXE 身分。BD25CC 是 ordinal111 import；現有本機 x86 ws2_32.dll 的 export111 對應 WSAGetLastError，已記錄 DLL SHA；不聲稱驗證歷史 runtime DLL 載入。

## 確認需更正

1. 69 行67稱 A0A4 為 queue count gate 過度定義。真正 list size 是 A078；A0A4 在 drain 成功／失敗路徑有 ±5／清零更新。保留 `signed A0A4>300` gate，業務意義仍應限定。
2. 70 行50標題 WORD 順序倒置，應為 `[length16,1A68]`；正文與範例本來正確。行116 的 `mov edx,2633` 應在807BD8，807BDD 是 `mov dword [esp+20],4`。
3. 70 把 stream 相對欄位混作 connection 相對欄位。80620C／806234 傳入的是 `connection+501C`；framer 的 `+5004/+500C` 對應 connection `+A020/+A028`，實際 buffer 起點 `+5020`。涉及行54、80、143、168。
4. 71 行52 的 C51748 raw 應是84FD48，不是852D48；slot+C／+10／+14 的原生目標仍成立。行29 的806909 push ECX 是 WSABUF，OVERLAPPED 在8068F3 push EAX。行36 xor EAX,EAX 在80695A；行134 mov EDI,EAX 在807DAB，807DAD 是 call8040A0。

8 筆精確退回提案保存於 `return-proposals.json`／`return-notices-draft.md`。三份 `proposed-T16-*.diff` 是未套用的 T01 勘誤提案，附原稿版本及預期結果 SHA；不冒稱原作者的新稿，也未將更正版提前驗收。

## 仍成立與限制

有條件的 producer→local queue→framer→WSASend 靜態資料路徑，以及 generic WSARecv→IOCP completion→frame parser 的連結獲支持。實際發包次數、Server 實收／ACK、Quest16→Quest15、NPC 接取、UI、重登與持久化仍 unknown。804310／489920 的完整 callee 顯示是 lazy getter；原稿把它們寫為 app-level candidates，未據此驗收 Quest dispatcher，後續應沿8076F0／8040A0追查。

API 參數名稱依 [WSASend](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsasend)、[WSARecv](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsarecv) 與 [OVERLAPPED](https://learn.microsoft.com/en-us/windows/win32/api/minwinbase/ns-minwinbase-overlapped) 官方定義核對。這是靜態呼叫設定與 API 邊界，不是執行觀測。

## 重跑

使用 Python、Capstone 5.0.6，依序執行 `verify.py`、`review_records.py`、`finalize.py`、`validate.py`。`T01_TARGET` 指定原 BIN；`T01_EXE` 指定原 EXE；`T01_CAPSTONE_ROOT` 指定既有 Capstone 目錄；`T01_BULK_ROOT` 指定既有 bulk 根；`T01_WS2_DLL` 指定待核對的 x86 Windows DLL。預設路徑記於程式。共用 helper 在前批 support/audit.py，未改動。

本輪僅寫本資料夾，未執行／附加遊戲、呼叫目標 API、修改原件、原稿、Task、catalog，亦未 commit／push。其他 T16 待審篇章未擴張。日期：2026-10-29 Asia/Taipei。
'''
(D/'README.md').write_text(README,encoding='utf8')
print('saved patches and return drafts')
if __name__=='__main__':pass
