
/* WARNING: Type propagation algorithm not settling */

void FUN_00697710(uint param_1)

{
  wchar_t wVar1;
  short sVar2;
  int *piVar3;
  undefined4 *puVar4;
  code *pcVar5;
  wchar_t *pwVar6;
  wchar_t *_Str;
  undefined4 uVar7;
  short *psVar8;
  undefined4 *******pppppppuVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  int in_ECX;
  short *psVar13;
  uint uVar14;
  uint uVar15;
  int *piVar16;
  wchar_t *local_4ac;
  uint local_4a8;
  uint local_4a4;
  int local_4a0;
  int local_49c;
  uint local_498;
  uint local_494;
  int local_490;
  int local_48c;
  uint local_488;
  int local_484;
  uint local_480;
  char local_47a;
  char local_479;
  uint local_478;
  undefined4 local_474;
  uint local_460;
  uint local_458 [4];
  undefined4 local_448;
  uint local_444;
  undefined4 *******local_43c [4];
  undefined4 local_42c;
  uint local_428;
  wchar_t local_420 [260];
  short local_218;
  undefined1 local_216 [510];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092c69b;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_498 = param_1;
  local_484 = in_ECX;
  if ((DAT_00fb1350 & 1) == 0) {
    DAT_00fb1350 = DAT_00fb1350 | 1;
    local_8 = 0;
    FUN_00511ca0(local_18);
    _atexit((_func_4879 *)&LAB_00bccf40);
  }
  local_8 = 0xffffffff;
  local_494 = param_1;
  FUN_008438c0(&local_494);
  if (local_4a0 == DAT_00fb136c) {
    iVar12 = 0;
  }
  else {
    iVar12 = *(int *)(local_4a0 + 0x10);
  }
  local_4a0 = iVar12;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 1;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_8 = 0xffffffff;
  }
  local_494 = param_1;
  FUN_008438c0(&local_494);
  if (local_490 == DAT_00f8d91c) {
    uVar14 = 0;
  }
  else {
    uVar14 = *(uint *)(local_490 + 0x10);
  }
  local_494 = uVar14;
  if ((iVar12 == 0) || (uVar14 == 0)) goto LAB_0069871c;
  *(int *)(in_ECX + 0x25c) = iVar12;
  FUN_00757710();
  (**(code **)(**(int **)(in_ECX + 0x248) + 0x19c))(*(undefined4 *)(uVar14 + 0x20),local_498,0,0);
  iVar12 = *(int *)(in_ECX + 0x248);
  *(undefined1 *)(iVar12 + 0x269) = 1;
  *(undefined4 *)(iVar12 + 0x26c) = 0;
  *(undefined4 *)(iVar12 + 0x270) = 0;
  *(undefined4 *)(iVar12 + 0x274) = 0;
  iVar12 = *(int *)(*(int *)(in_ECX + 0x24c) + 0x24c);
  if ((iVar12 != 0) && (iVar12 = *(int *)(iVar12 + 0xcc), iVar12 != 0)) {
    FUN_006438f0(iVar12);
  }
  FUN_00757710();
  iVar12 = (*(int *)(*(int *)(in_ECX + 0x25c) + 0x68) - *(int *)(*(int *)(in_ECX + 0x25c) + 100)) /
           0x18;
  if (iVar12 != 0) {
    local_48c = 0;
    local_490 = iVar12;
    do {
      local_444 = 7;
      local_448 = 0;
      local_458[0] = local_458[0] & 0xffff0000;
      local_8 = 2;
      local_4a4 = *(int *)(*(int *)(local_484 + 0x25c) + 100) + local_48c;
      local_498 = 0;
      uVar14 = *(int *)(local_4a4 + 0xc) - *(int *)(local_4a4 + 8) >> 3;
      local_480 = uVar14;
      if (uVar14 != 0) {
        do {
          uVar15 = local_498;
          iVar12 = DAT_00fc0e34;
          local_488 = *(uint *)(*(int *)(local_4a4 + 8) + local_498 * 8);
          local_49c = *(int *)(local_4a4 + 8) + local_498 * 8;
          FUN_005740f0(&local_488);
          if (local_4a8 != *(uint *)(iVar12 + 0xc)) {
            _Str = (wchar_t *)(local_4a8 + 0x10);
            if (7 < *(uint *)(local_4a8 + 0x24)) {
              _Str = *(wchar_t **)_Str;
            }
            if (_Str != (wchar_t *)0x0) {
              local_218 = 0;
              _memset(local_216,0,0x1fe);
              pwVar6 = _wcsstr(_Str,L"%");
              _wcsstr(_Str,L"10x");
              iVar12 = (int)local_420 - (int)_Str;
              do {
                wVar1 = *_Str;
                *(wchar_t *)(iVar12 + (int)_Str) = wVar1;
                _Str = _Str + 1;
              } while (wVar1 != L'\0');
              local_4ac = (wchar_t *)0x0;
              _wcstok_s(local_420,L"(",&local_4ac);
              if (local_4ac != (wchar_t *)0x0) {
                *local_4ac = L'\0';
              }
              psVar13 = &DAT_00c02bac;
              if (*(int *)(local_49c + 4) < 0) {
                psVar13 = &DAT_00bed1fc;
              }
              local_428 = 7;
              local_42c = 0;
              local_43c[0] = (undefined4 *******)((uint)local_43c[0] & 0xffff0000);
              psVar8 = psVar13;
              do {
                sVar2 = *psVar8;
                psVar8 = psVar8 + 1;
              } while (sVar2 != 0);
              FUN_00402160(psVar13,(int)psVar8 - (int)(psVar13 + 1) >> 1);
              local_8._0_1_ = 3;
              uVar7 = FUN_0040ef80();
              local_8._0_1_ = 4;
              FUN_004041f0(uVar7,0,0xffffffff);
              local_8._0_1_ = 3;
              if (7 < local_460) {
                FUN_0089120c(local_474);
              }
              psVar13 = &DAT_00c02ba8;
              if (pwVar6 == (wchar_t *)0x0) {
                psVar13 = &DAT_00bed1fc;
              }
              psVar8 = psVar13;
              do {
                sVar2 = *psVar8;
                psVar8 = psVar8 + 1;
              } while (sVar2 != 0);
              FUN_00404300(psVar13,(int)psVar8 - (int)(psVar13 + 1) >> 1);
              pppppppuVar9 = local_43c[0];
              if (local_428 < 8) {
                pppppppuVar9 = local_43c;
              }
              FUN_0040aeb0(L"%s : %s",local_420,pppppppuVar9);
              psVar13 = &local_218;
              do {
                sVar2 = *psVar13;
                psVar13 = psVar13 + 1;
              } while (sVar2 != 0);
              FUN_00404300(&local_218,(int)psVar13 - (int)local_216 >> 1);
              local_8 = CONCAT31(local_8._1_3_,2);
              if (7 < local_428) {
                FUN_0089120c(local_43c[0]);
              }
              local_428 = 7;
              local_42c = 0;
              local_43c[0] = (undefined4 *******)((uint)local_43c[0] & 0xffff0000);
              uVar14 = local_480;
              uVar15 = local_498;
            }
          }
          uVar15 = uVar15 + 1;
          if (uVar15 < uVar14) {
            if ((DAT_00fe5ae4 & 1) == 0) {
              DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
              local_8._0_1_ = 5;
              FUN_00584c40(&DAT_00fe5ac4);
              _atexit((_func_4879 *)&LAB_00bcf390);
              local_8 = CONCAT31(local_8._1_3_,2);
            }
            local_488 = 1;
            FUN_005740f0(&local_488);
            if (local_478 == DAT_00fe5ac8) {
              pcVar5 = (code *)swi(3);
              (*pcVar5)();
              return;
            }
            psVar13 = (short *)(local_478 + 0x10);
            if (7 < *(uint *)(local_478 + 0x24)) {
              psVar13 = *(short **)psVar13;
            }
            psVar8 = psVar13;
            do {
              sVar2 = *psVar8;
              psVar8 = psVar8 + 1;
            } while (sVar2 != 0);
            FUN_00404300(psVar13,(int)psVar8 - (int)(psVar13 + 1) >> 1);
          }
          local_498 = uVar15;
        } while (uVar15 < uVar14);
      }
      local_488 = *(uint *)(local_484 + 0x24c);
      if (*(int *)(local_488 + 0x24c) != 0) {
        piVar16 = *(int **)(*(int *)(local_488 + 0x24c) + 0xcc);
        if (piVar16 == (int *)0x0) {
LAB_00697d20:
          iVar12 = -1;
        }
        else {
          piVar3 = (int *)piVar16[0x29];
          iVar12 = piVar16[0x39];
          if (piVar3 == (int *)0x0) goto LAB_00697d20;
          if (piVar16[0x2e] == piVar16[0x2f]) {
            uVar14 = (**(code **)(*piVar3 + 0x28))();
          }
          else {
            uVar14 = *(uint *)(piVar16[0x2f] + -4);
            (**(code **)(*piVar3 + 0x2c))(uVar14);
            if (piVar16[0x2e] != piVar16[0x2f]) {
              piVar16[0x2f] = piVar16[0x2f] + -4;
            }
          }
          *(int *)(uVar14 + 0x20) = iVar12;
          local_480 = uVar14;
          (**(code **)(*piVar16 + 0x70))(uVar14);
          FUN_00443d10();
          uVar14 = iVar12 + 1U;
          if (iVar12 + 1U <= (uint)piVar16[0x39]) {
            uVar14 = piVar16[0x39];
          }
          piVar16[0x39] = uVar14;
        }
        iVar11 = *(int *)(*(int *)(local_488 + 0x24c) + 0xcc);
        if (iVar11 != 0) {
          for (piVar16 = *(int **)(iVar11 + 0xa8);
              (piVar16 != *(int **)(iVar11 + 0xac) && (*(int *)(*piVar16 + 0x20) != iVar12));
              piVar16 = piVar16 + 1) {
          }
        }
        FUN_00757800(local_458);
      }
      local_8 = 0xffffffff;
      if (7 < local_444) {
        FUN_0089120c(local_458[0]);
      }
      local_48c = local_48c + 0x18;
      local_490 = local_490 + -1;
    } while (local_490 != 0);
  }
  iVar12 = *(int *)(*(int *)(local_484 + 0x24c) + 0x24c);
  if (iVar12 != 0) {
    FUN_00749920(iVar12);
  }
  iVar12 = local_484;
  FUN_00749920(*(undefined4 *)(local_484 + 0x24c));
  piVar16 = *(int **)(iVar12 + 0x24c);
  if (((piVar16[0x93] == 0) || (iVar11 = *(int *)(piVar16[0x93] + 0xcc), iVar11 == 0)) ||
     (*(int *)(iVar11 + 0xac) - *(int *)(iVar11 + 0xa8) >> 2 == 0)) {
    (**(code **)(*piVar16 + 0x90))(0);
  }
  else {
    if (piVar16[0x93] != 0) {
      iVar11 = *(int *)(piVar16[0x93] + 0xcc);
      if (iVar11 == 0) {
        iVar11 = 0;
      }
      else {
        iVar11 = *(int *)(iVar11 + 0xdc);
      }
      if ((iVar11 != 0) && (*(int *)(iVar11 + 0x20) != -1)) goto LAB_00697e0b;
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 6;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_478 = 0x30a;
    FUN_005740f0(&local_478);
    if (local_480 == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    FUN_00757710();
  }
LAB_00697e0b:
  iVar11 = *(int *)(*(int *)(iVar12 + 0x250) + 0x24c);
  if ((iVar11 != 0) && (iVar11 = *(int *)(iVar11 + 0xcc), iVar11 != 0)) {
    FUN_006438f0(iVar11);
  }
  FUN_00757710();
  iVar12 = (*(int *)(*(int *)(iVar12 + 0x25c) + 0x58) - *(int *)(*(int *)(iVar12 + 0x25c) + 0x54)) /
           0xc;
  local_47a = '\0';
  local_479 = '\0';
  if (iVar12 != 0) {
    local_48c = 0;
    local_490 = iVar12;
    do {
      piVar16 = (int *)(*(int *)(local_4a0 + 0x54) + local_48c);
      local_428 = 7;
      local_42c = 0;
      local_43c[0] = (undefined4 *******)((uint)local_43c[0] & 0xffff0000);
      local_8._0_1_ = 7;
      local_8._1_3_ = 0;
      iVar12 = piVar16[1];
      if (iVar12 == 0) {
LAB_00698061:
        if (*piVar16 < 2) {
          switch(*(undefined4 *)(*(int *)(local_494 + 0x54) + 8)) {
          case 1:
          case 2:
          case 3:
          case 4:
          case 0x11:
          case 0x12:
          case 0x13:
          case 0x1b:
          case 0x20:
          case 0x24:
          case 0x25:
          case 0x28:
          case 0x29:
          case 0x2a:
          case 0x2b:
            if ((DAT_00fe5b2c & 1) == 0) {
              DAT_00fe5b2c = DAT_00fe5b2c | 1;
              local_8._0_1_ = 10;
              local_8._1_3_ = 0;
              FUN_00584c40(&DAT_00fe5b0c);
              _atexit(FUN_00bcf370);
            }
            local_8._0_1_ = 7;
            local_478 = 0x101;
            FUN_005740f0(&local_478);
            if (local_4a8 == DAT_00fe5b10) {
              pcVar5 = (code *)swi(3);
              (*pcVar5)();
              return;
            }
            uVar7 = FUN_004068f0();
            local_8._0_1_ = 0xb;
            FUN_00402800(uVar7);
            local_8._0_1_ = 7;
            if (7 < local_444) {
              FUN_0089120c(local_458[0]);
              local_47a = '\x01';
              goto LAB_0069837b;
            }
            break;
          default:
            if ((DAT_00fe5b2c & 1) == 0) {
              DAT_00fe5b2c = DAT_00fe5b2c | 1;
              local_8._0_1_ = 0xc;
              local_8._1_3_ = 0;
              FUN_00584c40(&DAT_00fe5b0c);
              _atexit(FUN_00bcf370);
            }
            local_8._0_1_ = 7;
            local_478 = 0x104;
            FUN_005740f0(&local_478);
            if (local_488 == DAT_00fe5b10) {
              pcVar5 = (code *)swi(3);
              (*pcVar5)();
              return;
            }
            puVar10 = (undefined4 *)(local_488 + 0x10);
            if (7 < *(uint *)(local_488 + 0x24)) {
              puVar10 = (undefined4 *)*puVar10;
            }
            uVar7 = FUN_0040e460(puVar10);
            local_8._0_1_ = 0xd;
            FUN_00402800(uVar7);
            goto joined_r0x006981e1;
          }
LAB_006982b4:
          local_47a = '\x01';
        }
        else {
          if (iVar12 != 0) goto LAB_006981fb;
          if (1 < *piVar16) goto LAB_006982c9;
        }
      }
      else {
        if (*piVar16 < 2) {
          if (iVar12 == 0) goto LAB_00698061;
LAB_006981fb:
          if (*piVar16 < 2) {
            if ((DAT_00fe5b2c & 1) == 0) {
              DAT_00fe5b2c = DAT_00fe5b2c | 1;
              local_8._0_1_ = 0xe;
              local_8._1_3_ = 0;
              FUN_00584c40(&DAT_00fe5b0c);
              _atexit(FUN_00bcf370);
            }
            local_8._0_1_ = 7;
            local_478 = 0x102;
            FUN_005740f0(&local_478);
            if (local_4a4 == DAT_00fe5b10) {
              pcVar5 = (code *)swi(3);
              (*pcVar5)();
              return;
            }
            puVar10 = (undefined4 *)(local_4a4 + 0x10);
            if (7 < *(uint *)(local_4a4 + 0x24)) {
              puVar10 = (undefined4 *)*puVar10;
            }
            uVar7 = FUN_0040e460(puVar10);
            local_8._0_1_ = 0xf;
            FUN_00402800(uVar7);
            local_8._0_1_ = 7;
            if (7 < local_444) {
              FUN_0089120c(local_458[0]);
            }
            goto LAB_006982b4;
          }
LAB_006982c9:
          if ((DAT_00fe5b2c & 1) == 0) {
            DAT_00fe5b2c = DAT_00fe5b2c | 1;
            local_8 = 0x10;
            FUN_00584c40(&DAT_00fe5b0c);
            _atexit(FUN_00bcf370);
          }
          local_8._0_1_ = 7;
          local_478 = 0x104;
          FUN_005740f0(&local_478);
          if (local_498 == DAT_00fe5b10) {
            pcVar5 = (code *)swi(3);
            (*pcVar5)();
            return;
          }
          puVar10 = (undefined4 *)(local_498 + 0x10);
          if (7 < *(uint *)(local_498 + 0x24)) {
            puVar10 = (undefined4 *)*puVar10;
          }
          uVar7 = FUN_0040e460(puVar10);
          local_8._0_1_ = 0x11;
          FUN_00402800(uVar7);
joined_r0x006981e1:
          local_8._0_1_ = 7;
          if (7 < local_444) {
            local_8._0_1_ = 7;
            FUN_0089120c(local_458[0]);
          }
        }
        else {
          if ((DAT_00fe5b2c & 1) == 0) {
            DAT_00fe5b2c = DAT_00fe5b2c | 1;
            local_8._0_1_ = 8;
            local_8._1_3_ = 0;
            FUN_00584c40(&DAT_00fe5b0c);
            _atexit(FUN_00bcf370);
          }
          local_8._0_1_ = 7;
          local_478 = 0x103;
          FUN_005740f0(&local_478);
          if (local_480 == DAT_00fe5b10) {
            pcVar5 = (code *)swi(3);
            (*pcVar5)();
            return;
          }
          puVar10 = (undefined4 *)(local_480 + 0x10);
          if (7 < *(uint *)(local_480 + 0x24)) {
            puVar10 = (undefined4 *)*puVar10;
          }
          uVar7 = FUN_00421540(puVar10,piVar16[1]);
          local_8._0_1_ = 9;
          FUN_00402800(uVar7);
          local_8._0_1_ = 7;
          if (7 < local_444) {
            FUN_0089120c(local_458[0]);
          }
          local_47a = '\x01';
        }
        local_479 = '\x01';
      }
LAB_0069837b:
      local_49c = *(int *)(local_484 + 0x250);
      if (*(int *)(local_49c + 0x24c) != 0) {
        piVar16 = *(int **)(*(int *)(local_49c + 0x24c) + 0xcc);
        if (piVar16 == (int *)0x0) {
LAB_00698437:
          iVar12 = -1;
        }
        else {
          iVar12 = piVar16[0x39];
          if ((int *)piVar16[0x29] == (int *)0x0) goto LAB_00698437;
          iVar11 = *(int *)piVar16[0x29];
          if (piVar16[0x2e] == piVar16[0x2f]) {
            uVar14 = (**(code **)(iVar11 + 0x28))();
          }
          else {
            uVar14 = *(uint *)(piVar16[0x2f] + -4);
            (**(code **)(iVar11 + 0x2c))(uVar14);
            if (piVar16[0x2e] != piVar16[0x2f]) {
              piVar16[0x2f] = piVar16[0x2f] + -4;
            }
          }
          *(int *)(uVar14 + 0x20) = iVar12;
          local_478 = uVar14;
          (**(code **)(*piVar16 + 0x70))(uVar14);
          FUN_00443d10();
          uVar14 = iVar12 + 1U;
          if (iVar12 + 1U <= (uint)piVar16[0x39]) {
            uVar14 = piVar16[0x39];
          }
          piVar16[0x39] = uVar14;
        }
        iVar11 = *(int *)(*(int *)(local_49c + 0x24c) + 0xcc);
        if (iVar11 != 0) {
          for (piVar16 = *(int **)(iVar11 + 0xa8);
              (piVar16 != *(int **)(iVar11 + 0xac) && (*(int *)(*piVar16 + 0x20) != iVar12));
              piVar16 = piVar16 + 1) {
          }
        }
        FUN_00757800(local_43c);
      }
      local_8 = 0xffffffff;
      if (7 < local_428) {
        FUN_0089120c(local_43c[0]);
      }
      local_48c = local_48c + 0xc;
      local_490 = local_490 + -1;
    } while (local_490 != 0);
  }
  iVar12 = *(int *)(*(int *)(local_484 + 0x250) + 0x24c);
  if (iVar12 == 0) {
LAB_006984fd:
    if (local_47a == '\0') {
      if (local_479 == '\0') {
        if ((DAT_00fe5ae4 & 1) == 0) {
          DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
          local_8 = 0x14;
          FUN_00584c40(&DAT_00fe5ac4);
          _atexit((_func_4879 *)&LAB_00bcf390);
          local_8 = 0xffffffff;
        }
        local_478 = 0x30b;
        FUN_005740f0(&local_478);
        if (local_480 == DAT_00fe5ac8) {
          pcVar5 = (code *)swi(3);
          (*pcVar5)();
          return;
        }
      }
      else {
        if ((DAT_00fe5ae4 & 1) == 0) {
          DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
          local_8 = 0x13;
          FUN_00584c40(&DAT_00fe5ac4);
          _atexit((_func_4879 *)&LAB_00bcf390);
          local_8 = 0xffffffff;
        }
        local_478 = 0x30d;
        FUN_005740f0(&local_478);
        if (local_480 == DAT_00fe5ac8) {
          pcVar5 = (code *)swi(3);
          (*pcVar5)();
          return;
        }
      }
    }
    else {
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_8 = 0x12;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_8 = 0xffffffff;
      }
      local_478 = 0x30c;
      FUN_005740f0(&local_478);
      if (local_480 == DAT_00fe5ac8) {
        pcVar5 = (code *)swi(3);
        (*pcVar5)();
        return;
      }
    }
    FUN_00757710();
  }
  else {
    iVar12 = *(int *)(iVar12 + 0xcc);
    if (iVar12 == 0) {
      iVar12 = 0;
    }
    else {
      iVar12 = *(int *)(iVar12 + 0xdc);
    }
    if ((iVar12 == 0) || (*(int *)(iVar12 + 0x20) == -1)) goto LAB_006984fd;
  }
  iVar12 = *(int *)(*(int *)(local_484 + 0x250) + 0x24c);
  if (iVar12 != 0) {
    FUN_00749920(iVar12);
  }
  piVar16 = *(int **)(local_484 + 0x250);
  puVar10 = (undefined4 *)piVar16[0x19];
  for (puVar4 = (undefined4 *)*puVar10; puVar4 != puVar10; puVar4 = (undefined4 *)*puVar4) {
    iVar12 = puVar4[2];
    if ((*(int *)(iVar12 + 0x60) != 0) && ((*(int **)(iVar12 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar12 + 0x1c) + 0x30))(iVar12);
    }
  }
  (**(code **)(*piVar16 + 0x128))();
LAB_0069871c:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

