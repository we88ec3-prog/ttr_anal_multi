
void FUN_0070a470(void)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  if (((*(int *)(*(int *)(in_EAX + 8) + -8) != 4) && (iVar1 = FUN_006fb5d0(), iVar1 != 0)) &&
     (*(uint *)(*(int *)(in_EAX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_EAX + 0x10) + 0x44))) {
    FUN_006fb3a0();
  }
  puVar2 = *(undefined4 **)(in_EAX + 0xc);
  if (*(undefined4 **)(in_EAX + 8) <= puVar2) {
    puVar2 = &DAT_00c0bfc8;
  }
  if (((puVar2[2] != 4) && (iVar1 = FUN_006fb5d0(), iVar1 != 0)) &&
     (*(uint *)(*(int *)(in_EAX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_EAX + 0x10) + 0x44))) {
    FUN_006fb3a0();
  }
  FUN_006f5f30();
  return;
}

