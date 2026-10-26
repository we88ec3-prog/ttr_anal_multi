
void FUN_00825210(byte *param_1)

{
  char cVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined2 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  undefined4 uVar11;
  byte *pbVar12;
  byte *pbVar13;
  int local_dc;
  undefined1 local_cc [4];
  byte *local_c8;
  undefined1 local_c4;
  byte local_c3;
  int local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  byte *local_b0;
  byte *local_ac;
  undefined4 local_a8;
  byte local_a1;
  undefined **local_a0 [19];
  uint local_54;
  undefined4 local_44;
  uint local_40;
  undefined1 local_24;
  byte local_23;
  undefined4 local_20;
  uint local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925e41;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_ac = param_1;
  local_18 = uVar5;
  FUN_0072ee30(local_a0);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if ((cVar1 == '\0') ||
     (local_b0 = (byte *)FUN_0072e2e0("GUILD_REPUTATION"), local_b0 == (byte *)0x0)) {
    local_a0[0] = TiXmlDocument::vftable;
    local_8 = 0xffffffff;
    if (0xf < local_40) {
      local_8 = 0xffffffff;
      local_a0[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_54);
    }
    local_40 = 0xf;
    local_44 = 0;
    local_54 = local_54 & 0xffffff00;
    FUN_0072e040();
  }
  else {
    local_a1 = 0;
    iVar6 = FUN_0072e360(uVar5);
    if ((iVar6 != 0) &&
       ((iVar6 = FUN_0072e360(uVar5), iVar6 != 0 && (iVar6 = FUN_0072e360(), iVar6 != 0)))) {
      local_c8 = local_ac + 8;
      do {
        iVar6 = FUN_007300a0("CONTRACT_NO");
        if (iVar6 == 0) {
LAB_0082536c:
          uVar2 = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar6 + 0x30);
          if (0xf < *(uint *)(iVar6 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_0082536c;
          uVar2 = FUN_008917b4(puVar7);
        }
        local_a8._0_3_ = CONCAT12(uVar2,(undefined2)local_a8);
        iVar6 = FUN_007300a0("LEVEL");
        if (iVar6 == 0) {
LAB_0082539e:
          bVar3 = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar6 + 0x30);
          if (0xf < *(uint *)(iVar6 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_0082539e;
          bVar3 = FUN_008917b4(puVar7);
        }
        local_a8 = CONCAT13(bVar3,(undefined3)local_a8);
        iVar6 = FUN_007300a0("NEED_EXP");
        if (iVar6 == 0) {
LAB_008253ce:
          uVar4 = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar6 + 0x30);
          if (0xf < *(uint *)(iVar6 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_008253ce;
          uVar4 = FUN_008917b4(puVar7);
        }
        local_a8 = CONCAT22(local_a8._2_2_,uVar4);
        if (local_a1 < bVar3) {
          local_a1 = bVar3;
        }
        FUN_0083eab0();
        iVar6 = FUN_0072e3c0();
      } while (iVar6 != 0);
    }
    *local_ac = local_a1;
    local_a8 = FUN_0072e360();
    if (local_a8 != 0) {
      local_b0 = local_ac + 0x18;
      do {
        local_c0 = 0;
        local_bc = 0;
        local_b8 = 0;
        local_8 = CONCAT31(local_8._1_3_,1);
        iVar6 = FUN_007300a0("TOWN_NO");
        if (iVar6 == 0) {
LAB_0082549b:
          local_c4 = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar6 + 0x30);
          if (0xf < *(uint *)(iVar6 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_0082549b;
          local_c4 = FUN_008917b4(puVar7);
        }
        local_a1 = 0;
        iVar8 = FUN_0072e360();
        iVar6 = 0;
        if ((iVar8 != 0) &&
           (pbVar9 = (byte *)FUN_0072e360(), local_ac = pbVar9, pbVar9 != (byte *)0x0)) {
          do {
            pbVar13 = pbVar9 + 0x44;
            local_ac = pbVar9;
            for (pbVar10 = *(byte **)(pbVar9 + 0x94); pbVar10 != pbVar13;
                pbVar10 = *(byte **)(pbVar10 + 0x50)) {
              pbVar12 = pbVar10 + 0x14;
              if (0xf < *(uint *)(pbVar10 + 0x28)) {
                pbVar12 = *(byte **)pbVar12;
              }
              iVar6 = __stricmp((char *)pbVar12,"CONTRACT_NO");
              if (iVar6 == 0) {
                if (pbVar10 != (byte *)0x0) {
                  pbVar12 = pbVar10 + 0x30;
                  if (0xf < *(uint *)(pbVar10 + 0x44)) {
                    pbVar12 = *(byte **)pbVar12;
                  }
                  if (pbVar12 != (byte *)0x0) {
                    local_24 = FUN_008917b4(pbVar12);
                    goto LAB_0082551b;
                  }
                }
                break;
              }
            }
            local_24 = 0;
LAB_0082551b:
            for (pbVar10 = *(byte **)(pbVar9 + 0x94); pbVar10 != pbVar13;
                pbVar10 = *(byte **)(pbVar10 + 0x50)) {
              pbVar12 = pbVar10 + 0x14;
              if (0xf < *(uint *)(pbVar10 + 0x28)) {
                pbVar12 = *(byte **)pbVar12;
              }
              iVar6 = __stricmp((char *)pbVar12,"LEVEL");
              if (iVar6 == 0) {
                if (pbVar10 != (byte *)0x0) {
                  pbVar12 = pbVar10 + 0x30;
                  if (0xf < *(uint *)(pbVar10 + 0x44)) {
                    pbVar12 = *(byte **)pbVar12;
                  }
                  if (pbVar12 != (byte *)0x0) {
                    bVar3 = FUN_008917b4(pbVar12);
                    goto LAB_0082554e;
                  }
                }
                break;
              }
            }
            bVar3 = 0;
LAB_0082554e:
            local_23 = bVar3;
            for (pbVar10 = *(byte **)(pbVar9 + 0x94); pbVar10 != pbVar13;
                pbVar10 = *(byte **)(pbVar10 + 0x50)) {
              pbVar12 = pbVar10 + 0x14;
              if (0xf < *(uint *)(pbVar10 + 0x28)) {
                pbVar12 = *(byte **)pbVar12;
              }
              iVar6 = __stricmp((char *)pbVar12,"NEED_EXP");
              if (iVar6 == 0) {
                if (pbVar10 != (byte *)0x0) {
                  pbVar12 = pbVar10 + 0x30;
                  if (0xf < *(uint *)(pbVar10 + 0x44)) {
                    pbVar12 = *(byte **)pbVar12;
                  }
                  if (pbVar12 != (byte *)0x0) {
                    local_20 = FUN_008917b4(pbVar12);
                    goto LAB_0082558a;
                  }
                }
                break;
              }
            }
            local_20 = 0;
LAB_0082558a:
            for (pbVar9 = *(byte **)(pbVar9 + 0x94); pbVar9 != pbVar13;
                pbVar9 = *(byte **)(pbVar9 + 0x50)) {
              pbVar10 = pbVar9 + 0x14;
              if (0xf < *(uint *)(pbVar9 + 0x28)) {
                pbVar10 = *(byte **)pbVar10;
              }
              iVar6 = __stricmp((char *)pbVar10,"GUILD_REPUTATION_LEVELUP");
              if (iVar6 == 0) {
                if (pbVar9 != (byte *)0x0) {
                  pbVar13 = pbVar9 + 0x30;
                  if (0xf < *(uint *)(pbVar9 + 0x44)) {
                    pbVar13 = *(byte **)pbVar13;
                  }
                  if (pbVar13 != (byte *)0x0) {
                    iVar6 = __stricmp((char *)pbVar13,"true");
                    local_1c = (uint)(iVar6 == 0);
                    goto LAB_008255be;
                  }
                }
                break;
              }
            }
            local_1c = 0;
LAB_008255be:
            if (local_a1 < bVar3) {
              local_a1 = bVar3;
            }
            FUN_0085df00();
            pbVar9 = (byte *)FUN_0072e3c0();
          } while (pbVar9 != (byte *)0x0);
          local_ac = (byte *)0x0;
          iVar6 = local_c0;
        }
        local_c3 = local_a1;
        uVar11 = FUN_00825bb0();
        pbVar9 = local_b0;
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_00825cb0(uVar11);
        FUN_00825be0(pbVar9,local_cc);
        if (local_dc != 0) {
          FUN_0089120c(local_dc);
        }
        local_dc = 0;
        local_8 = local_8 & 0xffffff00;
        if (iVar6 != 0) {
          FUN_0089120c(iVar6);
        }
        local_a8 = FUN_0072e3c0();
      } while (local_a8 != 0);
    }
    local_8 = 0xffffffff;
    local_a0[0] = TiXmlDocument::vftable;
    if (0xf < local_40) {
      FUN_0089120c(local_54);
    }
    local_40 = 0xf;
    local_44 = 0;
    local_54 = local_54 & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

