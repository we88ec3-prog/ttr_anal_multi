
void FUN_0078e4b0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (param_3 - param_1) / 0x30;
  if (iVar1 < 0x29) {
    if (*(int *)(param_2 + 0x10) < *(int *)(param_1 + 0x10)) {
      FUN_0078fa80();
    }
    if (*(int *)(param_3 + 0x10) < *(int *)(param_2 + 0x10)) {
      FUN_0078fa80();
    }
    if (*(int *)(param_2 + 0x10) < *(int *)(param_1 + 0x10)) {
      FUN_0078fa80();
    }
  }
  else {
    iVar1 = iVar1 + 1;
    iVar2 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
    iVar1 = iVar2 * 0x30 + param_1;
    if (*(int *)(iVar1 + 0x10) < *(int *)(param_1 + 0x10)) {
      FUN_0078fa80();
    }
    if (*(int *)(iVar2 * 0x60 + 0x10 + param_1) < *(int *)(iVar1 + 0x10)) {
      FUN_0078fa80();
    }
    if (*(int *)(iVar1 + 0x10) < *(int *)(param_1 + 0x10)) {
      FUN_0078fa80();
    }
    iVar3 = param_2 + iVar2 * -0x30;
    if (*(int *)(param_2 + 0x10) < *(int *)(iVar3 + 0x10)) {
      FUN_0078fa80();
    }
    if (*(int *)(iVar2 * 0x30 + param_2 + 0x10) < *(int *)(param_2 + 0x10)) {
      FUN_0078fa80();
    }
    if (*(int *)(param_2 + 0x10) < *(int *)(iVar3 + 0x10)) {
      FUN_0078fa80();
    }
    iVar3 = param_3 + iVar2 * -0x30;
    iVar2 = param_3 + iVar2 * -0x60;
    if (*(int *)(iVar3 + 0x10) < *(int *)(iVar2 + 0x10)) {
      FUN_0078fa80();
    }
    if (*(int *)(param_3 + 0x10) < *(int *)(iVar3 + 0x10)) {
      FUN_0078fa80();
    }
    if (*(int *)(iVar3 + 0x10) < *(int *)(iVar2 + 0x10)) {
      FUN_0078fa80();
    }
    if (*(int *)(param_2 + 0x10) < *(int *)(iVar1 + 0x10)) {
      FUN_0078fa80();
    }
    if (*(int *)(iVar3 + 0x10) < *(int *)(param_2 + 0x10)) {
      FUN_0078fa80();
    }
    if (*(int *)(param_2 + 0x10) < *(int *)(iVar1 + 0x10)) {
      FUN_0078fa80();
      return;
    }
  }
  return;
}

