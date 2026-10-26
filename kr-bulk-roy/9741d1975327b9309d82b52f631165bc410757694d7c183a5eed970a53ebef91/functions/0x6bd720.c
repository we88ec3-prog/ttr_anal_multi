
void FUN_006bd720(void)

{
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093a77c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb72a4 & 1) == 0) {
    DAT_00fb72a4 = DAT_00fb72a4 | 1;
    local_8 = 0;
    FUN_0049f850(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccfe0);
  }
  local_8 = 0xffffffff;
  FUN_004a0540();
  if ((DAT_00fdf3d4 & 1) == 0) {
    DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
    local_8 = 1;
    FUN_006f4380();
    _atexit((_func_4879 *)&LAB_00bce6d0);
    local_8 = 0xffffffff;
  }
  FUN_004ad0a0(&DAT_00fdf3c8,0,"OnEndTalk");
  (**(code **)(*in_ECX + 0xd4))();
  in_ECX[0x27] = 0;
  ExceptionList = local_10;
  return;
}

