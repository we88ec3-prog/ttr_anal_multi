
int FUN_00508e00(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  piVar2 = (int *)(in_ECX + 0x48);
  iVar3 = 0x14;
  do {
    if (0 < piVar2[-8]) {
      iVar1 = iVar1 + 1;
    }
    if (0 < *piVar2) {
      iVar1 = iVar1 + 1;
    }
    if (0 < piVar2[8]) {
      iVar1 = iVar1 + 1;
    }
    if (0 < piVar2[0x10]) {
      iVar1 = iVar1 + 1;
    }
    if (0 < piVar2[0x18]) {
      iVar1 = iVar1 + 1;
    }
    piVar2 = piVar2 + 0x28;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return iVar1;
}

