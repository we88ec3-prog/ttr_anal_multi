
undefined4 FUN_008cb0d0(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 100);
  if (iVar1 == 0) {
    if ((param_2 <= *(int *)(unaff_EDI + 0x48)) && (*(int *)(unaff_EDI + 0x48) <= param_2))
    goto LAB_008cb1a7;
  }
  else {
    if (iVar1 == 1) {
      uVar2 = *(uint *)(unaff_EDI + 0x48);
      if ((int)uVar2 <= param_2) goto LAB_008cb1a7;
      cVar3 = FUN_008caa50(*(int *)(unaff_EDI + 8) <=
                           (int)(uVar2 - (-*(int *)(unaff_EDI + 4) & uVar2)));
    }
    else {
      if ((iVar1 != 2) || (iVar1 = *(int *)(unaff_EDI + 0x48), param_2 <= iVar1)) goto LAB_008cb1a7;
      cVar3 = FUN_008caa50(*(int *)(unaff_EDI + 8) <=
                           (*(int *)(unaff_EDI + 4) + -1 + iVar1 & -*(int *)(unaff_EDI + 4)) - iVar1
                          );
    }
    if (cVar3 != '\0') {
      return 1;
    }
  }
  cVar3 = FUN_008ca9a0();
  if (cVar3 != '\0') {
    return 1;
  }
LAB_008cb1a7:
  if (*(int *)(unaff_EDI + 100) == 1) {
    cVar3 = FUN_008cad20(*(undefined4 *)(unaff_EDI + 0x44),param_2,*(undefined4 *)(unaff_EDI + 0x50)
                        );
    if (cVar3 != '\0') {
      return 1;
    }
  }
  else if ((*(int *)(unaff_EDI + 100) == 2) && (cVar3 = FUN_008caeb0(), cVar3 != '\0')) {
    return 1;
  }
  *(int *)(unaff_EDI + 0x48) = param_2;
  *(undefined4 *)(unaff_EDI + 0x44) = param_1;
  return 0;
}

