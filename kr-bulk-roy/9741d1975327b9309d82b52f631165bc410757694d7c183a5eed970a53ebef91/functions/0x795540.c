
void FUN_00795540(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  int *in_EAX;
  int iVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
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
  float local_10;
  float local_c;
  int local_8;
  
  local_c = (float)(**(code **)(*in_EAX + 0x18))();
  iVar4 = (int)local_c + -3;
  uVar1 = (int)local_c - 1;
  local_10 = (float)iVar4;
  local_8 = (**(code **)(*in_EAX + 0x20))(uVar1);
  iVar4 = (**(code **)(*in_EAX + 0x20))(iVar4);
  local_14 = (float)(local_8 - iVar4);
  local_8 = (int)local_c + -2;
  iVar4 = (**(code **)(*in_EAX + 0x20))(local_8);
  iVar5 = (**(code **)(*in_EAX + 0x20))(uVar1);
  local_c = (float)(iVar5 - iVar4);
  pfVar6 = (float *)(**(code **)(*in_EAX + 0x1c))(&local_44,local_10);
  pfVar7 = (float *)(**(code **)(*in_EAX + 0x1c))(&local_38,uVar1);
  local_20 = *pfVar7 - *pfVar6;
  local_1c = pfVar7[1] - pfVar6[1];
  local_18 = pfVar7[2] - pfVar6[2];
  pfVar6 = (float *)(**(code **)(*in_EAX + 0x1c))(&local_44,local_8);
  pfVar7 = (float *)(**(code **)(*in_EAX + 0x1c))(&local_38,uVar1);
  local_44 = local_20 * 0.5;
  local_40 = local_1c * 0.5;
  local_3c = local_18 * 0.5;
  local_38 = (*pfVar7 - *pfVar6) - local_44;
  local_34 = (pfVar7[1] - pfVar6[1]) - local_40;
  local_30 = (pfVar7[2] - pfVar6[2]) - local_3c;
  local_2c = local_38 * 3.0;
  local_28 = local_34 * 3.0;
  local_24 = local_30 * 3.0;
  if ((uint)((in_EAX[7] - in_EAX[6]) / 0x44) <= uVar1) {
    local_20 = local_2c * 0.5;
    local_1c = local_28 * 0.5;
    local_18 = local_24 * 0.5;
    local_10 = local_3c;
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  iVar4 = in_EAX[6] + uVar1 * 0x44;
  fVar2 = 0.25 - local_c / (local_14 + local_14);
  fVar3 = 1.0 - *(float *)(iVar4 + 0x18);
  *(float *)(iVar4 + 0x2c) = fVar3 * fVar2 * local_20 + local_2c * 0.5 + local_44;
  *(float *)(iVar4 + 0x30) = fVar2 * local_1c * fVar3 + local_28 * 0.5 + local_40;
  *(float *)(iVar4 + 0x34) = fVar3 * local_18 * fVar2 + local_24 * 0.5 + local_3c;
  return;
}

