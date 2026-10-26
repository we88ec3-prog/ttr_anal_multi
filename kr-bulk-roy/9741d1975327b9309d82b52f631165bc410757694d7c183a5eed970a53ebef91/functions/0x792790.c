
int FUN_00792790(int *param_1)

{
  int in_EAX;
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = (in_EAX - in_ECX) / 0x1c;
  if (0 < iVar2) {
    do {
      iVar1 = iVar2 / 2;
      if (*(int *)(in_ECX + 0x14 + iVar1 * 0x1c) < *param_1) {
        in_ECX = in_ECX + iVar1 * 0x1c + 0x1c;
        iVar1 = iVar2 + (-1 - iVar1);
      }
      iVar2 = iVar1;
    } while (0 < iVar1);
  }
  return in_ECX;
}

