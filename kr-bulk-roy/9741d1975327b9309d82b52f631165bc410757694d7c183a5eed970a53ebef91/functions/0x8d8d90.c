
int FUN_008d8d90(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 *in_ECX;
  int iVar3;
  
  iVar1 = *(int *)(in_EAX + 0x1c);
  if (*(char *)(in_EAX + 0x20) == '\0') {
    return 8;
  }
  if ((*(uint *)(iVar1 + 4) < (uint)(*(short *)(iVar1 + 0x3a) + 1 + (int)*(short *)(iVar1 + 0x16)))
     && (iVar2 = FUN_008bc9a0(iVar1,1,0), iVar2 != 0)) {
    return iVar2;
  }
  iVar3 = (int)*(short *)(iVar1 + 0x3a);
  iVar2 = *(int *)(iVar1 + 0x3c);
  *(undefined4 *)(iVar2 + iVar3 * 8) = *in_ECX;
  *(undefined4 *)(iVar2 + 4 + iVar3 * 8) = in_ECX[1];
  *(undefined1 *)(iVar3 + *(int *)(iVar1 + 0x40)) = 1;
  *(short *)(iVar1 + 0x3a) = *(short *)(iVar1 + 0x3a) + 1;
  return 0;
}

