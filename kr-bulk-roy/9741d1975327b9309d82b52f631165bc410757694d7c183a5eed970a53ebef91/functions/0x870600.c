
undefined4 * FUN_00870600(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092038b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_00891268(0x40,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_0086d480(puVar1);
    *puVar1 = gbDxEffectScriptCommandsHint::vftable;
    puVar2 = puVar1;
  }
  ExceptionList = local_10;
  return puVar2;
}

