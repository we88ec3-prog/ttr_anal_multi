
void FUN_00645250(int param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093327e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((*(int *)(*(int *)(param_1 + 0x110) + 0xcc) != 0) &&
     (*(int *)(*(int *)(param_1 + 0x110) + 0xd8) != 0)) {
    iVar1 = FUN_005f55a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar1 != -1) {
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_8 = 0;
        FUN_004d4d10();
        _atexit((_func_4879 *)&LAB_00bccef0);
        local_8 = 0xffffffff;
      }
      FUN_00645060(param_1);
      FUN_004d7ab0();
      FUN_00645300(param_1,iVar1);
    }
  }
  ExceptionList = local_10;
  return;
}

