
undefined4 FUN_007e7240(int param_1)

{
  float fVar1;
  uint uVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  undefined1 *puVar7;
  undefined1 local_64 [12];
  undefined1 local_58 [12];
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  int local_28;
  float local_24;
  int local_20;
  float local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b9de;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(float *)(param_1 + 0x14) <= 0.0) {
    if (*(float *)(param_1 + 8) < *(float *)(in_ECX + 0x138)) {
      return 0;
    }
    if (*(float *)(param_1 + 8) <= *(float *)(in_ECX + 0x144)) {
      local_24 = *(float *)(param_1 + 8);
    }
    else {
      local_24 = *(float *)(in_ECX + 0x144);
    }
    ExceptionList = &local_10;
    pfVar3 = (float *)FUN_007c92e0(local_64,*(undefined4 *)(in_ECX + 0x138),uVar2);
    local_38 = *pfVar3;
    puVar7 = local_58;
    fVar1 = local_24;
  }
  else {
    if (*(float *)(in_ECX + 0x144) < *(float *)(param_1 + 8)) {
      return 0;
    }
    if (*(float *)(in_ECX + 0x138) <= *(float *)(param_1 + 8)) {
      local_24 = *(float *)(param_1 + 8);
    }
    else {
      local_24 = *(float *)(in_ECX + 0x138);
    }
    ExceptionList = &local_10;
    pfVar3 = (float *)FUN_007c92e0(local_58,local_24,uVar2);
    local_38 = *pfVar3;
    puVar7 = local_64;
    fVar1 = (float)*(undefined4 *)(in_ECX + 0x144);
  }
  local_34 = pfVar3[1];
  local_30 = pfVar3[2];
  pfVar3 = (float *)FUN_007c92e0(puVar7,fVar1,uVar2);
  local_4c = *pfVar3;
  local_48 = pfVar3[1];
  local_44 = pfVar3[2];
  local_40 = local_4c;
  if (local_38 < local_4c) {
    local_40 = local_38;
  }
  local_3c = local_48;
  if (local_34 < local_48) {
    local_3c = local_34;
  }
  if (local_40 < *(float *)(in_ECX + 0x130)) {
    local_40 = *(float *)(in_ECX + 0x130);
  }
  if (local_3c < *(float *)(in_ECX + 0x134)) {
    local_3c = *(float *)(in_ECX + 0x134);
  }
  fVar1 = local_4c;
  if (local_4c < local_38) {
    fVar1 = local_38;
  }
  local_30 = local_48;
  if (local_48 < local_34) {
    local_30 = local_34;
  }
  local_34 = fVar1;
  if (*(float *)(in_ECX + 0x13c) < fVar1) {
    local_34 = *(float *)(in_ECX + 0x13c);
  }
  if (*(float *)(in_ECX + 0x140) < local_30) {
    local_30 = *(float *)(in_ECX + 0x140);
  }
  iVar6 = *(int *)(in_ECX + 0x150);
  iVar4 = FUN_008fed10();
  iVar5 = FUN_008fed10();
  iVar4 = (iVar4 * iVar6 + iVar5) * 2 + -2;
  iVar5 = FUN_008fed10();
  local_24 = (float)(iVar5 * iVar6);
  iVar6 = FUN_008fed10();
  iVar6 = ((int)local_24 + iVar6) * 2 + 2;
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  if (*(int *)(in_ECX + 0x17c) < iVar6) {
    iVar6 = *(int *)(in_ECX + 0x17c);
  }
  local_1c = 0.0;
  local_18 = -1;
  local_20 = iVar6;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_24 = *(float *)(DAT_00fb76e8 + 0x24);
  if (iVar4 < iVar6) {
    iVar5 = *(int *)(in_ECX + 0x16c);
    iVar6 = *(int *)(in_ECX + 0x178) + iVar4 * 6;
    local_14 = iVar4;
    do {
      iVar4 = FUN_007c81e0(param_1 + 0xc,iVar5 + (uint)*(ushort *)(iVar6 + 2) * 0xc,&local_2c,
                           &local_3c,&local_30,&local_28);
      if (iVar4 != 0) {
        if ((((local_18 != -1) || (local_2c <= 0.0)) || (local_24 <= local_2c)) || (local_28 != 1))
        {
          if (((local_1c < local_2c) && (0.0 < local_2c)) &&
             ((local_2c < local_24 && (local_28 == 1)))) {
            local_1c = local_2c;
            local_18 = local_14;
          }
        }
        else {
          local_1c = local_2c;
          local_18 = local_14;
        }
      }
      local_14 = local_14 + 1;
      iVar6 = iVar6 + 6;
    } while (local_14 < local_20);
    if (local_18 != -1) {
      *(float *)(DAT_00fb76e8 + 0xd4) = (local_24 - local_1c) - 3.0;
      ExceptionList = local_10;
      return 1;
    }
  }
  ExceptionList = local_10;
  return 0;
}

