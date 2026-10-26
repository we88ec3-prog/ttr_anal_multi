
undefined4 * FUN_00734330(void)

{
  int iVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091c0db;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_00891268(0x48,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_00734010();
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_007340c0(puVar2);
  if (iVar1 < 0) {
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    ExceptionList = local_10;
    return (undefined4 *)0x0;
  }
  ExceptionList = local_10;
  return puVar2;
}

