
void FUN_00789f90(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (param_3 - param_1) / 0x60;
  if (iVar1 < 0x29) {
    if (*(int *)(param_2 + 0x14) < *(int *)(param_1 + 0x14)) {
      FUN_0078afd0();
    }
    if (*(int *)(param_3 + 0x14) < *(int *)(param_2 + 0x14)) {
      FUN_0078afd0();
    }
    if (*(int *)(param_2 + 0x14) < *(int *)(param_1 + 0x14)) {
      FUN_0078afd0();
    }
  }
  else {
    iVar1 = iVar1 + 1;
    iVar2 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
    iVar1 = iVar2 * 0x60 + param_1;
    if (*(int *)(iVar1 + 0x14) < *(int *)(param_1 + 0x14)) {
      FUN_0078afd0();
    }
    if (*(int *)(iVar2 * 0xc0 + 0x14 + param_1) < *(int *)(iVar1 + 0x14)) {
      FUN_0078afd0();
    }
    if (*(int *)(iVar1 + 0x14) < *(int *)(param_1 + 0x14)) {
      FUN_0078afd0();
    }
    iVar3 = param_2 + iVar2 * -0x60;
    if (*(int *)(param_2 + 0x14) < *(int *)(iVar3 + 0x14)) {
      FUN_0078afd0();
    }
    if (*(int *)(iVar2 * 0x60 + param_2 + 0x14) < *(int *)(param_2 + 0x14)) {
      FUN_0078afd0();
    }
    if (*(int *)(param_2 + 0x14) < *(int *)(iVar3 + 0x14)) {
      FUN_0078afd0();
    }
    iVar3 = param_3 + iVar2 * -0x60;
    iVar2 = param_3 + iVar2 * -0xc0;
    if (*(int *)(iVar3 + 0x14) < *(int *)(iVar2 + 0x14)) {
      FUN_0078afd0();
    }
    if (*(int *)(param_3 + 0x14) < *(int *)(iVar3 + 0x14)) {
      FUN_0078afd0();
    }
    if (*(int *)(iVar3 + 0x14) < *(int *)(iVar2 + 0x14)) {
      FUN_0078afd0();
    }
    if (*(int *)(param_2 + 0x14) < *(int *)(iVar1 + 0x14)) {
      FUN_0078afd0();
    }
    if (*(int *)(iVar3 + 0x14) < *(int *)(param_2 + 0x14)) {
      FUN_0078afd0();
    }
    if (*(int *)(param_2 + 0x14) < *(int *)(iVar1 + 0x14)) {
      FUN_0078afd0();
      return;
    }
  }
  return;
}

