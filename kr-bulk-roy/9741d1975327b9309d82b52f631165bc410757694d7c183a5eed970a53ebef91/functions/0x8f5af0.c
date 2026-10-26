
int FUN_008f5af0(void)

{
  int in_EAX;
  int in_ECX;
  int iVar1;
  uint uVar2;
  int in_EDX;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_8;
  
  iVar5 = 0x62;
  iVar3 = in_EAX;
  if (0 < in_ECX) {
    piVar4 = (int *)(in_EDX + 4);
    local_8 = in_ECX;
    do {
      iVar1 = in_EAX - *piVar4;
      if (iVar1 < 0) {
        iVar1 = -iVar1;
      }
      if (iVar1 < iVar5) {
        iVar3 = *piVar4;
        iVar5 = iVar1;
      }
      piVar4 = piVar4 + 3;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  uVar2 = iVar3 + 0x20U & 0xffffffc0;
  if (in_EAX < iVar3) {
    if ((int)(uVar2 - 0x30) < in_EAX) {
      in_EAX = iVar3;
    }
  }
  else if (in_EAX < (int)(uVar2 + 0x30)) {
    return iVar3;
  }
  return in_EAX;
}

