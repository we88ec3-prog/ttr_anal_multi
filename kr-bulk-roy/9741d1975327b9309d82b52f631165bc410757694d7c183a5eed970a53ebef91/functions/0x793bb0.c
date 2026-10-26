
void FUN_00793bb0(float param_1)

{
  uint uVar1;
  int *in_EAX;
  float *pfVar2;
  float *pfVar3;
  float10 fVar4;
  undefined1 local_38 [12];
  undefined1 local_2c [12];
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  int local_8;
  
  uVar1 = (uint)param_1;
  local_8 = (**(code **)(*in_EAX + 0x18))();
  local_8 = (int)((int)param_1 + 1U) % local_8;
  fVar4 = (float10)FUN_00793920(param_1,local_8);
  param_1 = (float)fVar4;
  if (param_1 == 0.0) {
    param_1 = 1.0;
  }
  pfVar2 = (float *)(**(code **)(*in_EAX + 0x1c))(local_2c,uVar1);
  pfVar3 = (float *)(**(code **)(*in_EAX + 0x1c))(local_38,local_8);
  local_14 = *pfVar3 - *pfVar2;
  local_10 = pfVar3[1] - pfVar2[1];
  local_c = pfVar3[2] - pfVar2[2];
  local_20 = local_14 / param_1;
  local_1c = local_10 / param_1;
  local_18 = local_c / param_1;
  if ((uint)((in_EAX[7] - in_EAX[6]) / 0x30) <= uVar1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  pfVar2 = (float *)(in_EAX[6] + 0x24 + uVar1 * 0x30);
  *pfVar2 = local_20;
  pfVar2[1] = local_1c;
  pfVar2[2] = local_18;
  return;
}

