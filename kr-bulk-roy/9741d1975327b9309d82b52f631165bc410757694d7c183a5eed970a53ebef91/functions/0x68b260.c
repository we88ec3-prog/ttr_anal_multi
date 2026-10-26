
void FUN_0068b260(int *param_1)

{
  uint *puVar1;
  char cVar2;
  undefined1 uVar3;
  ushort uVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  bool bVar10;
  int *piVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  int iVar15;
  int *piVar16;
  uint *puVar17;
  uint local_68 [4];
  int *local_58;
  uint *local_54;
  uint local_50;
  int *local_4c;
  uint *local_48;
  uint *local_44;
  uint *local_40;
  uint *local_38;
  uint *local_34;
  undefined4 local_30;
  undefined1 local_28 [4];
  int *local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00942c8e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (param_1[0x33] == 0) {
    local_68[2] = 0;
  }
  else {
    local_68[2] = *(int *)(param_1[0x33] + 0xd4);
  }
  if (param_1[0x37] == 1) {
    local_48 = (uint *)0x0;
    local_44 = (uint *)0x0;
    local_40 = (uint *)0x0;
    local_38 = (uint *)0x0;
    local_34 = (uint *)0x0;
    local_30 = 0;
    local_c._1_3_ = 0;
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c._0_1_ = 2;
      local_c._1_3_ = 0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c._0_1_ = 1;
    FUN_00462570(DAT_00f9430c,&local_48);
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c._0_1_ = 3;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c._0_1_ = 1;
    }
    local_68[3] = DAT_00f94308;
    FUN_00419660(local_28,DAT_00f94308 + 0x10);
    local_c = CONCAT31(local_c._1_3_,4);
    piVar16 = (int *)*local_24;
    local_54 = (uint *)local_24;
    puVar13 = local_44;
    puVar14 = local_48;
    if (piVar16 != local_24) {
      do {
        if (*(int *)piVar16[4] != 0) {
          puVar1 = (uint *)(piVar16 + 3);
          if ((puVar1 < puVar13) && (puVar14 <= puVar1)) {
            iVar15 = (int)puVar1 - (int)puVar14;
            if (puVar13 == local_40) {
              FUN_00419600();
              puVar13 = local_44;
              puVar14 = local_48;
            }
            if (puVar13 != (uint *)0x0) {
              *(undefined2 *)puVar13 = *(undefined2 *)((int)puVar14 + (iVar15 >> 1) * 2);
            }
          }
          else {
            if (puVar13 == local_40) {
              FUN_00419600();
              puVar13 = local_44;
              puVar14 = local_48;
            }
            if (puVar13 != (uint *)0x0) {
              *(short *)puVar13 = (short)*puVar1;
            }
          }
          puVar13 = (uint *)((int)puVar13 + 2);
          local_44 = puVar13;
        }
        if (*(char *)((int)piVar16 + 0x15) == '\0') {
          piVar5 = (int *)piVar16[2];
          if (*(char *)((int)piVar5 + 0x15) == '\0') {
            cVar2 = *(char *)(*piVar5 + 0x15);
            piVar16 = piVar5;
            piVar5 = (int *)*piVar5;
            while (cVar2 == '\0') {
              cVar2 = *(char *)(*piVar5 + 0x15);
              piVar16 = piVar5;
              piVar5 = (int *)*piVar5;
            }
          }
          else {
            cVar2 = *(char *)(piVar16[1] + 0x15);
            piVar11 = (int *)piVar16[1];
            piVar5 = piVar16;
            while ((piVar16 = piVar11, cVar2 == '\0' && (piVar5 == (int *)piVar16[2]))) {
              cVar2 = *(char *)(piVar16[1] + 0x15);
              piVar11 = (int *)piVar16[1];
              piVar5 = piVar16;
            }
          }
        }
      } while ((uint *)piVar16 != local_54);
    }
    FUN_0068b930(&local_48);
    puVar1 = local_34;
    puVar13 = local_38;
    local_68[0] = (int)local_34 - (int)local_38 >> 1;
    if (param_1[0x33] != 0) {
      FUN_00408920(param_1[0x33],local_68[0]);
    }
    if (param_1[0x33] == 0) {
      local_58 = (int *)0x0;
    }
    else {
      local_58 = (int *)(param_1[0x33] + 0xa8);
    }
    local_54 = puVar13;
    puVar17 = puVar13;
    if (puVar13 != puVar1) {
      local_68[1] = 0;
      do {
        uVar6 = local_68[3];
        uVar4 = (ushort)*puVar13;
        piVar16 = *(int **)(local_68[1] + *local_58);
        local_54 = puVar13;
        if ((short)uVar4 < 10000) {
          local_50 = (uint)uVar4;
          FUN_004a4cc0(&local_50);
          if ((local_4c != *(int **)(uVar6 + 0x14)) && (local_4c[4] != 0)) {
            uVar3 = *(undefined1 *)(local_4c[4] + 0x10);
            iVar15 = (int)(short)uVar4;
            if ((piVar16[0x95] == 1) && (piVar16[0x92] == iVar15)) {
              bVar10 = false;
            }
            else {
              bVar10 = true;
            }
            piVar16[0x95] = 1;
            *(undefined1 *)(piVar16 + 0x93) = uVar3;
            goto LAB_0068b57d;
          }
          if ((piVar16[0x95] == 1) && (piVar16[0x92] == -1)) {
            bVar10 = false;
          }
          else {
            bVar10 = true;
          }
          piVar16[0x95] = 1;
          piVar16[0x92] = -1;
          *(undefined1 *)(piVar16 + 0x93) = 0;
        }
        else {
          iVar15 = (short)uVar4 + -10000;
          if ((piVar16[0x95] == 2) && (piVar16[0x92] == iVar15)) {
            bVar10 = false;
          }
          else {
            bVar10 = true;
          }
          piVar16[0x95] = 2;
          *(undefined1 *)(piVar16 + 0x93) = 0;
LAB_0068b57d:
          piVar16[0x92] = iVar15;
        }
        FUN_006be4b0(piVar16);
        if (bVar10) {
          (**(code **)(*piVar16 + 200))();
        }
        local_68[1] = local_68[1] + 4;
        puVar13 = (uint *)((int)local_54 + 2);
        puVar14 = local_48;
        puVar17 = local_38;
        local_54 = puVar13;
      } while (puVar13 != local_34);
    }
    local_c = CONCAT31(local_c._1_3_,5);
    FUN_005540c0(*local_24,local_24);
    FUN_0089120c(local_24);
    if (puVar17 != (uint *)0x0) {
      FUN_0089120c(puVar17);
    }
    local_c = 0xffffffff;
    if (puVar14 != (uint *)0x0) {
      FUN_0089120c(puVar14);
    }
  }
  else {
    iVar15 = FUN_0068b1e0(DAT_00d61f20 ^ (uint)&stack0xffffff88);
    if (iVar15 == 0) {
      local_68[0] = 0;
      if (param_1[0x33] != 0) {
        FUN_006438f0(param_1[0x33]);
      }
    }
    else {
      puVar13 = (uint *)0x0;
      local_38 = (uint *)0x0;
      local_34 = (uint *)0x0;
      local_30 = 0;
      local_48 = (uint *)0x0;
      local_44 = (uint *)0x0;
      local_40 = (uint *)0x0;
      local_c = 7;
      local_4c = *(int **)(iVar15 + 4);
      local_54 = (uint *)*local_4c;
      if (local_54 != (uint *)local_4c) {
        puVar14 = (uint *)0x0;
        do {
          local_68[0] = local_54[4] & 0xffffff;
          if ((local_68 < puVar13) && (puVar14 <= local_68)) {
            iVar15 = (int)local_68 - (int)puVar14;
            if (puVar13 == local_40) {
              FUN_0068c010();
              puVar14 = local_48;
              puVar13 = local_44;
            }
            if (puVar13 != (uint *)0x0) {
              *puVar13 = puVar14[iVar15 >> 2];
            }
          }
          else {
            if (puVar13 == local_40) {
              FUN_0068c010();
              puVar14 = local_48;
              puVar13 = local_44;
            }
            if (puVar13 != (uint *)0x0) {
              *puVar13 = local_68[0];
            }
          }
          puVar13 = puVar13 + 1;
          local_44 = puVar13;
          FUN_0049e6a0();
        } while (local_54 != (uint *)local_4c);
      }
      FUN_0068bca0(&local_48);
      puVar14 = local_34;
      puVar13 = local_38;
      local_68[0] = (int)local_34 - (int)local_38 >> 2;
      if (param_1[0x33] != 0) {
        FUN_00408920(param_1[0x33],local_68[0]);
      }
      if (param_1[0x33] == 0) {
        local_54 = (uint *)0x0;
      }
      else {
        local_54 = (uint *)(param_1[0x33] + 0xa8);
      }
      if (puVar13 != puVar14) {
        local_68[1] = 0;
        do {
          uVar6 = *puVar13;
          piVar16 = *(int **)(local_68[1] + *local_54);
          uVar12 = uVar6 & 0xffff;
          if ((piVar16[0x95] == 0) && (piVar16[0x92] == uVar12)) {
            bVar10 = false;
          }
          else {
            bVar10 = true;
          }
          piVar16[0x95] = 0;
          if (uVar12 == 0) {
            uVar12 = 0xffffffff;
          }
          piVar16[0x92] = uVar12;
          *(char *)(piVar16 + 0x93) = (char)(uVar6 >> 0x10);
          FUN_006be4b0(piVar16);
          if (bVar10) {
            (**(code **)(*piVar16 + 200))();
          }
          local_68[1] = local_68[1] + 4;
          puVar13 = puVar13 + 1;
        } while (puVar13 != local_34);
      }
      if (local_48 != (uint *)0x0) {
        FUN_0089120c(local_48);
      }
      local_c = 0xffffffff;
      if (local_38 != (uint *)0x0) {
        FUN_0089120c(local_38);
      }
    }
  }
  uVar6 = local_68[2];
  if (local_68[0] != param_1[0x3a]) {
    iVar15 = (int)(local_68[0] - 1) / 10;
    iVar9 = (int)(param_1[0x3a] - 1U) / 10;
    if (iVar9 < iVar15) {
      FUN_00749d00();
      param_1[3] = param_1[3] + -uVar6;
      param_1[5] = param_1[5] + -uVar6;
      param_1[0xb] = param_1[2];
      param_1[0xc] = param_1[3];
      param_1[0xd] = param_1[4];
      param_1[0xe] = param_1[5];
      if (param_1[0x18] != 0) {
        iVar15 = *(int *)(param_1[0x18] + 0x2c);
        param_1[0xb] = param_1[0xb] + iVar15;
        param_1[0xd] = param_1[0xd] + iVar15;
        iVar15 = *(int *)(param_1[0x18] + 0x30);
        param_1[0xc] = param_1[0xc] + iVar15;
        param_1[0xe] = param_1[0xe] + iVar15;
      }
      puVar7 = (undefined4 *)param_1[0x19];
      for (puVar8 = (undefined4 *)*puVar7; puVar8 != puVar7; puVar8 = (undefined4 *)*puVar8) {
        FUN_00746f70();
      }
    }
    else if (iVar15 < iVar9) {
      FUN_00749d00();
      param_1[3] = param_1[3] + uVar6;
      param_1[5] = param_1[5] + uVar6;
      FUN_00746f70();
    }
    puVar7 = (undefined4 *)param_1[0x19];
    for (puVar8 = (undefined4 *)*puVar7; puVar8 != puVar7; puVar8 = (undefined4 *)*puVar8) {
      iVar15 = puVar8[2];
      if ((*(int *)(iVar15 + 0x60) != 0) && ((*(int **)(iVar15 + 0x1c))[2] != 6)) {
        (**(code **)(**(int **)(iVar15 + 0x1c) + 0x30))(iVar15);
      }
    }
    (**(code **)(*param_1 + 0x128))();
    (**(code **)(*param_1 + 200))();
    param_1[0x3a] = local_68[0];
  }
  ExceptionList = local_14;
  return;
}

