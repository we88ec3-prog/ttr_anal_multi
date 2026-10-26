
void FUN_00678310(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009081d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00678380(param_1,*(undefined4 *)*param_1,param_2,param_3,param_1);
  ExceptionList = local_10;
  return;
}

