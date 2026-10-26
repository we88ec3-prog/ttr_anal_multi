
void FUN_00656a10(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 2) {
    FUN_00656f30();
  }
  iVar1 = 0xcf6c;
  do {
    iVar3 = 5;
    iVar2 = iVar1;
    do {
      if (param_1 == iVar2) {
        FUN_0045efe0(&param_1);
      }
      iVar2 = iVar2 + 1000;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar1 = iVar1 + 10000;
  } while (iVar1 < 0x16bac);
  return;
}

