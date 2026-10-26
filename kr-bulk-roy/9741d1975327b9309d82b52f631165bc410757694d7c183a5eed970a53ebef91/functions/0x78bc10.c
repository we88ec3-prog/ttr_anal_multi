
void FUN_0078bc10(uint *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint local_20;
  
  uVar13 = param_2 + ((int)(param_3 - param_2) / 0x30) * 0x18;
  FUN_0078e220(uVar13,param_3 - 0x18,param_4);
  uVar14 = uVar13 + 0x18;
  for (; param_2 < uVar13; uVar13 = uVar13 - 0x18) {
    if ((*(int *)(uVar13 - 8) < *(int *)(uVar13 + 0x10)) ||
       (*(int *)(uVar13 + 0x10) < *(int *)(uVar13 - 8))) break;
  }
  uVar15 = uVar14;
  local_20 = uVar13;
  if (uVar14 < param_3) {
    do {
      uVar15 = uVar14;
      if ((*(int *)(uVar14 + 0x10) < *(int *)(uVar13 + 0x10)) ||
         (*(int *)(uVar13 + 0x10) < *(int *)(uVar14 + 0x10))) break;
      uVar14 = uVar14 + 0x18;
      uVar15 = uVar14;
    } while (uVar14 < param_3);
  }
  do {
    if (uVar14 < param_3) {
      if (3 < (int)((param_3 - uVar14) + 0x17) / 0x18) {
        do {
          if (*(int *)(uVar14 + 0x10) <= *(int *)(uVar13 + 0x10)) {
            if (*(int *)(uVar14 + 0x10) < *(int *)(uVar13 + 0x10)) goto LAB_0078bf28;
            uVar1 = *(undefined4 *)(uVar15 + 4);
            uVar2 = *(undefined4 *)(uVar15 + 8);
            uVar3 = *(undefined4 *)(uVar15 + 0xc);
            uVar4 = *(undefined4 *)(uVar15 + 0x10);
            uVar5 = *(undefined4 *)(uVar15 + 0x14);
            *(undefined4 *)(uVar15 + 4) = *(undefined4 *)(uVar14 + 4);
            *(undefined4 *)(uVar15 + 8) = *(undefined4 *)(uVar14 + 8);
            *(undefined4 *)(uVar15 + 0xc) = *(undefined4 *)(uVar14 + 0xc);
            *(undefined4 *)(uVar15 + 0x10) = *(undefined4 *)(uVar14 + 0x10);
            *(undefined4 *)(uVar15 + 0x14) = *(undefined4 *)(uVar14 + 0x14);
            *(undefined4 *)(uVar14 + 4) = uVar1;
            *(undefined4 *)(uVar14 + 8) = uVar2;
            *(undefined4 *)(uVar14 + 0xc) = uVar3;
            uVar15 = uVar15 + 0x18;
            *(undefined4 *)(uVar14 + 0x10) = uVar4;
            *(undefined4 *)(uVar14 + 0x14) = uVar5;
          }
          if (*(int *)(uVar14 + 0x28) <= *(int *)(uVar13 + 0x10)) {
            if (*(int *)(uVar14 + 0x28) < *(int *)(uVar13 + 0x10)) {
              uVar14 = uVar14 + 0x18;
              goto LAB_0078bf28;
            }
            uVar1 = *(undefined4 *)(uVar15 + 4);
            uVar2 = *(undefined4 *)(uVar15 + 8);
            uVar3 = *(undefined4 *)(uVar15 + 0xc);
            uVar4 = *(undefined4 *)(uVar15 + 0x10);
            uVar5 = *(undefined4 *)(uVar15 + 0x14);
            *(undefined4 *)(uVar15 + 4) = *(undefined4 *)(uVar14 + 0x1c);
            *(undefined4 *)(uVar15 + 8) = *(undefined4 *)(uVar14 + 0x20);
            *(undefined4 *)(uVar15 + 0xc) = *(undefined4 *)(uVar14 + 0x24);
            *(undefined4 *)(uVar15 + 0x10) = *(undefined4 *)(uVar14 + 0x28);
            *(undefined4 *)(uVar15 + 0x14) = *(undefined4 *)(uVar14 + 0x2c);
            *(undefined4 *)(uVar14 + 0x1c) = uVar1;
            *(undefined4 *)(uVar14 + 0x20) = uVar2;
            *(undefined4 *)(uVar14 + 0x24) = uVar3;
            uVar15 = uVar15 + 0x18;
            *(undefined4 *)(uVar14 + 0x28) = uVar4;
            *(undefined4 *)(uVar14 + 0x2c) = uVar5;
          }
          if (*(int *)(uVar14 + 0x40) <= *(int *)(uVar13 + 0x10)) {
            if (*(int *)(uVar14 + 0x40) < *(int *)(uVar13 + 0x10)) {
              uVar14 = uVar14 + 0x30;
              goto LAB_0078bf28;
            }
            uVar1 = *(undefined4 *)(uVar15 + 4);
            uVar2 = *(undefined4 *)(uVar15 + 8);
            uVar3 = *(undefined4 *)(uVar15 + 0xc);
            uVar4 = *(undefined4 *)(uVar15 + 0x10);
            uVar5 = *(undefined4 *)(uVar15 + 0x14);
            *(undefined4 *)(uVar15 + 4) = *(undefined4 *)(uVar14 + 0x34);
            *(undefined4 *)(uVar15 + 8) = *(undefined4 *)(uVar14 + 0x38);
            *(undefined4 *)(uVar15 + 0xc) = *(undefined4 *)(uVar14 + 0x3c);
            *(undefined4 *)(uVar15 + 0x10) = *(undefined4 *)(uVar14 + 0x40);
            *(undefined4 *)(uVar15 + 0x14) = *(undefined4 *)(uVar14 + 0x44);
            *(undefined4 *)(uVar14 + 0x34) = uVar1;
            *(undefined4 *)(uVar14 + 0x38) = uVar2;
            *(undefined4 *)(uVar14 + 0x3c) = uVar3;
            uVar15 = uVar15 + 0x18;
            *(undefined4 *)(uVar14 + 0x40) = uVar4;
            *(undefined4 *)(uVar14 + 0x44) = uVar5;
          }
          if (*(int *)(uVar14 + 0x58) <= *(int *)(uVar13 + 0x10)) {
            if (*(int *)(uVar14 + 0x58) < *(int *)(uVar13 + 0x10)) {
              uVar14 = uVar14 + 0x48;
              goto LAB_0078bf28;
            }
            uVar1 = *(undefined4 *)(uVar15 + 4);
            uVar2 = *(undefined4 *)(uVar15 + 8);
            uVar3 = *(undefined4 *)(uVar15 + 0xc);
            uVar4 = *(undefined4 *)(uVar15 + 0x10);
            uVar5 = *(undefined4 *)(uVar15 + 0x14);
            *(undefined4 *)(uVar15 + 4) = *(undefined4 *)(uVar14 + 0x4c);
            *(undefined4 *)(uVar15 + 8) = *(undefined4 *)(uVar14 + 0x50);
            *(undefined4 *)(uVar15 + 0xc) = *(undefined4 *)(uVar14 + 0x54);
            *(undefined4 *)(uVar15 + 0x10) = *(undefined4 *)(uVar14 + 0x58);
            *(undefined4 *)(uVar15 + 0x14) = *(undefined4 *)(uVar14 + 0x5c);
            *(undefined4 *)(uVar14 + 0x4c) = uVar1;
            *(undefined4 *)(uVar14 + 0x50) = uVar2;
            *(undefined4 *)(uVar14 + 0x54) = uVar3;
            uVar15 = uVar15 + 0x18;
            *(undefined4 *)(uVar14 + 0x58) = uVar4;
            *(undefined4 *)(uVar14 + 0x5c) = uVar5;
          }
          uVar14 = uVar14 + 0x60;
        } while ((int)uVar14 < (int)(param_3 - 0x48));
      }
      for (; uVar14 < param_3; uVar14 = uVar14 + 0x18) {
        if (*(int *)(uVar14 + 0x10) <= *(int *)(uVar13 + 0x10)) {
          if (*(int *)(uVar14 + 0x10) < *(int *)(uVar13 + 0x10)) break;
          uVar1 = *(undefined4 *)(uVar15 + 4);
          uVar2 = *(undefined4 *)(uVar15 + 8);
          uVar3 = *(undefined4 *)(uVar15 + 0xc);
          uVar4 = *(undefined4 *)(uVar15 + 0x10);
          uVar5 = *(undefined4 *)(uVar15 + 0x14);
          *(undefined4 *)(uVar15 + 4) = *(undefined4 *)(uVar14 + 4);
          *(undefined4 *)(uVar15 + 8) = *(undefined4 *)(uVar14 + 8);
          *(undefined4 *)(uVar15 + 0xc) = *(undefined4 *)(uVar14 + 0xc);
          *(undefined4 *)(uVar15 + 0x10) = *(undefined4 *)(uVar14 + 0x10);
          *(undefined4 *)(uVar15 + 0x14) = *(undefined4 *)(uVar14 + 0x14);
          *(undefined4 *)(uVar14 + 4) = uVar1;
          *(undefined4 *)(uVar14 + 8) = uVar2;
          *(undefined4 *)(uVar14 + 0xc) = uVar3;
          uVar15 = uVar15 + 0x18;
          *(undefined4 *)(uVar14 + 0x10) = uVar4;
          *(undefined4 *)(uVar14 + 0x14) = uVar5;
        }
      }
    }
LAB_0078bf28:
    if (param_2 < local_20) {
      piVar11 = (int *)(local_20 - 8);
      uVar12 = uVar13;
      do {
        uVar13 = uVar12;
        if (*(int *)(uVar12 + 0x10) <= *piVar11) {
          if (*(int *)(uVar12 + 0x10) < *piVar11) break;
          iVar6 = *(int *)(uVar12 - 0x10);
          iVar7 = *(int *)(uVar12 - 0x14);
          uVar13 = uVar12 - 0x18;
          iVar8 = *(int *)(uVar12 - 0xc);
          iVar9 = *(int *)(uVar12 - 8);
          iVar10 = *(int *)(uVar12 - 4);
          *(int *)(uVar12 - 0x14) = piVar11[-3];
          *(int *)(uVar12 - 0x10) = piVar11[-2];
          *(int *)(uVar12 - 0xc) = piVar11[-1];
          *(int *)(uVar12 - 8) = *piVar11;
          *(int *)(uVar12 - 4) = piVar11[1];
          piVar11[-3] = iVar7;
          piVar11[-2] = iVar6;
          piVar11[-1] = iVar8;
          *piVar11 = iVar9;
          piVar11[1] = iVar10;
        }
        local_20 = local_20 - 0x18;
        piVar11 = piVar11 + -6;
        uVar12 = uVar13;
      } while (param_2 < local_20);
    }
    if (local_20 == param_2) {
      if (uVar14 == param_3) {
        param_1[1] = uVar15;
        *param_1 = uVar13;
        return;
      }
      if (uVar15 != uVar14) {
        uVar1 = *(undefined4 *)(uVar13 + 0xc);
        uVar2 = *(undefined4 *)(uVar13 + 4);
        uVar3 = *(undefined4 *)(uVar13 + 8);
        uVar4 = *(undefined4 *)(uVar13 + 0x10);
        uVar5 = *(undefined4 *)(uVar13 + 0x14);
        *(undefined4 *)(uVar13 + 4) = *(undefined4 *)(uVar15 + 4);
        *(undefined4 *)(uVar13 + 8) = *(undefined4 *)(uVar15 + 8);
        *(undefined4 *)(uVar13 + 0xc) = *(undefined4 *)(uVar15 + 0xc);
        *(undefined4 *)(uVar13 + 0x10) = *(undefined4 *)(uVar15 + 0x10);
        *(undefined4 *)(uVar13 + 0x14) = *(undefined4 *)(uVar15 + 0x14);
        *(undefined4 *)(uVar15 + 4) = uVar2;
        *(undefined4 *)(uVar15 + 8) = uVar3;
        *(undefined4 *)(uVar15 + 0xc) = uVar1;
        *(undefined4 *)(uVar15 + 0x10) = uVar4;
        *(undefined4 *)(uVar15 + 0x14) = uVar5;
      }
      uVar1 = *(undefined4 *)(uVar13 + 4);
      uVar2 = *(undefined4 *)(uVar13 + 8);
      uVar3 = *(undefined4 *)(uVar13 + 0xc);
      uVar4 = *(undefined4 *)(uVar13 + 0x10);
      uVar5 = *(undefined4 *)(uVar13 + 0x14);
      *(undefined4 *)(uVar13 + 4) = *(undefined4 *)(uVar14 + 4);
      *(undefined4 *)(uVar13 + 8) = *(undefined4 *)(uVar14 + 8);
      *(undefined4 *)(uVar13 + 0xc) = *(undefined4 *)(uVar14 + 0xc);
      *(undefined4 *)(uVar13 + 0x10) = *(undefined4 *)(uVar14 + 0x10);
      *(undefined4 *)(uVar13 + 0x14) = *(undefined4 *)(uVar14 + 0x14);
      *(undefined4 *)(uVar14 + 4) = uVar1;
      *(undefined4 *)(uVar14 + 8) = uVar2;
      *(undefined4 *)(uVar14 + 0xc) = uVar3;
      *(undefined4 *)(uVar14 + 0x10) = uVar4;
      *(undefined4 *)(uVar14 + 0x14) = uVar5;
      uVar14 = uVar14 + 0x18;
      uVar13 = uVar13 + 0x18;
      uVar15 = uVar15 + 0x18;
    }
    else {
      uVar12 = local_20 - 0x18;
      if (uVar14 == param_3) {
        if (uVar12 != uVar13 - 0x18) {
          uVar1 = *(undefined4 *)(local_20 - 0x10);
          uVar2 = *(undefined4 *)(local_20 - 0x14);
          uVar3 = *(undefined4 *)(local_20 - 0xc);
          uVar4 = *(undefined4 *)(local_20 - 8);
          uVar5 = *(undefined4 *)(local_20 - 4);
          *(undefined4 *)(local_20 - 0x14) = *(undefined4 *)(uVar13 - 0x14);
          *(undefined4 *)(local_20 - 0x10) = *(undefined4 *)(uVar13 - 0x10);
          *(undefined4 *)(local_20 - 0xc) = *(undefined4 *)(uVar13 - 0xc);
          *(undefined4 *)(local_20 - 8) = *(undefined4 *)(uVar13 - 8);
          *(undefined4 *)(local_20 - 4) = *(undefined4 *)(uVar13 - 4);
          *(undefined4 *)(uVar13 - 0x14) = uVar2;
          *(undefined4 *)(uVar13 - 0x10) = uVar1;
          *(undefined4 *)(uVar13 - 0xc) = uVar3;
          *(undefined4 *)(uVar13 - 8) = uVar4;
          *(undefined4 *)(uVar13 - 4) = uVar5;
        }
        uVar1 = *(undefined4 *)(uVar13 - 0x10);
        uVar2 = *(undefined4 *)(uVar13 - 0x14);
        uVar3 = *(undefined4 *)(uVar13 - 0xc);
        uVar4 = *(undefined4 *)(uVar13 - 8);
        uVar5 = *(undefined4 *)(uVar13 - 4);
        *(undefined4 *)(uVar13 - 0x14) = *(undefined4 *)(uVar15 - 0x14);
        *(undefined4 *)(uVar13 - 0x10) = *(undefined4 *)(uVar15 - 0x10);
        *(undefined4 *)(uVar13 - 0xc) = *(undefined4 *)(uVar15 - 0xc);
        *(undefined4 *)(uVar13 - 8) = *(undefined4 *)(uVar15 - 8);
        *(undefined4 *)(uVar13 - 4) = *(undefined4 *)(uVar15 - 4);
        *(undefined4 *)(uVar15 - 0x14) = uVar2;
        *(undefined4 *)(uVar15 - 0x10) = uVar1;
        *(undefined4 *)(uVar15 - 0xc) = uVar3;
        *(undefined4 *)(uVar15 - 8) = uVar4;
        *(undefined4 *)(uVar15 - 4) = uVar5;
        uVar13 = uVar13 - 0x18;
        uVar15 = uVar15 - 0x18;
        local_20 = uVar12;
      }
      else {
        uVar1 = *(undefined4 *)(uVar14 + 8);
        uVar2 = *(undefined4 *)(uVar14 + 4);
        uVar3 = *(undefined4 *)(uVar14 + 0xc);
        uVar4 = *(undefined4 *)(uVar14 + 0x10);
        uVar5 = *(undefined4 *)(uVar14 + 0x14);
        *(undefined4 *)(uVar14 + 4) = *(undefined4 *)(local_20 - 0x14);
        *(undefined4 *)(uVar14 + 8) = *(undefined4 *)(local_20 - 0x10);
        *(undefined4 *)(uVar14 + 0xc) = *(undefined4 *)(local_20 - 0xc);
        *(undefined4 *)(uVar14 + 0x10) = *(undefined4 *)(local_20 - 8);
        *(undefined4 *)(uVar14 + 0x14) = *(undefined4 *)(local_20 - 4);
        *(undefined4 *)(local_20 - 0x14) = uVar2;
        *(undefined4 *)(local_20 - 0x10) = uVar1;
        *(undefined4 *)(local_20 - 0xc) = uVar3;
        *(undefined4 *)(local_20 - 8) = uVar4;
        *(undefined4 *)(local_20 - 4) = uVar5;
        uVar14 = uVar14 + 0x18;
        local_20 = uVar12;
      }
    }
  } while( true );
}

