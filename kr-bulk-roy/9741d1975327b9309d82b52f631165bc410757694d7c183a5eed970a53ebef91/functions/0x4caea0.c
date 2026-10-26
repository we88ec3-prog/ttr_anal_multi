
void FUN_004caea0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090d938;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = CEffectObject::vftable;
  local_8 = 0;
  if (in_ECX[0x3c] != 0) {
    FUN_004c7db0(uVar1);
    in_ECX[0x3c] = 0;
  }
  *in_ECX = CBasicObject::vftable;
  ExceptionList = local_10;
  return;
}

