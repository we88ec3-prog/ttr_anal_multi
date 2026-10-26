
undefined4 FUN_007c5600(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00914c99;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_007c5670(param_1);
  local_8 = 0;
  FUN_00401fc0("Texture/",8);
  ExceptionList = local_10;
  return param_1;
}

