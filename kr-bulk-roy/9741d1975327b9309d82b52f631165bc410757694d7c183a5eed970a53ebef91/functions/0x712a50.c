
void FUN_00712a50(void)

{
  uint uVar1;
  int in_EAX;
  int *in_ECX;
  uint *puVar2;
  
  puVar2 = (uint *)(*(int *)(*in_ECX + 0xc) + *(int *)(in_EAX + 8) * 4);
  if ((0 < *(int *)(in_EAX + 8)) && (((&DAT_00c0b914)[puVar2[-1] & 0x3f] & 0x80) != 0)) {
    puVar2 = puVar2 + -1;
  }
  uVar1 = *puVar2;
  *puVar2 = ((uint)((uVar1 & 0x3fc0) == 0) * 0x40 ^ uVar1) & 0x3fc0 ^ uVar1;
  return;
}

