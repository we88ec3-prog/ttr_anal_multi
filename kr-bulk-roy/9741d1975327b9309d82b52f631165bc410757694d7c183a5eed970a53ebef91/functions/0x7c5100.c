
undefined4 FUN_007c5100(int param_1,undefined4 param_2,int param_3,int *param_4)

{
  short *psVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar2 = param_4;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938a7b;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 0xec) == 0) {
    return 0;
  }
  ExceptionList = &local_10;
  if (*param_4 == 0) {
    uVar3 = (**(code **)(**(int **)(param_1 + 0xec) + 0xc))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    iVar4 = FUN_00891268(0xb8);
    local_8 = 0;
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_007d2db0(iVar4,uVar3);
    }
    *piVar2 = iVar4;
  }
  local_8 = 0xffffffff;
  param_2 = CONCAT22((undefined2)param_2,(undefined2)param_3);
  FUN_0082ef00(&param_2);
  if (param_3 != *(int *)(param_1 + 0xb8)) {
    psVar1 = *(short **)(param_3 + 0x10);
    iVar4 = *(int *)(psVar1 + 0x14);
    if (iVar4 != *(int *)(psVar1 + 0x16)) {
      do {
        FUN_007c5270(param_1,*param_4,iVar4 + 1,iVar4 + 0x21);
        iVar4 = iVar4 + 0x68;
      } while (iVar4 != *(int *)(psVar1 + 0x16));
    }
    if (*psVar1 == 0) {
      FUN_007c4c80();
    }
    *psVar1 = *psVar1 + 1;
  }
  ExceptionList = local_10;
  return 1;
}

