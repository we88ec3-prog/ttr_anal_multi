
void FUN_0078e3d0(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *unaff_EDI;
  
  if ((unaff_EDI != param_1) && (puVar10 = unaff_EDI + 6, puVar10 != param_1)) {
    puVar11 = unaff_EDI + 7;
    do {
      uVar2 = *puVar11;
      iVar3 = puVar11[3];
      uVar4 = puVar11[1];
      uVar5 = puVar11[2];
      uVar6 = puVar11[4];
      if (iVar3 < (int)unaff_EDI[4]) {
        FUN_007903f0();
        unaff_EDI[1] = uVar2;
        unaff_EDI[2] = uVar4;
        unaff_EDI[3] = uVar5;
        unaff_EDI[4] = iVar3;
        unaff_EDI[5] = uVar6;
      }
      else {
        iVar1 = puVar11[-3];
        puVar9 = puVar11 + -7;
        puVar8 = puVar10;
        while (puVar7 = puVar9, iVar3 < iVar1) {
          puVar8[1] = puVar7[1];
          puVar8[2] = puVar7[2];
          puVar8[3] = puVar7[3];
          puVar8[4] = puVar7[4];
          puVar8[5] = puVar7[5];
          puVar9 = puVar7 + -6;
          puVar8 = puVar7;
          iVar1 = puVar7[-2];
        }
        puVar8[1] = uVar2;
        puVar8[2] = uVar4;
        puVar8[3] = uVar5;
        puVar8[4] = iVar3;
        puVar8[5] = uVar6;
      }
      puVar10 = puVar10 + 6;
      puVar11 = puVar11 + 6;
    } while (puVar10 != param_1);
  }
  return;
}

