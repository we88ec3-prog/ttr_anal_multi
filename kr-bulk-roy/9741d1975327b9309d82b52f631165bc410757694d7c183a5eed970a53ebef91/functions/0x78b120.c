
void FUN_0078b120(uint *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint local_8;
  
  uVar9 = (((int)(param_3 - param_2) >> 4) - ((int)(param_3 - param_2) >> 0x1f) >> 1) * 0x10 +
          param_2;
  FUN_0078d7a0(uVar9,param_3 - 0x10,param_4);
  uVar10 = uVar9 + 0x10;
  for (; param_2 < uVar9; uVar9 = uVar9 - 0x10) {
    if ((*(int *)(uVar9 - 8) < *(int *)(uVar9 + 8)) || (*(int *)(uVar9 + 8) < *(int *)(uVar9 - 8)))
    break;
  }
  uVar11 = uVar10;
  local_8 = uVar9;
  if (uVar10 < param_3) {
    do {
      uVar11 = uVar10;
      if ((*(int *)(uVar10 + 8) < *(int *)(uVar9 + 8)) ||
         (*(int *)(uVar9 + 8) < *(int *)(uVar10 + 8))) break;
      uVar10 = uVar10 + 0x10;
      uVar11 = uVar10;
    } while (uVar10 < param_3);
  }
  do {
    if (uVar10 < param_3) {
      iVar6 = (param_3 - uVar10) + 0xf;
      if (3 < (int)(iVar6 + (iVar6 >> 0x1f & 0xfU)) >> 4) {
        do {
          if (*(int *)(uVar10 + 8) <= *(int *)(uVar9 + 8)) {
            if (*(int *)(uVar10 + 8) < *(int *)(uVar9 + 8)) goto LAB_0078b35c;
            uVar2 = *(undefined4 *)(uVar11 + 8);
            uVar1 = *(undefined4 *)(uVar11 + 4);
            uVar3 = *(undefined4 *)(uVar11 + 0xc);
            *(undefined4 *)(uVar11 + 4) = *(undefined4 *)(uVar10 + 4);
            *(undefined4 *)(uVar11 + 8) = *(undefined4 *)(uVar10 + 8);
            *(undefined4 *)(uVar11 + 0xc) = *(undefined4 *)(uVar10 + 0xc);
            *(undefined4 *)(uVar10 + 4) = uVar1;
            uVar11 = uVar11 + 0x10;
            *(undefined4 *)(uVar10 + 8) = uVar2;
            *(undefined4 *)(uVar10 + 0xc) = uVar3;
          }
          if (*(int *)(uVar10 + 0x18) <= *(int *)(uVar9 + 8)) {
            if (*(int *)(uVar10 + 0x18) < *(int *)(uVar9 + 8)) {
              uVar10 = uVar10 + 0x10;
              goto LAB_0078b35c;
            }
            uVar2 = *(undefined4 *)(uVar11 + 8);
            uVar1 = *(undefined4 *)(uVar11 + 4);
            uVar3 = *(undefined4 *)(uVar11 + 0xc);
            *(undefined4 *)(uVar11 + 4) = *(undefined4 *)(uVar10 + 0x14);
            *(undefined4 *)(uVar11 + 8) = *(undefined4 *)(uVar10 + 0x18);
            *(undefined4 *)(uVar11 + 0xc) = *(undefined4 *)(uVar10 + 0x1c);
            *(undefined4 *)(uVar10 + 0x14) = uVar1;
            uVar11 = uVar11 + 0x10;
            *(undefined4 *)(uVar10 + 0x18) = uVar2;
            *(undefined4 *)(uVar10 + 0x1c) = uVar3;
          }
          if (*(int *)(uVar10 + 0x28) <= *(int *)(uVar9 + 8)) {
            if (*(int *)(uVar10 + 0x28) < *(int *)(uVar9 + 8)) {
              uVar10 = uVar10 + 0x20;
              goto LAB_0078b35c;
            }
            uVar2 = *(undefined4 *)(uVar11 + 8);
            uVar1 = *(undefined4 *)(uVar11 + 4);
            uVar3 = *(undefined4 *)(uVar11 + 0xc);
            *(undefined4 *)(uVar11 + 4) = *(undefined4 *)(uVar10 + 0x24);
            *(undefined4 *)(uVar11 + 8) = *(undefined4 *)(uVar10 + 0x28);
            *(undefined4 *)(uVar11 + 0xc) = *(undefined4 *)(uVar10 + 0x2c);
            *(undefined4 *)(uVar10 + 0x24) = uVar1;
            uVar11 = uVar11 + 0x10;
            *(undefined4 *)(uVar10 + 0x28) = uVar2;
            *(undefined4 *)(uVar10 + 0x2c) = uVar3;
          }
          if (*(int *)(uVar10 + 0x38) <= *(int *)(uVar9 + 8)) {
            if (*(int *)(uVar10 + 0x38) < *(int *)(uVar9 + 8)) {
              uVar10 = uVar10 + 0x30;
              goto LAB_0078b35c;
            }
            uVar1 = *(undefined4 *)(uVar11 + 4);
            uVar2 = *(undefined4 *)(uVar11 + 0xc);
            uVar3 = *(undefined4 *)(uVar11 + 8);
            *(undefined4 *)(uVar11 + 4) = *(undefined4 *)(uVar10 + 0x34);
            *(undefined4 *)(uVar11 + 8) = *(undefined4 *)(uVar10 + 0x38);
            *(undefined4 *)(uVar11 + 0xc) = *(undefined4 *)(uVar10 + 0x3c);
            *(undefined4 *)(uVar10 + 0x34) = uVar1;
            uVar11 = uVar11 + 0x10;
            *(undefined4 *)(uVar10 + 0x38) = uVar3;
            *(undefined4 *)(uVar10 + 0x3c) = uVar2;
          }
          uVar10 = uVar10 + 0x40;
        } while ((int)uVar10 < (int)(param_3 - 0x30));
      }
      for (; uVar10 < param_3; uVar10 = uVar10 + 0x10) {
        if (*(int *)(uVar10 + 8) <= *(int *)(uVar9 + 8)) {
          if (*(int *)(uVar10 + 8) < *(int *)(uVar9 + 8)) break;
          uVar1 = *(undefined4 *)(uVar11 + 4);
          uVar2 = *(undefined4 *)(uVar11 + 0xc);
          uVar3 = *(undefined4 *)(uVar11 + 8);
          *(undefined4 *)(uVar11 + 4) = *(undefined4 *)(uVar10 + 4);
          *(undefined4 *)(uVar11 + 8) = *(undefined4 *)(uVar10 + 8);
          *(undefined4 *)(uVar11 + 0xc) = *(undefined4 *)(uVar10 + 0xc);
          *(undefined4 *)(uVar10 + 4) = uVar1;
          uVar11 = uVar11 + 0x10;
          *(undefined4 *)(uVar10 + 8) = uVar3;
          *(undefined4 *)(uVar10 + 0xc) = uVar2;
        }
      }
    }
LAB_0078b35c:
    if (param_2 < local_8) {
      piVar7 = (int *)(local_8 - 8);
      uVar8 = uVar9;
      do {
        uVar9 = uVar8;
        if (*(int *)(uVar8 + 8) <= *piVar7) {
          if (*(int *)(uVar8 + 8) < *piVar7) break;
          iVar6 = *(int *)(uVar8 - 0xc);
          iVar4 = *(int *)(uVar8 - 4);
          iVar5 = *(int *)(uVar8 - 8);
          uVar9 = uVar8 - 0x10;
          *(int *)(uVar8 - 0xc) = piVar7[-1];
          *(int *)(uVar8 - 8) = *piVar7;
          *(int *)(uVar8 - 4) = piVar7[1];
          piVar7[-1] = iVar6;
          *piVar7 = iVar5;
          piVar7[1] = iVar4;
        }
        local_8 = local_8 - 0x10;
        piVar7 = piVar7 + -4;
        uVar8 = uVar9;
      } while (param_2 < local_8);
    }
    if (local_8 == param_2) {
      if (uVar10 == param_3) {
        param_1[1] = uVar11;
        *param_1 = uVar9;
        return;
      }
      if (uVar11 != uVar10) {
        uVar1 = *(undefined4 *)(uVar9 + 4);
        uVar2 = *(undefined4 *)(uVar9 + 8);
        uVar3 = *(undefined4 *)(uVar9 + 0xc);
        *(undefined4 *)(uVar9 + 4) = *(undefined4 *)(uVar11 + 4);
        *(undefined4 *)(uVar9 + 8) = *(undefined4 *)(uVar11 + 8);
        *(undefined4 *)(uVar9 + 0xc) = *(undefined4 *)(uVar11 + 0xc);
        *(undefined4 *)(uVar11 + 4) = uVar1;
        *(undefined4 *)(uVar11 + 8) = uVar2;
        *(undefined4 *)(uVar11 + 0xc) = uVar3;
      }
      uVar2 = *(undefined4 *)(uVar9 + 8);
      uVar1 = *(undefined4 *)(uVar9 + 4);
      uVar3 = *(undefined4 *)(uVar9 + 0xc);
      *(undefined4 *)(uVar9 + 4) = *(undefined4 *)(uVar10 + 4);
      *(undefined4 *)(uVar9 + 8) = *(undefined4 *)(uVar10 + 8);
      *(undefined4 *)(uVar9 + 0xc) = *(undefined4 *)(uVar10 + 0xc);
      *(undefined4 *)(uVar10 + 4) = uVar1;
      *(undefined4 *)(uVar10 + 8) = uVar2;
      *(undefined4 *)(uVar10 + 0xc) = uVar3;
      uVar10 = uVar10 + 0x10;
      uVar9 = uVar9 + 0x10;
      uVar11 = uVar11 + 0x10;
    }
    else {
      uVar8 = local_8 - 0x10;
      if (uVar10 == param_3) {
        if (uVar8 != uVar9 - 0x10) {
          uVar1 = *(undefined4 *)(local_8 - 0xc);
          uVar2 = *(undefined4 *)(local_8 - 4);
          uVar3 = *(undefined4 *)(local_8 - 8);
          *(undefined4 *)(local_8 - 0xc) = *(undefined4 *)(uVar9 - 0xc);
          *(undefined4 *)(local_8 - 8) = *(undefined4 *)(uVar9 - 8);
          *(undefined4 *)(local_8 - 4) = *(undefined4 *)(uVar9 - 4);
          *(undefined4 *)(uVar9 - 0xc) = uVar1;
          *(undefined4 *)(uVar9 - 8) = uVar3;
          *(undefined4 *)(uVar9 - 4) = uVar2;
        }
        uVar1 = *(undefined4 *)(uVar9 - 0xc);
        uVar2 = *(undefined4 *)(uVar9 - 4);
        uVar3 = *(undefined4 *)(uVar9 - 8);
        *(undefined4 *)(uVar9 - 0xc) = *(undefined4 *)(uVar11 - 0xc);
        *(undefined4 *)(uVar9 - 8) = *(undefined4 *)(uVar11 - 8);
        *(undefined4 *)(uVar9 - 4) = *(undefined4 *)(uVar11 - 4);
        *(undefined4 *)(uVar11 - 0xc) = uVar1;
        *(undefined4 *)(uVar11 - 8) = uVar3;
        *(undefined4 *)(uVar11 - 4) = uVar2;
        uVar9 = uVar9 - 0x10;
        uVar11 = uVar11 - 0x10;
        local_8 = uVar8;
      }
      else {
        uVar1 = *(undefined4 *)(uVar10 + 4);
        uVar2 = *(undefined4 *)(uVar10 + 0xc);
        uVar3 = *(undefined4 *)(uVar10 + 8);
        *(undefined4 *)(uVar10 + 4) = *(undefined4 *)(local_8 - 0xc);
        *(undefined4 *)(uVar10 + 8) = *(undefined4 *)(local_8 - 8);
        *(undefined4 *)(uVar10 + 0xc) = *(undefined4 *)(local_8 - 4);
        *(undefined4 *)(local_8 - 0xc) = uVar1;
        *(undefined4 *)(local_8 - 8) = uVar3;
        *(undefined4 *)(local_8 - 4) = uVar2;
        uVar10 = uVar10 + 0x10;
        local_8 = uVar8;
      }
    }
  } while( true );
}

