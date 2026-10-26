
void FUN_0078dd80(int param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = (param_2 - in_EAX) / 0x2c;
  if (iVar1 < 0x29) {
    if (*(int *)(param_1 + 8) < *(int *)(in_EAX + 8)) {
      FUN_0078f700();
    }
    if (*(int *)(param_2 + 8) < *(int *)(param_1 + 8)) {
      FUN_0078f700();
    }
    if (*(int *)(param_1 + 8) < *(int *)(in_EAX + 8)) {
      FUN_0078f700();
    }
  }
  else {
    iVar1 = iVar1 + 1;
    iVar2 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
    iVar4 = iVar2 * 0x2c;
    iVar1 = iVar4 + in_EAX;
    if (*(int *)(iVar4 + 8 + in_EAX) < *(int *)(in_EAX + 8)) {
      FUN_0078f700();
    }
    if (*(int *)(iVar2 * 0x58 + 8 + in_EAX) < *(int *)(iVar1 + 8)) {
      FUN_0078f700();
    }
    if (*(int *)(iVar1 + 8) < *(int *)(in_EAX + 8)) {
      FUN_0078f700();
    }
    iVar3 = param_1 + iVar2 * -0x2c;
    if (*(int *)(param_1 + 8) < *(int *)(iVar3 + 8)) {
      FUN_0078f700();
    }
    if (*(int *)(iVar4 + 8 + param_1) < *(int *)(param_1 + 8)) {
      FUN_0078f700();
    }
    if (*(int *)(param_1 + 8) < *(int *)(iVar3 + 8)) {
      FUN_0078f700();
    }
    iVar4 = param_2 + iVar2 * -0x2c;
    iVar2 = param_2 + iVar2 * -0x58;
    if (*(int *)(iVar4 + 8) < *(int *)(iVar2 + 8)) {
      FUN_0078f700();
    }
    if (*(int *)(param_2 + 8) < *(int *)(iVar4 + 8)) {
      FUN_0078f700();
    }
    if (*(int *)(iVar4 + 8) < *(int *)(iVar2 + 8)) {
      FUN_0078f700();
    }
    if (*(int *)(param_1 + 8) < *(int *)(iVar1 + 8)) {
      FUN_0078f700();
    }
    if (*(int *)(iVar4 + 8) < *(int *)(param_1 + 8)) {
      FUN_0078f700();
    }
    if (*(int *)(param_1 + 8) < *(int *)(iVar1 + 8)) {
      FUN_0078f700();
      return;
    }
  }
  return;
}

