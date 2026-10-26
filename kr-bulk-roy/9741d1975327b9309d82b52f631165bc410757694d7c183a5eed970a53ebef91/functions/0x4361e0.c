
void FUN_004361e0(undefined1 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 in_ECX;
  undefined2 in_DX;
  int unaff_ESI;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093d77c;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffe0;
  ExceptionList = &local_14;
  *(undefined1 *)(unaff_ESI + 0x159) = param_1;
  *(undefined4 *)(unaff_ESI + 0x15c) = in_ECX;
  *(undefined2 *)(unaff_ESI + 0x160) = in_DX;
  *(undefined4 *)(unaff_ESI + 0x168) = param_2;
  *(undefined4 *)(unaff_ESI + 0x16c) = param_3;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  DAT_00f942ca = *(undefined2 *)(unaff_ESI + 0x160);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  DAT_00f942d0 = *(undefined4 *)(unaff_ESI + 0x168);
  DAT_00f942d4 = *(undefined4 *)(unaff_ESI + 0x16c);
  ExceptionList = local_14;
  return;
}

