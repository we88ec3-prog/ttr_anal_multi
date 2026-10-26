
void FUN_008110c0(void)

{
  undefined4 in_ECX;
  int unaff_ESI;
  
  if (DAT_00fba90c != (HMODULE)0x0) {
    FreeLibrary(DAT_00fba90c);
    DAT_00fba90c = (HMODULE)0x0;
  }
  if (*(int *)(unaff_ESI + 0x104) != 0) {
    FUN_00811ac0(*(undefined4 *)(unaff_ESI + 0x108),in_ECX);
    FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x104));
  }
  *(undefined4 *)(unaff_ESI + 0x104) = 0;
  *(undefined4 *)(unaff_ESI + 0x108) = 0;
  *(undefined4 *)(unaff_ESI + 0x10c) = 0;
  return;
}

