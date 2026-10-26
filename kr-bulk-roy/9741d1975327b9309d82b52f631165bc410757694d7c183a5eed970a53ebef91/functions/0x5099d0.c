
int FUN_005099d0(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  if ((in_ECX != -0x16f8) && (iVar3 = *(int *)(in_ECX + 0x2398), 0 < iVar3)) {
    piVar2 = (int *)(in_ECX + 0x1720);
    do {
      if ((piVar2[1] == 0) && (*piVar2 == 0)) {
        iVar1 = iVar1 + 1;
      }
      piVar2 = piVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar1;
}

