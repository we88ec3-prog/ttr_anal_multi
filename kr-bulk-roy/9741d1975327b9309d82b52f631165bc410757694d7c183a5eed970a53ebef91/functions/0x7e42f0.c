
void FUN_007e42f0(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092b79e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = 0;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  if (DAT_00fb76e4 == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = FUN_00838860(*(undefined4 *)(unaff_EDI + 0x68),*(undefined4 *)(unaff_EDI + 0x6c),
                         *(undefined4 *)(unaff_EDI + 0x70),*(undefined4 *)(unaff_EDI + 0x74));
  }
  *(uint *)(unaff_EDI + 0x78) = (uint)(iVar1 == 0);
  if ((iVar1 == 0) == 0) {
    for (iVar1 = (*(int *)(unaff_EDI + 0x5c) - *(int *)(unaff_EDI + 0x58)) / 0x2c; iVar1 != 0;
        iVar1 = iVar1 + -1) {
      (**(code **)(**(int **)(iVar2 + 0x28 + *(int *)(unaff_EDI + 0x58)) + 0x24))();
      iVar2 = iVar2 + 0x2c;
    }
  }
  ExceptionList = local_10;
  return;
}

