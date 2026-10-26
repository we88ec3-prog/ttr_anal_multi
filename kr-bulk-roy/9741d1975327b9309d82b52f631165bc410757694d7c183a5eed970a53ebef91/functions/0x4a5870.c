
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a5870(void)

{
  int iVar1;
  int unaff_EDI;
  int local_c;
  uint local_8;
  
  if (*(char *)(*(int *)(unaff_EDI + 0x108) + 0x14) != '\0') {
    FUN_004a5520(unaff_EDI);
    *(undefined1 *)(*(int *)(unaff_EDI + 0x108) + 0x14) = 0;
  }
  iVar1 = *(int *)(*(int *)(unaff_EDI + 0xfc) + 0xcc);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xdc) != 0)) {
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0xdc);
    }
    if (*(int *)(iVar1 + 0x254) == 0) {
      local_8 = (uint)_DAT_00000000;
      iVar1 = *(int *)(unaff_EDI + 0x108);
      FUN_004a4cc0(&local_8);
      FUN_004a5970(0,local_c != *(int *)(iVar1 + 4));
    }
  }
  return;
}

