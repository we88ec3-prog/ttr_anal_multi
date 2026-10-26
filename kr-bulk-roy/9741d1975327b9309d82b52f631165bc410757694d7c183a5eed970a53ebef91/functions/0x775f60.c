
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00775f60(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0xc) + 8))();
  if ((_DAT_00fe2890 & 1) == 0) {
    _DAT_00fe2890 = _DAT_00fe2890 | 1;
    if ((_DAT_00fe37e8 & 1) == 0) {
      _DAT_00fe37e8 = _DAT_00fe37e8 | 1;
      DAT_00fe37e4 = FoxUI::CReferenceFontImplEntry::vftable;
    }
    DAT_00fe2894 = (int *)&DAT_00fe37e4;
    (*(code *)DAT_00fe37e4[1])(*(undefined4 *)(in_ECX + 0xc));
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  (**(code **)(*DAT_00fe2894 + 4))(*(undefined4 *)(in_ECX + 0xc));
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}

