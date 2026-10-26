
void FUN_005cd3c0(int param_1)

{
  int iVar1;
  int *piVar2;
  int unaff_EDI;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093605e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  if (DAT_00fba7a4 != (int *)0x0) {
    iVar1 = (**(code **)(*DAT_00fba7a4 + 0x1c))(0);
    if (iVar1 == 0) {
      piVar2 = (int *)(param_1 + 0x10c);
      iVar1 = 6;
      do {
        (**(code **)(**(int **)(*piVar2 + 0x280) + 0x94))(0);
        piVar2 = piVar2 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      ExceptionList = local_14;
      return;
    }
    if (*(char *)(param_1 + 0x37c) != '\0') {
      iVar1 = 0;
      piVar2 = (int *)(param_1 + 0x124);
      do {
        (**(code **)(**(int **)(piVar2[-6] + 0x280) + 0x94))(1);
        (**(code **)(**(int **)(*piVar2 + 0x280) + 0x94))(1);
        (**(code **)(**(int **)(piVar2[6] + 0x280) + 0x94))(1);
        (**(code **)(**(int **)(*(int *)(param_1 + 0x10c +
                                        (iVar1 + *(int *)(unaff_EDI + 1000) * 6) * 4) + 0x280) +
                    0x94))(0);
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar1 < 6);
    }
  }
  ExceptionList = local_14;
  return;
}

