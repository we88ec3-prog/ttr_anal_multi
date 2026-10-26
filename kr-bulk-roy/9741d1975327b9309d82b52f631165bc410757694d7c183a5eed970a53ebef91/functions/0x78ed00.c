
void FUN_0078ed00(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = (param_3 - param_1) / 0x1c;
  if (iVar1 < 0x29) {
    if (*(int *)(param_2 + 0x14) < *(int *)(param_1 + 0x14)) {
      FUN_0078fdf0();
    }
    if (*(int *)(param_3 + 0x14) < *(int *)(param_2 + 0x14)) {
      FUN_0078fdf0();
    }
    if (*(int *)(param_2 + 0x14) < *(int *)(param_1 + 0x14)) {
      FUN_0078fdf0();
    }
  }
  else {
    iVar1 = iVar1 + 1;
    iVar2 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
    iVar4 = iVar2 * 0x1c;
    iVar1 = iVar4 + param_1;
    if (*(int *)(iVar4 + 0x14 + param_1) < *(int *)(param_1 + 0x14)) {
      FUN_0078fdf0();
    }
    if (*(int *)(iVar2 * 0x38 + 0x14 + param_1) < *(int *)(iVar1 + 0x14)) {
      FUN_0078fdf0();
    }
    if (*(int *)(iVar1 + 0x14) < *(int *)(param_1 + 0x14)) {
      FUN_0078fdf0();
    }
    iVar3 = param_2 + iVar2 * -0x1c;
    if (*(int *)(param_2 + 0x14) < *(int *)(iVar3 + 0x14)) {
      FUN_0078fdf0();
    }
    if (*(int *)(iVar4 + 0x14 + param_2) < *(int *)(param_2 + 0x14)) {
      FUN_0078fdf0();
    }
    if (*(int *)(param_2 + 0x14) < *(int *)(iVar3 + 0x14)) {
      FUN_0078fdf0();
    }
    iVar4 = param_3 + iVar2 * -0x1c;
    iVar2 = param_3 + iVar2 * -0x38;
    if (*(int *)(iVar4 + 0x14) < *(int *)(iVar2 + 0x14)) {
      FUN_0078fdf0();
    }
    if (*(int *)(param_3 + 0x14) < *(int *)(iVar4 + 0x14)) {
      FUN_0078fdf0();
    }
    if (*(int *)(iVar4 + 0x14) < *(int *)(iVar2 + 0x14)) {
      FUN_0078fdf0();
    }
    if (*(int *)(param_2 + 0x14) < *(int *)(iVar1 + 0x14)) {
      FUN_0078fdf0();
    }
    if (*(int *)(iVar4 + 0x14) < *(int *)(param_2 + 0x14)) {
      FUN_0078fdf0();
    }
    if (*(int *)(param_2 + 0x14) < *(int *)(iVar1 + 0x14)) {
      FUN_0078fdf0();
      return;
    }
  }
  return;
}

