
undefined4 FUN_004ac970(int param_1)

{
  double *pdVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009387d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar2 = (*DAT_00fe1878)(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  pdVar1 = *(double **)(param_1 + 8);
  *(undefined4 *)(pdVar1 + 1) = 3;
  *pdVar1 = (double)iVar2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  ExceptionList = local_10;
  return 1;
}

