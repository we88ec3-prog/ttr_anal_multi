
undefined4 FUN_0045cc80(char param_1,char param_2,byte param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0xc);
  uVar2 = 0;
  uVar3 = *(int *)(unaff_EDI + 0x10) - iVar1 >> 1;
  if (uVar3 != 0) {
    do {
      if ((*(char *)(iVar1 + uVar2 * 2) == param_1) && (*(char *)(iVar1 + 1 + uVar2 * 2) == param_2)
         ) goto LAB_0045ccba;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar3);
  }
  if (iVar1 == *(int *)(unaff_EDI + 0x10)) {
LAB_0045ccba:
    if (param_3 < *(byte *)(unaff_EDI + 0x1c)) {
      return 1;
    }
  }
  return 0;
}

