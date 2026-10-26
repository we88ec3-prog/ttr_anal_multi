
void FUN_007051d0(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 uVar2;
  
  if (*(uint *)(*(int *)(in_EAX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_EAX + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  puVar1 = *(undefined4 **)(in_EAX + 8);
  uVar2 = FUN_006f99a0();
  *puVar1 = uVar2;
  puVar1[2] = 5;
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
  if (*(uint *)(*(int *)(in_EAX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_EAX + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  puVar1 = *(undefined4 **)(in_EAX + 8);
  uVar2 = FUN_006fec70();
  *puVar1 = uVar2;
  puVar1[2] = 4;
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
  puVar1 = *(undefined4 **)(in_EAX + 8);
  *puVar1 = puVar1[-8];
  puVar1[1] = puVar1[-7];
  puVar1[2] = puVar1[-6];
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
  FUN_006f5910();
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + -0x10;
  puVar1 = *(undefined4 **)(in_EAX + 8);
  *puVar1 = puVar1[-8];
  puVar1[1] = puVar1[-7];
  puVar1[2] = puVar1[-6];
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
  FUN_006fec70();
  FUN_006fb9a0();
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + -0x20;
  return;
}

