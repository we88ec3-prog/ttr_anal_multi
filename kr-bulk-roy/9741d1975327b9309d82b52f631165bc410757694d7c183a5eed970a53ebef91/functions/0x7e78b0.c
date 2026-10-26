
void FUN_007e78b0(int param_1)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined4 local_98 [5];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_54 [4];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_20;
  int *local_1c;
  int *local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00934abe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  local_1c = (int *)FUN_0079a5f0(&DAT_00fb76a8);
  (**(code **)(**(int **)(param_1 + 8) + 0x34))(*(int **)(param_1 + 8),local_18);
  puVar7 = *(undefined4 **)(param_1 + 0x180);
  local_98[0] = *puVar7;
  local_98[1] = puVar7[1];
  local_98[2] = puVar7[2];
  local_20 = *(undefined4 *)(*(int *)(param_1 + 0x24) + 8);
  local_98[3] = 0;
  local_98[4] = puVar7[3];
  local_84 = puVar7[4];
  local_80 = puVar7[5];
  local_7c = 0;
  local_78 = puVar7[6];
  local_74 = puVar7[7];
  local_70 = puVar7[8];
  local_6c = 0;
  local_68 = puVar7[9];
  local_64 = puVar7[10];
  uVar2 = 0;
  local_60 = puVar7[0xb];
  local_5c = 0x3f800000;
  puVar7 = local_98;
  puVar8 = (undefined4 *)(*(int *)(param_1 + 0x19c) + 0x18);
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  uVar6 = *(int *)(param_1 + 0x188) - *(int *)(param_1 + 0x184) >> 2;
  if (3 < (int)uVar6) {
    iVar4 = 0;
    do {
      piVar9 = *(int **)(*(int *)(param_1 + 0x184) + uVar2 * 4);
      if (*piVar9 != 0) {
        puVar7 = (undefined4 *)piVar9[0x10];
        puVar8 = local_54;
        for (iVar5 = 0xd; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        local_98[0] = local_54[0];
        local_98[1] = local_54[1];
        local_98[2] = local_54[2];
        local_98[3] = 0;
        local_98[4] = local_54[3];
        local_84 = local_44;
        local_80 = local_40;
        local_7c = 0;
        local_78 = local_3c;
        local_74 = local_38;
        local_70 = local_34;
        local_6c = 0;
        local_68 = local_30;
        local_64 = local_2c;
        local_60 = local_28;
        local_5c = 0x3f800000;
        puVar7 = local_98;
        puVar8 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x19c) + 0x84) + 8 + iVar4);
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      piVar9 = *(int **)(*(int *)(param_1 + 0x184) + 4 + uVar2 * 4);
      if (*piVar9 != 0) {
        puVar7 = (undefined4 *)piVar9[0x10];
        puVar8 = local_54;
        for (iVar5 = 0xd; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        local_98[0] = local_54[0];
        local_98[1] = local_54[1];
        local_98[2] = local_54[2];
        local_98[3] = 0;
        local_98[4] = local_54[3];
        local_84 = local_44;
        local_80 = local_40;
        local_7c = 0;
        local_78 = local_3c;
        local_74 = local_38;
        local_70 = local_34;
        local_6c = 0;
        local_68 = local_30;
        local_64 = local_2c;
        local_60 = local_28;
        local_5c = 0x3f800000;
        puVar7 = local_98;
        puVar8 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x19c) + 0x84) + 0x50 + iVar4);
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      piVar9 = *(int **)(*(int *)(param_1 + 0x184) + 8 + uVar2 * 4);
      if (*piVar9 != 0) {
        puVar7 = (undefined4 *)piVar9[0x10];
        puVar8 = local_54;
        for (iVar5 = 0xd; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        local_98[0] = local_54[0];
        local_98[1] = local_54[1];
        local_98[2] = local_54[2];
        local_98[3] = 0;
        local_98[4] = local_54[3];
        local_84 = local_44;
        local_80 = local_40;
        local_7c = 0;
        local_78 = local_3c;
        local_74 = local_38;
        local_70 = local_34;
        local_6c = 0;
        local_68 = local_30;
        local_64 = local_2c;
        local_60 = local_28;
        local_5c = 0x3f800000;
        puVar7 = local_98;
        puVar8 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x19c) + 0x84) + 0x98 + iVar4);
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      piVar9 = *(int **)(*(int *)(param_1 + 0x184) + 0xc + uVar2 * 4);
      if (*piVar9 != 0) {
        puVar7 = (undefined4 *)piVar9[0x10];
        puVar8 = local_54;
        for (iVar5 = 0xd; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        local_98[0] = local_54[0];
        local_98[1] = local_54[1];
        local_98[2] = local_54[2];
        local_98[3] = 0;
        local_98[4] = local_54[3];
        local_84 = local_44;
        local_80 = local_40;
        local_7c = 0;
        local_78 = local_3c;
        local_74 = local_38;
        local_70 = local_34;
        local_6c = 0;
        local_68 = local_30;
        local_64 = local_2c;
        local_60 = local_28;
        local_5c = 0x3f800000;
        puVar7 = local_98;
        puVar8 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x19c) + 0x84) + 0xe0 + iVar4);
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      uVar2 = uVar2 + 4;
      iVar4 = iVar4 + 0x120;
    } while (uVar2 < uVar6 - 3);
  }
  if (uVar2 < uVar6) {
    iVar4 = uVar2 * 0x48;
    do {
      piVar9 = *(int **)(*(int *)(param_1 + 0x184) + uVar2 * 4);
      if (*piVar9 != 0) {
        puVar7 = (undefined4 *)piVar9[0x10];
        puVar8 = local_54;
        for (iVar5 = 0xd; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        local_98[0] = local_54[0];
        local_98[1] = local_54[1];
        local_98[2] = local_54[2];
        local_98[3] = 0;
        local_98[4] = local_54[3];
        local_84 = local_44;
        local_80 = local_40;
        local_7c = 0;
        local_78 = local_3c;
        local_74 = local_38;
        local_70 = local_34;
        local_6c = 0;
        local_68 = local_30;
        local_64 = local_2c;
        local_60 = local_28;
        local_5c = 0x3f800000;
        puVar7 = local_98;
        puVar8 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x19c) + 0x84) + 8 + iVar4);
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      uVar2 = uVar2 + 1;
      iVar4 = iVar4 + 0x48;
    } while (uVar2 < uVar6);
  }
  piVar1 = local_1c;
  local_5c = 0x3f800000;
  local_6c = 0;
  local_7c = 0;
  local_98[3] = 0;
  (**(code **)(*local_1c + 0x15c))(local_1c,*(undefined4 *)(param_1 + 0xc));
  (**(code **)(*piVar1 + 400))(piVar1,0,local_18[0],0,0x18);
  (**(code **)(*piVar1 + 0x1a0))(piVar1,local_20);
  piVar9 = *(int **)(param_1 + 8);
  uVar3 = (**(code **)(*piVar9 + 0x14))(piVar9,*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x10));
  FUN_007f8650(piVar1,uVar3,piVar9);
  (**(code **)(*local_18[0] + 8))(local_18[0]);
  ExceptionList = local_10;
  return;
}

