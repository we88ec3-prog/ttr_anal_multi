
void FUN_0046df80(undefined4 *param_1)

{
  undefined4 in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009066f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0046e070(*param_1,in_EDX,param_1);
  ExceptionList = local_10;
  return;
}

