
void FUN_007aaac0(void)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00918c67;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe1770 & 1) == 0) {
    DAT_00fe1770 = DAT_00fe1770 | 1;
    local_8 = 0;
    FUN_007b7da0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce790);
  }
  if ((DAT_00fd93f0 & 1) == 0) {
    DAT_00fd93f0 = DAT_00fd93f0 | 1;
    local_8 = 1;
    FUN_007ab4e0();
    _atexit((_func_4879 *)&LAB_00bce6a0);
  }
  local_8 = 0xffffffff;
  if (DAT_00fba838 == 0) {
    iVar1 = FUN_00891268(0x10c);
    local_8 = 2;
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_007b8a50(iVar1);
    }
    if (DAT_00fba838 == 0) {
      DAT_00fba838 = iVar1;
    }
  }
  ExceptionList = local_10;
  return;
}

