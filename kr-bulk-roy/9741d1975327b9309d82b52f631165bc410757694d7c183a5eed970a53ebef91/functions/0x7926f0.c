
int FUN_007926f0(int param_1)

{
  int *in_EAX;
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = in_ECX - param_1 >> 4;
  if (0 < iVar2) {
    do {
      iVar1 = iVar2 / 2;
      if (*(int *)(param_1 + 8 + iVar1 * 0x10) < *in_EAX) {
        param_1 = param_1 + 0x10 + iVar1 * 0x10;
        iVar1 = iVar2 + (-1 - iVar1);
      }
      iVar2 = iVar1;
    } while (0 < iVar1);
  }
  return param_1;
}

