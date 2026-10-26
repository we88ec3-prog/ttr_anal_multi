
void FUN_00711e80(void)

{
  uint uVar1;
  int in_EAX;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  int *in_EDX;
  
  while( true ) {
    if (in_EAX == -1) {
      return;
    }
    puVar2 = (uint *)(*(int *)(*in_EDX + 0xc) + in_EAX * 4);
    if ((in_EAX < 1) || (puVar4 = puVar2 + -1, ((&DAT_00c0b914)[puVar2[-1] & 0x3f] & 0x80) == 0)) {
      puVar4 = puVar2;
    }
    uVar1 = *puVar4;
    if (((byte)uVar1 & 0x3f) == 0x1b) {
      *puVar4 = (uVar1 & 0xffb5ffff | 0x340000) >> 0x11 | uVar1 & 0x7fc000;
    }
    iVar3 = (*(uint *)(in_EAX * 4 + *(int *)(*in_EDX + 0xc)) >> 0xe) - 0x1ffff;
    if (iVar3 == -1) break;
    in_EAX = in_EAX + 1 + iVar3;
  }
  return;
}

