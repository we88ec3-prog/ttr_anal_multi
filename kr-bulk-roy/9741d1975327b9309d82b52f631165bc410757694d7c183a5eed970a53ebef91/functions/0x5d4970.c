
/* WARNING: Removing unreachable block (ram,0x005d49db) */
/* WARNING: Removing unreachable block (ram,0x005d4a50) */

void FUN_005d4970(void)

{
  undefined4 uVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091a930;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_0040b670(in_ECX);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 3;
  FUN_005d4de0();
  FUN_005a9f40((undefined4 *)(in_ECX + 0x380));
  uVar1 = FUN_00746940(0x87a23);
  FUN_0040b670(uVar1);
  (**(code **)(**(int **)(in_ECX + 0x380) + 0xd0))();
  ExceptionList = local_10;
  return;
}

