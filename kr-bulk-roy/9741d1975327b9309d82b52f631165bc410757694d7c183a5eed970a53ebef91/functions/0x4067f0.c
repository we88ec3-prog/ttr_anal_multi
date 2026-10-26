
void FUN_004067f0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  FUN_00745930();
  iVar1 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_0040682c;
    iVar1 = FUN_00745c20();
  }
  if (((iVar1 != 0) && ((*(uint *)(iVar1 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar1 + 0x60) != 0)
     ) {
    FUN_00749f40(iVar1);
  }
LAB_0040682c:
  puVar2 = (undefined4 *)FUN_00891268(0x18);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_004072a0();
    return;
  }
  puVar2[5] = in_ECX;
  puVar2[1] = 0xffffffff;
  puVar2[2] = 0xffffffff;
  puVar2[3] = 0;
  puVar2[4] = 0xf4350;
  *puVar2 = FoxUI::FXUIEventP1::vftable;
  FUN_004072a0();
  return;
}

