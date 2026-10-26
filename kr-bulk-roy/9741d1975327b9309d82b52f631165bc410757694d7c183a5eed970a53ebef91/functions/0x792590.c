
int FUN_00792590(int *param_1)

{
  int in_EAX;
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = (in_EAX - in_ECX) / 0x2c;
  if (0 < iVar2) {
    do {
      iVar1 = iVar2 / 2;
      if (*(int *)(iVar1 * 0x2c + 8 + in_ECX) < *param_1) {
        in_ECX = iVar1 * 0x2c + 0x2c + in_ECX;
        iVar1 = iVar2 + (-1 - iVar1);
      }
      iVar2 = iVar1;
    } while (0 < iVar1);
  }
  return in_ECX;
}

