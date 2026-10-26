
void FUN_00615960(int param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined1 auStack_98 [4];
  undefined4 uStack_94;
  int iStack_90;
  undefined1 *puStack_8c;
  undefined1 *puStack_88;
  wchar_t *pwStack_84;
  undefined1 auStack_6c [7];
  undefined1 uStack_65;
  uint uStack_64;
  undefined1 *puStack_60;
  int local_5c;
  undefined1 auStack_58 [20];
  uint uStack_44;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093e1d8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_6c;
  ExceptionList = &local_14;
  local_5c = param_1;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90();
    pwStack_84 = 
    L"쒃위⑄ｰ\xffff诿ꐍﮧ蔀࿉悄\x02\xf600Ⰵ者Ā⩵㔉눬ú璉瀤雨\xec92棿츰¼ᛨ⟉윀⑄ｴ\xffff诿ꐍﮧ茀ӄᆋ䊋＠藐࿀Ẅ\x02\xe800阷￟උꞤûᆋ䊋＠࿐뢷\x88"
    ;
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  if (DAT_00fba7a4 != (int *)0x0) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 1;
      FUN_004dec90();
      pwStack_84 = L"䓇琤\xffff\xffffඋꞤû쒃謄謑⁂탿삅萏Ȟ";
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_c = 0xffffffff;
    iVar2 = (**(code **)(*DAT_00fba7a4 + 0x20))();
    if (iVar2 != 0) {
      FUN_0040f060();
      iVar2 = (**(code **)(*DAT_00fba7a4 + 0x20))();
      puVar4 = (undefined1 *)(uint)*(ushort *)(iVar2 + 0x88);
      puStack_60 = puVar4;
      iVar2 = FUN_00404ba0();
      if (puVar4 < (undefined1 *)0xa) {
        uStack_64 = (int)puVar4 * 0x210 + *(int *)(iVar2 + 0x6924);
        uStack_64 = -(uint)(*(int *)(uStack_64 + 0x5c) != 0) & uStack_64;
      }
      else {
        uStack_64 = 0;
      }
      uVar3 = uStack_64;
      iVar2 = FUN_00404ba0();
      if (((puVar4 < (undefined1 *)0xa) &&
          (iVar2 = *(int *)(iVar2 + 0x6924) + (int)puVar4 * 0x210, *(int *)(iVar2 + 0x5c) != 0)) &&
         (iVar2 != 0)) {
        iVar2 = iVar2 + 500;
      }
      else {
        iVar2 = 0;
      }
      if ((uVar3 != 0) && (iVar2 != 0)) {
        uStack_65 = *(undefined1 *)(uVar3 + 0xd8);
        uVar3 = 0;
        do {
          pwStack_84 = *(wchar_t **)(uStack_64 + 8);
          puStack_8c = puStack_60;
          iStack_90 = local_5c;
          uStack_94 = 0x615ae9;
          puStack_88 = (undefined1 *)uVar3;
          FUN_00615c70();
          uVar3 = uVar3 + 1;
        } while (uVar3 < 7);
        if ((DAT_00fe5ae4 & 1) == 0) {
          DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
          local_c = 2;
          pwStack_84 = 
          L"遨볳\xe800쟿\'쒃위⑄ｰ\xffff跿⑄倜䒍ᰤ쒹﹚윀⑄유\x02\xe800\xe5af\xfff5䒋ᠤࢿ"
          ;
          FUN_00584c40();
          pwStack_84 = 
          L"쒃위⑄ｰ\xffff跿⑄倜䒍ᰤ쒹﹚윀⑄유\x02\xe800\xe5af\xfff5䒋ᠤࢿ";
          _atexit((_func_4879 *)&LAB_00bcf390);
          local_c = 0xffffffff;
        }
        puStack_60 = (undefined1 *)0x2c7;
        pwStack_84 = L"䒋ᠤࢿ";
        FUN_005740f0();
        if (uStack_64 == DAT_00fe5ac8) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        pwStack_84 = L"<#FFFFFF>{0}  <#FFFFA0>{1}/{2}</#>";
        puStack_88 = (undefined1 *)0x615b79;
        FUN_004cf650();
        iVar2 = *(int *)(local_5c + 0x180);
        local_c = 3;
        FUN_007578f0();
        pwStack_84 = (wchar_t *)0x7b;
        puStack_88 = auStack_58;
        iStack_90 = 0x615ba8;
        puStack_8c = (undefined1 *)(iVar2 + 0xe8);
        FUN_00759ed0();
        local_c = 0xffffffff;
        if (7 < uStack_44) {
          pwStack_84 = L"쒃\xf604逅弄Ā╵ඃ䎐ù윁⑄Ѱ";
          FUN_0089120c();
        }
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c = 4;
          FUN_004e1590();
          pwStack_84 = (wchar_t *)0x615be9;
          _atexit((_func_4879 *)&LAB_00bccc80);
          local_c = 0xffffffff;
        }
        puStack_60 = auStack_98;
        FUN_00412df0();
        FUN_00424c80(&DAT_00bf7508);
        local_c = 5;
        pwStack_84 = L"簹堤൲䒋䐤\xe850뗍\'쒃謄⑌摨ඉ";
        FUN_00757800();
        if (7 < uStack_24) {
          pwStack_84 = L"쒃謄⑌摨ඉ";
          FUN_0089120c();
        }
      }
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_6c);
  return;
}

