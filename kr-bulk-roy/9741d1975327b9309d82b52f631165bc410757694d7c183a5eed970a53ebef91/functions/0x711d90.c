
undefined4 FUN_00711d90(void)

{
  uint *puVar1;
  int *in_EAX;
  int iVar2;
  int in_EDX;
  uint *puVar3;
  
  if (in_EDX != -1) {
    do {
      puVar1 = (uint *)(*(int *)(*in_EAX + 0xc) + in_EDX * 4);
      if ((in_EDX < 1) || (puVar3 = puVar1 + -1, ((&DAT_00c0b914)[puVar1[-1] & 0x3f] & 0x80) == 0))
      {
        puVar3 = puVar1;
      }
      if (((byte)*puVar3 & 0x3f) != 0x1b) {
        return 1;
      }
      iVar2 = (*puVar1 >> 0xe) - 0x1ffff;
    } while ((iVar2 != -1) && (in_EDX = in_EDX + 1 + iVar2, in_EDX != -1));
  }
  return 0;
}

