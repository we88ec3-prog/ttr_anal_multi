
undefined4 * FUN_00861900(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 local_18 [4];
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911150;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)FUN_00891268(0x194,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (puVar2 != (undefined4 *)0x0) {
    local_14 = puVar2;
    FUN_00843940(puVar2);
    puVar1 = puVar2 + 0x61;
    *puVar2 = gbMultiMaterial::vftable;
    *puVar1 = 0;
    puVar2[0x62] = 0;
    puVar2[99] = 0;
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00860810(puVar1,local_18,*puVar1,puVar2[0x62]);
    ExceptionList = local_10;
    return puVar2;
  }
  ExceptionList = local_10;
  return (undefined4 *)0x0;
}

