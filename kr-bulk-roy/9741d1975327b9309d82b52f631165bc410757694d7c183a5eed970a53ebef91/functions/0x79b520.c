
void FUN_0079b520(int param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  uint local_14;
  uint local_c;
  int local_8;
  
  iVar5 = param_1;
  piVar3 = (int *)FUN_0079a5f0(param_1);
  iVar6 = 0;
  do {
    (**(code **)(*piVar3 + 0xd4))(piVar3,iVar6,0);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 8);
  switch(param_2) {
  case 2:
    uVar4 = *(int *)(param_1 + 0x2d0) - *(int *)(param_1 + 0x2cc) >> 7;
    param_1 = 0;
    local_c = 0;
    if (uVar4 != 0) {
      local_8 = 0;
      while (param_1 < 8) {
        piVar7 = (int *)(*(int *)(iVar5 + 0x2cc) + local_8);
        if (piVar7[0x1e] != 0) {
          if ((((*(int *)(iVar5 + 0x3c) == 0) ||
               (iVar6 = FUN_00838860(piVar7[0xd],piVar7[0xe],piVar7[0xf],piVar7[0x13]), iVar6 != 0))
              || (*piVar7 == 3)) && (piVar7[0x1d] != 0)) {
            (**(code **)(*piVar3 + 0xd4))(piVar3,param_1,1);
            (**(code **)(*piVar3 + 0xcc))(piVar3,param_1,piVar7);
            param_1 = param_1 + 1;
          }
        }
        local_8 = local_8 + 0x80;
        local_c = local_c + 1;
        if (uVar4 <= local_c) {
          return;
        }
      }
    }
    break;
  case 3:
    uVar4 = *(int *)(param_1 + 0x2d0) - *(int *)(param_1 + 0x2cc) >> 7;
    param_1 = 0;
    local_c = 0;
    if (uVar4 != 0) {
      local_8 = 0;
      while (param_1 < 8) {
        piVar7 = (int *)(*(int *)(iVar5 + 0x2cc) + local_8);
        if (piVar7[0x1e] != 0) {
          if ((((*(int *)(iVar5 + 0x3c) == 0) ||
               (iVar6 = FUN_00838860(piVar7[0xd],piVar7[0xe],piVar7[0xf],piVar7[0x13]), iVar6 != 0))
              || (*piVar7 == 3)) && (piVar7[0x1c] != 0)) {
            (**(code **)(*piVar3 + 0xd4))(piVar3,param_1,1);
            (**(code **)(*piVar3 + 0xcc))(piVar3,param_1,piVar7);
            param_1 = param_1 + 1;
          }
        }
        local_8 = local_8 + 0x80;
        local_c = local_c + 1;
        if (uVar4 <= local_c) {
          return;
        }
      }
    }
    break;
  case 4:
    uVar4 = *(int *)(param_1 + 0x2d0) - *(int *)(param_1 + 0x2cc) >> 7;
    param_1 = 0;
    local_c = 0;
    if (uVar4 != 0) {
      local_8 = 0;
      while (param_1 < 8) {
        piVar7 = (int *)(*(int *)(iVar5 + 0x2cc) + local_8);
        if (piVar7[0x1e] != 0) {
          if ((((*(int *)(iVar5 + 0x3c) == 0) ||
               (iVar6 = FUN_00838860(piVar7[0xd],piVar7[0xe],piVar7[0xf],piVar7[0x13]), iVar6 != 0))
              || (*piVar7 == 3)) && (piVar7[0x1b] != 0)) {
            (**(code **)(*piVar3 + 0xd4))(piVar3,param_1,1);
            (**(code **)(*piVar3 + 0xcc))(piVar3,param_1,piVar7);
            param_1 = param_1 + 1;
          }
        }
        local_8 = local_8 + 0x80;
        local_c = local_c + 1;
        if (uVar4 <= local_c) {
          return;
        }
      }
    }
    break;
  case 5:
    uVar4 = *(int *)(param_1 + 0x2d0) - *(int *)(param_1 + 0x2cc) >> 7;
    param_2 = 0;
    bVar2 = false;
    local_14 = 0;
    if (uVar4 != 0) {
      local_8 = 0;
      do {
        if (7 < param_2) {
          return;
        }
        piVar7 = (int *)(*(int *)(param_1 + 0x2cc) + local_8);
        if (piVar7[0x1e] != 0) {
          if ((((*(int *)(param_1 + 0x3c) == 0) ||
               (iVar5 = FUN_00838860(piVar7[0xd],piVar7[0xe],piVar7[0xf],piVar7[0x13]), iVar5 != 0))
              || (*piVar7 == 3)) && (piVar7[0x1a] != 0)) {
            (**(code **)(*piVar3 + 0xd4))(piVar3,param_2,1);
            (**(code **)(*piVar3 + 0xcc))(piVar3,param_2,piVar7);
            param_2 = param_2 + 1;
            if ((!bVar2) && (*piVar7 == 3)) {
              bVar2 = true;
              piVar1 = *(int **)(param_1 + 0x9c);
              uVar9 = 0;
              uVar8 = piVar1[1] - *piVar1 >> 2;
              if (uVar8 != 0) {
                do {
                  (**(code **)(**(int **)(*piVar1 + uVar9 * 4) + 0x1c))(piVar7);
                  uVar9 = uVar9 + 1;
                } while (uVar9 < uVar8);
              }
            }
          }
        }
        local_8 = local_8 + 0x80;
        local_14 = local_14 + 1;
      } while (local_14 < uVar4);
    }
  }
  return;
}

