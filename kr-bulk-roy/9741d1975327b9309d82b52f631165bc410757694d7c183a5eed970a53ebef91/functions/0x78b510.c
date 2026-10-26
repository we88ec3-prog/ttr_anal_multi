
void FUN_0078b510(uint *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint local_8;
  
  uVar10 = param_2 + ((int)(param_3 - param_2) / 0x30) * 0x18;
  FUN_0078da80(uVar10,param_3 - 0x18,param_4);
  uVar11 = uVar10 + 0x18;
  for (; param_2 < uVar10; uVar10 = uVar10 - 0x18) {
    if ((*(int *)(uVar10 - 0x10) < *(int *)(uVar10 + 8)) ||
       (*(int *)(uVar10 + 8) < *(int *)(uVar10 - 0x10))) break;
  }
  uVar14 = uVar11;
  local_8 = uVar10;
  if (uVar11 < param_3) {
    do {
      uVar14 = uVar11;
      if ((*(int *)(uVar11 + 8) < *(int *)(uVar10 + 8)) ||
         (*(int *)(uVar10 + 8) < *(int *)(uVar11 + 8))) break;
      uVar11 = uVar11 + 0x18;
      uVar14 = uVar11;
    } while (uVar11 < param_3);
  }
  do {
    uVar12 = uVar14;
    if (uVar11 < param_3) {
      if (3 < (int)((param_3 - uVar11) + 0x17) / 0x18) {
        do {
          uVar12 = uVar14;
          if (*(int *)(uVar11 + 8) <= *(int *)(uVar10 + 8)) {
            if (*(int *)(uVar11 + 8) < *(int *)(uVar10 + 8)) goto LAB_0078b80f;
            uVar1 = *(undefined4 *)(uVar14 + 4);
            uVar7 = *(undefined4 *)(uVar14 + 8);
            uVar2 = *(undefined4 *)(uVar14 + 0x10);
            uVar12 = uVar14 + 0x18;
            uVar3 = *(undefined4 *)(uVar14 + 0x14);
            *(undefined4 *)(uVar14 + 4) = *(undefined4 *)(uVar11 + 4);
            *(undefined4 *)(uVar14 + 8) = *(undefined4 *)(uVar11 + 8);
            *(undefined4 *)(uVar14 + 0xc) = *(undefined4 *)(uVar11 + 0xc);
            *(undefined4 *)(uVar14 + 0x10) = *(undefined4 *)(uVar11 + 0x10);
            *(undefined4 *)(uVar14 + 0x14) = *(undefined4 *)(uVar11 + 0x14);
            *(undefined4 *)(uVar11 + 8) = uVar7;
            *(undefined4 *)(uVar11 + 4) = uVar1;
            *(undefined4 *)(uVar11 + 0xc) = 0;
            *(undefined4 *)(uVar11 + 0x10) = uVar2;
            *(undefined4 *)(uVar11 + 0x14) = uVar3;
          }
          if (*(int *)(uVar11 + 0x20) <= *(int *)(uVar10 + 8)) {
            if (*(int *)(uVar11 + 0x20) < *(int *)(uVar10 + 8)) {
              uVar11 = uVar11 + 0x18;
              goto LAB_0078b80f;
            }
            uVar1 = *(undefined4 *)(uVar12 + 4);
            uVar7 = *(undefined4 *)(uVar12 + 8);
            uVar2 = *(undefined4 *)(uVar12 + 0x10);
            uVar3 = *(undefined4 *)(uVar12 + 0x14);
            *(undefined4 *)(uVar12 + 4) = *(undefined4 *)(uVar11 + 0x1c);
            *(undefined4 *)(uVar12 + 8) = *(undefined4 *)(uVar11 + 0x20);
            *(undefined4 *)(uVar12 + 0xc) = *(undefined4 *)(uVar11 + 0x24);
            *(undefined4 *)(uVar12 + 0x10) = *(undefined4 *)(uVar11 + 0x28);
            *(undefined4 *)(uVar12 + 0x14) = *(undefined4 *)(uVar11 + 0x2c);
            *(undefined4 *)(uVar11 + 0x20) = uVar7;
            *(undefined4 *)(uVar11 + 0x1c) = uVar1;
            *(undefined4 *)(uVar11 + 0x24) = 0;
            *(undefined4 *)(uVar11 + 0x28) = uVar2;
            *(undefined4 *)(uVar11 + 0x2c) = uVar3;
            uVar12 = uVar12 + 0x18;
          }
          uVar13 = uVar12;
          if (*(int *)(uVar11 + 0x38) <= *(int *)(uVar10 + 8)) {
            if (*(int *)(uVar11 + 0x38) < *(int *)(uVar10 + 8)) {
              uVar11 = uVar11 + 0x30;
              goto LAB_0078b80f;
            }
            uVar1 = *(undefined4 *)(uVar12 + 4);
            uVar7 = *(undefined4 *)(uVar12 + 8);
            uVar2 = *(undefined4 *)(uVar12 + 0x10);
            uVar13 = uVar12 + 0x18;
            uVar3 = *(undefined4 *)(uVar12 + 0x14);
            *(undefined4 *)(uVar12 + 4) = *(undefined4 *)(uVar11 + 0x34);
            *(undefined4 *)(uVar12 + 8) = *(undefined4 *)(uVar11 + 0x38);
            *(undefined4 *)(uVar12 + 0xc) = *(undefined4 *)(uVar11 + 0x3c);
            *(undefined4 *)(uVar12 + 0x10) = *(undefined4 *)(uVar11 + 0x40);
            *(undefined4 *)(uVar12 + 0x14) = *(undefined4 *)(uVar11 + 0x44);
            *(undefined4 *)(uVar11 + 0x38) = uVar7;
            *(undefined4 *)(uVar11 + 0x34) = uVar1;
            *(undefined4 *)(uVar11 + 0x3c) = 0;
            *(undefined4 *)(uVar11 + 0x40) = uVar2;
            *(undefined4 *)(uVar11 + 0x44) = uVar3;
          }
          uVar14 = uVar13;
          if (*(int *)(uVar11 + 0x50) <= *(int *)(uVar10 + 8)) {
            if (*(int *)(uVar11 + 0x50) < *(int *)(uVar10 + 8)) {
              uVar11 = uVar11 + 0x48;
              uVar12 = uVar13;
              goto LAB_0078b80f;
            }
            uVar1 = *(undefined4 *)(uVar13 + 4);
            uVar7 = *(undefined4 *)(uVar13 + 8);
            uVar2 = *(undefined4 *)(uVar13 + 0x10);
            uVar14 = uVar13 + 0x18;
            uVar3 = *(undefined4 *)(uVar13 + 0x14);
            *(undefined4 *)(uVar13 + 4) = *(undefined4 *)(uVar11 + 0x4c);
            *(undefined4 *)(uVar13 + 8) = *(undefined4 *)(uVar11 + 0x50);
            *(undefined4 *)(uVar13 + 0xc) = *(undefined4 *)(uVar11 + 0x54);
            *(undefined4 *)(uVar13 + 0x10) = *(undefined4 *)(uVar11 + 0x58);
            *(undefined4 *)(uVar13 + 0x14) = *(undefined4 *)(uVar11 + 0x5c);
            *(undefined4 *)(uVar11 + 0x50) = uVar7;
            *(undefined4 *)(uVar11 + 0x4c) = uVar1;
            *(undefined4 *)(uVar11 + 0x54) = 0;
            *(undefined4 *)(uVar11 + 0x58) = uVar2;
            *(undefined4 *)(uVar11 + 0x5c) = uVar3;
          }
          uVar11 = uVar11 + 0x60;
        } while ((int)uVar11 < (int)(param_3 - 0x48));
      }
      for (; uVar12 = uVar14, uVar11 < param_3; uVar11 = uVar11 + 0x18) {
        if (*(int *)(uVar11 + 8) <= *(int *)(uVar10 + 8)) {
          if (*(int *)(uVar11 + 8) < *(int *)(uVar10 + 8)) break;
          uVar1 = *(undefined4 *)(uVar14 + 4);
          uVar7 = *(undefined4 *)(uVar14 + 8);
          uVar2 = *(undefined4 *)(uVar14 + 0x10);
          uVar12 = uVar14 + 0x18;
          uVar3 = *(undefined4 *)(uVar14 + 0x14);
          *(undefined4 *)(uVar14 + 4) = *(undefined4 *)(uVar11 + 4);
          *(undefined4 *)(uVar14 + 8) = *(undefined4 *)(uVar11 + 8);
          *(undefined4 *)(uVar14 + 0xc) = *(undefined4 *)(uVar11 + 0xc);
          *(undefined4 *)(uVar14 + 0x10) = *(undefined4 *)(uVar11 + 0x10);
          *(undefined4 *)(uVar14 + 0x14) = *(undefined4 *)(uVar11 + 0x14);
          *(undefined4 *)(uVar11 + 8) = uVar7;
          *(undefined4 *)(uVar11 + 4) = uVar1;
          *(undefined4 *)(uVar11 + 0xc) = 0;
          *(undefined4 *)(uVar11 + 0x10) = uVar2;
          *(undefined4 *)(uVar11 + 0x14) = uVar3;
        }
        uVar14 = uVar12;
      }
    }
LAB_0078b80f:
    if (param_2 < local_8) {
      piVar9 = (int *)(local_8 - 0x10);
      uVar14 = uVar10;
      do {
        uVar10 = uVar14;
        if (*(int *)(uVar14 + 8) <= *piVar9) {
          if (*(int *)(uVar14 + 8) < *piVar9) break;
          iVar4 = *(int *)(uVar14 - 0x14);
          iVar8 = *(int *)(uVar14 - 0x10);
          uVar10 = uVar14 - 0x18;
          iVar5 = *(int *)(uVar14 - 8);
          iVar6 = *(int *)(uVar14 - 4);
          *(int *)(uVar14 - 0x14) = piVar9[-1];
          *(int *)(uVar14 - 0x10) = *piVar9;
          *(int *)(uVar14 - 0xc) = piVar9[1];
          *(int *)(uVar14 - 8) = piVar9[2];
          *(int *)(uVar14 - 4) = piVar9[3];
          *piVar9 = iVar8;
          piVar9[1] = 0;
          piVar9[-1] = iVar4;
          piVar9[2] = iVar5;
          piVar9[3] = iVar6;
        }
        local_8 = local_8 - 0x18;
        piVar9 = piVar9 + -6;
        uVar14 = uVar10;
      } while (param_2 < local_8);
    }
    if (local_8 == param_2) {
      if (uVar11 == param_3) {
        param_1[1] = uVar12;
        *param_1 = uVar10;
        return;
      }
      if (uVar12 != uVar11) {
        uVar1 = *(undefined4 *)(uVar10 + 4);
        uVar7 = *(undefined4 *)(uVar10 + 8);
        uVar2 = *(undefined4 *)(uVar10 + 0x10);
        uVar3 = *(undefined4 *)(uVar10 + 0x14);
        *(undefined4 *)(uVar10 + 4) = *(undefined4 *)(uVar12 + 4);
        *(undefined4 *)(uVar10 + 8) = *(undefined4 *)(uVar12 + 8);
        *(undefined4 *)(uVar10 + 0xc) = *(undefined4 *)(uVar12 + 0xc);
        *(undefined4 *)(uVar10 + 0x10) = *(undefined4 *)(uVar12 + 0x10);
        *(undefined4 *)(uVar10 + 0x14) = *(undefined4 *)(uVar12 + 0x14);
        *(undefined4 *)(uVar12 + 8) = uVar7;
        *(undefined4 *)(uVar12 + 0xc) = 0;
        *(undefined4 *)(uVar12 + 4) = uVar1;
        *(undefined4 *)(uVar12 + 0x10) = uVar2;
        *(undefined4 *)(uVar12 + 0x14) = uVar3;
      }
      uVar1 = *(undefined4 *)(uVar10 + 4);
      uVar7 = *(undefined4 *)(uVar10 + 8);
      uVar2 = *(undefined4 *)(uVar10 + 0x10);
      uVar3 = *(undefined4 *)(uVar10 + 0x14);
      *(undefined4 *)(uVar10 + 4) = *(undefined4 *)(uVar11 + 4);
      *(undefined4 *)(uVar10 + 8) = *(undefined4 *)(uVar11 + 8);
      *(undefined4 *)(uVar10 + 0xc) = *(undefined4 *)(uVar11 + 0xc);
      *(undefined4 *)(uVar10 + 0x10) = *(undefined4 *)(uVar11 + 0x10);
      *(undefined4 *)(uVar10 + 0x14) = *(undefined4 *)(uVar11 + 0x14);
      *(undefined4 *)(uVar11 + 8) = uVar7;
      *(undefined4 *)(uVar11 + 4) = uVar1;
      *(undefined4 *)(uVar11 + 0xc) = 0;
      *(undefined4 *)(uVar11 + 0x10) = uVar2;
      *(undefined4 *)(uVar11 + 0x14) = uVar3;
      uVar11 = uVar11 + 0x18;
      uVar10 = uVar10 + 0x18;
      uVar14 = uVar12 + 0x18;
    }
    else {
      uVar13 = local_8 - 0x18;
      if (uVar11 == param_3) {
        if (uVar13 != uVar10 - 0x18) {
          uVar1 = *(undefined4 *)(local_8 - 0x14);
          uVar7 = *(undefined4 *)(local_8 - 0x10);
          uVar2 = *(undefined4 *)(local_8 - 8);
          uVar3 = *(undefined4 *)(local_8 - 4);
          *(undefined4 *)(local_8 - 0x14) = *(undefined4 *)(uVar10 - 0x14);
          *(undefined4 *)(local_8 - 0x10) = *(undefined4 *)(uVar10 - 0x10);
          *(undefined4 *)(local_8 - 0xc) = *(undefined4 *)(uVar10 - 0xc);
          *(undefined4 *)(local_8 - 8) = *(undefined4 *)(uVar10 - 8);
          *(undefined4 *)(local_8 - 4) = *(undefined4 *)(uVar10 - 4);
          *(undefined4 *)(uVar10 - 0x10) = uVar7;
          *(undefined4 *)(uVar10 - 0xc) = 0;
          *(undefined4 *)(uVar10 - 0x14) = uVar1;
          *(undefined4 *)(uVar10 - 8) = uVar2;
          *(undefined4 *)(uVar10 - 4) = uVar3;
        }
        uVar1 = *(undefined4 *)(uVar10 - 0x14);
        uVar7 = *(undefined4 *)(uVar10 - 0x10);
        uVar2 = *(undefined4 *)(uVar10 - 8);
        uVar3 = *(undefined4 *)(uVar10 - 4);
        *(undefined4 *)(uVar10 - 0x14) = *(undefined4 *)(uVar12 - 0x14);
        *(undefined4 *)(uVar10 - 0x10) = *(undefined4 *)(uVar12 - 0x10);
        *(undefined4 *)(uVar10 - 0xc) = *(undefined4 *)(uVar12 - 0xc);
        *(undefined4 *)(uVar10 - 8) = *(undefined4 *)(uVar12 - 8);
        *(undefined4 *)(uVar10 - 4) = *(undefined4 *)(uVar12 - 4);
        *(undefined4 *)(uVar12 - 0x10) = uVar7;
        *(undefined4 *)(uVar12 - 0xc) = 0;
        *(undefined4 *)(uVar12 - 0x14) = uVar1;
        *(undefined4 *)(uVar12 - 8) = uVar2;
        *(undefined4 *)(uVar12 - 4) = uVar3;
        uVar10 = uVar10 - 0x18;
        uVar14 = uVar12 - 0x18;
        local_8 = uVar13;
      }
      else {
        uVar1 = *(undefined4 *)(uVar11 + 4);
        uVar7 = *(undefined4 *)(uVar11 + 8);
        uVar2 = *(undefined4 *)(uVar11 + 0x10);
        uVar3 = *(undefined4 *)(uVar11 + 0x14);
        *(undefined4 *)(uVar11 + 4) = *(undefined4 *)(local_8 - 0x14);
        *(undefined4 *)(uVar11 + 8) = *(undefined4 *)(local_8 - 0x10);
        *(undefined4 *)(uVar11 + 0xc) = *(undefined4 *)(local_8 - 0xc);
        *(undefined4 *)(uVar11 + 0x10) = *(undefined4 *)(local_8 - 8);
        *(undefined4 *)(uVar11 + 0x14) = *(undefined4 *)(local_8 - 4);
        *(undefined4 *)(local_8 - 0x10) = uVar7;
        *(undefined4 *)(local_8 - 0xc) = 0;
        *(undefined4 *)(local_8 - 0x14) = uVar1;
        *(undefined4 *)(local_8 - 8) = uVar2;
        *(undefined4 *)(local_8 - 4) = uVar3;
        uVar11 = uVar11 + 0x18;
        uVar14 = uVar12;
        local_8 = uVar13;
      }
    }
  } while( true );
}

