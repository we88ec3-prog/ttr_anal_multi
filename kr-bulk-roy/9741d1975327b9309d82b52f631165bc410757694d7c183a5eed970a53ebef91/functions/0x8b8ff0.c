
int FUN_008b8ff0(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = 0;
  if ((param_1 != (int *)0x0) &&
     ((*(code **)(*param_1 + 0x20) == (code *)0x0 ||
      (iVar3 = (**(code **)(*param_1 + 0x20))(param_1,param_2), iVar3 == 0)))) {
    puVar4 = (undefined4 *)(param_1[1] + 0x14);
    puVar1 = puVar4 + *(int *)(param_1[1] + 0x10);
    while ((puVar4 < puVar1 &&
           (((piVar2 = (int *)*puVar4, piVar2 == param_1 ||
             (*(code **)(*piVar2 + 0x20) == (code *)0x0)) ||
            (iVar3 = (**(code **)(*piVar2 + 0x20))(piVar2,param_2), iVar3 == 0))))) {
      puVar4 = puVar4 + 1;
    }
  }
  return iVar3;
}

