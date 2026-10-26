
uint FUN_006fe6d0(void)

{
  short sVar1;
  int in_EAX;
  uint uVar2;
  
  if ((*(char *)(in_EAX + 6) != '\x01') &&
     ((*(char *)(in_EAX + 6) != '\0' || (*(int *)(in_EAX + 0x14) != *(int *)(in_EAX + 0x28))))) {
    uVar2 = FUN_006fe660();
    return uVar2;
  }
  if (199 < *(ushort *)(in_EAX + 0x34)) {
    uVar2 = FUN_006fe660();
    return uVar2;
  }
  sVar1 = *(ushort *)(in_EAX + 0x34) + 1;
  *(short *)(in_EAX + 0x34) = sVar1;
  *(short *)(in_EAX + 0x36) = sVar1;
  uVar2 = FUN_006fdba0();
  if (uVar2 != 0) {
    *(char *)(in_EAX + 6) = (char)uVar2;
    FUN_006fda60();
    *(undefined4 *)(*(int *)(in_EAX + 0x14) + 8) = *(undefined4 *)(in_EAX + 8);
    *(short *)(in_EAX + 0x34) = *(short *)(in_EAX + 0x34) + -1;
    return uVar2;
  }
  *(short *)(in_EAX + 0x34) = *(short *)(in_EAX + 0x34) + -1;
  return (uint)*(byte *)(in_EAX + 6);
}

