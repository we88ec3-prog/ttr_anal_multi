
/* WARNING: Removing unreachable block (ram,0x0052ecad) */
/* WARNING: Removing unreachable block (ram,0x0052ee81) */

void FUN_0052eb80(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  undefined **local_a0 [17];
  char local_5c;
  uint local_54;
  undefined4 local_44;
  uint local_40;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00923696;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar3;
  FUN_0072ee30(local_a0);
  local_8 = 0;
  FUN_0072f110(0);
  if ((local_5c == '\0') && (iVar4 = FUN_0072e2e0("SCENARIOTALKTABLE"), iVar4 != 0)) {
    local_8 = CONCAT31(local_8._1_3_,1);
    for (piVar1 = *(int **)(iVar4 + 0x18); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x10]) {
      (**(code **)(*piVar1 + 0x14))(uVar3);
      iVar4 = FUN_007300a0(&DAT_00bed1d0);
      if (iVar4 != 0) {
        puVar5 = (undefined4 *)(iVar4 + 0x30);
        if (0xf < *(uint *)(iVar4 + 0x44)) {
          puVar5 = (undefined4 *)*puVar5;
        }
        if (puVar5 != (undefined4 *)0x0) {
          FUN_008917b4(puVar5);
        }
      }
      iVar4 = FUN_007300a0("scene");
      if (iVar4 != 0) {
        puVar5 = (undefined4 *)(iVar4 + 0x30);
        if (0xf < *(uint *)(iVar4 + 0x44)) {
          puVar5 = (undefined4 *)*puVar5;
        }
        if (puVar5 != (undefined4 *)0x0) {
          FUN_008917b4(puVar5);
        }
      }
      iVar4 = FUN_007300a0(&DAT_00c0efc0);
      if (iVar4 != 0) {
        puVar5 = (undefined4 *)(iVar4 + 0x30);
        if (0xf < *(uint *)(iVar4 + 0x44)) {
          puVar5 = (undefined4 *)*puVar5;
        }
        if (puVar5 != (undefined4 *)0x0) {
          FUN_008917b4(puVar5);
        }
      }
      if (piVar1[6] != 0) {
        for (piVar2 = *(int **)(piVar1[6] + 0x18); piVar2 != (int *)0x0;
            piVar2 = (int *)piVar2[0x10]) {
          iVar6 = (**(code **)(*piVar2 + 0x14))();
          for (iVar4 = *(int *)(iVar6 + 0x94); iVar4 != iVar6 + 0x44; iVar4 = *(int *)(iVar4 + 0x50)
              ) {
            pcVar8 = (char *)(iVar4 + 0x14);
            if (0xf < *(uint *)(iVar4 + 0x28)) {
              pcVar8 = *(char **)pcVar8;
            }
            iVar7 = __stricmp(pcVar8,"char");
            if (iVar7 == 0) {
              if (iVar4 != 0) {
                puVar5 = (undefined4 *)(iVar4 + 0x30);
                if (0xf < *(uint *)(iVar4 + 0x44)) {
                  puVar5 = (undefined4 *)*puVar5;
                }
                if (puVar5 != (undefined4 *)0x0) {
                  local_24 = FUN_008917b4(puVar5);
                  local_1c = 0;
                  goto LAB_0052ee00;
                }
              }
              break;
            }
          }
          iVar4 = FUN_007300a0(&DAT_00c0efc4);
          if (iVar4 == 0) {
LAB_0052ef1e:
            local_24 = 0;
          }
          else {
            puVar5 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) goto LAB_0052ef1e;
            local_24 = FUN_008917b4(puVar5);
            local_1c = 1;
          }
LAB_0052ee00:
          for (iVar4 = *(int *)(iVar6 + 0x94); iVar4 != iVar6 + 0x44; iVar4 = *(int *)(iVar4 + 0x50)
              ) {
            pcVar8 = (char *)(iVar4 + 0x14);
            if (0xf < *(uint *)(iVar4 + 0x28)) {
              pcVar8 = *(char **)pcVar8;
            }
            iVar7 = __stricmp(pcVar8,"talk");
            if (iVar7 == 0) {
              if (iVar4 != 0) {
                puVar5 = (undefined4 *)(iVar4 + 0x30);
                if (0xf < *(uint *)(iVar4 + 0x44)) {
                  puVar5 = (undefined4 *)*puVar5;
                }
                if (puVar5 != (undefined4 *)0x0) {
                  local_20 = FUN_008917b4(puVar5);
                  goto LAB_0052ee36;
                }
              }
              break;
            }
          }
          local_20 = 0;
LAB_0052ee36:
          FUN_0052ef90();
        }
      }
      FUN_0052f010();
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
  else {
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
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

