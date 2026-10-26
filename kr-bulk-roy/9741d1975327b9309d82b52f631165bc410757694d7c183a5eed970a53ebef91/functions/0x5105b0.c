
void FUN_005105b0(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint *puVar6;
  char *pcVar7;
  uint *puVar8;
  char *pcVar9;
  uint *puVar10;
  uint *puStack_11c;
  uint *local_118;
  int local_114;
  uint *puStack_110;
  uint local_10c [6];
  undefined4 local_f4;
  uint local_f0;
  uint *local_e8;
  uint *local_e4;
  undefined4 local_e0;
  uint local_d8 [4];
  undefined4 local_c8;
  uint local_c4;
  uint local_bc;
  undefined4 uStack_b8;
  uint uStack_b4;
  undefined4 local_ac;
  uint local_a8;
  undefined4 uStack_a4;
  uint uStack_a0;
  undefined **local_98 [17];
  char local_54;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00923fdc;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&puStack_11c;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffed8;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  FUN_0072f110(0);
  if (local_54 == '\0') {
    iVar3 = FUN_0072e2e0("BUFFEXPLAINTABLE");
    if (iVar3 == 0) {
      FUN_006edb60("BUFF Explain Table Error!");
      local_c = 0xffffffff;
      local_98[0] = TiXmlDocument::vftable;
      if (0xf < local_38) {
        FUN_0089120c(local_4c);
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      FUN_0072e040();
    }
    else {
      local_114 = FUN_0072e360(uVar2);
      if (local_114 != 0) {
        local_118 = (uint *)(param_1 + 8);
        do {
          local_f0 = 7;
          local_f4 = 0;
          local_10c[2] = local_10c[2] & 0xffff0000;
          local_e8 = (uint *)0x0;
          local_e4 = (uint *)0x0;
          local_e0 = 0;
          local_c = CONCAT31(local_c._1_3_,1);
          iVar3 = FUN_007300a0(&DAT_00bfaf5c);
          if (iVar3 == 0) {
LAB_00510798:
            local_10c[0] = 0;
          }
          else {
            puVar4 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar4 = (undefined4 *)*puVar4;
            }
            if (puVar4 == (undefined4 *)0x0) goto LAB_00510798;
            local_10c[0] = FUN_008917b4(puVar4);
          }
          iVar3 = FUN_007300a0("attribute");
          if (iVar3 == 0) {
LAB_005107c6:
            local_10c[1] = 0;
          }
          else {
            puVar4 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar4 = (undefined4 *)*puVar4;
            }
            if (puVar4 == (undefined4 *)0x0) goto LAB_005107c6;
            local_10c[1] = FUN_008917b4(puVar4);
          }
          local_c4 = 0xf;
          local_c8 = 0;
          local_d8[0] = local_d8[0] & 0xffffff00;
          FUN_00402a70(&DAT_00bed1d4,4);
          local_c._0_1_ = 2;
          uVar5 = FUN_0072ecf0(&DAT_00bf2375);
          local_c = CONCAT31(local_c._1_3_,3);
          FUN_00440130(uVar5);
          if (0xf < local_a8) {
            FUN_0089120c(local_bc);
          }
          local_c = CONCAT31(local_c._1_3_,1);
          local_a8 = 0xf;
          local_ac = 0;
          local_bc = local_bc & 0xffffff00;
          if (0xf < local_c4) {
            FUN_0089120c(local_d8[0]);
          }
          puVar6 = (uint *)FUN_0072e360();
          while (puStack_11c = puVar6, puVar6 != (uint *)0x0) {
            local_bc = 0;
            uStack_b8 = 0;
            uStack_a0 = 7;
            uStack_a4 = 0;
            uStack_b4 = uStack_b4 & 0xffff0000;
            local_c._1_3_ = (uint3)((uint)local_c >> 8);
            local_c._0_1_ = 4;
            for (puVar10 = (uint *)puVar6[0x25]; puVar10 != puVar6 + 0x11;
                puVar10 = (uint *)puVar10[0x14]) {
              puVar8 = puVar10 + 5;
              if (0xf < puVar10[10]) {
                puVar8 = (uint *)*puVar8;
              }
              iVar3 = __stricmp((char *)puVar8,"val");
              if (iVar3 == 0) {
                if (puVar10 != (uint *)0x0) {
                  puVar8 = puVar10 + 0xc;
                  if (0xf < puVar10[0x11]) {
                    puVar8 = (uint *)*puVar8;
                  }
                  if (puVar8 != (uint *)0x0) {
                    local_bc = FUN_008917b4(puVar8);
                    goto LAB_005108ea;
                  }
                }
                break;
              }
            }
            local_bc = 0;
LAB_005108ea:
            for (puVar10 = (uint *)puVar6[0x25]; puVar10 != puVar6 + 0x11;
                puVar10 = (uint *)puVar10[0x14]) {
              puVar8 = puVar10 + 5;
              if (0xf < puVar10[10]) {
                puVar8 = (uint *)*puVar8;
              }
              iVar3 = __stricmp((char *)puVar8,"time");
              if (iVar3 == 0) {
                if (puVar10 != (uint *)0x0) {
                  puVar6 = puVar10 + 0xc;
                  if (0xf < puVar10[0x11]) {
                    puVar6 = (uint *)*puVar6;
                  }
                  if (puVar6 != (uint *)0x0) {
                    uStack_b8 = FUN_008917b4(puVar6);
                    goto LAB_00510922;
                  }
                }
                break;
              }
            }
            uStack_b8 = 0;
LAB_00510922:
            if (((int *)puStack_11c[6] != (int *)0x0) &&
               (iVar3 = (**(code **)(*(int *)puStack_11c[6] + 0x30))(), iVar3 != 0)) {
              pcVar9 = (char *)(iVar3 + 0x20);
              if (0xf < *(uint *)(iVar3 + 0x34)) {
                pcVar9 = *(char **)pcVar9;
              }
              if (pcVar9 != (char *)0x0) {
                local_c4 = 0xf;
                local_c8 = 0;
                local_d8[0] = local_d8[0] & 0xffffff00;
                pcVar7 = pcVar9;
                do {
                  cVar1 = *pcVar7;
                  pcVar7 = pcVar7 + 1;
                } while (cVar1 != '\0');
                FUN_00402a70(pcVar9,(int)pcVar7 - (int)(pcVar9 + 1));
                local_c._0_1_ = 5;
                FUN_00440130(local_d8);
                local_c._0_1_ = 4;
                if (0xf < local_c4) {
                  FUN_0089120c(local_d8[0]);
                }
              }
            }
            FUN_0049e530();
            local_c = CONCAT31(local_c._1_3_,1);
            if (7 < uStack_a0) {
              FUN_0089120c(uStack_b4);
            }
            puVar6 = (uint *)FUN_0072e3c0();
          }
          puVar6 = (uint *)local_118[1];
          if ((local_10c < puVar6) && (puVar10 = (uint *)*local_118, puVar10 <= local_10c)) {
            if (puVar6 == (uint *)local_118[2]) {
              FUN_00510d90();
            }
            puVar6 = (uint *)local_118[1];
            puVar10 = (uint *)((((int)local_10c - (int)puVar10) / 0x34) * 0x34 + *local_118);
            local_c._0_1_ = 6;
            puStack_11c = puVar6;
            puStack_110 = puVar6;
            if (puVar6 != (uint *)0x0) {
              *puVar6 = *puVar10;
              puVar6[1] = puVar10[1];
              puVar6[7] = 7;
              puVar6[6] = 0;
              *(undefined2 *)(puVar6 + 2) = 0;
              FUN_004026e0(puVar10 + 2,0,0xffffffff);
              local_c._0_1_ = 7;
              FUN_00510fd0(puVar6 + 9,puVar10 + 9);
            }
            local_118[1] = local_118[1] + 0x34;
          }
          else {
            if (puVar6 == (uint *)local_118[2]) {
              FUN_00510d90();
            }
            puVar10 = local_118;
            puVar6 = (uint *)local_118[1];
            local_c._0_1_ = 8;
            puStack_11c = puVar6;
            puStack_110 = puVar6;
            if (puVar6 != (uint *)0x0) {
              *puVar6 = local_10c[0];
              puVar6[1] = local_10c[1];
              puVar6[7] = 7;
              puVar6[6] = 0;
              *(undefined2 *)(puVar6 + 2) = 0;
              FUN_004026e0(local_10c + 2,0,0xffffffff);
              local_c._0_1_ = 9;
              FUN_00510fd0(puVar6 + 9,&local_e8);
            }
            puVar10[1] = puVar10[1] + 0x34;
          }
          puVar6 = local_e4;
          local_c = (uint)local_c._1_3_ << 8;
          if (local_e8 != (uint *)0x0) {
            if (local_e8 != local_e4) {
              puVar10 = local_e8 + 7;
              do {
                if (7 < *puVar10) {
                  FUN_0089120c(puVar10[-5]);
                }
                *puVar10 = 7;
                puVar10[-1] = 0;
                *(undefined2 *)(puVar10 + -5) = 0;
                puVar8 = puVar10 + 2;
                puVar10 = puVar10 + 9;
              } while (puVar8 != puVar6);
            }
            FUN_0089120c(local_e8);
          }
          local_e8 = (uint *)0x0;
          local_e4 = (uint *)0x0;
          local_e0 = 0;
          if (7 < local_f0) {
            FUN_0089120c(local_10c[2]);
          }
          local_f0 = 7;
          local_f4 = 0;
          local_10c[2] = local_10c[2] & 0xffff0000;
          local_114 = FUN_0072e3c0();
        } while (local_114 != 0);
      }
      local_c = 0xffffffff;
      local_98[0] = TiXmlDocument::vftable;
      if (0xf < local_38) {
        FUN_0089120c(local_4c);
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      FUN_0072e040();
    }
  }
  else {
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
    local_38 = 0xf;
    local_3c = 0;
    local_4c = local_4c & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&puStack_11c);
  return;
}

