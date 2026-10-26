
int FUN_00716eb0(int param_1,int param_2,undefined4 *param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  int unaff_EDI;
  int local_38;
  undefined4 *local_34;
  undefined **local_30;
  undefined **local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined1 local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009059f8;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  local_24 = param_2;
  local_30 = MemoryStream::vftable;
  local_2c = MemoryStream::vftable;
  local_28 = param_1;
  local_20 = 0;
  local_1c = 0;
  local_c = 0;
  *param_3 = 0;
  *param_4 = 0;
  iVar2 = FUN_00716d10(&local_30,uVar1);
  if (iVar2 < 0) {
    ExceptionList = local_14;
    return -3;
  }
  FUN_00719d20(local_20 + param_1,(local_24 - local_20) + -8);
  (*(code *)*local_2c)(&local_34,4);
  (*(code *)*local_34)(&stack0xffffffc0,4);
  local_34 = (undefined4 *)FUN_0087dc3d(unaff_EDI);
  iVar2 = FUN_00716e30(local_34);
  if (-1 < iVar2) {
    if (unaff_EDI != local_38) {
      ExceptionList = local_14;
      return -3;
    }
    *param_3 = local_34;
    *param_4 = unaff_EDI;
    iVar2 = 0;
  }
  ExceptionList = local_14;
  return iVar2;
}

