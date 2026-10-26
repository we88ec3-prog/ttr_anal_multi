
void FUN_006f8ad0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_EAX;
  undefined4 *puVar3;
  
  if (*(int *)(in_EAX + 0x74) != 0) {
    puVar3 = (undefined4 *)(*(int *)(in_EAX + 0x20) + *(int *)(in_EAX + 0x74));
    if (puVar3[2] != 6) {
      FUN_006fdb40();
    }
    puVar1 = *(undefined4 **)(in_EAX + 8);
    *puVar1 = puVar1[-4];
    puVar1[1] = puVar1[-3];
    puVar1[2] = puVar1[-2];
    iVar2 = *(int *)(in_EAX + 8);
    *(undefined4 *)(iVar2 + -0x10) = *puVar3;
    *(undefined4 *)(iVar2 + -0xc) = puVar3[1];
    *(undefined4 *)(iVar2 + -8) = puVar3[2];
    if (*(int *)(in_EAX + 0x1c) - *(int *)(in_EAX + 8) < 0x11) {
      FUN_006fdcb0();
    }
    *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
    FUN_006fe550();
  }
  FUN_006fdb40();
  return;
}

