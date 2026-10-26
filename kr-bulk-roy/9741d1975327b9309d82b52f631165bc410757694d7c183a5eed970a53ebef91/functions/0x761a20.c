
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00761a20(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EDI;
  
  if (0 < *(int *)(unaff_EDI + 0x14c)) {
    if ((_DAT_00fe2ffc & 1) == 0) {
      _DAT_00fe2ffc = _DAT_00fe2ffc | 1;
      _DAT_00fe3000 = 1;
      _DAT_00fe3004 = 0;
      _atexit((_func_4879 *)&DAT_00bcfed0);
    }
    if (*(uint *)(unaff_EDI + 0x118) < *(uint *)(unaff_EDI + 0x14c)) {
      return;
    }
    iVar1 = FUN_00777030();
    if (iVar1 < 0) {
      return;
    }
    *(int *)(unaff_EDI + 0x14c) = *(int *)(unaff_EDI + 0x14c) - iVar1;
    if (*(int *)(unaff_EDI + 0x14c) < *(int *)(unaff_EDI + 0x168)) {
      *(int *)(unaff_EDI + 0x168) = *(int *)(unaff_EDI + 0x14c);
    }
  }
  iVar1 = *(int *)(*(int *)(unaff_EDI + 0x24) + 0x3d4);
  if ((((iVar1 != 1) && (iVar1 != 2)) &&
      (iVar1 = *(int *)(*(int *)(unaff_EDI + 0x24) + 0x404), iVar1 != 1)) && (iVar1 != 2)) {
    *(undefined4 *)(unaff_EDI + 0x160) = *(undefined4 *)(unaff_EDI + 0x14c);
    *(undefined4 *)(unaff_EDI + 0x164) = *(undefined4 *)(unaff_EDI + 0x14c);
    FUN_00761800();
    return;
  }
  uVar2 = *(undefined4 *)(unaff_EDI + 0x160);
  if (*(char *)(unaff_EDI + 0x150) != '\0') {
    uVar2 = *(undefined4 *)(unaff_EDI + 0x14c);
  }
  *(undefined4 *)(unaff_EDI + 0x164) = uVar2;
  FUN_00761800();
  return;
}

