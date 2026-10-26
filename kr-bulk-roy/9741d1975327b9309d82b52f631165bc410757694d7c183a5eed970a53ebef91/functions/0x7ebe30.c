
undefined4 FUN_007ebe30(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  char *pcVar7;
  undefined4 *puVar8;
  int *_Str1;
  float fVar9;
  float fVar10;
  double dVar11;
  float local_10;
  float local_c;
  
  piVar2 = (int *)FUN_0072e2e0(&DAT_00c507d4);
joined_r0x007ebe48:
  do {
    if (piVar2 == (int *)0x0) {
      return 1;
    }
    iVar3 = (**(code **)(*piVar2 + 0x14))();
    if (iVar3 != 0) {
      iVar1 = iVar3 + 0x44;
      for (iVar5 = *(int *)(iVar3 + 0x94); iVar5 != iVar1; iVar5 = *(int *)(iVar5 + 0x50)) {
        pcVar7 = (char *)(iVar5 + 0x14);
        if (0xf < *(uint *)(iVar5 + 0x28)) {
          pcVar7 = *(char **)pcVar7;
        }
        iVar4 = __stricmp(pcVar7,"Start");
        if (iVar4 == 0) {
          if (iVar5 != 0) {
            pcVar7 = (char *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              pcVar7 = *(char **)pcVar7;
            }
            if (pcVar7 != (char *)0x0) {
              dVar11 = _atof(pcVar7);
              local_c = (float)dVar11;
              goto LAB_007ebec7;
            }
          }
          break;
        }
      }
      local_c = 0.0;
LAB_007ebec7:
      for (iVar5 = *(int *)(iVar3 + 0x94); iVar5 != iVar1; iVar5 = *(int *)(iVar5 + 0x50)) {
        pcVar7 = (char *)(iVar5 + 0x14);
        if (0xf < *(uint *)(iVar5 + 0x28)) {
          pcVar7 = *(char **)pcVar7;
        }
        iVar4 = __stricmp(pcVar7,"End");
        if (iVar4 == 0) {
          if (iVar5 != 0) {
            pcVar7 = (char *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              pcVar7 = *(char **)pcVar7;
            }
            if (pcVar7 != (char *)0x0) {
              dVar11 = _atof(pcVar7);
              local_10 = (float)dVar11;
              goto LAB_007ebefc;
            }
          }
          break;
        }
      }
      local_10 = 0.0;
LAB_007ebefc:
      for (iVar5 = *(int *)(iVar3 + 0x94); iVar5 != iVar1; iVar5 = *(int *)(iVar5 + 0x50)) {
        pcVar7 = (char *)(iVar5 + 0x14);
        if (0xf < *(uint *)(iVar5 + 0x28)) {
          pcVar7 = *(char **)pcVar7;
        }
        iVar4 = __stricmp(pcVar7,"Color");
        if (iVar4 == 0) {
          if (iVar5 != 0) {
            puVar8 = (undefined4 *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              puVar8 = (undefined4 *)*puVar8;
            }
            if (puVar8 != (undefined4 *)0x0) {
              fVar10 = (float)FUN_008917b4(puVar8);
              goto LAB_007ebf2c;
            }
          }
          break;
        }
      }
      fVar10 = 0.0;
LAB_007ebf2c:
      for (iVar3 = *(int *)(iVar3 + 0x94); iVar3 != iVar1; iVar3 = *(int *)(iVar3 + 0x50)) {
        pcVar7 = (char *)(iVar3 + 0x14);
        if (0xf < *(uint *)(iVar3 + 0x28)) {
          pcVar7 = *(char **)pcVar7;
        }
        iVar5 = __stricmp(pcVar7,"Enable");
        if (iVar5 == 0) {
          if (iVar3 != 0) {
            puVar8 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar8 = (undefined4 *)*puVar8;
            }
            if (puVar8 != (undefined4 *)0x0) {
              fVar9 = (float)FUN_008917b4(puVar8);
              goto LAB_007ebf5d;
            }
          }
          break;
        }
      }
      fVar9 = 0.0;
LAB_007ebf5d:
      pfVar6 = (float *)FUN_00891268(0x10);
      if (pfVar6 == (float *)0x0) {
        pfVar6 = (float *)0x0;
      }
      else {
        pfVar6[3] = fVar9;
        *pfVar6 = local_c;
        pfVar6[2] = fVar10;
        pfVar6[1] = local_10;
      }
      if (*(int *)(param_1 + 0xc) != 0) {
        FUN_0089120c(*(int *)(param_1 + 0xc));
        *(undefined4 *)(param_1 + 0xc) = 0;
      }
      *(float **)(param_1 + 0xc) = pfVar6;
    }
    for (piVar2 = (int *)piVar2[0x10]; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0x10]) {
      _Str1 = piVar2 + 8;
      if (0xf < (uint)piVar2[0xd]) {
        _Str1 = (int *)*_Str1;
      }
      iVar3 = __stricmp((char *)_Str1,"Fog");
      if (iVar3 == 0) goto joined_r0x007ebe48;
    }
    piVar2 = (int *)0x0;
  } while( true );
}

