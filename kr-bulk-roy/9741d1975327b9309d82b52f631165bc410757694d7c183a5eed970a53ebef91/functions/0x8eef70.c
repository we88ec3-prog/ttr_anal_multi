
void FUN_008eef70(void)

{
  byte *pbVar1;
  int in_EAX;
  byte bVar2;
  ushort *in_ECX;
  
  if (*in_ECX < *(ushort *)(in_EAX + 0x2c)) {
    bVar2 = 0xff;
    if (*(short *)(in_EAX + 0x12a) != 0) {
      bVar2 = 0xf7;
    }
    if (*(short *)(in_EAX + 300) != 0) {
      bVar2 = bVar2 & 0xef;
    }
    pbVar1 = (byte *)(*(int *)(in_EAX + 0x3c) + (uint)*in_ECX);
    *pbVar1 = *pbVar1 & bVar2;
  }
  else if (*(char *)(in_EAX + 0x231) != '\0') {
    *(undefined4 *)(in_EAX + 0xc) = 0x86;
    return;
  }
  return;
}

