
void FUN_007e6a90(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *puVar10;
  float10 extraout_ST0;
  uint uStack_180;
  int *piStack_178;
  undefined4 local_170;
  int aiStack_16c [3];
  float fStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  float fStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  float fStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  int iStack_128;
  undefined4 uStack_124;
  int local_120 [4];
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 auStack_f4 [5];
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 local_a8 [4];
  undefined4 local_98;
  undefined4 local_88;
  undefined4 local_74 [4];
  undefined4 local_64;
  undefined4 local_54;
  
  if (*(int *)(in_ECX + 0x194) == 0) {
    _memset(local_74,0,0x34);
    local_54 = 0x3f800000;
    local_64 = 0x3f800000;
    local_74[0] = 0x3f800000;
    _memset(local_a8,0,0x34);
    local_88 = 0x3f800000;
    local_98 = 0x3f800000;
    local_a8[0] = 0x3f800000;
    piVar8 = param_1 + 0x26;
    piVar2 = local_120;
    for (iVar6 = 0xd; iVar6 != 0; iVar6 = iVar6 + -1) {
      *piVar2 = *piVar8;
      piVar8 = piVar8 + 1;
      piVar2 = piVar2 + 1;
    }
    FUN_00790b40();
    uVar1 = FUN_007e7dd0(local_a8);
    piVar2 = (int *)FUN_007e7dd0(uVar1);
    piVar8 = *(int **)(in_ECX + 4);
    piVar9 = local_120;
    for (iVar6 = 0xd; iVar6 != 0; iVar6 = iVar6 + -1) {
      *piVar9 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar9 = piVar9 + 1;
    }
    (**(code **)(*piVar8 + 0x34))(piVar8,&local_170);
    local_170 = *(undefined4 *)(*(int *)(in_ECX + 0x20) + 8);
    *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(*(int *)(in_ECX + 0x20) + 0x10);
    uVar3 = *(int *)(in_ECX + 0x184) - *(int *)(in_ECX + 0x180) >> 2;
    uStack_180 = 0;
    if (uVar3 != 0) {
      do {
        piVar8 = *(int **)(*(int *)(in_ECX + 0x180) + uStack_180 * 4);
        if (*piVar8 != 0) {
          iVar6 = piVar8[0x20];
          iVar4 = FUN_00843ef0();
          aiStack_16c[0] = iStack_128;
          aiStack_16c[1] = uStack_124;
          aiStack_16c[2] = local_120[0];
          fStack_160 = (float)extraout_ST0;
          uStack_15c = local_120[1];
          uStack_158 = local_120[2];
          uStack_154 = local_120[3];
          fStack_150 = (float)extraout_ST0;
          uStack_14c = uStack_110;
          uStack_148 = uStack_10c;
          uStack_144 = uStack_108;
          fStack_140 = (float)extraout_ST0;
          uStack_13c = uStack_104;
          uStack_138 = uStack_100;
          uStack_134 = uStack_fc;
          uStack_130 = 0x3f800000;
          piVar8 = aiStack_16c;
          piVar2 = (int *)(iVar4 + 0x70);
          for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
            *piVar2 = *piVar8;
            piVar8 = piVar8 + 1;
            piVar2 = piVar2 + 1;
          }
          *(undefined4 *)(iVar4 + 0xb4) = 1;
          iVar4 = FUN_00843ef0();
          puVar5 = (undefined4 *)FUN_007e7dd0();
          auStack_f4[0] = *puVar5;
          auStack_f4[1] = puVar5[1];
          auStack_f4[2] = puVar5[2];
          auStack_f4[3] = 0;
          auStack_f4[4] = puVar5[3];
          uStack_e0 = puVar5[4];
          uStack_dc = puVar5[5];
          uStack_d8 = 0;
          uStack_d4 = puVar5[6];
          uStack_d0 = puVar5[7];
          uStack_cc = puVar5[8];
          uStack_c8 = 0;
          uStack_c4 = puVar5[9];
          uStack_c0 = puVar5[10];
          uStack_bc = puVar5[0xb];
          uStack_b8 = 0x3f800000;
          puVar5 = auStack_f4;
          puVar10 = (undefined4 *)(iVar4 + 0x70);
          for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar10 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar10 = puVar10 + 1;
          }
          *(undefined4 *)(iVar4 + 0xb4) = 1;
          if ((*(int *)(in_ECX + 0x24) != 0) && (2 < *(int *)(iVar6 + 0x178))) {
            iVar4 = FUN_00843ef0();
            FUN_0079c530();
            piVar8 = aiStack_16c;
            piVar2 = (int *)(iVar4 + 0x70);
            for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
              *piVar2 = *piVar8;
              piVar8 = piVar8 + 1;
              piVar2 = piVar2 + 1;
            }
            *(undefined4 *)(iVar4 + 0xb4) = 1;
          }
          FUN_0083cc70(param_1,iVar6,piStack_178,local_170,*(undefined4 *)(in_ECX + 8),in_ECX + 0xc,
                       0x3ff0000000000000);
          (**(code **)(*param_1 + 0xc))(1,1,1);
        }
        uStack_180 = uStack_180 + 1;
      } while (uStack_180 < uVar3);
    }
    (**(code **)(*piStack_178 + 8))();
    return;
  }
  FUN_007f86f0();
  FUN_007e78b0(in_ECX + -4);
  return;
}

