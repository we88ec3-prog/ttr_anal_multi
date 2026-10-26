
/* WARNING: Removing unreachable block (ram,0x0084e05e) */
/* WARNING: Removing unreachable block (ram,0x0084e060) */

void FUN_0084e030(void)

{
  int iVar1;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x44);
  if (iVar1 != 0) {
    FUN_00857730(iVar1);
    FUN_0089120c(iVar1);
    *(undefined4 *)(unaff_EDI + 0x44) = 0;
  }
  if (*(int *)(unaff_EDI + 0x28) != *(int *)(unaff_EDI + 0x2c)) {
    *(int *)(unaff_EDI + 0x2c) = *(int *)(unaff_EDI + 0x28);
  }
  *(undefined4 *)(unaff_EDI + 0x38) = 1;
  return;
}

