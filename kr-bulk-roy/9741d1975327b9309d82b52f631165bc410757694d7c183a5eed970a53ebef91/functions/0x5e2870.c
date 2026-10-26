
void FUN_005e2870(void)

{
  short sVar1;
  wchar_t wVar2;
  code *pcVar3;
  bool bVar4;
  short *psVar5;
  wchar_t *pwVar6;
  wchar_t *_Str;
  undefined4 *****pppppuVar7;
  int iVar8;
  int iVar9;
  int in_ECX;
  short *psVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  undefined1 auStack_6fc [4];
  int local_6f8;
  uint local_6f4;
  uint local_6f0;
  int local_6ec;
  uint local_6e8;
  int local_6e4;
  uint local_6e0;
  int local_6d8;
  int local_6d4;
  wchar_t *local_6d0;
  undefined4 local_6cc;
  undefined4 local_6c8;
  int local_6c4;
  uint local_6c0;
  tm tStack_6bc;
  uint auStack_698 [4];
  undefined4 uStack_688;
  uint uStack_684;
  undefined4 ****local_67c [4];
  undefined4 local_66c;
  uint local_668;
  undefined4 local_660;
  uint local_64c;
  undefined4 uStack_644;
  uint uStack_630;
  short local_628;
  undefined1 local_626 [510];
  short sStack_428;
  undefined1 auStack_426 [510];
  wchar_t local_228 [262];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093f130;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_6fc;
  ExceptionList = &local_14;
  local_6d4 = in_ECX;
  if ((DAT_00fb1350 & 1) == 0) {
    DAT_00fb1350 = DAT_00fb1350 | 1;
    local_c = 0;
    FUN_00511ca0(DAT_00d61f20 ^ (uint)&stack0xfffff8f8);
    _atexit((_func_4879 *)&LAB_00bccf40);
  }
  local_c = 0xffffffff;
  local_6e8 = *(uint *)(in_ECX + 0x164);
  FUN_008438c0(&local_6e8);
  if ((local_6ec != DAT_00fb136c) && (local_6f8 = *(int *)(local_6ec + 0x10), local_6f8 != 0)) {
    if ((*(char *)(in_ECX + 0x178) == '\0') &&
       (*(int *)(local_6f8 + 100) != *(int *)(local_6f8 + 0x68))) {
      uVar14 = 400;
      FUN_00585620(400);
      psVar5 = (short *)FUN_00585330(uVar14);
      psVar10 = psVar5;
      do {
        sVar1 = *psVar10;
        psVar10 = psVar10 + 1;
      } while (sVar1 != 0);
      FUN_00404300(psVar5,(int)psVar10 - (int)(psVar5 + 1) >> 1);
      local_6f4 = (*(int *)(local_6f8 + 0x68) - *(int *)(local_6f8 + 100)) / 0x18;
      local_6e0 = 0;
      if (local_6f4 != 0) {
        local_6c8 = 2;
        local_6e4 = 0;
        do {
          local_6c4 = *(int *)(local_6f8 + 100) + local_6e4;
          uVar12 = *(int *)(local_6c4 + 0xc) - *(int *)(local_6c4 + 8) >> 3;
          local_6f0 = uVar12;
          FUN_00440010(1,local_6e0 + 0x31);
          if ((DAT_00fe5ae4 & 1) == 0) {
            DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
            local_c = 1;
            FUN_00584c40(&DAT_00fe5ac4);
            _atexit((_func_4879 *)&LAB_00bcf390);
            local_c = 0xffffffff;
          }
          FUN_005740f0(&local_6c8);
          if (local_6c0 == DAT_00fe5ac8) {
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          psVar10 = (short *)(local_6c0 + 0x10);
          if (7 < *(uint *)(local_6c0 + 0x24)) {
            psVar10 = *(short **)psVar10;
          }
          psVar5 = psVar10;
          do {
            sVar1 = *psVar5;
            psVar5 = psVar5 + 1;
          } while (sVar1 != 0);
          FUN_00404300(psVar10,(int)psVar5 - (int)(psVar10 + 1) >> 1);
          local_6e8 = 0;
          uVar13 = local_6e8;
          if (uVar12 != 0) {
            do {
              uVar13 = local_6e8;
              iVar9 = DAT_00fc0e34;
              local_6cc = *(undefined4 *)(*(int *)(local_6c4 + 8) + local_6e8 * 8);
              local_6ec = *(int *)(local_6c4 + 8) + local_6e8 * 8;
              FUN_005740f0(&local_6cc);
              if (local_6d8 != *(int *)(iVar9 + 0xc)) {
                _Str = (wchar_t *)(local_6d8 + 0x10);
                if (7 < *(uint *)(local_6d8 + 0x24)) {
                  _Str = *(wchar_t **)_Str;
                }
                if (_Str != (wchar_t *)0x0) {
                  local_628 = 0;
                  _memset(local_626,0,0x1fe);
                  pwVar6 = _wcsstr(_Str,L"%");
                  _wcsstr(_Str,L"10x");
                  iVar9 = (int)local_228 - (int)_Str;
                  do {
                    wVar2 = *_Str;
                    *(wchar_t *)(iVar9 + (int)_Str) = wVar2;
                    _Str = _Str + 1;
                  } while (wVar2 != L'\0');
                  local_6d0 = (wchar_t *)0x0;
                  _wcstok_s(local_228,L"(",&local_6d0);
                  if (local_6d0 != (wchar_t *)0x0) {
                    *local_6d0 = L'\0';
                  }
                  psVar10 = &DAT_00c02bac;
                  if (*(int *)(local_6ec + 4) < 0) {
                    psVar10 = &DAT_00bed1fc;
                  }
                  local_668 = 7;
                  local_66c = 0;
                  local_67c[0] = (undefined4 ****)((uint)local_67c[0] & 0xffff0000);
                  psVar5 = psVar10;
                  do {
                    sVar1 = *psVar5;
                    psVar5 = psVar5 + 1;
                  } while (sVar1 != 0);
                  FUN_00402160(psVar10,(int)psVar5 - (int)(psVar10 + 1) >> 1);
                  local_c = 2;
                  uVar14 = FUN_0040ef80();
                  local_c._0_1_ = 3;
                  FUN_004041f0(uVar14,0,0xffffffff);
                  local_c._0_1_ = 2;
                  if (7 < local_64c) {
                    FUN_0089120c(local_660);
                  }
                  psVar10 = &DAT_00c02ba8;
                  if (pwVar6 == (wchar_t *)0x0) {
                    psVar10 = &DAT_00bed1fc;
                  }
                  psVar5 = psVar10;
                  do {
                    sVar1 = *psVar5;
                    psVar5 = psVar5 + 1;
                  } while (sVar1 != 0);
                  FUN_00404300(psVar10,(int)psVar5 - (int)(psVar10 + 1) >> 1);
                  pppppuVar7 = (undefined4 *****)local_67c[0];
                  if (local_668 < 8) {
                    pppppuVar7 = local_67c;
                  }
                  FUN_0040aeb0(L"%s : %s",local_228,pppppuVar7);
                  iVar9 = *(int *)(local_6d4 + 0x180);
                  if (iVar9 == 0) {
                    uVar12 = 0;
                  }
                  else {
                    uVar12 = (uint)*(byte *)(iVar9 + 0x4c);
                  }
                  iVar8 = *(int *)(local_6d4 + 0x188);
                  if (iVar8 == 0) {
                    iVar11 = 0;
                  }
                  else {
                    iVar11 = *(int *)(iVar8 + 0x10);
                  }
                  if (iVar11 < (int)uVar12) {
                    if (iVar9 == 0) {
LAB_005e2cbb:
                      uVar12 = 0;
                    }
                    else {
                      uVar12 = (uint)*(byte *)(iVar9 + 0x4c);
                    }
                  }
                  else {
                    if (iVar8 == 0) goto LAB_005e2cbb;
                    uVar12 = *(uint *)(iVar8 + 0x10);
                  }
                  uStack_684 = 7;
                  uStack_688 = 0;
                  auStack_698[0] = auStack_698[0] & 0xffff0000;
                  local_c = CONCAT31(local_c._1_3_,4);
                  if (*(int *)(*(int *)(local_6d4 + 0x184) + 8) == 0xf) {
                    uVar12 = 0xffcccccc;
                  }
                  else {
                    switch(uVar12) {
                    case 0:
                      uVar12 = 0xffffffff;
                      break;
                    case 1:
                      uVar12 = 0xffffff00;
                      break;
                    case 2:
                      uVar12 = 0xff5aff78;
                      break;
                    case 3:
                      uVar12 = 0xff00bbdd;
                      break;
                    case 4:
                      uVar12 = 0xffe243ff;
                      break;
                    case 5:
                      uVar12 = 0xffb41010;
                      break;
                    default:
                      uVar12 = 0xff6600;
                    }
                  }
                  FUN_0040aeb0(L"<#%02x%02x%02x>",uVar12 >> 0x10 & 0xff,uVar12 >> 8 & 0xff,
                               uVar12 & 0xff);
                  psVar10 = &sStack_428;
                  do {
                    sVar1 = *psVar10;
                    psVar10 = psVar10 + 1;
                  } while (sVar1 != 0);
                  FUN_00404300(&sStack_428,(int)psVar10 - (int)auStack_426 >> 1);
                  FUN_004041f0(auStack_698,0,0xffffffff);
                  psVar10 = &local_628;
                  do {
                    sVar1 = *psVar10;
                    psVar10 = psVar10 + 1;
                  } while (sVar1 != 0);
                  FUN_00404300(&local_628,(int)psVar10 - (int)local_626 >> 1);
                  if (7 < uStack_684) {
                    FUN_0089120c(auStack_698[0]);
                  }
                  local_c = 0xffffffff;
                  uStack_684 = 7;
                  uStack_688 = 0;
                  auStack_698[0] = auStack_698[0] & 0xffff0000;
                  if (7 < local_668) {
                    FUN_0089120c(local_67c[0]);
                  }
                  local_668 = 7;
                  local_66c = 0;
                  local_67c[0] = (undefined4 ****)((uint)local_67c[0] & 0xffff0000);
                  uVar12 = local_6f0;
                  uVar13 = local_6e8;
                }
              }
              uVar13 = uVar13 + 1;
              if (uVar12 <= uVar13) break;
              FUN_00404300(&DAT_00c02b94,2);
              local_6e8 = uVar13;
            } while( true );
          }
          local_6e8 = uVar13;
          FUN_00404300(L"<br>",4);
          local_6e4 = local_6e4 + 0x18;
          local_6e0 = local_6e0 + 1;
        } while (local_6e0 < local_6f4);
      }
    }
    if (*(char *)(local_6d4 + 0x179) != '\0') {
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_c = 5;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_c = 0xffffffff;
      }
      local_6f4 = 0x191;
      FUN_005740f0(&local_6f4);
      if (local_6f0 == DAT_00fe5ac8) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      uVar14 = FUN_00426ec0();
      local_c = 6;
      FUN_004041f0(uVar14,0,0xffffffff);
      local_c = 0xffffffff;
      if (7 < uStack_684) {
        FUN_0089120c(auStack_698[0]);
      }
      FUN_00404300(L"<br>",4);
    }
    if (*(int *)(local_6d4 + 0x17c) != 0) {
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 7;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      iVar9 = *(int *)(local_6d4 + 0x17c);
      local_6d8 = DAT_00f93950;
      if (iVar9 < DAT_00f93950) {
        uVar14 = 0x19f;
        FUN_00585620(0x19f);
        psVar5 = (short *)FUN_00585330(uVar14);
        psVar10 = psVar5;
        do {
          sVar1 = *psVar10;
          psVar10 = psVar10 + 1;
        } while (sVar1 != 0);
        FUN_00404300(psVar5,(int)psVar10 - (int)(psVar5 + 1) >> 1);
      }
      else {
        local_6f4 = 0x19e;
        iVar8 = FUN_00585620();
        FUN_005740f0(&local_6f4);
        if (local_6f0 == *(uint *)(iVar8 + 4)) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        psVar10 = (short *)(local_6f0 + 0x10);
        if (7 < *(uint *)(local_6f0 + 0x24)) {
          psVar10 = *(short **)psVar10;
        }
        psVar5 = psVar10;
        do {
          sVar1 = *psVar5;
          psVar5 = psVar5 + 1;
        } while (sVar1 != 0);
        FUN_00404300(psVar10,(int)psVar5 - (int)(psVar10 + 1) >> 1);
        local_6f8 = iVar9 - local_6d8;
        __gmtime32_s(&tStack_6bc,&local_6f8);
        bVar4 = true;
        if ((tStack_6bc.tm_yday != 0) ||
           (tStack_6bc.tm_year != 0x46 && -1 < tStack_6bc.tm_year + -0x46)) {
          local_6f4 = 0x34;
          iVar9 = FUN_00585620();
          FUN_005740f0(&local_6f4);
          if (local_6f0 == *(uint *)(iVar9 + 4)) {
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          uVar14 = FUN_004068f0();
          local_c = 8;
          FUN_004041f0(uVar14,0,0xffffffff);
          local_c = 0xffffffff;
          if (7 < uStack_684) {
            FUN_0089120c(auStack_698[0]);
          }
          FUN_00404300(&DAT_00bf3a70,1);
          bVar4 = false;
        }
        if (tStack_6bc.tm_hour != 0) {
          uVar14 = 0x35;
          FUN_00585620(0x35);
          FUN_00585330(uVar14);
          uVar14 = FUN_004068f0();
          local_c = 9;
          FUN_004041f0(uVar14,0,0xffffffff);
          local_c = 0xffffffff;
          if (7 < local_64c) {
            FUN_0089120c(local_660);
          }
          FUN_00404300(&DAT_00bf3a70,1);
          bVar4 = false;
        }
        if (tStack_6bc.tm_min == 0) {
          if (!bVar4) goto LAB_005e3242;
          uVar14 = 0x37;
          FUN_00585620(0x37);
          FUN_00585330(uVar14);
          uVar14 = FUN_004068f0();
          local_c = 0xb;
          FUN_004041f0(uVar14,0,0xffffffff);
        }
        else {
          uVar14 = 0x36;
          FUN_00585620(0x36);
          FUN_00585330(uVar14);
          uVar14 = FUN_004068f0();
          local_c = 10;
          FUN_004041f0(uVar14,0,0xffffffff);
          uStack_644 = local_660;
          uStack_630 = local_64c;
        }
        if (7 < uStack_630) {
          FUN_0089120c(uStack_644);
        }
      }
    }
  }
LAB_005e3242:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_6fc);
  return;
}

