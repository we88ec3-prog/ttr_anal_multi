
void FUN_0065d8d0(int param_1)

{
  int iVar1;
  int in_ECX;
  bool bVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x578) {
    bVar2 = *(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xfc) + 0x20);
  }
  else {
    if (iVar1 == 0x709) {
      if (*(int *)(param_1 + 0x14) == -1) {
        return;
      }
      FUN_0065d9a0(in_ECX,*(int *)(param_1 + 0x14) + 1);
      return;
    }
    bVar2 = iVar1 == 0x70a;
  }
  if (bVar2) {
    FUN_0065d920();
  }
  return;
}

