
void FUN_008f6d50(void)

{
  uint uVar1;
  int in_ECX;
  int in_EDX;
  
  uVar1 = *(uint *)(in_ECX + 0x68);
  if ((uVar1 & 4) != 0) {
    if (in_EDX == 1) {
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

