
undefined4
FUN_00840310(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int param_6)

{
  undefined4 uVar1;
  undefined1 local_18 [4];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0090e491;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  local_8 = 1;
  FUN_00840950(param_1,param_3,param_4,param_5,param_6,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = local_8 & 0xffffff00;
  local_14 = 1;
  if (DAT_00fbacc0 != DAT_00fbacc4) {
    if (param_6 != 0) {
      uVar1 = FUN_0083eef0(param_5);
      FUN_00863050(uVar1,param_5);
    }
    FUN_0083f0d0(&DAT_00fbacc0,local_18,DAT_00fbacc0,DAT_00fbacc4);
  }
  ExceptionList = local_10;
  return param_1;
}

