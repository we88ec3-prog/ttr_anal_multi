
undefined4 FUN_004acd30(code *param_1)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  
  iVar1 = *in_EAX;
  iVar2 = *(int *)(iVar1 + 8);
  if (*(int *)(iVar2 + -8) != 4) {
    iVar2 = FUN_006fb5d0();
    if (iVar2 == 0) {
      (*param_1)(0);
      return 0;
    }
    if (*(uint *)(*(int *)(iVar1 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    iVar2 = *(int *)(iVar1 + 8);
  }
  (*param_1)(*(int *)(iVar2 + -0x10) + 0x10);
  return 0;
}

