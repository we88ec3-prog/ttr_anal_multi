
int FUN_005495f0(int param_1)

{
  int in_EAX;
  int iVar1;
  uint *puVar2;
  
  if (in_EAX == 0) {
    return -1;
  }
  iVar1 = 0;
  puVar2 = (uint *)(param_1 + 0xa8);
  do {
    if (*puVar2 == (uint)*(ushort *)(in_EAX + 4)) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 4;
  } while (iVar1 < 3);
  return -1;
}

