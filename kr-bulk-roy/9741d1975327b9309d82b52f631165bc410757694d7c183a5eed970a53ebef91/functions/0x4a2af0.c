
int FUN_004a2af0(void)

{
  int iVar1;
  int *in_EAX;
  int *piVar2;
  int iVar3;
  
  iVar1 = *in_EAX;
  piVar2 = (int *)FUN_006f50f0();
  if (piVar2[2] != 4) {
    iVar3 = FUN_006fb5d0();
    if (iVar3 == 0) {
      return 0;
    }
    if (*(uint *)(*(int *)(iVar1 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    piVar2 = (int *)FUN_006f50f0();
  }
  return *piVar2 + 0x10;
}

