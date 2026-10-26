
undefined4 * FUN_00580c60(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091fb90;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  cVar1 = FUN_00556670();
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar2 = FUN_00580e20(*param_2,param_2[1],*param_1,param_1);
    param_1[1] = uVar2;
  }
  ExceptionList = local_10;
  return param_1;
}

