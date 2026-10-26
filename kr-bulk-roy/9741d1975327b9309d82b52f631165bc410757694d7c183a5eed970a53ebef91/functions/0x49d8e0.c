
undefined4 FUN_0049d8e0(void)

{
  int iVar1;
  uint unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00930e4c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0;
    FUN_004f3d80(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_004f7a70();
  if (*(uint *)(iVar1 + 0x30) < 8) {
    iVar1 = iVar1 + 0x1c;
  }
  else {
    iVar1 = *(int *)(iVar1 + 0x1c);
  }
  if ((DAT_00fb11e0 & 1) == 0) {
    DAT_00fb11e0 = DAT_00fb11e0 | 1;
    local_8 = 1;
    FUN_004d4d10();
    _atexit((_func_4879 *)&LAB_00bccef0);
    local_8 = 0xffffffff;
  }
  FUN_004d6c70(&DAT_00c05d6c,iVar1,unaff_EDI & 0xffff,(char)(unaff_EDI >> 0x10) + '\x01');
  ExceptionList = local_10;
  return 1;
}

