
void FUN_0052c390(void)

{
  undefined4 *puVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  undefined1 local_ec [8];
  undefined4 local_e4;
  undefined2 local_e0;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  uint local_cc;
  undefined4 local_c4;
  undefined4 local_bc;
  undefined2 local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  int local_9c;
  uint local_98;
  uint local_94;
  int local_90;
  undefined **local_8c [6];
  undefined4 *local_74;
  undefined4 local_6c;
  uint local_58;
  char local_48;
  uint local_40;
  undefined4 local_30;
  uint local_2c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009236de;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar3;
  FUN_0072ee30(local_8c);
  local_8 = 0;
  FUN_0072f110(0);
  if ((local_48 == '\0') && (local_9c = FUN_0072e2e0("REINFORCE_STONE_COMPOUND"), local_9c != 0)) {
    iVar4 = FUN_0072e2e0("COMPOUND_INFO");
    if (iVar4 != 0) {
      local_90 = FUN_0072e360(uVar3);
      while (local_90 != 0) {
        iVar4 = FUN_007300a0("RANK_SUM");
        if (iVar4 == 0) {
LAB_0052c4db:
          local_98 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_0052c4db;
          local_98 = FUN_008917b4(puVar5);
        }
        iVar4 = FUN_007300a0("CHARGE");
        if (iVar4 == 0) {
LAB_0052c50e:
          local_94 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_0052c50e;
          local_94 = FUN_008917b4(puVar5);
        }
        iVar4 = FUN_007300a0(&DAT_00c0e484);
        if (iVar4 == 0) {
LAB_0052c53d:
          uVar3 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_0052c53d;
          uVar3 = FUN_008917b4(puVar5);
        }
        iVar4 = FUN_007300a0("PATTERN");
        if (iVar4 == 0) {
LAB_0052c569:
          uVar6 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_0052c569;
          uVar6 = FUN_008917b4(puVar5);
        }
        iVar4 = FUN_007300a0(&DAT_00c0d848);
        if (iVar4 == 0) {
LAB_0052c593:
          local_a0 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_0052c593;
          local_a0 = FUN_008917b4(puVar5);
        }
        local_b4 = local_98;
        local_b0 = local_98;
        local_ac = local_94;
        local_a8 = uVar3;
        local_a4 = uVar6;
        uVar7 = FUN_0052e860();
        FUN_00834230(&DAT_00fc0d00,uVar7);
        local_90 = FUN_0072e3c0();
      }
    }
    iVar4 = FUN_0072e2e0("COMPOUND_RAKNUP_INFO");
    if (iVar4 != 0) {
      local_90 = FUN_0072e360();
      while (local_90 != 0) {
        iVar4 = FUN_007300a0("RANK_SUM");
        if (iVar4 == 0) {
LAB_0052c67b:
          local_94 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_0052c67b;
          local_94 = FUN_008917b4(puVar5);
        }
        iVar4 = FUN_007300a0("CHARGE");
        if (iVar4 == 0) {
LAB_0052c6ae:
          local_98 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_0052c6ae;
          local_98 = FUN_008917b4(puVar5);
        }
        iVar4 = FUN_007300a0(&DAT_00c0e484);
        if (iVar4 == 0) {
LAB_0052c6dd:
          uVar3 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_0052c6dd;
          uVar3 = FUN_008917b4(puVar5);
        }
        iVar4 = FUN_007300a0("PATTERN");
        if (iVar4 == 0) {
LAB_0052c709:
          uVar6 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_0052c709;
          uVar6 = FUN_008917b4(puVar5);
        }
        iVar4 = FUN_007300a0(&DAT_00c0d848);
        if (iVar4 == 0) {
LAB_0052c733:
          local_a0 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_0052c733;
          local_a0 = FUN_008917b4(puVar5);
        }
        local_b4 = local_94;
        local_b0 = local_94;
        local_ac = local_98;
        local_a8 = uVar3;
        local_a4 = uVar6;
        uVar7 = FUN_0052e860();
        FUN_00834230(&DAT_00fc0d10,uVar7);
        local_90 = FUN_0072e3c0();
      }
    }
    for (iVar4 = *(int *)(local_9c + 0x18); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x40)) {
      pcVar10 = (char *)(iVar4 + 0x20);
      if (0xf < *(uint *)(iVar4 + 0x34)) {
        pcVar10 = *(char **)pcVar10;
      }
      iVar8 = __stricmp(pcVar10,"REINFORCE_STONE_STATUS");
      if (iVar8 == 0) {
        if (iVar4 != 0) {
          iVar4 = FUN_0072e360();
          while (iVar4 != 0) {
            iVar11 = *(int *)(iVar4 + 0x94);
            iVar8 = iVar4 + 0x44;
            local_dc = 0;
            local_d8 = 0;
            local_d4 = 0;
            local_d0 = 0;
            for (; iVar11 != iVar8; iVar11 = *(int *)(iVar11 + 0x50)) {
              pcVar10 = (char *)(iVar11 + 0x14);
              if (0xf < *(uint *)(iVar11 + 0x28)) {
                pcVar10 = *(char **)pcVar10;
              }
              iVar9 = __stricmp(pcVar10,"ITEM");
              if (iVar9 == 0) {
                if (iVar11 != 0) {
                  puVar5 = (undefined4 *)(iVar11 + 0x30);
                  if (0xf < *(uint *)(iVar11 + 0x44)) {
                    puVar5 = (undefined4 *)*puVar5;
                  }
                  if (puVar5 != (undefined4 *)0x0) {
                    local_e4 = FUN_008917b4(puVar5);
                    goto LAB_0052c861;
                  }
                }
                break;
              }
            }
            local_e4 = 0;
LAB_0052c861:
            for (iVar11 = *(int *)(iVar4 + 0x94); iVar11 != iVar8; iVar11 = *(int *)(iVar11 + 0x50))
            {
              pcVar10 = (char *)(iVar11 + 0x14);
              if (0xf < *(uint *)(iVar11 + 0x28)) {
                pcVar10 = *(char **)pcVar10;
              }
              iVar9 = __stricmp(pcVar10,"RANK");
              if (iVar9 == 0) {
                if (iVar11 != 0) {
                  puVar5 = (undefined4 *)(iVar11 + 0x30);
                  if (0xf < *(uint *)(iVar11 + 0x44)) {
                    puVar5 = (undefined4 *)*puVar5;
                  }
                  if (puVar5 != (undefined4 *)0x0) {
                    local_e0 = FUN_008917b4(puVar5);
                    goto LAB_0052c89a;
                  }
                }
                break;
              }
            }
            local_e0 = 0;
LAB_0052c89a:
            for (iVar4 = *(int *)(iVar4 + 0x94); iVar4 != iVar8; iVar4 = *(int *)(iVar4 + 0x50)) {
              pcVar10 = (char *)(iVar4 + 0x14);
              if (0xf < *(uint *)(iVar4 + 0x28)) {
                pcVar10 = *(char **)pcVar10;
              }
              iVar11 = __stricmp(pcVar10,"CAN_COMPOUND");
              if (iVar11 == 0) {
                if (iVar4 != 0) {
                  puVar5 = (undefined4 *)(iVar4 + 0x30);
                  if (0xf < *(uint *)(iVar4 + 0x44)) {
                    puVar5 = (undefined4 *)*puVar5;
                  }
                  if (puVar5 != (undefined4 *)0x0) {
                    local_cc = FUN_008917b4(puVar5);
                    goto LAB_0052c8da;
                  }
                }
                break;
              }
            }
            local_cc = 0;
LAB_0052c8da:
            iVar4 = FUN_0072e360();
            if (iVar4 != 0) {
              FUN_0052c290(iVar4);
            }
            local_c4 = local_e4;
            local_bc = local_e4;
            local_b8 = local_e0;
            local_b4 = local_dc;
            local_b0 = local_d8;
            local_ac = local_d4;
            local_a8 = local_d0;
            local_a4 = local_cc;
            uVar7 = FUN_0052e8f0();
            FUN_0052df50(&DAT_00fc0d20,uVar7);
            iVar4 = FUN_0072e3c0();
          }
        }
        break;
      }
    }
    for (iVar4 = *(int *)(local_9c + 0x18); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x40)) {
      pcVar10 = (char *)(iVar4 + 0x20);
      if (0xf < *(uint *)(iVar4 + 0x34)) {
        pcVar10 = *(char **)pcVar10;
      }
      iVar8 = __stricmp(pcVar10,"UNIDENTIFIED_REINFORCE_STONE_STATUS");
      if (iVar8 == 0) {
        if (iVar4 != 0) {
          iVar4 = FUN_0072e360();
          while (local_90 = iVar4, iVar4 != 0) {
            for (iVar8 = *(int *)(iVar4 + 0x94); iVar8 != iVar4 + 0x44;
                iVar8 = *(int *)(iVar8 + 0x50)) {
              pcVar10 = (char *)(iVar8 + 0x14);
              if (0xf < *(uint *)(iVar8 + 0x28)) {
                pcVar10 = *(char **)pcVar10;
              }
              iVar11 = __stricmp(pcVar10,"RANK");
              if (iVar11 == 0) {
                if (iVar8 != 0) {
                  puVar5 = (undefined4 *)(iVar8 + 0x30);
                  if (0xf < *(uint *)(iVar8 + 0x44)) {
                    puVar5 = (undefined4 *)*puVar5;
                  }
                  if (puVar5 != (undefined4 *)0x0) {
                    local_94 = FUN_008917b4(puVar5);
                    goto LAB_0052cab1;
                  }
                }
                break;
              }
            }
            local_94 = 0;
LAB_0052cab1:
            local_94 = local_94 & 0xffff;
            for (iVar8 = *(int *)(iVar4 + 0x94); iVar8 != iVar4 + 0x44;
                iVar8 = *(int *)(iVar8 + 0x50)) {
              pcVar10 = (char *)(iVar8 + 0x14);
              if (0xf < *(uint *)(iVar8 + 0x28)) {
                pcVar10 = *(char **)pcVar10;
              }
              iVar11 = __stricmp(pcVar10,"ITEM");
              if (iVar11 == 0) {
                if (iVar8 != 0) {
                  puVar5 = (undefined4 *)(iVar8 + 0x30);
                  if (0xf < *(uint *)(iVar8 + 0x44)) {
                    puVar5 = (undefined4 *)*puVar5;
                  }
                  if (puVar5 != (undefined4 *)0x0) {
                    uVar3 = FUN_008917b4(puVar5);
                    goto LAB_0052caea;
                  }
                }
                break;
              }
            }
            uVar3 = 0;
LAB_0052caea:
            local_ac = 0;
            local_a8 = 0;
            local_a4 = 0;
            local_a0 = 0;
            iVar4 = FUN_0072e360();
            if ((iVar4 != 0) && (cVar2 = FUN_0052c290(iVar4), cVar2 != '\0')) {
              local_d8 = local_a8;
              local_dc = local_ac;
              local_d4 = local_a4;
              local_d0 = local_a0;
              local_cc = uVar3;
              uVar7 = FUN_0052cfb0(&DAT_00fc0d30,&local_94);
              FUN_0052e980();
              FUN_0052e170(uVar7,local_ec);
            }
            iVar4 = FUN_0072e3c0();
          }
        }
        break;
      }
    }
    local_8c[0] = TiXmlDocument::vftable;
    if (0xf < local_2c) {
      FUN_0089120c(local_40);
    }
    local_2c = 0xf;
    local_30 = 0;
    local_40 = local_40 & 0xffffff00;
    local_8c[0] = TiXmlNode::vftable;
    local_8 = 2;
    puVar5 = local_74;
    while (puVar5 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*puVar5;
      puVar5 = (undefined4 *)puVar5[0x10];
      (*(code *)*puVar1)(1);
    }
    if (0xf < local_58) {
      FUN_0089120c(local_6c);
    }
  }
  else {
    local_8c[0] = TiXmlDocument::vftable;
    local_8 = 0xffffffff;
    if (0xf < local_2c) {
      local_8 = 0xffffffff;
      local_8c[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_40);
    }
    local_2c = 0xf;
    local_30 = 0;
    local_40 = local_40 & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

