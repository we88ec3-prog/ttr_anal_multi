
void FUN_0078e820(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined4 *unaff_ESI;
  undefined4 *puVar16;
  
  if ((unaff_ESI != param_1) && (puVar15 = unaff_ESI + 0xc, puVar15 != param_1)) {
    puVar16 = unaff_ESI + 0xd;
    do {
      uVar2 = *puVar16;
      iVar3 = puVar16[3];
      uVar4 = puVar16[1];
      uVar5 = puVar16[2];
      uVar6 = puVar16[5];
      uVar7 = puVar16[6];
      uVar8 = puVar16[7];
      uVar9 = puVar16[8];
      uVar10 = puVar16[9];
      uVar11 = puVar16[10];
      if (iVar3 < (int)unaff_ESI[4]) {
        FUN_00790500();
        unaff_ESI[1] = uVar2;
        unaff_ESI[2] = uVar4;
        unaff_ESI[3] = uVar5;
        unaff_ESI[6] = uVar6;
        unaff_ESI[7] = uVar7;
        unaff_ESI[8] = uVar8;
        unaff_ESI[9] = uVar9;
        unaff_ESI[10] = uVar10;
        unaff_ESI[4] = iVar3;
        unaff_ESI[5] = 0;
        unaff_ESI[0xb] = uVar11;
      }
      else {
        iVar1 = puVar16[-9];
        puVar14 = puVar16 + -0xd;
        puVar13 = puVar15;
        while (puVar12 = puVar14, iVar3 < iVar1) {
          puVar13[1] = puVar12[1];
          puVar13[2] = puVar12[2];
          puVar13[3] = puVar12[3];
          puVar13[4] = puVar12[4];
          puVar13[5] = puVar12[5];
          puVar13[6] = puVar12[6];
          puVar13[7] = puVar12[7];
          puVar13[8] = puVar12[8];
          puVar13[9] = puVar12[9];
          puVar13[10] = puVar12[10];
          puVar13[0xb] = puVar12[0xb];
          puVar14 = puVar12 + -0xc;
          puVar13 = puVar12;
          iVar1 = puVar12[-8];
        }
        puVar13[1] = uVar2;
        puVar13[2] = uVar4;
        puVar13[3] = uVar5;
        puVar13[6] = uVar6;
        puVar13[7] = uVar7;
        puVar13[8] = uVar8;
        puVar13[9] = uVar9;
        puVar13[10] = uVar10;
        puVar13[4] = iVar3;
        puVar13[5] = 0;
        puVar13[0xb] = uVar11;
      }
      puVar15 = puVar15 + 0xc;
      puVar16 = puVar16 + 0xc;
    } while (puVar15 != param_1);
  }
  return;
}

