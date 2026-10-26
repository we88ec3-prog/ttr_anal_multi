
undefined4 FUN_004cc6f0(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0xfc) != 0) &&
     (iVar1 = *(int *)(*(int *)(in_ECX + 0xfc) + 0x24), iVar1 != 0)) {
    FUN_007bdf40(iVar1);
  }
  if ((*(int *)(in_ECX + 0xf0) != 0) &&
     (iVar1 = *(int *)(*(int *)(in_ECX + 0xf0) + 0x24), iVar1 != 0)) {
    FUN_007bdf40(iVar1);
  }
  return 0;
}

