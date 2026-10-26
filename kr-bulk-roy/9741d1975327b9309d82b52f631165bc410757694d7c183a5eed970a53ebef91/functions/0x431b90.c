
int * FUN_00431b90(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_009135f0;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)((int)param_1 + *(int *)(*param_1 + 4)) =
       std::basic_istream<wchar_t,std::char_traits<wchar_t>_>::vftable;
  param_1[2] = 0;
  param_1[3] = 0;
  iVar1 = *(int *)(*param_1 + 4);
  FUN_004310f0(uVar3);
  *(undefined4 *)((int)param_1 + iVar1 + 0x38) = param_2;
  *(undefined4 *)((int)param_1 + iVar1 + 0x3c) = 0;
  uVar2 = FUN_00431950();
  *(undefined2 *)((int)param_1 + iVar1 + 0x40) = uVar2;
  if (*(int *)((int)param_1 + iVar1 + 0x38) == 0) {
    FUN_00431a90(0);
  }
  ExceptionList = local_10;
  return param_1;
}

