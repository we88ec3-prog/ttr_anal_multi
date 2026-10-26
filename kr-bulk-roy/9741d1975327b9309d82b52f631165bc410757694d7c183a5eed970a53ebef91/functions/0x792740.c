
int FUN_00792740(int *param_1)

{
  int in_EAX;
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = (in_EAX - in_ECX) / 0x18;
  if (0 < iVar2) {
    do {
      iVar1 = iVar2 / 2;
      if (*(int *)(in_ECX + 0x10 + iVar1 * 0x18) < *param_1) {
        in_ECX = in_ECX + iVar1 * 0x18 + 0x18;
        iVar1 = iVar2 + (-1 - iVar1);
      }
      iVar2 = iVar1;
    } while (0 < iVar1);
  }
  return in_ECX;
}

