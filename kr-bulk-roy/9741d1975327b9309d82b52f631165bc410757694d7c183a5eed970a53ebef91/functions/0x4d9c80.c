
undefined2 * FUN_004d9c80(undefined2 *param_1)

{
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090d7f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_004026e0(unaff_EDI,0,0xffffffff);
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x18) = 7;
  *(undefined4 *)(param_1 + 0x16) = 0;
  param_1[0xe] = 0;
  FUN_004026e0(unaff_EDI + 0x1c,0,0xffffffff);
  *(undefined1 *)(param_1 + 0x1c) = *(undefined1 *)(unaff_EDI + 0x38);
  *(undefined1 *)((int)param_1 + 0x39) = *(undefined1 *)(unaff_EDI + 0x39);
  *(undefined4 *)(param_1 + 0x1e) = *(undefined4 *)(unaff_EDI + 0x3c);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(unaff_EDI + 0x40);
  ExceptionList = local_10;
  return param_1;
}

