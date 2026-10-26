
void FUN_005103e0(int param_1,uint param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 uint param_6)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  int local_1c;
  uint local_10;
  int local_c;
  int local_8;
  
  local_8 = param_4 - param_2;
  iVar8 = param_6 - param_2;
  local_c = iVar8;
  if (param_6 < param_2) {
  }
  iVar3 = iVar8;
  iVar6 = local_8;
  if (local_8 != 0) {
    do {
      local_c = iVar6;
      iVar6 = iVar3 % local_c;
      iVar3 = local_c;
    } while (iVar6 != 0);
  }
  if (local_c < iVar8) {
    while (0 < local_c) {
      uVar10 = param_2 + local_c;
      local_1c = param_1;
      if (local_8 + uVar10 == param_6) {
        piVar4 = &param_1;
      }
      else {
        local_20 = local_8 + uVar10;
        local_10 = uVar10;
        local_24 = param_1;
        piVar4 = &local_24;
      }
      local_2c = *piVar4;
      uVar11 = piVar4[1];
      uVar9 = uVar10;
      do {
        uVar5 = uVar11;
        uVar11 = uVar5 >> 2;
        if (*(uint *)(local_2c + 8) <= uVar11) {
          uVar11 = uVar11 - *(uint *)(local_2c + 8);
        }
        uVar7 = uVar9 >> 2;
        if (*(uint *)(local_1c + 8) <= uVar7) {
          uVar7 = uVar7 - *(uint *)(local_1c + 8);
        }
        iVar8 = *(int *)(*(int *)(local_2c + 4) + uVar11 * 4);
        puVar1 = (undefined4 *)(*(int *)(*(int *)(local_1c + 4) + uVar7 * 4) + (uVar9 & 3) * 4);
        uVar2 = *puVar1;
        *puVar1 = *(undefined4 *)(iVar8 + (uVar5 & 3) * 4);
        *(undefined4 *)(iVar8 + (uVar5 & 3) * 4) = uVar2;
        local_1c = local_2c;
        if (local_8 < (int)(param_6 - uVar5)) {
          local_10 = uVar5;
          local_28 = uVar5 + local_8;
          piVar4 = &local_2c;
        }
        else {
          local_34 = param_1;
          local_10 = param_2;
          local_30 = (param_2 - (param_6 - uVar5)) + local_8;
          piVar4 = &local_34;
        }
        local_2c = *piVar4;
        uVar11 = piVar4[1];
        uVar9 = uVar5;
      } while (piVar4[1] != uVar10);
      local_c = local_c + -1;
    }
  }
  return;
}

