
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00775ef0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int in_ECX;
  
  if ((_DAT_00fe2890 & 1) == 0) {
    _DAT_00fe2890 = _DAT_00fe2890 | 1;
    if ((_DAT_00fe37e8 & 1) == 0) {
      _DAT_00fe37e8 = _DAT_00fe37e8 | 1;
      DAT_00fe37e4 = FoxUI::CReferenceFontImplEntry::vftable;
    }
    DAT_00fe2894 = &DAT_00fe37e4;
  }
  piVar1 = (int *)(**(code **)*DAT_00fe2894)();
  *(int **)(in_ECX + 0xc) = piVar1;
  (**(code **)(*piVar1 + 4))
            (param_1,*(undefined4 *)(in_ECX + 0x10),*(undefined1 *)(in_ECX + 0x14),param_2);
  return;
}

