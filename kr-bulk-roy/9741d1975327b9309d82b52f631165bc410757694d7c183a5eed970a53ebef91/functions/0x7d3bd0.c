
void FUN_007d3bd0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int local_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  uint local_16c;
  undefined4 local_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
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
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined1 auStack_90 [44];
  undefined1 auStack_64 [4];
  undefined1 auStack_60 [40];
  undefined1 auStack_38 [52];
  
  FUN_00780150(*(int *)(param_1 + 0x10),*(undefined4 *)(*(int *)(param_1 + 0x10) + 0x30));
  iVar6 = *(int *)(param_1 + 0x9c) - *(int *)(param_1 + 0x98);
  iVar3 = iVar6 >> 0x1f;
  local_16c = 0;
  if (iVar6 / 0xc + iVar3 != iVar3) {
    local_19c = 0;
    do {
      puVar7 = (undefined4 *)(*(int *)(param_1 + 0x98) + local_19c);
      if (puVar7[1] == 0) {
        FUN_0077ef30();
      }
      else {
        (**(code **)(*(int *)*puVar7 + 0x24))(&local_168);
        (**(code **)(*(int *)puVar7[1] + 0x24))(auStack_38);
      }
      uVar2 = uStack_164;
      uVar1 = local_168;
      uStack_180 = uStack_150;
      uStack_18c = uStack_15c;
      uStack_194 = uStack_164;
      uStack_188 = uStack_158;
      uStack_198 = local_168;
      uStack_184 = uStack_154;
      uStack_190 = uStack_160;
      uStack_17c = uStack_14c;
      uStack_178 = uStack_148;
      uStack_174 = uStack_144;
      uStack_170 = uStack_140;
      FUN_0077ef30();
      (**(code **)(*(int *)puVar7[2] + 0x24))(auStack_60);
      uStack_114 = 0;
      uStack_110 = 0;
      uStack_10c = 0;
      uStack_108 = 0;
      uStack_104 = 0;
      uStack_ec = 1;
      uStack_100 = 0;
      uStack_fc = 0x3f800000;
      uStack_f8 = 0x3f800000;
      uStack_f4 = 0x3f800000;
      uStack_f0 = 0x3f800000;
      FUN_007cce40(&uStack_114,auStack_90);
      uStack_bc = 0;
      uStack_b8 = 0;
      uStack_b4 = 0;
      uStack_b0 = 0;
      uStack_ac = 0;
      uStack_94 = 1;
      uStack_a8 = 0;
      uStack_a4 = 0x3f800000;
      uStack_a0 = 0x3f800000;
      uStack_9c = 0x3f800000;
      uStack_98 = 0x3f800000;
      FUN_007cce40(&uStack_bc,auStack_64);
      FUN_0077e910(&uStack_140,auStack_90,&uStack_114);
      iVar3 = (**(code **)(*(int *)puVar7[2] + 0x3c))();
      if (iVar3 != 0) {
        piVar4 = (int *)(**(code **)(*(int *)puVar7[2] + 0x3c))();
        puVar5 = (undefined4 *)(**(code **)(*piVar4 + 0x24))(auStack_38);
        if (&uStack_140 != puVar5) {
          uStack_140 = *puVar5;
          uStack_13c = puVar5[1];
          uStack_138 = puVar5[2];
          if (&uStack_134 != puVar5 + 3) {
            uStack_128 = puVar5[6];
            uStack_134 = puVar5[3];
            uStack_130 = puVar5[4];
            uStack_12c = puVar5[5];
          }
          uStack_124 = puVar5[7];
          uStack_120 = puVar5[8];
          uStack_11c = puVar5[9];
          uStack_118 = puVar5[10];
        }
      }
      uStack_e8 = 0;
      uStack_e4 = 0;
      uStack_e0 = 0;
      uStack_dc = 0;
      uStack_c0 = 1;
      uStack_d8 = 0;
      uStack_d4 = 0;
      uStack_d0 = 0x3f800000;
      uStack_cc = 0x3f800000;
      uStack_c8 = 0x3f800000;
      uStack_c4 = 0x3f800000;
      FUN_007cce40(&uStack_e8,&uStack_140);
      (**(code **)(*(int *)puVar7[2] + 0x34))();
      iVar3 = puVar7[2];
      if (*(int *)(iVar3 + 0xdc) - *(int *)(iVar3 + 0xd8) >> 2 == 0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)**(undefined4 **)(iVar3 + 0xd8);
      }
      iVar3 = (**(code **)(*piVar4 + 4))();
      iVar3 = *(int *)(iVar3 + 4);
      if (iVar3 == -0x5ed90000) {
        iVar3 = puVar7[2];
        if ((undefined4 *)(iVar3 + 0x68) != &uStack_198) {
          *(undefined4 *)(iVar3 + 0x68) = uVar1;
          *(undefined4 *)(iVar3 + 0x6c) = uVar2;
          *(undefined4 *)(iVar3 + 0x70) = uStack_190;
          if ((undefined4 *)(iVar3 + 0x74) != &uStack_18c) {
            *(undefined4 *)(iVar3 + 0x80) = uStack_180;
            *(undefined4 *)(iVar3 + 0x74) = uStack_18c;
            *(undefined4 *)(iVar3 + 0x78) = uStack_188;
            *(undefined4 *)(iVar3 + 0x7c) = uStack_184;
          }
          *(undefined4 *)(iVar3 + 0x84) = uStack_17c;
          *(undefined4 *)(iVar3 + 0x88) = uStack_178;
          *(undefined4 *)(iVar3 + 0x8c) = uStack_174;
          *(undefined4 *)(iVar3 + 0x90) = uStack_170;
        }
        *(undefined4 *)(iVar3 + 0xc0) = 0;
      }
      else if ((iVar3 != -0x5edc0000) && (iVar3 == -0x5edf0000)) {
        iVar3 = puVar7[2];
        if (*(int *)(iVar3 + 0xdc) - *(int *)(iVar3 + 0xd8) >> 2 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = **(int **)(iVar3 + 0xd8);
        }
        iVar6 = *(int *)(iVar3 + 0x74);
        FUN_0077ea00();
        *(undefined4 *)(iVar6 + 0xc0) = 0;
        FUN_00780150(iVar3,*(undefined4 *)(iVar3 + 0x30));
      }
      local_19c = local_19c + 0xc;
      local_16c = local_16c + 1;
    } while (local_16c < (uint)((*(int *)(param_1 + 0x9c) - *(int *)(param_1 + 0x98)) / 0xc));
  }
  return;
}

