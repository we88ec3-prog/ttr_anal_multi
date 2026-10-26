
undefined1 FUN_0061d0c0(int param_1,int param_2)

{
  undefined1 uVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  
  uVar1 = 1;
  if (((in_ECX == 0) || (in_ECX == 1)) && (param_2 == 6)) {
    iVar3 = 0;
    do {
      if ((in_ECX != 1) || (iVar2 = 5, iVar3 != 6)) {
        iVar2 = iVar3;
      }
      if (*(char *)(*(int *)(param_1 + (iVar2 + (in_ECX + 0xb) * 7) * 4) + 0x250) != '\0') {
        uVar1 = 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 7);
  }
  return uVar1;
}

