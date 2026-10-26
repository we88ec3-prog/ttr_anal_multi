
int FUN_008e0f80(int param_1)

{
  longlong lVar1;
  int *piVar2;
  uint uVar3;
  int unaff_EDI;
  
  if ((*(int *)(unaff_EDI + 0x14) == 0) || (*(char *)(unaff_EDI + 0xd) == '\0')) {
    lVar1 = (longlong)param_1 * (longlong)*(int *)(unaff_EDI + 0x10);
    lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
    return ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
  }
  uVar3 = *(uint *)(unaff_EDI + 0x18);
  if (uVar3 < *(int *)(unaff_EDI + 0x14) - 1U) {
    piVar2 = (int *)(unaff_EDI + 0x38 + uVar3 * 0x14);
    do {
      if (param_1 < *piVar2) break;
      uVar3 = uVar3 + 1;
      piVar2 = piVar2 + 5;
    } while (uVar3 < *(int *)(unaff_EDI + 0x14) - 1U);
  }
  if (uVar3 != 0) {
    piVar2 = (int *)(unaff_EDI + 0x24 + uVar3 * 0x14);
    do {
      if (*piVar2 <= param_1) break;
      piVar2 = piVar2 + -5;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  *(uint *)(unaff_EDI + 0x18) = uVar3;
  if ((uVar3 == 0) && (param_1 < *(int *)(unaff_EDI + 0x24))) {
    lVar1 = (longlong)(param_1 - *(int *)(unaff_EDI + 0x24)) * (longlong)*(int *)(unaff_EDI + 0x10);
    lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
    return *(int *)(unaff_EDI + 0x28) +
           ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
  }
  lVar1 = (longlong)(param_1 - *(int *)(unaff_EDI + 0x24 + uVar3 * 0x14)) *
          (longlong)*(int *)(unaff_EDI + 0x2c + uVar3 * 0x14);
  lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
  return *(int *)(unaff_EDI + (uVar3 * 5 + 10) * 4) +
         ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
}

