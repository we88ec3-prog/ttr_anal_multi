
/* WARNING: Type propagation algorithm not settling */

void FUN_007ade80(int param_1,int param_2)

{
  uint *puVar1;
  char cVar2;
  char cVar3;
  int *piVar4;
  float *pfVar5;
  long lVar6;
  char *_Str1;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 **ppuVar11;
  char *in_ECX;
  char *******_Str2;
  char *in_EDX;
  undefined1 uVar12;
  ushort uVar13;
  char *pcVar14;
  uint uVar15;
  uint *puVar16;
  float10 fVar17;
  undefined1 auStack_364 [4];
  undefined4 uStack_360;
  int local_32c;
  int local_328;
  int local_324;
  int local_320;
  int local_31c;
  int local_318;
  undefined4 *local_314;
  int local_310;
  undefined4 *local_30c;
  uint local_308;
  int local_304;
  uint *local_300;
  undefined4 *local_2fc;
  undefined4 local_2f8;
  undefined4 local_2f4;
  undefined1 local_230;
  uint local_22c;
  undefined4 local_21c;
  uint local_218;
  ushort local_210;
  undefined1 local_20c;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined1 local_1f0;
  undefined1 local_1ef;
  undefined4 *local_1ec;
  char local_1e8;
  undefined1 local_1e7;
  undefined4 local_1e4;
  undefined1 local_1e0;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined1 local_1c4;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1a8;
  undefined1 local_1a4;
  undefined4 local_194;
  undefined4 local_190;
  undefined1 local_188;
  undefined4 local_178;
  undefined4 local_174;
  long local_16c;
  int local_168;
  undefined4 local_164;
  undefined4 local_160;
  uint local_158;
  undefined4 local_148;
  uint local_144;
  char *******local_13c [2];
  long local_134;
  float local_130;
  float local_12c;
  float local_128;
  undefined4 *local_124;
  char local_120 [264];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092272d;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_310 = param_1;
  local_308 = 0;
  local_8 = 0;
  local_144 = 0xf;
  local_148 = 0;
  local_158 = local_158 & 0xffffff00;
  do {
    cVar3 = *in_ECX;
    in_ECX = in_ECX + 1;
  } while (cVar3 != '\0');
  FUN_00402a70();
  local_8._0_1_ = 1;
  do {
    cVar3 = *in_EDX;
    in_EDX = in_EDX + 1;
  } while (cVar3 != '\0');
  FUN_00401fc0();
  local_2f8 = 0;
  local_2f4 = 0;
  FUN_0071bc20();
  local_230 = 0;
  local_218 = 0xf;
  local_21c = 0;
  local_22c = local_22c & 0xffffff00;
  local_8 = CONCAT31(local_8._1_3_,2);
  piVar4 = (int *)FUN_00714770();
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0x38))();
    (**(code **)(*piVar4 + 0x2c))();
    cVar3 = FUN_00499340();
    (**(code **)(*piVar4 + 4))();
    if (cVar3 != '\0') {
      local_2fc = (undefined4 *)local_2f8;
      pfVar5 = (float *)FUN_0071ba40();
      local_2fc = (undefined4 *)*pfVar5;
      FUN_00719da0();
      if (local_300 != (uint *)0x0) {
LAB_007ae09b:
        local_1ec = (undefined4 *)0x0;
        local_210 = 0;
        local_1f8 = 0xf;
        local_1fc = 0;
        local_20c = 0;
        local_1ef = 0;
        local_1e7 = 0;
        local_1e4 = 0;
        local_1cc = 0xf;
        local_1d0 = 0;
        local_1e0 = 0;
        local_1b0 = 0xf;
        local_1b4 = 0;
        local_1c4 = 0;
        local_1a8 = 0;
        local_190 = 0xf;
        local_194 = 0;
        local_1a4 = 0;
        local_174 = 0xf;
        local_178 = 0;
        local_188 = 0;
        local_16c = 0;
        local_168 = 0;
        local_164 = 0;
        local_160 = 0;
        local_8 = CONCAT31(local_8._1_3_,3);
        uVar13 = 0;
        FUN_0071baa0();
        if (local_328 != 0) {
          if (*(char **)(local_328 + 8) == (char *)0x0) {
            uVar13 = 0;
          }
          else {
            uStack_360 = 0x7ae173;
            lVar6 = _strtol(*(char **)(local_328 + 8),(char **)0x0,10);
            uVar13 = (ushort)lVar6;
          }
        }
        local_210 = uVar13;
        FUN_00719f10();
        local_8._0_1_ = 4;
        FUN_00402bb0();
        local_8 = CONCAT31(local_8._1_3_,3);
        if (0xf < (uint)local_128) {
          FUN_0089120c();
        }
        FUN_00719da0();
        if (local_304 != 0) {
          lVar6 = 0;
          FUN_0071baa0();
          if (local_32c != 0) {
            if (*(char **)(local_32c + 8) == (char *)0x0) {
              lVar6 = 0;
            }
            else {
              uStack_360 = 0x7ae220;
              lVar6 = _strtol(*(char **)(local_32c + 8),(char **)0x0,10);
            }
          }
          uVar12 = 0;
          local_16c = lVar6;
          FUN_0071baa0();
          if (local_324 != 0) {
            if ((*(char **)(local_324 + 8) == (char *)0x0) ||
               ((((cVar3 = **(char **)(local_324 + 8), cVar3 != '1' && (cVar3 != 't')) &&
                 (cVar3 != 'T')) && ((cVar3 != 'y' && (cVar3 != 'Y')))))) {
              uVar12 = 0;
            }
            else {
              uVar12 = 1;
            }
          }
          local_1f0 = uVar12;
          FUN_0071baa0();
          local_1ef = 0;
          if (local_31c != 0) {
            if ((*(char **)(local_31c + 8) == (char *)0x0) ||
               (((cVar3 = **(char **)(local_31c + 8), cVar3 != '1' && (cVar3 != 't')) &&
                ((cVar3 != 'T' && ((cVar3 != 'y' && (cVar3 != 'Y')))))))) {
              local_1ef = 0;
            }
            else {
              local_1ef = 1;
            }
          }
          local_2fc = (undefined4 *)0x0;
          FUN_0071baa0();
          if (local_320 != 0) {
            if (*(int *)(local_320 + 8) == 0) {
              local_2fc = (undefined4 *)0x0;
            }
            else {
              fVar17 = (float10)FUN_00898a3f();
              local_2fc = (undefined4 *)(float)fVar17;
            }
          }
          local_1ec = local_2fc;
          local_1e8 = '\0';
          FUN_0071baa0();
          uVar12 = 0;
          if (local_318 != 0) {
            if (*(char **)(local_318 + 8) == (char *)0x0) {
              uVar12 = 0;
            }
            else {
              uStack_360 = 0x7ae360;
              lVar6 = _strtol(*(char **)(local_318 + 8),(char **)0x0,10);
              uVar12 = (char)lVar6;
            }
          }
          local_1e7 = uVar12;
          FUN_00719f10();
          cVar3 = '\0';
          pcVar14 = (char *)&DAT_00fbabf8;
          do {
            _Str2 = local_13c[0];
            if ((uint)local_128 < 0x10) {
              _Str2 = (char *******)local_13c;
            }
            _Str1 = pcVar14;
            if (0xf < *(uint *)(pcVar14 + 0x14)) {
              _Str1 = *(char **)pcVar14;
            }
            iVar7 = __stricmp(_Str1,(char *)_Str2);
            cVar2 = cVar3;
            if (iVar7 == 0) break;
            pcVar14 = pcVar14 + 0x1c;
            cVar3 = cVar3 + '\x01';
            cVar2 = local_1e8;
          } while ((int)pcVar14 < 0xfbac84);
          local_1e8 = cVar2;
          if (0xf < (uint)local_128) {
            FUN_0089120c();
          }
        }
        if (local_300 != (uint *)0x0) {
          for (puVar16 = (uint *)local_300[4]; puVar16 != (uint *)0x0; puVar16 = (uint *)puVar16[6])
          {
            if (((char *)puVar16[2] != (char *)0x0) &&
               (iVar7 = __stricmp("ReferIndex",(char *)puVar16[2]), iVar7 == 0)) {
              if (puVar16 == (uint *)0x0) goto LAB_007ae473;
              goto LAB_007ae441;
            }
          }
          goto LAB_007ae7a2;
        }
        goto LAB_007aeaf6;
      }
LAB_007aed16:
      local_8 = CONCAT31(local_8._1_3_,1);
      if (0xf < local_218) {
        FUN_0089120c();
      }
      local_218 = 0xf;
      local_21c = 0;
      local_22c = local_22c & 0xffffff00;
      FUN_0071bc90();
      if (0xf < local_144) {
        FUN_0089120c();
      }
      local_144 = 0xf;
      local_148 = 0;
      local_158 = local_158 & 0xffffff00;
      if (param_2 != 0) {
        FUN_007b2b40();
        FUN_0089120c();
      }
      goto LAB_007aedb0;
    }
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (0xf < local_218) {
    FUN_0089120c();
  }
  local_218 = 0xf;
  local_21c = 0;
  local_22c = local_22c & 0xffffff00;
  FUN_0071bc90();
  if (0xf < local_144) {
    FUN_0089120c();
  }
  local_144 = 0xf;
  local_148 = 0;
  local_158 = local_158 & 0xffffff00;
  if (param_2 != 0) {
    FUN_007b2b40();
    FUN_0089120c();
  }
LAB_007aedb0:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
LAB_007ae441:
  do {
    if ((*puVar16 & 7) == 1) {
      puVar16 = (uint *)puVar16[4];
      goto joined_r0x007ae487;
    }
    for (puVar16 = (uint *)puVar16[6]; puVar16 != (uint *)0x0; puVar16 = (uint *)puVar16[6]) {
      if (((char *)puVar16[2] != (char *)0x0) &&
         (iVar7 = __stricmp("ReferIndex",(char *)puVar16[2]), iVar7 == 0)) goto LAB_007ae475;
    }
LAB_007ae473:
    puVar16 = (uint *)0x0;
LAB_007ae475:
  } while (puVar16 != (uint *)0x0);
  goto LAB_007ae7a2;
joined_r0x007ae487:
  if (puVar16 == (uint *)0x0) goto LAB_007ae7a2;
  if (((char *)puVar16[2] != (char *)0x0) &&
     (iVar7 = __stricmp("SpliteData",(char *)puVar16[2]), iVar7 == 0)) {
    if (puVar16 == (uint *)0x0) goto LAB_007ae4f0;
    goto LAB_007ae4bb;
  }
  puVar16 = (uint *)puVar16[6];
  goto joined_r0x007ae487;
LAB_007ae4bb:
  do {
    if ((*puVar16 & 7) == 1) goto LAB_007ae501;
    for (puVar16 = (uint *)puVar16[6]; puVar16 != (uint *)0x0; puVar16 = (uint *)puVar16[6]) {
      if (((char *)puVar16[2] != (char *)0x0) &&
         (iVar7 = __stricmp("SpliteData",(char *)puVar16[2]), iVar7 == 0)) goto LAB_007ae4f2;
    }
LAB_007ae4f0:
    puVar16 = (uint *)0x0;
LAB_007ae4f2:
  } while (puVar16 != (uint *)0x0);
LAB_007ae7a2:
  puVar1 = local_300;
  for (puVar16 = (uint *)local_300[4]; puVar16 != (uint *)0x0; puVar16 = (uint *)puVar16[6]) {
    if (((char *)puVar16[2] != (char *)0x0) &&
       (iVar7 = __stricmp("Effect",(char *)puVar16[2]), iVar7 == 0)) goto LAB_007ae7e0;
  }
  goto LAB_007ae96d;
LAB_007ae501:
  lVar6 = 0;
  if ((puVar16 != (uint *)0x0) && (uVar15 = puVar16[7], uVar15 != 0)) {
    lVar6 = 0;
    do {
      if ((*(char **)(uVar15 + 4) != (char *)0x0) &&
         (iVar7 = __stricmp("FileID",*(char **)(uVar15 + 4)), iVar7 == 0)) {
        if (*(char **)(uVar15 + 8) == (char *)0x0) {
          lVar6 = 0;
        }
        else {
          uStack_360 = 0x7ae543;
          lVar6 = _strtol(*(char **)(uVar15 + 8),(char **)0x0,10);
        }
        break;
      }
      uVar15 = *(uint *)(uVar15 + 0x10);
    } while (uVar15 != 0);
  }
  local_2fc = (undefined4 *)0x0;
  local_134 = lVar6;
  if (puVar16 != (uint *)0x0) {
    for (uVar15 = puVar16[7]; uVar15 != 0; uVar15 = *(uint *)(uVar15 + 0x10)) {
      if ((*(char **)(uVar15 + 4) != (char *)0x0) &&
         (iVar7 = __stricmp("FPS",*(char **)(uVar15 + 4)), iVar7 == 0)) {
        if (*(int *)(uVar15 + 8) == 0) {
          local_2fc = (undefined4 *)0x0;
        }
        else {
          fVar17 = (float10)FUN_00898a3f();
          local_2fc = (undefined4 *)(float)fVar17;
        }
        break;
      }
    }
  }
  local_130 = (float)local_2fc;
  local_2fc = (undefined4 *)0x0;
  if (puVar16 != (uint *)0x0) {
    for (uVar15 = puVar16[7]; uVar15 != 0; uVar15 = *(uint *)(uVar15 + 0x10)) {
      if ((*(char **)(uVar15 + 4) != (char *)0x0) &&
         (iVar7 = __stricmp("StartFrame",*(char **)(uVar15 + 4)), iVar7 == 0)) {
        if (*(int *)(uVar15 + 8) == 0) {
          local_2fc = (undefined4 *)0x0;
        }
        else {
          fVar17 = (float10)FUN_00898a3f();
          local_2fc = (undefined4 *)(float)fVar17;
        }
        break;
      }
    }
  }
  local_12c = (float)local_2fc;
  local_2fc = (undefined4 *)0x0;
  if (puVar16 != (uint *)0x0) {
    for (uVar15 = puVar16[7]; uVar15 != 0; uVar15 = *(uint *)(uVar15 + 0x10)) {
      if ((*(char **)(uVar15 + 4) != (char *)0x0) &&
         (iVar7 = __stricmp("EndFrame",*(char **)(uVar15 + 4)), iVar7 == 0)) {
        if (*(int *)(uVar15 + 8) == 0) {
          local_2fc = (undefined4 *)0x0;
        }
        else {
          fVar17 = (float10)FUN_00898a3f();
          local_2fc = (undefined4 *)(float)fVar17;
        }
        break;
      }
    }
  }
  local_128 = (float)local_2fc;
  local_2fc = (undefined4 *)0x0;
  if (puVar16 != (uint *)0x0) {
    for (uVar15 = puVar16[7]; uVar15 != 0; uVar15 = *(uint *)(uVar15 + 0x10)) {
      if ((*(char **)(uVar15 + 4) != (char *)0x0) &&
         (iVar7 = __stricmp("Delay",*(char **)(uVar15 + 4)), iVar7 == 0)) {
        if (*(int *)(uVar15 + 8) == 0) {
          local_2fc = (undefined4 *)0x0;
        }
        else {
          fVar17 = (float10)FUN_00898a3f();
          local_2fc = (undefined4 *)(float)fVar17;
        }
        break;
      }
    }
  }
  local_124 = local_2fc;
  FUN_007b1810();
  if (puVar16 != (uint *)0x0) {
    for (puVar16 = (uint *)puVar16[6]; puVar16 != (uint *)0x0; puVar16 = (uint *)puVar16[6]) {
      if (((char *)puVar16[2] != (char *)0x0) &&
         (iVar7 = __stricmp("SpliteData",(char *)puVar16[2]), iVar7 == 0)) {
        if (puVar16 == (uint *)0x0) goto LAB_007ae790;
        goto LAB_007ae758;
      }
    }
  }
  goto LAB_007ae796;
LAB_007ae758:
  do {
    if ((*puVar16 & 7) == 1) goto LAB_007ae798;
    for (puVar16 = (uint *)puVar16[6]; puVar16 != (uint *)0x0; puVar16 = (uint *)puVar16[6]) {
      if (((char *)puVar16[2] != (char *)0x0) &&
         (iVar7 = __stricmp("SpliteData",(char *)puVar16[2]), iVar7 == 0)) goto LAB_007ae792;
    }
LAB_007ae790:
    puVar16 = (uint *)0x0;
LAB_007ae792:
  } while (puVar16 != (uint *)0x0);
LAB_007ae796:
  puVar16 = (uint *)0x0;
LAB_007ae798:
  if (puVar16 == (uint *)0x0) goto LAB_007ae7a2;
  goto LAB_007ae501;
LAB_007ae7e0:
  do {
    if (puVar16 != (uint *)0x0) {
      if ((*puVar16 & 7) == 1) {
        uVar15 = puVar16[7];
        goto joined_r0x007ae828;
      }
      for (puVar16 = (uint *)puVar16[6]; puVar16 != (uint *)0x0; puVar16 = (uint *)puVar16[6]) {
        if (((char *)puVar16[2] != (char *)0x0) &&
           (iVar7 = __stricmp("Effect",(char *)puVar16[2]), iVar7 == 0)) goto LAB_007ae818;
      }
    }
    puVar16 = (uint *)0x0;
LAB_007ae818:
  } while (puVar16 != (uint *)0x0);
  goto LAB_007ae96d;
joined_r0x007ae828:
  if (uVar15 == 0) goto LAB_007ae854;
  if ((*(char **)(uVar15 + 4) != (char *)0x0) &&
     (iVar7 = __stricmp("File",*(char **)(uVar15 + 4)), iVar7 == 0)) {
    pcVar14 = *(char **)(uVar15 + 8);
    if (pcVar14 == (char *)0x0) {
      pcVar14 = "";
    }
    goto LAB_007ae856;
  }
  uVar15 = *(uint *)(uVar15 + 0x10);
  goto joined_r0x007ae828;
LAB_007ae854:
  pcVar14 = (char *)0x0;
LAB_007ae856:
  uStack_360 = 0x7ae868;
  _strncpy(local_120,pcVar14,0x104);
  pcVar14 = local_120;
  do {
    cVar3 = *pcVar14;
    pcVar14 = pcVar14 + 1;
  } while (cVar3 != '\0');
  FUN_00402a70();
  for (uVar15 = puVar16[7]; uVar15 != 0; uVar15 = *(uint *)(uVar15 + 0x10)) {
    if ((*(char **)(uVar15 + 4) != (char *)0x0) &&
       (iVar7 = __stricmp("Folder",*(char **)(uVar15 + 4)), iVar7 == 0)) {
      pcVar14 = *(char **)(uVar15 + 8);
      if (pcVar14 == (char *)0x0) {
        pcVar14 = "";
      }
      goto LAB_007ae8bd;
    }
  }
  pcVar14 = (char *)0x0;
LAB_007ae8bd:
  uStack_360 = 0x7ae8cf;
  _strncpy(local_120,pcVar14,0x104);
  pcVar14 = local_120;
  do {
    cVar3 = *pcVar14;
    pcVar14 = pcVar14 + 1;
  } while (cVar3 != '\0');
  FUN_00402a70();
  local_1e4 = 1;
  if ((DAT_00fe1770 & 1) == 0) {
    DAT_00fe1770 = DAT_00fe1770 | 1;
    local_8._0_1_ = 5;
    FUN_007b7da0();
    _atexit((_func_4879 *)&LAB_00bce790);
    local_8 = CONCAT31(local_8._1_3_,3);
  }
  FUN_007b8480();
LAB_007ae96d:
  for (puVar16 = (uint *)puVar1[4]; puVar16 != (uint *)0x0; puVar16 = (uint *)puVar16[6]) {
    if (((char *)puVar16[2] != (char *)0x0) &&
       (iVar7 = __stricmp("Sound",(char *)puVar16[2]), iVar7 == 0)) goto LAB_007ae9d0;
  }
LAB_007aeaf6:
  puVar8 = (undefined4 *)FUN_00891268();
  local_8._0_1_ = 6;
  local_314 = puVar8;
  if (puVar8 == (undefined4 *)0x0) {
    local_2fc = (undefined4 *)0x0;
    iVar7 = local_310;
  }
  else {
    local_2fc = (undefined4 *)auStack_364;
    FUN_007b18b0(auStack_364,&param_2);
    iVar7 = local_310;
    local_8 = CONCAT31(local_8._1_3_,7);
    puVar9 = (undefined4 *)FUN_007c5710(local_13c);
    local_308 = local_308 | 1;
    if (0xf < (uint)puVar9[5]) {
      puVar9 = (undefined4 *)*puVar9;
    }
    local_8 = 9;
    local_2fc = (undefined4 *)FUN_007d8d50(puVar8,puVar9);
  }
  local_8 = 3;
  if ((local_308 & 1) != 0) {
    local_308 = local_308 & 0xfffffffe;
    if (0xf < (uint)local_128) {
      FUN_0089120c();
    }
    local_128 = 2.10195e-44;
    local_12c = 0.0;
    local_13c[0] = (char *******)((uint)local_13c[0] & 0xffffff00);
  }
  puVar8 = *(undefined4 **)(iVar7 + 0xd8);
  cVar3 = *(char *)((int)puVar8[1] + 0x15);
  local_314 = puVar8;
  puVar9 = (undefined4 *)puVar8[1];
  while (cVar3 == '\0') {
    if ((uint)puVar9[3] < (uint)local_210) {
      puVar10 = (undefined4 *)puVar9[2];
      puVar9 = local_314;
    }
    else {
      puVar10 = (undefined4 *)*puVar9;
    }
    local_314 = puVar9;
    puVar9 = puVar10;
    cVar3 = *(char *)((int)puVar10 + 0x15);
  }
  if ((local_314 == puVar8) || ((uint)local_210 < (uint)local_314[3])) {
    local_30c = puVar8;
    ppuVar11 = &local_30c;
  }
  else {
    ppuVar11 = &local_314;
  }
  if (*ppuVar11 == puVar8) {
    FUN_0057ef20();
    FUN_0082f200();
  }
  else if (local_2fc != (undefined4 *)0x0) {
    (**(code **)*local_2fc)();
  }
  if (local_300 != (uint *)0x0) {
    for (puVar16 = (uint *)local_300[6]; puVar16 != (uint *)0x0; puVar16 = (uint *)puVar16[6]) {
      if (((char *)puVar16[2] != (char *)0x0) &&
         (iVar7 = __stricmp("AnimationHeader",(char *)puVar16[2]), iVar7 == 0)) {
        if (puVar16 == (uint *)0x0) goto LAB_007aee06;
        goto LAB_007aedd4;
      }
    }
  }
LAB_007aecd4:
  puVar16 = (uint *)0x0;
LAB_007aecd6:
  local_300 = puVar16;
  if (local_168 != 0) {
    FUN_0089120c();
  }
  local_168 = 0;
  local_164 = 0;
  local_160 = 0;
  FUN_007ac410();
  if (puVar16 == (uint *)0x0) goto LAB_007aed16;
  goto LAB_007ae09b;
LAB_007ae9d0:
  do {
    if (puVar16 != (uint *)0x0) {
      if ((*puVar16 & 7) == 1) {
        uVar15 = puVar16[7];
        goto joined_r0x007aea18;
      }
      for (puVar16 = (uint *)puVar16[6]; puVar16 != (uint *)0x0; puVar16 = (uint *)puVar16[6]) {
        if (((char *)puVar16[2] != (char *)0x0) &&
           (iVar7 = __stricmp("Sound",(char *)puVar16[2]), iVar7 == 0)) goto LAB_007aea08;
      }
    }
    puVar16 = (uint *)0x0;
LAB_007aea08:
  } while (puVar16 != (uint *)0x0);
  goto LAB_007aeaf6;
joined_r0x007aea18:
  if (uVar15 == 0) goto LAB_007aea44;
  if ((*(char **)(uVar15 + 4) != (char *)0x0) &&
     (iVar7 = __stricmp("File",*(char **)(uVar15 + 4)), iVar7 == 0)) {
    pcVar14 = *(char **)(uVar15 + 8);
    if (pcVar14 == (char *)0x0) {
      pcVar14 = "";
    }
    goto LAB_007aea46;
  }
  uVar15 = *(uint *)(uVar15 + 0x10);
  goto joined_r0x007aea18;
LAB_007aea44:
  pcVar14 = (char *)0x0;
LAB_007aea46:
  uStack_360 = 0x7aea58;
  _strncpy(local_120,pcVar14,0x104);
  pcVar14 = local_120;
  do {
    cVar3 = *pcVar14;
    pcVar14 = pcVar14 + 1;
  } while (cVar3 != '\0');
  FUN_00402a70();
  for (uVar15 = puVar16[7]; uVar15 != 0; uVar15 = *(uint *)(uVar15 + 0x10)) {
    if ((*(char **)(uVar15 + 4) != (char *)0x0) &&
       (iVar7 = __stricmp("Folder",*(char **)(uVar15 + 4)), iVar7 == 0)) {
      pcVar14 = *(char **)(uVar15 + 8);
      if (pcVar14 == (char *)0x0) {
        pcVar14 = "";
      }
      goto LAB_007aeaad;
    }
  }
  pcVar14 = (char *)0x0;
LAB_007aeaad:
  uStack_360 = 0x7aeabf;
  _strncpy(local_120,pcVar14,0x104);
  pcVar14 = local_120;
  do {
    cVar3 = *pcVar14;
    pcVar14 = pcVar14 + 1;
  } while (cVar3 != '\0');
  FUN_00402a70();
  local_1a8 = 1;
  goto LAB_007aeaf6;
LAB_007aedd4:
  do {
    if ((*puVar16 & 7) == 1) goto LAB_007aecd6;
    for (puVar16 = (uint *)puVar16[6]; puVar16 != (uint *)0x0; puVar16 = (uint *)puVar16[6]) {
      if (((char *)puVar16[2] != (char *)0x0) &&
         (iVar7 = __stricmp("AnimationHeader",(char *)puVar16[2]), iVar7 == 0)) goto LAB_007aee08;
    }
LAB_007aee06:
    puVar16 = (uint *)0x0;
LAB_007aee08:
  } while (puVar16 != (uint *)0x0);
  goto LAB_007aecd4;
}

