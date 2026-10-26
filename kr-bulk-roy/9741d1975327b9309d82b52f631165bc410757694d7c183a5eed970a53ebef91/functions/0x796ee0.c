
void FUN_00796ee0(void)

{
  int *piVar1;
  float *pfVar2;
  float *pfVar3;
  float **ppfVar4;
  float **ppfVar5;
  uint *puVar6;
  char cVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  float fVar11;
  int iVar12;
  int *piVar13;
  char *pcVar14;
  undefined4 *puVar15;
  uint uVar16;
  int in_ECX;
  double dVar17;
  undefined1 auStack_ac [4];
  float fStack_a8;
  int *local_a4;
  float *local_a0;
  uint *local_9c;
  undefined **local_98 [19];
  uint local_4c;
  undefined4 uStack_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092287b;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_ac;
  ExceptionList = &local_14;
  FUN_00797510(DAT_00d61f20 ^ (uint)&stack0xffffff48);
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar7 = FUN_0072f110(0);
  if (cVar7 != '\0') {
    FUN_0072e2e0("cameraworks");
    local_a4 = (int *)FUN_0072e2e0("keyframe");
    if (local_a4 != (int *)0x0) {
      local_9c = (uint *)(in_ECX + 4);
      do {
        pfVar8 = (float *)FUN_00891268(0x28);
        if (pfVar8 == (float *)0x0) {
          pfVar8 = (float *)0x0;
        }
        else {
          *pfVar8 = 0.0;
          pfVar8[7] = 0.0;
          pfVar8[1] = 0.0;
          pfVar8[9] = 0.0;
          pfVar8[2] = 0.0;
          pfVar8[3] = 0.0;
          pfVar8[4] = 0.0;
          pfVar8[5] = 0.0;
          pfVar8[6] = 0.0;
          pfVar8[8] = 0.0;
        }
        local_a0 = pfVar8;
        iVar9 = (**(code **)(*local_a4 + 0x14))();
        for (iVar12 = *(int *)(iVar9 + 0x94); iVar12 != iVar9 + 0x44;
            iVar12 = *(int *)(iVar12 + 0x50)) {
          pcVar14 = (char *)(iVar12 + 0x14);
          if (0xf < *(uint *)(iVar12 + 0x28)) {
            pcVar14 = *(char **)pcVar14;
          }
          iVar10 = __stricmp(pcVar14,"framepos");
          if (iVar10 == 0) {
            if (iVar12 != 0) {
              puVar15 = (undefined4 *)(iVar12 + 0x30);
              if (0xf < *(uint *)(iVar12 + 0x44)) {
                puVar15 = (undefined4 *)*puVar15;
              }
              if (puVar15 != (undefined4 *)0x0) {
                fVar11 = (float)FUN_008917b4(puVar15);
                goto LAB_0079700b;
              }
            }
            break;
          }
        }
        fVar11 = 0.0;
LAB_0079700b:
        pfVar8[9] = fVar11;
        iVar9 = (**(code **)(*local_a4 + 0x14))();
        for (iVar12 = *(int *)(iVar9 + 0x94); iVar12 != iVar9 + 0x44;
            iVar12 = *(int *)(iVar12 + 0x50)) {
          pcVar14 = (char *)(iVar12 + 0x14);
          if (0xf < *(uint *)(iVar12 + 0x28)) {
            pcVar14 = *(char **)pcVar14;
          }
          iVar10 = __stricmp(pcVar14,"followtarget");
          if (iVar10 == 0) break;
        }
        for (piVar1 = (int *)local_a4[6]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x10]) {
          piVar13 = piVar1 + 8;
          if (0xf < (uint)piVar1[0xd]) {
            piVar13 = (int *)*piVar13;
          }
          iVar12 = __stricmp((char *)piVar13,"position");
          if (iVar12 == 0) {
            if (((piVar1 != (int *)0x0) && (iVar12 = (**(code **)(*piVar1 + 0x14))(), iVar12 != 0))
               && (iVar12 = (**(code **)(*piVar1 + 0x14))(), iVar12 != 0)) {
              iVar12 = FUN_007300a0(&DAT_00c06928);
              if (iVar12 == 0) {
LAB_0079710f:
                fStack_a8 = 0.0;
              }
              else {
                pcVar14 = (char *)(iVar12 + 0x30);
                if (0xf < *(uint *)(iVar12 + 0x44)) {
                  pcVar14 = *(char **)pcVar14;
                }
                if (pcVar14 == (char *)0x0) goto LAB_0079710f;
                dVar17 = _atof(pcVar14);
                fStack_a8 = (float)dVar17;
              }
              *pfVar8 = fStack_a8;
              iVar12 = FUN_007300a0(&DAT_00c0692c);
              if (iVar12 == 0) {
LAB_00797146:
                fStack_a8 = 0.0;
              }
              else {
                pcVar14 = (char *)(iVar12 + 0x30);
                if (0xf < *(uint *)(iVar12 + 0x44)) {
                  pcVar14 = *(char **)pcVar14;
                }
                if (pcVar14 == (char *)0x0) goto LAB_00797146;
                dVar17 = _atof(pcVar14);
                fStack_a8 = (float)dVar17;
              }
              pfVar8[1] = fStack_a8;
              iVar12 = FUN_007300a0(&DAT_00c4f1ec);
              if (iVar12 == 0) {
LAB_0079717e:
                fStack_a8 = 0.0;
              }
              else {
                pcVar14 = (char *)(iVar12 + 0x30);
                if (0xf < *(uint *)(iVar12 + 0x44)) {
                  pcVar14 = *(char **)pcVar14;
                }
                if (pcVar14 == (char *)0x0) goto LAB_0079717e;
                dVar17 = _atof(pcVar14);
                fStack_a8 = (float)dVar17;
              }
              pfVar8[2] = fStack_a8;
            }
            break;
          }
        }
        for (piVar1 = (int *)local_a4[6]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x10]) {
          piVar13 = piVar1 + 8;
          if (0xf < (uint)piVar1[0xd]) {
            piVar13 = (int *)*piVar13;
          }
          iVar12 = __stricmp((char *)piVar13,"pivot");
          if (iVar12 == 0) {
            if (((piVar1 != (int *)0x0) && (iVar12 = (**(code **)(*piVar1 + 0x14))(), iVar12 != 0))
               && (iVar12 = (**(code **)(*piVar1 + 0x14))(), iVar12 != 0)) {
              iVar12 = FUN_007300a0("pitch");
              if (iVar12 == 0) {
LAB_00797225:
                fStack_a8 = 0.0;
              }
              else {
                pcVar14 = (char *)(iVar12 + 0x30);
                if (0xf < *(uint *)(iVar12 + 0x44)) {
                  pcVar14 = *(char **)pcVar14;
                }
                if (pcVar14 == (char *)0x0) goto LAB_00797225;
                dVar17 = _atof(pcVar14);
                fStack_a8 = (float)dVar17;
              }
              pfVar8[3] = fStack_a8;
              iVar12 = FUN_007300a0(&DAT_00c4f200);
              if (iVar12 == 0) {
LAB_0079725d:
                fStack_a8 = 0.0;
              }
              else {
                pcVar14 = (char *)(iVar12 + 0x30);
                if (0xf < *(uint *)(iVar12 + 0x44)) {
                  pcVar14 = *(char **)pcVar14;
                }
                if (pcVar14 == (char *)0x0) goto LAB_0079725d;
                dVar17 = _atof(pcVar14);
                fStack_a8 = (float)dVar17;
              }
              pfVar8[4] = fStack_a8;
              iVar12 = FUN_007300a0(&DAT_00c4f204);
              if (iVar12 == 0) {
LAB_00797295:
                fStack_a8 = 0.0;
              }
              else {
                pcVar14 = (char *)(iVar12 + 0x30);
                if (0xf < *(uint *)(iVar12 + 0x44)) {
                  pcVar14 = *(char **)pcVar14;
                }
                if (pcVar14 == (char *)0x0) goto LAB_00797295;
                dVar17 = _atof(pcVar14);
                fStack_a8 = (float)dVar17;
              }
              pfVar8[5] = fStack_a8;
              iVar12 = FUN_007300a0(&DAT_00c4f20c);
              if (iVar12 == 0) {
LAB_007972cd:
                fStack_a8 = 0.0;
              }
              else {
                pcVar14 = (char *)(iVar12 + 0x30);
                if (0xf < *(uint *)(iVar12 + 0x44)) {
                  pcVar14 = *(char **)pcVar14;
                }
                if (pcVar14 == (char *)0x0) goto LAB_007972cd;
                dVar17 = _atof(pcVar14);
                fStack_a8 = (float)dVar17;
              }
              pfVar8[6] = fStack_a8;
              iVar12 = FUN_007300a0("easing");
              if (iVar12 == 0) {
LAB_00797305:
                fStack_a8 = 0.0;
              }
              else {
                pcVar14 = (char *)(iVar12 + 0x30);
                if (0xf < *(uint *)(iVar12 + 0x44)) {
                  pcVar14 = *(char **)pcVar14;
                }
                if (pcVar14 == (char *)0x0) goto LAB_00797305;
                dVar17 = _atof(pcVar14);
                fStack_a8 = (float)dVar17;
              }
              pfVar8[8] = fStack_a8;
              iVar12 = FUN_007300a0("easingtype");
              if (iVar12 == 0) {
LAB_00797339:
                fVar11 = 0.0;
              }
              else {
                puVar15 = (undefined4 *)(iVar12 + 0x30);
                if (0xf < *(uint *)(iVar12 + 0x44)) {
                  puVar15 = (undefined4 *)*puVar15;
                }
                if (puVar15 == (undefined4 *)0x0) goto LAB_00797339;
                fVar11 = (float)FUN_008917b4(puVar15);
              }
              pfVar8[7] = fVar11;
            }
            break;
          }
        }
        puVar6 = local_9c;
        uVar16 = (int)(local_9c[1] - *local_9c) >> 2;
        if (1 < uVar16) {
          pfVar2 = *(float **)((*local_9c - 8) + uVar16 * 4);
          pfVar3 = *(float **)((*local_9c - 4) + uVar16 * 4);
          fVar11 = pfVar3[9];
          if (pfVar8[9] == fVar11) {
            if (((*pfVar3 == *pfVar2) && (pfVar3[1] == pfVar2[1])) &&
               ((pfVar3[2] == pfVar2[2] &&
                (((pfVar3[3] == pfVar2[3] && (pfVar3[4] == pfVar2[4])) && (pfVar3[6] == pfVar2[6])))
                ))) {
              if (*local_9c != local_9c[1]) {
                local_9c[1] = local_9c[1] - 4;
              }
              *(undefined4 *)
               (*(int *)((*local_9c - 4) + ((int)(local_9c[1] - *local_9c) >> 2) * 4) + 0x1c) = 4;
            }
            else if (1 < (int)fVar11 - (int)pfVar2[9]) {
              pfVar3[9] = (float)((int)fVar11 + -1);
            }
          }
        }
        ppfVar4 = (float **)local_9c[1];
        if (&local_a0 < ppfVar4) {
          ppfVar5 = (float **)*local_9c;
          if (&local_a0 < ppfVar5) goto LAB_0079742d;
          if (ppfVar4 == (float **)local_9c[2]) {
            FUN_00797930();
          }
          if ((undefined4 *)puVar6[1] != (undefined4 *)0x0) {
            *(undefined4 *)puVar6[1] =
                 *(undefined4 *)(*puVar6 + ((int)&local_a0 - (int)ppfVar5 >> 2) * 4);
          }
        }
        else {
LAB_0079742d:
          if (ppfVar4 == (float **)local_9c[2]) {
            FUN_00797930();
          }
          if ((undefined4 *)puVar6[1] != (undefined4 *)0x0) {
            *(undefined4 *)puVar6[1] = pfVar8;
          }
        }
        puVar6[1] = puVar6[1] + 4;
        local_a4 = (int *)local_a4[0x10];
      } while (local_a4 != (int *)0x0);
    }
  }
  local_c = 0xffffffff;
  local_98[0] = TiXmlDocument::vftable;
  if (0xf < local_38) {
    FUN_0089120c(local_4c);
  }
  local_38 = 0xf;
  uStack_3c = 0;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_ac);
  return;
}

