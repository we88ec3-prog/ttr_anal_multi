
void FUN_005c3610(void)

{
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0094736c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fdf3d4 & 1) == 0) {
    DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
    local_8 = 0;
    FUN_006f4380(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce6d0);
  }
  local_8 = 0xffffffff;
  FUN_004ad0a0(&DAT_00fdf3c8,0,"OnYesTriggered");
  FUN_00596e00(unaff_ESI,*(undefined4 *)(unaff_ESI + 0x22c));
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf4358);
  ExceptionList = local_10;
  return;
}

