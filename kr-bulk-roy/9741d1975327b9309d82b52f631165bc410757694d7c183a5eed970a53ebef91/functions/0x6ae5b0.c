
void FUN_006ae5b0(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_00745930();
  iVar1 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_006ae5ec;
    iVar1 = FUN_00745c20();
  }
  if (((iVar1 != 0) && ((*(uint *)(iVar1 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar1 + 0x60) != 0)
     ) {
    FUN_00749f40(iVar1);
  }
LAB_006ae5ec:
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf4) + 0xcc);
  if (iVar1 != 0) {
    FUN_006438f0(iVar1);
  }
  return;
}

