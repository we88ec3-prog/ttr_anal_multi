
undefined4 FUN_0081b4f0(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 != 0) {
    if (*(int *)(in_ECX + 8) == 0) {
      piVar2 = *(int **)(iVar1 + 0xc);
    }
    else {
      piVar2 = *(int **)(iVar1 + 8);
    }
    if (piVar2 != (int *)0x0) {
      uVar3 = (**(code **)(*piVar2 + 8))
                        (*(undefined1 *)(in_ECX + 0xc),*(undefined1 *)(in_ECX + 0xd),
                         *(undefined1 *)(in_ECX + 0xe));
      return uVar3;
    }
  }
  return 0;
}

