
undefined4 FUN_007e6e50(undefined4 param_1,undefined4 param_2,float *param_3,int param_4)

{
  float *pfVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  float local_5c;
  undefined1 local_58 [4];
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_14 = param_1;
  local_10 = param_2;
  iVar5 = *(int *)(in_ECX + 0x150);
  local_c = 0x476a6000;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0xbf800000;
  iVar3 = FUN_008fed10();
  iVar4 = FUN_008fed10();
  iVar4 = iVar3 * iVar5 + iVar4;
  iVar3 = iVar4 * 2;
  if ((iVar3 < *(int *)(in_ECX + 0x154) * iVar5 * 2) && (-1 < iVar3)) {
    iVar4 = iVar4 * 0xc;
    local_50 = *(float *)(*(int *)(in_ECX + 0x178) + iVar4);
    uVar2 = *(ushort *)(*(int *)(in_ECX + 0x178) + 4 + iVar4);
    local_4c = (float)CONCAT22(local_4c._2_2_,uVar2);
    iVar5 = *(int *)(in_ECX + 0x16c);
    pfVar1 = (float *)(iVar5 + ((uint)local_50 & 0xffff) * 0xc);
    local_38 = *pfVar1;
    local_34 = pfVar1[1];
    local_30 = pfVar1[2];
    pfVar1 = (float *)(iVar5 + ((uint)local_50 >> 0x10) * 0xc);
    local_44 = *pfVar1;
    local_40 = pfVar1[1];
    local_3c = pfVar1[2];
    pfVar1 = (float *)(iVar5 + (uint)uVar2 * 0xc);
    local_2c = *pfVar1;
    local_28 = pfVar1[1];
    local_24 = pfVar1[2];
    iVar5 = FUN_007c81e0(&local_20,&local_44,&local_5c,&local_54,local_58,0);
    if (iVar5 == 0) {
      local_50 = *(float *)(*(int *)(in_ECX + 0x178) + 6 + iVar4);
      iVar3 = *(int *)(in_ECX + 0x16c);
      local_38 = *(float *)(iVar3 + ((uint)local_50 & 0xffff) * 0xc);
      iVar5 = iVar3 + ((uint)local_50 & 0xffff) * 0xc;
      local_34 = *(float *)(iVar5 + 4);
      local_30 = *(float *)(iVar5 + 8);
      pfVar1 = (float *)(iVar3 + ((uint)local_50 >> 0x10) * 0xc);
      local_40 = pfVar1[1];
      local_44 = *pfVar1;
      local_3c = pfVar1[2];
      pfVar1 = (float *)(iVar3 + (uint)*(ushort *)(*(int *)(in_ECX + 0x178) + iVar4 + 10) * 0xc);
      local_28 = pfVar1[1];
      local_2c = *pfVar1;
      local_24 = pfVar1[2];
      iVar5 = FUN_007c81e0(&local_20,&local_44,&local_5c,&local_54,local_58,0);
      if (iVar5 == 0) {
        return 0;
      }
      local_50 = local_44 - local_38;
      local_4c = local_40 - local_34;
      local_48 = local_3c - local_30;
      local_38 = local_2c - local_38;
      local_34 = local_28 - local_34;
      local_30 = local_24 - local_30;
      local_44 = local_4c * local_30 - local_48 * local_34;
      local_40 = local_38 * local_48 - local_50 * local_30;
      local_3c = local_34 * local_50 - local_4c * local_38;
      local_2c = local_44;
      local_28 = local_40;
      local_24 = local_3c;
      FUN_00781020(0x3f800000);
      local_5c = local_5c * -1.0;
      local_54 = local_5c;
    }
    else {
      local_50 = local_44 - local_38;
      local_4c = local_40 - local_34;
      local_48 = local_3c - local_30;
      local_38 = local_2c - local_38;
      local_34 = local_28 - local_34;
      local_30 = local_24 - local_30;
      local_44 = local_4c * local_30 - local_48 * local_34;
      local_40 = local_38 * local_48 - local_50 * local_30;
      local_3c = local_34 * local_50 - local_4c * local_38;
      local_2c = local_44;
      local_28 = local_40;
      local_24 = local_3c;
      FUN_00781020(0x3f800000);
      local_5c = local_5c * -1.0;
    }
    local_5c = local_5c + 60000.0;
    if (*param_3 < local_5c) {
      *param_3 = local_5c;
      if (param_4 != 0) {
        local_14 = 0;
        local_10 = 0;
        local_c = 0x3f800000;
        FUN_00780610();
      }
      return 1;
    }
  }
  return 0;
}

