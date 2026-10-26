
int * FUN_007a4790(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091517a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = (int)&PTR_00bf9598;
  param_1[4] = (int)&PTR_00c4f5dc;
  param_1[0x18] = (int)std::basic_ios<char,std::char_traits<char>_>::vftable;
  piVar1 = param_1 + 6;
  local_8 = 0;
  FUN_00782c20(param_1,piVar1);
  *(undefined ***)((int)param_1 + *(int *)(param_1[4] + 4) + 0x10) =
       std::basic_ostream<char,std::char_traits<char>_>::vftable;
  *(undefined ***)((int)param_1 + *(int *)(*param_1 + 4)) =
       std::basic_iostream<char,std::char_traits<char>_>::vftable;
  local_8 = 4;
  *(undefined ***)((int)param_1 + *(int *)(*param_1 + 4)) =
       std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
  FUN_00730ad0(piVar1);
  local_8 = CONCAT31(local_8._1_3_,5);
  *piVar1 = (int)std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::vftable;
  iVar2 = param_2[4];
  if (0xf < (uint)param_2[5]) {
    param_2 = (undefined4 *)*param_2;
  }
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  if (iVar2 != 0) {
    FUN_00730b70(param_2,iVar2);
  }
  ExceptionList = local_10;
  return param_1;
}

