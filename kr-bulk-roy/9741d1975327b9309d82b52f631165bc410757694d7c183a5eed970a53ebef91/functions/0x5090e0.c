
int FUN_005090e0(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int in_EDX;
  int iVar3;
  
  iVar1 = 0;
  piVar2 = (int *)(in_ECX + 0x28);
  iVar3 = 0x14;
  do {
    if (piVar2[1] == in_EDX) {
      iVar1 = iVar1 + *piVar2;
    }
    if (piVar2[9] == in_EDX) {
      iVar1 = iVar1 + piVar2[8];
    }
    if (piVar2[0x11] == in_EDX) {
      iVar1 = iVar1 + piVar2[0x10];
    }
    if (piVar2[0x19] == in_EDX) {
      iVar1 = iVar1 + piVar2[0x18];
    }
    if (piVar2[0x21] == in_EDX) {
      iVar1 = iVar1 + piVar2[0x20];
    }
    piVar2 = piVar2 + 0x28;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return iVar1;
}

