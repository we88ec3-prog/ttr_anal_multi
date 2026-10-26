
void FUN_00811120(int param_1)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  int iVar11;
  byte *pbVar12;
  int iVar13;
  bool bVar14;
  bool bVar15;
  int local_94;
  int local_90;
  uint local_88;
  uint local_74;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_34;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009282eb;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar4;
  FUN_00811870(10);
  cVar3 = FUN_00812810(uVar4);
  if ((cVar3 != '\0') &&
     (cVar3 = (**(code **)(param_1 + 0xf8))(0,"ALC_ENUMERATION_EXT"), cVar3 != '\0')) {
    pbVar5 = (byte *)(**(code **)(param_1 + 200))(0,0x1005);
    pbVar6 = (byte *)(**(code **)(param_1 + 200))(0,0x1004);
    bVar1 = *pbVar5;
    local_90 = 0;
    while (pbVar9 = pbVar6, pbVar10 = pbVar5, bVar1 != 0) {
      do {
        bVar1 = *pbVar9;
        bVar14 = bVar1 < *pbVar10;
        if (bVar1 != *pbVar10) {
LAB_00811200:
          iVar7 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
          goto LAB_00811205;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar9[1];
        bVar14 = bVar1 < pbVar10[1];
        if (bVar1 != pbVar10[1]) goto LAB_00811200;
        pbVar9 = pbVar9 + 2;
        pbVar10 = pbVar10 + 2;
      } while (bVar1 != 0);
      iVar7 = 0;
LAB_00811205:
      if (iVar7 == 0) {
        *(int *)(param_1 + 0x114) = local_90;
      }
      iVar7 = (**(code **)(param_1 + 0xd0))(pbVar5);
      if (iVar7 != 0) {
        iVar8 = (**(code **)(param_1 + 0xd8))(iVar7,0);
        if (iVar8 != 0) {
          (**(code **)(param_1 + 0xdc))(iVar8);
          pbVar9 = (byte *)(**(code **)(param_1 + 200))(iVar7,0x1005);
          iVar2 = (*(int *)(param_1 + 0x108) - *(int *)(param_1 + 0x104)) / 0x3c;
          iVar13 = 0;
          bVar14 = true;
          if (iVar2 < 1) {
LAB_00811309:
            if (pbVar9 != (byte *)0x0) {
              pbVar10 = pbVar9;
              do {
                bVar1 = *pbVar10;
                pbVar10 = pbVar10 + 1;
              } while (bVar1 != 0);
              if (pbVar10 != pbVar9 + 1) {
                local_50 = 0;
                local_4c = 0;
                local_48 = 0;
                local_44 = 0;
                local_40 = 0;
                local_3c = 0;
                local_8._0_1_ = 0;
                local_8._1_3_ = 0;
                local_34 = 1;
                pbVar10 = pbVar9;
                do {
                  bVar1 = *pbVar10;
                  pbVar10 = pbVar10 + 1;
                } while (bVar1 != 0);
                FUN_00402a70(pbVar9,(int)pbVar10 - (int)(pbVar9 + 1));
                (**(code **)(param_1 + 0xcc))(iVar7,0x1000,4,&local_50);
                (**(code **)(param_1 + 0xcc))(iVar7,0x1001,4,&local_4c);
                cVar3 = (**(code **)(param_1 + 0xf8))(iVar7,"ALC_EXT_CAPTURE");
                if (cVar3 != '\0') {
                  FUN_00402b70("ALC_EXT_CAPTURE");
                  local_8._0_1_ = 1;
                  FUN_00440c60();
                  local_8._0_1_ = 0;
                  if (0xf < local_1c) {
                    FUN_0089120c(local_30);
                  }
                }
                cVar3 = (**(code **)(param_1 + 0xf8))(iVar7,"ALC_EXT_EFX");
                if (cVar3 != '\0') {
                  FUN_00402b70("ALC_EXT_EFX");
                  local_8._0_1_ = 2;
                  FUN_00440c60();
                  local_8._0_1_ = 0;
                  if (0xf < local_1c) {
                    FUN_0089120c(local_30);
                  }
                }
                cVar3 = (**(code **)(param_1 + 0x34))("AL_EXT_OFFSET");
                if (cVar3 != '\0') {
                  FUN_00402b70("AL_EXT_OFFSET");
                  local_8._0_1_ = 3;
                  FUN_00440c60();
                  local_8._0_1_ = 0;
                  if (0xf < local_1c) {
                    FUN_0089120c(local_30);
                  }
                }
                cVar3 = (**(code **)(param_1 + 0x34))("AL_EXT_LINEAR_DISTANCE");
                if (cVar3 != '\0') {
                  FUN_00402b70("AL_EXT_LINEAR_DISTANCE");
                  local_8._0_1_ = 4;
                  FUN_00440c60();
                  local_8._0_1_ = 0;
                  if (0xf < local_1c) {
                    FUN_0089120c(local_30);
                  }
                }
                cVar3 = (**(code **)(param_1 + 0x34))("AL_EXT_EXPONENT_DISTANCE");
                if (cVar3 != '\0') {
                  FUN_00402b70("AL_EXT_EXPONENT_DISTANCE");
                  local_8._0_1_ = 5;
                  FUN_00440c60();
                  local_8._0_1_ = 0;
                  if (0xf < local_1c) {
                    FUN_0089120c(local_30);
                  }
                }
                cVar3 = (**(code **)(param_1 + 0x34))("EAX2.0");
                if (cVar3 != '\0') {
                  FUN_00402b70("EAX2.0");
                  local_8._0_1_ = 6;
                  FUN_00440c60();
                  local_8._0_1_ = 0;
                  if (0xf < local_1c) {
                    FUN_0089120c(local_30);
                  }
                }
                cVar3 = (**(code **)(param_1 + 0x34))("EAX3.0");
                if (cVar3 != '\0') {
                  FUN_00402b70("EAX3.0");
                  local_8._0_1_ = 7;
                  FUN_00440c60();
                  local_8._0_1_ = 0;
                  if (0xf < local_1c) {
                    FUN_0089120c(local_30);
                  }
                }
                cVar3 = (**(code **)(param_1 + 0x34))("EAX4.0");
                if (cVar3 != '\0') {
                  FUN_00402b70("EAX4.0");
                  local_8._0_1_ = 8;
                  FUN_00440c60();
                  local_8._0_1_ = 0;
                  if (0xf < local_1c) {
                    FUN_0089120c(local_30);
                  }
                }
                cVar3 = (**(code **)(param_1 + 0x34))("EAX5.0");
                if (cVar3 != '\0') {
                  FUN_00402b70("EAX5.0");
                  local_8._0_1_ = 9;
                  FUN_00440c60();
                  local_8._0_1_ = 0;
                  if (0xf < local_1c) {
                    FUN_0089120c(local_30);
                  }
                }
                cVar3 = (**(code **)(param_1 + 0x34))("EAX-RAM");
                if (cVar3 != '\0') {
                  FUN_00402b70("EAX-RAM");
                  local_8._0_1_ = 10;
                  FUN_00440c60();
                  local_8._0_1_ = 0;
                  if (0xf < local_74) {
                    FUN_0089120c(local_88);
                  }
                  local_74 = 0xf;
                  local_88 = local_88 & 0xffffff00;
                }
                local_48 = FUN_00811790();
                FUN_00811980(param_1 + 0x104);
                local_8 = 0xffffffff;
                FUN_00811cc0();
              }
            }
          }
          else {
            local_94 = 0;
            if (iVar2 < 1) {
              pbVar10 = (byte *)0x0;
              pbVar12 = pbVar9;
              goto LAB_008112c1;
            }
            do {
              pbVar10 = (byte *)(*(int *)(param_1 + 0x104) + local_94);
              pbVar12 = pbVar9;
              if (0xf < *(uint *)(pbVar10 + 0x14)) {
                pbVar10 = *(byte **)pbVar10;
              }
LAB_008112c1:
              do {
                bVar1 = *pbVar10;
                bVar15 = bVar1 < *pbVar12;
                if (bVar1 != *pbVar12) {
LAB_008112e1:
                  iVar11 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
                  goto LAB_008112e6;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar10[1];
                bVar15 = bVar1 < pbVar12[1];
                if (bVar1 != pbVar12[1]) goto LAB_008112e1;
                pbVar10 = pbVar10 + 2;
                pbVar12 = pbVar12 + 2;
              } while (bVar1 != 0);
              iVar11 = 0;
LAB_008112e6:
              if (iVar11 == 0) {
                bVar14 = false;
              }
              local_94 = local_94 + 0x3c;
              iVar13 = iVar13 + 1;
            } while (iVar13 < iVar2);
            if (bVar14) goto LAB_00811309;
          }
          (**(code **)(param_1 + 0xdc))(0);
          (**(code **)(param_1 + 0xf0))(iVar8);
        }
        (**(code **)(param_1 + 0xd4))(iVar7);
      }
      do {
        bVar1 = *pbVar5;
        pbVar5 = pbVar5 + 1;
      } while (bVar1 != 0);
      local_90 = local_90 + 1;
      bVar1 = *pbVar5;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

