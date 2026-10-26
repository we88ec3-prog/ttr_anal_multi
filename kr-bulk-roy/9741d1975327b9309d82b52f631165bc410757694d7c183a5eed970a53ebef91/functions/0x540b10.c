
void FUN_00540b10(void)

{
  char cVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  char *******pppppppcVar8;
  char *pcVar9;
  char **ppcVar10;
  char *******pppppppcVar11;
  undefined1 local_1f0 [12];
  undefined4 uStack_1e4;
  int local_1e0;
  undefined4 local_1dc;
  undefined4 uStack_1d8;
  undefined1 local_1d4 [12];
  undefined4 uStack_1c8;
  char ******local_1c4;
  undefined4 local_1c0;
  undefined1 local_1b8 [12];
  undefined4 uStack_1ac;
  undefined **local_18c [3];
  undefined **local_180 [4];
  int local_170;
  undefined4 local_16c;
  uint *local_160;
  undefined4 local_15c;
  undefined1 *local_154;
  char *local_150;
  undefined1 *local_14c;
  char *local_148;
  char *local_144;
  uint *local_140;
  uint *local_13c;
  char local_135;
  uint *local_134;
  int local_130;
  undefined1 local_6c;
  uint local_68;
  undefined4 local_58;
  uint local_54;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  char ******local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8._0_1_ = 0xff;
  local_8._1_3_ = 0xffffff;
  puStack_c = &LAB_00939511;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_15c = 0;
  puVar4 = (uint *)FUN_00891268();
  if (puVar4 == (uint *)0x0) {
    local_150 = (char *)0x0;
    ppcVar10 = &local_150;
LAB_00541385:
    std::exception::exception((exception *)local_180,ppcVar10);
    local_180[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8();
  }
  *puVar4 = (uint)puVar4;
  puVar4[1] = (uint)puVar4;
  puVar4[2] = (uint)puVar4;
  *(undefined1 *)(puVar4 + 0xb) = 1;
  *(undefined1 *)((int)puVar4 + 0x2d) = 1;
  local_8 = 0;
  local_16c = 0;
  local_160 = puVar4;
  local_170 = FUN_00891268();
  if (local_170 == 0) {
    local_148 = (char *)0x0;
    std::exception::exception((exception *)local_18c,&local_148);
    local_18c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8();
  }
  *(int *)local_170 = local_170;
  *(int *)(local_170 + 4) = local_170;
  *(int *)(local_170 + 8) = local_170;
  *(undefined1 *)(local_170 + 0x10) = 1;
  *(undefined1 *)(local_170 + 0x11) = 1;
  local_150 = (char *)timeGetTime();
  local_134 = (uint *)0x0;
  local_130 = 0;
  FUN_0071bc20();
  local_6c = 0;
  local_54 = 0xf;
  local_58 = 0;
  local_68 = local_68 & 0xffffff00;
  local_8._0_1_ = 2;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (char ******)((uint)local_30[0] & 0xffffff00);
  FUN_00402a70();
  local_8 = CONCAT31(local_8._1_3_,3);
  piVar5 = (int *)FUN_00714770();
  if (piVar5 == (int *)0x0) {
    local_135 = '\0';
  }
  else {
    (**(code **)(*piVar5 + 0x38))();
    (**(code **)(*piVar5 + 0x2c))();
    local_135 = FUN_00499340();
    (**(code **)(*piVar5 + 4))();
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  if (0xf < local_1c) {
    FUN_0089120c();
  }
  if (local_135 != '\0') {
    local_140 = local_134;
    puVar6 = (undefined4 *)FUN_0071ba40();
    local_140 = (uint *)*puVar6;
    FUN_00719da0();
    if (local_13c != (uint *)0x0) {
LAB_00540d00:
      FUN_0071baa0();
      if (local_14c != (undefined1 *)0x0) {
        if (*(char **)(local_14c + 8) == (char *)0x0) {
          local_144 = (char *)0x0;
        }
        else {
          uStack_1ac = 0x540d30;
          local_144 = (char *)_strtol(*(char **)(local_14c + 8),(char **)0x0,10);
        }
      }
      if (local_144 != (char *)0x3) {
        FUN_00719da0();
        puVar4 = local_140;
joined_r0x00540d69:
        local_140 = puVar4;
        if (puVar4 != (uint *)0x0) {
          if (puVar4 != (uint *)0x0) {
            for (uVar2 = puVar4[7]; uVar2 != 0; uVar2 = *(uint *)(uVar2 + 0x10)) {
              if ((*(char **)(uVar2 + 4) != (char *)0x0) &&
                 (iVar7 = __stricmp("ID",*(char **)(uVar2 + 4)), iVar7 == 0)) {
                if (*(char **)(uVar2 + 8) == (char *)0x0) {
                  local_154 = (undefined1 *)0x0;
                }
                else {
                  uStack_1ac = 0x540db2;
                  local_154 = (undefined1 *)_strtol(*(char **)(uVar2 + 8),(char **)0x0,10);
                }
                break;
              }
            }
            for (uVar2 = puVar4[7]; uVar2 != 0; uVar2 = *(uint *)(uVar2 + 0x10)) {
              if ((*(char **)(uVar2 + 4) != (char *)0x0) &&
                 (iVar7 = __stricmp("PRE",*(char **)(uVar2 + 4)), iVar7 == 0)) {
                if (*(char **)(uVar2 + 8) != (char *)0x0) {
                  uStack_1ac = 0x540df8;
                  _strtol(*(char **)(uVar2 + 8),(char **)0x0,10);
                }
                break;
              }
            }
          }
          FUN_006bde40();
          FUN_0044bbd0();
          if (puVar4 != (uint *)0x0) {
            for (uVar2 = puVar4[7]; uVar2 != 0; uVar2 = *(uint *)(uVar2 + 0x10)) {
              if ((*(char **)(uVar2 + 4) != (char *)0x0) &&
                 (iVar7 = __stricmp("FILE",*(char **)(uVar2 + 4)), iVar7 == 0)) {
                pcVar9 = *(char **)(uVar2 + 8);
                if (pcVar9 == (char *)0x0) {
                  pcVar9 = "";
                }
                goto LAB_00540e4d;
              }
            }
          }
          pcVar9 = (char *)0x0;
LAB_00540e4d:
          local_1c = 0xf;
          local_20 = 0;
          local_30[0] = (char ******)((uint)local_30[0] & 0xffffff00);
          do {
            cVar1 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70();
          local_8._0_1_ = 4;
          local_140 = (uint *)local_154;
          FUN_004f7df0();
          uStack_1ac = 0x540ea2;
          FUN_00403040();
          local_8 = CONCAT31(local_8._1_3_,2);
          if (0xf < local_1c) {
            FUN_0089120c();
          }
          if (puVar4 != (uint *)0x0) {
            for (puVar4 = (uint *)puVar4[6]; puVar4 != (uint *)0x0; puVar4 = (uint *)puVar4[6]) {
              if ((*puVar4 & 7) == 1) goto joined_r0x00540d69;
            }
          }
          puVar4 = (uint *)0x0;
          goto joined_r0x00540d69;
        }
      }
      if (local_13c != (uint *)0x0) {
        for (puVar4 = (uint *)local_13c[6]; puVar4 != (uint *)0x0; puVar4 = (uint *)puVar4[6]) {
          if (((char *)puVar4[2] != (char *)0x0) &&
             (iVar7 = __stricmp("OBJCATEGORY",(char *)puVar4[2]), iVar7 == 0)) {
            if (puVar4 == (uint *)0x0) goto LAB_00540f74;
            goto LAB_00540f3d;
          }
        }
      }
      goto LAB_00540f7a;
    }
  }
LAB_00540f8a:
  local_13c = (uint *)*local_160;
  if (local_13c != local_160) {
    do {
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = (char ******)((uint)local_30[0] & 0xffffff00);
      uStack_1ac = 0x540fbd;
      FUN_00403040();
      local_8._0_1_ = 5;
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      uStack_1ac = 0x540fd6;
      FUN_00403040();
      local_8._0_1_ = 6;
      FUN_00401fc0();
      if ((DAT_00fe1df8 & 1) == 0) {
        DAT_00fe1df8 = DAT_00fe1df8 | 1;
        local_8._0_1_ = 7;
        DAT_00fe1e04 = 0;
        iVar7 = FUN_00891268();
        if (iVar7 == 0) {
          local_144 = (char *)0x0;
          ppcVar10 = &local_144;
          goto LAB_00541385;
        }
        DAT_00fe1e00 = iVar7;
        *(int *)iVar7 = iVar7;
        *(int *)(DAT_00fe1e00 + 4) = DAT_00fe1e00;
        *(int *)(DAT_00fe1e00 + 8) = DAT_00fe1e00;
        *(undefined1 *)(DAT_00fe1e00 + 0x2c) = 1;
        *(undefined1 *)(DAT_00fe1e00 + 0x2d) = 1;
        _atexit((_func_4879 *)&LAB_00bcf1a0);
        local_8._0_1_ = 6;
      }
      iVar7 = FUN_00716740();
      if (iVar7 == 0) {
        if (0xf < local_38) {
          FUN_0089120c();
        }
      }
      else {
        local_14c = local_1b8;
        local_1c0 = 0;
        local_1c4 = (char ******)(iVar7 + 0x1c);
        local_1b8[0] = 0;
        uStack_1c8 = 0x5410cd;
        FUN_00403040();
        local_140 = (uint *)local_1d4;
        local_8._0_1_ = 8;
        uStack_1d8 = 0xffffffff;
        local_1dc = 0;
        local_1c0 = 0xf;
        local_1c4 = (char ******)0x0;
        local_1d4[0] = 0;
        uStack_1e4 = 0x5410ed;
        local_1e0 = iVar7;
        FUN_00403040();
        local_8._0_1_ = 9;
        pppppppcVar11 = (char *******)local_30[0];
        if (local_1c < 0x10) {
          pppppppcVar11 = local_30;
        }
        local_154 = local_1f0;
        local_1dc = 0xf;
        local_1e0 = 0;
        local_1f0[0] = 0;
        pppppppcVar8 = pppppppcVar11;
        do {
          cVar1 = *(char *)pppppppcVar8;
          pppppppcVar8 = (char *******)((int)pppppppcVar8 + 1);
        } while (cVar1 != '\0');
        FUN_00402a70(pppppppcVar11,(int)pppppppcVar8 - (int)((int)pppppppcVar11 + 1));
        if ((DAT_00fc0f60 & 1) == 0) {
          DAT_00fc0f60 = DAT_00fc0f60 | 1;
          local_8._0_1_ = 0xb;
          FUN_0079cf40();
          _atexit((_func_4879 *)&LAB_00bcdb80);
        }
        local_8._0_1_ = 6;
        FUN_0079d610(&DAT_00fc0e90);
        local_14c = local_1b8;
        local_1c0 = 0;
        local_1c4 = (char ******)local_30;
        local_1b8[0] = 0;
        uStack_1c8 = 0x541190;
        FUN_00403040();
        if ((DAT_00fc0f60 & 1) == 0) {
          DAT_00fc0f60 = DAT_00fc0f60 | 1;
          local_8._0_1_ = 0xd;
          FUN_0079cf40();
          local_1c0 = 0x5411b7;
          _atexit((_func_4879 *)&LAB_00bcdb80);
        }
        local_8 = CONCAT31(local_8._1_3_,6);
        local_1c0 = 0x5411d6;
        FUN_0079d8e0();
        if (0xf < local_38) {
          FUN_0089120c();
        }
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      local_4c = local_4c & 0xffffff00;
      local_3c = 0;
      local_38 = 0xf;
      if (0xf < local_1c) {
        local_38 = 0xf;
        local_3c = 0;
        FUN_0089120c();
      }
      if (*(char *)((int)local_13c + 0x2d) == '\0') {
        puVar4 = (uint *)local_13c[2];
        if (*(char *)((int)puVar4 + 0x2d) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x2d);
          local_13c = puVar4;
          puVar4 = (uint *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x2d);
            local_13c = puVar4;
            puVar4 = (uint *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)local_13c[1] + 0x2d);
          puVar3 = (uint *)local_13c[1];
          puVar4 = local_13c;
          while ((local_13c = puVar3, cVar1 == '\0' && (puVar4 == (uint *)local_13c[2]))) {
            cVar1 = *(char *)((int)local_13c[1] + 0x2d);
            puVar3 = (uint *)local_13c[1];
            puVar4 = local_13c;
          }
        }
      }
    } while (local_13c != local_160);
  }
  timeGetTime();
  uStack_1ac = 0x541281;
  FUN_00893164();
  local_8 = CONCAT31(local_8._1_3_,1);
  if (0xf < local_54) {
    FUN_0089120c();
  }
  local_54 = 0xf;
  local_58 = 0;
  local_68 = local_68 & 0xffffff00;
  if (local_130 != 0) {
    (*(code *)PTR_FUN_00d63d4c)();
    local_130 = 0;
  }
  if (local_134 != (uint *)0x0) {
    puVar6 = (undefined4 *)(*local_134 & 0xffffffe0);
    iVar7 = puVar6[3];
    while (iVar7 != 0) {
      iVar7 = *(int *)(iVar7 + 0xc);
      (*(code *)PTR_FUN_00d63d4c)();
    }
    *puVar6 = 0;
    puVar6[3] = 0;
    puVar6[5] = 0;
    puVar6[4] = 0;
    local_134 = (uint *)0x0;
  }
  local_8 = CONCAT31(local_8._1_3_,0xe);
  FUN_004ca160();
  FUN_0089120c();
  local_8 = 0xf;
  FUN_004f7fe0();
  FUN_0089120c();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
LAB_00540f3d:
  do {
    if ((*puVar4 & 7) == 1) goto LAB_00540f7c;
    for (puVar4 = (uint *)puVar4[6]; puVar4 != (uint *)0x0; puVar4 = (uint *)puVar4[6]) {
      if (((char *)puVar4[2] != (char *)0x0) &&
         (iVar7 = __stricmp("OBJCATEGORY",(char *)puVar4[2]), iVar7 == 0)) goto LAB_00540f76;
    }
LAB_00540f74:
    puVar4 = (uint *)0x0;
LAB_00540f76:
  } while (puVar4 != (uint *)0x0);
LAB_00540f7a:
  puVar4 = (uint *)0x0;
LAB_00540f7c:
  local_13c = puVar4;
  if (puVar4 == (uint *)0x0) goto LAB_00540f8a;
  goto LAB_00540d00;
}

