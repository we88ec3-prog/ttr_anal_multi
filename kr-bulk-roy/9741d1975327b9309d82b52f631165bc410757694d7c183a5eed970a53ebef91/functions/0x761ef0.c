
void FUN_00761ef0(void)

{
  int iVar1;
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x168) = 0;
  *(undefined4 *)(in_EAX + 0x14c) = 0;
  iVar1 = *(int *)(*(int *)(in_EAX + 0x24) + 0x3d4);
  if ((((iVar1 != 1) && (iVar1 != 2)) &&
      (iVar1 = *(int *)(*(int *)(in_EAX + 0x24) + 0x404), iVar1 != 1)) && (iVar1 != 2)) {
    *(undefined4 *)(in_EAX + 0x160) = 0;
    *(undefined4 *)(in_EAX + 0x164) = 0;
    FUN_00761800();
    return;
  }
  *(uint *)(in_EAX + 0x164) = (*(char *)(in_EAX + 0x150) != '\0') - 1 & *(uint *)(in_EAX + 0x160);
  FUN_00761800();
  return;
}

