
void FUN_0053b680(void)

{
  uint uVar1;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009386bc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc7f1c & 1) == 0) {
    DAT_00fc7f1c = DAT_00fc7f1c | 1;
    local_8 = 0;
    FUN_0053c300(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bce1d0);
  }
  local_8 = 0xffffffff;
  FUN_0044e720(&DAT_00fcddcc);
  DAT_00fcdddc = 0;
  FUN_0053bed0(unaff_ESI + 0x5ec8);
  uVar1 = DAT_00faadd4 & 1;
  *(undefined4 *)(unaff_ESI + 0x5ed8) = 0;
  if (uVar1 == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf4404);
  ExceptionList = local_10;
  return;
}

