
/* WARNING: Removing unreachable block (ram,0x0052540a) */
/* WARNING: Removing unreachable block (ram,0x0052552d) */

void FUN_005252f0(undefined4 param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint *puVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 *puVar14;
  undefined4 local_70;
  undefined4 local_6c;
  uint local_5c;
  uint local_48;
  undefined4 local_24 [4];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917070;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = FUN_0072e360(local_14);
  pvVar1 = ExceptionList;
  ExceptionList = local_10;
  do {
    local_10 = ExceptionList;
    if (iVar2 == 0) {
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    for (iVar5 = *(int *)(iVar2 + 0x94); ExceptionList = pvVar1, iVar5 != iVar2 + 0x44;
        iVar5 = *(int *)(iVar5 + 0x50)) {
      pcVar9 = (char *)(iVar5 + 0x14);
      if (0xf < *(uint *)(iVar5 + 0x28)) {
        pcVar9 = *(char **)pcVar9;
      }
      iVar3 = __stricmp(pcVar9,"ID");
      if (iVar3 == 0) {
        if (iVar5 != 0) {
          puVar6 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar6 = (undefined4 *)*puVar6;
          }
          if (puVar6 != (undefined4 *)0x0) {
            uVar4 = FUN_008917b4(puVar6);
            goto LAB_0052537e;
          }
        }
        break;
      }
      pvVar1 = ExceptionList;
    }
    uVar4 = 0;
LAB_0052537e:
    iVar2 = FUN_00526f60(param_1,uVar4);
    if (*(int *)(iVar2 + 0x14) == 0) {
      FUN_00402a70(&DAT_00c0ce30,4);
      local_8 = 0;
      uVar4 = FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_00440130(uVar4);
      if (0xf < local_48) {
        FUN_0089120c(local_5c);
      }
      local_8 = 0xffffffff;
      local_48 = 0xf;
      local_5c = local_5c & 0xffffff00;
    }
    iVar5 = FUN_0072e360();
    if (iVar5 != 0) {
      iVar5 = FUN_007300a0(&DAT_00c0ecb8);
      if (iVar5 == 0) {
LAB_00525485:
        local_70 = 0;
      }
      else {
        puVar6 = (undefined4 *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          puVar6 = (undefined4 *)*puVar6;
        }
        if (puVar6 == (undefined4 *)0x0) goto LAB_00525485;
        local_70 = FUN_008917b4(puVar6);
      }
      iVar5 = FUN_007300a0(&DAT_00c0ecbc);
      if (iVar5 == 0) {
LAB_005254b3:
        local_6c = 0;
      }
      else {
        puVar6 = (undefined4 *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          puVar6 = (undefined4 *)*puVar6;
        }
        if (puVar6 == (undefined4 *)0x0) goto LAB_005254b3;
        local_6c = FUN_008917b4(puVar6);
      }
      FUN_00402a70("GROUP",5);
      local_8 = 2;
      uVar4 = FUN_0072ecf0(&DAT_00bf2375);
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_00402bb0(uVar4);
      if (0xf < local_48) {
        FUN_0089120c(local_5c);
      }
      local_48 = 0xf;
      local_5c = local_5c & 0xffffff00;
      local_8 = 0xffffffff;
      iVar5 = FUN_0072e360();
      if (iVar5 != 0) {
        puVar7 = (uint *)(iVar2 + 0x6c);
        do {
          iVar3 = iVar5 + 0x44;
          for (iVar10 = *(int *)(iVar5 + 0x94); iVar10 != iVar3; iVar10 = *(int *)(iVar10 + 0x50)) {
            pcVar9 = (char *)(iVar10 + 0x14);
            if (0xf < *(uint *)(iVar10 + 0x28)) {
              pcVar9 = *(char **)pcVar9;
            }
            iVar8 = __stricmp(pcVar9,"ID");
            if (iVar8 == 0) {
              if (iVar10 != 0) {
                puVar6 = (undefined4 *)(iVar10 + 0x30);
                if (0xf < *(uint *)(iVar10 + 0x44)) {
                  puVar6 = (undefined4 *)*puVar6;
                }
                if (puVar6 != (undefined4 *)0x0) {
                  local_24[0] = FUN_008917b4(puVar6);
                  goto LAB_0052559b;
                }
              }
              break;
            }
          }
          local_24[0] = 0;
LAB_0052559b:
          for (iVar10 = *(int *)(iVar5 + 0x94); iVar10 != iVar3; iVar10 = *(int *)(iVar10 + 0x50)) {
            pcVar9 = (char *)(iVar10 + 0x14);
            if (0xf < *(uint *)(iVar10 + 0x28)) {
              pcVar9 = *(char **)pcVar9;
            }
            iVar8 = __stricmp(pcVar9,"ITEM");
            if (iVar8 == 0) {
              if (iVar10 != 0) {
                puVar6 = (undefined4 *)(iVar10 + 0x30);
                if (0xf < *(uint *)(iVar10 + 0x44)) {
                  puVar6 = (undefined4 *)*puVar6;
                }
                if (puVar6 != (undefined4 *)0x0) {
                  local_24[3] = FUN_008917b4(puVar6);
                  goto LAB_005255ce;
                }
              }
              break;
            }
          }
          local_24[3] = 0;
LAB_005255ce:
          for (iVar10 = *(int *)(iVar5 + 0x94); uVar4 = local_70, iVar10 != iVar3;
              iVar10 = *(int *)(iVar10 + 0x50)) {
            pcVar9 = (char *)(iVar10 + 0x14);
            if (0xf < *(uint *)(iVar10 + 0x28)) {
              pcVar9 = *(char **)pcVar9;
            }
            iVar8 = __stricmp(pcVar9,"X");
            if (iVar8 == 0) {
              if (iVar10 != 0) {
                puVar6 = (undefined4 *)(iVar10 + 0x30);
                if (0xf < *(uint *)(iVar10 + 0x44)) {
                  puVar6 = (undefined4 *)*puVar6;
                }
                if (puVar6 != (undefined4 *)0x0) {
                  uVar4 = FUN_008917b4(puVar6);
                }
              }
              break;
            }
          }
          local_24[1] = uVar4;
          for (iVar5 = *(int *)(iVar5 + 0x94); uVar12 = local_6c, iVar5 != iVar3;
              iVar5 = *(int *)(iVar5 + 0x50)) {
            pcVar9 = (char *)(iVar5 + 0x14);
            if (0xf < *(uint *)(iVar5 + 0x28)) {
              pcVar9 = *(char **)pcVar9;
            }
            iVar10 = __stricmp(pcVar9,"Y");
            if (iVar10 == 0) {
              if (iVar5 != 0) {
                puVar6 = (undefined4 *)(iVar5 + 0x30);
                if (0xf < *(uint *)(iVar5 + 0x44)) {
                  puVar6 = (undefined4 *)*puVar6;
                }
                if (puVar6 != (undefined4 *)0x0) {
                  uVar12 = FUN_008917b4(puVar6);
                }
              }
              break;
            }
          }
          puVar6 = *(undefined4 **)(iVar2 + 0x70);
          local_24[2] = uVar12;
          if ((local_24 < puVar6) && (puVar14 = (undefined4 *)*puVar7, puVar14 <= local_24)) {
            if (puVar6 == *(undefined4 **)(iVar2 + 0x74)) {
              uVar11 = (int)puVar6 - (int)puVar14 >> 4;
              if (0xffffffe < uVar11) {
LAB_0052582c:
                    /* WARNING: Subroutine does not return */
                FUN_0087db30("vector<T> too long");
              }
              uVar11 = uVar11 + 1;
              uVar13 = (int)*(undefined4 **)(iVar2 + 0x74) - (int)puVar14 >> 4;
              if (uVar13 < uVar11) {
                if (0xfffffff - (uVar13 >> 1) < uVar13) {
                  uVar13 = 0;
                }
                else {
                  uVar13 = uVar13 + (uVar13 >> 1);
                }
                if (uVar13 < uVar11) {
                  uVar13 = uVar11;
                }
                FUN_00531860(uVar13);
              }
            }
            puVar6 = *(undefined4 **)(iVar2 + 0x70);
            puVar14 = (undefined4 *)(((int)local_24 - (int)puVar14 & 0xfffffff0U) + *puVar7);
            if (puVar6 != (undefined4 *)0x0) {
              *puVar6 = *puVar14;
              puVar6[1] = puVar14[1];
              puVar6[2] = puVar14[2];
              uVar4 = puVar14[3];
LAB_005257d2:
              puVar6[3] = uVar4;
            }
          }
          else {
            if (puVar6 == *(undefined4 **)(iVar2 + 0x74)) {
              uVar11 = (int)((int)puVar6 - *puVar7) >> 4;
              if (0xffffffe < uVar11) goto LAB_0052582c;
              uVar11 = uVar11 + 1;
              uVar13 = (int)((int)*(undefined4 **)(iVar2 + 0x74) - *puVar7) >> 4;
              if (uVar13 < uVar11) {
                if (0xfffffff - (uVar13 >> 1) < uVar13) {
                  uVar13 = 0;
                }
                else {
                  uVar13 = uVar13 + (uVar13 >> 1);
                }
                if (uVar13 < uVar11) {
                  uVar13 = uVar11;
                }
                FUN_00531860(uVar13);
              }
            }
            puVar6 = *(undefined4 **)(iVar2 + 0x70);
            if (puVar6 != (undefined4 *)0x0) {
              *puVar6 = local_24[0];
              puVar6[1] = uVar4;
              puVar6[2] = uVar12;
              uVar4 = local_24[3];
              goto LAB_005257d2;
            }
          }
          *(int *)(iVar2 + 0x70) = *(int *)(iVar2 + 0x70) + 0x10;
          iVar5 = FUN_0072e3c0();
        } while (iVar5 != 0);
      }
    }
    iVar2 = FUN_0072e3c0();
    pvVar1 = ExceptionList;
    ExceptionList = local_10;
  } while( true );
}

