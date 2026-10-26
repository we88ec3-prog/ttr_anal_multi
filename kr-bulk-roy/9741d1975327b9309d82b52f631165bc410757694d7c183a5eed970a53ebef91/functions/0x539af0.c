
void FUN_00539af0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00943f6a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == 0) {
    iVar2 = FUN_00404ba0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    uVar1 = *(undefined4 *)(iVar2 + 0x5f50);
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_8 = 1;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_8 = 0xffffffff;
    }
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      local_8 = 2;
      FUN_00539c20();
      _atexit((_func_4879 *)&LAB_00bccfb0);
      local_8 = 0xffffffff;
    }
    FUN_004f6a30(uVar1);
    if (DAT_00fb7258 == 0) {
      FUN_0053b900(1,0);
    }
  }
  else {
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      local_8 = 0;
      FUN_00539c20();
      _atexit((_func_4879 *)&LAB_00bccfb0);
    }
    local_8 = 0xffffffff;
    if (DAT_00fb7258 != 0) {
      FUN_0053b990(1,0);
      ExceptionList = local_10;
      return;
    }
  }
  ExceptionList = local_10;
  return;
}

