
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004a9260(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00924f5c;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480(uVar1);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  if (DAT_00faadec == 0x10) {
    FUN_0058a9a0();
  }
  else {
    _DAT_00faadf0 = 0x10;
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 1;
    FUN_00587480(uVar1);
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058ac30(0xf43fd,10,0);
  ExceptionList = local_10;
  return 0;
}

