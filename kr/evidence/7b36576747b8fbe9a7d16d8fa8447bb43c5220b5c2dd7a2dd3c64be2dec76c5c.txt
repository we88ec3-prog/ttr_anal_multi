
void FUN_004c0ec0(int ****param_1)

{
  int **ppiVar1;
  char cVar2;
  int ****ppppiVar3;
  int *piVar4;
  undefined4 uVar5;
  int ***pppiVar6;
  long lVar7;
  int iVar8;
  long lVar9;
  float *pfVar10;
  float *pfVar11;
  float10 fVar12;
  float fStack_1b4;
  uint *puStack_1b0;
  int ***local_1ac;
  long lStack_1a8;
  float fStack_1a4;
  float fStack_1a0;
  float fStack_19c;
  int iStack_198;
  int iStack_194;
  int iStack_190;
  float fStack_18c;
  float fStack_188;
  int *local_184;
  int iStack_180;
  int iStack_17c;
  int iStack_178;
  int iStack_174;
  int **local_170;
  int **local_16c;
  float afStack_168 [2];
  undefined1 uStack_160;
  float fStack_15c;
  long lStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  long lStack_144;
  int ***local_140;
  int ***local_13c;
  undefined4 local_130;
  uint local_12c;
  uint local_124;
  undefined4 local_114;
  uint local_110;
  undefined4 local_108;
  undefined4 local_104;
  undefined1 local_40;
  uint local_3c;
  undefined4 local_2c;
  uint local_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093874c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&fStack_1b4;
  ExceptionList = &local_14;
  local_1ac = (int ***)param_1;
  local_108 = 0;
  local_104 = 0;
  FUN_0071bc20(DAT_00d61f20 ^ (uint)&stack0xfffffe40);
  local_40 = 0;
  local_28 = 0xf;
  local_2c = 0;
  local_3c = local_3c & 0xffffff00;
  local_c = 0;
  local_12c = 0xf;
  local_130 = 0;
  local_140 = (int ***)((uint)local_140 & 0xffffff00);
  FUN_00402a70("Table/ExpeditionPosition.xml",0x1c);
  local_c = CONCAT31(local_c._1_3_,1);
  ppppiVar3 = (int ****)local_140;
  if (local_12c < 0x10) {
    ppppiVar3 = &local_140;
  }
  piVar4 = (int *)FUN_00714770(ppppiVar3,&DAT_00bed1e0);
  if (piVar4 == (int *)0x0) {
    cVar2 = '\0';
  }
  else {
    (**(code **)(*piVar4 + 0x38))();
    uVar5 = (**(code **)(*piVar4 + 0x2c))();
    cVar2 = FUN_00499340(uVar5);
    (**(code **)(*piVar4 + 4))();
  }
  local_c = local_c & 0xffffff00;
  if (0xf < local_12c) {
    FUN_0089120c(local_140);
  }
  if (cVar2 == '\0') {
    local_c = 0xffffffff;
    if (0xf < local_28) {
      FUN_0089120c(local_3c);
    }
  }
  else {
    FUN_004c2900();
    local_c._0_1_ = 2;
    FUN_0071a090(&local_140);
    local_c = CONCAT31(local_c._1_3_,4);
    if (0xf < local_110) {
      FUN_0089120c(local_124);
    }
    local_110 = 0xf;
    local_114 = 0;
    local_124 = local_124 & 0xffffff00;
    local_1ac = local_140;
    ppppiVar3 = (int ****)local_140;
    if (local_140 != local_13c) {
      do {
        lVar7 = 0;
        local_170 = *local_1ac;
        local_16c = local_1ac[1];
        if ((int ***)local_16c == (int ***)0x0) {
          pppiVar6 = &local_170;
        }
        else {
          local_184 = (int *)0x0;
          pppiVar6 = (int ***)&local_184;
        }
        ppiVar1 = *pppiVar6;
        if ((ppiVar1 != (int **)0x0) && (((uint)*ppiVar1 & 7) == 1)) {
          lStack_1a8 = 0;
          puStack_1b0 = (uint *)ppiVar1;
          FUN_0071baa0(&DAT_00c071fc);
          if (iStack_190 != 0) {
            if (*(char **)(iStack_190 + 8) == (char *)0x0) {
              lStack_1a8 = 0;
            }
            else {
              lStack_1a8 = _strtol(*(char **)(iStack_190 + 8),(char **)0x0,10);
            }
          }
          fStack_1a0 = 0.0;
          FUN_0071baa0(&DAT_00c06928);
          if (iStack_17c != 0) {
            if (*(int *)(iStack_17c + 8) == 0) {
              fStack_1a0 = 0.0;
            }
            else {
              fVar12 = (float10)FUN_00898a3f(*(int *)(iStack_17c + 8),0);
              fStack_1b4 = (float)fVar12;
              fStack_1a0 = fStack_1b4;
            }
          }
          fStack_1a4 = 0.0;
          FUN_0071baa0(&DAT_00c0692c);
          if (iStack_198 != 0) {
            if (*(int *)(iStack_198 + 8) == 0) {
              fStack_1a4 = 0.0;
            }
            else {
              fVar12 = (float10)FUN_00898a3f(*(int *)(iStack_198 + 8),0);
              fStack_1b4 = (float)fVar12;
              fStack_1a4 = fStack_1b4;
            }
          }
          fStack_19c = 0.0;
          FUN_0071baa0("scale");
          if (iStack_174 != 0) {
            if (*(int *)(iStack_174 + 8) == 0) {
              fStack_19c = 0.0;
            }
            else {
              fVar12 = (float10)FUN_00898a3f(*(int *)(iStack_174 + 8),0);
              fStack_19c = (float)fVar12;
            }
          }
          fStack_1b4 = 0.0;
          FUN_0071baa0(&PTR_LAB_00c07268);
          if (iStack_178 != 0) {
            if (*(char **)(iStack_178 + 8) == (char *)0x0) {
              fStack_1b4 = 0.0;
            }
            else {
              fStack_1b4 = (float)_strtol(*(char **)(iStack_178 + 8),(char **)0x0,10);
            }
          }
          FUN_0071baa0("weapon");
          if (iStack_180 != 0) {
            if (*(char **)(iStack_180 + 8) == (char *)0x0) {
              lVar7 = 0;
            }
            else {
              lVar7 = _strtol(*(char **)(iStack_180 + 8),(char **)0x0,10);
            }
          }
          lVar9 = 0;
          FUN_0071baa0("sitdown");
          if (iStack_194 != 0) {
            if (*(char **)(iStack_194 + 8) == (char *)0x0) {
              lVar9 = 0;
            }
            else {
              lVar9 = _strtol(*(char **)(iStack_194 + 8),(char **)0x0,10);
            }
          }
          uStack_154 = 0;
          uStack_150 = 0;
          uStack_14c = 0;
          uStack_148 = 0;
          fStack_15c = fStack_19c;
          uStack_160 = fStack_1b4._0_1_;
          lStack_144 = lVar9;
          fStack_18c = fStack_1a0;
          lStack_158 = lVar7;
          pfVar10 = afStack_168;
          pfVar11 = (float *)(&DAT_00fba950 + lStack_1a8 * 0x28);
          for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
            *pfVar11 = *pfVar10;
            pfVar10 = pfVar10 + 1;
            pfVar11 = pfVar11 + 1;
          }
          fStack_188 = fStack_1a4;
          *(float *)(&DAT_00fba950 + lStack_1a8 * 0x28) = fStack_1a0;
          *(float *)(&DAT_00fba954 + lStack_1a8 * 0x28) = fStack_1a4;
          ppppiVar3 = (int ****)local_140;
        }
        local_1ac = local_1ac + 2;
      } while (local_1ac != local_13c);
    }
    if (ppppiVar3 != (int ****)0x0) {
      FUN_0089120c(ppppiVar3);
    }
    local_c = 0xffffffff;
    if (0xf < local_28) {
      FUN_0089120c(local_3c);
    }
  }
  local_2c = 0;
  local_28 = 0xf;
  local_3c = local_3c & 0xffffff00;
  FUN_0071bc90(&local_108);
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&fStack_1b4);
  return;
}

