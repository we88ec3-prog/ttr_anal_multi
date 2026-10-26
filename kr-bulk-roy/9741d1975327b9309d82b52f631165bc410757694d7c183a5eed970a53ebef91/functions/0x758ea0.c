
int * FUN_00758ea0(undefined4 *param_1,int *param_2,int *param_3,float param_4)

{
  float fVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int *in_ECX;
  int *piVar5;
  int iVar6;
  int local_50;
  int local_40 [4];
  int *local_30;
  int local_2c;
  undefined4 local_28;
  int local_20;
  undefined4 local_1c;
  int local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907e20;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (param_1[4] == 0) {
    *param_2 = *param_3;
    param_2[1] = param_3[1];
    iVar6 = param_3[3];
    param_2[2] = param_3[2];
    param_2[3] = iVar6;
    return param_2;
  }
  if (in_ECX[2] == 0) {
    fVar1 = 1.33;
  }
  else {
    fVar1 = *(float *)(in_ECX[2] + 0x80);
  }
  local_14 = (float)in_ECX[4];
  if (in_ECX[4] < 0) {
    local_14 = local_14 + 4.2949673e+09;
  }
  local_14 = local_14 * fVar1;
  local_30 = (int *)0x0;
  local_2c = 0;
  local_28 = 0;
  local_40[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  local_8 = 1;
  ExceptionList = &local_10;
  FUN_00758180(param_1,&local_30,local_40,in_ECX,param_3,param_1[4],param_4);
  param_4 = 0.0;
  iVar6 = local_2c - (int)local_30 >> 2;
  local_20 = iVar6;
  local_20 = FUN_008fed10(uVar2);
  if (iVar6 != 0) {
    local_18 = local_40[0] - (int)local_30;
    piVar5 = local_30;
    do {
      local_14 = 0.0;
      local_1c = 0;
      puVar3 = param_1;
      if (7 < (uint)param_1[5]) {
        puVar3 = (undefined4 *)*param_1;
      }
      (**(code **)(*in_ECX + 0x30))
                (&local_14,&local_1c,(int)puVar3 + *piVar5 * 2,
                 *(undefined4 *)(local_18 + (int)piVar5));
      if ((int)param_4 <= (int)local_14) {
        param_4 = local_14;
      }
      piVar5 = piVar5 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  local_50 = 0;
  if (*param_3 < 1) {
    local_50 = *param_3;
  }
  if ((int)param_4 <= param_3[2]) {
    param_4 = (float)param_3[2];
  }
  iVar6 = 0;
  if (param_3[1] < 1) {
    iVar6 = param_3[1];
  }
  iVar4 = local_20;
  if (local_20 <= param_3[3]) {
    iVar4 = param_3[3];
  }
  *param_2 = local_50;
  param_2[1] = iVar6;
  param_2[2] = (int)param_4;
  param_2[3] = iVar4;
  if (local_40[0] != 0) {
    FUN_0089120c(local_40[0]);
  }
  if (local_30 != (int *)0x0) {
    FUN_0089120c(local_30);
  }
  ExceptionList = local_10;
  return param_2;
}

