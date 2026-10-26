
undefined4 FUN_006e3c10(int *param_1,int *param_2,int *param_3)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  
  if ((((((*param_3 == 1) && (*param_1 != *param_2)) ||
        ((param_3[1] == 1 && (param_1[1] != param_2[1])))) ||
       ((param_3[2] == 1 && (param_1[4] != param_2[0xc])))) ||
      ((param_3[3] == 1 && (param_1[2] != param_2[2])))) ||
     (((param_3[4] == 1 && ((*(byte *)(param_2 + 3) & 0x40) != 0)) &&
      ((*(uint *)(param_1[0x15] + 0x24) & 0x10000) == 0)))) {
    return 0;
  }
  if (param_3[5] == 1) {
    iVar4 = *(int *)(param_1[0x14] + 0x654);
    iVar5 = 0;
    if (0 < iVar4) {
      piVar3 = *(int **)(param_1[0x14] + 0x650);
      do {
        if (((piVar3[3] == param_1[2]) && (*piVar3 == param_2[4])) && (piVar3[1] == param_2[5]))
        goto LAB_006e3cd2;
        iVar5 = iVar5 + 1;
        piVar3 = piVar3 + 4;
      } while (iVar5 < iVar4);
    }
    return 0;
  }
LAB_006e3cd2:
  if ((param_3[6] == 1) && (param_1[3] != param_2[6])) {
    return 0;
  }
  if (param_3[8] == 1) {
    iVar4 = 0;
    if (0 < param_1[9]) {
      do {
        if ((*(int *)(param_1[8] + iVar4 * 4) == param_2[8]) &&
           ((uint)param_2[9] <= *(uint *)(param_1[0xb] + iVar4 * 4))) goto LAB_006e3d24;
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_1[9]);
    }
    return 0;
  }
LAB_006e3d24:
  if (param_3[10] == 1) {
    if (((param_3[0xb] == 1) && (param_2[0xe] != 0)) &&
       (cVar2 = FUN_006eac90(param_2 + 0xe), cVar2 == '\0')) {
      return 0;
    }
    if (param_2[0xe] != 0) {
      bVar1 = false;
      iVar5 = FUN_006ec980();
      iVar4 = param_1[6];
      if (iVar4 < 1) {
        return 0;
      }
      puVar7 = (undefined4 *)param_1[5];
      do {
        switch(*puVar7) {
        case 0x46:
        case 0x50:
          iVar6 = 0x10;
          break;
        case 0x47:
        case 0x52:
          iVar6 = 0x20;
          break;
        default:
          iVar6 = 0;
          break;
        case 0x49:
          iVar6 = 0xf;
          break;
        case 0x4b:
        case 0x4d:
        case 0x4f:
        case 0x53:
          iVar6 = 0x18;
        }
        if (iVar6 == iVar5) {
          bVar1 = true;
        }
        puVar7 = puVar7 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      if (!bVar1) {
        return 0;
      }
    }
  }
  if ((param_3[0xb] == 1) && (param_2[0xe] != 0)) {
    bVar1 = false;
    switch(param_2[0xe]) {
    default:
      iVar4 = 0;
      break;
    case 0x49:
      iVar4 = 1;
      break;
    case 0x4b:
    case 0x53:
      iVar4 = 8;
      break;
    case 0x4f:
      iVar4 = 4;
    }
    iVar5 = param_1[6];
    if (iVar5 < 1) {
      return 0;
    }
    puVar7 = (undefined4 *)param_1[5];
    do {
      switch(*puVar7) {
      default:
        iVar6 = 0;
        break;
      case 0x49:
        iVar6 = 1;
        break;
      case 0x4b:
      case 0x53:
        iVar6 = 8;
        break;
      case 0x4f:
        iVar6 = 4;
      }
      if (iVar6 == iVar4) {
        bVar1 = true;
      }
      puVar7 = puVar7 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    if (!bVar1) {
      return 0;
    }
  }
  if (param_3[0xd] == 1) {
    iVar4 = *(int *)(param_1[0x14] + 0x654);
    iVar5 = 0;
    if (0 < iVar4) {
      iVar6 = *(int *)(param_1[0x14] + 0x650);
      do {
        if ((*(int *)(iVar6 + 0xc) == param_1[2]) && (*(int *)(iVar6 + 8) == param_2[0x10]))
        goto LAB_006e3eb2;
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 0x10;
      } while (iVar5 < iVar4);
    }
  }
  else {
LAB_006e3eb2:
    if (param_3[0xe] != 1) {
      return 1;
    }
    iVar4 = param_1[0xf];
    if (((0 < iVar4) && (0 < iVar4)) && (-1 < iVar4)) {
      piVar3 = (int *)param_1[0xe];
      iVar5 = 0;
      while (param_2[0x11] != *piVar3) {
        iVar5 = iVar5 + 1;
        piVar3 = piVar3 + 1;
        if (iVar4 <= iVar5) {
          return 0;
        }
      }
      if (iVar5 != -1) {
        return 1;
      }
    }
  }
  return 0;
}

