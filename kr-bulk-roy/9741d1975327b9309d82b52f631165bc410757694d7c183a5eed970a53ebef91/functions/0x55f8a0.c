
void FUN_0055f8a0(void)

{
  undefined4 *unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922fbc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0055f5d0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  *unaff_ESI = 0;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf434f);
  if ((DAT_00fb72a4 & 1) == 0) {
    DAT_00fb72a4 = DAT_00fb72a4 | 1;
    local_8 = 1;
    FUN_0049f850();
    _atexit((_func_4879 *)&LAB_00bccfe0);
  }
  FUN_004a0540();
  ExceptionList = local_10;
  return;
}

