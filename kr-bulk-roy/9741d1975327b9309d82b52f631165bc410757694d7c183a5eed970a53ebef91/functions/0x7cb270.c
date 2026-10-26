
uint FUN_007cb270(undefined4 *param_1,int *param_2,undefined4 *param_3,float *param_4,
                 undefined4 param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  undefined4 *puVar9;
  int aiStack_108 [6];
  undefined4 uStack_f0;
  undefined4 auStack_ec [4];
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  int iStack_d4;
  undefined4 auStack_d0 [4];
  undefined4 uStack_c0;
  float *pfStack_bc;
  int iStack_b8;
  undefined4 *puStack_b4;
  uint uStack_b0;
  float *pfStack_ac;
  float *pfStack_a8;
  undefined4 uStack_a4;
  undefined4 *puStack_a0;
  float local_64 [11];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  float local_c;
  uint local_8;
  
  piVar6 = param_2;
  uVar7 = 0;
  local_10 = 1;
  if (param_3 == (undefined4 *)0x0) {
    param_3 = &local_38;
  }
  puVar5 = param_3;
  local_14 = 0x3f800000;
  local_18 = 0x3f800000;
  local_1c = 0x3f800000;
  local_20 = 0x3f800000;
  local_24 = 0;
  local_28 = 0;
  local_2c = 0;
  local_30 = 0;
  local_34 = 0;
  local_38 = 0;
  puStack_a0 = (undefined4 *)0x7cb2e8;
  iVar1 = (**(code **)(*param_2 + 4))();
  iVar1 = *(int *)(iVar1 + 4);
  if (iVar1 == -0x5eed0000) {
    uStack_a4 = 0x7cb51b;
    puStack_a0 = puVar5;
    uStack_a4 = FUN_0077ef30();
    pfStack_a8 = local_64;
    pfStack_ac = (float *)0x7cb525;
    FUN_0077e910();
    iVar1 = piVar6[0x37] - piVar6[0x36] >> 2;
    param_3 = (undefined4 *)0x0;
    if (0 < iVar1) {
      do {
        if (param_3 < (uint)(piVar6[0x37] - piVar6[0x36] >> 2)) {
          uStack_b0 = *(undefined4 *)(piVar6[0x36] + (int)param_3 * 4);
        }
        else {
          uStack_b0 = 0;
        }
        puStack_a0 = (undefined4 *)param_6;
        uStack_a4 = param_5;
        pfStack_a8 = param_4;
        pfStack_ac = local_64;
        puStack_b4 = param_1;
        iStack_b8 = 0x7cb590;
        uVar2 = FUN_007cb270();
        if (uVar7 < uVar2) {
          uVar7 = uVar2;
        }
        param_3 = (undefined4 *)((int)param_3 + 1);
      } while ((int)param_3 < iVar1);
    }
    puStack_a0 = (undefined4 *)0x7cb5ad;
    param_3 = (undefined4 *)(**(code **)(*piVar6 + 0x34))();
    uVar2 = 0;
    if (param_3 != (undefined4 *)0x0) {
      do {
        puStack_a0 = (undefined4 *)param_6;
        uStack_a4 = param_5;
        pfStack_a8 = param_4;
        pfStack_ac = local_64;
        puStack_b4 = (undefined4 *)0x7cb5d3;
        uStack_b0 = uVar2;
        uStack_b0 = (**(code **)(*piVar6 + 0x30))();
        puStack_b4 = param_1;
        iStack_b8 = 0x7cb5dd;
        uVar3 = FUN_007cb270();
        if (uVar7 < uVar3) {
          uVar7 = uVar3;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < param_3);
    }
    return uVar7;
  }
  if (iVar1 == -0x5edf0000) {
    local_c = 65535.0;
    param_2 = (int *)0x0;
    uVar7 = piVar6[0x1f] - piVar6[0x1e] >> 2;
    local_8 = 0;
    if (uVar7 != 0) {
      do {
        uStack_b0 = *(undefined4 *)(piVar6[0x1e] + local_8 * 4);
        puStack_a0 = (undefined4 *)param_6;
        uStack_a4 = param_5;
        pfStack_a8 = param_4;
        pfStack_ac = (float *)param_3;
        puStack_b4 = param_1;
        iStack_b8 = 0x7cb45f;
        uVar2 = FUN_007cb270();
        if (param_2 < uVar2) {
          param_2 = (int *)uVar2;
        }
        local_8 = local_8 + 1;
      } while (local_8 < uVar7);
    }
    puStack_b4 = (undefined4 *)*param_1;
    uStack_b0 = param_1[1];
    pfStack_ac = (float *)param_1[2];
    pfStack_a8 = (float *)param_1[3];
    uStack_a4 = param_1[4];
    puStack_a0 = (undefined4 *)param_1[5];
    iStack_b8 = param_6;
    pfStack_bc = &local_c;
    uStack_c0 = param_5;
    puVar5 = param_3;
    puVar9 = auStack_ec;
    for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    piVar6 = piVar6 + 0x15;
    piVar4 = aiStack_108;
    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar4 = *piVar6;
      piVar6 = piVar6 + 1;
      piVar4 = piVar4 + 1;
    }
    uVar7 = FUN_007c9890();
    if (param_2 < uVar7) {
      param_2 = (int *)uVar7;
    }
    if (param_6 == 0) {
      if (*param_4 <= local_c) {
        return (uint)param_2;
      }
    }
    else if (local_c <= *param_4) {
      return (uint)param_2;
    }
    *param_4 = local_c;
    return (uint)param_2;
  }
  if (iVar1 == -0x5edc0000) {
    if (param_6 == 0) {
      param_2 = (int *)0x477fff00;
    }
    else {
      param_2 = (int *)0x0;
    }
    puStack_b4 = (undefined4 *)*param_1;
    uStack_b0 = param_1[1];
    pfStack_ac = (float *)param_1[2];
    pfStack_a8 = (float *)param_1[3];
    uStack_a4 = param_1[4];
    puStack_a0 = (undefined4 *)param_1[5];
    iStack_b8 = param_6;
    pfStack_bc = (float *)&param_2;
    uStack_c0 = param_5;
    puVar9 = auStack_ec;
    for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    piVar4 = piVar6 + 0x15;
    piVar8 = aiStack_108;
    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar8 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar8 = piVar8 + 1;
    }
    iVar1 = FUN_007c9890();
    if (param_6 == 0) {
      param_2 = (int *)0x477fff00;
    }
    else {
      param_2 = (int *)0x0;
    }
    uVar7 = 0;
    if (iVar1 != 0) {
      iStack_d4 = piVar6[0x1e];
      puStack_a0 = (undefined4 *)param_6;
      uStack_a4 = param_5;
      puVar5 = param_3;
      puVar9 = auStack_d0;
      for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar9 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar9 = puVar9 + 1;
      }
      auStack_ec[0] = *param_1;
      auStack_ec[1] = param_1[1];
      auStack_ec[2] = param_1[2];
      auStack_ec[3] = param_1[3];
      uStack_dc = param_1[4];
      uStack_d8 = param_1[5];
      uStack_f0 = 0x7cb3e5;
      uVar7 = FUN_007c8460();
    }
    if (param_6 == 0) {
      if (*param_4 <= (float)param_2) {
        return uVar7;
      }
    }
    else if ((float)param_2 <= *param_4) {
      return uVar7;
    }
    *param_4 = (float)param_2;
    return uVar7;
  }
  return 0;
}

