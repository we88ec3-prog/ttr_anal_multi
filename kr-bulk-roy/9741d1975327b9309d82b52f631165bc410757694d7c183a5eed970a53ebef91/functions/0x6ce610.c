
void FUN_006ce610(int param_1)

{
  int unaff_EDI;
  
  FUN_00403040(param_1,0,0xffffffff);
  FUN_00403040(param_1 + 0x1c,0,0xffffffff);
  *(undefined4 *)(unaff_EDI + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(unaff_EDI + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  if (unaff_EDI + 0x40 != param_1 + 0x40) {
    FUN_00535ac0(**(undefined4 **)(unaff_EDI + 0x44),*(undefined4 **)(unaff_EDI + 0x44));
    FUN_006cf030(param_1 + 0x40);
  }
  if (unaff_EDI + 0x50 != param_1 + 0x50) {
    FUN_00535ac0(**(undefined4 **)(unaff_EDI + 0x54),*(undefined4 **)(unaff_EDI + 0x54));
    FUN_006cf030(param_1 + 0x50);
  }
  if (unaff_EDI + 0x60 != param_1 + 0x60) {
    FUN_00535ac0(**(undefined4 **)(unaff_EDI + 100),*(undefined4 **)(unaff_EDI + 100));
    FUN_006cf030(param_1 + 0x60);
  }
  if (unaff_EDI + 0x70 != param_1 + 0x70) {
    FUN_00535ac0(**(undefined4 **)(unaff_EDI + 0x74),*(undefined4 **)(unaff_EDI + 0x74));
    FUN_006cf030(param_1 + 0x70);
  }
  return;
}

