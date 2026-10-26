
void FUN_00619150(byte param_1)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  undefined4 **ppuVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  int in_EDX;
  uint *puVar9;
  undefined4 *puVar10;
  int *piVar11;
  int iVar12;
  undefined4 *puVar13;
  int iStack_6c;
  int local_68;
  int *local_64;
  undefined4 *local_60;
  undefined4 *local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  int local_4c;
  undefined4 local_48;
  uint local_40;
  undefined4 local_3c;
  uint uStack_28;
  uint uStack_20;
  uint local_1c;
  void *pvStack_18;
  void *local_14;
  int iStack_10;
  int local_c;
  
  iStack_10._0_1_ = 0xd2;
  iStack_10._1_3_ = 0x93df;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_6c;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff88;
  ExceptionList = &local_14;
  *(byte *)(in_EDX + 0xfd) = param_1;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_c = 0;
  local_68 = in_EDX;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c._0_1_ = 1;
    local_c._1_3_ = 0;
    FUN_004e1590(uVar3);
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = (uint)local_c._1_3_ << 8;
  }
  local_54 = (uint)param_1;
  if (local_54 < 10) {
    uVar3 = DAT_00f94304 + local_54 * 0x210;
    uVar3 = -(uint)(*(int *)(uVar3 + 0x5c) != 0) & uVar3;
  }
  else {
    uVar3 = 0;
  }
  if (*(byte *)(local_68 + 0xfc) < 7) {
    local_64 = (int *)(uVar3 + 0x110 + (uint)*(byte *)(local_68 + 0xfc) * 0x1c);
  }
  else {
    local_64 = (int *)0x0;
  }
  iVar6 = *local_64;
  uVar4 = local_64[1] - iVar6 >> 3;
  local_58 = 0;
  uVar3 = 0;
  iVar12 = 0;
  puVar10 = DAT_00fb11b0;
  if (uVar4 != 0) {
    do {
      if (local_58 < uVar4) {
        puVar9 = (uint *)(iVar6 + local_58 * 8);
      }
      else {
        puVar9 = (uint *)0x0;
      }
      if ((DAT_00fb11a8 & 1) == 0) {
        DAT_00fb11a8 = DAT_00fb11a8 | 1;
        local_c._0_1_ = 2;
        FUN_00813890();
        _atexit((_func_4879 *)&LAB_00bccec0);
        local_c = (uint)local_c._1_3_ << 8;
        puVar10 = DAT_00fb11b0;
      }
      uVar3 = *puVar9;
      cVar1 = *(char *)((int)puVar10[1] + 0x15);
      puVar13 = (undefined4 *)puVar10[1];
      local_5c = puVar10;
      while (puVar7 = puVar13, cVar1 == '\0') {
        if ((uint)puVar7[3] < uVar3) {
          puVar13 = (undefined4 *)puVar7[2];
          puVar7 = local_5c;
        }
        else {
          puVar13 = (undefined4 *)*puVar7;
        }
        cVar1 = *(char *)((int)puVar13 + 0x15);
        local_5c = puVar7;
      }
      if ((local_5c == puVar10) || (uVar3 < (uint)local_5c[3])) {
        local_60 = puVar10;
        ppuVar5 = &local_60;
      }
      else {
        ppuVar5 = &local_5c;
      }
      if (((*ppuVar5 != puVar10) && (iVar6 = (*ppuVar5)[4], iVar6 != 0)) &&
         (*(int *)(iVar6 + 8) == 2)) {
        local_3c = CONCAT31(local_3c._1_3_,(char)puVar9[1]);
        local_40 = uVar3;
        FUN_004fc620();
        puVar10 = DAT_00fb11b0;
      }
      iVar6 = *local_64;
      local_58 = local_58 + 1;
      uVar4 = local_64[1] - iVar6 >> 3;
      uVar3 = local_50;
      iVar12 = local_4c;
    } while (local_58 < uVar4);
  }
  iVar6 = *(int *)(*(int *)(local_68 + 0xec) + 0xcc);
  puVar10 = (undefined4 *)((int)(iVar12 - uVar3) >> 3);
  local_5c = puVar10;
  if (iVar6 != 0) {
    FUN_00408920(iVar6,puVar10);
  }
  (**(code **)(**(int **)(local_68 + 0xf4) + 0x94))(puVar10 == (undefined4 *)0x0);
  puVar13 = (undefined4 *)0x0;
  if (puVar10 != (undefined4 *)0x0) {
    do {
      iVar12 = iStack_6c;
      iVar6 = *(int *)(*(int *)(iStack_6c + 0xec) + 0xcc);
      if (((iVar6 == 0) || ((int)puVar13 < 0)) ||
         (*(int *)(iVar6 + 0xac) - *(int *)(iVar6 + 0xa8) >> 2 <= (int)puVar13)) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(*(int *)(iVar6 + 0xa8) + (int)puVar13 * 4);
      }
      if (iVar6 != 0) {
        FUN_00618f30(*(undefined1 *)(uVar3 + 4 + (int)puVar13 * 8));
      }
      piVar2 = *(int **)(iVar12 + 0xec);
      piVar8 = (int *)piVar2[0x19];
      piVar11 = (int *)*piVar8;
      local_64 = piVar8;
      if (piVar11 != piVar8) {
        do {
          iVar6 = piVar11[2];
          if ((*(int *)(iVar6 + 0x60) != 0) && ((*(int **)(iVar6 + 0x1c))[2] != 6)) {
            (**(code **)(**(int **)(iVar6 + 0x1c) + 0x30))(iVar6);
            piVar8 = local_64;
          }
          piVar11 = (int *)*piVar11;
        } while (piVar11 != piVar8);
      }
      (**(code **)(*piVar2 + 0x128))();
      (**(code **)(**(int **)(iStack_6c + 0xec) + 200))();
      puVar13 = (undefined4 *)((int)puVar13 + 1);
      uVar3 = local_54;
    } while (puVar13 < local_60);
  }
  local_68 = 0;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    iStack_10._0_1_ = 3;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    iStack_10._0_1_ = 0;
  }
  if ((((-1 < (int)local_58) && ((int)local_58 < 10)) &&
      (iVar6 = local_58 * 0x210 + DAT_00f94304, *(int *)(iVar6 + 0x5c) != 0)) && (iVar6 != 0)) {
    local_68 = *(undefined4 *)(iVar6 + 0xd4);
  }
  FUN_00412df0();
  iStack_10._0_1_ = 4;
  FUN_00759ac0(0);
  iStack_10._0_1_ = 0;
  if (7 < uStack_28) {
    FUN_0089120c(local_3c);
  }
  FUN_00412df0();
  iStack_10._0_1_ = 5;
  FUN_00759ac0(1);
  iStack_10 = (uint)iStack_10._1_3_ << 8;
  if (7 < uStack_28) {
    FUN_0089120c(local_3c);
  }
  (**(code **)(**(int **)(iStack_6c + 0xf0) + 200))();
  if (local_54 != 0) {
    FUN_0089120c(local_54);
  }
  ExceptionList = pvStack_18;
  __security_check_cookie(uStack_20 ^ (uint)&stack0xffffff90);
  return;
}

