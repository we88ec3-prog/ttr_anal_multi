
void FUN_00795310(void)

{
  float fVar1;
  float fVar2;
  int *in_EAX;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
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
  float local_8;
  
  iVar3 = (**(code **)(*in_EAX + 0x20))(2);
  iVar4 = (**(code **)(*in_EAX + 0x20))(0);
  local_8 = (float)(iVar3 - iVar4);
  local_10 = (float)(int)local_8;
  iVar3 = (**(code **)(*in_EAX + 0x20))(1);
  iVar4 = (**(code **)(*in_EAX + 0x20))(0);
  local_8 = (float)(iVar3 - iVar4);
  local_c = (float)(int)local_8;
  pfVar5 = (float *)(**(code **)(*in_EAX + 0x1c))(&local_40,0);
  pfVar6 = (float *)(**(code **)(*in_EAX + 0x1c))(&local_34,2);
  local_1c = *pfVar6 - *pfVar5;
  local_18 = pfVar6[1] - pfVar5[1];
  local_14 = pfVar6[2] - pfVar5[2];
  pfVar5 = (float *)(**(code **)(*in_EAX + 0x1c))(&local_40,0);
  pfVar6 = (float *)(**(code **)(*in_EAX + 0x1c))(&local_34,1);
  iVar3 = in_EAX[6];
  local_40 = local_1c * 0.5;
  local_3c = local_18 * 0.5;
  iVar4 = in_EAX[7] - iVar3 >> 0x1f;
  local_38 = local_14 * 0.5;
  local_34 = (*pfVar6 - *pfVar5) - local_40;
  local_30 = (pfVar6[1] - pfVar5[1]) - local_3c;
  local_2c = (pfVar6[2] - pfVar5[2]) - local_38;
  local_28 = local_34 * 3.0;
  local_24 = local_30 * 3.0;
  local_20 = local_2c * 3.0;
  if ((in_EAX[7] - iVar3) / 0x44 + iVar4 == iVar4) {
    local_1c = local_28 * 0.5;
    local_18 = local_24 * 0.5;
    local_14 = local_20 * 0.5;
    local_8 = local_38;
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  fVar1 = 0.25 - local_c / (local_10 + local_10);
  fVar2 = 1.0 - *(float *)(iVar3 + 0x18);
  *(float *)(iVar3 + 0x38) = fVar2 * fVar1 * local_1c + local_28 * 0.5 + local_40;
  *(float *)(iVar3 + 0x3c) = fVar1 * local_18 * fVar2 + local_24 * 0.5 + local_3c;
  *(float *)(iVar3 + 0x40) = fVar2 * local_14 * fVar1 + local_20 * 0.5 + local_38;
  return;
}

