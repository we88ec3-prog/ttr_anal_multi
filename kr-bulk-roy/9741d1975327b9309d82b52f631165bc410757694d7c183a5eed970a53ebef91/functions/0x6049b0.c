
void FUN_006049b0(void)

{
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0094103e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc1cbc & 1) == 0) {
    DAT_00fc1cbc = DAT_00fc1cbc | 1;
    local_8 = 0;
    FUN_004fdac0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bce150);
  }
  local_8 = 0xffffffff;
  FUN_004ff1a0(0);
  *(undefined4 *)(unaff_ESI + 0x13c) = 0;
  *(undefined4 *)(unaff_ESI + 0x140) = 0;
  *(undefined4 *)(unaff_ESI + 0x144) = 0;
  *(undefined4 *)(unaff_ESI + 0x148) = 0;
  *(undefined4 *)(unaff_ESI + 0x14c) = 0;
  *(undefined4 *)(unaff_ESI + 0x150) = 0;
  *(undefined4 *)(unaff_ESI + 0x154) = 0;
  *(undefined4 *)(unaff_ESI + 0x158) = 0;
  *(undefined4 *)(unaff_ESI + 0x15c) = 0;
  *(undefined4 *)(unaff_ESI + 0x160) = 0;
  *(undefined4 *)(unaff_ESI + 0x164) = 0;
  *(undefined4 *)(unaff_ESI + 0x168) = 0;
  *(undefined4 *)(unaff_ESI + 0x16c) = 0;
  *(undefined4 *)(unaff_ESI + 0x170) = 0;
  *(undefined4 *)(unaff_ESI + 0x174) = 0;
  *(undefined4 *)(unaff_ESI + 0x178) = 0;
  ExceptionList = local_10;
  return;
}

