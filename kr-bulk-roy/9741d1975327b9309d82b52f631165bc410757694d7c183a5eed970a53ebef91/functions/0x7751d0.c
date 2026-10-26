
void FUN_007751d0(byte param_1)

{
  int *piVar1;
  uint uVar2;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907d06;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::FXUIManagedRect::vftable;
  local_8 = 0;
  piVar1 = (int *)in_ECX[0x1f];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
    in_ECX[0x1f] = 0;
  }
  local_8 = 0xffffffff;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,6,FUN_005f5d10);
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

