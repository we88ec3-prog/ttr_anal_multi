
int * FUN_0079a5f0(int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093250e;
  local_10 = ExceptionList;
  piVar2 = (int *)0x0;
  if (*param_1 == 0) {
    return (int *)0x0;
  }
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  iVar1 = DAT_00fb76a8;
  local_8 = 0xffffffff;
  if (*(int *)(DAT_00fb76a8 + 0xec) != 0) {
    (**(code **)(**(int **)(DAT_00fb76a8 + 0xec) + 4))(*(int **)(DAT_00fb76a8 + 0xec));
    piVar2 = *(int **)(iVar1 + 0xec);
  }
  (**(code **)(*piVar2 + 8))(piVar2);
  ExceptionList = local_10;
  return piVar2;
}

