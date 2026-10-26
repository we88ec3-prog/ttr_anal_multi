
void FUN_006b66d0(void)

{
  int iVar1;
  undefined4 unaff_EDI;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094259c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (DAT_00f9392c == 6) {
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      local_c = 1;
      FUN_00539c20();
      _atexit((_func_4879 *)&LAB_00bccfb0);
    }
    local_c = 0xffffffff;
    if (DAT_00fb7258 != 0) {
      iVar1 = FUN_00404ba0();
      iVar1 = FUN_00539aa0(*(undefined4 *)(iVar1 + 0x5f50));
      if (*(char *)(iVar1 + 0xb) == '\x03') {
        FUN_006b71a0(unaff_EDI);
        FUN_006b73b0(unaff_EDI);
        ExceptionList = local_14;
        return;
      }
      FUN_006b6ce0(unaff_EDI);
      FUN_006b6f40(unaff_EDI);
      ExceptionList = local_14;
      return;
    }
  }
  else {
    FUN_006b67e0(unaff_EDI);
    FUN_006b6a60(unaff_EDI);
  }
  ExceptionList = local_14;
  return;
}

