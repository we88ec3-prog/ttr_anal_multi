
void FUN_007be150(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  byte bVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  undefined4 *puVar11;
  int *piVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  float local_ec;
  undefined4 local_c8 [3];
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_a8;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
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
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [4];
  undefined4 local_2c;
  undefined4 local_1c;
  
  local_ec = 0.0;
  local_78 = *(undefined4 *)(param_1 + 0x18);
  local_74 = *(undefined4 *)(param_1 + 0x18);
  local_70 = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x14) = 0;
  local_6c = 1;
  _memset(local_c8,0,0x34);
  local_a8 = 0x3f800000;
  local_b8 = 0x3f800000;
  local_c8[0] = 0x3f800000;
  FUN_00790dc0(*(undefined4 *)(param_1 + 0x34));
  FUN_00790e90(*(undefined4 *)(param_1 + 0x38));
  FUN_00790f60(*(undefined4 *)(param_1 + 0x3c));
  FUN_00780890();
  local_7c = 0x3f800000;
  local_40 = 1;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_94 = *(undefined4 *)(param_1 + 0x28);
  local_90 = *(undefined4 *)(param_1 + 0x2c);
  local_8c = *(undefined4 *)(param_1 + 0x30);
  local_4c = *(undefined4 *)(param_1 + 0x40);
  local_48 = *(undefined4 *)(param_1 + 0x40);
  local_44 = *(undefined4 *)(param_1 + 0x40);
  _memset(local_c8,0,0x34);
  local_a8 = 0x3f800000;
  local_b8 = 0x3f800000;
  local_c8[0] = 0x3f800000;
  FUN_00790dc0(*(undefined4 *)(param_1 + 0x50));
  FUN_00790e90(*(undefined4 *)(param_1 + 0x54));
  FUN_00790f60(*(undefined4 *)(param_1 + 0x58));
  FUN_00780890();
  local_50 = 0x3f800000;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_68 = *(undefined4 *)(param_1 + 0x44);
  local_64 = *(undefined4 *)(param_1 + 0x48);
  local_60 = *(undefined4 *)(param_1 + 0x4c);
  piVar7 = *(int **)(param_1 + 8);
  for (piVar12 = *(int **)(param_1 + 4); piVar12 != piVar7; piVar12 = piVar12 + 1) {
    iVar8 = *piVar12;
    iVar9 = *(int *)(iVar8 + 4);
    uVar13 = *(undefined4 *)(iVar9 + 0x44);
    uVar1 = *(undefined4 *)(iVar9 + 0x44);
    uVar2 = *(undefined4 *)(iVar9 + 0x44);
    _memset(local_3c,0,0x34);
    local_1c = 0x3f800000;
    local_2c = 0x3f800000;
    local_3c[0] = 0x3f800000;
    FUN_00790dc0(*(undefined4 *)(iVar9 + 0x54));
    FUN_00790e90(*(undefined4 *)(iVar9 + 0x58));
    FUN_00790f60(*(undefined4 *)(iVar9 + 0x5c));
    FUN_00780890();
    uVar3 = *(undefined4 *)(iVar9 + 0x48);
    uVar4 = *(undefined4 *)(iVar9 + 0x4c);
    bVar6 = *(byte *)(*(int *)(iVar8 + 4) + 0x61);
    uVar5 = *(undefined4 *)(iVar9 + 0x50);
    if (bVar6 == 0) {
      bVar6 = 1;
      *(undefined4 *)(param_1 + 0x14) = 1;
    }
    if (*(int *)(iVar8 + 8) != 0) {
      puVar14 = *(undefined4 **)(*(int *)(iVar8 + 8) + 0x78);
      if (puVar14 != local_c8) {
        *puVar14 = uVar3;
        puVar14[1] = uVar4;
        puVar14[2] = uVar5;
        if (puVar14 + 3 != &local_bc) {
          puVar14[6] = 0x3f800000;
          puVar14[3] = 0;
          puVar14[4] = 0;
          puVar14[5] = 0;
        }
        puVar14[7] = uVar13;
        puVar14[8] = uVar1;
        puVar14[9] = uVar2;
        puVar14[10] = 1;
      }
      if (*(char *)(iVar9 + 0x60) == '\0') {
        uVar13 = *(undefined4 *)(*(int *)(iVar8 + 8) + 0x78);
        puVar14 = &local_68;
      }
      else {
        uVar13 = *(undefined4 *)(*(int *)(iVar8 + 8) + 0x78);
        puVar14 = &local_94;
      }
      puVar11 = (undefined4 *)FUN_0077e910(local_c8,uVar13,puVar14);
      puVar14 = *(undefined4 **)(*(int *)(iVar8 + 8) + 0x74);
      if (puVar14 != puVar11) {
        *puVar14 = *puVar11;
        puVar14[1] = puVar11[1];
        puVar14[2] = puVar11[2];
        if (puVar14 + 3 != puVar11 + 3) {
          puVar14[6] = puVar11[6];
          puVar14[3] = puVar11[3];
          puVar14[4] = puVar11[4];
          puVar14[5] = puVar11[5];
        }
        puVar14[7] = puVar11[7];
        puVar14[8] = puVar11[8];
        puVar14[9] = puVar11[9];
        puVar14[10] = puVar11[10];
      }
    }
    fVar10 = *(float *)(*(int *)(iVar8 + 8) + 0x70) * (float)bVar6 *
             (1.0 / *(float *)(*(int *)(iVar8 + 4) + 100)) + *(float *)(iVar9 + 0x40);
    if (local_ec < fVar10) {
      local_ec = fVar10;
    }
  }
  *(float *)(param_1 + 0x20) = local_ec;
  return;
}

