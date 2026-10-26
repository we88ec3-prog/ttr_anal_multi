
undefined4 FUN_004fec40(int param_1)

{
  uint uVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00924d9e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(char *)(param_1 + 2) == '\0') {
    *(undefined4 *)(in_ECX + 0x6230) = *(undefined4 *)(param_1 + 3);
  }
  else {
    *(undefined4 *)(in_ECX + 0x6234) = *(undefined4 *)(param_1 + 3);
  }
  *(undefined4 *)(in_ECX + 0x623c) = 0;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480(uVar1);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  FUN_0058aad0(0xf4264);
  ExceptionList = local_10;
  return 0;
}

