
void FUN_007521a0(int *param_1,int *param_2,undefined4 param_3,float *param_4)

{
  float *pfVar1;
  int *piVar2;
  float fVar3;
  int in_EAX;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  float10 extraout_ST0;
  undefined4 local_38;
  undefined4 local_34;
  int *local_30;
  int *local_2c;
  float local_28;
  float local_24;
  float local_20;
  int *local_1c;
  int *local_18;
  float local_14;
  float local_10;
  int *local_c;
  int *local_8;
  
  iVar5 = *(int *)(in_EAX + 0x5c);
  iVar6 = *(int *)(in_EAX + 0x58);
  if ((0 < iVar6) && (0 < iVar5)) {
    local_14 = (float)iVar6;
    local_10 = (float)iVar5;
    uVar4 = (**(code **)(**(int **)(in_EAX + 8) + 0x10))();
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x104))(*(int **)(in_ECX + 0x1c),0,uVar4);
    local_8 = (int *)0x0;
    local_c = (int *)0x0;
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x5c))
              (*(int **)(in_ECX + 0x1c),iVar6,iVar5,1,1,0x15,0,&local_1c,0);
    (**(code **)(*local_1c + 0x48))(local_1c,0,&local_18);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x98))(*(int **)(in_ECX + 0x1c),0,&local_8);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0xa0))(*(int **)(in_ECX + 0x1c),&local_c);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x110))(*(int **)(in_ECX + 0x1c),0,1,&local_34);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x110))(*(int **)(in_ECX + 0x1c),0,2,&local_38);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x94))(*(int **)(in_ECX + 0x1c),0,local_18);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x9c))(*(int **)(in_ECX + 0x1c),0);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x114))(*(int **)(in_ECX + 0x1c),0,1,1);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x114))(*(int **)(in_ECX + 0x1c),0,2,1);
    local_20 = (float)(int)local_14;
    local_30 = param_1 + 1;
    local_2c = param_1 + 3;
    pfVar1 = (float *)(in_ECX + 0x1524);
    local_14 = 1.0 / local_20;
    fVar3 = (float)(int)local_10;
    local_10 = 1.0 / fVar3;
    local_24 = local_14 * (float)*param_1;
    local_14 = local_14 * (float)param_1[2];
    local_28 = local_10 * (float)*local_30;
    local_10 = local_10 * (float)*local_2c;
    fVar3 = fVar3 - 0.5;
    *pfVar1 = -0.5;
    *(float *)(in_ECX + 0x1528) = fVar3;
    *(undefined4 *)(in_ECX + 0x152c) = 0;
    local_20 = local_20 - 0.5;
    *(float *)(in_ECX + 0x1540) = local_20;
    *(float *)(in_ECX + 0x1544) = fVar3;
    *(undefined4 *)(in_ECX + 0x1548) = 0;
    *(undefined4 *)(in_ECX + 0x155c) = 0xbf000000;
    *(undefined4 *)(in_ECX + 0x1560) = 0xbf000000;
    *(undefined4 *)(in_ECX + 0x1564) = 0;
    *(float *)(in_ECX + 0x1578) = local_20;
    *(undefined4 *)(in_ECX + 0x157c) = 0xbf000000;
    *(undefined4 *)(in_ECX + 0x1580) = 0;
    *(float *)(in_ECX + 0x1538) = local_24;
    *(float *)(in_ECX + 0x153c) = local_10;
    *(float *)(in_ECX + 0x1554) = local_14;
    *(float *)(in_ECX + 0x1558) = local_10;
    *(float *)(in_ECX + 0x1570) = local_24;
    *(float *)(in_ECX + 0x1574) = local_28;
    *(float *)(in_ECX + 0x1590) = local_28;
    *(float *)(in_ECX + 0x158c) = local_14;
    FUN_00753930(pfVar1);
    piVar2 = *(int **)(in_ECX + 0x1c);
    (**(code **)(*piVar2 + 400))(piVar2,0,*(undefined4 *)(in_ECX + 0x1598),0,0x1c);
    (**(code **)(*piVar2 + 0x164))(piVar2,0x144);
    (**(code **)(*piVar2 + 0x144))(piVar2,5,0,2);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x104))(*(int **)(in_ECX + 0x1c),0,0);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x94))(*(int **)(in_ECX + 0x1c),0,local_8);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x9c))(*(int **)(in_ECX + 0x1c),local_c);
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 8))(local_8);
      local_8 = (int *)0x0;
    }
    if (local_c != (int *)0x0) {
      (**(code **)(*local_c + 8))(local_c);
      local_c = (int *)0x0;
    }
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x104))(*(int **)(in_ECX + 0x1c),0,local_1c);
    local_14 = (float)(param_2[2] - *param_2) / (float)(param_1[2] - *param_1);
    local_10 = (float)(param_2[3] - param_2[1]) / (float)(*local_2c - *local_30);
    iVar5 = FUN_008fed10();
    FUN_0043c810((float)(extraout_ST0 * (float10)*param_4));
    local_30 = (int *)FUN_008fed10();
    local_2c = (int *)FUN_008fed10();
    FUN_0043c810((float)(param_2[3] - param_2[1]) * param_4[1]);
    iVar6 = FUN_008fed10();
    *pfVar1 = (float)iVar5 - 0.5;
    *(float *)(in_ECX + 0x1528) = (float)iVar6 - 0.5;
    *(undefined4 *)(in_ECX + 0x152c) = 0;
    *(float *)(in_ECX + 0x1540) = (float)(int)local_30 - 0.5;
    *(float *)(in_ECX + 0x1544) = (float)iVar6 - 0.5;
    *(undefined4 *)(in_ECX + 0x1548) = 0;
    *(float *)(in_ECX + 0x155c) = (float)iVar5 - 0.5;
    *(float *)(in_ECX + 0x1560) = (float)(int)local_2c - 0.5;
    *(undefined4 *)(in_ECX + 0x1564) = 0;
    *(float *)(in_ECX + 0x1578) = (float)(int)local_30 - 0.5;
    *(float *)(in_ECX + 0x157c) = (float)(int)local_2c - 0.5;
    *(undefined4 *)(in_ECX + 0x1580) = 0;
    *(undefined4 *)(in_ECX + 0x1538) = 0;
    *(float *)(in_ECX + 0x153c) = local_10;
    *(float *)(in_ECX + 0x1554) = local_14;
    *(float *)(in_ECX + 0x158c) = local_14;
    *(float *)(in_ECX + 0x1558) = local_10;
    *(undefined4 *)(in_ECX + 0x1570) = 0;
    *(undefined4 *)(in_ECX + 0x1574) = 0;
    *(undefined4 *)(in_ECX + 0x1590) = 0;
    FUN_00753930(pfVar1);
    piVar2 = *(int **)(in_ECX + 0x1c);
    (**(code **)(*piVar2 + 400))(piVar2,0,*(undefined4 *)(in_ECX + 0x1598),0,0x1c);
    (**(code **)(*piVar2 + 0x164))(piVar2,0x144);
    (**(code **)(*piVar2 + 0x144))(piVar2,5,0,2);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x104))(*(int **)(in_ECX + 0x1c),0,0);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x114))(*(int **)(in_ECX + 0x1c),0,1,local_34);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x114))(*(int **)(in_ECX + 0x1c),0,2,local_38);
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
      local_18 = (int *)0x0;
    }
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
  }
  return;
}

