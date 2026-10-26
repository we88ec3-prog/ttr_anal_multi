
bool FUN_007c8720(int param_1,int param_2)

{
  float *in_EAX;
  int iVar1;
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
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  float local_8;
  
  local_34 = *in_EAX;
  local_30 = in_EAX[1];
  local_2c = in_EAX[2];
  local_28 = in_EAX[3];
  local_24 = in_EAX[4];
  local_4c = 0.0;
  local_20 = in_EAX[5];
  local_48 = 0.0;
  local_44 = -1.0;
  local_40 = in_EAX[6];
  local_3c = in_EAX[7];
  local_1c = 0.0;
  local_38 = in_EAX[8];
  local_18 = 0.0;
  local_14 = 1.0;
  iVar1 = FUN_007c81e0(&local_4c,&local_28,&local_8,local_10,local_c,0);
  if (iVar1 != 0) {
    local_4c = local_28 - local_34;
    local_48 = local_24 - local_30;
    local_44 = local_20 - local_2c;
    local_34 = local_40 - local_34;
    local_30 = local_3c - local_30;
    local_2c = local_38 - local_2c;
    local_40 = local_48 * local_2c - local_44 * local_30;
    local_3c = local_34 * local_44 - local_4c * local_2c;
    local_38 = local_30 * local_4c - local_48 * local_34;
    local_1c = local_40;
    local_18 = local_3c;
    local_14 = local_38;
    FUN_00781020(0x3f800000);
    *(float *)(param_1 + 8) = local_8 * -1.0 + 60000.0;
  }
  if (param_2 != 0) {
    FUN_00780610();
  }
  return iVar1 != 0;
}

