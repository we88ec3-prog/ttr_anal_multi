
void FUN_007a5730(int param_1)

{
  int unaff_EDI;
  
  if (unaff_EDI != param_1) {
    FUN_004ca160(**(undefined4 **)(unaff_EDI + 4),*(undefined4 **)(unaff_EDI + 4));
    FUN_007a1540(param_1);
  }
  if (unaff_EDI + 0x10 != param_1 + 0x10) {
    FUN_006d7120(**(undefined4 **)(unaff_EDI + 0x14),*(undefined4 **)(unaff_EDI + 0x14));
    FUN_007a1660(param_1 + 0x10);
  }
  return;
}

