
void FUN_008f5b50(void)

{
  uint uVar1;
  int in_ECX;
  int in_EDX;
  
  uVar1 = *(uint *)(in_EDX + 0x68);
  if (((uVar1 & 4) != 0) && (*(char *)(in_ECX * 0x42c + *(int *)(in_EDX + 0x6c) + 0x100) == '\0')) {
    if (in_ECX == 1) {
      uVar1 = uVar1 & 2;
    }
    else {
      uVar1 = uVar1 & 1;
    }
    if (uVar1 != 0) {
      FUN_008f5af0();
    }
  }
  return;
}

