
void FUN_00751f90(int param_1,undefined4 param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int in_EAX;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar6 = *(int *)(param_1 + 8);
  if (iVar6 != 0) {
    iVar7 = *(int *)(iVar6 + 0x58);
    iVar8 = *(int *)(iVar6 + 0x5c);
    if ((0 < iVar7) && (0 < iVar8)) {
      uVar5 = (**(code **)(**(int **)(iVar6 + 8) + 0x10))();
      (**(code **)(**(int **)(in_EAX + 0x1c) + 0x104))(*(int **)(in_EAX + 0x1c),0,uVar5);
      fVar1 = 1.0 / (float)iVar7;
      fVar2 = 1.0 / (float)iVar8;
      fVar3 = fVar1 * (float)*(int *)(param_1 + 0x28);
      fVar1 = fVar1 * (float)*(int *)(param_1 + 0x30);
      fVar4 = fVar2 * (float)*(int *)(param_1 + 0x2c);
      fVar2 = fVar2 * (float)*(int *)(param_1 + 0x34);
      iVar6 = FUN_008fed10();
      FUN_0043c810((float)(*(int *)(param_1 + 0x30) - *(int *)(param_1 + 0x28)) * *param_3);
      iVar7 = FUN_008fed10();
      iVar8 = FUN_008fed10();
      FUN_0043c810((float)(*(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x2c)) * param_3[1]);
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
      *(float *)(in_EAX + 0x153c) = fVar2;
      *(float *)(in_EAX + 0x1554) = fVar1;
      *(float *)(in_EAX + 0x1558) = fVar2;
      *(float *)(in_EAX + 0x1570) = fVar3;
      *(float *)(in_EAX + 0x1574) = fVar4;
      *(float *)(in_EAX + 0x1590) = fVar4;
      *(float *)(in_EAX + 0x158c) = fVar1;
      FUN_00753930((float *)(in_EAX + 0x1524));
      FUN_00753980();
      (**(code **)(**(int **)(in_EAX + 0x1c) + 0x104))(*(int **)(in_EAX + 0x1c),0,0);
    }
  }
  return;
}

