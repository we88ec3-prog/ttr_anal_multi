
void FUN_00793c90(float param_1)

{
  uint uVar1;
  int *in_EAX;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float10 fVar5;
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
  iVar2 = (**(code **)(*in_EAX + 0x18))();
  local_8 = (**(code **)(*in_EAX + 0x18))();
  local_8 = (iVar2 + -1 + (int)param_1) % local_8;
  fVar5 = (float10)FUN_00793920(local_8,param_1);
  param_1 = (float)fVar5;
  if (param_1 == 0.0) {
    param_1 = 1.0;
  }
  pfVar3 = (float *)(**(code **)(*in_EAX + 0x1c))(local_2c,uVar1);
  pfVar4 = (float *)(**(code **)(*in_EAX + 0x1c))(local_38,local_8);
  local_14 = *pfVar4 - *pfVar3;
  local_10 = pfVar4[1] - pfVar3[1];
  local_c = pfVar4[2] - pfVar3[2];
  local_20 = local_14 / param_1;
  local_1c = local_10 / param_1;
  local_18 = local_c / param_1;
  if ((uint)((in_EAX[7] - in_EAX[6]) / 0x30) <= uVar1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  pfVar3 = (float *)(in_EAX[6] + 0x18 + uVar1 * 0x30);
  *pfVar3 = local_20;
  pfVar3[1] = local_1c;
  pfVar3[2] = local_18;
  return;
}

