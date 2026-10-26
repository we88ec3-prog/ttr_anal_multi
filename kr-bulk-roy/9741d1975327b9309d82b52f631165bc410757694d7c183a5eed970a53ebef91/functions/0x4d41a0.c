
undefined4 FUN_004d41a0(void)

{
  int in_EAX;
  int in_ECX;
  
  *(uint *)(in_ECX + 8) = (uint)*(byte *)(in_EAX + 3);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(in_EAX + 4);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(in_EAX + 8);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(in_EAX + 0xc);
  *(uint *)(in_ECX + 0x40) = (uint)*(ushort *)(in_EAX + 0x10);
  *(uint *)(in_ECX + 0x48) = (uint)*(ushort *)(in_EAX + 0x12);
  *(uint *)(in_ECX + 0x44) = (uint)*(ushort *)(in_EAX + 0x14);
  *(uint *)(in_ECX + 0x60) = (uint)*(ushort *)(in_EAX + 0x16);
  *(uint *)(in_ECX + 100) = (uint)*(ushort *)(in_EAX + 0x18);
  *(uint *)(in_ECX + 0x68) = (uint)*(ushort *)(in_EAX + 0x1a);
  *(uint *)(in_ECX + 0x6c) = (uint)*(ushort *)(in_EAX + 0x1c);
  *(uint *)(in_ECX + 0x70) = (uint)*(ushort *)(in_EAX + 0x1e);
  *(uint *)(in_ECX + 0x74) = (uint)*(ushort *)(in_EAX + 0x20);
  *(uint *)(in_ECX + 0xd4) = (uint)*(byte *)(in_EAX + 0x22);
  return 1;
}

