
void FUN_007e0b00(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  int *piVar3;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093250e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar3 = (int *)(in_ECX + 0xc);
  local_14 = 8;
  do {
    iVar1 = *piVar3;
    if (iVar1 != 0) {
      if ((*(int *)(iVar1 + 4) != 0) && ((DAT_00fb79e8 & 1) == 0)) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 0;
        FUN_00798de0(uVar2);
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
      if (*(int *)(iVar1 + 0x10) != 0) {
        (**(code **)(**(int **)(iVar1 + 0x10) + 0x18))();
      }
    }
    piVar3 = piVar3 + 1;
    local_14 = local_14 + -1;
  } while (local_14 != 0);
  ExceptionList = local_10;
  return;
}

