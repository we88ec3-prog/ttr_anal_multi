
void FUN_004f49a0(void)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint *puVar5;
  char *pcVar6;
  char ****ppppcVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  char *pcVar12;
  uint uVar13;
  uint *puVar14;
  long lVar15;
  long lVar16;
  int local_19c;
  uint *local_190;
  int local_18c;
  uint *local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined1 local_bc;
  uint local_b8;
  undefined4 local_a8;
  uint local_a4;
  uint local_9c [4];
  undefined4 local_8c;
  uint local_88;
  uint local_80 [4];
  undefined4 local_70;
  uint local_6c;
  uint local_64 [4];
  undefined4 local_54;
  uint local_50;
  uint local_48;
  long local_44;
  float local_40;
  undefined1 local_3c;
  undefined1 local_3b;
  char ***local_30 [4];
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009247d6;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_184 = 0;
  local_180 = 0;
  FUN_0071bc20(local_14);
  local_bc = 0;
  local_a4 = 0xf;
  local_a8 = 0;
  local_b8 = local_b8 & 0xffffff00;
  local_8 = 0;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
  FUN_00402a70("Table/_ActorList.xml",0x14);
  local_8 = CONCAT31(local_8._1_3_,1);
  ppppcVar7 = (char ****)local_30[0];
  if (local_1c < 0x10) {
    ppppcVar7 = local_30;
  }
  piVar2 = (int *)FUN_00714770(ppppcVar7,&DAT_00bed1e0);
  if (piVar2 == (int *)0x0) {
    cVar1 = '\0';
  }
  else {
    (**(code **)(*piVar2 + 0x38))();
    uVar3 = (**(code **)(*piVar2 + 0x2c))();
    cVar1 = FUN_00499340(uVar3);
    (**(code **)(*piVar2 + 4))();
  }
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  if (cVar1 != '\0') {
    local_18c = local_184;
    piVar2 = (int *)FUN_0071ba40("ACTORLIST");
    local_18c = *piVar2;
    FUN_00719da0(&local_190);
    if (local_190 != (uint *)0x0) {
LAB_004f4ade:
      puVar11 = local_190;
      FUN_0071baa0(&DAT_00bfb82c);
      if ((local_19c != 0) && (*(char **)(local_19c + 8) != (char *)0x0)) {
        _strtol(*(char **)(local_19c + 8),(char **)0x0,10);
      }
      if (puVar11 != (uint *)0x0) {
        for (puVar5 = (uint *)puVar11[4]; puVar5 != (uint *)0x0; puVar5 = (uint *)puVar5[6]) {
          if (((char *)puVar5[2] != (char *)0x0) &&
             (iVar4 = __stricmp("ACTOR",(char *)puVar5[2]), iVar4 == 0)) {
            if (puVar5 == (uint *)0x0) goto LAB_004f4b90;
            goto LAB_004f4b5b;
          }
        }
        goto LAB_004f5182;
      }
      goto LAB_004f522a;
    }
  }
LAB_004f523c:
  local_8 = 0xffffffff;
  if (0xf < local_a4) {
    FUN_0089120c(local_b8);
  }
  local_a4 = 0xf;
  local_a8 = 0;
  local_b8 = local_b8 & 0xffffff00;
  FUN_0071bc90(&local_184);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
LAB_004f4b5b:
  do {
    if ((*puVar5 & 7) == 1) goto LAB_004f4bc6;
    for (puVar5 = (uint *)puVar5[6]; puVar5 != (uint *)0x0; puVar5 = (uint *)puVar5[6]) {
      if (((char *)puVar5[2] != (char *)0x0) &&
         (iVar4 = __stricmp("ACTOR",(char *)puVar5[2]), iVar4 == 0)) goto LAB_004f4b92;
    }
LAB_004f4b90:
    puVar5 = (uint *)0x0;
LAB_004f4b92:
  } while (puVar5 != (uint *)0x0);
LAB_004f5182:
  for (puVar11 = (uint *)puVar11[6]; puVar11 != (uint *)0x0; puVar11 = (uint *)puVar11[6]) {
    if (((char *)puVar11[2] != (char *)0x0) &&
       (iVar4 = __stricmp("OBJCATEGORY",(char *)puVar11[2]), iVar4 == 0)) {
      if (puVar11 == (uint *)0x0) goto LAB_004f5224;
      goto LAB_004f51ea;
    }
  }
LAB_004f522a:
  puVar11 = (uint *)0x0;
LAB_004f522c:
  local_190 = puVar11;
  if (puVar11 == (uint *)0x0) goto LAB_004f523c;
  goto LAB_004f4ade;
LAB_004f4bc6:
  local_188 = puVar5;
  local_88 = 0xf;
  local_8c = 0;
  local_9c[0] = local_9c[0] & 0xffffff00;
  local_6c = 7;
  local_70 = 0;
  local_80[0] = local_80[0] & 0xffff0000;
  local_50 = 0xf;
  local_54 = 0;
  local_64[0] = local_64[0] & 0xffffff00;
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_188 != (uint *)0x0) {
    for (uVar13 = local_188[7]; uVar13 != 0; uVar13 = *(uint *)(uVar13 + 0x10)) {
      if ((*(char **)(uVar13 + 4) != (char *)0x0) &&
         (iVar4 = __stricmp("ID",*(char **)(uVar13 + 4)), iVar4 == 0)) {
        if (*(char **)(uVar13 + 8) != (char *)0x0) {
          _strtol(*(char **)(uVar13 + 8),(char **)0x0,10);
        }
        break;
      }
    }
    for (uVar13 = local_188[7]; uVar13 != 0; uVar13 = *(uint *)(uVar13 + 0x10)) {
      if ((*(char **)(uVar13 + 4) != (char *)0x0) &&
         (iVar4 = __stricmp("PRE",*(char **)(uVar13 + 4)), iVar4 == 0)) {
        if (*(char **)(uVar13 + 8) != (char *)0x0) {
          _strtol(*(char **)(uVar13 + 8),(char **)0x0,10);
        }
        break;
      }
    }
    for (uVar13 = local_188[7]; uVar13 != 0; uVar13 = *(uint *)(uVar13 + 0x10)) {
      if ((*(char **)(uVar13 + 4) != (char *)0x0) &&
         (iVar4 = __stricmp("FILE",*(char **)(uVar13 + 4)), iVar4 == 0)) {
        pcVar12 = *(char **)(uVar13 + 8);
        if (pcVar12 == (char *)0x0) {
          pcVar12 = "";
        }
        goto LAB_004f4cd6;
      }
    }
  }
  pcVar12 = (char *)0x0;
LAB_004f4cd6:
  pcVar6 = pcVar12;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(pcVar12,(int)pcVar6 - (int)(pcVar12 + 1));
  puVar11 = local_188;
  if (local_188 != (uint *)0x0) {
    for (uVar13 = local_188[7]; uVar13 != 0; uVar13 = *(uint *)(uVar13 + 0x10)) {
      if ((*(char **)(uVar13 + 4) != (char *)0x0) &&
         (iVar4 = __stricmp("NAME",*(char **)(uVar13 + 4)), iVar4 == 0)) {
        pcVar12 = *(char **)(uVar13 + 8);
        if (pcVar12 == (char *)0x0) {
          pcVar12 = "";
        }
        goto LAB_004f4d46;
      }
    }
  }
  pcVar12 = (char *)0x0;
LAB_004f4d46:
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
  pcVar6 = pcVar12;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(pcVar12,(int)pcVar6 - (int)(pcVar12 + 1));
  local_8._0_1_ = 3;
  FUN_00440130(local_30);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  FUN_004f9cd0(local_80);
  local_18c = 0;
  if (puVar11 != (uint *)0x0) {
    for (uVar13 = puVar11[7]; uVar13 != 0; uVar13 = *(uint *)(uVar13 + 0x10)) {
      if ((*(char **)(uVar13 + 4) != (char *)0x0) &&
         (iVar4 = __stricmp("SCALE",*(char **)(uVar13 + 4)), iVar4 == 0)) {
        if (*(char **)(uVar13 + 8) == (char *)0x0) {
          local_18c = 0;
        }
        else {
          local_18c = _strtol(*(char **)(uVar13 + 8),(char **)0x0,10);
        }
        break;
      }
    }
  }
  lVar15 = 0;
  local_40 = (float)local_18c / 100.0;
  if (local_188 != (uint *)0x0) {
    for (uVar13 = local_188[7]; uVar13 != 0; uVar13 = *(uint *)(uVar13 + 0x10)) {
      if ((*(char **)(uVar13 + 4) != (char *)0x0) &&
         (iVar4 = __stricmp("SPECIES",*(char **)(uVar13 + 4)), iVar4 == 0)) {
        if (*(char **)(uVar13 + 8) == (char *)0x0) {
          lVar15 = 0;
        }
        else {
          lVar15 = _strtol(*(char **)(uVar13 + 8),(char **)0x0,10);
        }
        break;
      }
    }
  }
  lVar16 = 1;
  local_44 = lVar15;
  if (local_188 != (uint *)0x0) {
    for (uVar13 = local_188[7]; uVar13 != 0; uVar13 = *(uint *)(uVar13 + 0x10)) {
      if ((*(char **)(uVar13 + 4) != (char *)0x0) &&
         (iVar4 = __stricmp("SHOW_MINIMAP",*(char **)(uVar13 + 4)), iVar4 == 0)) {
        if (*(char **)(uVar13 + 8) == (char *)0x0) {
          lVar16 = 0;
        }
        else {
          lVar16 = _strtol(*(char **)(uVar13 + 8),(char **)0x0,10);
        }
        break;
      }
    }
  }
  local_3c = lVar16 == 1;
  lVar15 = 1;
  if ((local_188 != (uint *)0x0) && (uVar13 = local_188[7], uVar13 != 0)) {
    lVar15 = 1;
    do {
      if ((*(char **)(uVar13 + 4) != (char *)0x0) &&
         (iVar4 = __stricmp("SHOW_PANEL",*(char **)(uVar13 + 4)), iVar4 == 0)) {
        if (*(char **)(uVar13 + 8) == (char *)0x0) {
          lVar15 = 0;
        }
        else {
          lVar15 = _strtol(*(char **)(uVar13 + 8),(char **)0x0,10);
        }
        break;
      }
      uVar13 = *(uint *)(uVar13 + 0x10);
    } while (uVar13 != 0);
  }
  local_3b = lVar15 == 1;
  if (local_188 != (uint *)0x0) {
    for (uVar13 = local_188[7]; uVar13 != 0; uVar13 = *(uint *)(uVar13 + 0x10)) {
      if ((*(char **)(uVar13 + 4) != (char *)0x0) &&
         (iVar4 = __stricmp("NAMECOLOR",*(char **)(uVar13 + 4)), iVar4 == 0)) {
        uVar13 = local_188[7];
        goto joined_r0x004f4f90;
      }
    }
  }
  goto LAB_004f5084;
joined_r0x004f4f90:
  if (uVar13 == 0) goto LAB_004f4fb6;
  if ((*(char **)(uVar13 + 4) != (char *)0x0) &&
     (iVar4 = __stricmp("NAMECOLOR",*(char **)(uVar13 + 4)), iVar4 == 0)) {
    pcVar12 = *(char **)(uVar13 + 8);
    if (pcVar12 == (char *)0x0) {
      pcVar12 = "";
    }
    goto LAB_004f4fb8;
  }
  uVar13 = *(uint *)(uVar13 + 0x10);
  goto joined_r0x004f4f90;
LAB_004f4fb6:
  pcVar12 = (char *)0x0;
LAB_004f4fb8:
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
  pcVar6 = pcVar12;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(pcVar12,(int)pcVar6 - (int)(pcVar12 + 1));
  uVar13 = local_1c;
  ppppcVar7 = (char ****)local_30[0];
  if (local_1c < 0x10) {
    ppppcVar7 = local_30;
  }
  if ((*(char *)ppppcVar7 == '#') && (local_20 == 7)) {
    uVar8 = FUN_0049b1b0();
    uVar9 = FUN_0049b1b0();
    uVar10 = FUN_0049b1b0();
    local_48 = ((uVar8 | 0xffffff00) << 8 | uVar9 & 0xff) << 8 | uVar10 & 0xff;
  }
  if (0xf < uVar13) {
    FUN_0089120c(local_30[0]);
  }
LAB_004f5084:
  iVar4 = FUN_004f7a70();
  FUN_00403040(local_9c,0,0xffffffff);
  FUN_004026e0(local_80,0,0xffffffff);
  FUN_00403040(local_64,0,0xffffffff);
  *(uint *)(iVar4 + 0x54) = local_48;
  *(long *)(iVar4 + 0x58) = local_44;
  *(float *)(iVar4 + 0x5c) = local_40;
  *(undefined1 *)(iVar4 + 0x60) = local_3c;
  *(undefined1 *)(iVar4 + 0x61) = local_3b;
  if (local_188 != (uint *)0x0) {
    for (puVar14 = (uint *)local_188[6]; puVar14 != (uint *)0x0; puVar14 = (uint *)puVar14[6]) {
      if ((*puVar14 & 7) == 1) goto LAB_004f5112;
    }
  }
  puVar14 = (uint *)0x0;
LAB_004f5112:
  local_188 = puVar14;
  if (0xf < local_50) {
    FUN_0089120c(local_64[0]);
  }
  local_50 = 0xf;
  local_54 = 0;
  local_64[0] = local_64[0] & 0xffffff00;
  if (7 < local_6c) {
    FUN_0089120c(local_80[0]);
  }
  local_6c = 7;
  local_70 = 0;
  local_80[0] = local_80[0] & 0xffff0000;
  if (0xf < local_88) {
    FUN_0089120c(local_9c[0]);
  }
  puVar11 = local_190;
  puVar5 = local_188;
  if (puVar14 == (uint *)0x0) goto LAB_004f5182;
  goto LAB_004f4bc6;
LAB_004f51ea:
  do {
    if ((*puVar11 & 7) == 1) goto LAB_004f522c;
    for (puVar11 = (uint *)puVar11[6]; puVar11 != (uint *)0x0; puVar11 = (uint *)puVar11[6]) {
      if (((char *)puVar11[2] != (char *)0x0) &&
         (iVar4 = __stricmp("OBJCATEGORY",(char *)puVar11[2]), iVar4 == 0)) goto LAB_004f5226;
    }
LAB_004f5224:
    puVar11 = (uint *)0x0;
LAB_004f5226:
  } while (puVar11 != (uint *)0x0);
  goto LAB_004f522a;
}

