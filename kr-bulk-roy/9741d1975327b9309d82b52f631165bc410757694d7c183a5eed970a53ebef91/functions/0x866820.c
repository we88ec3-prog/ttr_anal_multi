
void FUN_00866820(byte param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *in_ECX;
  undefined1 local_18 [8];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_00911115;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = gbEffectMaterial::vftable;
  puVar1 = in_ECX + 0x61;
  local_8 = 1;
  FUN_0085e020(puVar1,local_18,*puVar1,in_ECX[0x62]);
  local_8 = local_8 & 0xffffff00;
  FUN_0083f1b0(puVar1);
  local_8 = 0xffffffff;
  FUN_00843d60(uVar2);
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

