
void FUN_00746020(void)

{
  undefined4 *puVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  if (*(int **)(unaff_ESI + 0x1c) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_ESI + 0x1c) + 0x1c))(1);
    *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  }
  if (unaff_EDI == 0) {
    puVar1 = _malloc(0xc);
    if (puVar1 != (undefined4 *)0x0) {
      DAT_00fba828 = DAT_00fba828 + 1;
      puVar1[1] = DAT_00fba828;
      *puVar1 = FoxUI::FXUIDockInfo::vftable;
      puVar1[2] = 6;
      *(undefined4 **)(unaff_ESI + 0x1c) = puVar1;
      return;
    }
    *(undefined4 *)(unaff_ESI + 0x1c) = 0;
    return;
  }
  *(int *)(unaff_ESI + 0x1c) = unaff_EDI;
  return;
}

