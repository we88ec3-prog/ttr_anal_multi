
void FUN_00751230(int param_1,int param_2,undefined4 *param_3,float *param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int *in_EAX;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int unaff_EDI;
  
  if (0x1ff < *(int *)(unaff_EDI + 0x1659c)) {
    FUN_006edb60(&DAT_00c478c0);
    return;
  }
  if ((0 < param_1) && (0 < param_2)) {
    fVar2 = (1.0 / (float)param_1) * (float)*in_EAX;
    fVar1 = (1.0 / (float)param_1) * (float)in_EAX[2];
    fVar4 = (1.0 / (float)param_2) * (float)in_EAX[1];
    fVar3 = (1.0 / (float)param_2) * (float)in_EAX[3];
    FUN_0043c810(*param_3);
    iVar9 = FUN_008fed10();
    FUN_0043c810((float)(in_EAX[2] - *in_EAX) * *param_4);
    iVar10 = FUN_008fed10();
    FUN_0043c810(param_3[1]);
    iVar11 = FUN_008fed10();
    FUN_0043c810((float)(in_EAX[3] - in_EAX[1]) * param_4[1]);
    iVar12 = FUN_008fed10();
    fVar5 = (float)iVar9 - 0.5;
    iVar9 = unaff_EDI + *(int *)(unaff_EDI + 0x1659c) * 0xa8;
    fVar6 = (float)iVar12 - 0.5;
    fVar7 = (float)iVar10 - 0.5;
    fVar8 = (float)iVar11 - 0.5;
    *(float *)(iVar9 + 0x159c) = fVar5;
    *(float *)(iVar9 + 0x15a0) = fVar8;
    *(undefined4 *)(iVar9 + 0x15a4) = 0;
    *(float *)(iVar9 + 0x15b8) = fVar5;
    *(float *)(iVar9 + 0x15bc) = fVar6;
    *(undefined4 *)(iVar9 + 0x15c0) = 0;
    *(float *)(iVar9 + 0x15d4) = fVar7;
    *(float *)(iVar9 + 0x15d8) = fVar6;
    *(undefined4 *)(iVar9 + 0x15dc) = 0;
    *(float *)(iVar9 + 0x15b0) = fVar2;
    *(float *)(iVar9 + 0x15b4) = fVar4;
    *(float *)(iVar9 + 0x15cc) = fVar2;
    *(float *)(iVar9 + 0x15d0) = fVar3;
    *(float *)(iVar9 + 0x15e8) = fVar1;
    *(float *)(iVar9 + 0x15ec) = fVar3;
    *(float *)(iVar9 + 0x15f0) = fVar7;
    *(float *)(iVar9 + 0x15f4) = fVar6;
    *(undefined4 *)(iVar9 + 0x15f8) = 0;
    *(float *)(iVar9 + 0x160c) = fVar7;
    *(float *)(iVar9 + 0x1610) = fVar8;
    *(undefined4 *)(iVar9 + 0x1614) = 0;
    *(undefined4 *)(iVar9 + 0x1630) = 0;
    *(float *)(iVar9 + 0x1628) = fVar5;
    *(float *)(iVar9 + 0x162c) = fVar8;
    *(float *)(iVar9 + 0x1604) = fVar1;
    *(float *)(iVar9 + 0x1620) = fVar1;
    *(float *)(iVar9 + 0x1608) = fVar3;
    *(float *)(iVar9 + 0x1624) = fVar4;
    *(float *)(iVar9 + 0x1640) = fVar4;
    *(float *)(iVar9 + 0x163c) = fVar2;
    param_2._0_1_ = (undefined1)(int)ROUND(param_5 * 255.0);
    uVar13 = CONCAT31(CONCAT21(CONCAT11((undefined1)param_2,(undefined1)param_2),(undefined1)param_2
                              ),(undefined1)param_2);
    *(undefined4 *)(iVar9 + 0x15ac) = uVar13;
    *(undefined4 *)(iVar9 + 0x15c8) = uVar13;
    *(undefined4 *)(iVar9 + 0x15e4) = uVar13;
    *(undefined4 *)(iVar9 + 0x1600) = uVar13;
    *(undefined4 *)(iVar9 + 0x161c) = uVar13;
    *(undefined4 *)(iVar9 + 0x1638) = uVar13;
    *(int *)(unaff_EDI + 0x1659c) = *(int *)(unaff_EDI + 0x1659c) + 1;
  }
  return;
}

