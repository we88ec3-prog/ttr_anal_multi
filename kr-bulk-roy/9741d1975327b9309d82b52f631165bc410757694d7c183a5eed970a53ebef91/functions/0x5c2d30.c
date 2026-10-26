
void FUN_005c2d30(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094a11c;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_005b7f80(param_1);
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_8 = 0;
    FUN_00539c20(uVar2);
    _atexit((_func_4879 *)&LAB_00bccfb0);
    local_8 = 0xffffffff;
  }
  iVar1 = DAT_00fb7258;
  if ((DAT_00fc7f1c & 1) == 0) {
    DAT_00fc7f1c = DAT_00fc7f1c | 1;
    local_8 = 1;
    FUN_0053c300();
    _atexit(FUN_00bce1d0);
    local_8 = 0xffffffff;
  }
  if (*(int *)(param_1 + 0x10) == 0xf43e2) {
    if (DAT_00fcdddc == 0) {
      if (iVar1 == 0) {
        ExceptionList = local_10;
        return;
      }
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    FUN_0040b5b0(uVar3);
  }
  ExceptionList = local_10;
  return;
}

