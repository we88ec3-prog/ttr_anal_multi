
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_008e39d0(uint *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 char param_5,uint param_6,uint param_7,int *param_8)

{
  uint *puVar1;
  char cVar2;
  undefined1 uVar3;
  short sVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  byte bVar13;
  uint uVar14;
  bool bVar15;
  undefined *puVar16;
  undefined1 local_3e08 [32];
  undefined1 local_3de8 [32];
  int local_3dc8;
  undefined4 local_3dc4;
  undefined4 local_3dc0;
  uint local_3dbc;
  uint *local_3db8;
  int local_3db4;
  uint local_3db0;
  int local_3dac;
  uint local_3da8;
  int local_3da4;
  uint local_3da0;
  int local_3d9c;
  int local_3d98;
  int local_3d94;
  int *local_3d90;
  int local_3d8c;
  uint *local_3d88;
  uint local_3d84;
  undefined4 *local_3d80;
  uint local_3d7c;
  uint local_3d78;
  uint local_3d74;
  uint local_3d70;
  byte local_3d6a;
  char local_3d69;
  uint local_3d68;
  undefined1 local_3d64 [3868];
  undefined1 local_2e48 [7744];
  undefined1 local_1008 [3868];
  undefined1 local_ec [172];
  undefined1 local_40 [28];
  undefined1 local_24 [12];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_3d70 = *param_1;
  local_3dc4 = param_3;
  local_3db0 = param_1[0x21];
  local_3dc0 = param_4;
  local_3dbc = param_1[0xc];
  puVar1 = param_1 + 1;
  local_3d88 = param_1;
  local_3d90 = param_8;
  local_3d8c = 0;
  local_3db8 = puVar1;
  local_3db4 = FUN_008e0e10();
  local_3dc8 = 20000000;
  FUN_008e06e0(0x10);
  FUN_008e06e0(0x14);
  FUN_008e06e0(0x14);
  FUN_008e1cc0(puVar1);
  FUN_008e12c0(local_3dc4,local_3dbc,local_3e08,local_3de8,local_40,param_7,param_1 + 0x31,
               local_3dc0);
  local_3d69 = '\0';
  iVar6 = FUN_008e0e00();
  *local_3d90 = iVar6;
  iVar6 = FUN_008e1dd0(puVar1);
  local_3dac = iVar6;
  if (iVar6 == 0) {
    local_3d8c = 0x40;
    iVar8 = local_3d8c;
  }
  else {
    FUN_008e22c0();
    local_3d80 = (undefined4 *)FUN_008e0750();
    *local_3d80 = *param_2;
    local_3d80[1] = param_2[1];
    local_3d80[2] = param_2[2];
    local_3d80[3] = param_2[3];
    local_3da8 = 0;
    iVar8 = local_3d8c;
    if (*local_3db8 == 0) {
LAB_008e3b61:
      cVar2 = FUN_008e1dc0();
      if (cVar2 == '\0') {
        bVar13 = FUN_008e1d90();
      }
      else {
        bVar13 = (-(local_3da8 != 0) & 0xfdU) + 0xe;
      }
      puVar1 = local_3d88;
      iVar8 = local_3d8c;
      local_3d6a = bVar13;
      if (*local_3db8 != 0) goto LAB_008e4a24;
      local_3dc8 = local_3dc8 + -1;
      if (local_3dc8 == 0) goto LAB_008e48df;
      uVar14 = (uint)bVar13;
      switch(uVar14) {
      case 1:
      case 0x12:
        FUN_008e36f0(iVar6,local_3e08,local_3d90,&local_3d69,0);
        iVar8 = local_3d8c;
        if (*(char *)(puVar1[0x21] + 0x2f1) != '\0') break;
        FUN_008e1fb0();
        goto LAB_008e3b61;
      case 3:
      case 0x17:
        FUN_008e36f0(iVar6,local_3de8,local_3d90,&local_3d69,0);
        iVar8 = local_3d8c;
        if (*(char *)(puVar1[0x21] + 0x2f1) != '\0') break;
        FUN_008e1fb0();
        goto LAB_008e3b61;
      case 4:
        uVar14 = FUN_008e1e30();
        if ((1 < uVar14) && (local_3d69 == '\0')) {
          iVar8 = FUN_008e1f60();
          *local_3d90 = iVar8 + local_3db4;
        }
        local_3d69 = '\x01';
        iVar8 = local_3d8c;
        if (*(char *)(local_3d88[0x21] + 0x2f1) != '\0') break;
        iVar8 = FUN_008e1f00();
        param_7 = param_7 + iVar8;
        FUN_008e3940(local_2e48,param_6,param_7);
        FUN_008e1fb0();
        goto LAB_008e3b61;
      case 5:
        local_3d70 = FUN_008e1e30();
        uVar14 = 0;
        if (local_3d70 != 0) {
          do {
            iVar8 = FUN_008e1f60();
            param_6 = param_6 + iVar8;
            iVar8 = FUN_008e1f60();
            param_7 = param_7 + iVar8;
            FUN_008e3310(param_6,param_7);
            uVar14 = uVar14 + 2;
          } while (uVar14 < local_3d70);
        }
        FUN_008e1fb0();
        goto LAB_008e3b61;
      case 6:
      case 7:
        local_3d70 = FUN_008e1e30();
        bVar15 = bVar13 == 6;
        local_3d74 = 0;
        if (local_3d70 != 0) {
          do {
            iVar8 = FUN_008e1f60();
            if (bVar15) {
              param_6 = param_6 + iVar8;
            }
            else {
              param_7 = param_7 + iVar8;
            }
            bVar15 = bVar15 == false;
            FUN_008e3310(param_6,param_7);
            local_3d74 = local_3d74 + 1;
          } while (local_3d74 < local_3d70);
        }
        FUN_008e1fb0();
        goto LAB_008e3b61;
      case 8:
      case 0x18:
        local_3d74 = FUN_008e1e30();
        local_3d68 = 0;
        if (5 < local_3d74) {
          do {
            iVar8 = FUN_008e1f60();
            iVar8 = iVar8 + param_6;
            iVar7 = FUN_008e1f60();
            local_3d78 = iVar7 + param_7;
            iVar7 = FUN_008e1f60();
            local_3d70 = iVar7 + iVar8;
            iVar7 = FUN_008e1f60();
            local_3da0 = iVar7 + local_3d78;
            iVar7 = FUN_008e1f60();
            local_3d7c = iVar7 + local_3d70;
            iVar7 = FUN_008e1f60();
            uVar10 = iVar7 + local_3da0;
            FUN_008e3480(iVar8,local_3d78,local_3d70,local_3da0,local_3d7c,uVar10);
            param_6 = local_3d7c;
            uVar14 = local_3d68 + 6;
            uVar9 = local_3d68 + 0xc;
            param_7 = uVar10;
            local_3d68 = uVar14;
            bVar13 = local_3d6a;
          } while (uVar9 <= local_3d74);
        }
        if (bVar13 == 0x18) {
          iVar8 = FUN_008e1f60();
          uVar14 = param_6 + iVar8;
          param_6 = uVar14;
          iVar8 = FUN_008e1f60();
          param_7 = param_7 + iVar8;
          FUN_008e3310(uVar14,param_7);
        }
        FUN_008e1fb0();
        goto LAB_008e3b61;
      case 10:
      case 0x1d:
        if (10 < (int)local_3da8) goto LAB_008e48df;
        local_3d70 = local_3da8 + 1;
        local_3d80 = (undefined4 *)FUN_008e22e0();
        FUN_008e1ec0();
        if (bVar13 == 0x1d) {
          iVar8 = FUN_008e0d00();
        }
        else {
          iVar8 = FUN_008e0dc0();
        }
        if (iVar8 != 0) goto LAB_008e48df;
        local_3da8 = local_3d70;
        goto LAB_008e3b61;
      case 0xb:
        if ((int)local_3da8 < 1) goto LAB_008e48df;
        local_3da8 = local_3da8 - 1;
        local_3d80 = (undefined4 *)FUN_008e22e0();
        goto LAB_008e3b61;
      case 0xc:
        uVar3 = FUN_008e1d90();
        switch(uVar3) {
        default:
          goto switchD_008e3bc5_caseD_0;
        case 0x22:
          uVar11 = 0;
          puVar16 = &DAT_00bea168;
          break;
        case 0x23:
          FUN_008e37d0(&param_6,&param_7,&DAT_00bea174,0);
          FUN_008e1fb0();
          goto LAB_008e3b61;
        case 0x24:
          FUN_008e37d0(&param_6,&param_7,&DAT_00bea180,0);
          goto LAB_008e3b61;
        case 0x25:
          uVar11 = 1;
          puVar16 = &DAT_00bea18c;
        }
        FUN_008e37d0(&param_6,&param_7,puVar16,uVar11);
        goto LAB_008e3b61;
      case 0xe:
        iVar6 = FUN_008e1e30();
        if (((iVar6 == 1) || (iVar6 = FUN_008e1e30(), iVar6 == 5)) && (local_3d69 == '\0')) {
          iVar6 = FUN_008e1f60();
          *local_3d90 = iVar6 + local_3db4;
        }
        iVar8 = local_3d8c;
        if (*(char *)(local_3d88[0x21] + 0x2f1) == '\0') {
          FUN_008e3640();
          uVar14 = FUN_008e1e30();
          iVar8 = local_3d8c;
          if (1 < uVar14) {
            if (param_5 == '\0') {
              uVar11 = FUN_008e1ec0();
              uVar12 = FUN_008e1ec0();
              param_7 = FUN_008e1f00();
              param_6 = FUN_008e1f00();
              iVar8 = FUN_008e0d40(uVar11);
              if (iVar8 == 0) {
                FUN_008e39d0(local_3d88,local_18,local_3dc4,local_3dc0,1,param_6,param_7,&local_3dbc
                            );
                FUN_008e0da0();
                iVar8 = FUN_008e0d40(uVar12);
                if (iVar8 == 0) {
                  FUN_008e39d0(local_3d88,local_18,local_3dc4,local_3dc0,1,0,0,&local_3dbc);
                  FUN_008e0da0();
                  iVar8 = local_3d8c;
                }
              }
            }
            else {
LAB_008e48df:
              local_3d8c = 0x12;
              iVar8 = local_3d8c;
            }
          }
        }
        break;
      case 0x13:
      case 0x14:
        FUN_008e36f0(iVar6,local_3de8,local_3d90,&local_3d69,0);
        iVar8 = local_3d8c;
        if (*(char *)(puVar1[0x21] + 0x2f1) != '\0') break;
        if (bVar13 == 0x13) {
          FUN_008e0740();
          FUN_008e0740();
          FUN_008e36c0();
          iVar6 = local_3dac;
          FUN_008e1fb0();
        }
        else {
          FUN_008e0f30(local_1008,local_ec,local_3dbc);
          FUN_008e1cc0(local_3db8);
          FUN_008e0740();
          FUN_008e0740();
          FUN_008e36c0();
          FUN_008e2ff0(local_3d64,local_3e08,local_3de8,local_24,0,0);
          iVar6 = local_3dac;
          FUN_008e1fb0();
        }
        goto LAB_008e3b61;
      case 0x15:
        uVar14 = FUN_008e1e30();
        if ((2 < uVar14) && (local_3d69 == '\0')) {
          iVar8 = FUN_008e1f60();
          *local_3d90 = iVar8 + local_3db4;
        }
        local_3d69 = '\x01';
        iVar8 = local_3d8c;
        if (*(char *)(local_3d88[0x21] + 0x2f1) != '\0') break;
        iVar8 = FUN_008e1f00();
        uVar14 = param_7 + iVar8;
        param_7 = uVar14;
        iVar8 = FUN_008e1f00();
        param_6 = param_6 + iVar8;
        FUN_008e3940(local_2e48,param_6,uVar14);
        FUN_008e1fb0();
        goto LAB_008e3b61;
      case 0x16:
        uVar14 = FUN_008e1e30();
        if ((1 < uVar14) && (local_3d69 == '\0')) {
          iVar8 = FUN_008e1f60();
          *local_3d90 = iVar8 + local_3db4;
        }
        local_3d69 = '\x01';
        iVar8 = local_3d8c;
        if (*(char *)(local_3d88[0x21] + 0x2f1) != '\0') break;
        iVar8 = FUN_008e1f00();
        param_6 = param_6 + iVar8;
        FUN_008e3940(local_2e48,param_6,param_7);
      case 0:
      case 2:
      case 9:
      case 0xd:
      case 0xf:
      case 0x10:
      case 0x11:
switchD_008e3bc5_caseD_0:
        FUN_008e1fb0();
        goto LAB_008e3b61;
      case 0x19:
        local_3d74 = FUN_008e1e30();
        local_3d84 = 0;
        if (6 < local_3d74) {
          uVar14 = 6;
          do {
            iVar8 = FUN_008e1f60();
            param_6 = param_6 + iVar8;
            iVar8 = FUN_008e1f60();
            param_7 = param_7 + iVar8;
            FUN_008e3310(param_6,param_7);
            local_3d84 = local_3d84 + 2;
            uVar14 = uVar14 + 2;
          } while (uVar14 < local_3d74);
        }
        if (local_3d84 < local_3d74) {
          local_3d68 = local_3d84 + 2;
          do {
            iVar8 = FUN_008e1f60();
            iVar8 = iVar8 + param_6;
            iVar7 = FUN_008e1f60();
            local_3d78 = iVar7 + param_7;
            iVar7 = FUN_008e1f60();
            local_3d70 = iVar7 + iVar8;
            iVar7 = FUN_008e1f60();
            local_3da0 = iVar7 + local_3d78;
            iVar7 = FUN_008e1f60();
            local_3d7c = iVar7 + local_3d70;
            iVar7 = FUN_008e1f60();
            uVar10 = iVar7 + local_3da0;
            FUN_008e3480(iVar8,local_3d78,local_3d70,local_3da0,local_3d7c,uVar10);
            param_6 = local_3d7c;
            uVar14 = local_3d68 + 6;
            uVar9 = local_3d68 + 4;
            param_7 = uVar10;
            local_3d68 = uVar14;
          } while (uVar9 < local_3d74);
        }
        FUN_008e1fb0();
        goto LAB_008e3b61;
      case 0x1a:
        local_3d78 = FUN_008e1e30();
        local_3d68 = 0;
        if (local_3d78 != 0) {
          do {
            uVar14 = local_3d68;
            if ((local_3d78 - local_3d68 & 1) == 0) {
              local_3d74 = param_6;
            }
            else {
              iVar8 = FUN_008e1f60();
              local_3d74 = iVar8 + param_6;
              local_3d68 = uVar14 + 1;
            }
            iVar8 = FUN_008e1f60();
            iVar8 = iVar8 + param_7;
            iVar7 = FUN_008e1f60();
            local_3d70 = iVar7 + local_3d74;
            iVar7 = FUN_008e1f60();
            local_3d7c = iVar7 + iVar8;
            iVar7 = FUN_008e1f60();
            uVar14 = local_3d7c + iVar7;
            FUN_008e3480(local_3d74,iVar8,local_3d70,local_3d7c,local_3d70,uVar14);
            param_6 = local_3d70;
            local_3d68 = local_3d68 + 4;
            param_7 = uVar14;
          } while (local_3d68 < local_3d78);
        }
        FUN_008e1fb0();
        goto LAB_008e3b61;
      case 0x1b:
        local_3d78 = FUN_008e1e30();
        local_3d68 = 0;
        if (local_3d78 != 0) {
          do {
            uVar9 = local_3d68;
            uVar14 = param_7;
            if ((local_3d78 - local_3d68 & 1) == 0) {
              local_3d74 = param_7;
            }
            else {
              iVar8 = FUN_008e1f60();
              local_3d74 = iVar8 + uVar14;
              local_3d68 = uVar9 + 1;
            }
            iVar8 = FUN_008e1f60();
            iVar8 = iVar8 + param_6;
            iVar7 = FUN_008e1f60();
            local_3d7c = iVar7 + iVar8;
            iVar7 = FUN_008e1f60();
            local_3d70 = iVar7 + local_3d74;
            iVar7 = FUN_008e1f60();
            uVar14 = iVar7 + local_3d7c;
            FUN_008e3480(iVar8,local_3d74,local_3d7c,local_3d70,uVar14,local_3d70);
            param_7 = local_3d70;
            local_3d68 = local_3d68 + 4;
            param_6 = uVar14;
          } while (local_3d68 < local_3d78);
        }
        FUN_008e1fb0();
        goto LAB_008e3b61;
      case 0x1c:
        sVar4 = FUN_008e1d90();
        uVar5 = FUN_008e1d90();
        FUN_008e1e40((int)(short)(uVar5 | sVar4 << 8));
        goto LAB_008e3b61;
      case 0x1e:
      case 0x1f:
        local_3d70 = FUN_008e1e30();
        local_3d68 = 0;
        if (local_3d70 != 0) {
          local_3da4 = 4;
          local_3d98 = 3;
          local_3d94 = 2;
          local_3d9c = 1;
          bVar13 = bVar13 == 0x1f;
          do {
            if (bVar13 == 0) {
              local_3d78 = param_6;
              iVar8 = FUN_008e1f60();
              local_3d7c = iVar8 + param_7;
              iVar8 = FUN_008e1f60();
              uVar14 = iVar8 + param_6;
              iVar8 = FUN_008e1f60();
              local_3d84 = iVar8 + local_3d7c;
              iVar7 = FUN_008e1f60();
              iVar8 = local_3da4;
              local_3d74 = iVar7 + uVar14;
              if (local_3d70 - local_3d68 == 5) {
                iVar7 = FUN_008e1f60();
                local_3da0 = iVar7 + local_3d84;
                local_3d68 = local_3d68 + 1;
                local_3d9c = local_3d9c + 1;
                local_3d94 = local_3d94 + 1;
                local_3d98 = local_3d98 + 1;
                local_3da4 = iVar8 + 1;
              }
              else {
                local_3da0 = local_3d84;
              }
              local_3d6a = 1;
            }
            else {
              iVar8 = FUN_008e1f60();
              local_3d78 = iVar8 + param_6;
              local_3d7c = param_7;
              iVar8 = FUN_008e1f60();
              uVar14 = iVar8 + local_3d78;
              iVar8 = FUN_008e1f60();
              local_3d84 = iVar8 + param_7;
              iVar7 = FUN_008e1f60();
              iVar8 = local_3da4;
              local_3da0 = iVar7 + local_3d84;
              if (local_3d70 - local_3d68 == 5) {
                iVar7 = FUN_008e1f60();
                local_3d68 = local_3d68 + 1;
                local_3d9c = local_3d9c + 1;
                local_3d94 = local_3d94 + 1;
                local_3d98 = local_3d98 + 1;
                local_3da4 = iVar8 + 1;
                local_3d6a = 0;
                local_3d74 = iVar7 + uVar14;
              }
              else {
                local_3d6a = 0;
                local_3d74 = uVar14;
              }
            }
            uVar9 = local_3da0;
            FUN_008e3480(local_3d78,local_3d7c,uVar14,local_3d84,local_3d74,local_3da0);
            param_6 = local_3d74;
            local_3d9c = local_3d9c + 4;
            local_3d94 = local_3d94 + 4;
            local_3d98 = local_3d98 + 4;
            local_3da4 = local_3da4 + 4;
            local_3d68 = local_3d68 + 4;
            param_7 = uVar9;
            bVar13 = local_3d6a;
          } while (local_3d68 < local_3d70);
        }
        FUN_008e1fb0();
        goto LAB_008e3b61;
      default:
        goto switchD_008e3bc5_default;
      }
    }
  }
LAB_008e4a24:
  local_3d8c = iVar8;
  FUN_008e0760();
  FUN_008e1410();
  FUN_008e0710();
  FUN_008e0710();
  FUN_008e0710();
  FUN_008e1e10();
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
switchD_008e3bc5_default:
  if (bVar13 < 0xf7) {
    FUN_008e1e40(uVar14 - 0x8b);
  }
  else {
    iVar8 = FUN_008e1d90();
    if (bVar13 < 0xfb) {
      FUN_008e1e40(iVar8 + -0xf694 + uVar14 * 0x100);
    }
    else if (bVar13 == 0xff) {
      uVar14 = FUN_008e1d90();
      uVar9 = FUN_008e1d90();
      uVar10 = FUN_008e1d90();
      FUN_008e1e80(uVar10 | (uVar9 | (uVar14 | iVar8 << 8) << 8) << 8);
    }
    else {
      FUN_008e1e40((uVar14 * -0x100 + 0xfa94) - iVar8);
    }
  }
  goto LAB_008e3b61;
}

