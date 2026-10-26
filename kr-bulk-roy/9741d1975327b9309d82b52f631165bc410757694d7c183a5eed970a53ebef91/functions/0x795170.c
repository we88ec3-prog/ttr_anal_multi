
void FUN_00795170(void)

{
  int iVar1;
  int *in_EAX;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  undefined1 local_38 [12];
  undefined1 local_2c [12];
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar4 = in_EAX[7] - in_EAX[6];
  iVar1 = iVar4 >> 0x1f;
  if (iVar4 / 0x44 + iVar1 == iVar1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  local_8 = *(float *)(in_EAX[6] + 0x18);
  pfVar2 = (float *)(**(code **)(*in_EAX + 0x1c))(local_2c,0);
  pfVar3 = (float *)(**(code **)(*in_EAX + 0x1c))(local_38,1);
  local_14 = *pfVar3 - *pfVar2;
  iVar1 = in_EAX[6];
  local_10 = pfVar3[1] - pfVar2[1];
  local_c = pfVar3[2] - pfVar2[2];
  local_8 = 1.0 - local_8;
  iVar4 = in_EAX[7] - iVar1 >> 0x1f;
  local_20 = local_8 * local_14;
  local_1c = local_10 * local_8;
  local_18 = local_8 * local_c;
  if ((in_EAX[7] - iVar1) / 0x44 + iVar4 == iVar4) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  *(float *)(iVar1 + 0x38) = local_20;
  *(float *)(iVar1 + 0x3c) = local_1c;
  *(float *)(iVar1 + 0x40) = local_18;
  if ((uint)((in_EAX[7] - in_EAX[6]) / 0x44) < 2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  local_8 = 1.0 - *(float *)(in_EAX[6] + 0x5c);
  pfVar2 = (float *)(**(code **)(*in_EAX + 0x1c))(local_38,0);
  local_20 = local_8 * *pfVar2;
  local_1c = pfVar2[1] * local_8;
  local_18 = local_8 * pfVar2[2];
  pfVar2 = (float *)(**(code **)(*in_EAX + 0x1c))(local_2c,1);
  iVar1 = in_EAX[6];
  local_14 = *pfVar2 - local_20;
  local_10 = pfVar2[1] - local_1c;
  local_c = pfVar2[2] - local_18;
  if ((uint)((in_EAX[7] - iVar1) / 0x44) < 2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  *(float *)(iVar1 + 0x70) = local_14;
  *(float *)(iVar1 + 0x74) = local_10;
  *(float *)(iVar1 + 0x78) = local_c;
  return;
}

