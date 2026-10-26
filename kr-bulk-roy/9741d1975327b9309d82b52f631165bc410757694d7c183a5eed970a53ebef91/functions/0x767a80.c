
void FUN_00767a80(void)

{
  int in_EAX;
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (*(uint *)(in_EAX + 0x13c) < (uint)(*(int *)(in_EAX + 0x114) - *(int *)(in_EAX + 0x110) >> 2))
  {
    iVar3 = in_ECX + *(int *)(in_EAX + 0x140);
    do {
      iVar1 = iVar3 - *(int *)(*(int *)(*(int *)(in_EAX + 0x110) + *(int *)(in_EAX + 0x13c) * 4) +
                              0x10);
      if (iVar1 < 1) {
        *(int *)(in_EAX + 0x140) = iVar3;
        break;
      }
      *(int *)(in_EAX + 0x13c) = *(int *)(in_EAX + 0x13c) + 1;
      iVar3 = iVar1;
    } while (*(uint *)(in_EAX + 0x13c) <
             (uint)(*(int *)(in_EAX + 0x114) - *(int *)(in_EAX + 0x110) >> 2));
  }
  if (*(int *)(in_EAX + 0x140) != 0) {
    puVar2 = *(undefined4 **)(*(int *)(in_EAX + 0x110) + *(int *)(in_EAX + 0x13c) * 4);
    if (7 < (uint)puVar2[5]) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (*(short *)((int)puVar2 + *(int *)(in_EAX + 0x140) * 2 + -2) == 10) {
      *(int *)(in_EAX + 0x13c) = *(int *)(in_EAX + 0x13c) + 1;
      *(undefined4 *)(in_EAX + 0x140) = 0;
    }
  }
  return;
}

