
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e5ee0(undefined4 param_1)

{
  char cVar1;
  wchar_t wVar2;
  short sVar3;
  int iVar4;
  code *pcVar5;
  bool bVar6;
  int iVar7;
  int *piVar8;
  wchar_t *pwVar9;
  wchar_t *pwVar10;
  wchar_t **ppwVar11;
  wchar_t *pwVar12;
  int in_ECX;
  short *psVar13;
  uint uVar14;
  int *piVar15;
  undefined2 auStack_618 [2];
  undefined4 uStack_614;
  wchar_t *local_5ec;
  uint uStack_5e8;
  int *piStack_5e4;
  int *piStack_5e0;
  wchar_t *local_5dc;
  uint uStack_5d8;
  uint uStack_5d4;
  int iStack_5d0;
  wchar_t *local_5cc;
  wchar_t *pwStack_5c8;
  undefined4 uStack_5c4;
  wchar_t *pwStack_5c0;
  undefined4 uStack_5bc;
  wchar_t *pwStack_5b8;
  wchar_t *local_5b4;
  undefined4 local_5b0;
  wchar_t *pwStack_5ac;
  wchar_t *pwStack_5a8;
  uint uStack_5a4;
  undefined **appuStack_5a0 [3];
  undefined **appuStack_594 [3];
  uint uStack_588;
  undefined4 uStack_578;
  uint uStack_574;
  undefined4 uStack_56c;
  undefined4 uStack_55c;
  uint uStack_558;
  uint uStack_550;
  undefined4 uStack_540;
  uint uStack_53c;
  uint uStack_520;
  int local_518 [60];
  short sStack_428;
  undefined1 auStack_426 [510];
  wchar_t awStack_228 [262];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009470f4;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_5ec;
  ExceptionList = &local_14;
  local_5b0 = param_1;
  if (in_ECX != 0) {
    if ((DAT_00fe1dcc & 1) == 0) {
      DAT_00fe1dcc = DAT_00fe1dcc | 1;
      local_c = 0;
      FUN_0051ed80();
      _atexit(FUN_00bcefc0);
    }
    local_c = 0xffffffff;
    local_5ec = *(wchar_t **)(in_ECX + 0x74);
    FUN_00834f20();
    pwVar9 = local_5dc;
    if ((local_5dc != DAT_00fe1dd4) && (local_5b4 = local_5dc + 8, local_5b4 != (wchar_t *)0x0)) {
      uStack_614 = 0x5e5fbe;
      _eh_vector_constructor_iterator_
                (local_518,0x10,0xf,(_func_void_void_ptr *)&LAB_00689330,FUN_00418290);
      local_c = 1;
      iVar7 = FUN_00404ba0();
      local_5cc = *(wchar_t **)(iVar7 + 0x6920);
      FUN_0040f060();
      iVar7 = (**(code **)(*DAT_00fba7a4 + 0x20))();
      uStack_5e8 = 0;
      if (iVar7 != 0) {
        uStack_5e8 = (uint)*(ushort *)(iVar7 + 0x88);
      }
      uStack_5d8 = 0;
      uVar14 = *(int *)(pwVar9 + 0x1a) - *(int *)(pwVar9 + 0x18) >> 2;
      if (uVar14 != 0) {
        do {
          iVar4 = *(int *)(local_5b4 + 0x10);
          iVar7 = uStack_5d8 * 4;
          if ((DAT_00f8d9a8 & 1) == 0) {
            DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
            local_c._0_1_ = 2;
            FUN_00523540();
            local_c._0_1_ = 3;
            FUN_00521080();
            _atexit((_func_4879 *)&LAB_00bccc50);
            local_c = CONCAT31(local_c._1_3_,1);
          }
          local_5ec = *(wchar_t **)(iVar4 + iVar7);
          FUN_008438c0();
          if (((local_5dc != DAT_00f8d9b0) &&
              (piVar15 = *(int **)(local_5dc + 8), piStack_5e4 = piVar15, piVar15 != (int *)0x0)) &&
             (*piVar15 != 0)) {
            switch(piVar15[2]) {
            case 1:
              break;
            case 2:
              break;
            case 3:
              break;
            case 4:
              break;
            case 0x11:
              break;
            case 0x12:
              break;
            case 0x13:
              break;
            case 0x1b:
              break;
            case 0x20:
              break;
            case 0x24:
              break;
            case 0x25:
              break;
            case 0x28:
              break;
            case 0x29:
              break;
            case 0x2a:
              break;
            case 0x2b:
            }
            iVar7 = FUN_00509650();
            if (iVar7 == 0) {
              pwStack_5c0 = (wchar_t *)*piVar15;
              uStack_5bc = 0;
            }
            else {
              piVar8 = (int *)FUN_00508be0();
              if (((piVar8 == (int *)0x0) || (piVar8[1] == 0)) || (*piVar8 != *piVar15)) {
                pwStack_5c8 = (wchar_t *)*piVar15;
                uStack_5c4 = 0;
              }
              else {
                iVar7 = FUN_005e06b0();
                uStack_5a4 = (uint)(iVar7 == 0);
                pwStack_5a8 = (wchar_t *)*piStack_5e4;
              }
            }
            FUN_0041e560();
          }
          uStack_5d8 = uStack_5d8 + 1;
        } while (uStack_5d8 < uVar14);
      }
      iStack_5d0 = 0;
      uStack_5d8 = 0;
      uStack_558 = 7;
      uStack_55c = 0;
      uStack_56c = (uint)uStack_56c._2_2_ << 0x10;
      local_c._0_1_ = 4;
      piStack_5e4 = (int *)0x0;
      piStack_5e0 = local_518;
      do {
        bVar6 = false;
        if (*piStack_5e0 != piStack_5e0[1]) {
          iStack_5d0 = iStack_5d0 + 1;
          uStack_5d4 = piStack_5e0[1] - *piStack_5e0 >> 3;
          uStack_574 = 7;
          uStack_578 = 0;
          uStack_588 = uStack_588 & 0xffff0000;
          local_c._0_1_ = 5;
          uStack_5e8 = 0;
          if (uStack_5d4 == 0) {
LAB_005e65b0:
            if ((DAT_00fe5ae4 & 1) == 0) {
              DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
              local_c._0_1_ = 0xb;
              FUN_00584c40();
              _atexit((_func_4879 *)&LAB_00bcf390);
              local_c._0_1_ = 5;
            }
            uStack_5d4 = 0x18c;
            FUN_005740f0();
            if (pwStack_5c0 == DAT_00fe5ac8) {
              pcVar5 = (code *)swi(3);
              (*pcVar5)();
              return;
            }
            if (*(uint *)(pwStack_5c0 + 0x12) < 8) {
              pwVar9 = pwStack_5c0 + 8;
            }
            else {
              pwVar9 = *(wchar_t **)(pwStack_5c0 + 8);
            }
            do {
              wVar2 = *pwVar9;
              pwVar9 = pwVar9 + 1;
            } while (wVar2 != L'\0');
          }
          else {
            while( true ) {
              iVar7 = uStack_5e8 * 8;
              if (*(int *)(iVar7 + 4 + *piStack_5e0) == 0) {
                FUN_00404300();
              }
              else {
                uStack_5d8 = uStack_5d8 + 1;
                if ((DAT_00fe5ae4 & 1) == 0) {
                  DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
                  local_c._0_1_ = 6;
                  FUN_00584c40();
                  _atexit((_func_4879 *)&LAB_00bcf390);
                  local_c._0_1_ = 5;
                }
                cVar1 = *(char *)((int)*(wchar_t **)(DAT_00fe5ac8 + 2) + 0x2d);
                pwVar9 = *(wchar_t **)(DAT_00fe5ac8 + 2);
                local_5ec = DAT_00fe5ac8;
                while (pwVar12 = pwVar9, cVar1 == '\0') {
                  if (*(int *)(pwVar12 + 6) < 0x1c4) {
                    pwVar9 = *(wchar_t **)(pwVar12 + 4);
                    pwVar12 = local_5ec;
                  }
                  else {
                    pwVar9 = *(wchar_t **)pwVar12;
                  }
                  cVar1 = *(char *)((int)pwVar9 + 0x2d);
                  local_5ec = pwVar12;
                }
                if ((local_5ec == DAT_00fe5ac8) || (0x1c4 < *(int *)(local_5ec + 6))) {
                  local_5dc = DAT_00fe5ac8;
                  ppwVar11 = &local_5dc;
                }
                else {
                  ppwVar11 = &local_5ec;
                }
                pwVar9 = *ppwVar11;
                if (pwVar9 == DAT_00fe5ac8) {
                  pcVar5 = (code *)swi(3);
                  (*pcVar5)();
                  return;
                }
                pwVar12 = pwVar9 + 8;
                if (7 < *(uint *)(pwVar9 + 0x12)) {
                  pwVar12 = *(wchar_t **)pwVar12;
                }
                do {
                  wVar2 = *pwVar12;
                  pwVar12 = pwVar12 + 1;
                } while (wVar2 != L'\0');
                FUN_00404300();
                bVar6 = true;
              }
              iVar4 = *piStack_5e0;
              if ((DAT_00f8d9a8 & 1) == 0) {
                DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
                local_c._0_1_ = 7;
                DAT_00f8d9b4 = 0;
                pwVar9 = (wchar_t *)FUN_00891268();
                if (pwVar9 == (wchar_t *)0x0) {
                  pwStack_5c8 = (wchar_t *)0x0;
                  std::exception::exception((exception *)appuStack_5a0,(char **)&pwStack_5c8);
                  appuStack_5a0[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
                  __CxxThrowException_8();
                }
                DAT_00f8d9b0 = pwVar9;
                *(wchar_t **)pwVar9 = pwVar9;
                *(wchar_t **)(DAT_00f8d9b0 + 2) = DAT_00f8d9b0;
                *(wchar_t **)(DAT_00f8d9b0 + 4) = DAT_00f8d9b0;
                *(undefined1 *)(DAT_00f8d9b0 + 10) = 1;
                *(undefined1 *)((int)DAT_00f8d9b0 + 0x15) = 1;
                local_c._0_1_ = 8;
                FUN_00521080();
                _atexit((_func_4879 *)&LAB_00bccc50);
                local_c._0_1_ = 5;
              }
              iVar7 = *(int *)(iVar4 + iVar7);
              cVar1 = *(char *)((int)*(wchar_t **)(DAT_00f8d9b0 + 2) + 0x15);
              pwVar9 = *(wchar_t **)(DAT_00f8d9b0 + 2);
              local_5ec = DAT_00f8d9b0;
              while (pwVar12 = pwVar9, cVar1 == '\0') {
                if (*(int *)(pwVar12 + 6) < iVar7) {
                  pwVar9 = *(wchar_t **)(pwVar12 + 4);
                  pwVar12 = local_5ec;
                }
                else {
                  pwVar9 = *(wchar_t **)pwVar12;
                }
                cVar1 = *(char *)((int)pwVar9 + 0x15);
                local_5ec = pwVar12;
              }
              if ((local_5ec == DAT_00f8d9b0) || (iVar7 < *(int *)(local_5ec + 6))) {
                local_5cc = DAT_00f8d9b0;
                ppwVar11 = &local_5cc;
              }
              else {
                ppwVar11 = &local_5ec;
              }
              if (*ppwVar11 == DAT_00f8d9b0) {
                iVar7 = 0;
              }
              else {
                iVar7 = *(int *)(*ppwVar11 + 8);
              }
              psVar13 = (short *)(iVar7 + 0x98);
              if (7 < *(uint *)(iVar7 + 0xac)) {
                psVar13 = *(short **)psVar13;
              }
              do {
                sVar3 = *psVar13;
                psVar13 = psVar13 + 1;
              } while (sVar3 != 0);
              FUN_00404300();
              uStack_5e8 = uStack_5e8 + 1;
              if (uStack_5d4 <= uStack_5e8) break;
              if ((DAT_00fe5ae4 & 1) == 0) {
                DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
                local_c._0_1_ = 9;
                FUN_00584c40();
                _atexit((_func_4879 *)&LAB_00bcf390);
                local_c._0_1_ = 5;
              }
              cVar1 = *(char *)((int)*(wchar_t **)(DAT_00fe5ac8 + 2) + 0x2d);
              pwVar9 = *(wchar_t **)(DAT_00fe5ac8 + 2);
              local_5ec = DAT_00fe5ac8;
              while (pwVar12 = pwVar9, cVar1 == '\0') {
                if (*(int *)(pwVar12 + 6) < 0x18a) {
                  pwVar9 = *(wchar_t **)(pwVar12 + 4);
                  pwVar12 = local_5ec;
                }
                else {
                  pwVar9 = *(wchar_t **)pwVar12;
                }
                cVar1 = *(char *)((int)pwVar9 + 0x2d);
                local_5ec = pwVar12;
              }
              if ((local_5ec == DAT_00fe5ac8) || (0x18a < *(int *)(local_5ec + 6))) {
                pwStack_5ac = DAT_00fe5ac8;
                ppwVar11 = &pwStack_5ac;
              }
              else {
                ppwVar11 = &local_5ec;
              }
              pwVar9 = *ppwVar11;
              if (pwVar9 == DAT_00fe5ac8) {
                pcVar5 = (code *)swi(3);
                (*pcVar5)();
                return;
              }
              if (*(uint *)(pwVar9 + 0x12) < 8) {
                pwVar9 = pwVar9 + 8;
              }
              else {
                pwVar9 = *(wchar_t **)(pwVar9 + 8);
              }
              do {
                wVar2 = *pwVar9;
                pwVar9 = pwVar9 + 1;
              } while (wVar2 != L'\0');
              FUN_00404300();
            }
            if (!bVar6) goto LAB_005e65b0;
            if ((DAT_00fe5ae4 & 1) == 0) {
              DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
              local_c._0_1_ = 10;
              FUN_00584c40();
              _atexit((_func_4879 *)&LAB_00bcf390);
              local_c._0_1_ = 5;
            }
            uStack_5d4 = 0x18b;
            FUN_005740f0();
            if (pwStack_5b8 == DAT_00fe5ac8) {
              pcVar5 = (code *)swi(3);
              (*pcVar5)();
              return;
            }
            if (*(uint *)(pwStack_5b8 + 0x12) < 8) {
              pwVar9 = pwStack_5b8 + 8;
            }
            else {
              pwVar9 = *(wchar_t **)(pwStack_5b8 + 8);
            }
            do {
              wVar2 = *pwVar9;
              pwVar9 = pwVar9 + 1;
            } while (wVar2 != L'\0');
          }
          FUN_00404300();
          FUN_004041f0();
          FUN_00404300();
          local_c._0_1_ = 4;
          if (7 < uStack_574) {
            FUN_0089120c();
          }
        }
        pwVar9 = local_5b4;
        piStack_5e4 = (int *)((int)piStack_5e4 + 1);
        piStack_5e0 = piStack_5e0 + 4;
      } while ((int)piStack_5e4 < 0xf);
      pwStack_5a8 = auStack_618;
      auStack_618[0] = 0;
      FUN_004026e0(local_5b4 + 2,0,0xffffffff);
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_c._0_1_ = 0xd;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
      }
      local_c._0_1_ = 0xc;
      pwStack_5c8 = (wchar_t *)0x1a1;
      FUN_005740f0(&pwStack_5c8);
      if (pwStack_5c0 == DAT_00fe5ac8) {
        pcVar5 = (code *)swi(3);
        (*pcVar5)();
        return;
      }
      pwVar12 = pwStack_5c0 + 8;
      if (7 < *(uint *)(pwStack_5c0 + 0x12)) {
        pwVar12 = *(wchar_t **)pwVar12;
      }
      local_c._0_1_ = 4;
      FUN_004606f0(pwVar12);
      local_c._0_1_ = 0xe;
      FUN_004041f0();
      local_c._0_1_ = 4;
      if (7 < uStack_53c) {
        FUN_0089120c();
      }
      FUN_004041f0();
      pwStack_5a8 = (wchar_t *)((*(int *)(pwVar9 + 0x1a) - *(int *)(pwVar9 + 0x18)) / 0x14);
      local_5ec = (wchar_t *)0x0;
      if (pwStack_5a8 != (wchar_t *)0x0) {
        iStack_5d0 = 0;
        do {
          piVar15 = (int *)(*(int *)(local_5b4 + 0x18) + iStack_5d0);
          piStack_5e0 = piVar15;
          if ((DAT_00fe5ae4 & 1) == 0) {
            DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
            local_c._0_1_ = 0xf;
            _DAT_00fe5acc = 0;
            pwVar9 = (wchar_t *)FUN_00891268();
            if (pwVar9 == (wchar_t *)0x0) {
              piStack_5e4 = (int *)0x0;
              std::exception::exception((exception *)appuStack_5a0,(char **)&piStack_5e4);
              appuStack_5a0[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
              __CxxThrowException_8();
            }
            DAT_00fe5ac8 = pwVar9;
            *(wchar_t **)pwVar9 = pwVar9;
            *(wchar_t **)(DAT_00fe5ac8 + 2) = DAT_00fe5ac8;
            *(wchar_t **)(DAT_00fe5ac8 + 4) = DAT_00fe5ac8;
            *(undefined1 *)(DAT_00fe5ac8 + 0x16) = 1;
            *(undefined1 *)((int)DAT_00fe5ac8 + 0x2d) = 1;
            local_c._0_1_ = 0x10;
            _DAT_00fe5adc = 0;
            iVar7 = FUN_00891268();
            if (iVar7 == 0) {
              local_5cc = (wchar_t *)0x0;
              std::exception::exception((exception *)appuStack_594,(char **)&local_5cc);
              appuStack_594[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
              __CxxThrowException_8();
            }
            DAT_00fe5ad8 = iVar7;
            *(int *)iVar7 = iVar7;
            *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
            *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
            *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
            *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
            _atexit((_func_4879 *)&LAB_00bcf390);
            local_c._0_1_ = 4;
          }
          cVar1 = *(char *)((int)*(wchar_t **)(DAT_00fe5ac8 + 2) + 0x2d);
          pwVar9 = *(wchar_t **)(DAT_00fe5ac8 + 2);
          pwStack_5c8 = DAT_00fe5ac8;
          while (pwVar12 = pwVar9, cVar1 == '\0') {
            if (*(int *)(pwVar12 + 6) < 0x18d) {
              pwVar9 = *(wchar_t **)(pwVar12 + 4);
              pwVar12 = pwStack_5c8;
            }
            else {
              pwVar9 = *(wchar_t **)pwVar12;
            }
            cVar1 = *(char *)((int)pwVar9 + 0x2d);
            pwStack_5c8 = pwVar12;
          }
          if ((pwStack_5c8 == DAT_00fe5ac8) || (0x18d < *(int *)(pwStack_5c8 + 6))) {
            pwStack_5c0 = DAT_00fe5ac8;
            ppwVar11 = &pwStack_5c0;
          }
          else {
            ppwVar11 = &pwStack_5c8;
          }
          if (*ppwVar11 == DAT_00fe5ac8) {
            pcVar5 = (code *)swi(3);
            (*pcVar5)();
            return;
          }
          FUN_004068f0();
          local_c._0_1_ = 0x11;
          FUN_004041f0();
          local_c._0_1_ = 4;
          if (7 < uStack_520) {
            FUN_0089120c();
          }
          if (*piVar15 <= (int)uStack_5d8) {
            if ((DAT_00fe5ae4 & 1) == 0) {
              DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
              local_c._0_1_ = 0x12;
              FUN_00584c40();
              _atexit((_func_4879 *)&LAB_00bcf390);
              local_c._0_1_ = 4;
            }
            cVar1 = *(char *)((int)*(wchar_t **)(DAT_00fe5ac8 + 2) + 0x2d);
            pwVar9 = *(wchar_t **)(DAT_00fe5ac8 + 2);
            pwStack_5c8 = DAT_00fe5ac8;
            while (pwVar12 = pwVar9, cVar1 == '\0') {
              if (*(int *)(pwVar12 + 6) < 0x1c4) {
                pwVar9 = *(wchar_t **)(pwVar12 + 4);
                pwVar12 = pwStack_5c8;
              }
              else {
                pwVar9 = *(wchar_t **)pwVar12;
              }
              cVar1 = *(char *)((int)pwVar9 + 0x2d);
              pwStack_5c8 = pwVar12;
            }
            if ((pwStack_5c8 == DAT_00fe5ac8) || (0x1c4 < *(int *)(pwStack_5c8 + 6))) {
              pwStack_5b8 = DAT_00fe5ac8;
              ppwVar11 = &pwStack_5b8;
            }
            else {
              ppwVar11 = &pwStack_5c8;
            }
            pwVar9 = *ppwVar11;
            if (pwVar9 == DAT_00fe5ac8) {
              pcVar5 = (code *)swi(3);
              (*pcVar5)();
              return;
            }
            pwVar12 = pwVar9 + 8;
            if (7 < *(uint *)(pwVar9 + 0x12)) {
              pwVar12 = *(wchar_t **)pwVar12;
            }
            do {
              wVar2 = *pwVar12;
              pwVar12 = pwVar12 + 1;
            } while (wVar2 != L'\0');
          }
          FUN_00404300();
          uStack_5d4 = piStack_5e0[2] - piStack_5e0[1] >> 3;
          uStack_5e8 = 0;
          if (uStack_5d4 != 0) {
            do {
              pwVar9 = *(wchar_t **)(DAT_00fc0e34 + 0xc);
              iVar7 = *(int *)(piStack_5e0[1] + uStack_5e8 * 8);
              cVar1 = *(char *)((int)*(wchar_t **)(pwVar9 + 2) + 0x2d);
              pwStack_5c8 = pwVar9;
              pwVar12 = *(wchar_t **)(pwVar9 + 2);
              while (cVar1 == '\0') {
                if (*(int *)(pwVar12 + 6) < iVar7) {
                  pwVar10 = *(wchar_t **)(pwVar12 + 4);
                  pwVar12 = pwStack_5c8;
                }
                else {
                  pwVar10 = *(wchar_t **)pwVar12;
                }
                pwStack_5c8 = pwVar12;
                pwVar12 = pwVar10;
                cVar1 = *(char *)((int)pwVar10 + 0x2d);
              }
              if ((pwStack_5c8 == pwVar9) || (iVar7 < *(int *)(pwStack_5c8 + 6))) {
                pwStack_5ac = pwVar9;
                ppwVar11 = &pwStack_5ac;
              }
              else {
                ppwVar11 = &pwStack_5c8;
              }
              pwVar12 = *ppwVar11;
              if (pwVar12 != pwVar9) {
                pwVar9 = pwVar12 + 8;
                if (7 < *(uint *)(pwVar12 + 0x12)) {
                  pwVar9 = *(wchar_t **)pwVar9;
                }
                if (pwVar9 != (wchar_t *)0x0) {
                  sStack_428 = 0;
                  _memset(auStack_426,0,0x1fe);
                  pwVar12 = _wcsstr(pwVar9,L"%");
                  _wcsstr(pwVar9,L"10x");
                  iVar7 = (int)awStack_228 - (int)pwVar9;
                  do {
                    wVar2 = *pwVar9;
                    *(wchar_t *)(iVar7 + (int)pwVar9) = wVar2;
                    pwVar9 = pwVar9 + 1;
                  } while (wVar2 != L'\0');
                  local_5dc = (wchar_t *)0x0;
                  _wcstok_s(awStack_228,L"(",&local_5dc);
                  if (local_5dc != (wchar_t *)0x0) {
                    *local_5dc = L'\0';
                  }
                  psVar13 = &DAT_00c02bac;
                  if (*(int *)(piStack_5e0[1] + 4 + uStack_5e8 * 8) < 0) {
                    psVar13 = &DAT_00bed1fc;
                  }
                  uStack_588 = uStack_588 & 0xffff0000;
                  uStack_574 = 7;
                  uStack_578 = 0;
                  do {
                    sVar3 = *psVar13;
                    psVar13 = psVar13 + 1;
                  } while (sVar3 != 0);
                  FUN_00402160();
                  local_c._0_1_ = 0x13;
                  FUN_0040ef80();
                  local_c._0_1_ = 0x14;
                  FUN_004041f0();
                  local_c._0_1_ = 0x13;
                  if (7 < uStack_53c) {
                    FUN_0089120c();
                  }
                  uStack_550 = uStack_550 & 0xffff0000;
                  uStack_53c = 7;
                  uStack_540 = 0;
                  psVar13 = &DAT_00c02ba8;
                  if (pwVar12 == (wchar_t *)0x0) {
                    psVar13 = &DAT_00bed1fc;
                  }
                  do {
                    sVar3 = *psVar13;
                    psVar13 = psVar13 + 1;
                  } while (sVar3 != 0);
                  FUN_00404300();
                  FUN_0040aeb0();
                  psVar13 = &sStack_428;
                  do {
                    sVar3 = *psVar13;
                    psVar13 = psVar13 + 1;
                  } while (sVar3 != 0);
                  FUN_00404300();
                  local_c._0_1_ = 4;
                  if (7 < uStack_574) {
                    FUN_0089120c();
                  }
                  uStack_574 = 7;
                  uStack_578 = 0;
                  uStack_588 = uStack_588 & 0xffff0000;
                }
              }
              uStack_5e8 = uStack_5e8 + 1;
            } while (uStack_5e8 < uStack_5d4);
          }
          iStack_5d0 = iStack_5d0 + 0x14;
          local_5ec = (wchar_t *)((int)local_5ec + 1);
        } while (local_5ec < pwStack_5a8);
      }
      if (7 < uStack_558) {
        FUN_0089120c();
      }
      uStack_558 = 7;
      uStack_55c = 0;
      uStack_56c = uStack_56c & 0xffff0000;
      local_c = 0xffffffff;
      _eh_vector_destructor_iterator_(local_518,0x10,0xf,FUN_00418290);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_5ec);
  return;
}

