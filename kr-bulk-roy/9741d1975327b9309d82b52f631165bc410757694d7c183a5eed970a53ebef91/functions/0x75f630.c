
void FUN_0075f630(int param_1)

{
  int unaff_EDI;
  
  FUN_00404ed0();
  *(undefined4 *)(unaff_EDI + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  if (unaff_EDI + 0xa8 != param_1 + 0xa8) {
    FUN_005540c0(**(undefined4 **)(unaff_EDI + 0xac),*(undefined4 **)(unaff_EDI + 0xac));
    FUN_005c7580(param_1 + 0xa8);
  }
  if (unaff_EDI + 0xb8 != param_1 + 0xb8) {
    FUN_005540c0(**(undefined4 **)(unaff_EDI + 0xbc),*(undefined4 **)(unaff_EDI + 0xbc));
    FUN_005c7580(param_1 + 0xb8);
  }
  *(undefined4 *)(unaff_EDI + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(unaff_EDI + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(unaff_EDI + 0xd0) = *(undefined4 *)(param_1 + 0xd0);
  *(undefined4 *)(unaff_EDI + 0xd4) = *(undefined4 *)(param_1 + 0xd4);
  return;
}

