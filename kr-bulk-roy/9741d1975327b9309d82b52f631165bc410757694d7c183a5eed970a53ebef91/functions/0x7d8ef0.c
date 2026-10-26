
undefined2 * FUN_007d8ef0(undefined2 *param_1)

{
  undefined2 *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911796;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *unaff_EDI;
  *(undefined4 *)(param_1 + 0xc) = 0xf;
  *(undefined4 *)(param_1 + 10) = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  FUN_00403040(unaff_EDI + 2,0,0xffffffff);
  local_8 = 0;
  *(undefined1 *)(param_1 + 0x10) = *(undefined1 *)(unaff_EDI + 0x10);
  *(undefined1 *)((int)param_1 + 0x21) = *(undefined1 *)((int)unaff_EDI + 0x21);
  *(undefined4 *)(param_1 + 0x12) = *(undefined4 *)(unaff_EDI + 0x12);
  *(undefined1 *)(param_1 + 0x14) = *(undefined1 *)(unaff_EDI + 0x14);
  *(undefined1 *)((int)param_1 + 0x29) = *(undefined1 *)((int)unaff_EDI + 0x29);
  FUN_007d8fa0(param_1 + 0x16);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_007d8fa0(param_1 + 0x34);
  ExceptionList = local_10;
  return param_1;
}

