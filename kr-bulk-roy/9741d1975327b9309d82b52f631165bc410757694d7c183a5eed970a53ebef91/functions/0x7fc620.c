
void FUN_007fc620(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x40);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 8) != 0)) {
    FUN_005366c0(&param_1);
    iVar1 = *(int *)(iVar1 + 4);
    if (in_ECX == iVar1) {
      param_1 = 0;
      piVar2 = (int *)FUN_005366c0(&param_1);
      if (*piVar2 != iVar1) {
        *(undefined4 *)(in_ECX + 0x3c) = 0;
        return;
      }
    }
    else {
      *(undefined4 *)(in_ECX + 0x3c) = param_1;
      *(undefined4 *)(in_ECX + 0x4c) = 0;
    }
  }
  return;
}

