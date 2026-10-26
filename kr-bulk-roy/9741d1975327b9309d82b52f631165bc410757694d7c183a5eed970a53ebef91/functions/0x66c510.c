
void FUN_0066c510(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((*(int *)(param_1 + 0xf0) != 0) && (*(int *)(param_1 + 0xf4) != 0)) {
    iVar2 = *(int *)(*(int *)(param_1 + 0xf0) + 0xcc);
    if (iVar2 == 0) {
      iVar2 = -1;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0xdc);
      if (iVar2 == 0) {
        iVar2 = -1;
      }
      else {
        iVar2 = *(int *)(iVar2 + 0x20);
      }
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0xf4) + 0xcc);
    if (iVar1 == 0) {
      iVar1 = -1;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0xdc);
      if (iVar1 == 0) {
        iVar1 = -1;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0x20);
      }
    }
    (**(code **)(**(int **)(param_1 + 0xf0) + 0x90))(DAT_00d63dcc == -1);
    if ((iVar2 == -1) || (iVar1 == -1)) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    (**(code **)(**(int **)(param_1 + 0xf8) + 0x90))(uVar3);
  }
  return;
}

