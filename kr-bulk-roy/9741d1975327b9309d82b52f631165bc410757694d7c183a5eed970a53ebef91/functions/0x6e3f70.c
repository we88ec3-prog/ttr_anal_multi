
float10 FUN_006e3f70(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  float local_8;
  
  local_8 = 0.0;
  if (*param_1 == *param_2) {
    local_8 = 1000.0;
  }
  if (param_1[1] == param_2[1]) {
    local_8 = local_8 + 100.0;
  }
  if (param_1[1] == 1) {
    local_8 = local_8 + 0.1;
  }
  if (param_1[4] == param_2[0xc]) {
    local_8 = local_8 + 10.0;
  }
  iVar1 = param_1[2];
  if (iVar1 == param_2[2]) {
    local_8 = local_8 + 1.0;
  }
  else {
    switch(iVar1) {
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x20:
      iVar7 = 8;
      break;
    case 0x17:
    case 0x18:
    case 0x19:
      iVar7 = 5;
      break;
    case 0x1a:
    case 0x1e:
      iVar7 = 4;
      break;
    case 0x1b:
    case 0x1d:
      iVar7 = 2;
      break;
    default:
      iVar7 = 0;
      break;
    case 0x1f:
    case 0x23:
      iVar7 = 10;
      break;
    case 0x24:
      iVar7 = 0x10;
    }
    switch(param_2[2]) {
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x20:
      iVar8 = 8;
      break;
    case 0x17:
    case 0x18:
    case 0x19:
      iVar8 = 5;
      break;
    case 0x1a:
    case 0x1e:
      iVar8 = 4;
      break;
    case 0x1b:
    case 0x1d:
      iVar8 = 2;
      break;
    default:
      iVar8 = 0;
      break;
    case 0x1f:
    case 0x23:
      iVar8 = 10;
      break;
    case 0x24:
      iVar8 = 0x10;
    }
    uVar6 = iVar7 - iVar8 >> 0x1f;
    fVar2 = 0.9 - (float)(int)((iVar7 - iVar8 ^ uVar6) - uVar6) * 0.2;
    if (fVar2 <= 0.0) {
      fVar2 = 0.0;
    }
    local_8 = fVar2 + local_8;
  }
  if (param_1[4] == 0) {
    switch(*(int *)(param_3 + 0xc)) {
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x1f:
    case 0x20:
    case 0x23:
    case 0x24:
      bVar9 = iVar1 == *(int *)(param_3 + 0xc);
      break;
    default:
      bVar9 = iVar1 == 0x16;
    }
    if (bVar9) {
      local_8 = local_8 + 0.1;
    }
  }
  if (((param_2[3] & 0xc0U) != 0) && ((*(uint *)(param_1[0x15] + 0x24) & 0x10000) != 0)) {
    local_8 = local_8 + 1.0;
  }
  if ((*(uint *)(param_1[0x15] + 0x24) & 0x10000) != 0) {
    local_8 = local_8 + 0.1;
  }
  iVar7 = *(int *)(param_1[0x14] + 0x654);
  bVar9 = false;
  if (0 < iVar7) {
    piVar3 = *(int **)(param_1[0x14] + 0x650);
    iVar8 = iVar7;
    do {
      if (((piVar3[3] == iVar1) && (*piVar3 == param_2[4])) && (piVar3[1] == param_2[5])) {
        bVar9 = true;
      }
      piVar3 = piVar3 + 4;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    if (bVar9) {
      local_8 = local_8 + 1.0;
    }
  }
  iVar8 = param_1[3];
  if (iVar8 == param_2[6]) {
    local_8 = local_8 + 1.0;
  }
  else {
    switch(iVar8) {
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x20:
      iVar4 = 8;
      break;
    case 0x17:
    case 0x18:
    case 0x19:
      iVar4 = 5;
      break;
    case 0x1a:
    case 0x1e:
      iVar4 = 4;
      break;
    case 0x1b:
    case 0x1d:
      iVar4 = 2;
      break;
    default:
      iVar4 = 0;
      break;
    case 0x1f:
    case 0x23:
      iVar4 = 10;
      break;
    case 0x24:
      iVar4 = 0x10;
    }
    switch(param_2[6]) {
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x20:
      iVar5 = 8;
      break;
    case 0x17:
    case 0x18:
    case 0x19:
      iVar5 = 5;
      break;
    case 0x1a:
    case 0x1e:
      iVar5 = 4;
      break;
    case 0x1b:
    case 0x1d:
      iVar5 = 2;
      break;
    default:
      iVar5 = 0;
      break;
    case 0x1f:
    case 0x23:
      iVar5 = 10;
      break;
    case 0x24:
      iVar5 = 0x10;
    }
    uVar6 = iVar4 - iVar5 >> 0x1f;
    fVar2 = 0.9 - (float)(int)((iVar4 - iVar5 ^ uVar6) - uVar6) * 0.2;
    if (fVar2 <= 0.0) {
      fVar2 = 0.0;
    }
    local_8 = fVar2 + local_8;
  }
  if (iVar8 == iVar1) {
    local_8 = local_8 + 0.1;
  }
  iVar8 = 0;
  if (0 < param_1[9]) {
    do {
      if ((*(int *)(param_1[8] + iVar8 * 4) == param_2[8]) &&
         ((uint)param_2[9] <= *(uint *)(param_1[0xb] + iVar8 * 4))) {
        local_8 = local_8 + 1.0;
        break;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < param_1[9]);
  }
  iVar8 = param_1[6];
  if (((0 < iVar8) && (0 < iVar8)) && (-1 < iVar8)) {
    piVar3 = (int *)param_1[5];
    iVar4 = 0;
    do {
      if (param_2[0xe] == *piVar3) {
        if (iVar4 != -1) {
          local_8 = local_8 + 1.0;
        }
        break;
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar4 < iVar8);
  }
  bVar9 = false;
  if (0 < iVar7) {
    iVar8 = *(int *)(param_1[0x14] + 0x650);
    do {
      if ((*(int *)(iVar8 + 0xc) == iVar1) && (*(int *)(iVar8 + 8) == param_2[0x10])) {
        bVar9 = true;
      }
      iVar8 = iVar8 + 0x10;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    if (bVar9) {
      local_8 = local_8 + 1.0;
    }
  }
  iVar1 = param_1[0xf];
  if (((0 < iVar1) && (0 < iVar1)) && (-1 < iVar1)) {
    piVar3 = (int *)param_1[0xe];
    iVar7 = 0;
    do {
      if (param_2[0x11] == *piVar3) {
        if (iVar7 != -1) {
          return (float10)(local_8 + 1.0);
        }
        break;
      }
      iVar7 = iVar7 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar7 < iVar1);
  }
  return (float10)local_8;
}

