
undefined4 FUN_007c6880(int *param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  byte *pbVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  uint uVar9;
  bool bVar10;
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
  undefined1 auStack_e4 [132];
  undefined1 auStack_60 [44];
  undefined1 auStack_34 [48];
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (*(int *)(iVar2 + 4) == -0x5eed0000) {
    uStack_13c = 0;
    pbVar4 = (byte *)(param_1 + 2);
    uStack_138 = 0;
    uStack_114 = 1;
    uStack_134 = 0;
    uStack_130 = 0;
    uStack_12c = 0;
    uStack_128 = 0;
    uStack_124 = 0x3f800000;
    uStack_120 = 0x3f800000;
    uStack_11c = 0x3f800000;
    uStack_118 = 0x3f800000;
    pbVar8 = param_2;
    if (0xf < (uint)param_1[7]) {
      pbVar4 = *(byte **)pbVar4;
    }
    do {
      bVar1 = *pbVar4;
      bVar10 = bVar1 < *pbVar8;
      if (bVar1 != *pbVar8) {
LAB_007c6995:
        iVar2 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_007c699a;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar10 = bVar1 < pbVar8[1];
      if (bVar1 != pbVar8[1]) goto LAB_007c6995;
      pbVar4 = pbVar4 + 2;
      pbVar8 = pbVar8 + 2;
    } while (bVar1 != 0);
    iVar2 = 0;
LAB_007c699a:
    if (iVar2 == 0) {
      FUN_0077ef30();
      FUN_0077ea00();
      return 1;
    }
    uVar5 = (**(code **)(*param_1 + 0x34))();
    uVar9 = 0;
    if (uVar5 != 0) {
      do {
        uStack_13c = 0;
        uStack_138 = 0;
        uStack_134 = 0;
        uStack_130 = 0;
        uStack_12c = 0;
        uStack_128 = 0;
        uStack_124 = 0x3f800000;
        uStack_120 = 0x3f800000;
        uStack_11c = 0x3f800000;
        uStack_118 = 0x3f800000;
        uVar6 = (**(code **)(*param_1 + 0x30))(uVar9,param_2,&uStack_13c);
        iVar2 = FUN_007c6880(uVar6);
        if (iVar2 != 0) {
          uVar6 = FUN_0077ef30();
          FUN_0077e910(auStack_e4,&uStack_13c,uVar6);
          FUN_0077ea00();
          return 1;
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < uVar5);
    }
    uVar9 = 0;
    uVar5 = param_1[0x37] - param_1[0x36] >> 2;
    if (uVar5 != 0) {
      do {
        uStack_13c = 0;
        uStack_138 = 0;
        uStack_134 = 0;
        uStack_130 = 0;
        uStack_12c = 0;
        uStack_128 = 0;
        uStack_124 = 0x3f800000;
        uStack_120 = 0x3f800000;
        uStack_11c = 0x3f800000;
        uStack_118 = 0x3f800000;
        if (uVar9 < (uint)(param_1[0x37] - param_1[0x36] >> 2)) {
          uVar6 = *(undefined4 *)(param_1[0x36] + uVar9 * 4);
        }
        else {
          uVar6 = 0;
        }
        iVar2 = FUN_007c6880(uVar6,param_2,&uStack_13c);
        if (iVar2 != 0) {
          uVar6 = FUN_0077ef30();
          puVar7 = (undefined4 *)FUN_0077e910(auStack_34,&uStack_13c,uVar6);
          if (param_3 != puVar7) {
            *param_3 = *puVar7;
            param_3[1] = puVar7[1];
            param_3[2] = puVar7[2];
            if (param_3 + 3 != puVar7 + 3) {
              param_3[6] = puVar7[6];
              param_3[3] = puVar7[3];
              param_3[4] = puVar7[4];
              param_3[5] = puVar7[5];
            }
            param_3[7] = puVar7[7];
            param_3[8] = puVar7[8];
            param_3[9] = puVar7[9];
            param_3[10] = puVar7[10];
          }
          return 1;
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < uVar5);
    }
  }
  else if (*(int *)(iVar2 + 4) == -0x5edf0000) {
    uStack_13c = 0;
    uStack_138 = 0;
    uStack_134 = 0;
    uStack_114 = 1;
    uStack_130 = 0;
    uStack_12c = 0;
    uStack_128 = 0;
    uStack_124 = 0x3f800000;
    uStack_120 = 0x3f800000;
    uStack_11c = 0x3f800000;
    uStack_118 = 0x3f800000;
    piVar3 = (int *)FUN_00872500(param_2);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(auStack_60);
      FUN_0077ea00();
      FUN_0077ea00();
      return 1;
    }
  }
  return 0;
}

