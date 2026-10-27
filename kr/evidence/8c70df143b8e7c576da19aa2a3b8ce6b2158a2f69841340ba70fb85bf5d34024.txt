
undefined4 * FUN_0048ab70(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  HDC hdc;
  int iVar5;
  int iVar6;
  byte local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093a73d;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CSingleton<CClient>::vftable;
  DAT_00fb1318 = param_1;
  local_8 = 0;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 1;
    FUN_0054f850(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  if ((0 < DAT_00fb92ba) && ((DAT_00fb8828 & 1) == 0)) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_0054f850(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_0054f850(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  if ((0 < DAT_00fb92aa) && ((DAT_00fb8828 & 1) == 0)) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_0054f850(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  FUN_006deaa0();
  puVar2 = (undefined4 *)FUN_00804380();
  param_1[0x80] = CPacketProcessor::vftable;
  local_8._0_1_ = 7;
  *puVar2 = CClient::vftable;
  *param_1 = CClient::vftable;
  param_1[2] = CClient::vftable;
  param_1[0x80] = CClient::vftable;
  param_1[0x2fd8] = 0;
  param_1[0x2fd9] = 0;
  param_1[0x2fda] = 0;
  param_1[0x2fdb] = 0;
  param_1[0x2fdc] = 100;
  param_1[0x2fdd] = 0;
  param_1[0x2fde] = 0;
  param_1[0x2fdf] = 0;
  param_1[0x2fe0] = 0;
  param_1[0x2fe1] = 0xd2;
  param_1[0x2fe2] = 0;
  param_1[0x2fe3] = 0;
  param_1[0x2fe4] = 0;
  *(undefined1 *)(param_1 + 0x2fe5) = 0;
  _memset((void *)((int)param_1 + 0xbf95),0,0x3e);
  param_1[0x2ff5] = 0;
  param_1[0x2ff6] = 1;
  param_1[0x2ff7] = 0;
  puVar2 = (undefined4 *)FUN_00891268(0x10);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
  }
  param_1[0x2ff8] = puVar2;
  iVar3 = FUN_00891268(0xc4);
  local_8._0_1_ = 8;
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_006dbbb0();
  }
  param_1[0x2ffa] = uVar4;
  param_1[0x2ffb] = 0;
  param_1[0x2ffc] = 0;
  param_1[0x2ffd] = 0;
  param_1[0x2fff] = 0;
  param_1[0x3000] = 0;
  param_1[0x3001] = 0;
  local_8._0_1_ = 10;
  param_1[0x3006] = 1;
  param_1[0x3007] = 0;
  param_1[0x3008] = 0;
  param_1[0x3009] = 0;
  FUN_006dacd0(param_1 + 0x300a);
  local_8._0_1_ = 0xb;
  hdc = GetDC((HWND)0x0);
  iVar3 = GetDeviceCaps(hdc,8);
  iVar5 = GetDeviceCaps(hdc,10);
  iVar6 = GetDeviceCaps(hdc,0xc);
  ReleaseDC((HWND)0x0,hdc);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8._0_1_ = 0xc;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8._0_1_ = 0xb;
  }
  if (0 < DAT_00fb92aa) {
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8._0_1_ = 0xd;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_8._0_1_ = 0xb;
    }
    if (0 < DAT_00fb92ba) {
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_8._0_1_ = 0xe;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_8._0_1_ = 0xb;
      }
      if (DAT_00fb92c9 != 0) goto LAB_0048afab;
    }
  }
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8._0_1_ = 0xf;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8._0_1_ = 0xb;
  }
  DAT_00fb92aa = DAT_00fb92ae;
  if ((short)iVar3 <= DAT_00fb92ae) {
    DAT_00fb92aa = (short)iVar3;
  }
  if (DAT_00fb92aa < DAT_00fb92ac) {
    DAT_00fb92aa = DAT_00fb92ac;
  }
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8._0_1_ = 0x10;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8._0_1_ = 0xb;
  }
  DAT_00fb92ba = DAT_00fb92be;
  if ((short)iVar5 <= DAT_00fb92be) {
    DAT_00fb92ba = (short)iVar5;
  }
  if (DAT_00fb92ba < DAT_00fb92bc) {
    DAT_00fb92ba = DAT_00fb92bc;
  }
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8._0_1_ = 0x11;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8._0_1_ = 0xb;
  }
  local_1c = (byte)iVar6;
  if (DAT_00fb92cb < local_1c) {
    local_1c = DAT_00fb92cb;
  }
  DAT_00fb92c9 = local_1c;
  if (local_1c < DAT_00fb92ca) {
    DAT_00fb92c9 = DAT_00fb92ca;
  }
LAB_0048afab:
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8._0_1_ = 0x12;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8._0_1_ = 0xb;
  }
  FUN_006df0e0(DAT_00fb91d1 != '\0');
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8._0_1_ = 0x13;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8._0_1_ = 0xb;
  }
  iVar3 = (int)DAT_00fb92aa;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8._0_1_ = 0x14;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8._0_1_ = 0xb;
  }
  iVar5 = (int)DAT_00fb92ba;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8._0_1_ = 0x15;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8._0_1_ = 0xb;
  }
  FUN_006dedf0(iVar3,iVar5,DAT_00fb92c9);
  DAT_00fba824 = 0;
  DAT_00fba820 = 0;
  iVar3 = FUN_00891268(0x24);
  local_8._0_1_ = 0x16;
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_006d5f10(iVar3);
  }
  local_8._0_1_ = 0xb;
  param_1[0x2ff9] = uVar4;
  iVar3 = FUN_00891268(0x28);
  local_8._0_1_ = 0x17;
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00506ad0(iVar3);
  }
  uVar1 = DAT_00fdf3d4 & 1;
  param_1[0x2fd7] = uVar4;
  if (uVar1 == 0) {
    DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
    local_8._0_1_ = 0x18;
    FUN_006f4380();
    _atexit((_func_4879 *)&LAB_00bce6d0);
  }
  local_8 = CONCAT31(local_8._1_3_,0xb);
  FUN_006f4a50("Boot.lua");
  FUN_006f4a50("Logic.lua");
  FUN_006f4a50("Coroutine.lua");
  ExceptionList = local_10;
  return param_1;
}

