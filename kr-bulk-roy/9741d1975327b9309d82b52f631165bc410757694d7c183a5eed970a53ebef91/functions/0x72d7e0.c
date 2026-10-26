
void FUN_0072d7e0(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x16bc) == 0x10) {
    *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
         *(undefined1 *)(in_EAX + 0x16b8);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
         *(undefined1 *)(in_EAX + 0x16b9);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(undefined2 *)(in_EAX + 0x16b8) = 0;
    *(undefined4 *)(in_EAX + 0x16bc) = 0;
    return;
  }
  if (7 < *(int *)(in_EAX + 0x16bc)) {
    *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
         *(undefined1 *)(in_EAX + 0x16b8);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(int *)(in_EAX + 0x16bc) = *(int *)(in_EAX + 0x16bc) + -8;
    *(ushort *)(in_EAX + 0x16b8) = (ushort)*(byte *)(in_EAX + 0x16b9);
  }
  return;
}

