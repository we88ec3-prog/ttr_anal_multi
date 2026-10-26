
void FUN_008d8d00(int param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  if (*(char *)(param_1 + 0x20) != '\0') {
    sVar1 = *(short *)(iVar3 + 0x3a);
    sVar2 = *(short *)(iVar3 + 0x38);
    iVar5 = sVar1 + -1;
    iVar6 = 0;
    if (0 < sVar2) {
      iVar6 = (int)*(short *)(*(int *)(iVar3 + 0x44) + -2 + sVar2 * 2);
    }
    iVar4 = iVar5 - iVar6;
    if (iVar6 < iVar5) {
      iVar4 = *(int *)(iVar3 + 0x3c);
      if ((*(int *)(iVar4 + iVar6 * 8) == *(int *)(iVar4 + iVar5 * 8)) &&
         (*(int *)(iVar4 + 4 + iVar6 * 8) == *(int *)(iVar4 + 4 + iVar5 * 8))) {
        *(short *)(iVar3 + 0x3a) = *(short *)(iVar3 + 0x3a) + -1;
        iVar5 = sVar1 + -2;
      }
      iVar4 = iVar5 - iVar6;
    }
    if (SBORROW4(iVar5,iVar6) == iVar4 < 0) {
      *(short *)(*(int *)(iVar3 + 0x44) + sVar2 * 2) = (short)iVar5;
      *(short *)(iVar3 + 0x38) = *(short *)(iVar3 + 0x38) + 1;
    }
    *(undefined1 *)(param_1 + 0x20) = 0;
  }
  return;
}

