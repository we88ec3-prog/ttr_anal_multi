
uint FUN_00717ed0(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  uVar2 = FUN_00729460(0);
  if (uVar2 == 0) {
    _fflush(*(FILE **)(iVar1 + 0x40));
    uVar2 = *(uint *)(iVar1 + 0x38);
    uVar2 = -(uint)(uVar2 != 1) & uVar2;
  }
  return uVar2;
}

