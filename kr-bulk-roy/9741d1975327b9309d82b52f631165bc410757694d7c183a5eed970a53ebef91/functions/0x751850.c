
void FUN_00751850(int param_1,float param_2,float param_3,int *param_4,int *param_5,float *param_6)

{
  int *piVar1;
  float *pfVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int in_EDX;
  float10 extraout_ST0;
  float10 fVar6;
  undefined4 local_58;
  undefined4 local_54;
  float *local_50;
  int local_4c;
  float local_48;
  float local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  float local_2c;
  float local_28;
  float local_24;
  int *local_20;
  int *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_20 = param_5;
  local_24 = param_2;
  local_28 = param_3;
  local_50 = param_6;
  if ((0 < (int)param_2) && (0 < (int)param_3)) {
    local_4c = in_EDX;
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x104))(*(int **)(param_1 + 0x1c),0);
    local_34 = (int *)0x0;
    local_40 = (int *)0x0;
    local_3c = (int *)0x0;
    local_38 = (int *)0x0;
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x5c))
              (*(int **)(param_1 + 0x1c),param_2,param_3,1,1,0x15,0,&local_34,0);
    if (local_34 != (int *)0x0) {
      (**(code **)(*local_34 + 0x48))(local_34,0,&local_40);
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x98))(*(int **)(param_1 + 0x1c),0,&local_3c);
      (**(code **)(**(int **)(param_1 + 0x1c) + 0xa0))(*(int **)(param_1 + 0x1c),&local_38);
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x110))(*(int **)(param_1 + 0x1c),0,1,&local_58);
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x110))(*(int **)(param_1 + 0x1c),0,2,&local_54);
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x94))(*(int **)(param_1 + 0x1c),0,local_40);
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x9c))(*(int **)(param_1 + 0x1c),0);
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x114))(*(int **)(param_1 + 0x1c),0,1,1);
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x114))(*(int **)(param_1 + 0x1c),0,2,1);
      local_18 = 0;
      local_14 = 0;
      local_10 = param_2;
      local_c = param_3;
      (**(code **)(**(int **)(param_1 + 0x1c) + 0xac))
                (*(int **)(param_1 + 0x1c),1,&local_18,1,0,0,0);
      local_2c = (float)(int)local_24;
      local_1c = param_4 + 1;
      local_30 = param_4 + 3;
      pfVar2 = (float *)(param_1 + 0x1524);
      local_24 = 1.0 / local_2c;
      fVar3 = (float)(int)local_28;
      local_28 = 1.0 / fVar3;
      local_48 = local_24 * (float)*param_4;
      local_24 = local_24 * (float)param_4[2];
      local_44 = local_28 * (float)*local_1c;
      local_28 = local_28 * (float)*local_30;
      fVar3 = fVar3 - 0.5;
      *pfVar2 = -0.5;
      *(float *)(param_1 + 0x1528) = fVar3;
      *(undefined4 *)(param_1 + 0x152c) = 0;
      local_2c = local_2c - 0.5;
      *(float *)(param_1 + 0x1540) = local_2c;
      *(float *)(param_1 + 0x1544) = fVar3;
      *(undefined4 *)(param_1 + 0x1548) = 0;
      *(undefined4 *)(param_1 + 0x155c) = 0xbf000000;
      *(undefined4 *)(param_1 + 0x1560) = 0xbf000000;
      *(undefined4 *)(param_1 + 0x1564) = 0;
      *(float *)(param_1 + 0x1578) = local_2c;
      *(undefined4 *)(param_1 + 0x157c) = 0xbf000000;
      *(undefined4 *)(param_1 + 0x1580) = 0;
      *(float *)(param_1 + 0x1538) = local_48;
      *(float *)(param_1 + 0x153c) = local_28;
      *(float *)(param_1 + 0x1554) = local_24;
      *(float *)(param_1 + 0x1558) = local_28;
      *(float *)(param_1 + 0x1570) = local_48;
      *(float *)(param_1 + 0x1574) = local_44;
      *(float *)(param_1 + 0x1590) = local_44;
      *(float *)(param_1 + 0x158c) = local_24;
      FUN_00753930(pfVar2);
      FUN_00753980();
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x94))(*(int **)(param_1 + 0x1c),0,local_3c);
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x9c))(*(int **)(param_1 + 0x1c),local_38);
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x104))(*(int **)(param_1 + 0x1c),0,local_34);
      piVar4 = local_20;
      piVar1 = local_20 + 2;
      iVar5 = *local_20;
      local_20 = (int *)(local_20[3] - local_20[1]);
      local_24 = (float)(*piVar1 - iVar5) / (float)(param_4[2] - *param_4);
      local_1c = (int *)(*local_30 - *local_1c);
      local_28 = (float)(int)local_20 / (float)(int)local_1c;
      local_20 = (int *)FUN_008fed10();
      local_1c = (int *)(float)(extraout_ST0 * (float10)*local_50);
      fVar6 = (float10)FUN_0043c810(local_1c);
      local_1c = (int *)(float)fVar6;
      local_44 = (float)FUN_008fed10();
      local_30 = (int *)(local_4c + 4);
      local_48 = (float)FUN_008fed10();
      local_1c = (int *)((float)(piVar4[3] - piVar4[1]) * local_50[1]);
      fVar6 = (float10)FUN_0043c810(local_1c);
      local_1c = (int *)(float)fVar6;
      iVar5 = FUN_008fed10();
      local_30 = (int *)((float)(int)local_20 - 0.5);
      *pfVar2 = (float)local_30;
      *(float *)(param_1 + 0x1528) = (float)iVar5 - 0.5;
      *(undefined4 *)(param_1 + 0x152c) = 0;
      *(float *)(param_1 + 0x1540) = (float)(int)local_44 - 0.5;
      *(float *)(param_1 + 0x1544) = (float)iVar5 - 0.5;
      *(undefined4 *)(param_1 + 0x1548) = 0;
      local_1c = (int *)((float)(int)local_48 - 0.5);
      *(int **)(param_1 + 0x155c) = local_30;
      *(int **)(param_1 + 0x1560) = local_1c;
      *(undefined4 *)(param_1 + 0x1564) = 0;
      *(float *)(param_1 + 0x1578) = (float)(int)local_44 - 0.5;
      *(int **)(param_1 + 0x157c) = local_1c;
      *(undefined4 *)(param_1 + 0x1580) = 0;
      *(undefined4 *)(param_1 + 0x1538) = 0;
      *(float *)(param_1 + 0x153c) = local_28;
      *(float *)(param_1 + 0x1554) = local_24;
      *(float *)(param_1 + 0x158c) = local_24;
      *(float *)(param_1 + 0x1558) = local_28;
      *(undefined4 *)(param_1 + 0x1570) = 0;
      *(undefined4 *)(param_1 + 0x1574) = 0;
      *(undefined4 *)(param_1 + 0x1590) = 0;
      FUN_00753930(pfVar2);
      FUN_00753980();
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x104))(*(int **)(param_1 + 0x1c),0,0);
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x114))(*(int **)(param_1 + 0x1c),0,1,local_58);
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x114))(*(int **)(param_1 + 0x1c),0,2,local_54);
      if (local_3c != (int *)0x0) {
        (**(code **)(*local_3c + 8))(local_3c);
        local_3c = (int *)0x0;
      }
      if (local_38 != (int *)0x0) {
        (**(code **)(*local_38 + 8))(local_38);
        local_38 = (int *)0x0;
      }
      if (local_40 != (int *)0x0) {
        (**(code **)(*local_40 + 8))(local_40);
        local_40 = (int *)0x0;
      }
      if (local_34 != (int *)0x0) {
        (**(code **)(*local_34 + 8))(local_34);
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

