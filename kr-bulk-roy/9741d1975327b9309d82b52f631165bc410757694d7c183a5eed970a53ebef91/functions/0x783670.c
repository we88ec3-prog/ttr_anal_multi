
int * FUN_00783670(int *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00915342;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = (int)&PTR_00bf9598;
  param_1[0x18] = (int)std::basic_ios<char,std::char_traits<char>_>::vftable;
  piVar1 = param_1 + 1;
  local_8 = 0;
  FUN_007309e0(param_1,piVar1);
  local_8 = 1;
  *(undefined ***)((int)param_1 + *(int *)(*param_1 + 4)) =
       std::basic_ofstream<char,std::char_traits<char>_>::vftable;
  FUN_00730ad0(piVar1);
  *piVar1 = (int)std::basic_filebuf<char,std::char_traits<char>_>::vftable;
  *(undefined1 *)(param_1 + 0x15) = 0;
  *(undefined1 *)((int)param_1 + 0x4d) = 0;
  FUN_00730d00(uVar2);
  iVar3 = DAT_00fe31e4;
  param_1[0x16] = 0;
  param_1[0x14] = iVar3;
  param_1[0x12] = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar3 = FUN_00783970(0x22);
  if (iVar3 == 0) {
    FUN_00431a90(0);
  }
  ExceptionList = local_10;
  return param_1;
}

