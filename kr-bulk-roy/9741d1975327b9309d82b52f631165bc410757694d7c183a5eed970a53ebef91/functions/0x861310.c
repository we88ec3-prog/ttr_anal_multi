
undefined4 FUN_00861310(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (*(int *)(iVar2 + 4) != *(int *)(in_ECX + 0x28)) {
    return 0;
  }
  piVar1 = *(int **)(in_ECX + 0x34);
  iVar2 = FUN_00796de0(0,param_2,*(undefined4 *)(in_ECX + 0x40));
  piVar3 = *(int **)(in_ECX + 0x30);
  if (piVar3 != piVar1) {
    while (*(int *)*piVar3 <= iVar2) {
      piVar3 = piVar3 + 1;
      if (piVar3 == piVar1) {
        return 1;
      }
    }
    if (piVar3 != piVar1) {
      param_1[0x2e] = ((int *)*piVar3)[1];
    }
  }
  return 1;
}

