
void FUN_005d8660(int param_1)

{
  int iVar1;
  int in_ECX;
  
  FUN_005d6fb0(param_1);
  iVar1 = *(int *)(param_1 + 0x10);
  if ((iVar1 != 0x69) && (iVar1 != 0x7c)) {
    if (iVar1 == 0x66) {
      *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x13c8) = 0;
    }
    return;
  }
  FUN_005d8750();
  return;
}

