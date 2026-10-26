
void FUN_004d28c0(float param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  float10 fVar3;
  undefined1 auStack_74 [4];
  float local_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  undefined1 local_54 [40];
  undefined1 auStack_2c [4];
  float fStack_28;
  float fStack_24;
  float fStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093a3fe;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_74;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffff80;
  ExceptionList = &local_14;
  *(float *)(in_ECX + 0x428) = param_1 + *(float *)(in_ECX + 0x428);
  if (0.02 < param_1) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 0;
      FUN_00798de0(uVar1);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_c = 0xffffffff;
    if (DAT_00fb76e8 != 0) {
      puVar2 = (undefined4 *)(**(code **)(**(int **)(DAT_00fb76e8 + 4) + 0x24))(local_54);
      fStack_64 = (float)*puVar2;
      fStack_60 = (float)puVar2[1];
      fStack_5c = (float)puVar2[2];
      (**(code **)(*(int *)(*(int *)(in_ECX + 0x15c) + 4) + 8))(auStack_2c);
      fStack_6c = fStack_60 - fStack_28;
      fStack_68 = fStack_5c - fStack_24;
      fStack_64 = fStack_58 - fStack_20;
      local_70 = fStack_64 * fStack_64 + fStack_6c * fStack_6c + fStack_68 * fStack_68;
      fVar3 = (float10)FUN_008ff870();
      local_70 = (float)fVar3;
      if ((200.0 < local_70) &&
         (*(float *)(in_ECX + 0x428) <= 0.06666667 && *(float *)(in_ECX + 0x428) != 0.06666667))
      goto LAB_004d2a53;
    }
  }
  local_70 = *(float *)(in_ECX + 0x428);
  *(undefined4 *)(in_ECX + 0x428) = 0;
  FUN_004c87d0(local_70);
  if ((*(int *)(in_ECX + 0x420) != 0) && (*(int *)(*(int *)(in_ECX + 0x420) + 0x24) != 0)) {
    FUN_007bd8d0(local_70);
  }
LAB_004d2a53:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_74);
  return;
}

