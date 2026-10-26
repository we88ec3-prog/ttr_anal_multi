
int FUN_005093a0(void)

{
  int in_EAX;
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  iVar1 = in_EAX * 0x50 + -0x4f;
  if (iVar1 <= *(int *)(in_ECX + 0x2d18)) {
    piVar2 = (int *)(in_ECX + 8 + iVar1 * 0x18);
    do {
      if (in_EAX * 0x50 < iVar1) {
        return 0;
      }
      if ((piVar2[1] == 0) && (*piVar2 == 0)) {
        return iVar1 + in_EAX * -0x50 + 0x50;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 6;
    } while (iVar1 <= *(int *)(in_ECX + 0x2d18));
  }
  return 0;
}

