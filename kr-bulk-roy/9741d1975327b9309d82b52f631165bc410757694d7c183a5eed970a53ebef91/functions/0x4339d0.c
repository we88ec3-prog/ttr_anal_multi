
int * FUN_004339d0(int *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int *unaff_EDI;
  _Lockit local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00906789;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar1 = *(int *)unaff_EDI[0xe];
  *param_1 = iVar1;
  std::_Lockit::_Lockit(local_14,0);
  if (*(int *)(iVar1 + 4) != -1) {
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
  }
  FUN_0087dd6f(uVar2);
  local_8 = 0;
  (**(code **)(*unaff_EDI + 0x38))(param_2);
  FUN_00433950(unaff_EDI[0xe],param_2);
  ExceptionList = local_10;
  return param_1;
}

