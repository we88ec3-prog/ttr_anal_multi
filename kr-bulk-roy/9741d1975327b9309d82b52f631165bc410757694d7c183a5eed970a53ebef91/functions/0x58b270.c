
undefined4 FUN_0058b270(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 in_stack_00000018;
  uint in_stack_0000001c;
  undefined4 in_stack_00000024;
  uint in_stack_00000038;
  undefined4 in_stack_00000040;
  undefined4 in_stack_00000044;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092e35e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  puVar2 = param_2;
  if (in_stack_0000001c < 8) {
    puVar2 = &param_2;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    FUN_0074d990(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  uVar1 = FUN_007532b0(&DAT_00f94810,puVar2,in_stack_00000040,in_stack_00000044);
  if (7 < in_stack_0000001c) {
    FUN_0089120c(param_2);
  }
  in_stack_0000001c = 7;
  in_stack_00000018 = 0;
  param_2 = (undefined4 *)((uint)param_2 & 0xffff0000);
  if (7 < in_stack_00000038) {
    FUN_0089120c(in_stack_00000024);
  }
  ExceptionList = local_10;
  return uVar1;
}

