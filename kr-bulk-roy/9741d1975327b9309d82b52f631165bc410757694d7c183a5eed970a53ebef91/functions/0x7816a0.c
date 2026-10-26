
int * FUN_007816a0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00911a97;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = (int)&PTR_00c4ee00;
  param_1[0x1a] = (int)std::basic_ios<char,std::char_traits<char>_>::vftable;
  piVar1 = param_1 + 4;
  local_8 = 0;
  FUN_00782c20(param_1,piVar1);
  local_8 = 1;
  *(undefined ***)((int)param_1 + *(int *)(*param_1 + 4)) = std::istrstream::vftable;
  FUN_00730ad0(piVar1);
  *piVar1 = (int)std::strstreambuf::vftable;
  FUN_007815d0(param_3,param_4);
  ExceptionList = local_10;
  return param_1;
}

