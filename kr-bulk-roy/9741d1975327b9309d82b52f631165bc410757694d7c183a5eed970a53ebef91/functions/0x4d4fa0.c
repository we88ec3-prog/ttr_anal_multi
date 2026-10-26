
void FUN_004d4fa0(void)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  uint *puVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint **ppuVar8;
  uint *puVar9;
  uint *puVar10;
  short *psVar11;
  int *piVar12;
  uint *in_ECX;
  wchar_t *_Src;
  uint uVar13;
  bool bVar14;
  undefined4 uVar15;
  uint auStack_160 [2];
  undefined4 uStack_158;
  undefined1 auStack_134 [4];
  uint *local_130;
  uint local_12c;
  uint *local_128;
  uint *local_124;
  int *local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  uint local_110;
  int local_108;
  uint *local_104;
  uint *local_100;
  char *local_fc;
  uint *local_f8;
  uint *local_f4;
  undefined **local_f0 [3];
  int *local_e4;
  uint local_dc;
  uint local_c0 [4];
  undefined4 local_b0;
  uint local_ac;
  short local_88 [54];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00929d59;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_134;
  ExceptionList = &local_14;
  puVar4 = in_ECX + 0x3c;
  local_128 = (uint *)0x0;
  in_ECX[0x40] = 0;
  if (7 < in_ECX[0x41]) {
    puVar4 = (uint *)*puVar4;
  }
  *(undefined2 *)puVar4 = 0;
  local_120 = (int *)0x0;
  local_130 = in_ECX;
  piVar5 = (int *)FUN_00891268();
  puVar4 = local_130;
  if (piVar5 == (int *)0x0) {
    local_fc = (char *)0x0;
    std::exception::exception((exception *)local_f0,&local_fc);
    local_f0[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8();
  }
  piVar5[1] = 0;
  *piVar5 = 0;
  *piVar5 = (int)&local_120;
  local_11c = 0;
  local_118 = 0;
  local_114 = 0;
  local_110 = 0;
  local_c._0_1_ = 0;
  local_c._1_3_ = 0;
  local_124 = (uint *)0x0;
  if (*in_ECX == 1) {
    local_124 = (uint *)0x32;
  }
  else if (*in_ECX == 2) {
    local_124 = (uint *)0x7;
  }
  local_12c = 0;
  local_120 = piVar5;
  FUN_004d7e10();
  while( true ) {
    local_128 = (uint *)((uint)local_128 | 1);
    uVar13 = local_dc - 1;
    FUN_004d7e80();
    iVar6 = FUN_004d8bf0();
    if ((local_dc == *(uint *)(iVar6 + 8)) || ((int)local_124 <= (int)local_12c)) {
      bVar14 = false;
    }
    else {
      bVar14 = true;
    }
    if (((uint)local_128 & 1) != 0) {
      local_128 = (uint *)((uint)local_128 & 0xfffffffe);
    }
    if (!bVar14) break;
    if (((local_e4 == (int *)0x0) || ((int *)*local_e4 == (int *)0x0)) ||
       (piVar5 = *(int **)*local_e4, piVar5 == (int *)0x0)) {
      iVar6 = 0;
    }
    else {
      iVar6 = *piVar5;
    }
    uVar7 = uVar13 >> 1;
    if (*(uint *)(iVar6 + 8) <= uVar7) {
      uVar7 = uVar7 - *(uint *)(iVar6 + 8);
    }
    iVar6 = *(int *)(*(int *)(*(int *)(iVar6 + 4) + uVar7 * 4) + (uVar13 & 1) * 8);
    local_dc = uVar13;
    if ((((iVar6 == 0) || ((uVar13 = puVar4[0x47], (uVar13 & 1) != 0 && (iVar6 == 1)))) ||
        (((uVar13 & 2) != 0 && (iVar6 == 2)))) ||
       (((((uVar13 & 4) != 0 && (iVar6 == 3)) || (((uVar13 & 8) != 0 && (iVar6 == 4)))) ||
        (((((uVar13 & 0x10) != 0 && (iVar6 == 5)) || (iVar6 == 6)) ||
         (((uVar13 & 0x20) != 0 && (iVar6 == 7)))))))) {
      FUN_004f07f0();
      local_12c = local_12c + 1;
    }
  }
  local_12c = 0;
  if (local_110 != 0) {
    do {
      FUN_00542210();
      piVar5 = (int *)FUN_0050b4b0();
      if ((int *)*piVar5 == (int *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)*piVar5;
      }
      uVar13 = (uint)piVar5[2] >> 2;
      if (*(uint *)(iVar6 + 8) <= uVar13) {
        uVar13 = uVar13 - *(uint *)(iVar6 + 8);
      }
      piVar5 = *(int **)(*(int *)(*(int *)(iVar6 + 4) + uVar13 * 4) + (piVar5[2] & 3U) * 4);
      cVar1 = (char)piVar5[1];
      switch(cVar1) {
      case '\x01':
        bVar14 = (puVar4[0x47] & 0x10) == 0;
        break;
      case '\x02':
      case '\x03':
        bVar14 = (puVar4[0x47] & 2) == 0;
        break;
      case '\x04':
      case '\x05':
        bVar14 = (puVar4[0x47] & 1) == 0;
        break;
      case '\x06':
        bVar14 = (puVar4[0x47] & 8) == 0;
        break;
      case '\a':
        bVar14 = (puVar4[0x47] & 4) == 0;
        break;
      default:
        goto switchD_004d51dc_default;
      }
      if (!bVar14) {
switchD_004d51dc_default:
        if (cVar1 == '\0') {
          if ((DAT_00fe5b08 & 1) == 0) {
            DAT_00fe5b08 = DAT_00fe5b08 | 1;
            local_c._0_1_ = 1;
            FUN_00584c40();
            _atexit((_func_4879 *)&LAB_00bcf380);
            local_c._0_1_ = 0;
          }
          cVar1 = *(char *)((int)DAT_00fe5aec[1] + 0x2d);
          puVar10 = (uint *)DAT_00fe5aec[1];
          local_130 = DAT_00fe5aec;
          while (puVar9 = puVar10, cVar1 == '\0') {
            if ((int)puVar9[3] < 0x3d) {
              puVar10 = (uint *)puVar9[2];
              puVar9 = local_130;
            }
            else {
              puVar10 = (uint *)*puVar9;
            }
            cVar1 = *(char *)((int)puVar10 + 0x2d);
            local_130 = puVar9;
          }
          if ((local_130 == DAT_00fe5aec) || (0x3d < (int)local_130[3])) {
            local_124 = DAT_00fe5aec;
            ppuVar8 = &local_124;
          }
          else {
            ppuVar8 = &local_130;
          }
          puVar10 = *ppuVar8;
          if (puVar10 == DAT_00fe5aec) {
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          puVar9 = puVar10 + 4;
          if (7 < puVar10[9]) {
            puVar9 = (uint *)*puVar9;
          }
          do {
            uVar13 = *puVar9;
            puVar9 = (uint *)((int)puVar9 + 2);
          } while ((short)uVar13 != 0);
LAB_004d535b:
          FUN_00404300();
        }
        else {
          if (cVar1 == '\x01') {
            if ((DAT_00fe5b08 & 1) == 0) {
              DAT_00fe5b08 = DAT_00fe5b08 | 1;
              local_c._0_1_ = 2;
              FUN_00584c40();
              _atexit((_func_4879 *)&LAB_00bcf380);
              local_c._0_1_ = 0;
            }
            local_130 = (uint *)0x3e;
            FUN_005740f0();
            if (local_128 == DAT_00fe5aec) {
              pcVar3 = (code *)swi(3);
              (*pcVar3)();
              return;
            }
            puVar10 = local_128 + 4;
            if (7 < local_128[9]) {
              puVar10 = (uint *)*puVar10;
            }
            do {
              uVar13 = *puVar10;
              puVar10 = (uint *)((int)puVar10 + 2);
            } while ((short)uVar13 != 0);
            goto LAB_004d535b;
          }
          if (cVar1 == '\x06') {
            if ((DAT_00fe5b08 & 1) == 0) {
              DAT_00fe5b08 = DAT_00fe5b08 | 1;
              local_c._0_1_ = 3;
              FUN_00584c40();
              _atexit((_func_4879 *)&LAB_00bcf380);
              local_c._0_1_ = 0;
            }
            local_130 = (uint *)0x3f;
            FUN_005740f0();
            if (local_104 == DAT_00fe5aec) {
              pcVar3 = (code *)swi(3);
              (*pcVar3)();
              return;
            }
            FUN_004d78f0();
            FUN_004ed610();
            local_c._0_1_ = 4;
            FUN_004041f0();
            local_c._0_1_ = 0;
            if (7 < local_ac) {
              FUN_0089120c();
            }
          }
          else if (cVar1 == '\a') {
            if ((DAT_00fe5b08 & 1) == 0) {
              DAT_00fe5b08 = DAT_00fe5b08 | 1;
              local_c._0_1_ = 5;
              FUN_00584c40();
              _atexit((_func_4879 *)&LAB_00bcf380);
              local_c._0_1_ = 0;
            }
            local_130 = (uint *)0x40;
            FUN_005740f0();
            if (local_100 == DAT_00fe5aec) {
              pcVar3 = (code *)swi(3);
              (*pcVar3)();
              return;
            }
            FUN_004d78f0();
            FUN_004ed610();
            local_c._0_1_ = 6;
LAB_004d56f0:
            FUN_004041f0();
            local_c._0_1_ = 0;
            if (7 < local_ac) {
              FUN_0089120c();
            }
          }
          else if (cVar1 == '\x04') {
            if ((DAT_00fe5b08 & 1) == 0) {
              DAT_00fe5b08 = DAT_00fe5b08 | 1;
              local_c._0_1_ = 7;
              FUN_00584c40();
              _atexit((_func_4879 *)&LAB_00bcf380);
              local_c._0_1_ = 0;
            }
            local_130 = (uint *)0x41;
            FUN_005740f0();
            if (local_f4 == DAT_00fe5aec) {
              pcVar3 = (code *)swi(3);
              (*pcVar3)();
              return;
            }
            FUN_004d78f0();
            FUN_004ed610();
            local_c._0_1_ = 8;
            FUN_004041f0();
            local_c._0_1_ = 0;
            if (7 < local_ac) {
              FUN_0089120c();
            }
          }
          else if (cVar1 == '\x02') {
            if ((DAT_00fe5b08 & 1) == 0) {
              DAT_00fe5b08 = DAT_00fe5b08 | 1;
              local_c._0_1_ = 9;
              FUN_00584c40();
              _atexit((_func_4879 *)&LAB_00bcf380);
              local_c._0_1_ = 0;
            }
            local_130 = (uint *)&DAT_00000042;
            FUN_005740f0();
            if (local_f8 == DAT_00fe5aec) {
              pcVar3 = (code *)swi(3);
              (*pcVar3)();
              return;
            }
            FUN_004d78f0();
            FUN_004ed610();
            local_c._0_1_ = 10;
            FUN_004041f0();
            local_c._0_1_ = 0;
            if (7 < local_ac) {
              FUN_0089120c();
            }
          }
          else {
            if (cVar1 == '\x03') {
              local_130 = (uint *)0x43;
              iVar6 = FUN_005855b0();
              FUN_005740f0();
              if (local_108 == *(int *)(iVar6 + 4)) {
                pcVar3 = (code *)swi(3);
                (*pcVar3)();
                return;
              }
              FUN_004d78f0();
              FUN_004ed610();
              local_c._0_1_ = 0xb;
              goto LAB_004d56f0;
            }
            if (cVar1 == '\b') {
              local_130 = (uint *)FUN_004d78f0();
              FUN_005855b0();
              FUN_00585330();
              FUN_004ed610();
              local_c = CONCAT31(local_c._1_3_,0xc);
LAB_004d5761:
              FUN_004041f0();
            }
            else {
              if (cVar1 == '\t') {
                local_130 = (uint *)FUN_004d78f0();
                FUN_005855b0();
                FUN_00585330();
                FUN_004ed610();
                local_c = CONCAT31(local_c._1_3_,0xd);
                goto LAB_004d5761;
              }
              if (cVar1 == '\v') {
                local_130 = (uint *)FUN_004d78f0();
                FUN_005855b0();
                FUN_00585330();
                FUN_004ed610();
                local_c = CONCAT31(local_c._1_3_,0xe);
                goto LAB_004d5761;
              }
              if (cVar1 == '\n') {
                local_130 = (uint *)FUN_004d78f0();
                FUN_005855b0();
                FUN_00585330();
                FUN_004ed610();
                local_c = CONCAT31(local_c._1_3_,0xf);
                goto LAB_004d5761;
              }
              if (cVar1 == '\f') {
                local_130 = (uint *)FUN_004d78f0();
                FUN_005855b0();
                FUN_00585330();
                FUN_004ed610();
                local_c = CONCAT31(local_c._1_3_,0x10);
                goto LAB_004d5761;
              }
              if (cVar1 == -1) {
                local_ac = 7;
                local_b0 = 0;
                local_c0[0] = local_c0[0] & 0xffff0000;
                local_c = CONCAT31(local_c._1_3_,0x11);
                if (*piVar5 == 0) {
                  _Src = (wchar_t *)(piVar5 + 2);
                  psVar11 = (short *)FUN_004023e0();
                  if (*psVar11 == 0x23) {
                    if (7 < (uint)piVar5[7]) {
                      _Src = *(wchar_t **)_Src;
                    }
                    uStack_158 = 0x4d58dd;
                    FID_conflict__swscanf(_Src,L"#%s");
                    goto LAB_004d58ef;
                  }
                }
                else {
                  FUN_004d78f0();
LAB_004d58ef:
                  FUN_0041f490();
                }
                local_130 = auStack_160;
                FUN_00402110(local_c0);
                uVar15 = 0x48;
                local_c._0_1_ = 0x12;
                FUN_005855b0(0x48);
                uVar15 = FUN_00585330(uVar15);
                local_c._0_1_ = 0x11;
                FUN_00424c80(uVar15);
                local_c._0_1_ = 0x13;
                FUN_004041f0();
                FUN_004fa440();
                local_c._0_1_ = 0;
                FUN_004fa440();
                goto LAB_004d5a4b;
              }
              local_130 = (uint *)FUN_004d78f0();
              FUN_005855b0();
              FUN_00585330();
              FUN_004ed610();
              local_c = CONCAT31(local_c._1_3_,0x14);
              FUN_004041f0();
            }
            local_c._0_1_ = 0;
            FUN_004fa440();
          }
        }
        if (puVar4[0x49] != 0) {
          FUN_004d8300();
          psVar11 = local_88;
          do {
            sVar2 = *psVar11;
            psVar11 = psVar11 + 1;
          } while (sVar2 != 0);
          FUN_00404300();
        }
        piVar12 = piVar5 + 2;
        if (7 < (uint)piVar5[7]) {
          piVar12 = (int *)*piVar12;
        }
        do {
          iVar6 = *piVar12;
          piVar12 = (int *)((int)piVar12 + 2);
        } while ((short)iVar6 != 0);
        FUN_00404300();
        FUN_00404300();
      }
LAB_004d5a4b:
      local_12c = local_12c + 1;
    } while (local_12c < local_110);
  }
  FUN_007b6d70();
  FUN_0089120c();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_134);
  return;
}

