
void FUN_006b4a50(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x578) {
    FUN_006b4ab0();
  }
  else if (iVar1 == 0x709) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)) {
      FUN_006b4bb0(in_ECX);
      FUN_006b4f80(in_ECX);
      return;
    }
  }
  else if (iVar1 == 0x70a) {
    FUN_006b4b10();
    return;
  }
  return;
}

