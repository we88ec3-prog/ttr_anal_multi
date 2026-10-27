
void FUN_006d08f0(void)

{
  uint *puVar1;
  uint *puVar2;
  char cVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  int *unaff_FS_OFFSET;
  uint auStack_ac [5];
  undefined **local_98 [19];
  uint local_4c;
  undefined4 uStack_3c;
  uint local_38;
  uint local_1c;
  int local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092287b;
  local_14 = *unaff_FS_OFFSET;
  local_1c = DAT_00d61f20 ^ (uint)auStack_ac;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff48;
  *unaff_FS_OFFSET = (int)&local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar3 = FUN_0072f110(0);
  if (cVar3 == '\0') {
    FUN_006d0eb0(uVar4);
    goto joined_r0x006d0c74;
  }
  piVar5 = (int *)FUN_0072e2e0("KeyMapping");
  if ((piVar5 != (int *)0x0) && (iVar6 = (**(code **)(*piVar5 + 0x14))(), iVar6 != 0)) {
    (**(code **)(*piVar5 + 0x14))();
  }
  iVar6 = FUN_007300a0("DefaultType");
  if (iVar6 == 0) {
LAB_006d09c8:
    DAT_00fb9034 = 0;
  }
  else {
    puVar7 = (undefined4 *)(iVar6 + 0x30);
    if (0xf < *(uint *)(iVar6 + 0x44)) {
      puVar7 = (undefined4 *)*puVar7;
    }
    if (puVar7 == (undefined4 *)0x0) goto LAB_006d09c8;
    DAT_00fb9034 = FUN_008917b4(puVar7);
  }
  auStack_ac[2] = FUN_0072e360();
  while (auStack_ac[2] != 0) {
    iVar6 = FUN_007300a0(&DAT_00c071fc);
    if (iVar6 == 0) {
LAB_006d0b71:
      uVar4 = 0;
    }
    else {
      puVar7 = (undefined4 *)(iVar6 + 0x30);
      if (0xf < *(uint *)(iVar6 + 0x44)) {
        puVar7 = (undefined4 *)*puVar7;
      }
      if (puVar7 == (undefined4 *)0x0) goto LAB_006d0b71;
      uVar4 = FUN_008917b4(puVar7);
      if (2 < uVar4) goto LAB_006d0c92;
    }
    iVar6 = FUN_0072e360();
    auStack_ac[1] = iVar6;
    if (iVar6 != 0) {
      auStack_ac[4] = uVar4 * 0x28;
      do {
        uVar4 = iVar6 + 0x44;
        auStack_ac[0] = uVar4;
        auStack_ac[1] = iVar6;
        for (uVar10 = *(uint *)(iVar6 + 0x94); uVar10 != uVar4; uVar10 = *(uint *)(uVar10 + 0x50)) {
          pcVar9 = (char *)(uVar10 + 0x14);
          if (0xf < *(uint *)(uVar10 + 0x28)) {
            pcVar9 = *(char **)pcVar9;
          }
          iVar8 = __stricmp(pcVar9,"MapButton");
          if (iVar8 == 0) {
            if (uVar10 != 0) {
              puVar7 = (undefined4 *)(uVar10 + 0x30);
              if (0xf < *(uint *)(uVar10 + 0x44)) {
                puVar7 = (undefined4 *)*puVar7;
              }
              if (puVar7 != (undefined4 *)0x0) {
                auStack_ac[3] = FUN_008917b4(puVar7);
                goto LAB_006d0a96;
              }
            }
            break;
          }
        }
        auStack_ac[3] = 0;
LAB_006d0a96:
        for (uVar10 = *(uint *)(iVar6 + 0x94); uVar10 != uVar4; uVar10 = *(uint *)(uVar10 + 0x50)) {
          pcVar9 = (char *)(uVar10 + 0x14);
          if (0xf < *(uint *)(uVar10 + 0x28)) {
            pcVar9 = *(char **)pcVar9;
          }
          iVar8 = __stricmp(pcVar9,"Key");
          if (iVar8 == 0) {
            if (uVar10 != 0) {
              puVar7 = (undefined4 *)(uVar10 + 0x30);
              if (0xf < *(uint *)(uVar10 + 0x44)) {
                puVar7 = (undefined4 *)*puVar7;
              }
              if (puVar7 != (undefined4 *)0x0) {
                uVar10 = FUN_008917b4(puVar7);
                goto LAB_006d0ac9;
              }
            }
            break;
          }
        }
        uVar10 = 0;
LAB_006d0ac9:
        uVar11 = *(uint *)(iVar6 + 0x94);
        if (uVar11 != uVar4) {
          do {
            pcVar9 = (char *)(uVar11 + 0x14);
            if (0xf < *(uint *)(uVar11 + 0x28)) {
              pcVar9 = *(char **)pcVar9;
            }
            iVar6 = __stricmp(pcVar9,"ModKey");
            if (iVar6 == 0) {
              if (uVar11 != 0) {
                puVar7 = (undefined4 *)(uVar11 + 0x30);
                if (0xf < *(uint *)(uVar11 + 0x44)) {
                  puVar7 = (undefined4 *)*puVar7;
                }
                if (puVar7 != (undefined4 *)0x0) {
                  uVar4 = FUN_008917b4(puVar7);
                  goto LAB_006d0b00;
                }
              }
              break;
            }
            uVar11 = *(uint *)(uVar11 + 0x50);
          } while (uVar11 != auStack_ac[0]);
        }
        uVar4 = 0;
LAB_006d0b00:
        iVar6 = (auStack_ac[4] + auStack_ac[3]) * 0x10;
        uVar4 = (uVar4 & 0xff) << 0x10 | uVar10 & 0xff;
        puVar1 = *(uint **)(&DAT_00fb8838 + iVar6);
        auStack_ac[0] = uVar4;
        if (auStack_ac < puVar1) {
          puVar2 = *(uint **)(&DAT_00fb8834 + iVar6);
          if (auStack_ac < puVar2) goto LAB_006d0bf6;
          if (puVar1 == *(uint **)(&DAT_00fb883c + iVar6)) {
            FUN_006d6240();
          }
          if (*(undefined4 **)(&DAT_00fb8838 + iVar6) != (undefined4 *)0x0) {
            **(undefined4 **)(&DAT_00fb8838 + iVar6) =
                 *(undefined4 *)
                  (*(uint *)(&DAT_00fb8834 + iVar6) + ((int)auStack_ac - (int)puVar2 >> 2) * 4);
          }
        }
        else {
LAB_006d0bf6:
          if (puVar1 == *(uint **)(&DAT_00fb883c + iVar6)) {
            FUN_006d6240();
          }
          if (*(uint **)(&DAT_00fb8838 + iVar6) != (uint *)0x0) {
            **(uint **)(&DAT_00fb8838 + iVar6) = uVar4;
          }
        }
        *(int *)(&DAT_00fb8838 + iVar6) = *(int *)(&DAT_00fb8838 + iVar6) + 4;
        iVar6 = FUN_0072e3c0();
      } while (iVar6 != 0);
      auStack_ac[1] = 0;
    }
    auStack_ac[2] = FUN_0072e3c0();
  }
joined_r0x006d0c74:
  if ((DAT_00fb9034 == 0) || (DAT_00fb9034 == 1)) {
    FUN_006d1be0(&DAT_00fb8d34,&DAT_00fb8834 + DAT_00fb9034 * 0x280);
  }
LAB_006d0c92:
  local_c = 0xffffffff;
  local_98[0] = TiXmlDocument::vftable;
  if (0xf < local_38) {
    FUN_0089120c(local_4c);
  }
  local_38 = 0xf;
  uStack_3c = 0;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  *unaff_FS_OFFSET = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_ac);
  return;
}

