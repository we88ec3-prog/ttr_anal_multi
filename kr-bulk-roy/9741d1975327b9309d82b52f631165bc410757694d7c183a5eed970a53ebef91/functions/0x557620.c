
void FUN_00557620(int param_1)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  code *pcVar6;
  float fVar7;
  uint *puVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 **ppuVar13;
  short *psVar14;
  undefined4 *puVar15;
  int iVar16;
  short *psVar17;
  int *piVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  uint *puVar22;
  uint *puVar23;
  bool bVar24;
  undefined2 in_FPUControlWord;
  int local_88;
  int local_74;
  int local_70;
  float local_6c;
  float local_68;
  int *local_64;
  uint *local_60;
  uint *local_5c;
  uint *local_58;
  undefined4 local_50;
  int local_4c;
  uint local_48;
  undefined4 *local_44;
  undefined4 *local_40;
  float local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092951a;
  local_10 = ExceptionList;
  uVar10 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar22 = (uint *)0x0;
  local_4c = param_1;
  local_60 = (uint *)0x0;
  local_5c = (uint *)0x0;
  local_58 = (uint *)0x0;
  local_8 = 0;
  piVar18 = (int *)**(int **)(param_1 + 4);
  local_64 = (int *)0x0;
  local_38 = 0.0;
  local_18 = uVar10;
  if (piVar18 != *(int **)(param_1 + 4)) {
    do {
      if (local_38 == *(float *)(local_4c + 0x10)) {
        local_64 = (int *)piVar18[4];
      }
      puVar23 = (uint *)(piVar18 + 4);
      if ((puVar23 < local_5c) && (puVar22 <= puVar23)) {
        iVar19 = (int)puVar23 - (int)puVar22;
        if (local_5c == local_58) {
          FUN_004deab0(uVar10);
          puVar22 = local_60;
        }
        if (local_5c != (uint *)0x0) {
          *local_5c = puVar22[iVar19 >> 2];
        }
      }
      else {
        if (local_5c == local_58) {
          FUN_004deab0(uVar10);
          puVar22 = local_60;
        }
        if (local_5c != (uint *)0x0) {
          *local_5c = *puVar23;
        }
      }
      puVar23 = local_5c + 1;
      if ((puVar22 != puVar23) && (0 < (int)local_5c - (int)puVar22 >> 2)) {
        local_48 = *local_5c;
        local_5c = puVar23;
        FUN_00557d80(&local_48,local_50);
        puVar23 = local_5c;
      }
      local_5c = puVar23;
      if (*(char *)((int)piVar18 + 0x15) == '\0') {
        piVar3 = (int *)piVar18[2];
        if (*(char *)((int)piVar3 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x15);
          piVar18 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x15);
            piVar18 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar18[1] + 0x15);
          piVar9 = (int *)piVar18[1];
          piVar3 = piVar18;
          while ((piVar18 = piVar9, cVar1 == '\0' && (piVar3 == (int *)piVar18[2]))) {
            cVar1 = *(char *)(piVar18[1] + 0x15);
            piVar9 = (int *)piVar18[1];
            piVar3 = piVar18;
          }
        }
      }
      local_38 = (float)((int)local_38 + 1);
    } while (piVar18 != *(int **)(local_4c + 4));
  }
  if (DAT_00fba7cc == 0) {
    iVar19 = FUN_00891268(0x1380);
    if (iVar19 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      *(undefined8 *)(iVar19 + 0x1350) = 0;
      *(undefined8 *)(iVar19 + 0x1358) = 0;
      *(undefined4 *)(iVar19 + 0x1370) = 1;
      *(undefined4 *)(iVar19 + 0x1374) = 1;
      *(undefined8 *)(iVar19 + 0x1368) = 0x3fa1111111111111;
      *(undefined4 *)(iVar19 + 0x1378) = 0;
      *(undefined4 *)(iVar19 + 0x1360) = 0x1e;
      FUN_006df660();
      DAT_00fba7cc = iVar19;
    }
  }
  iVar19 = DAT_00fba7cc;
  bVar24 = DAT_00d63d09 == '\0';
  if (!bVar24) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    bVar24 = DAT_00d63d09 == '\0';
  }
  if (!bVar24) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  uVar10 = *(uint *)(iVar19 + 0x28) >> 1;
  if (DAT_00fba7cc == 0) {
    iVar19 = FUN_00891268(0x1380);
    if (iVar19 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      *(undefined8 *)(iVar19 + 0x1350) = 0;
      *(undefined8 *)(iVar19 + 0x1358) = 0;
      *(undefined4 *)(iVar19 + 0x1370) = 1;
      *(undefined4 *)(iVar19 + 0x1374) = 1;
      *(undefined8 *)(iVar19 + 0x1368) = 0x3fa1111111111111;
      *(undefined4 *)(iVar19 + 0x1378) = 0;
      *(undefined4 *)(iVar19 + 0x1360) = 0x1e;
      FUN_006df660();
      DAT_00fba7cc = iVar19;
    }
  }
  iVar19 = DAT_00fba7cc;
  if ((DAT_00d63d09 != '\0') &&
     (EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8), DAT_00d63d09 != '\0')) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  uVar11 = *(uint *)(iVar19 + 0x2c) >> 1;
  local_48 = 0;
  puVar22 = local_5c;
  puVar23 = local_60;
  if (*(int *)(local_4c + 8) != 0) {
    do {
      puVar8 = local_60;
      uVar4 = *puVar23;
      if (4 < (int)((int)puVar22 - (int)puVar23 & 0xfffffffcU)) {
        local_3c = (float)puVar22[-1];
        puVar22[-1] = uVar4;
        iVar16 = (int)(((int)puVar22 - (int)puVar23) - 4U) >> 2;
        iVar19 = 2;
        iVar20 = 0;
        bVar24 = iVar16 == 2;
        iVar21 = iVar20;
        if (2 < iVar16) {
          do {
            iVar20 = iVar19;
            if (*(float *)(puVar23[iVar19 + -1] + 0xc) < *(float *)(puVar23[iVar19] + 0xc)) {
              iVar20 = iVar19 + -1;
            }
            puVar23[iVar21] = puVar23[iVar20];
            iVar19 = iVar20 * 2 + 2;
            bVar24 = iVar19 == iVar16;
            iVar21 = iVar20;
          } while (iVar19 < iVar16);
        }
        if (bVar24) {
          puVar23[iVar20] = puVar23[iVar16 + -1];
        }
        FUN_00557d80(&local_3c,local_50);
        puVar22 = local_5c;
        puVar23 = puVar8;
      }
      if (puVar23 != puVar22) {
        puVar22 = puVar22 + -1;
        local_5c = puVar22;
      }
      if (*(int **)(uVar4 + 4) != (int *)0x0) {
        iVar19 = (**(code **)(**(int **)(uVar4 + 4) + 0x14))();
        local_44 = (undefined4 *)((float)iVar19 * *(float *)(uVar4 + 0x20) * 0.5);
        local_3c = *(float *)(uVar4 + 0x20);
        iVar19 = (**(code **)(**(int **)(uVar4 + 4) + 0x18))();
        local_38 = local_3c * 0.5 + 0.3;
        if (local_38 < 1.0) {
          if (0.0 < local_38) {
            fVar7 = local_38 * 255.0;
            local_38 = (float)CONCAT22(in_FPUControlWord,SUB42(local_38,0));
            local_88 = (int)(longlong)ROUND(fVar7 + 0.5);
          }
          else {
            local_88 = 0;
          }
        }
        else {
          local_88 = 0xff;
        }
        local_40 = (undefined4 *)(*(float *)(uVar4 + 0xc) - local_3c * (float)iVar19 * 0.5);
        local_6c = local_3c;
        local_44 = (undefined4 *)(*(float *)(uVar4 + 8) - (float)local_44);
        local_68 = local_3c;
        (**(code **)(**(int **)(uVar4 + 4) + 0x30))
                  (local_44,local_40,0,&local_6c,local_88 << 0x18 | 0xffffff);
      }
      local_48 = local_48 + 1;
    } while (local_48 < *(uint *)(local_4c + 8));
  }
  local_20 = 7;
  local_24 = 0;
  local_34 = (undefined4 *)((uint)local_34._2_2_ << 0x10);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_64 == (int *)0x0) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 3;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    cVar1 = *(char *)((int)DAT_00fe5ac8[1] + 0x2d);
    puVar12 = (undefined4 *)DAT_00fe5ac8[1];
    local_44 = DAT_00fe5ac8;
    while (puVar15 = puVar12, cVar1 == '\0') {
      if ((int)puVar15[3] < 0x7d) {
        puVar12 = (undefined4 *)puVar15[2];
        puVar15 = local_44;
      }
      else {
        puVar12 = (undefined4 *)*puVar15;
      }
      cVar1 = *(char *)((int)puVar12 + 0x2d);
      local_44 = puVar15;
    }
    if ((local_44 == DAT_00fe5ac8) || (0x7d < (int)local_44[3])) {
      local_40 = DAT_00fe5ac8;
      ppuVar13 = &local_40;
    }
    else {
      ppuVar13 = &local_44;
    }
    puVar12 = *ppuVar13;
    if (puVar12 == DAT_00fe5ac8) {
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
    if ((uint)puVar12[9] < 8) {
      psVar17 = (short *)(puVar12 + 4);
    }
    else {
      psVar17 = (short *)puVar12[4];
    }
    psVar14 = psVar17;
    do {
      sVar2 = *psVar14;
      psVar14 = psVar14 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar17,(int)psVar14 - (int)(psVar17 + 1) >> 1);
  }
  else {
    uVar5 = *(undefined4 *)(*local_64 + 0x11c);
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_8._0_1_ = 2;
      FUN_0051c120();
      _atexit((_func_4879 *)&LAB_00bccc90);
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    iVar19 = FUN_0051d700(uVar5);
    if (iVar19 != 0) {
      FUN_004026e0(iVar19 + 0x98,0,0xffffffff);
    }
  }
  local_74 = uVar10 - 0xe8;
  local_70 = uVar11 - 0x5c;
  local_6c = (float)(uVar10 + 0xe8);
  local_68 = (float)(uVar11 + 0x50);
  puVar12 = local_34;
  if (local_20 < 8) {
    puVar12 = &local_34;
  }
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8._0_1_ = 4;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  FUN_00735c90(&local_74,puVar12,0xffffffff,0xff000000);
  if (7 < local_20) {
    FUN_0089120c(local_34);
  }
  local_20 = 7;
  local_24 = 0;
  local_34 = (undefined4 *)((uint)local_34 & 0xffff0000);
  if (local_60 != (uint *)0x0) {
    FUN_0089120c(local_60);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

