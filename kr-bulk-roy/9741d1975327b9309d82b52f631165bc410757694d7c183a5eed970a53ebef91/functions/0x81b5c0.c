
undefined4 FUN_0081b5c0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int *piVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(int *)(in_ECX + 8) == 0) {
    piVar3 = *(int **)(iVar1 + 0xc);
  }
  else {
    piVar3 = *(int **)(iVar1 + 8);
  }
  uVar2 = (**(code **)(*piVar3 + 0x10))
                    (0,*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x10),
                     *(undefined4 *)(in_ECX + 0x14));
  return uVar2;
}

