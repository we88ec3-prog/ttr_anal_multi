
void FUN_0078c380(uint *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  uint uVar33;
  int *piVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  
  uVar38 = param_2 + ((int)(param_3 - param_2) / 0x88) * 0x44;
  FUN_0078e990(uVar38,param_3 - 0x44,param_4);
  uVar39 = uVar38 + 0x44;
  for (; param_2 < uVar38; uVar38 = uVar38 - 0x44) {
    if ((*(int *)(uVar38 - 0x34) < *(int *)(uVar38 + 0x10)) ||
       (*(int *)(uVar38 + 0x10) < *(int *)(uVar38 - 0x34))) break;
  }
  uVar33 = uVar39;
  uVar35 = uVar39;
  uVar36 = uVar38;
  if (uVar39 < param_3) {
    do {
      uVar33 = uVar39;
      uVar35 = uVar39;
      if ((*(int *)(uVar39 + 0x10) < *(int *)(uVar38 + 0x10)) ||
         (*(int *)(uVar38 + 0x10) < *(int *)(uVar39 + 0x10))) break;
      uVar39 = uVar39 + 0x44;
      uVar33 = uVar39;
      uVar35 = uVar39;
    } while (uVar39 < param_3);
  }
joined_r0x0078c40a:
  do {
    if (param_3 <= uVar39) {
LAB_0078c53e:
      if (param_2 < uVar36) {
        piVar34 = (int *)(uVar36 - 0x34);
        uVar37 = uVar38;
        do {
          uVar38 = uVar37;
          uVar39 = uVar35;
          if (*(int *)(uVar37 + 0x10) <= *piVar34) {
            if (*(int *)(uVar37 + 0x10) < *piVar34) break;
            iVar11 = *(int *)(uVar37 - 0x3c);
            iVar1 = *(int *)(uVar37 - 0x2c);
            uVar38 = uVar37 - 0x44;
            iVar2 = *(int *)(uVar37 - 0x28);
            iVar12 = *(int *)(uVar37 - 0x38);
            iVar3 = *(int *)(uVar37 - 0x24);
            iVar13 = *(int *)(uVar37 - 0x34);
            iVar14 = *(int *)(uVar37 - 0x40);
            iVar4 = *(int *)(uVar37 - 0x20);
            iVar15 = *(int *)(uVar37 - 0x30);
            iVar5 = *(int *)(uVar37 - 0x1c);
            iVar16 = *(int *)(uVar37 - 0x18);
            iVar17 = *(int *)(uVar37 - 0x14);
            iVar18 = *(int *)(uVar37 - 0x10);
            iVar19 = *(int *)(uVar37 - 0xc);
            iVar20 = *(int *)(uVar37 - 8);
            iVar21 = *(int *)(uVar37 - 4);
            *(int *)(uVar37 - 0x40) = piVar34[-3];
            *(int *)(uVar37 - 0x3c) = piVar34[-2];
            *(int *)(uVar37 - 0x38) = piVar34[-1];
            *(int *)(uVar37 - 0x34) = *piVar34;
            *(int *)(uVar37 - 0x30) = piVar34[1];
            *(int *)(uVar37 - 0x2c) = piVar34[2];
            *(int *)(uVar37 - 0x28) = piVar34[3];
            *(int *)(uVar37 - 0x24) = piVar34[4];
            *(int *)(uVar37 - 0x20) = piVar34[5];
            *(int *)(uVar37 - 0x1c) = piVar34[6];
            *(int *)(uVar37 - 0x18) = piVar34[7];
            *(int *)(uVar37 - 0x14) = piVar34[8];
            *(int *)(uVar37 - 0x10) = piVar34[9];
            *(int *)(uVar37 - 0xc) = piVar34[10];
            *(int *)(uVar37 - 8) = piVar34[0xb];
            *(int *)(uVar37 - 4) = piVar34[0xc];
            piVar34[2] = iVar1;
            piVar34[-3] = iVar14;
            piVar34[3] = iVar2;
            piVar34[-2] = iVar11;
            piVar34[4] = iVar3;
            piVar34[-1] = iVar12;
            piVar34[5] = iVar4;
            *piVar34 = iVar13;
            piVar34[1] = iVar15;
            piVar34[6] = iVar5;
            piVar34[7] = iVar16;
            piVar34[8] = iVar17;
            piVar34[10] = iVar19;
            piVar34[9] = iVar18;
            piVar34[0xb] = iVar20;
            piVar34[0xc] = iVar21;
          }
          uVar36 = uVar36 - 0x44;
          piVar34 = piVar34 + -0x11;
          uVar37 = uVar38;
        } while (param_2 < uVar36);
      }
      if (uVar36 == param_2) {
        if (uVar39 == param_3) {
          param_1[1] = uVar33;
          *param_1 = uVar38;
          return;
        }
        if (uVar33 != uVar39) {
          uVar22 = *(undefined4 *)(uVar38 + 8);
          uVar6 = *(undefined4 *)(uVar38 + 0x18);
          uVar23 = *(undefined4 *)(uVar38 + 0xc);
          uVar7 = *(undefined4 *)(uVar38 + 0x1c);
          uVar24 = *(undefined4 *)(uVar38 + 0x10);
          uVar8 = *(undefined4 *)(uVar38 + 0x20);
          uVar25 = *(undefined4 *)(uVar38 + 4);
          uVar9 = *(undefined4 *)(uVar38 + 0x24);
          uVar26 = *(undefined4 *)(uVar38 + 0x14);
          uVar10 = *(undefined4 *)(uVar38 + 0x28);
          uVar27 = *(undefined4 *)(uVar38 + 0x2c);
          uVar28 = *(undefined4 *)(uVar38 + 0x30);
          uVar29 = *(undefined4 *)(uVar38 + 0x34);
          uVar30 = *(undefined4 *)(uVar38 + 0x38);
          uVar31 = *(undefined4 *)(uVar38 + 0x3c);
          uVar32 = *(undefined4 *)(uVar38 + 0x40);
          *(undefined4 *)(uVar38 + 4) = *(undefined4 *)(uVar33 + 4);
          *(undefined4 *)(uVar38 + 8) = *(undefined4 *)(uVar33 + 8);
          *(undefined4 *)(uVar38 + 0xc) = *(undefined4 *)(uVar33 + 0xc);
          *(undefined4 *)(uVar38 + 0x10) = *(undefined4 *)(uVar33 + 0x10);
          *(undefined4 *)(uVar38 + 0x14) = *(undefined4 *)(uVar33 + 0x14);
          *(undefined4 *)(uVar38 + 0x18) = *(undefined4 *)(uVar33 + 0x18);
          *(undefined4 *)(uVar38 + 0x1c) = *(undefined4 *)(uVar33 + 0x1c);
          *(undefined4 *)(uVar38 + 0x20) = *(undefined4 *)(uVar33 + 0x20);
          *(undefined4 *)(uVar38 + 0x24) = *(undefined4 *)(uVar33 + 0x24);
          *(undefined4 *)(uVar38 + 0x28) = *(undefined4 *)(uVar33 + 0x28);
          *(undefined4 *)(uVar38 + 0x2c) = *(undefined4 *)(uVar33 + 0x2c);
          *(undefined4 *)(uVar38 + 0x30) = *(undefined4 *)(uVar33 + 0x30);
          *(undefined4 *)(uVar38 + 0x34) = *(undefined4 *)(uVar33 + 0x34);
          *(undefined4 *)(uVar38 + 0x38) = *(undefined4 *)(uVar33 + 0x38);
          *(undefined4 *)(uVar38 + 0x3c) = *(undefined4 *)(uVar33 + 0x3c);
          *(undefined4 *)(uVar38 + 0x40) = *(undefined4 *)(uVar33 + 0x40);
          *(undefined4 *)(uVar33 + 0x18) = uVar6;
          *(undefined4 *)(uVar33 + 0x1c) = uVar7;
          *(undefined4 *)(uVar33 + 4) = uVar25;
          *(undefined4 *)(uVar33 + 0x20) = uVar8;
          *(undefined4 *)(uVar33 + 8) = uVar22;
          *(undefined4 *)(uVar33 + 0xc) = uVar23;
          *(undefined4 *)(uVar33 + 0x24) = uVar9;
          *(undefined4 *)(uVar33 + 0x10) = uVar24;
          *(undefined4 *)(uVar33 + 0x14) = uVar26;
          *(undefined4 *)(uVar33 + 0x28) = uVar10;
          *(undefined4 *)(uVar33 + 0x2c) = uVar27;
          *(undefined4 *)(uVar33 + 0x30) = uVar28;
          *(undefined4 *)(uVar33 + 0x38) = uVar30;
          *(undefined4 *)(uVar33 + 0x34) = uVar29;
          *(undefined4 *)(uVar33 + 0x3c) = uVar31;
          *(undefined4 *)(uVar33 + 0x40) = uVar32;
        }
        uVar6 = *(undefined4 *)(uVar38 + 0x18);
        uVar35 = uVar39 + 0x44;
        uVar7 = *(undefined4 *)(uVar38 + 0x1c);
        uVar22 = *(undefined4 *)(uVar38 + 4);
        uVar8 = *(undefined4 *)(uVar38 + 0x20);
        uVar23 = *(undefined4 *)(uVar38 + 8);
        uVar9 = *(undefined4 *)(uVar38 + 0x24);
        uVar24 = *(undefined4 *)(uVar38 + 0xc);
        uVar10 = *(undefined4 *)(uVar38 + 0x28);
        uVar25 = *(undefined4 *)(uVar38 + 0x10);
        uVar26 = *(undefined4 *)(uVar38 + 0x14);
        uVar27 = *(undefined4 *)(uVar38 + 0x2c);
        uVar28 = *(undefined4 *)(uVar38 + 0x30);
        uVar29 = *(undefined4 *)(uVar38 + 0x34);
        uVar30 = *(undefined4 *)(uVar38 + 0x38);
        uVar31 = *(undefined4 *)(uVar38 + 0x3c);
        uVar32 = *(undefined4 *)(uVar38 + 0x40);
        *(undefined4 *)(uVar38 + 4) = *(undefined4 *)(uVar39 + 4);
        *(undefined4 *)(uVar38 + 8) = *(undefined4 *)(uVar39 + 8);
        *(undefined4 *)(uVar38 + 0xc) = *(undefined4 *)(uVar39 + 0xc);
        *(undefined4 *)(uVar38 + 0x10) = *(undefined4 *)(uVar39 + 0x10);
        *(undefined4 *)(uVar38 + 0x14) = *(undefined4 *)(uVar39 + 0x14);
        *(undefined4 *)(uVar38 + 0x18) = *(undefined4 *)(uVar39 + 0x18);
        *(undefined4 *)(uVar38 + 0x1c) = *(undefined4 *)(uVar39 + 0x1c);
        *(undefined4 *)(uVar38 + 0x20) = *(undefined4 *)(uVar39 + 0x20);
        *(undefined4 *)(uVar38 + 0x24) = *(undefined4 *)(uVar39 + 0x24);
        *(undefined4 *)(uVar38 + 0x28) = *(undefined4 *)(uVar39 + 0x28);
        *(undefined4 *)(uVar38 + 0x2c) = *(undefined4 *)(uVar39 + 0x2c);
        *(undefined4 *)(uVar38 + 0x30) = *(undefined4 *)(uVar39 + 0x30);
        *(undefined4 *)(uVar38 + 0x34) = *(undefined4 *)(uVar39 + 0x34);
        *(undefined4 *)(uVar38 + 0x38) = *(undefined4 *)(uVar39 + 0x38);
        *(undefined4 *)(uVar38 + 0x3c) = *(undefined4 *)(uVar39 + 0x3c);
        *(undefined4 *)(uVar38 + 0x40) = *(undefined4 *)(uVar39 + 0x40);
        *(undefined4 *)(uVar39 + 4) = uVar22;
        *(undefined4 *)(uVar39 + 8) = uVar23;
        *(undefined4 *)(uVar39 + 0xc) = uVar24;
        *(undefined4 *)(uVar39 + 0x10) = uVar25;
        *(undefined4 *)(uVar39 + 0x14) = uVar26;
        *(undefined4 *)(uVar39 + 0x18) = uVar6;
        *(undefined4 *)(uVar39 + 0x1c) = uVar7;
        *(undefined4 *)(uVar39 + 0x2c) = uVar27;
        *(undefined4 *)(uVar39 + 0x20) = uVar8;
        *(undefined4 *)(uVar39 + 0x30) = uVar28;
        *(undefined4 *)(uVar39 + 0x34) = uVar29;
        *(undefined4 *)(uVar39 + 0x24) = uVar9;
        *(undefined4 *)(uVar39 + 0x38) = uVar30;
        *(undefined4 *)(uVar39 + 0x28) = uVar10;
        *(undefined4 *)(uVar39 + 0x3c) = uVar31;
        *(undefined4 *)(uVar39 + 0x40) = uVar32;
        uVar39 = uVar35;
        uVar33 = uVar33 + 0x44;
        uVar38 = uVar38 + 0x44;
      }
      else {
        uVar37 = uVar36 - 0x44;
        if (uVar39 == param_3) {
          if (uVar37 != uVar38 - 0x44) {
            uVar22 = *(undefined4 *)(uVar36 - 0x3c);
            uVar6 = *(undefined4 *)(uVar36 - 0x2c);
            uVar23 = *(undefined4 *)(uVar36 - 0x38);
            uVar7 = *(undefined4 *)(uVar36 - 0x28);
            uVar24 = *(undefined4 *)(uVar36 - 0x34);
            uVar8 = *(undefined4 *)(uVar36 - 0x24);
            uVar25 = *(undefined4 *)(uVar36 - 0x40);
            uVar9 = *(undefined4 *)(uVar36 - 0x20);
            uVar26 = *(undefined4 *)(uVar36 - 0x30);
            uVar10 = *(undefined4 *)(uVar36 - 0x1c);
            uVar27 = *(undefined4 *)(uVar36 - 0x18);
            uVar28 = *(undefined4 *)(uVar36 - 0x14);
            uVar29 = *(undefined4 *)(uVar36 - 0x10);
            uVar30 = *(undefined4 *)(uVar36 - 0xc);
            uVar31 = *(undefined4 *)(uVar36 - 8);
            uVar32 = *(undefined4 *)(uVar36 - 4);
            *(undefined4 *)(uVar36 - 0x40) = *(undefined4 *)(uVar38 - 0x40);
            *(undefined4 *)(uVar36 - 0x3c) = *(undefined4 *)(uVar38 - 0x3c);
            *(undefined4 *)(uVar36 - 0x38) = *(undefined4 *)(uVar38 - 0x38);
            *(undefined4 *)(uVar36 - 0x34) = *(undefined4 *)(uVar38 - 0x34);
            *(undefined4 *)(uVar36 - 0x30) = *(undefined4 *)(uVar38 - 0x30);
            *(undefined4 *)(uVar36 - 0x2c) = *(undefined4 *)(uVar38 - 0x2c);
            *(undefined4 *)(uVar36 - 0x28) = *(undefined4 *)(uVar38 - 0x28);
            *(undefined4 *)(uVar36 - 0x24) = *(undefined4 *)(uVar38 - 0x24);
            *(undefined4 *)(uVar36 - 0x20) = *(undefined4 *)(uVar38 - 0x20);
            *(undefined4 *)(uVar36 - 0x1c) = *(undefined4 *)(uVar38 - 0x1c);
            *(undefined4 *)(uVar36 - 0x18) = *(undefined4 *)(uVar38 - 0x18);
            *(undefined4 *)(uVar36 - 0x14) = *(undefined4 *)(uVar38 - 0x14);
            *(undefined4 *)(uVar36 - 0x10) = *(undefined4 *)(uVar38 - 0x10);
            *(undefined4 *)(uVar36 - 0xc) = *(undefined4 *)(uVar38 - 0xc);
            *(undefined4 *)(uVar36 - 8) = *(undefined4 *)(uVar38 - 8);
            *(undefined4 *)(uVar36 - 4) = *(undefined4 *)(uVar38 - 4);
            *(undefined4 *)(uVar38 - 0x2c) = uVar6;
            *(undefined4 *)(uVar38 - 0x28) = uVar7;
            *(undefined4 *)(uVar38 - 0x40) = uVar25;
            *(undefined4 *)(uVar38 - 0x24) = uVar8;
            *(undefined4 *)(uVar38 - 0x3c) = uVar22;
            *(undefined4 *)(uVar38 - 0x38) = uVar23;
            *(undefined4 *)(uVar38 - 0x20) = uVar9;
            *(undefined4 *)(uVar38 - 0x34) = uVar24;
            *(undefined4 *)(uVar38 - 0x30) = uVar26;
            *(undefined4 *)(uVar38 - 0x1c) = uVar10;
            *(undefined4 *)(uVar38 - 0x18) = uVar27;
            *(undefined4 *)(uVar38 - 0x14) = uVar28;
            *(undefined4 *)(uVar38 - 0xc) = uVar30;
            *(undefined4 *)(uVar38 - 0x10) = uVar29;
            *(undefined4 *)(uVar38 - 8) = uVar31;
            *(undefined4 *)(uVar38 - 4) = uVar32;
          }
          uVar22 = *(undefined4 *)(uVar38 - 0x3c);
          uVar6 = *(undefined4 *)(uVar38 - 0x2c);
          uVar23 = *(undefined4 *)(uVar38 - 0x38);
          uVar7 = *(undefined4 *)(uVar38 - 0x28);
          uVar24 = *(undefined4 *)(uVar38 - 0x34);
          uVar8 = *(undefined4 *)(uVar38 - 0x24);
          uVar25 = *(undefined4 *)(uVar38 - 0x40);
          uVar9 = *(undefined4 *)(uVar38 - 0x20);
          uVar26 = *(undefined4 *)(uVar38 - 0x30);
          uVar10 = *(undefined4 *)(uVar38 - 0x1c);
          uVar27 = *(undefined4 *)(uVar38 - 0x18);
          uVar28 = *(undefined4 *)(uVar38 - 0x14);
          uVar29 = *(undefined4 *)(uVar38 - 0x10);
          uVar30 = *(undefined4 *)(uVar38 - 0xc);
          uVar31 = *(undefined4 *)(uVar38 - 8);
          uVar32 = *(undefined4 *)(uVar38 - 4);
          *(undefined4 *)(uVar38 - 0x40) = *(undefined4 *)(uVar33 - 0x40);
          *(undefined4 *)(uVar38 - 0x3c) = *(undefined4 *)(uVar33 - 0x3c);
          *(undefined4 *)(uVar38 - 0x38) = *(undefined4 *)(uVar33 - 0x38);
          *(undefined4 *)(uVar38 - 0x34) = *(undefined4 *)(uVar33 - 0x34);
          *(undefined4 *)(uVar38 - 0x30) = *(undefined4 *)(uVar33 - 0x30);
          *(undefined4 *)(uVar38 - 0x2c) = *(undefined4 *)(uVar33 - 0x2c);
          *(undefined4 *)(uVar38 - 0x28) = *(undefined4 *)(uVar33 - 0x28);
          *(undefined4 *)(uVar38 - 0x24) = *(undefined4 *)(uVar33 - 0x24);
          *(undefined4 *)(uVar38 - 0x20) = *(undefined4 *)(uVar33 - 0x20);
          *(undefined4 *)(uVar38 - 0x1c) = *(undefined4 *)(uVar33 - 0x1c);
          *(undefined4 *)(uVar38 - 0x18) = *(undefined4 *)(uVar33 - 0x18);
          *(undefined4 *)(uVar38 - 0x14) = *(undefined4 *)(uVar33 - 0x14);
          *(undefined4 *)(uVar38 - 0x10) = *(undefined4 *)(uVar33 - 0x10);
          *(undefined4 *)(uVar38 - 0xc) = *(undefined4 *)(uVar33 - 0xc);
          *(undefined4 *)(uVar38 - 8) = *(undefined4 *)(uVar33 - 8);
          *(undefined4 *)(uVar38 - 4) = *(undefined4 *)(uVar33 - 4);
          *(undefined4 *)(uVar33 - 0x2c) = uVar6;
          *(undefined4 *)(uVar33 - 0x40) = uVar25;
          *(undefined4 *)(uVar33 - 0x28) = uVar7;
          *(undefined4 *)(uVar33 - 0x3c) = uVar22;
          *(undefined4 *)(uVar33 - 0x24) = uVar8;
          *(undefined4 *)(uVar33 - 0x38) = uVar23;
          *(undefined4 *)(uVar33 - 0x20) = uVar9;
          *(undefined4 *)(uVar33 - 0x34) = uVar24;
          *(undefined4 *)(uVar33 - 0x30) = uVar26;
          *(undefined4 *)(uVar33 - 0x1c) = uVar10;
          *(undefined4 *)(uVar33 - 0x18) = uVar27;
          *(undefined4 *)(uVar33 - 0x14) = uVar28;
          *(undefined4 *)(uVar33 - 0xc) = uVar30;
          *(undefined4 *)(uVar33 - 0x10) = uVar29;
          *(undefined4 *)(uVar33 - 8) = uVar31;
          *(undefined4 *)(uVar33 - 4) = uVar32;
          uVar33 = uVar33 - 0x44;
          uVar38 = uVar38 - 0x44;
          uVar36 = uVar37;
        }
        else {
          uVar22 = *(undefined4 *)(uVar39 + 8);
          uVar6 = *(undefined4 *)(uVar39 + 0x18);
          uVar23 = *(undefined4 *)(uVar39 + 0xc);
          uVar7 = *(undefined4 *)(uVar39 + 0x1c);
          uVar24 = *(undefined4 *)(uVar39 + 0x10);
          uVar8 = *(undefined4 *)(uVar39 + 0x20);
          uVar25 = *(undefined4 *)(uVar39 + 4);
          uVar9 = *(undefined4 *)(uVar39 + 0x24);
          uVar26 = *(undefined4 *)(uVar39 + 0x14);
          uVar10 = *(undefined4 *)(uVar39 + 0x28);
          uVar27 = *(undefined4 *)(uVar39 + 0x2c);
          uVar28 = *(undefined4 *)(uVar39 + 0x30);
          uVar29 = *(undefined4 *)(uVar39 + 0x34);
          uVar30 = *(undefined4 *)(uVar39 + 0x38);
          uVar31 = *(undefined4 *)(uVar39 + 0x3c);
          uVar32 = *(undefined4 *)(uVar39 + 0x40);
          *(undefined4 *)(uVar39 + 4) = *(undefined4 *)(uVar36 - 0x40);
          *(undefined4 *)(uVar39 + 8) = *(undefined4 *)(uVar36 - 0x3c);
          *(undefined4 *)(uVar39 + 0xc) = *(undefined4 *)(uVar36 - 0x38);
          *(undefined4 *)(uVar39 + 0x10) = *(undefined4 *)(uVar36 - 0x34);
          *(undefined4 *)(uVar39 + 0x14) = *(undefined4 *)(uVar36 - 0x30);
          *(undefined4 *)(uVar39 + 0x18) = *(undefined4 *)(uVar36 - 0x2c);
          *(undefined4 *)(uVar39 + 0x1c) = *(undefined4 *)(uVar36 - 0x28);
          *(undefined4 *)(uVar39 + 0x20) = *(undefined4 *)(uVar36 - 0x24);
          *(undefined4 *)(uVar39 + 0x24) = *(undefined4 *)(uVar36 - 0x20);
          *(undefined4 *)(uVar39 + 0x28) = *(undefined4 *)(uVar36 - 0x1c);
          *(undefined4 *)(uVar39 + 0x2c) = *(undefined4 *)(uVar36 - 0x18);
          *(undefined4 *)(uVar39 + 0x30) = *(undefined4 *)(uVar36 - 0x14);
          *(undefined4 *)(uVar39 + 0x34) = *(undefined4 *)(uVar36 - 0x10);
          *(undefined4 *)(uVar39 + 0x38) = *(undefined4 *)(uVar36 - 0xc);
          *(undefined4 *)(uVar39 + 0x3c) = *(undefined4 *)(uVar36 - 8);
          *(undefined4 *)(uVar39 + 0x40) = *(undefined4 *)(uVar36 - 4);
          *(undefined4 *)(uVar36 - 0x2c) = uVar6;
          *(undefined4 *)(uVar36 - 0x28) = uVar7;
          *(undefined4 *)(uVar36 - 0x40) = uVar25;
          *(undefined4 *)(uVar36 - 0x24) = uVar8;
          *(undefined4 *)(uVar36 - 0x3c) = uVar22;
          *(undefined4 *)(uVar36 - 0x38) = uVar23;
          *(undefined4 *)(uVar36 - 0x20) = uVar9;
          *(undefined4 *)(uVar36 - 0x34) = uVar24;
          *(undefined4 *)(uVar36 - 0x30) = uVar26;
          *(undefined4 *)(uVar36 - 0x1c) = uVar10;
          *(undefined4 *)(uVar36 - 0x18) = uVar27;
          *(undefined4 *)(uVar36 - 0x14) = uVar28;
          *(undefined4 *)(uVar36 - 0xc) = uVar30;
          *(undefined4 *)(uVar36 - 0x10) = uVar29;
          *(undefined4 *)(uVar36 - 8) = uVar31;
          *(undefined4 *)(uVar36 - 4) = uVar32;
          uVar39 = uVar39 + 0x44;
          uVar35 = uVar39;
          uVar36 = uVar37;
        }
      }
      goto joined_r0x0078c40a;
    }
    uVar37 = uVar39;
    uVar40 = uVar33;
    if (*(int *)(uVar39 + 0x10) <= *(int *)(uVar38 + 0x10)) {
      if (*(int *)(uVar39 + 0x10) < *(int *)(uVar38 + 0x10)) goto LAB_0078c53e;
      uVar40 = uVar33 + 0x44;
      FUN_00786620();
      *(undefined4 *)(uVar33 + 4) = *(undefined4 *)(uVar35 + 4);
      *(undefined4 *)(uVar33 + 8) = *(undefined4 *)(uVar35 + 8);
      *(undefined4 *)(uVar33 + 0xc) = *(undefined4 *)(uVar35 + 0xc);
      *(undefined4 *)(uVar33 + 0x10) = *(undefined4 *)(uVar35 + 0x10);
      *(undefined4 *)(uVar33 + 0x14) = *(undefined4 *)(uVar35 + 0x14);
      *(undefined4 *)(uVar33 + 0x18) = *(undefined4 *)(uVar35 + 0x18);
      *(undefined4 *)(uVar33 + 0x1c) = *(undefined4 *)(uVar35 + 0x1c);
      *(undefined4 *)(uVar33 + 0x20) = *(undefined4 *)(uVar35 + 0x20);
      *(undefined4 *)(uVar33 + 0x24) = *(undefined4 *)(uVar35 + 0x24);
      *(undefined4 *)(uVar33 + 0x28) = *(undefined4 *)(uVar35 + 0x28);
      *(undefined4 *)(uVar33 + 0x2c) = *(undefined4 *)(uVar35 + 0x2c);
      *(undefined4 *)(uVar33 + 0x30) = *(undefined4 *)(uVar35 + 0x30);
      *(undefined4 *)(uVar33 + 0x34) = *(undefined4 *)(uVar35 + 0x34);
      *(undefined4 *)(uVar33 + 0x38) = *(undefined4 *)(uVar35 + 0x38);
      *(undefined4 *)(uVar33 + 0x3c) = *(undefined4 *)(uVar35 + 0x3c);
      *(undefined4 *)(uVar33 + 0x40) = *(undefined4 *)(uVar35 + 0x40);
      *(undefined4 *)(uVar35 + 0x18) = local_1d0;
      *(undefined4 *)(uVar35 + 0x1c) = local_1cc;
      *(undefined4 *)(uVar35 + 4) = local_1e4;
      *(undefined4 *)(uVar35 + 0x20) = local_1c8;
      *(undefined4 *)(uVar35 + 8) = local_1e0;
      *(undefined4 *)(uVar35 + 0x24) = local_1c4;
      *(undefined4 *)(uVar35 + 0xc) = local_1dc;
      *(undefined4 *)(uVar35 + 0x28) = local_1c0;
      *(undefined4 *)(uVar35 + 0x10) = local_1d8;
      *(undefined4 *)(uVar35 + 0x14) = local_1d4;
      *(undefined4 *)(uVar35 + 0x2c) = local_1bc;
      *(undefined4 *)(uVar35 + 0x30) = local_1b8;
      *(undefined4 *)(uVar35 + 0x34) = local_1b4;
      *(undefined4 *)(uVar35 + 0x38) = local_1b0;
      *(undefined4 *)(uVar35 + 0x3c) = local_1ac;
      *(undefined4 *)(uVar35 + 0x40) = local_1a8;
      uVar37 = uVar35;
    }
    uVar39 = uVar37 + 0x44;
    uVar33 = uVar40;
    uVar35 = uVar37 + 0x44;
  } while( true );
}

