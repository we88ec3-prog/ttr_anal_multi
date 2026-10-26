
undefined4 FUN_007c4d30(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009377fe;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = *(int *)(param_1 + 0x28);
  if (iVar3 != *(int *)(param_1 + 0x2c)) {
    do {
      if ((DAT_00fe1ac0 & 1) == 0) {
        DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
        local_8 = 0;
        FUN_007bb970(uVar1);
        _atexit((_func_4879 *)&LAB_00bceac0);
        local_8 = 0xffffffff;
      }
      iVar2 = FUN_007bcf60();
      if (iVar2 == 0) {
        ExceptionList = local_10;
        return 0;
      }
      iVar3 = iVar3 + 0x68;
    } while (iVar3 != *(int *)(param_1 + 0x2c));
  }
  ExceptionList = local_10;
  return 1;
}

