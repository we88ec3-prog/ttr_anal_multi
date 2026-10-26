
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004bc220(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094799e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004bb010(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  *(undefined4 *)(in_ECX + 0x5eb8) = 0x168;
  *(undefined4 *)(in_ECX + 0x5eb4) = 0;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  if (DAT_00faadec != 6) {
    _DAT_00faadf0 = 6;
    ExceptionList = local_10;
    return 0;
  }
  FUN_0058a9a0();
  ExceptionList = local_10;
  return 0;
}

