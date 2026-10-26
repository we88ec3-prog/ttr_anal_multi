
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0053a2d0(int param_1)

{
  undefined2 local_1c;
  undefined4 local_1a;
  undefined4 local_16;
  undefined1 local_12;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093afea;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_8 = 0;
    FUN_00560170(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd110);
  }
  local_8 = 0xffffffff;
  if (DAT_00fb73e8 == 0) {
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_8 = 1;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
    }
    local_8 = 0xffffffff;
    FUN_004f6950(*(undefined4 *)(param_1 + 2),param_1 + 6);
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 2;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_0058acf0(0xf428c,*(undefined4 *)(param_1 + 2),*(undefined1 *)(param_1 + 0x30),
                 *(undefined1 *)(param_1 + 0x31));
  }
  else {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_1c = 0x56;
    local_16 = *(undefined4 *)(param_1 + 2);
    local_12 = *(undefined1 *)(param_1 + 0x33);
    local_1a = 2;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_1c,0xb);
    }
  }
  ExceptionList = local_10;
  return 0;
}

