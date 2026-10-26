
void FUN_00798500(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  float10 fVar3;
  undefined4 local_70;
  float local_6c;
  undefined8 local_68;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c [4];
  undefined4 local_3c;
  undefined4 local_2c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093267e;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff80;
  ExceptionList = &local_14;
  _memset(local_4c,0,0x34);
  local_2c = 0x3f800000;
  local_3c = 0x3f800000;
  local_4c[0] = 0x3f800000;
  FUN_00790990(&param_2,&stack0x00000020,0);
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0x3f800000;
  FUN_00780890(uVar2);
  FUN_007cc3a0(&local_70,&local_6c,&local_68);
  *(undefined4 *)(param_1 + 0x20) = local_70;
  *(float *)(param_1 + 0x18) = local_6c;
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = param_3;
  iVar1 = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x14) = param_4;
  if (((*(float *)(iVar1 + 0x68) != 0.0) || (*(float *)(iVar1 + 0x6c) != 0.0)) ||
     (*(float *)(iVar1 + 0x70) != 0.0)) {
    *(undefined4 *)(iVar1 + 0x68) = 0;
    *(undefined4 *)(iVar1 + 0x6c) = 0;
    *(undefined4 *)(iVar1 + 0xc0) = 0;
    *(undefined4 *)(iVar1 + 0x70) = 0;
  }
  iVar1 = *(int *)(param_1 + 4);
  local_68 = 0;
  fVar3 = (float10)FUN_008ff0a0();
  local_6c = (float)(fVar3 * (float10)0.0);
  *(float *)(iVar1 + 0x74) = local_6c;
  *(float *)(iVar1 + 0x78) = local_6c;
  *(float *)(iVar1 + 0x7c) = local_6c;
  fVar3 = (float10)FUN_008fef70();
  *(float *)(iVar1 + 0x80) = (float)fVar3;
  *(undefined4 *)(iVar1 + 0xc0) = 0;
  FUN_0077efc0();
  iVar1 = *(int *)(param_1 + 8);
  *(undefined4 *)(iVar1 + 0x68) = param_2;
  *(undefined4 *)(iVar1 + 0x6c) = param_3;
  *(undefined4 *)(iVar1 + 0x70) = param_4;
  *(undefined4 *)(iVar1 + 0xc0) = 0;
  FUN_00780150(*(int *)(param_1 + 8),*(undefined4 *)(*(int *)(param_1 + 8) + 0x30));
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_c = 0xffffffff;
  }
  (**(code **)(**(int **)(param_1 + 8) + 0x28))(DAT_00fb76a8);
  ExceptionList = pvStack_18;
  return;
}

