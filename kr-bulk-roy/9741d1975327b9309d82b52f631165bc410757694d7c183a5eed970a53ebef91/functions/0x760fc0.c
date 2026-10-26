
void FUN_00760fc0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x24) != 0) {
    puVar1 = *(undefined4 **)(unaff_EDI + 100);
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      FUN_00748b00(param_1,*(undefined4 *)(unaff_EDI + 0x2c),*(undefined4 *)(unaff_EDI + 0x30),
                   *(undefined4 *)(unaff_EDI + 0x34),*(undefined4 *)(unaff_EDI + 0x38));
    }
  }
  return;
}

