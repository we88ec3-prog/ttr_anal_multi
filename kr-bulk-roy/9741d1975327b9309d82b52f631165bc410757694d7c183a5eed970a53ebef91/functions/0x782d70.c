
int * FUN_00782d70(int *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00915392;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = (int)&PTR_00c4ee00;
  param_1[0x1a] = (int)std::basic_ios<char,std::char_traits<char>_>::vftable;
  piVar1 = param_1 + 4;
  local_8 = 0;
  FUN_00782c20(param_1,piVar1);
  local_8 = 1;
  *(undefined ***)((int)param_1 + *(int *)(*param_1 + 4)) =
       std::basic_ifstream<char,std::char_traits<char>_>::vftable;
  FUN_00730ad0(piVar1);
  *piVar1 = (int)std::basic_filebuf<char,std::char_traits<char>_>::vftable;
  *(undefined1 *)(param_1 + 0x18) = 0;
  *(undefined1 *)((int)param_1 + 0x59) = 0;
  FUN_00730d00(uVar2);
  iVar3 = DAT_00fe31e4;
  param_1[0x19] = 0;
  param_1[0x17] = iVar3;
  param_1[0x15] = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar3 = FUN_00783970(0x21);
  if (iVar3 == 0) {
    FUN_00431a90(0);
  }
  ExceptionList = local_10;
  return param_1;
}

