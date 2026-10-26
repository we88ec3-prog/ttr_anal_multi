
void FUN_004ff080(void)

{
  uint uVar1;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093276e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(unaff_ESI + 0x5eac) = 0;
  _memset((void *)(unaff_ESI + 0x5eb0),0,0x1c0);
  _memset((void *)(unaff_ESI + 0x6070),0,0x1c0);
  *(undefined4 *)(unaff_ESI + 0x6230) = 0;
  *(undefined4 *)(unaff_ESI + 0x6234) = 0;
  *(undefined4 *)(unaff_ESI + 0x623c) = 0;
  *(undefined4 *)(unaff_ESI + 0x6240) = 0;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480(uVar1);
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf4264);
  ExceptionList = local_10;
  return;
}

