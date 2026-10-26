
void FUN_008f3d70(uint *param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int local_20;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  if (*param_1 != 1) {
    local_18 = 1;
    piVar4 = param_2;
    if (1 < *param_1) {
      do {
        uVar3 = local_18;
        for (piVar1 = piVar4 + 3; (uVar3 != 0 && (iVar2 = *piVar1, iVar2 < piVar1[-3]));
            piVar1 = piVar1 + -3) {
          iVar8 = piVar1[1];
          iVar7 = piVar1[2];
          *piVar1 = piVar1[-3];
          piVar1[1] = piVar1[-2];
          piVar1[-3] = iVar2;
          piVar1[-2] = iVar8;
          piVar1[2] = piVar1[-1];
          piVar1[-1] = iVar7;
          uVar3 = uVar3 - 1;
        }
        local_18 = local_18 + 1;
        piVar4 = piVar4 + 3;
      } while (local_18 < *param_1);
    }
    local_20 = *param_2;
    uVar9 = 0;
    uVar5 = *param_1;
    uVar3 = 1;
    local_14 = 0;
    if (1 < uVar5) {
      local_18 = 0;
      local_10 = 0;
      local_c = 0x18;
      piVar4 = param_2;
      do {
        local_8 = piVar4 + 3;
        if ((param_3 < *local_8 - local_20) || (uVar3 == uVar5 - 1)) {
          uVar6 = 0;
          if ((*local_8 - local_20 <= param_3) && (uVar3 == uVar5 - 1)) {
            local_8 = piVar4 + 6;
            local_c = local_c + 0xc;
            uVar3 = uVar3 + 1;
            local_10 = local_10 + 1;
          }
          iVar2 = 0;
          iVar8 = 0;
          if (uVar9 < uVar3) {
            if (1 < (int)(uVar3 - uVar9)) {
              piVar4 = (int *)((int)param_2 + local_18);
              iVar7 = ((local_10 - local_14) - 1 >> 1) + 1;
              uVar9 = local_14 + iVar7 * 2;
              do {
                iVar2 = iVar2 + *piVar4;
                iVar8 = iVar8 + piVar4[3];
                *piVar4 = 0;
                piVar4[3] = 0;
                piVar4 = piVar4 + 6;
                iVar7 = iVar7 + -1;
              } while (iVar7 != 0);
            }
            iVar7 = 0;
            if (uVar9 < uVar3) {
              iVar7 = param_2[uVar9 * 3];
              param_2[uVar9 * 3] = 0;
              uVar9 = uVar9 + 1;
            }
            uVar6 = iVar7 + iVar8 + iVar2;
          }
          *(uint *)(local_18 + (int)param_2) = uVar6 / uVar9;
          uVar5 = *param_1;
          uVar9 = local_14;
          if (uVar3 < uVar5 - 1) {
            uVar9 = uVar3 + 1;
            local_18 = local_c;
            local_20 = *(int *)(local_c + (int)param_2);
            local_14 = uVar9;
          }
        }
        local_10 = local_10 + 1;
        local_c = local_c + 0xc;
        uVar3 = uVar3 + 1;
        piVar4 = local_8;
      } while (uVar3 < *param_1);
    }
    uVar9 = 1;
    uVar3 = 1;
    if (1 < *param_1) {
      param_2 = param_2 + 3;
      piVar4 = param_2;
      do {
        if (*param_2 != 0) {
          *piVar4 = *param_2;
          piVar4[1] = param_2[1];
          piVar4[2] = param_2[2];
          uVar9 = uVar9 + 1;
          piVar4 = piVar4 + 3;
        }
        uVar3 = uVar3 + 1;
        param_2 = param_2 + 3;
      } while (uVar3 < *param_1);
    }
    *param_1 = uVar9;
  }
  return;
}

