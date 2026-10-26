
bool FUN_0083c600(undefined4 param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  
  if ((param_2 != 0) && (*(int *)(param_2 + 0x68) != 0)) {
    iVar3 = *(int *)(param_2 + 0x4c);
    iVar4 = *(int *)(param_2 + 0x48);
    if (*(int *)(param_2 + 0x40) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00857160(*(int *)(param_2 + 0x40));
    }
    iVar3 = FUN_00838f30(iVar2 * ((iVar3 - iVar4) / 0x18),param_1);
    if (iVar3 != 0) {
      iVar4 = FUN_00862570(iVar3,param_3);
      iVar3 = *(int *)(*(int *)(in_ECX + 0x354) + *(int *)(in_ECX + 0x364) * 4);
      if ((*(int *)(iVar3 + 0x14) != 0) && (piVar1 = *(int **)(iVar3 + 8), piVar1 != (int *)0x0)) {
        (**(code **)(*piVar1 + 0x30))(piVar1);
        *(undefined4 *)(iVar3 + 0x14) = 0;
      }
      return iVar4 != 0;
    }
    iVar3 = *(int *)(*(int *)(in_ECX + 0x354) + *(int *)(in_ECX + 0x364) * 4);
    if ((*(int *)(iVar3 + 0x14) != 0) && (piVar1 = *(int **)(iVar3 + 8), piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0x30))(piVar1);
      *(undefined4 *)(iVar3 + 0x14) = 0;
    }
  }
  return false;
}

