
int FUN_0042bee0(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0094566c;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar4 = *(int *)(*(int *)(param_1 + 0x108) + 0xcc);
  iVar2 = 0;
  if (iVar4 != 0) {
    iVar2 = *(int *)(iVar4 + 0xdc);
    if (iVar2 == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = *(uint *)(iVar2 + 0x20);
    }
    if (uVar3 != 0xffffffff) {
      if ((DAT_00fb1378 & 1) == 0) {
        DAT_00fb1378 = DAT_00fb1378 | 1;
        local_8 = 0;
        FUN_00539c20(uVar1);
        _atexit((_func_4879 *)&LAB_00bccfb0);
      }
      iVar2 = (DAT_00fb723c - DAT_00fb7238) * 0x4bda12f7;
      if ((uVar3 < (uint)((DAT_00fb723c - DAT_00fb7238) / 0x36)) &&
         (iVar4 = uVar3 * 0x36 + DAT_00fb7238, iVar4 != 0)) {
        if ((DAT_00fb1378 & 1) == 0) {
          DAT_00fb1378 = DAT_00fb1378 | 1;
          local_8 = 1;
          FUN_00539c20(uVar1);
          _atexit((_func_4879 *)&LAB_00bccfb0);
        }
        local_8 = 0xffffffff;
        iVar2 = FUN_0053bc00(*(undefined4 *)(iVar4 + 0x2e),1);
      }
    }
  }
  ExceptionList = local_10;
  return iVar2;
}

