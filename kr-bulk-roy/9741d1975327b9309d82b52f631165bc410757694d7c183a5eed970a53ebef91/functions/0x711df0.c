
undefined4 FUN_00711df0(int *param_1)

{
  uint *puVar1;
  uint uVar2;
  int in_EAX;
  uint in_ECX;
  uint *puVar3;
  
  puVar1 = (uint *)(*(int *)(*param_1 + 0xc) + in_EAX * 4);
  if ((in_EAX < 1) || (puVar3 = puVar1 + -1, ((&DAT_00c0b914)[puVar1[-1] & 0x3f] & 0x80) == 0)) {
    puVar3 = puVar1;
  }
  uVar2 = *puVar3;
  if (((byte)uVar2 & 0x3f) != 0x1b) {
    return 0;
  }
  if ((in_ECX != 0xff) && (in_ECX != uVar2 >> 0x17)) {
    *puVar3 = (in_ECX << 6 ^ uVar2) & 0x3fc0 ^ uVar2;
    return 1;
  }
  *puVar3 = (uVar2 & 0xffb5ffff | 0x340000) >> 0x11 | uVar2 & 0x7fc000;
  return 1;
}

