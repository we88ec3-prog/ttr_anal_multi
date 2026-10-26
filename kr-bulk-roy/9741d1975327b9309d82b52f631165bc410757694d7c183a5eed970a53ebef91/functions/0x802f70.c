
void FUN_00802f70(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009320ac;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
  }
  iVar2 = DAT_00fb76a8;
  local_8 = 0xffffffff;
  uVar3 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 8) >> 2;
  uVar4 = 0;
  if (uVar3 != 0) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 8) + uVar4 * 4);
      *(float *)(iVar1 + 0x18) =
           -(*(float *)(iVar1 + 0x14) * *(float *)(iVar2 + 0xb8) +
             *(float *)(iVar1 + 0xc) * *(float *)(iVar2 + 0xa0) +
             *(float *)(iVar1 + 0x10) * *(float *)(iVar2 + 0xac) + *(float *)(iVar2 + 0xc4));
      FUN_007f3970(*(undefined4 *)(*(int *)(param_1 + 8) + uVar4 * 4));
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  ExceptionList = local_10;
  return;
}

