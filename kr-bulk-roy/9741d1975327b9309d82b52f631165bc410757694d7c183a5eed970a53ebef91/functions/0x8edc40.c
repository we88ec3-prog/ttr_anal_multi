
void FUN_008edc40(void)

{
  byte *pbVar1;
  ushort uVar2;
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x10) < *(int *)(in_EAX + 0x130)) {
    if (*(char *)(in_EAX + 0x231) != '\0') {
      *(undefined4 *)(in_EAX + 0xc) = 0x81;
    }
  }
  else if (0 < *(int *)(in_EAX + 0x130)) {
    do {
      *(int *)(in_EAX + 0x1c) = *(int *)(in_EAX + 0x1c) + -1;
      uVar2 = *(ushort *)(*(int *)(in_EAX + 0x18) + *(int *)(in_EAX + 0x1c) * 4);
      if (uVar2 < *(ushort *)(in_EAX + 0x98)) {
        pbVar1 = (byte *)((uint)uVar2 + *(int *)(in_EAX + 0xa8));
        *pbVar1 = *pbVar1 ^ 1;
      }
      else if (*(char *)(in_EAX + 0x231) != '\0') {
        *(undefined4 *)(in_EAX + 0xc) = 0x86;
        return;
      }
      *(int *)(in_EAX + 0x130) = *(int *)(in_EAX + 0x130) + -1;
    } while (0 < *(int *)(in_EAX + 0x130));
    *(undefined4 *)(in_EAX + 0x130) = 1;
    *(undefined4 *)(in_EAX + 0x20) = *(undefined4 *)(in_EAX + 0x1c);
    return;
  }
  *(undefined4 *)(in_EAX + 0x130) = 1;
  *(undefined4 *)(in_EAX + 0x20) = *(undefined4 *)(in_EAX + 0x1c);
  return;
}

