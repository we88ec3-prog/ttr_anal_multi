
void FUN_006b0790(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_007459c0();
  iVar1 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_006b07cc;
    iVar1 = FUN_00745c20();
  }
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x60) != 0)) && ((*(uint *)(iVar1 + 0x28) >> 0xc & 1) == 0)
     ) {
    FUN_0074a010(iVar1);
  }
LAB_006b07cc:
  FUN_006b07e0(in_ECX);
  return;
}

