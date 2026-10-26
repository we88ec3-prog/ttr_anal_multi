
void FUN_0063afe0(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_007459c0();
  iVar1 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_0063b01c;
    iVar1 = FUN_00745c20();
  }
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x60) != 0)) && ((*(uint *)(iVar1 + 0x28) >> 0xc & 1) == 0)
     ) {
    FUN_0074a010(iVar1);
  }
LAB_0063b01c:
  if (((*(int *)(*(int *)(in_ECX + 0xf8) + 0xcc) != 0) &&
      (*(int *)(*(int *)(in_ECX + 0xf8) + 0xd8) != 0)) && (iVar1 = FUN_005f55a0(), iVar1 != -1)) {
    if (iVar1 == 0) {
      FUN_0063ad80();
      return;
    }
    if (iVar1 == 1) {
      FUN_0063ae20();
      return;
    }
    if (iVar1 == 2) {
      FUN_0063add0();
      return;
    }
  }
  return;
}

