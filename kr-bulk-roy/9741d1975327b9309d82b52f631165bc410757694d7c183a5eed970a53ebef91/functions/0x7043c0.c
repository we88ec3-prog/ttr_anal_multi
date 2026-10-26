
void FUN_007043c0(int param_1)

{
  int iVar1;
  int iVar2;
  double *pdVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint uVar7;
  undefined1 auStack_144 [4];
  int local_140;
  int local_13c;
  int local_138 [2];
  double local_130;
  undefined4 local_128;
  int local_120;
  uint local_11c;
  int local_118;
  undefined4 local_114;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_144;
  local_13c = FUN_006f53f0(0xffffd8ed,local_138);
  iVar2 = **(int **)(*(int *)(param_1 + 0x14) + 4);
  if (*(byte *)(iVar2 + 7) < 2) {
    piVar6 = &DAT_00c0bfc8;
  }
  else {
    piVar6 = (int *)(iVar2 + 0x28);
  }
  if (piVar6[2] == 4) {
LAB_00704451:
    local_140 = *piVar6 + 0x10;
  }
  else {
    iVar2 = FUN_006fb5d0();
    if (iVar2 != 0) {
      if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44))
      {
        FUN_006fb3a0();
      }
      iVar2 = **(int **)(*(int *)(param_1 + 0x14) + 4);
      if (*(byte *)(iVar2 + 7) < 2) {
        piVar6 = &DAT_00c0bfc8;
      }
      else {
        piVar6 = (int *)(iVar2 + 0x28);
      }
      goto LAB_00704451;
    }
    local_140 = 0;
  }
  local_11c = local_138[0] + local_13c;
  local_120 = local_13c;
  local_118 = param_1;
  pdVar3 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar3 + 1) == 3) {
LAB_007044b3:
    local_130 = *pdVar3;
    iVar2 = (int)ROUND(local_130);
    local_138[0] = iVar2;
  }
  else {
    if (*(int *)(pdVar3 + 1) == 4) {
      iVar2 = FUN_006f7760();
      if (iVar2 != 0) {
        local_128 = 3;
        pdVar3 = &local_130;
        goto LAB_007044b3;
      }
    }
    iVar2 = 0;
  }
  uVar7 = iVar2 + local_13c;
  if (uVar7 <= local_11c) {
    do {
      local_114 = 0;
      uVar4 = FUN_00703c30(&local_120,uVar7,local_140);
      if (uVar4 != 0) {
        local_140 = uVar4 - local_13c;
        if (uVar4 == uVar7) {
          local_140 = local_140 + 1;
        }
        pdVar3 = *(double **)(param_1 + 8);
        *(undefined4 *)(pdVar3 + 1) = 3;
        *pdVar3 = (double)local_140;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        iVar2 = **(int **)(*(int *)(param_1 + 0x14) + 4);
        iVar1 = *(int *)(param_1 + 8);
        if (*(byte *)(iVar2 + 7) < 3) {
          puVar5 = &DAT_00c0bfc8;
        }
        else {
          puVar5 = (undefined4 *)(iVar2 + 0x38);
        }
        *puVar5 = *(undefined4 *)(iVar1 + -0x10);
        puVar5[1] = *(undefined4 *)(iVar1 + -0xc);
        puVar5[2] = *(undefined4 *)(iVar1 + -8);
        if (((3 < *(int *)(*(int *)(param_1 + 8) + -8)) &&
            (iVar2 = *(int *)(*(int *)(param_1 + 8) + -0x10), (*(byte *)(iVar2 + 5) & 3) != 0)) &&
           ((*(byte *)(**(int **)(*(int *)(param_1 + 0x14) + 4) + 5) & 4) != 0)) {
          FUN_006fb5a0(iVar2);
        }
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
        FUN_007040b0(&local_120,uVar7,uVar4);
        __security_check_cookie(local_c ^ (uint)auStack_144);
        return;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 <= local_11c);
  }
  __security_check_cookie(local_c ^ (uint)auStack_144);
  return;
}

