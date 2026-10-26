
/* WARNING: Removing unreachable block (ram,0x005a7511) */

void FUN_005a7430(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922ca0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005960b0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004095e0(0);
  FUN_004095e0(5);
  FUN_004095e0(3);
  FUN_004095e0(4);
  FUN_004095e0(6);
  FUN_004095e0(7);
  FUN_004095e0(8);
  FUN_004095e0(9);
  FUN_004095e0(1);
  FUN_004095e0(2);
  FUN_004095e0(10);
  FUN_004095e0(0xb);
  FUN_004095e0(0xc);
  ExceptionList = local_10;
  return;
}

