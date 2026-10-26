
undefined4 FUN_0054f030(void)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int *in_ECX;
  
  pcVar2 = DAT_00fe1e2c;
  iVar1 = *in_ECX;
  iVar3 = *(int *)(iVar1 + 8);
  if (*(int *)(iVar3 + -8) != 4) {
    iVar3 = FUN_006fb5d0();
    if (iVar3 == 0) {
      (*pcVar2)(0);
      return 0;
    }
    if (*(uint *)(*(int *)(iVar1 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    iVar3 = *(int *)(iVar1 + 8);
  }
  (*pcVar2)(*(int *)(iVar3 + -0x10) + 0x10);
  return 0;
}

