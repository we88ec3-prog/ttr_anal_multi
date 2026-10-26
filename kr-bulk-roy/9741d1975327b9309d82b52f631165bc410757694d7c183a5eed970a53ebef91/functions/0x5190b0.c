
void FUN_005190b0(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined1 auStack_10c [4];
  int local_108;
  int local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 *local_e8;
  undefined4 *local_e4;
  undefined4 *local_e0;
  undefined4 local_d8 [4];
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  int local_b0 [4];
  undefined1 local_a0 [8];
  undefined **local_98 [17];
  char local_54;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00923cd1;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_10c;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffee8;
  ExceptionList = &local_14;
  local_d8[2] = param_1;
  FUN_0072ed80(local_98);
  local_c = 0;
  FUN_0072f110(0);
  if (local_54 != '\0') {
    FUN_006edb60(&DAT_00c0e4dc,uVar2);
  }
  iVar3 = FUN_0072e2e0("ITEM_COMPOUND");
  if (iVar3 == 0) {
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  else {
    local_108 = FUN_0072e360();
    while (local_108 != 0) {
      local_e8 = (undefined4 *)0x0;
      local_e4 = (undefined4 *)0x0;
      local_e0 = (undefined4 *)0x0;
      local_c._1_3_ = (undefined3)(local_c >> 8);
      local_c = CONCAT31(local_c._1_3_,1);
      iVar3 = FUN_007300a0("product");
      if (iVar3 == 0) {
LAB_005191e0:
        uVar5 = 0;
      }
      else {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_005191e0;
        uVar5 = FUN_008917b4(puVar4);
      }
      local_100 = uVar5;
      iVar3 = FUN_007300a0("charge");
      if (iVar3 == 0) {
LAB_00519210:
        local_f8 = 0;
      }
      else {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_00519210;
        local_f8 = FUN_008917b4(puVar4);
      }
      iVar3 = FUN_007300a0(&DAT_00bfb854);
      if (iVar3 == 0) {
LAB_0051923e:
        local_fc = 0;
      }
      else {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_0051923e;
        local_fc = FUN_008917b4(puVar4);
      }
      iVar3 = FUN_007300a0(&DAT_00c0e4bc);
      if (iVar3 == 0) {
LAB_0051926c:
        local_f4 = 100;
      }
      else {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_0051926c;
        local_f4 = FUN_008917b4(puVar4);
      }
      iVar3 = FUN_007300a0("period");
      if (iVar3 == 0) {
LAB_0051929d:
        local_f0 = 0;
      }
      else {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_0051929d;
        local_f0 = FUN_008917b4(puVar4);
      }
      iVar3 = FUN_007300a0("Quest");
      if (iVar3 == 0) {
LAB_005192cb:
        local_ec = 0;
      }
      else {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_005192cb;
        local_ec = FUN_008917b4(puVar4);
      }
      iVar3 = FUN_0072e360();
      if ((iVar3 != 0) && (iVar3 = FUN_0072e360(), local_104 = iVar3, iVar3 != 0)) {
        do {
          local_104 = iVar3;
          for (iVar1 = *(int *)(iVar3 + 0x94); iVar1 != iVar3 + 0x44; iVar1 = *(int *)(iVar1 + 0x50)
              ) {
            pcVar7 = (char *)(iVar1 + 0x14);
            if (0xf < *(uint *)(iVar1 + 0x28)) {
              pcVar7 = *(char **)pcVar7;
            }
            iVar6 = __stricmp(pcVar7,"item");
            if (iVar6 == 0) {
              if (iVar1 != 0) {
                puVar4 = (undefined4 *)(iVar1 + 0x30);
                if (0xf < *(uint *)(iVar1 + 0x44)) {
                  puVar4 = (undefined4 *)*puVar4;
                }
                if (puVar4 != (undefined4 *)0x0) {
                  uVar5 = FUN_008917b4(puVar4);
                  goto LAB_0051933b;
                }
              }
              break;
            }
          }
          uVar5 = 0;
LAB_0051933b:
          local_d8[0] = uVar5;
          for (iVar1 = *(int *)(iVar3 + 0x94); iVar1 != iVar3 + 0x44; iVar1 = *(int *)(iVar1 + 0x50)
              ) {
            pcVar7 = (char *)(iVar1 + 0x14);
            if (0xf < *(uint *)(iVar1 + 0x28)) {
              pcVar7 = *(char **)pcVar7;
            }
            iVar6 = __stricmp(pcVar7,"qty");
            if (iVar6 == 0) {
              if (iVar1 != 0) {
                puVar4 = (undefined4 *)(iVar1 + 0x30);
                if (0xf < *(uint *)(iVar1 + 0x44)) {
                  puVar4 = (undefined4 *)*puVar4;
                }
                if (puVar4 != (undefined4 *)0x0) {
                  uVar8 = FUN_008917b4(puVar4);
                  goto LAB_0051937a;
                }
              }
              break;
            }
          }
          uVar8 = 0;
LAB_0051937a:
          local_d8[1] = uVar8;
          if ((local_d8 < local_e4) && (local_e8 <= local_d8)) {
            iVar3 = (int)local_d8 - (int)local_e8 >> 3;
            if (local_e4 == local_e0) {
              uVar2 = (int)local_e4 - (int)local_e8 >> 3;
              if (0x1ffffffe < uVar2) {
LAB_005195fe:
                    /* WARNING: Subroutine does not return */
                FUN_0087db30("vector<T> too long");
              }
              uVar2 = uVar2 + 1;
              uVar9 = (int)local_e0 - (int)local_e8 >> 3;
              if (uVar9 < uVar2) {
                if (0x1fffffff - (uVar9 >> 1) < uVar9) {
                  uVar9 = 0;
                }
                else {
                  uVar9 = uVar9 + (uVar9 >> 1);
                }
                if (uVar9 < uVar2) {
                  uVar9 = uVar2;
                }
                FUN_004e7330(uVar9);
              }
            }
            if (local_e4 != (undefined4 *)0x0) {
              *local_e4 = local_e8[iVar3 * 2];
              local_e4[1] = local_e8[iVar3 * 2 + 1];
            }
          }
          else {
            if (local_e4 == local_e0) {
              uVar2 = (int)local_e4 - (int)local_e8 >> 3;
              if (0x1ffffffe < uVar2) goto LAB_005195fe;
              uVar2 = uVar2 + 1;
              uVar9 = (int)local_e0 - (int)local_e8 >> 3;
              if (uVar9 < uVar2) {
                if (0x1fffffff - (uVar9 >> 1) < uVar9) {
                  uVar9 = 0;
                }
                else {
                  uVar9 = uVar9 + (uVar9 >> 1);
                }
                if (uVar9 < uVar2) {
                  uVar9 = uVar2;
                }
                FUN_004e7330(uVar9);
              }
            }
            if (local_e4 != (undefined4 *)0x0) {
              *local_e4 = uVar5;
              local_e4[1] = uVar8;
            }
          }
          local_e4 = local_e4 + 2;
          iVar3 = FUN_0072e3c0();
        } while (iVar3 != 0);
        local_104 = 0;
        uVar5 = local_100;
      }
      local_c4 = local_fc;
      local_bc = local_f4;
      local_b8 = local_f0;
      local_c0 = local_f8;
      local_b4 = local_ec;
      local_d8[3] = uVar5;
      local_c8 = uVar5;
      FUN_004fcd00(local_b0,&local_e8);
      uVar5 = local_d8[2];
      local_c = CONCAT31(local_c._1_3_,2);
      FUN_00519d50(local_d8 + 3);
      FUN_00519ae0(uVar5,local_a0);
      if (local_b0[0] != 0) {
        FUN_0089120c(local_b0[0]);
      }
      local_c = local_c & 0xffffff00;
      if (local_e8 != (undefined4 *)0x0) {
        FUN_0089120c(local_e8);
      }
      local_108 = FUN_0072e3c0();
    }
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  local_3c = 0;
  local_38 = 0xf;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_10c);
  return;
}

