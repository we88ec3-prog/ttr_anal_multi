
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a40e0(void)

{
  int unaff_ESI;
  undefined2 local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_24 = 0xbd8;
  if ((_DAT_00fd94dc & 1) == 0) {
    _DAT_00fd94dc = _DAT_00fd94dc | 1;
    FUN_004f10f0(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bce260);
  }
  if ((DAT_00fdf3ac == 0) || (*(int *)(DAT_00fdf3ac + 8) != unaff_ESI)) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
  }
  else {
    FUN_00404ba0();
  }
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(2,&local_24,10);
  }
  ExceptionList = local_14;
  return;
}

