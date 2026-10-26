
int FUN_00508dd0(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  iVar1 = 1;
  if (0 < *(int *)(in_ECX + 0xca0)) {
    piVar2 = (int *)(in_ECX + 0x28);
    do {
      if ((piVar2[1] == 0) && (*piVar2 == 0)) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 8;
    } while (iVar1 <= *(int *)(in_ECX + 0xca0));
  }
  return 0;
}

