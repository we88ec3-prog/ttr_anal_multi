
int FUN_00721b30(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  uint *in_EDX;
  
  puVar1 = in_EDX + in_ECX;
  iVar3 = 0;
  for (; in_EDX < puVar1; in_EDX = in_EDX + 1) {
    uVar2 = *in_EDX;
    if (uVar2 < 0x10000) {
      if (uVar2 < 0x80) {
        iVar3 = iVar3 + 1;
      }
      else if (uVar2 < 0x800) {
        iVar3 = iVar3 + 2;
      }
      else {
        iVar3 = iVar3 + 3;
      }
    }
    else {
      iVar3 = iVar3 + 4;
    }
  }
  return iVar3;
}

