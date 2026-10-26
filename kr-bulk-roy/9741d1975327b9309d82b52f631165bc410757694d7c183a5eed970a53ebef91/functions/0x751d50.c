
void FUN_00751d50(int *param_1,undefined4 param_2,float *param_3)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int in_EAX;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int in_ECX;
  
  iVar7 = *(int *)(in_EAX + 0x5c);
  iVar8 = *(int *)(in_EAX + 0x58);
  if ((0 < iVar8) && (0 < iVar7)) {
    uVar6 = (**(code **)(**(int **)(in_EAX + 8) + 0x10))();
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x104))(*(int **)(in_ECX + 0x1c),0,uVar6);
    iVar9 = *param_1;
    iVar10 = param_1[2];
    fVar2 = 1.0 / (float)iVar8;
    fVar3 = 1.0 / (float)iVar7;
    fVar4 = fVar2 * (float)iVar9;
    fVar2 = fVar2 * (float)iVar10;
    fVar5 = fVar3 * (float)param_1[1];
    fVar3 = fVar3 * (float)param_1[3];
    iVar7 = FUN_008fed10();
    FUN_0043c810((float)(iVar10 - iVar9) * *param_3);
    iVar8 = FUN_008fed10();
    iVar9 = FUN_008fed10();
    FUN_0043c810((float)(param_1[3] - param_1[1]) * param_3[1]);
    iVar10 = FUN_008fed10();
    *(float *)(in_ECX + 0x1524) = (float)iVar7 - 0.5;
    *(float *)(in_ECX + 0x1528) = (float)iVar10 - 0.5;
    *(undefined4 *)(in_ECX + 0x152c) = 0;
    *(float *)(in_ECX + 0x1540) = (float)iVar8 - 0.5;
    *(float *)(in_ECX + 0x1544) = (float)iVar10 - 0.5;
    *(undefined4 *)(in_ECX + 0x1548) = 0;
    *(float *)(in_ECX + 0x155c) = (float)iVar7 - 0.5;
    *(float *)(in_ECX + 0x1560) = (float)iVar9 - 0.5;
    *(undefined4 *)(in_ECX + 0x1564) = 0;
    *(float *)(in_ECX + 0x1578) = (float)iVar8 - 0.5;
    *(float *)(in_ECX + 0x157c) = (float)iVar9 - 0.5;
    *(undefined4 *)(in_ECX + 0x1580) = 0;
    *(float *)(in_ECX + 0x1538) = fVar4;
    *(float *)(in_ECX + 0x153c) = fVar3;
    *(float *)(in_ECX + 0x1554) = fVar2;
    *(float *)(in_ECX + 0x1558) = fVar3;
    *(float *)(in_ECX + 0x1570) = fVar4;
    *(float *)(in_ECX + 0x1574) = fVar5;
    *(float *)(in_ECX + 0x1590) = fVar5;
    *(float *)(in_ECX + 0x158c) = fVar2;
    FUN_00753930((float *)(in_ECX + 0x1524));
    piVar1 = *(int **)(in_ECX + 0x1c);
    (**(code **)(*piVar1 + 400))(piVar1,0,*(undefined4 *)(in_ECX + 0x1598),0,0x1c);
    (**(code **)(*piVar1 + 0x164))(piVar1,0x144);
    (**(code **)(*piVar1 + 0x144))(piVar1,5,0,2);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x104))(*(int **)(in_ECX + 0x1c),0,0);
  }
  return;
}

