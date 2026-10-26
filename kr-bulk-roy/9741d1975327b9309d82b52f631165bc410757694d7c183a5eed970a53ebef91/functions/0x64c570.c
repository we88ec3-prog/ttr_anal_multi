
void FUN_0064c570(void)

{
  undefined4 uVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  switch(DAT_00f9392c) {
  case 1:
    uVar1 = 0x43;
    break;
  default:
    goto switchD_0064c5e2_caseD_2;
  case 5:
    uVar1 = 0x136;
    break;
  case 8:
    uVar1 = 0x139;
    break;
  case 0x1b:
    uVar1 = 0x13e;
  }
  FUN_00585620(uVar1);
  FUN_00585330(uVar1);
  FUN_00757710();
switchD_0064c5e2_caseD_2:
  ExceptionList = local_14;
  return;
}

