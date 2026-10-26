
void FUN_00406050(int param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint local_3c;
  uint local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092b6a4;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00faaf34 & 1) == 0) {
    DAT_00faaf34 = DAT_00faaf34 | 1;
    local_8 = 0;
    FUN_004073c0(uVar5);
    _atexit((_func_4879 *)&LAB_00bcccd0);
  }
  local_8 = 0xffffffff;
  uVar12 = 0;
  do {
    (**(code **)(**(int **)(param_1 + ((uVar12 / 7 + 0x11) * 7 + uVar12 % 7) * 4) + 0x94))(0);
    (**(code **)(**(int **)(param_1 + ((uVar12 / 7 + 0xd) * 7 + uVar12 % 7) * 4) + 0x19c))
              (0xffffffff);
    uVar12 = uVar12 + 1;
  } while ((int)uVar12 < 0x1c);
  if (DAT_00faaf54 == 0) {
    iVar10 = 0;
    do {
      (**(code **)(**(int **)(param_1 + iVar10 * 4 + 0x16c) + 0x19c))(0xffffffff);
      iVar10 = iVar10 + 1;
    } while (iVar10 < 0x1c);
  }
  else {
    piVar9 = (int *)*DAT_00faaf50;
    if (piVar9 != DAT_00faaf50) {
      do {
        iVar10 = piVar9[4];
        iVar6 = (int)(short)(((short)(ushort)*(byte *)(piVar9 + 3) + -1) / 7);
        iVar8 = (int)(short)(((short)(ushort)*(byte *)(piVar9 + 3) + -1) % 7);
        (**(code **)(**(int **)(param_1 + ((iVar6 + 0x11) * 7 + iVar8) * 4) + 0x94))(1);
        uVar7 = FUN_004068f0();
        local_8 = 1;
        FUN_00757800(uVar7);
        local_8 = 0xffffffff;
        if (7 < local_1c) {
          FUN_0089120c(local_30);
        }
        local_30 = local_30 & 0xffff0000;
        local_1c = 7;
        (**(code **)(**(int **)(param_1 + ((iVar6 + 0xd) * 7 + iVar8) * 4) + 0x19c))(iVar10);
        if (*(char *)((int)piVar9 + 0x19) == '\0') {
          piVar3 = (int *)piVar9[2];
          if (*(char *)((int)piVar3 + 0x19) == '\0') {
            cVar2 = *(char *)(*piVar3 + 0x19);
            piVar9 = piVar3;
            piVar3 = (int *)*piVar3;
            while (cVar2 == '\0') {
              cVar2 = *(char *)(*piVar3 + 0x19);
              piVar9 = piVar3;
              piVar3 = (int *)*piVar3;
            }
          }
          else {
            cVar2 = *(char *)(piVar9[1] + 0x19);
            piVar4 = (int *)piVar9[1];
            piVar3 = piVar9;
            while ((piVar9 = piVar4, cVar2 == '\0' && (piVar3 == (int *)piVar9[2]))) {
              cVar2 = *(char *)(piVar9[1] + 0x19);
              piVar4 = (int *)piVar9[1];
              piVar3 = piVar9;
            }
          }
        }
      } while (piVar9 != DAT_00faaf50);
      local_3c = 0;
      goto LAB_004062a3;
    }
  }
  local_3c = 0;
LAB_004062a3:
  do {
    uVar11 = local_3c / 7;
    uVar13 = local_3c % 7;
    piVar9 = (int *)(param_1 + ((uVar11 + 0xd) * 7 + uVar13) * 4);
    (**(code **)(**(int **)(*piVar9 + 0x260) + 0x94))(*(int *)(*piVar9 + 0x24c) == -1);
    puVar1 = (undefined4 *)(param_1 + ((uVar11 + 9) * 7 + uVar13) * 4);
    (**(code **)(*(int *)*puVar1 + 0x90))(0);
    (**(code **)(**(int **)(*piVar9 + 0x25c) + 0x90))(0);
    uVar12 = local_3c + 1;
    if (*(char *)(param_1 + 0x254 + uVar12) == '\0') {
      if ((DAT_00faaf34 & 1) == 0) {
        DAT_00faaf34 = DAT_00faaf34 | 1;
        local_8 = 2;
        FUN_004073c0();
        _atexit((_func_4879 *)&LAB_00bcccd0);
        local_8 = 0xffffffff;
      }
      if ((int)local_3c < (int)(uint)DAT_00faaf39) {
        (**(code **)(*(int *)*puVar1 + 0x90))(1);
        (**(code **)(**(int **)(*piVar9 + 0x25c) + 0x90))(1);
      }
      piVar9 = *(int **)(*piVar9 + 0x264);
    }
    else {
      (**(code **)(**(int **)(*piVar9 + 0x25c) + 0x90))(1);
      (**(code **)(**(int **)(*piVar9 + 0x264) + 0x94))(1);
      (**(code **)(*(int *)*puVar1 + 0x90))(1);
      piVar9 = *(int **)(param_1 + ((uVar11 + 0x11) * 7 + uVar13) * 4);
    }
    (**(code **)(*piVar9 + 0x94))(0);
    FUN_007597b0(0);
    local_3c = uVar12;
  } while ((int)uVar12 < 0x1c);
  ExceptionList = local_10;
  __security_check_cookie(uVar5 ^ (uint)&stack0xfffffffc);
  return;
}

