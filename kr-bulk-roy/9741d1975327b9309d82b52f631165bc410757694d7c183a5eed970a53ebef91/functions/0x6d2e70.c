
void FUN_006d2e70(void)

{
  uint *puVar1;
  uint *puVar2;
  char cVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  char *pcVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  uint auStack_ac [4];
  undefined *puStack_9c;
  undefined **local_98 [19];
  uint uStack_4c;
  undefined4 uStack_3c;
  uint uStack_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092287b;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_ac;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff48;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar3 = FUN_0072f110(0);
  if (cVar3 == '\0') {
    FUN_006d32b0(uVar4);
    goto LAB_006d31f5;
  }
  piVar5 = (int *)FUN_0072e2e0("KeyMapping");
  if ((piVar5 != (int *)0x0) && (iVar6 = (**(code **)(*piVar5 + 0x14))(), iVar6 != 0)) {
    (**(code **)(*piVar5 + 0x14))();
  }
  iVar6 = FUN_007300a0("DefaultType");
  if (iVar6 == 0) {
LAB_006d2f45:
    DAT_00fdf668 = 0;
  }
  else {
    puVar7 = (undefined4 *)(iVar6 + 0x30);
    if (0xf < *(uint *)(iVar6 + 0x44)) {
      puVar7 = (undefined4 *)*puVar7;
    }
    if (puVar7 == (undefined4 *)0x0) goto LAB_006d2f45;
    DAT_00fdf668 = FUN_008917b4(puVar7);
  }
  auStack_ac[1] = FUN_0072e360();
  while (auStack_ac[1] != 0) {
    iVar6 = FUN_007300a0(&DAT_00c071fc);
    if (iVar6 == 0) {
LAB_006d30f8:
      uVar4 = 0;
    }
    else {
      puVar7 = (undefined4 *)(iVar6 + 0x30);
      if (0xf < *(uint *)(iVar6 + 0x44)) {
        puVar7 = (undefined4 *)*puVar7;
      }
      if (puVar7 == (undefined4 *)0x0) goto LAB_006d30f8;
      uVar4 = FUN_008917b4(puVar7);
      if (2 < uVar4) {
        local_c = 0xffffffff;
        local_98[0] = TiXmlDocument::vftable;
        if (uStack_38 < 0x10) goto LAB_006d325e;
        goto LAB_006d3256;
      }
    }
    auStack_ac[3] = FUN_0072e360();
    if (auStack_ac[3] != 0) {
      puStack_9c = &DAT_00fdf3f4 + uVar4 * 0x10;
      do {
        uVar9 = auStack_ac[3];
        uVar11 = auStack_ac[3] + 0x44;
        auStack_ac[0] = uVar11;
        for (uVar4 = *(uint *)(auStack_ac[3] + 0x94); uVar4 != uVar11;
            uVar4 = *(uint *)(uVar4 + 0x50)) {
          pcVar8 = (char *)(uVar4 + 0x14);
          if (0xf < *(uint *)(uVar4 + 0x28)) {
            pcVar8 = *(char **)pcVar8;
          }
          iVar6 = __stricmp(pcVar8,"MapButton");
          if (iVar6 == 0) {
            if (uVar4 != 0) {
              puVar7 = (undefined4 *)(uVar4 + 0x30);
              if (0xf < *(uint *)(uVar4 + 0x44)) {
                puVar7 = (undefined4 *)*puVar7;
              }
              if (puVar7 != (undefined4 *)0x0) {
                auStack_ac[2] = FUN_008917b4(puVar7);
                goto LAB_006d3019;
              }
            }
            break;
          }
        }
        auStack_ac[2] = 0;
LAB_006d3019:
        for (uVar4 = *(uint *)(uVar9 + 0x94); uVar4 != uVar11; uVar4 = *(uint *)(uVar4 + 0x50)) {
          pcVar8 = (char *)(uVar4 + 0x14);
          if (0xf < *(uint *)(uVar4 + 0x28)) {
            pcVar8 = *(char **)pcVar8;
          }
          iVar6 = __stricmp(pcVar8,"Key");
          if (iVar6 == 0) {
            if (uVar4 != 0) {
              puVar7 = (undefined4 *)(uVar4 + 0x30);
              if (0xf < *(uint *)(uVar4 + 0x44)) {
                puVar7 = (undefined4 *)*puVar7;
              }
              if (puVar7 != (undefined4 *)0x0) {
                uVar4 = FUN_008917b4(puVar7);
                goto LAB_006d304d;
              }
            }
            break;
          }
        }
        uVar4 = 0;
LAB_006d304d:
        uVar9 = *(uint *)(uVar9 + 0x94);
        if (uVar9 != uVar11) {
          do {
            pcVar8 = (char *)(uVar9 + 0x14);
            if (0xf < *(uint *)(uVar9 + 0x28)) {
              pcVar8 = *(char **)pcVar8;
            }
            iVar6 = __stricmp(pcVar8,"ModKey");
            if (iVar6 == 0) {
              if (uVar9 != 0) {
                puVar7 = (undefined4 *)(uVar9 + 0x30);
                if (0xf < *(uint *)(uVar9 + 0x44)) {
                  puVar7 = (undefined4 *)*puVar7;
                }
                if (puVar7 != (undefined4 *)0x0) {
                  uVar9 = FUN_008917b4(puVar7);
                  goto LAB_006d308b;
                }
              }
              break;
            }
            uVar9 = *(uint *)(uVar9 + 0x50);
          } while (uVar9 != auStack_ac[0]);
        }
        uVar9 = 0;
LAB_006d308b:
        uVar4 = (uVar9 & 0xff) << 0x10 | uVar4 & 0xff;
        auStack_ac[0] = uVar4;
        puVar10 = (uint *)FUN_006d43f0(puStack_9c);
        puVar1 = (uint *)puVar10[1];
        if (auStack_ac < puVar1) {
          puVar2 = (uint *)*puVar10;
          if (auStack_ac < puVar2) goto LAB_006d3179;
          if (puVar1 == (uint *)puVar10[2]) {
            FUN_006d6240();
          }
          if ((undefined4 *)puVar10[1] != (undefined4 *)0x0) {
            *(undefined4 *)puVar10[1] =
                 *(undefined4 *)(*puVar10 + ((int)auStack_ac - (int)puVar2 >> 2) * 4);
          }
        }
        else {
LAB_006d3179:
          if (puVar1 == (uint *)puVar10[2]) {
            FUN_006d6240();
          }
          if ((uint *)puVar10[1] != (uint *)0x0) {
            *(uint *)puVar10[1] = uVar4;
          }
        }
        puVar10[1] = puVar10[1] + 4;
        auStack_ac[3] = FUN_0072e3c0();
      } while (auStack_ac[3] != 0);
    }
    auStack_ac[1] = FUN_0072e3c0();
  }
LAB_006d31f5:
  if (((DAT_00fdf668 == 0) || (DAT_00fdf668 == 1)) &&
     (iVar6 = DAT_00fdf668 * 0x10, &DAT_00fdf3f4 + iVar6 != &DAT_00fdf414)) {
    FUN_0085e680(*DAT_00fdf418,DAT_00fdf418);
    FUN_006d4530(&DAT_00fdf3f4 + iVar6);
  }
  local_c = 0xffffffff;
  local_98[0] = TiXmlDocument::vftable;
  if (0xf < uStack_38) {
LAB_006d3256:
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    FUN_0089120c(uStack_4c);
  }
LAB_006d325e:
  uStack_38 = 0xf;
  uStack_3c = 0;
  uStack_4c = uStack_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_ac);
  return;
}

