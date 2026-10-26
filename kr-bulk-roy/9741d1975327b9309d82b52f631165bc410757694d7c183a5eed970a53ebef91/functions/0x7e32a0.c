
void FUN_007e32a0(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00918803;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  iVar1 = (int)(param_1[0xb] - param_1[10]) >> 0x1f;
  uVar4 = 0;
  if ((int)(param_1[0xb] - param_1[10]) / 0x44 + iVar1 != iVar1) {
    do {
      FUN_007e24b0(uVar2);
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)((int)(param_1[0xb] - param_1[10]) / 0x44));
  }
  if (param_1[10] != param_1[0xb]) {
    uVar3 = FUN_007e4020(param_1[0xb],param_1[10],param_1);
    FUN_007e40a0(param_1);
    param_1[0xb] = uVar3;
  }
  if (param_1[10] != 0) {
    FUN_007e40a0(param_1);
    FUN_0089120c(param_1[10]);
  }
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  if (0xf < (uint)param_1[5]) {
    FUN_0089120c(*param_1);
  }
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  ExceptionList = local_10;
  return;
}

