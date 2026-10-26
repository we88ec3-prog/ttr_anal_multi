
undefined4 * FUN_008668b0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091c113;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_00891268(0x194,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00843b20(puVar1,in_ECX);
    local_8 = CONCAT31(local_8._1_3_,1);
    *puVar1 = gbEffectMaterial::vftable;
    FUN_0083ece0(puVar1 + 0x61,in_ECX + 0x184);
    puVar2 = puVar1;
  }
  ExceptionList = local_10;
  return puVar2;
}

