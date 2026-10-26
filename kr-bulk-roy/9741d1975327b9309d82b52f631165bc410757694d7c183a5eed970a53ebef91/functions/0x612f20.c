
void FUN_00612f20(undefined4 param_1,uint param_2)

{
  undefined4 in_stack_00000018;
  uint in_stack_0000001c;
  undefined4 in_stack_00000024;
  uint in_stack_00000038;
  undefined4 in_stack_00000040;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091d4d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_004026e0();
  local_8._0_1_ = 2;
  FUN_004026e0(&param_2,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00613740(param_1);
  if (7 < in_stack_0000001c) {
    FUN_0089120c();
  }
  in_stack_0000001c = 7;
  in_stack_00000018 = 0;
  param_2 = param_2 & 0xffff0000;
  if (7 < in_stack_00000038) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

