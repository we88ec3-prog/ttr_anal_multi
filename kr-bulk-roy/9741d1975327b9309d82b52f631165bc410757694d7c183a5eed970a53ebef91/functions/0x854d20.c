
void FUN_00854d20(byte param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00911280;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = gbStdMaterial::vftable;
  local_8 = 1;
  FUN_00855d00(*(undefined4 *)in_ECX[0x62],(undefined4 *)in_ECX[0x62]);
  FUN_0089120c(in_ECX[0x62],uVar1);
  local_8 = 0xffffffff;
  FUN_00843d60();
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

