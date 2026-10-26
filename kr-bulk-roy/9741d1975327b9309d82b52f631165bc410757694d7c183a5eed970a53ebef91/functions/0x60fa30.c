
void FUN_0060fa30(int param_1,undefined1 *param_2,byte param_3)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  byte bVar9;
  uint uVar10;
  undefined1 *puVar11;
  uint uVar12;
  undefined1 local_d4 [40];
  undefined1 local_ac [12];
  undefined1 local_a0 [4];
  undefined4 *local_9c;
  undefined1 local_84 [12];
  undefined1 local_78 [4];
  undefined4 *local_74;
  int local_54;
  int local_50;
  int local_4c;
  uint local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  int local_34;
  uint local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093e484;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb11a8 & 1) == 0) {
    DAT_00fb11a8 = DAT_00fb11a8 | 1;
    local_8 = 0;
    FUN_00813890(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccec0);
  }
  local_8 = 0xffffffff;
  FUN_0082ef00(&param_2);
  if (local_24 == DAT_00fb11b0) {
    local_2c = 0;
  }
  else {
    local_2c = *(int *)(local_24 + 0x10);
  }
  uVar10 = (uint)param_3;
  if (uVar10 < (uint)(*(int *)(local_2c + 0x18) - *(int *)(local_2c + 0x14) >> 2)) {
    iVar2 = *(int *)(*(int *)(local_2c + 0x14) + uVar10 * 4);
    local_30 = *(int *)(iVar2 + 0x18) - *(int *)(iVar2 + 0x14) >> 2;
  }
  else {
    local_30 = 0;
  }
  local_24 = 0;
  local_48 = uVar10;
  if (local_30 == 0) {
    ExceptionList = local_10;
    return;
  }
  do {
    uVar12 = local_24;
    iVar2 = *(int *)(*(int *)(local_2c + 0x14) + uVar10 * 4);
    if (((local_24 < (uint)(*(int *)(iVar2 + 0x18) - *(int *)(iVar2 + 0x14) >> 2)) &&
        (piVar3 = *(int **)(*(int *)(iVar2 + 0x14) + local_24 * 4), piVar3 != (int *)0x0)) &&
       (uVar5 = (**(code **)(*piVar3 + 4))(), (uVar5 & 0x14100000) == 0x14100000)) {
      uVar10 = (**(code **)(*piVar3 + 4))();
      puVar11 = (undefined1 *)(~-(uint)((uVar10 & 0x14100000) != 0x14100000) & (uint)piVar3);
      if (puVar11 == (undefined1 *)0x0) {
        ExceptionList = local_10;
        return;
      }
      param_2 = puVar11;
      FUN_007e8a90(&local_44,puVar11 + 8);
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      iVar2 = *(int *)(*(int *)(puVar11 + 0x18) + 4);
      local_20 = local_40 - local_44 >> 2;
      if (iVar2 == 1) {
        FUN_00830e10();
        local_8._0_1_ = 2;
        bVar9 = 1;
        local_18[0] = 0;
        if (local_20 == 0) {
LAB_0060ff37:
          uVar8 = FUN_00830d00(local_ac,param_1 + 0x198,local_84);
          local_8._0_1_ = 4;
          FUN_005cf7e0(uVar8);
          param_2 = local_a0;
          local_8._0_1_ = 5;
          FUN_004ca160(*local_9c,local_9c);
          FUN_0089120c(local_9c);
        }
        else {
          do {
            if (bVar9 == 0) goto LAB_0060ff92;
            uVar10 = local_1c;
            if (local_20 <= local_18[0]) goto LAB_00610002;
            iVar2 = *(int *)(local_44 + local_18[0] * 4);
            switch(*(undefined4 *)(iVar2 + 4)) {
            case 2:
            case 3:
            case 4:
            case 6:
            case 7:
            case 9:
            case 10:
switchD_0060fe39_caseD_2:
              bVar9 = 0;
              break;
            case 5:
              uVar1 = *(ushort *)(iVar2 + 8);
              bVar4 = FUN_0081b3d0();
              bVar9 = bVar9 & bVar4 & *(uint *)(param_1 + 0x15c) == (uint)uVar1;
              uVar8 = FUN_00830d00(local_d4,local_84,*(int *)(param_2 + 0x18) + 8);
              local_8._0_1_ = 3;
              FUN_005cf7e0(uVar8);
              local_8._0_1_ = 2;
              FUN_005ce3c0();
              break;
            case 8:
              iVar6 = *(int *)(iVar2 + 8);
              iVar7 = FUN_00404ba0();
              uVar8 = *(undefined4 *)(iVar7 + 0x5f50);
              FUN_00489d00();
              iVar7 = FUN_004d2da0(uVar8);
              local_28 = (uint)*(byte *)(iVar2 + 0xc);
              FUN_00826280(&local_28);
              if (local_54 == *(int *)(iVar7 + 4)) goto switchD_0060fe39_caseD_2;
              bVar4 = FUN_0081b540();
              bVar9 = (bVar9 & iVar6 != 0) != 0 & bVar4;
              break;
            case 0xb:
              iVar2 = *(int *)(iVar2 + 8);
              FUN_0040f060();
              (**(code **)(*DAT_00fba7a4 + 0x20))();
              bVar4 = FUN_0081b600();
              bVar9 = bVar9 & iVar2 != 0 & bVar4;
            }
            local_18[0] = local_18[0] + 1;
          } while (local_18[0] < local_20);
          if (bVar9 != 0) goto LAB_0060ff37;
        }
LAB_0060ff92:
        param_2 = local_78;
        local_8 = CONCAT31(local_8._1_3_,6);
        FUN_004ca160(*local_74,local_74);
        FUN_0089120c(local_74);
      }
      else if (iVar2 == 4) {
        local_34 = 0;
        local_1c = 0;
        bVar9 = 1;
        local_18[0] = 0;
        if (local_20 != 0) {
          uVar10 = local_1c;
          if (local_20 == 0) goto LAB_00610002;
          do {
            iVar2 = *(int *)(local_44 + local_18[0] * 4);
            switch(*(undefined4 *)(iVar2 + 4)) {
            case 2:
            case 3:
            case 4:
            case 6:
            case 7:
            case 9:
            case 10:
switchD_0060fceb_caseD_2:
              bVar9 = 0;
              break;
            case 5:
              uVar1 = *(ushort *)(iVar2 + 8);
              bVar4 = FUN_0081b3d0();
              bVar9 = bVar9 & bVar4 & *(uint *)(param_1 + 0x15c) == (uint)uVar1;
              local_34 = local_34 + *(short *)(*(int *)(param_2 + 0x18) + 10);
              local_1c = (uint)((float)(int)local_1c + *(float *)(*(int *)(param_2 + 0x18) + 0x18));
              break;
            case 8:
              iVar6 = *(int *)(iVar2 + 8);
              iVar7 = FUN_00404ba0();
              uVar8 = *(undefined4 *)(iVar7 + 0x5f50);
              FUN_00489d00();
              iVar7 = FUN_004d2da0(uVar8);
              local_28 = (uint)*(byte *)(iVar2 + 0xc);
              FUN_00826280(&local_28);
              if (local_50 == *(int *)(iVar7 + 4)) goto switchD_0060fceb_caseD_2;
              bVar4 = FUN_0081b540();
              bVar9 = (bVar9 & iVar6 != 0) != 0 & bVar4;
              break;
            case 0xb:
              iVar2 = *(int *)(iVar2 + 8);
              FUN_0040f060();
              (**(code **)(*DAT_00fba7a4 + 0x20))();
              bVar4 = FUN_0081b600();
              bVar9 = bVar9 & iVar2 != 0 & bVar4;
            }
            local_18[0] = local_18[0] + 1;
          } while (local_18[0] < local_20);
          if (bVar9 == 0) goto LAB_0060ffb9;
        }
        *(int *)(param_1 + 0x1c4) = *(int *)(param_1 + 0x1c4) + local_34;
        *(int *)(param_1 + 0x1c0) = *(int *)(param_1 + 0x1c0) + local_1c;
      }
      else if ((iVar2 == 5) && (local_1c = 0, local_20 != 0)) {
        local_1c = 0;
        uVar10 = 0;
        if (local_20 == 0) {
LAB_00610002:
          local_1c = uVar10;
                    /* WARNING: Subroutine does not return */
          FUN_0087db7d("invalid vector<T> subscript");
        }
        do {
          iVar2 = *(int *)(local_44 + local_1c * 4);
          switch(*(undefined4 *)(iVar2 + 4)) {
          case 2:
          case 3:
          case 4:
          case 6:
          case 7:
          case 9:
          case 10:
switchD_0060fbd7_caseD_2:
            break;
          case 5:
            local_18[0] = (uint)*(ushort *)(iVar2 + 8);
            FUN_0081b3d0();
            *(int *)(param_1 + 0x1cc) =
                 *(int *)(param_1 + 0x1cc) + (int)*(short *)(*(int *)(puVar11 + 0x18) + 10);
            break;
          case 8:
            iVar6 = FUN_00404ba0();
            uVar8 = *(undefined4 *)(iVar6 + 0x5f50);
            FUN_00489d00();
            iVar6 = FUN_004d2da0(uVar8);
            local_18[0] = (uint)*(byte *)(iVar2 + 0xc);
            FUN_00826280(local_18);
            puVar11 = param_2;
            if (local_4c == *(int *)(iVar6 + 4)) goto switchD_0060fbd7_caseD_2;
            FUN_0081b540();
            puVar11 = param_2;
            break;
          case 0xb:
            FUN_0040f060();
            (**(code **)(*DAT_00fba7a4 + 0x20))();
            FUN_0081b600();
          }
          local_1c = local_1c + 1;
        } while (local_1c < local_20);
      }
LAB_0060ffb9:
      local_8 = 0xffffffff;
      if (local_44 != 0) {
        FUN_0089120c(local_44);
      }
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      uVar10 = local_48;
      uVar12 = local_24;
    }
    local_24 = uVar12 + 1;
    if (local_30 <= local_24) {
      ExceptionList = local_10;
      return;
    }
  } while( true );
}

