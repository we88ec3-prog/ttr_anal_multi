
void FUN_007e5f70(undefined4 *param_1,int param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int unaff_ESI;
  uint uVar9;
  int local_20;
  undefined4 *local_1c;
  int local_18;
  int local_10;
  int local_c;
  undefined4 *local_8;
  
  uVar9 = param_2 * param_3;
  *(uint *)(unaff_ESI + 0x174) = uVar9;
  iVar6 = FUN_0087dc3d(-(uint)((int)((ulonglong)uVar9 * 0xc >> 0x20) != 0) |
                       (uint)((ulonglong)uVar9 * 0xc));
  if (iVar6 == 0) {
    iVar6 = 0;
  }
  else {
    iVar8 = uVar9 - 1;
    if (-1 < iVar8) {
      puVar7 = (undefined4 *)(iVar6 + 8);
      do {
        puVar7[-2] = 0;
        iVar8 = iVar8 + -1;
        puVar7[-1] = 0;
        *puVar7 = 0;
        puVar7 = puVar7 + 3;
      } while (-1 < iVar8);
    }
  }
  *(int *)(unaff_ESI + 0x16c) = iVar6;
  local_10 = 0;
  if (0 < param_3) {
    local_18 = 0;
    local_20 = 0;
    local_1c = param_1;
    do {
      local_c = 0;
      if (3 < param_2) {
        fVar5 = (float)local_10;
        local_8 = (undefined4 *)0x2;
        puVar7 = local_1c;
        iVar6 = local_20;
        do {
          fVar4 = (float)local_c;
          iVar8 = *(int *)(unaff_ESI + 0x16c);
          local_c = local_c + 4;
          fVar2 = *(float *)(unaff_ESI + 0x164);
          uVar3 = *puVar7;
          *(float *)(iVar8 + iVar6) = fVar4 * *(float *)(unaff_ESI + 0x160);
          *(float *)(iVar8 + 4 + iVar6) = fVar2 * fVar5;
          *(undefined4 *)(iVar8 + 8 + iVar6) = uVar3;
          pfVar1 = (float *)(iVar6 + 0xc + *(int *)(unaff_ESI + 0x16c));
          fVar2 = *(float *)(unaff_ESI + 0x164);
          fVar4 = (float)puVar7[1];
          *pfVar1 = (float)((int)local_8 + -1) * *(float *)(unaff_ESI + 0x160);
          pfVar1[1] = fVar2 * fVar5;
          pfVar1[2] = fVar4;
          pfVar1 = (float *)(iVar6 + 0x18 + *(int *)(unaff_ESI + 0x16c));
          fVar2 = *(float *)(unaff_ESI + 0x164);
          fVar4 = (float)puVar7[2];
          *pfVar1 = (float)(int)local_8 * *(float *)(unaff_ESI + 0x160);
          pfVar1[1] = fVar2 * fVar5;
          pfVar1[2] = fVar4;
          iVar8 = (int)local_8 + 1;
          local_8 = (undefined4 *)((int)local_8 + 4);
          pfVar1 = (float *)(iVar6 + 0x24 + *(int *)(unaff_ESI + 0x16c));
          iVar6 = iVar6 + 0x30;
          fVar2 = *(float *)(unaff_ESI + 0x164);
          fVar4 = (float)puVar7[3];
          *pfVar1 = (float)iVar8 * *(float *)(unaff_ESI + 0x160);
          pfVar1[1] = fVar2 * fVar5;
          pfVar1[2] = fVar4;
          puVar7 = puVar7 + 4;
        } while (local_c < param_2 + -3);
      }
      if (local_c < param_2) {
        iVar6 = (local_18 + local_c) * 0xc;
        local_8 = param_1 + local_18 + local_c;
        do {
          fVar2 = (float)local_c;
          iVar8 = *(int *)(unaff_ESI + 0x16c);
          local_c = local_c + 1;
          iVar6 = iVar6 + 0xc;
          fVar5 = *(float *)(unaff_ESI + 0x164);
          uVar3 = *local_8;
          *(float *)(iVar8 + -0xc + iVar6) = fVar2 * *(float *)(unaff_ESI + 0x160);
          *(float *)(iVar8 + -8 + iVar6) = fVar5 * (float)local_10;
          *(undefined4 *)(iVar8 + -4 + iVar6) = uVar3;
          local_8 = local_8 + 1;
        } while (local_c < param_2);
      }
      local_20 = local_20 + param_2 * 0xc;
      local_18 = local_18 + param_2;
      local_1c = local_1c + param_2;
      local_10 = local_10 + 1;
    } while (local_10 < param_3);
  }
  *(int *)(unaff_ESI + 0x154) = param_3 + -1;
  *(int *)(unaff_ESI + 0x150) = param_2 + -1;
  *(int *)(unaff_ESI + 0x17c) = (param_3 + -1) * (param_2 + -1) * 2;
  return;
}

