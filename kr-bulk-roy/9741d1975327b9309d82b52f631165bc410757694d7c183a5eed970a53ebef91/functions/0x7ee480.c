
void FUN_007ee480(int *param_1)

{
  char cVar1;
  float *pfVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  float fVar11;
  float *pfVar12;
  char ******ppppppcVar13;
  int *_Str1;
  int in_ECX;
  bool bVar14;
  double dVar15;
  uint *puVar16;
  undefined1 *puVar17;
  float local_6c;
  uint local_68;
  undefined4 local_58;
  uint local_54;
  char *****local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009186f6;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  local_14 = uVar3;
  FUN_00402a70(&DAT_00c50910,4);
  local_8 = 0;
  iVar4 = in_ECX + 0x28;
  puVar16 = local_30;
  (**(code **)(*param_1 + 0x14))(puVar16,iVar4,uVar3);
  iVar4 = FUN_007a4680(puVar16,iVar4);
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  if (iVar4 == 1) {
    *(undefined4 *)(in_ECX + 0x24) = 0;
  }
  else {
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffffff00;
    FUN_00402a70(&DAT_00c50910,4);
    local_8 = 1;
    puVar17 = &DAT_00bf2375;
    (**(code **)(*param_1 + 0x14))(&DAT_00bf2375);
    uVar5 = FUN_0072ecf0(puVar17);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00402bb0(uVar5);
    if (0xf < local_54) {
      FUN_0089120c(local_68);
    }
    local_8 = 0xffffffff;
    local_54 = 0xf;
    local_58 = 0;
    local_68 = local_68 & 0xffffff00;
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    *(undefined4 *)(in_ECX + 0x24) = 1;
  }
  (**(code **)(*param_1 + 0x14))();
  iVar4 = FUN_007300a0(&DAT_00c50918);
  if (iVar4 == 0) {
LAB_007ee5f0:
    local_6c = 30.0;
  }
  else {
    pcVar6 = (char *)(iVar4 + 0x30);
    if (0xf < *(uint *)(iVar4 + 0x44)) {
      pcVar6 = *(char **)pcVar6;
    }
    if (pcVar6 == (char *)0x0) goto LAB_007ee5f0;
    dVar15 = _atof(pcVar6);
    local_6c = (float)dVar15;
  }
  *(float *)(in_ECX + 0x20) = local_6c;
  (**(code **)(*param_1 + 0x14))();
  iVar4 = FUN_007300a0("BoundSize");
  if (iVar4 != 0) {
    pcVar6 = (char *)(iVar4 + 0x30);
    if (0xf < *(uint *)(iVar4 + 0x44)) {
      pcVar6 = *(char **)pcVar6;
    }
    if (pcVar6 != (char *)0x0) {
      dVar15 = _atof(pcVar6);
      local_6c = (float)dVar15;
      goto LAB_007ee642;
    }
  }
  local_6c = 100.0;
LAB_007ee642:
  *(float *)(in_ECX + 0x48) = local_6c;
  piVar7 = (int *)FUN_0072e2e0("Particle");
  do {
    if (piVar7 == (int *)0x0) {
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    iVar8 = (**(code **)(*piVar7 + 0x14))();
    for (iVar4 = *(int *)(iVar8 + 0x94); iVar4 != iVar8 + 0x44; iVar4 = *(int *)(iVar4 + 0x50)) {
      pcVar6 = (char *)(iVar4 + 0x14);
      if (0xf < *(uint *)(iVar4 + 0x28)) {
        pcVar6 = *(char **)pcVar6;
      }
      iVar9 = __stricmp(pcVar6,"Type");
      if (iVar9 == 0) {
        if (iVar4 != 0) {
          pcVar6 = (char *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            pcVar6 = *(char **)pcVar6;
          }
          goto LAB_007ee6c1;
        }
        break;
      }
    }
    pcVar6 = (char *)0x0;
LAB_007ee6c1:
    local_38 = 0xf;
    local_3c = 0;
    local_4c[0] = (char *****)((uint)local_4c[0] & 0xffffff00);
    pcVar10 = pcVar6;
    do {
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar6,(int)pcVar10 - (int)(pcVar6 + 1));
    local_8 = 3;
    ppppppcVar13 = (char ******)local_4c[0];
    if (local_38 < 0x10) {
      ppppppcVar13 = local_4c;
    }
    iVar4 = __stricmp((char *)ppppppcVar13,"PointSprite");
    if (iVar4 == 0) {
      local_6c = (float)FUN_00891268(0x80);
      local_8._0_1_ = 4;
      if (local_6c == 0.0) {
        fVar11 = 0.0;
      }
      else {
        fVar11 = (float)FUN_007fa190(local_6c);
      }
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_007faab0(fVar11);
      pfVar12 = *(float **)(in_ECX + 0x10);
      bVar14 = &local_6c < pfVar12;
LAB_007ee74b:
      local_6c = fVar11;
      if (bVar14) {
        pfVar2 = *(float **)(in_ECX + 0xc);
        if (&local_6c < pfVar2) goto LAB_007ee7e7;
        if (pfVar12 == *(float **)(in_ECX + 0x14)) {
          FUN_00797930();
        }
        if (*(undefined4 **)(in_ECX + 0x10) != (undefined4 *)0x0) {
          **(undefined4 **)(in_ECX + 0x10) =
               *(undefined4 *)(*(int *)(in_ECX + 0xc) + ((int)&local_6c - (int)pfVar2 >> 2) * 4);
        }
      }
      else {
LAB_007ee7e7:
        if (pfVar12 == *(float **)(in_ECX + 0x14)) {
          FUN_00797930();
        }
        if (*(float **)(in_ECX + 0x10) != (float *)0x0) {
          **(float **)(in_ECX + 0x10) = fVar11;
        }
      }
      *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 4;
    }
    else {
      ppppppcVar13 = (char ******)local_4c[0];
      if (local_38 < 0x10) {
        ppppppcVar13 = local_4c;
      }
      iVar4 = __stricmp((char *)ppppppcVar13,"QuadPatch");
      if (iVar4 == 0) {
        local_6c = (float)FUN_00891268(0x140);
        local_8._0_1_ = 5;
        if (local_6c == 0.0) {
          fVar11 = 0.0;
        }
        else {
          fVar11 = (float)FUN_007faf00(local_6c);
        }
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_007fbe70(fVar11);
        pfVar12 = *(float **)(in_ECX + 0x10);
        bVar14 = &local_6c < pfVar12;
        goto LAB_007ee74b;
      }
    }
    for (piVar7 = (int *)piVar7[0x10]; piVar7 != (int *)0x0; piVar7 = (int *)piVar7[0x10]) {
      _Str1 = piVar7 + 8;
      if (0xf < (uint)piVar7[0xd]) {
        _Str1 = (int *)*_Str1;
      }
      iVar4 = __stricmp((char *)_Str1,"Particle");
      if (iVar4 == 0) goto LAB_007ee835;
    }
    piVar7 = (int *)0x0;
LAB_007ee835:
    local_8 = 0xffffffff;
    if (0xf < local_38) {
      FUN_0089120c(local_4c[0]);
    }
  } while( true );
}

