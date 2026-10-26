
void FUN_00540250(int param_1)

{
  undefined3 uVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *unaff_ESI;
  int local_70;
  int local_6c;
  wchar_t local_68 [32];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0092f0b7;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[7] = 0x14;
  unaff_ESI[8] = 0x28;
  unaff_ESI[9] = 0;
  unaff_ESI[10] = 0x14;
  unaff_ESI[0xb] = 0x28;
  unaff_ESI[0xc] = 0x3c;
  unaff_ESI[0xd] = 0;
  *(undefined1 *)(unaff_ESI + 0xe) = 0;
  unaff_ESI[0xf] = 0;
  unaff_ESI[4] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[5] = 1;
  unaff_ESI[6] = 0;
  *unaff_ESI = CTriggerMsgObject::vftable;
  unaff_ESI[0x11] = 0;
  unaff_ESI[0x12] = 0;
  unaff_ESI[0x13] = 0;
  uStack_7 = 0;
  uVar1 = uStack_7;
  local_8 = 1;
  uStack_7 = 0;
  local_18 = uVar2;
  if (DAT_00e44af4 == -1) {
    local_28 = 0;
    _memset(local_68,0,0x40);
    local_24 = 0x28;
    local_20 = 4;
    local_1c = 1;
    _wcscpy_s(local_68,0x20,(wchar_t *)PTR_DAT_00d6a240);
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_8 = 2;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_8 = 1;
    }
    piVar3 = (int *)FUN_00735850(&DAT_00fb7b70,&local_6c);
    DAT_00e44af4 = *piVar3;
    uVar1 = uStack_7;
  }
  uStack_7 = uVar1;
  if ((DAT_00fe69a0 & 1) == 0) {
    DAT_00fe69a0 = DAT_00fe69a0 | 1;
    local_8 = 3;
    FUN_00536730(uVar2);
    local_8 = 4;
    FUN_00536280();
    _atexit(FUN_00bcf140);
    local_8 = 1;
  }
  local_70 = param_1;
  FUN_005366c0(&local_70);
  if (local_6c != DAT_00fe36f4) {
    puVar4 = (undefined4 *)(local_6c + 0x10);
    if (7 < *(uint *)(local_6c + 0x24)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    if (puVar4 != (undefined4 *)0x0) {
      FUN_004d4620(DAT_00e44af4,puVar4,0x400,unaff_ESI + 0x11);
    }
  }
  if ((DAT_00fe69a0 & 1) == 0) {
    DAT_00fe69a0 = DAT_00fe69a0 | 1;
    local_8 = 5;
    FUN_00536730(uVar2);
    local_8 = 6;
    FUN_00536280();
    _atexit(FUN_00bcf140);
  }
  local_6c = param_1;
  FUN_005366c0(&local_6c);
  if (local_70 == DAT_00fe36f4) {
    unaff_ESI[0x15] = 0;
  }
  else {
    unaff_ESI[0x15] = *(undefined4 *)(local_70 + 0x2c);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

