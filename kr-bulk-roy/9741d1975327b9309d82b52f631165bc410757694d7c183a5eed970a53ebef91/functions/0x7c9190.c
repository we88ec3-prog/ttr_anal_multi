
undefined4 * FUN_007c9190(undefined4 *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  float *pfVar3;
  undefined4 *puVar4;
  float *pfVar5;
  undefined4 local_9c [13];
  float local_68 [4];
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  puVar2 = (undefined4 *)(in_EAX + 0x98);
  puVar4 = local_9c;
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  pfVar3 = (float *)(in_EAX + 0x54);
  pfVar5 = local_68;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar5 = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pfVar5 = pfVar5 + 1;
  }
  local_14 = ((((float)param_2 * 2.0) / (float)param_4 - 1.0) - local_48) / local_68[0];
  local_10 = (-(((float)param_3 * 2.0) / (float)param_5 - 1.0) - local_44) / local_54;
  _memset(&local_58,0,0x34);
  local_38 = 1.0;
  local_48 = 1.0;
  local_58 = 1.0;
  FUN_00790b40();
  local_40 = -local_40;
  local_3c = -local_3c;
  local_38 = -local_38;
  local_20 = local_10 * local_4c + local_14 * local_58 + local_40;
  local_1c = local_54 * local_14 + local_48 * local_10 + local_3c;
  local_18 = local_10 * local_44 + local_50 * local_14 + local_38;
  FUN_00781020(0x3f800000);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *param_1 = local_34;
  param_1[1] = local_30;
  param_1[2] = local_2c;
  param_1[3] = local_20;
  param_1[4] = local_1c;
  param_1[5] = local_18;
  return param_1;
}

