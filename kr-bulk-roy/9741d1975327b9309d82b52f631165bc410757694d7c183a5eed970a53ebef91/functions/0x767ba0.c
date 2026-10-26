
void FUN_00767ba0(void)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(in_EAX + 0x24);
  if ((iVar1 == 0) ||
     ((((*(int *)(iVar1 + 0x3d4) != 1 && (*(int *)(iVar1 + 0x3d4) != 2)) &&
       (*(int *)(iVar1 + 0x404) != 1)) && (*(int *)(iVar1 + 0x404) != 2)))) {
    uVar2 = *(undefined4 *)(in_EAX + 0x140);
    uVar3 = *(undefined4 *)(in_EAX + 0x13c);
    *(undefined4 *)(in_EAX + 0x14c) = uVar3;
    *(undefined4 *)(in_EAX + 0x154) = uVar2;
  }
  else {
    uVar2 = *(undefined4 *)(in_EAX + 0x154);
    uVar3 = *(undefined4 *)(in_EAX + 0x14c);
    if (*(char *)(in_EAX + 0x148) != '\0') {
      *(undefined4 *)(in_EAX + 0x150) = *(undefined4 *)(in_EAX + 0x13c);
      *(undefined4 *)(in_EAX + 0x158) = *(undefined4 *)(in_EAX + 0x140);
      return;
    }
  }
  *(undefined4 *)(in_EAX + 0x150) = uVar3;
  *(undefined4 *)(in_EAX + 0x158) = uVar2;
  return;
}

