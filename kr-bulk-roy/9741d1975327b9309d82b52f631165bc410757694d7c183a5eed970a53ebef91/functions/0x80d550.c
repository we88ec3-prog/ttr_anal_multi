
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0080d550(void)

{
  int *in_ECX;
  
  if ((_DAT_00fe37d4 & 1) == 0) {
    _DAT_00fe37d4 = _DAT_00fe37d4 | 1;
    _DAT_00fe37c8 = 0;
    _DAT_00fe37cc = 0;
    _DAT_00fe37d0 = 0;
  }
  (**(code **)(*in_ECX + 0x10))(&DAT_00fe37c8,1);
  return;
}

