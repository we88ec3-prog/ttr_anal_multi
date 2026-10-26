
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00588770(int param_1)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  undefined4 uVar4;
  short *psVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  short *psVar10;
  undefined **local_268 [2];
  undefined4 *local_260;
  undefined **local_254;
  int local_250;
  int local_24c;
  undefined4 local_248;
  int local_240 [2];
  undefined4 *local_238;
  undefined4 local_234;
  undefined4 local_224;
  uint local_220;
  WCHAR local_218 [256];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092941f;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  FUN_00771420(local_268);
  local_8 = 0;
  local_240[0] = 0xd;
  FUN_0082ef00(local_240);
  if ((local_238 == local_260) || (psVar10 = (short *)local_238[4], psVar10 == (short *)0x0)) {
                    /* WARNING: Subroutine does not return */
    FUN_006edc70("Cannot find specified locale!",uVar2);
  }
  local_220 = 7;
  local_224 = 0;
  local_234 = (uint)local_234._2_2_ << 0x10;
  FUN_00402160(L"UI/Font/",8);
  local_8 = CONCAT31(local_8._1_3_,1);
  psVar5 = psVar10;
  if (7 < *(uint *)(psVar10 + 10)) {
    psVar5 = *(short **)psVar10;
  }
  psVar3 = psVar5;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  FUN_00404300(psVar5,(int)psVar3 - (int)(psVar5 + 1) >> 1);
  FUN_00404300(L".FFT",4);
  FUN_00770a80(*(undefined4 *)(param_1 + 0x30));
  if (7 < local_220) {
    FUN_0089120c(local_234);
  }
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x18) = 0xd;
  local_238 = _malloc(0x84);
  local_8._0_1_ = 2;
  if (local_238 == (undefined4 *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00772ca0(local_238);
  }
  local_8._0_1_ = 0;
  FUN_00770be0(uVar4);
  local_220 = 7;
  local_224 = 0;
  local_234 = local_234 & 0xffff0000;
  FUN_00402160(L"UI/StringTable/",0xf);
  local_8._0_1_ = 3;
  if (7 < *(uint *)(psVar10 + 10)) {
    psVar10 = *(short **)psVar10;
  }
  psVar5 = psVar10;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00404300(psVar10,(int)psVar5 - (int)(psVar10 + 1) >> 1);
  FUN_00404300(L".FCS",4);
  FUN_0075f030(*(undefined4 *)(param_1 + 0x34));
  local_8._0_1_ = 0;
  if (7 < local_220) {
    FUN_0089120c(local_234);
  }
  iVar7 = *(int *)(param_1 + 0x34);
  *(undefined4 *)(iVar7 + 0x14) = 0xd;
  local_238 = (undefined4 *)0xd;
  FUN_0082ef00(&local_238);
  if (local_240[0] == *(int *)(iVar7 + 8)) {
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined4 *)(local_240[0] + 0x10);
  }
  uVar2 = DAT_00f94394 & 1;
  *(undefined4 *)(iVar7 + 0x18) = uVar4;
  if (uVar2 == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8._0_1_ = 4;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8._0_1_ = 0;
  }
  FUN_005c4770(&DAT_00f94398);
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8._0_1_ = 5;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8._0_1_ = 0;
  }
  FUN_005c5830(&DAT_00f94398);
  puVar6 = (undefined4 *)FUN_00891268(0x28);
  if (puVar6 != (undefined4 *)0x0) {
    puVar6[1] = 0;
    *puVar6 = FUI::CIMECompositionType1::vftable;
    puVar6[7] = 7;
    puVar6[6] = 0;
    *(undefined2 *)(puVar6 + 2) = 0;
  }
  FUN_005cac30(*(undefined4 *)(param_1 + 0x38),0);
  puVar6 = (undefined4 *)FUN_00891268(8);
  if (puVar6 != (undefined4 *)0x0) {
    puVar6[1] = 0;
    *puVar6 = FUI::CIMECompositionType2::vftable;
  }
  FUN_005cac30(*(undefined4 *)(param_1 + 0x38),1);
  FUN_007710d0(*(undefined4 *)(param_1 + 0x28));
  iVar7 = *(int *)(param_1 + 0x28);
  local_238 = (undefined4 *)0x0;
  FUN_0082ef00(&local_238);
  if (local_240[0] == *(int *)(iVar7 + 8)) {
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined4 *)(local_240[0] + 0x10);
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8._0_1_ = 6;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  local_250 = 0;
  local_24c = 0;
  local_248 = 0;
  local_254 = FUI::CFXUIBinder::vftable;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  _DAT_00f95cd4 = uVar4;
  puVar6 = _malloc(0xf4);
  local_8._0_1_ = 9;
  local_238 = puVar6;
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    FUN_007564e0();
    puVar6[0x3b] = 0;
    *(undefined1 *)(puVar6 + 0x3c) = 0;
    *puVar6 = FUI::CMsgBoxWait::vftable;
  }
  local_8 = CONCAT31(local_8._1_3_,8);
  iVar7 = FUN_0058c9e0(199,puVar6);
  if (iVar7 == 0) {
    uVar4 = (*(code *)local_254[7])(199);
    FUN_0040aeb0(L"Can\'t Load Resource : [%d] %s",199,uVar4);
    MessageBoxW((HWND)0x0,local_218,L"Error",0);
  }
  puVar6 = _malloc(0xf4);
  local_8._0_1_ = 10;
  local_238 = puVar6;
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    FUN_007564e0();
    puVar6[0x3b] = 0;
    *(undefined1 *)(puVar6 + 0x3c) = 0;
    *puVar6 = FUI::CMsgBoxWaitAndEnableChat::vftable;
  }
  local_8 = CONCAT31(local_8._1_3_,8);
  iVar7 = FUN_0058c9e0(200,puVar6);
  if (iVar7 == 0) {
    uVar4 = (*(code *)local_254[7])(200);
    FUN_0040aeb0(L"Can\'t Load Resource : [%d] %s",200,uVar4);
    MessageBoxW((HWND)0x0,local_218,L"Error",0);
  }
  local_238 = _malloc(0x104);
  local_8._0_1_ = 0xb;
  if (local_238 == (undefined4 *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00585f40();
  }
  local_8 = CONCAT31(local_8._1_3_,8);
  iVar7 = FUN_0058c9e0(0xc9,uVar4);
  if (iVar7 == 0) {
    uVar4 = (*(code *)local_254[7])(0xc9);
    FUN_0040aeb0(L"Can\'t Load Resource : [%d] %s",0xc9,uVar4);
    MessageBoxW((HWND)0x0,local_218,L"Error",0);
  }
  puVar6 = _malloc(0xf4);
  local_8._0_1_ = 0xc;
  local_238 = puVar6;
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    FUN_007564e0();
    puVar6[0x3b] = 0;
    *(undefined1 *)(puVar6 + 0x3c) = 0;
    *puVar6 = FUI::CMsgBoxOk::vftable;
  }
  local_8 = CONCAT31(local_8._1_3_,8);
  iVar7 = FUN_0058c9e0(0xca,puVar6);
  if (iVar7 == 0) {
    uVar4 = (*(code *)local_254[7])(0xca);
    FUN_0040aeb0(L"Can\'t Load Resource : [%d] %s",0xca,uVar4);
    MessageBoxW((HWND)0x0,local_218,L"Error",0);
  }
  puVar6 = _malloc(0xf4);
  local_8._0_1_ = 0xd;
  local_238 = puVar6;
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    FUN_007564e0();
    puVar6[0x3b] = 0;
    *(undefined1 *)(puVar6 + 0x3c) = 0;
    *puVar6 = FUI::CMsgBoxCancel::vftable;
  }
  local_8 = CONCAT31(local_8._1_3_,8);
  iVar7 = FUN_0058c9e0(0xcb,puVar6);
  if (iVar7 == 0) {
    uVar4 = (*(code *)local_254[7])(0xcb);
    FUN_0040aeb0(L"Can\'t Load Resource : [%d] %s",0xcb,uVar4);
    MessageBoxW((HWND)0x0,local_218,L"Error",0);
  }
  puVar6 = _malloc(0xf4);
  local_8._0_1_ = 0xe;
  local_238 = puVar6;
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    FUN_007564e0();
    puVar6[0x3b] = 0;
    *(undefined1 *)(puVar6 + 0x3c) = 0;
    *puVar6 = FUI::CMsgBoxOkCancel::vftable;
  }
  local_8 = CONCAT31(local_8._1_3_,8);
  iVar7 = FUN_0058c9e0(0xcc,puVar6);
  if (iVar7 == 0) {
    uVar4 = (*(code *)local_254[7])(0xcc);
    FUN_0040aeb0(L"Can\'t Load Resource : [%d] %s",0xcc,uVar4);
    MessageBoxW((HWND)0x0,local_218,L"Error",0);
  }
  puVar6 = _malloc(0xf4);
  local_8._0_1_ = 0xf;
  local_238 = puVar6;
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    FUN_007564e0();
    puVar6[0x3b] = 0;
    *(undefined1 *)(puVar6 + 0x3c) = 0;
    *puVar6 = FUI::CMsgBoxYes::vftable;
  }
  local_8 = CONCAT31(local_8._1_3_,8);
  iVar7 = FUN_0058c9e0(0xcd,puVar6);
  if (iVar7 == 0) {
    uVar4 = (*(code *)local_254[7])(0xcd);
    FUN_0040aeb0(L"Can\'t Load Resource : [%d] %s",0xcd,uVar4);
    MessageBoxW((HWND)0x0,local_218,L"Error",0);
  }
  puVar6 = _malloc(0xf4);
  local_8._0_1_ = 0x10;
  local_238 = puVar6;
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    FUN_007564e0();
    puVar6[0x3b] = 0;
    *(undefined1 *)(puVar6 + 0x3c) = 0;
    *puVar6 = FUI::CMsgBoxNo::vftable;
  }
  local_8 = CONCAT31(local_8._1_3_,8);
  iVar7 = FUN_0058c9e0(0xce,puVar6);
  if (iVar7 == 0) {
    uVar4 = (*(code *)local_254[7])(0xce);
    FUN_0040aeb0(L"Can\'t Load Resource : [%d] %s",0xce,uVar4);
    MessageBoxW((HWND)0x0,local_218,L"Error",0);
  }
  puVar6 = _malloc(0xf4);
  local_8._0_1_ = 0x11;
  local_238 = puVar6;
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    FUN_007564e0();
    puVar6[0x3b] = 0;
    *(undefined1 *)(puVar6 + 0x3c) = 0;
    *puVar6 = FUI::CMsgBoxYesNo::vftable;
  }
  local_8 = CONCAT31(local_8._1_3_,8);
  iVar7 = FUN_0058c9e0(0xcf,puVar6);
  if (iVar7 == 0) {
    uVar4 = (*(code *)local_254[7])(0xcf);
    FUN_0040aeb0(L"Can\'t Load Resource : [%d] %s",0xcf,uVar4);
    MessageBoxW((HWND)0x0,local_218,L"Error",0);
  }
  puVar6 = _malloc(0xf4);
  local_8._0_1_ = 0x12;
  local_238 = puVar6;
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    FUN_007564e0();
    puVar6[0x3b] = 0;
    *(undefined1 *)(puVar6 + 0x3c) = 0;
    *puVar6 = FUI::CMsgBoxYesNoAndEnableChat::vftable;
  }
  local_8 = CONCAT31(local_8._1_3_,8);
  iVar7 = FUN_0058c9e0(0xd0,puVar6);
  if (iVar7 == 0) {
    uVar4 = (*(code *)local_254[7])(0xd0);
    FUN_0040aeb0(L"Can\'t Load Resource : [%d] %s",0xd0,uVar4);
    MessageBoxW((HWND)0x0,local_218,L"Error",0);
  }
  puVar6 = _malloc(0xf4);
  local_8._0_1_ = 0x13;
  local_238 = puVar6;
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    FUN_007564e0();
    puVar6[0x3b] = 0;
    *(undefined1 *)(puVar6 + 0x3c) = 0;
    *puVar6 = FUI::CMsgBoxYesNoNotKey::vftable;
  }
  local_8 = CONCAT31(local_8._1_3_,8);
  iVar7 = FUN_0058c9e0(0xd1,puVar6);
  if (iVar7 == 0) {
    uVar4 = (*(code *)local_254[7])(0xd1);
    FUN_0040aeb0(L"Can\'t Load Resource : [%d] %s",0xd1,uVar4);
    MessageBoxW((HWND)0x0,local_218,L"Error",0);
  }
  FUN_0040b670(0);
  uVar8 = local_24c - local_250 >> 2;
  uVar2 = 0;
  puVar6 = (undefined4 *)0x0;
  if (uVar8 != 0) {
    do {
      if ((*(int *)(local_250 + uVar2 * 4) != 0) &&
         (puVar6 = *(undefined4 **)(local_250 + uVar2 * 4), puVar6[8] == 199)) break;
      uVar2 = uVar2 + 1;
      puVar6 = (undefined4 *)0x0;
    } while (uVar2 < uVar8);
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8._0_1_ = 0x14;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = CONCAT31(local_8._1_3_,8);
  }
  iVar7 = local_250;
  local_238 = (undefined4 *)0xc7;
  FUN_0082ef00(&local_238);
  if (local_240[0] == DAT_00f95c24) {
    local_240[1] = 199;
    local_238 = puVar6;
    uVar4 = FUN_0057ef20();
    FUN_0082f200(&DAT_00f95c20,uVar4);
    iVar7 = local_250;
  }
  uVar8 = local_24c - iVar7 >> 2;
  uVar2 = 0;
  if (uVar8 != 0) {
    do {
      if ((*(int *)(iVar7 + uVar2 * 4) != 0) &&
         (puVar6 = *(undefined4 **)(iVar7 + uVar2 * 4), puVar6[8] == 200)) goto LAB_0058923f;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar8);
  }
  puVar6 = (undefined4 *)0x0;
LAB_0058923f:
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8._0_1_ = 0x15;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = CONCAT31(local_8._1_3_,8);
    iVar7 = local_250;
  }
  local_238 = (undefined4 *)0xc8;
  FUN_0082ef00(&local_238);
  if (local_240[0] == DAT_00f95c24) {
    local_240[1] = 200;
    local_238 = puVar6;
    uVar4 = FUN_0057ef20();
    FUN_0082f200(&DAT_00f95c20,uVar4);
    iVar7 = local_250;
  }
  uVar8 = local_24c - iVar7 >> 2;
  uVar2 = 0;
  if (uVar8 != 0) {
    do {
      if ((*(int *)(iVar7 + uVar2 * 4) != 0) &&
         (puVar6 = *(undefined4 **)(iVar7 + uVar2 * 4), puVar6[8] == 0xc9)) goto LAB_005892f9;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar8);
  }
  puVar6 = (undefined4 *)0x0;
LAB_005892f9:
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8._0_1_ = 0x16;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = CONCAT31(local_8._1_3_,8);
    iVar7 = local_250;
  }
  local_238 = (undefined4 *)0xc9;
  FUN_0082ef00(&local_238);
  if (local_240[0] == DAT_00f95c24) {
    local_240[1] = 0xc9;
    local_238 = puVar6;
    uVar4 = FUN_0057ef20();
    FUN_0082f200(&DAT_00f95c20,uVar4);
    iVar7 = local_250;
  }
  uVar8 = local_24c - iVar7 >> 2;
  uVar2 = 0;
  if (uVar8 != 0) {
    do {
      if ((*(int *)(iVar7 + uVar2 * 4) != 0) &&
         (puVar6 = *(undefined4 **)(iVar7 + uVar2 * 4), puVar6[8] == 0xca)) goto LAB_005893b9;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar8);
  }
  puVar6 = (undefined4 *)0x0;
LAB_005893b9:
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8._0_1_ = 0x17;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = CONCAT31(local_8._1_3_,8);
    iVar7 = local_250;
  }
  local_238 = (undefined4 *)0xca;
  FUN_0082ef00(&local_238);
  if (local_240[0] == DAT_00f95c24) {
    local_240[1] = 0xca;
    local_238 = puVar6;
    uVar4 = FUN_0057ef20();
    FUN_0082f200(&DAT_00f95c20,uVar4);
    iVar7 = local_250;
  }
  uVar8 = local_24c - iVar7 >> 2;
  uVar2 = 0;
  if (uVar8 != 0) {
    do {
      if ((*(int *)(iVar7 + uVar2 * 4) != 0) &&
         (puVar6 = *(undefined4 **)(iVar7 + uVar2 * 4), puVar6[8] == 0xcb)) goto LAB_00589479;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar8);
  }
  puVar6 = (undefined4 *)0x0;
LAB_00589479:
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8._0_1_ = 0x18;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = CONCAT31(local_8._1_3_,8);
    iVar7 = local_250;
  }
  local_238 = (undefined4 *)0xcb;
  FUN_0082ef00(&local_238);
  if (local_240[0] == DAT_00f95c24) {
    local_240[1] = 0xcb;
    local_238 = puVar6;
    uVar4 = FUN_0057ef20();
    FUN_0082f200(&DAT_00f95c20,uVar4);
    iVar7 = local_250;
  }
  uVar8 = local_24c - iVar7 >> 2;
  uVar2 = 0;
  if (uVar8 != 0) {
    do {
      if ((*(int *)(iVar7 + uVar2 * 4) != 0) &&
         (puVar6 = *(undefined4 **)(iVar7 + uVar2 * 4), puVar6[8] == 0xcc)) goto LAB_00589539;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar8);
  }
  puVar6 = (undefined4 *)0x0;
LAB_00589539:
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8._0_1_ = 0x19;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = CONCAT31(local_8._1_3_,8);
    iVar7 = local_250;
  }
  local_238 = (undefined4 *)0xcc;
  FUN_0082ef00(&local_238);
  if (local_240[0] == DAT_00f95c24) {
    local_240[1] = 0xcc;
    local_238 = puVar6;
    uVar4 = FUN_0057ef20();
    FUN_0082f200(&DAT_00f95c20,uVar4);
    iVar7 = local_250;
  }
  uVar8 = local_24c - iVar7 >> 2;
  uVar2 = 0;
  if (uVar8 != 0) {
    do {
      if ((*(int *)(iVar7 + uVar2 * 4) != 0) &&
         (puVar6 = *(undefined4 **)(iVar7 + uVar2 * 4), puVar6[8] == 0xcd)) goto LAB_005895f9;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar8);
  }
  puVar6 = (undefined4 *)0x0;
LAB_005895f9:
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8._0_1_ = 0x1a;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = CONCAT31(local_8._1_3_,8);
    iVar7 = local_250;
  }
  local_238 = (undefined4 *)0xcd;
  FUN_0082ef00(&local_238);
  if (local_240[0] == DAT_00f95c24) {
    local_240[1] = 0xcd;
    local_238 = puVar6;
    uVar4 = FUN_0057ef20();
    FUN_0082f200(&DAT_00f95c20,uVar4);
    iVar7 = local_250;
  }
  uVar8 = local_24c - iVar7 >> 2;
  uVar2 = 0;
  if (uVar8 != 0) {
    do {
      if ((*(int *)(iVar7 + uVar2 * 4) != 0) &&
         (puVar6 = *(undefined4 **)(iVar7 + uVar2 * 4), puVar6[8] == 0xca)) goto LAB_005896b5;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar8);
  }
  puVar6 = (undefined4 *)0x0;
LAB_005896b5:
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8._0_1_ = 0x1b;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = CONCAT31(local_8._1_3_,8);
    iVar7 = local_250;
  }
  local_238 = (undefined4 *)0xce;
  FUN_0082ef00(&local_238);
  if (local_240[0] == DAT_00f95c24) {
    local_240[1] = 0xce;
    local_238 = puVar6;
    uVar4 = FUN_0057ef20();
    FUN_0082f200(&DAT_00f95c20,uVar4);
    iVar7 = local_250;
  }
  uVar8 = local_24c - iVar7 >> 2;
  uVar2 = 0;
  if (uVar8 != 0) {
    do {
      if ((*(int *)(iVar7 + uVar2 * 4) != 0) &&
         (puVar6 = *(undefined4 **)(iVar7 + uVar2 * 4), puVar6[8] == 0xcf)) goto LAB_00589779;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar8);
  }
  puVar6 = (undefined4 *)0x0;
LAB_00589779:
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8._0_1_ = 0x1c;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = CONCAT31(local_8._1_3_,8);
    iVar7 = local_250;
  }
  local_238 = (undefined4 *)0xcf;
  FUN_0082ef00(&local_238);
  if (local_240[0] == DAT_00f95c24) {
    local_240[1] = 0xcf;
    local_238 = puVar6;
    uVar4 = FUN_0057ef20();
    FUN_0082f200(&DAT_00f95c20,uVar4);
    iVar7 = local_250;
  }
  uVar8 = local_24c - iVar7 >> 2;
  uVar2 = 0;
  if (uVar8 != 0) {
    do {
      if ((*(int *)(iVar7 + uVar2 * 4) != 0) &&
         (puVar6 = *(undefined4 **)(iVar7 + uVar2 * 4), puVar6[8] == 0xd0)) goto LAB_00589830;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar8);
  }
  puVar6 = (undefined4 *)0x0;
LAB_00589830:
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8._0_1_ = 0x1d;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = CONCAT31(local_8._1_3_,8);
    iVar7 = local_250;
  }
  iVar9 = local_24c;
  local_238 = (undefined4 *)0xd0;
  FUN_0082ef00(&local_238);
  if (local_240[0] == DAT_00f95c24) {
    local_240[1] = 0xd0;
    local_238 = puVar6;
    uVar4 = FUN_0057ef20();
    FUN_0082f200(&DAT_00f95c20,uVar4);
    iVar9 = local_24c;
    iVar7 = local_250;
  }
  uVar8 = iVar9 - iVar7 >> 2;
  uVar2 = 0;
  if (uVar8 != 0) {
    do {
      if ((*(int *)(iVar7 + uVar2 * 4) != 0) &&
         (puVar6 = *(undefined4 **)(iVar7 + uVar2 * 4), puVar6[8] == 0xd1)) goto LAB_005898f9;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar8);
  }
  puVar6 = (undefined4 *)0x0;
LAB_005898f9:
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8._0_1_ = 0x1e;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = CONCAT31(local_8._1_3_,8);
    iVar7 = local_250;
  }
  local_238 = (undefined4 *)0xd1;
  FUN_0082ef00(&local_238);
  if (local_240[0] == DAT_00f95c24) {
    local_240[1] = 0xd1;
    local_238 = puVar6;
    uVar4 = FUN_0057ef20();
    FUN_0082f200(&DAT_00f95c20,uVar4);
    iVar7 = local_250;
  }
  local_254 = FoxUI::FXUIBinderBase::vftable;
  if (iVar7 != 0) {
    FUN_0089120c(iVar7);
  }
  local_8 = 0xffffffff;
  local_250 = 0;
  local_24c = 0;
  local_248 = 0;
  local_268[0] = FoxUI::FXUILocaleManager::vftable;
  FUN_007728b0();
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

