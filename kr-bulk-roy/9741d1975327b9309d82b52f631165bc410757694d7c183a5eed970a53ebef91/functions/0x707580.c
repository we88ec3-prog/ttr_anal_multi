
void FUN_00707580(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 uVar2;
  
  puVar1 = *(undefined4 **)(in_EAX + 8);
  *puVar1 = *(undefined4 *)(in_EAX + 0x48);
  puVar1[1] = *(undefined4 *)(in_EAX + 0x4c);
  puVar1[2] = *(undefined4 *)(in_EAX + 0x50);
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
  FUN_006fec70();
  FUN_006fb9a0();
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + -0x10;
  FUN_006f6590(&DAT_00c43710,&PTR_s_assert_00c0bb90);
  if (*(uint *)(*(int *)(in_EAX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_EAX + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  puVar1 = *(undefined4 **)(in_EAX + 8);
  uVar2 = FUN_006fec70();
  *puVar1 = uVar2;
  puVar1[2] = 4;
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
  FUN_006fec70();
  FUN_006fb9a0();
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + -0x10;
  FUN_00707500("ipairs",FUN_00706330);
  FUN_00707500("pairs",FUN_00706170);
  if (*(uint *)(*(int *)(in_EAX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_EAX + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  puVar1 = *(undefined4 **)(in_EAX + 8);
  uVar2 = FUN_006f99a0();
  *puVar1 = uVar2;
  puVar1[2] = 5;
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
  puVar1 = *(undefined4 **)(in_EAX + 8);
  *puVar1 = puVar1[-4];
  puVar1[1] = puVar1[-3];
  puVar1[2] = puVar1[-2];
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
  FUN_006f5910();
  if (*(uint *)(*(int *)(in_EAX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_EAX + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  puVar1 = *(undefined4 **)(in_EAX + 8);
  uVar2 = FUN_006fec70();
  *puVar1 = uVar2;
  puVar1[2] = 4;
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
  FUN_006fec70();
  FUN_006fb9a0();
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + -0x10;
  FUN_006f55b0(FUN_00706e60,1);
  FUN_006fec70();
  FUN_006fb9a0();
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + -0x10;
  return;
}

