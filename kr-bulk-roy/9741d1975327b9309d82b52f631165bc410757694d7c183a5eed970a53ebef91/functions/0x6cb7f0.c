
/* WARNING: Removing unreachable block (ram,0x006cb85d) */

void FUN_006cb7f0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00922ca0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004095e0(0x11e);
  *param_1 = 0;
  ExceptionList = local_10;
  return;
}

