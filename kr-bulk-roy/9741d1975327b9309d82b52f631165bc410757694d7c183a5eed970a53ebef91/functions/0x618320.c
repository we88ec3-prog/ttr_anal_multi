
void FUN_00618320(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined1 auStack_90 [8];
  undefined4 uStack_88;
  int iStack_84;
  uint *puStack_80;
  wchar_t *pwStack_7c;
  undefined1 *local_5c;
  uint auStack_58 [4];
  undefined4 uStack_48;
  uint uStack_44;
  undefined1 local_38 [20];
  uint local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093e05e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    pwStack_7c = L"쒃茄ￏ粉栤ϫ쾃诿ࡵ똏ಆ\x01茀৸⁷쁩Ȑ";
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    pwStack_7c = L"쒃褄⑼ཨ蚶Č";
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 2;
    pwStack_7c = 
    L"遨볳\xe800黗\'쒃褄⑼赨⑔刔䒍ᰤ쒹﹚윀⑄윘\x02\xe800벋\xfff5䒋ᠤԻ嫈þᅴ삃뼐\b"
    ;
    FUN_00584c40();
    pwStack_7c = 
    L"쒃褄⑼赨⑔刔䒍ᰤ쒹﹚윀⑄윘\x02\xe800벋\xfff5䒋ᠤԻ嫈þᅴ삃뼐\b";
    _atexit((_func_4879 *)&LAB_00bcf390);
  }
  local_c = 0xffffffff;
  pwStack_7c = L"䒋ᠤԻ嫈þᅴ삃뼐\b";
  FUN_005740f0();
  if (local_5c == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  pwStack_7c = L"<#FFFFFF>{0} <#FFFFA0>{1} / {2}";
  puStack_80 = (uint *)0x6184a2;
  FUN_004cf650();
  iVar1 = *(int *)(param_1 + 0xfc);
  local_c = 3;
  FUN_007578f0();
  pwStack_7c = (wchar_t *)0x7b;
  puStack_80 = (uint *)local_38;
  uStack_88 = 0x6184d0;
  iStack_84 = iVar1 + 0xe8;
  FUN_00759ed0();
  local_c = 0xffffffff;
  if (7 < local_24) {
    pwStack_7c = L"쒃謄ﲋ";
    FUN_0089120c();
  }
  (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 4;
    FUN_004e1590();
    pwStack_7c = (wchar_t *)0x618521;
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  local_5c = auStack_90;
  FUN_00412df0();
  local_c = 5;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c._0_1_ = 6;
    local_c._1_3_ = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = CONCAT31(local_c._1_3_,5);
  }
  local_5c = (undefined1 *)0x2c6;
  FUN_005740f0(&local_5c);
  if (DAT_00fe5ac8 == (undefined1 *)0x2c7) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  uVar3 = 0x2d7;
  if (7 < uRam000002eb) {
    uVar3 = uRam000002d7;
  }
  local_c = 0xffffffff;
  FUN_004796c0(uVar3);
  iVar1 = *(int *)(param_1 + 0x100);
  local_c = 7;
  FUN_007578f0();
  pwStack_7c = (wchar_t *)0x7b;
  puStack_80 = auStack_58;
  uStack_88 = 0x618600;
  iStack_84 = iVar1 + 0xe8;
  FUN_00759ed0();
  local_c = 0xffffffff;
  if (7 < uStack_44) {
    pwStack_7c = L"쒃㌄曉䲉ᰤ讋Ā";
    FUN_0089120c();
  }
  auStack_58[0] = auStack_58[0] & 0xffff0000;
  uStack_44 = 7;
  uStack_48 = 0;
  (**(code **)(**(int **)(param_1 + 0x100) + 200))();
  ExceptionList = local_14;
  return;
}

