
void FUN_007f74f0(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093250e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  uVar1 = DAT_00fb76b0;
  local_8 = 0xffffffff;
  param_1 = (int *)*param_1;
  if (param_1 != (int *)0x0) {
    iVar2 = FUN_00838860(param_1[0xb],param_1[0xc],param_1[0xd],param_1[0x1a]);
    if (iVar2 == 0) {
      param_1[0x1b] = 0;
      ExceptionList = local_10;
      return;
    }
    iVar2 = FUN_00838800(param_1[0xe],param_1[0xf],param_1[0x10]);
    if (iVar2 != 0) {
      iVar2 = FUN_00838800(param_1[0x11],param_1[0x12],param_1[0x13]);
      if (iVar2 != 0) {
        iVar2 = FUN_00838800(param_1[0x14],param_1[0x15],param_1[0x16]);
        if (iVar2 != 0) {
          iVar2 = FUN_00838800(param_1[0x17],param_1[0x18],param_1[0x19]);
          if (iVar2 != 0) {
            param_1[0x1b] = 1;
            ExceptionList = local_10;
            return;
          }
        }
      }
    }
    param_1[0x1b] = 2;
    if (*param_1 == 0) {
      FUN_007f7210(uVar1);
      FUN_007f7210(uVar1);
      FUN_007f7210(uVar1);
      FUN_007f7210(uVar1);
    }
  }
  ExceptionList = local_10;
  return;
}

