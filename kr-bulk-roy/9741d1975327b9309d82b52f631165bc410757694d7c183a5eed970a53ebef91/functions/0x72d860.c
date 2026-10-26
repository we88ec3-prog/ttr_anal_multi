
void FUN_0072d860(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  
  if (*(int *)(in_EAX + 0x16bc) < 9) {
    if (*(int *)(in_EAX + 0x16bc) < 1) goto LAB_0072d8a4;
    iVar1 = *(int *)(in_EAX + 8);
    iVar2 = *(int *)(in_EAX + 0x14);
    uVar3 = *(undefined1 *)(in_EAX + 0x16b8);
  }
  else {
    *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
         *(undefined1 *)(in_EAX + 0x16b8);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    iVar1 = *(int *)(in_EAX + 0x14);
    iVar2 = *(int *)(in_EAX + 8);
    uVar3 = *(undefined1 *)(in_EAX + 0x16b9);
  }
  *(undefined1 *)(iVar1 + iVar2) = uVar3;
  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
LAB_0072d8a4:
  *(undefined2 *)(in_EAX + 0x16b8) = 0;
  *(undefined4 *)(in_EAX + 0x16bc) = 0;
  return;
}

