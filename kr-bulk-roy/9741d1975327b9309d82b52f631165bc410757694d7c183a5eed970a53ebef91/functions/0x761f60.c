
void FUN_00761f60(void)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  
  *(undefined4 *)(in_EAX + 0x14c) = *(undefined4 *)(in_EAX + 0x118);
  FUN_007619a0();
  iVar1 = *(int *)(*(int *)(in_EAX + 0x24) + 0x3d4);
  if ((((iVar1 == 1) || (iVar1 == 2)) ||
      (iVar1 = *(int *)(*(int *)(in_EAX + 0x24) + 0x404), iVar1 == 1)) || (iVar1 == 2)) {
    uVar2 = *(undefined4 *)(in_EAX + 0x160);
    if (*(char *)(in_EAX + 0x150) != '\0') {
      *(undefined4 *)(in_EAX + 0x164) = *(undefined4 *)(in_EAX + 0x14c);
      FUN_00761800();
      return;
    }
  }
  else {
    uVar2 = *(undefined4 *)(in_EAX + 0x14c);
    *(undefined4 *)(in_EAX + 0x160) = uVar2;
  }
  *(undefined4 *)(in_EAX + 0x164) = uVar2;
  FUN_00761800();
  return;
}

