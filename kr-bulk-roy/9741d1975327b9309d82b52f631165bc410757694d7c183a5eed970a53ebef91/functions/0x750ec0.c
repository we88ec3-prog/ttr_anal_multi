
void FUN_00750ec0(int param_1,int param_2,int *param_3,undefined4 param_4,float *param_5)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int in_EAX;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  if ((0 < param_1) && (0 < param_2)) {
    (**(code **)(**(int **)(in_EAX + 0x1c) + 0x104))(*(int **)(in_EAX + 0x1c),0);
    iVar7 = *param_3;
    iVar8 = param_3[2];
    fVar3 = (1.0 / (float)param_1) * (float)iVar7;
    fVar2 = (1.0 / (float)param_1) * (float)iVar8;
    fVar5 = (1.0 / (float)param_2) * (float)param_3[1];
    fVar4 = (1.0 / (float)param_2) * (float)param_3[3];
    iVar6 = FUN_008fed10();
    FUN_0043c810((float)(iVar8 - iVar7) * *param_5);
    iVar7 = FUN_008fed10();
    iVar8 = FUN_008fed10();
    FUN_0043c810((float)(param_3[3] - param_3[1]) * param_5[1]);
    iVar9 = FUN_008fed10();
    *(float *)(in_EAX + 0x1524) = (float)iVar6 - 0.5;
    *(float *)(in_EAX + 0x1528) = (float)iVar9 - 0.5;
    *(undefined4 *)(in_EAX + 0x152c) = 0;
    *(float *)(in_EAX + 0x1540) = (float)iVar7 - 0.5;
    *(float *)(in_EAX + 0x1544) = (float)iVar9 - 0.5;
    *(undefined4 *)(in_EAX + 0x1548) = 0;
    *(float *)(in_EAX + 0x155c) = (float)iVar6 - 0.5;
    *(float *)(in_EAX + 0x1560) = (float)iVar8 - 0.5;
    *(undefined4 *)(in_EAX + 0x1564) = 0;
    *(float *)(in_EAX + 0x1578) = (float)iVar7 - 0.5;
    *(float *)(in_EAX + 0x157c) = (float)iVar8 - 0.5;
    *(undefined4 *)(in_EAX + 0x1580) = 0;
    *(float *)(in_EAX + 0x1538) = fVar3;
    *(float *)(in_EAX + 0x153c) = fVar4;
    *(float *)(in_EAX + 0x1554) = fVar2;
    *(float *)(in_EAX + 0x1558) = fVar4;
    *(float *)(in_EAX + 0x1570) = fVar3;
    *(float *)(in_EAX + 0x1574) = fVar5;
    *(float *)(in_EAX + 0x1590) = fVar5;
    *(float *)(in_EAX + 0x158c) = fVar2;
    FUN_00753930((float *)(in_EAX + 0x1524));
    piVar1 = *(int **)(in_EAX + 0x1c);
    (**(code **)(*piVar1 + 400))(piVar1,0,*(undefined4 *)(in_EAX + 0x1598),0,0x1c);
    (**(code **)(*piVar1 + 0x164))(piVar1,0x144);
    (**(code **)(*piVar1 + 0x144))(piVar1,5,0,2);
    (**(code **)(**(int **)(in_EAX + 0x1c) + 0x104))(*(int **)(in_EAX + 0x1c),0,0);
  }
  return;
}

