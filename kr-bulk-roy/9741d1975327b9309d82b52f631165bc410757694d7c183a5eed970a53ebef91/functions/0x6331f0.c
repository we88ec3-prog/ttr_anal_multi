
void FUN_006331f0(undefined4 param_1,uint param_2)

{
  undefined4 in_stack_00000018;
  uint in_stack_0000001c;
  undefined4 in_stack_00000028;
  uint in_stack_0000003c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091a268;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_004026e0();
  local_8._0_1_ = 2;
  FUN_004026e0(&param_2,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00633300(param_1);
  if (7 < in_stack_0000001c) {
    FUN_0089120c();
  }
  in_stack_0000001c = 7;
  in_stack_00000018 = 0;
  param_2 = param_2 & 0xffff0000;
  if (7 < in_stack_0000003c) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

