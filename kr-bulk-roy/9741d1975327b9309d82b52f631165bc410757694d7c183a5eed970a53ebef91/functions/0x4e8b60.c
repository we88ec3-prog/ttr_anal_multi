
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004e8b60(int param_1)

{
  uint uVar1;
  undefined2 local_24;
  undefined1 local_22;
  undefined4 local_21;
  undefined4 local_1d;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093b0f8;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c = 0;
    FUN_004f3d80(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_c = 0xffffffff;
  FUN_004f6950(*(undefined4 *)(param_1 + 2),param_1 + 6);
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c = 1;
    FUN_004f3d80(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_c = 0xffffffff;
  }
  FUN_004f7280(&DAT_00fb7470,*(undefined4 *)(param_1 + 0x30),param_1 + 0x34,0xffffffff);
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_c = 2;
    FUN_00560170();
    _atexit((_func_4879 *)&LAB_00bcd110);
    local_c = 0xffffffff;
  }
  if (DAT_00fb73e8 == 0) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 3;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    FUN_0058ac30(0xf4257,*(undefined4 *)(param_1 + 2),*(undefined4 *)(param_1 + 0x30));
  }
  else {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_21 = *(undefined4 *)(param_1 + 2);
    local_1d = *(undefined4 *)(param_1 + 0x30);
    local_24 = 0xbbe;
    local_22 = 2;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(2,&local_24,0xb);
    }
  }
  ExceptionList = local_14;
  return 0;
}

