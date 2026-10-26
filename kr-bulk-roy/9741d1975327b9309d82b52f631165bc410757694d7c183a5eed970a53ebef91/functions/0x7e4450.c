
void FUN_007e4450(float param_1)

{
  int in_ECX;
  int iVar1;
  float fVar2;
  float10 fVar3;
  undefined1 auStack_34 [4];
  float local_30;
  float local_2c;
  float fStack_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_34;
  fVar2 = (float)((*(int *)(in_ECX + 0x5c) - *(int *)(in_ECX + 0x58)) / 0x2c);
  if (*(int *)(in_ECX + 0x4c) != 0) {
    FUN_007e46c0();
  }
  if (*(int *)(in_ECX + 0x20) != 0) {
    if (fVar2 != 0.0) {
      iVar1 = 0;
      local_30 = fVar2;
      do {
        local_2c = *(float *)(in_ECX + 0x54) * param_1 *
                   *(float *)(*(int *)(in_ECX + 0x58) + 0x24 + iVar1);
        (**(code **)(**(int **)(*(int *)(in_ECX + 0x58) + 0x28 + iVar1) + 0x20))(local_2c);
        iVar1 = iVar1 + 0x2c;
        local_30 = (float)((int)local_30 + -1);
      } while (local_30 != 0.0);
    }
    if ((*(int *)(in_ECX + 0x50) != 0) && (fVar2 != 0.0)) {
      iVar1 = 0;
      local_24 = 0.0;
      local_20 = 0.0;
      local_1c = 0.0;
      local_30 = fVar2;
      do {
        local_18 = 0.0;
        local_14 = 0.0;
        local_10 = 0.0;
        local_2c = 0.0;
        (**(code **)(**(int **)(iVar1 + 0x28 + *(int *)(in_ECX + 0x58)) + 0x28))
                  (&local_18,&local_2c);
        local_24 = local_18 + local_24;
        iVar1 = iVar1 + 0x2c;
        local_30 = (float)((int)local_30 + -1);
        local_20 = local_14 + local_20;
        local_1c = local_10 + local_1c;
      } while (local_30 != 0.0);
      local_2c = (float)(int)fVar2;
      if ((int)fVar2 < 0) {
        local_2c = local_2c + 4.2949673e+09;
      }
      local_2c = 1.0 / local_2c;
      local_18 = local_2c * local_24;
      *(float *)(in_ECX + 0x68) = local_18;
      local_14 = local_20 * local_2c;
      *(float *)(in_ECX + 0x6c) = local_14;
      local_10 = local_2c * local_1c;
      *(float *)(in_ECX + 0x70) = local_10;
      local_30 = 0.0;
      if (fVar2 == 0.0) {
        fStack_28 = 0.0;
      }
      else {
        iVar1 = 0;
        fStack_28 = fVar2;
        do {
          local_18 = 0.0;
          local_14 = 0.0;
          local_10 = 0.0;
          local_2c = 0.0;
          (**(code **)(**(int **)(iVar1 + 0x28 + *(int *)(in_ECX + 0x58)) + 0x28))
                    (&local_18,&local_2c);
          local_24 = *(float *)(in_ECX + 0x68) - local_18;
          local_20 = *(float *)(in_ECX + 0x6c) - local_14;
          local_1c = *(float *)(in_ECX + 0x70) - local_10;
          fStack_28 = local_1c * local_1c + local_24 * local_24 + local_20 * local_20;
          fVar3 = (float10)FUN_008ff870();
          fStack_28 = (float)fVar3 + local_2c;
          if (local_30 < fStack_28) {
            local_30 = fStack_28;
          }
          iVar1 = iVar1 + 0x2c;
          fVar2 = (float)((int)fVar2 + -1);
        } while (fVar2 != 0.0);
      }
      *(undefined4 *)(in_ECX + 0x50) = 0;
      *(float *)(in_ECX + 0x74) = local_30;
    }
  }
  __security_check_cookie(local_c ^ (uint)auStack_34);
  return;
}

