
int * FUN_00432890(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091bd4a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = (int)&PTR_00bf9598;
  param_1[4] = (int)&PTR_00c4f5dc;
  param_1[0x18] = (int)std::basic_ios<wchar_t,std::char_traits<wchar_t>_>::vftable;
  piVar1 = param_1 + 6;
  local_8 = 0;
  FUN_00431b90(param_1,piVar1);
  *(undefined ***)((int)param_1 + *(int *)(param_1[4] + 4) + 0x10) =
       std::basic_ostream<wchar_t,std::char_traits<wchar_t>_>::vftable;
  *(undefined ***)((int)param_1 + *(int *)(*param_1 + 4)) =
       std::basic_iostream<wchar_t,std::char_traits<wchar_t>_>::vftable;
  local_8 = 4;
  *(undefined ***)((int)param_1 + *(int *)(*param_1 + 4)) =
       std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::vftable;
  FUN_00431de0(piVar1);
  *piVar1 = (int)std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::
                 vftable;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  ExceptionList = local_10;
  return param_1;
}

