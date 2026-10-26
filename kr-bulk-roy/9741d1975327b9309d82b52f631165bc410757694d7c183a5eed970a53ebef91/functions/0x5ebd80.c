
void FUN_005ebd80(byte param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00905d18;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::UICachingData<134,FUI::CItemSlotToolTipEquipArmor>::vftable;
  local_8 = 0;
  if ((int *)in_ECX[3] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[3] + 0x1c))(1,uVar1);
    in_ECX[3] = 0;
  }
  DAT_00fe2f54 = 0;
  *in_ECX = FUI::UICachingDataBase::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

