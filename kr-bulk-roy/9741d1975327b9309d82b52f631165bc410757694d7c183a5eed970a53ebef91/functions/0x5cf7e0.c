
void FUN_005cf7e0(undefined2 *param_1)

{
  undefined2 *unaff_EDI;
  
  *unaff_EDI = *param_1;
  unaff_EDI[1] = param_1[1];
  unaff_EDI[2] = param_1[2];
  unaff_EDI[3] = param_1[3];
  unaff_EDI[4] = param_1[4];
  unaff_EDI[5] = param_1[5];
  if (unaff_EDI + 6 != param_1 + 6) {
    FUN_004ca160(**(undefined4 **)(unaff_EDI + 8),*(undefined4 **)(unaff_EDI + 8));
    FUN_005cfc80(param_1 + 6);
  }
  *(undefined4 *)(unaff_EDI + 0xe) = *(undefined4 *)(param_1 + 0xe);
  *(undefined4 *)(unaff_EDI + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(unaff_EDI + 0x12) = *(undefined4 *)(param_1 + 0x12);
  return;
}

