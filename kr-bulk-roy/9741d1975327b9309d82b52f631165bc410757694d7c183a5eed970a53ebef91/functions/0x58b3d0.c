
void FUN_0058b3d0(void)

{
  uint uVar1;
  undefined4 in_ECX;
  undefined4 *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009169ee;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *unaff_EDI = in_ECX;
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0;
    FUN_0074d990(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  DAT_00f94814 = in_ECX;
  *(undefined4 *)(unaff_EDI[0xe] + 0x18) = in_ECX;
  GetKeyboardLayout(0);
  FUN_005cafc0();
  ExceptionList = local_10;
  return;
}

