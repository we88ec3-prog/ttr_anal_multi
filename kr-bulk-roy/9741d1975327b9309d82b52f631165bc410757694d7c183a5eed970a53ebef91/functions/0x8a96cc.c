
/* Library Function - Single Match
    __winput_s_l
   
   Library: Visual Studio 2010 Release */

int __cdecl __winput_s_l(FILE *_File,wchar_t *param_2,_locale_t _Locale,va_list _ArgList)

{
  byte *pbVar1;
  size_t _Size;
  wchar_t wVar2;
  void *pvVar3;
  undefined2 uVar4;
  ushort uVar5;
  wchar_t wVar6;
  wint_t wVar7;
  int *piVar8;
  va_list pcVar9;
  int iVar10;
  char *_Dst;
  errno_t eVar11;
  code *pcVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  wchar_t *pwVar17;
  wchar_t *pwVar18;
  bool bVar19;
  longlong lVar20;
  char *pcVar21;
  uint local_34c;
  int local_348 [2];
  int local_340;
  char local_33c;
  int local_338;
  int local_334;
  va_list local_330;
  va_list local_32c;
  void *local_328;
  int local_324;
  int local_320;
  uint local_31c;
  int local_318;
  rsize_t local_314;
  int local_310;
  wchar_t *local_30c;
  wchar_t *local_308;
  byte local_301;
  undefined8 local_300;
  uint local_2f8;
  uint local_2f4;
  int local_2f0;
  wchar_t *local_2ec;
  char local_2e7;
  char local_2e6;
  char local_2e5;
  FILE *local_2e4;
  char local_2dd;
  int local_2dc;
  char local_2d5;
  uint local_2d4;
  char local_2cd;
  uint local_2cc;
  char local_2c5;
  wchar_t local_2c4 [350];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_32c = _ArgList;
  local_2ec = local_2c4;
  local_2e4 = _File;
  local_308 = param_2;
  local_320 = 0x15e;
  local_324 = 0;
  local_328 = (void *)0x0;
  local_334 = 0;
  local_2d4 = 0;
  local_338 = 0;
  if ((param_2 == (wchar_t *)0x0) || (_File == (FILE *)0x0)) {
    piVar8 = __errno();
    *piVar8 = 0x16;
    FUN_00893343();
  }
  else {
    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_348,_Locale);
    wVar6 = *param_2;
    local_2e6 = '\0';
    local_2cc = 0;
    local_318 = 0;
    if (wVar6 != L'\0') {
      do {
        iVar14 = _iswctype(wVar6,8);
        if (iVar14 == 0) {
          pwVar17 = local_308;
          if (*local_308 == L'%') {
            if (local_308[1] == L'%') {
              if (local_308[1] == L'%') {
                pwVar17 = local_308 + 1;
              }
              goto LAB_008aa731;
            }
            local_2f8 = 0;
            local_34c = 0;
            local_2f0 = 0;
            local_310 = 0;
            local_2dc = 0;
            local_314 = 0;
            local_301 = 0;
            local_2e7 = '\0';
            local_2d5 = '\0';
            local_2c5 = '\0';
            local_2e5 = '\0';
            local_2cd = '\0';
            local_2dd = '\x01';
            local_2f4 = 0;
            do {
              pwVar18 = pwVar17 + 1;
              uVar15 = (uint)(ushort)*pwVar18;
              if ((*pwVar18 & 0xff00U) == 0) {
                iVar14 = _isdigit(uVar15 & 0xff);
                if (iVar14 == 0) goto LAB_008a9894;
                local_310 = local_310 + 1;
                local_2dc = local_2dc * 10 + -0x30 + uVar15;
              }
              else {
LAB_008a9894:
                if (uVar15 < 0x4f) {
                  if (uVar15 != 0x4e) {
                    if (uVar15 == 0x2a) {
                      local_2d5 = local_2d5 + '\x01';
                    }
                    else if (uVar15 != 0x46) {
                      if (uVar15 == 0x49) {
                        wVar6 = pwVar17[2];
                        if ((wVar6 == L'6') && (pwVar17[3] == L'4')) {
                          pwVar18 = pwVar17 + 3;
                          goto LAB_008a98d9;
                        }
                        if ((wVar6 == L'3') && (pwVar17[3] == L'2')) {
                          pwVar18 = pwVar17 + 3;
                        }
                        else if ((wVar6 != L'd') &&
                                ((((wVar6 != L'i' && (wVar6 != L'o')) && (wVar6 != L'x')) &&
                                 (wVar6 != L'X')))) goto LAB_008a9930;
                      }
                      else if (uVar15 == 0x4c) {
                        local_2dd = local_2dd + '\x01';
                      }
                      else {
LAB_008a9930:
                        local_2c5 = local_2c5 + '\x01';
                      }
                    }
                  }
                }
                else if (uVar15 == 0x68) {
                  local_2dd = local_2dd + -1;
                  local_2cd = local_2cd + -1;
                }
                else {
                  if (uVar15 == 0x6c) {
                    if (pwVar17[2] == L'l') {
                      pwVar18 = pwVar17 + 2;
LAB_008a98d9:
                      local_2f4 = local_2f4 + 1;
                      local_300 = 0;
                      goto LAB_008a995e;
                    }
                    local_2dd = local_2dd + '\x01';
                  }
                  else if (uVar15 != 0x77) goto LAB_008a9930;
                  local_2cd = local_2cd + '\x01';
                }
              }
LAB_008a995e:
              pwVar17 = pwVar18;
            } while (local_2c5 == '\0');
            if (local_2d5 == '\0') {
              local_30c = *(wchar_t **)local_32c;
              local_330 = local_32c;
              local_32c = local_32c + 4;
            }
            else {
              local_30c = (wchar_t *)0x0;
            }
            local_2c5 = '\0';
            if ((local_2cd == '\0') &&
               ((*pwVar18 == L'S' || (local_2cd = '\x01', *pwVar18 == L'C')))) {
              local_2cd = -1;
            }
            uVar15 = (ushort)*pwVar18 | 0x20;
            local_31c = uVar15;
            local_308 = pwVar18;
            if (uVar15 != 0x6e) {
              if ((uVar15 == 99) || (uVar15 == 0x7b)) {
                local_2cc = local_2cc + 1;
                uVar5 = __fgetwc_nolock(local_2e4);
              }
              else {
                uVar5 = __whiteout(local_2e4);
              }
              local_2d4 = (uint)uVar5;
              if (uVar5 == 0xffff) break;
            }
            if ((local_310 != 0) && (local_2dc == 0)) goto LAB_008aa7fc;
            if ((local_2d5 == '\0') && (((uVar15 == 99 || (uVar15 == 0x73)) || (uVar15 == 0x7b)))) {
              local_30c = *(wchar_t **)local_330;
              pcVar9 = local_330 + 4;
              local_32c = local_330 + 8;
              local_314 = *(rsize_t *)(local_330 + 4);
              local_330 = pcVar9;
              if (local_314 == 0) {
                if (local_2cd < '\x01') {
                  *(undefined1 *)local_30c = 0;
                }
                else {
                  *local_30c = L'\0';
                }
                piVar8 = __errno();
                *piVar8 = 0xc;
                break;
              }
            }
            if (uVar15 < 0x70) {
              if (uVar15 == 0x6f) {
LAB_008aa3f8:
                if ((wchar_t)local_2d4 == L'-') {
                  local_2e7 = '\x01';
                }
                else if ((wchar_t)local_2d4 != L'+') goto LAB_008aa447;
                local_2dc = local_2dc + -1;
                if ((local_2dc == 0) && (local_310 != 0)) {
                  local_2c5 = '\x01';
                }
                else {
                  local_2cc = local_2cc + 1;
                  wVar7 = __fgetwc_nolock(local_2e4);
                  local_2d4 = (uint)wVar7;
                }
                goto LAB_008aa447;
              }
              if (uVar15 == 99) {
                if (local_310 == 0) {
                  local_2dc = local_2dc + 1;
                  local_310 = 1;
                }
LAB_008a9f8e:
                pwVar17 = local_308;
                if ('\0' < local_2cd) {
                  local_2e5 = '\x01';
                }
                goto LAB_008a9f9e;
              }
              if (uVar15 == 100) goto LAB_008aa3f8;
              if (uVar15 < 0x65) {
LAB_008aa0c3:
                if (*local_308 != (wchar_t)local_2d4) {
                  __un_inc(local_2d4,local_2e4);
                  local_338 = 1;
                  break;
                }
                local_2e6 = local_2e6 + -1;
                if (local_2d5 == '\0') {
                  local_32c = local_330;
                }
              }
              else {
                if (0x67 < uVar15) {
                  if (uVar15 == 0x69) {
                    local_31c = 100;
                    uVar15 = 100;
                    goto LAB_008a9ae6;
                  }
                  if (uVar15 != 0x6e) goto LAB_008aa0c3;
                  uVar15 = local_2cc;
                  lVar20 = local_300;
                  if (local_2d5 != '\0') goto LAB_008aa70c;
                  goto LAB_008aa6e0;
                }
                iVar14 = 0;
                if ((wchar_t)local_2d4 == L'-') {
                  *local_2ec = L'-';
                  iVar14 = 1;
LAB_008a9b2a:
                  local_2dc = local_2dc + -1;
                  local_2cc = local_2cc + 1;
                  wVar7 = __fgetwc_nolock(local_2e4);
                  local_2d4 = (uint)wVar7;
                }
                else if ((wchar_t)local_2d4 == L'+') goto LAB_008a9b2a;
                if (local_310 == 0) {
                  local_2dc = -1;
                }
                if ((local_2d4 & 0xff00) == 0) {
                  do {
                    iVar10 = _isdigit(local_2d4 & 0xff);
                    if ((iVar10 == 0) ||
                       (iVar10 = local_2dc + -1, bVar19 = local_2dc == 0, local_2dc = iVar10, bVar19
                       )) break;
                    local_2f0 = local_2f0 + 1;
                    local_2ec[iVar14] = (short)(char)local_2d4;
                    iVar14 = iVar14 + 1;
                    iVar10 = ___check_float_string(iVar14,local_2c4,&local_324);
                    if (iVar10 == 0) goto LAB_008aa80f;
                    local_2cc = local_2cc + 1;
                    wVar7 = __fgetwc_nolock(local_2e4);
                    local_2d4 = (uint)wVar7;
                  } while ((wVar7 & 0xff00) == 0);
                }
                wVar6 = **(wchar_t **)(*(int *)(local_348[0] + 0xbc) + 0x30);
                if (((uint)(ushort)wVar6 == (int)(char)local_2d4) &&
                   (iVar10 = local_2dc + -1, bVar19 = local_2dc != 0, local_2dc = iVar10, bVar19)) {
                  local_2cc = local_2cc + 1;
                  wVar7 = __fgetwc_nolock(local_2e4);
                  local_2d4 = (uint)wVar7;
                  local_2ec[iVar14] = wVar6;
                  iVar14 = iVar14 + 1;
                  iVar10 = ___check_float_string(iVar14,local_2c4,&local_324);
                  if (iVar10 == 0) break;
                  if ((local_2d4 & 0xff00) == 0) {
                    do {
                      iVar10 = _isdigit(local_2d4 & 0xff);
                      if ((iVar10 == 0) ||
                         (iVar10 = local_2dc + -1, bVar19 = local_2dc == 0, local_2dc = iVar10,
                         bVar19)) break;
                      local_2f0 = local_2f0 + 1;
                      local_2ec[iVar14] = (wchar_t)local_2d4;
                      iVar14 = iVar14 + 1;
                      iVar10 = ___check_float_string(iVar14,local_2c4,&local_324);
                      if (iVar10 == 0) goto LAB_008aa80f;
                      local_2cc = local_2cc + 1;
                      wVar7 = __fgetwc_nolock(local_2e4);
                      local_2d4 = (uint)wVar7;
                    } while ((wVar7 & 0xff00) == 0);
                  }
                }
                if ((local_2f0 != 0) &&
                   ((((wchar_t)local_2d4 == 0x65 || ((wchar_t)local_2d4 == 0x45)) &&
                    (iVar10 = local_2dc + -1, bVar19 = local_2dc != 0, local_2dc = iVar10, bVar19)))
                   ) {
                  local_2ec[iVar14] = L'e';
                  iVar16 = iVar14 + 1;
                  iVar10 = ___check_float_string(iVar16,local_2c4,&local_324);
                  if (iVar10 == 0) break;
                  local_2cc = local_2cc + 1;
                  wVar7 = __fgetwc_nolock(local_2e4);
                  local_2d4 = (uint)wVar7;
                  if (wVar7 == 0x2d) {
                    local_2ec[iVar16] = L'-';
                    iVar16 = iVar14 + 2;
                    iVar14 = ___check_float_string(iVar16,local_2c4,&local_324);
                    if (iVar14 == 0) break;
LAB_008a9dec:
                    iVar14 = iVar16;
                    if (local_2dc == 0) {
                      local_2dc = 0;
                    }
                    else {
                      local_2cc = local_2cc + 1;
                      local_2dc = local_2dc + -1;
                      wVar7 = __fgetwc_nolock(local_2e4);
                      local_2d4 = (uint)wVar7;
                    }
                  }
                  else {
                    iVar14 = iVar16;
                    if (wVar7 == 0x2b) goto LAB_008a9dec;
                  }
                  if ((local_2d4 & 0xff00) == 0) {
                    do {
                      iVar10 = _isdigit(local_2d4 & 0xff);
                      if ((iVar10 == 0) ||
                         (iVar10 = local_2dc + -1, bVar19 = local_2dc == 0, local_2dc = iVar10,
                         bVar19)) break;
                      local_2f0 = local_2f0 + 1;
                      local_2ec[iVar14] = (wchar_t)local_2d4;
                      iVar14 = iVar14 + 1;
                      iVar10 = ___check_float_string(iVar14,local_2c4,&local_324);
                      if (iVar10 == 0) goto LAB_008aa80f;
                      local_2cc = local_2cc + 1;
                      wVar7 = __fgetwc_nolock(local_2e4);
                      local_2d4 = (uint)wVar7;
                    } while ((wVar7 & 0xff00) == 0);
                  }
                }
                local_2cc = local_2cc - 1;
                __un_inc(local_2d4,local_2e4);
                if (local_2f0 == 0) break;
                if (local_2d5 == '\0') {
                  local_318 = local_318 + 1;
                  iVar10 = local_320 * 2;
                  _Size = iVar10 + 2;
                  local_2ec[iVar14] = L'\0';
                  _Dst = __malloc_crt(_Size);
                  if (_Dst != (char *)0x0) {
                    eVar11 = _wcstombs_s((size_t *)0x0,_Dst,_Size,local_2ec,iVar10 + 1);
                    if ((eVar11 != 0) && ((eVar11 == 0x16 || (eVar11 == 0x22)))) {
                    /* WARNING: Subroutine does not return */
                      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
                    }
                    piVar8 = local_348;
                    iVar14 = local_2dd + -1;
                    pwVar17 = local_30c;
                    pcVar21 = _Dst;
                    pcVar12 = DecodePointer(PTR_LAB_00d629c4);
                    (*pcVar12)(iVar14,pwVar17,pcVar21,piVar8);
                    _free(_Dst);
                    goto LAB_008aa70c;
                  }
                  break;
                }
              }
            }
            else {
              if (uVar15 == 0x70) {
                local_2dd = '\x01';
                goto LAB_008aa3f8;
              }
              if (uVar15 == 0x73) goto LAB_008a9f8e;
              if (uVar15 == 0x75) goto LAB_008aa3f8;
              if (uVar15 != 0x78) {
                if (uVar15 != 0x7b) goto LAB_008aa0c3;
                if ('\0' < local_2cd) {
                  local_2e5 = '\x01';
                }
                pwVar17 = local_308 + 1;
                if (local_308[1] == L'^') {
                  pwVar17 = local_308 + 2;
                  local_301 = 0xff;
                }
                if (local_328 == (void *)0x0) {
                  local_328 = __malloc_crt(0x2000);
                  if (local_328 == (void *)0x0) break;
                  local_334 = 1;
                }
                pvVar3 = local_328;
                _memset(local_328,0,0x2000);
                if (*pwVar17 == L']') {
                  *(undefined1 *)((int)pvVar3 + 0xb) = 0x20;
                  local_34c = 0x5d;
                  pwVar17 = pwVar17 + 1;
                }
LAB_008aa20b:
                do {
                  wVar6 = *pwVar17;
                  if (wVar6 == L']') goto code_r0x008aa21a;
                  if ((wVar6 == L'-') && ((wchar_t)local_34c != L'\0')) {
                    wVar2 = pwVar17[1];
                    uVar15 = (uint)(ushort)wVar2;
                    if (wVar2 != L']') {
                      local_2f4 = local_34c;
                      if ((ushort)(wchar_t)local_34c < (ushort)wVar2) {
                        local_2f4 = uVar15;
                        uVar15 = local_34c;
                      }
                      if ((ushort)uVar15 < (ushort)local_2f4) {
                        local_2f8 = local_2f4 - uVar15 & 0xffff;
                        do {
                          pbVar1 = (byte *)((uVar15 >> 3) + (int)pvVar3);
                          *pbVar1 = *pbVar1 | '\x01' << ((byte)uVar15 & 7);
                          uVar15 = uVar15 + 1;
                          local_2f8 = local_2f8 - 1;
                        } while (local_2f8 != 0);
                      }
                      pbVar1 = (byte *)((uint)(ushort)((ushort)local_2f4 >> 3) + (int)pvVar3);
                      *pbVar1 = *pbVar1 | '\x01' << ((byte)local_2f4 & 7);
                      local_34c = 0;
                      pwVar17 = pwVar17 + 2;
                      goto LAB_008aa20b;
                    }
                  }
                  pbVar1 = (byte *)((uint)((ushort)wVar6 >> 3) + (int)pvVar3);
                  *pbVar1 = *pbVar1 | '\x01' << ((byte)wVar6 & 7);
                  local_34c = (uint)(ushort)wVar6;
                  pwVar17 = pwVar17 + 1;
                } while( true );
              }
LAB_008a9ae6:
              if ((wchar_t)local_2d4 == L'-') {
                local_2e7 = '\x01';
LAB_008aa243:
                local_2dc = local_2dc + -1;
                if ((local_2dc == 0) && (local_310 != 0)) {
                  local_2c5 = '\x01';
                }
                else {
                  local_2cc = local_2cc + 1;
                  wVar7 = __fgetwc_nolock(local_2e4);
                  local_2d4 = (uint)wVar7;
                }
              }
              else if ((wchar_t)local_2d4 == L'+') goto LAB_008aa243;
              if ((short)local_2d4 == 0x30) {
                local_2cc = local_2cc + 1;
                wVar7 = __fgetwc_nolock(local_2e4);
                local_2d4 = (uint)wVar7;
                if ((wVar7 == 0x78) || (wVar7 == 0x58)) {
                  local_2cc = local_2cc + 1;
                  wVar7 = __fgetwc_nolock(local_2e4);
                  local_2d4 = (uint)wVar7;
                  if ((local_310 != 0) && (local_2dc = local_2dc + -2, local_2dc < 1)) {
                    local_2c5 = local_2c5 + '\x01';
                  }
                  local_31c = 0x78;
                  uVar15 = local_31c;
                }
                else {
                  local_2f0 = 1;
                  if (uVar15 == 0x78) {
                    local_2cc = local_2cc - 1;
                    __un_inc(local_2d4,local_2e4);
                    local_2d4 = 0x30;
                  }
                  else {
                    if ((local_310 != 0) && (local_2dc = local_2dc + -1, local_2dc == 0)) {
                      local_2c5 = local_2c5 + '\x01';
                    }
                    local_31c = 0x6f;
                    uVar15 = local_31c;
                  }
                }
              }
LAB_008aa447:
              lVar20 = local_300;
              if (local_2f4 == 0) {
                if (local_2c5 == '\0') {
                  while ((uVar13 = local_2d4, uVar15 != 0x78 && (uVar15 != 0x70))) {
                    if ((local_2d4 & 0xff00) != 0) goto LAB_008aa689;
                    iVar14 = _isdigit(local_2d4 & 0xff);
                    if (iVar14 == 0) goto LAB_008aa689;
                    if (uVar15 == 0x6f) {
                      if (0x37 < (ushort)uVar13) goto LAB_008aa689;
                      local_2f8 = local_2f8 << 3;
                    }
                    else {
                      local_2f8 = local_2f8 * 10;
                    }
LAB_008aa645:
                    local_2f0 = local_2f0 + 1;
                    local_2f8 = local_2f8 + -0x30 + (uVar13 & 0xffff);
                    if ((local_310 != 0) &&
                       (local_2dc = local_2dc + -1, lVar20 = local_300, local_2dc == 0))
                    goto LAB_008aa69d;
                    local_2cc = local_2cc + 1;
                    wVar7 = __fgetwc_nolock(local_2e4);
                    local_2d4 = (uint)wVar7;
                  }
                  if ((local_2d4 & 0xff00) == 0) {
                    iVar14 = _isxdigit(local_2d4 & 0xff);
                    if (iVar14 != 0) {
                      local_2f8 = local_2f8 << 4;
                      uVar13 = __hextodec(uVar13);
                      uVar13 = uVar13 & 0xffff;
                      local_2d4 = uVar13;
                      goto LAB_008aa645;
                    }
                  }
LAB_008aa689:
                  local_2cc = local_2cc - 1;
                  __un_inc(uVar13,local_2e4);
                  lVar20 = local_300;
                }
LAB_008aa69d:
                if (local_2e7 != '\0') {
                  local_2f8 = -local_2f8;
                }
              }
              else {
                if (local_2c5 == '\0') {
                  while ((uVar13 = local_2d4, uVar15 != 0x78 && (uVar15 != 0x70))) {
                    if ((local_2d4 & 0xff00) != 0) goto LAB_008aa571;
                    iVar14 = _isdigit(local_2d4 & 0xff);
                    if (iVar14 == 0) goto LAB_008aa571;
                    if (uVar15 == 0x6f) {
                      if (0x37 < (ushort)uVar13) goto LAB_008aa571;
                      local_300 = local_300 << 3;
                    }
                    else {
                      lVar20 = __allmul(local_300,10,0);
                      local_300 = lVar20;
                    }
LAB_008aa527:
                    local_2f0 = local_2f0 + 1;
                    local_300 = local_300 + (int)((uVar13 & 0xffff) - 0x30);
                    if ((local_310 != 0) &&
                       (local_2dc = local_2dc + -1, lVar20 = local_300, local_2dc == 0))
                    goto LAB_008aa585;
                    local_2cc = local_2cc + 1;
                    wVar7 = __fgetwc_nolock(local_2e4);
                    local_2d4 = (uint)wVar7;
                  }
                  if ((local_2d4 & 0xff00) == 0) {
                    iVar14 = _isxdigit(local_2d4 & 0xff);
                    if (iVar14 != 0) {
                      local_300 = local_300 << 4;
                      uVar13 = __hextodec(uVar13);
                      uVar13 = uVar13 & 0xffff;
                      local_2d4 = uVar13;
                      goto LAB_008aa527;
                    }
                  }
LAB_008aa571:
                  local_2cc = local_2cc - 1;
                  __un_inc(uVar13,local_2e4);
                  lVar20 = local_300;
                }
LAB_008aa585:
                local_300._4_4_ = (int)((ulonglong)lVar20 >> 0x20);
                local_300._0_4_ = (int)lVar20;
                if (local_2e7 != '\0') {
                  lVar20 = CONCAT44(-(local_300._4_4_ + (uint)((int)local_300 != 0)),-(int)local_300
                                   );
                }
              }
              if (uVar15 == 0x46) {
                local_2f0 = 0;
              }
              local_300 = lVar20;
              if (local_2f0 == 0) break;
              if (local_2d5 == '\0') {
                local_318 = local_318 + 1;
                uVar15 = local_2f8;
LAB_008aa6e0:
                local_300 = lVar20;
                if (local_2f4 == 0) {
                  if (local_2dd == '\0') {
                    *local_30c = (wchar_t)uVar15;
                  }
                  else {
                    *(uint *)local_30c = uVar15;
                  }
                }
                else {
                  *(longlong *)local_30c = lVar20;
                }
              }
            }
LAB_008aa70c:
            local_2e6 = local_2e6 + '\x01';
            local_308 = local_308 + 1;
          }
          else {
LAB_008aa731:
            local_2cc = local_2cc + 1;
            wVar6 = __fgetwc_nolock(local_2e4);
            local_2d4 = (uint)(ushort)wVar6;
            local_308 = pwVar17 + 1;
            if (*pwVar17 != wVar6) {
LAB_008aa7fc:
              __un_inc(local_2d4,local_2e4);
              break;
            }
          }
          pwVar17 = local_308;
          if (((wchar_t)local_2d4 == -1) && ((*local_308 != L'%' || (local_308[1] != L'n')))) break;
        }
        else {
          local_2cc = local_2cc - 1;
          uVar4 = __whiteout(local_2e4,local_2e4);
          __un_inc(uVar4);
          pwVar17 = local_308;
          do {
            pwVar17 = pwVar17 + 1;
            iVar14 = _iswctype(*pwVar17,8);
          } while (iVar14 != 0);
        }
        local_308 = pwVar17;
        wVar6 = *local_308;
      } while (wVar6 != L'\0');
LAB_008aa80f:
      if (local_334 == 1) {
        _free(local_328);
      }
      if (local_324 == 1) {
        _free(local_2ec);
      }
      if ((wchar_t)local_2d4 == -1) {
        if (local_33c != '\0') {
          *(uint *)(local_340 + 0x70) = *(uint *)(local_340 + 0x70) & 0xfffffffd;
        }
        goto LAB_008aa8a4;
      }
      if (local_338 == 1) {
        piVar8 = __errno();
        *piVar8 = 0x16;
        FUN_00893343();
      }
    }
    if (local_33c != '\0') {
      *(uint *)(local_340 + 0x70) = *(uint *)(local_340 + 0x70) & 0xfffffffd;
    }
  }
LAB_008aa8a4:
  iVar14 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar14;
code_r0x008aa21a:
  uVar15 = local_31c;
  if (*pwVar17 != L'\0') {
LAB_008a9f9e:
    local_308 = pwVar17;
    pwVar17 = local_30c;
    local_2cc = local_2cc - 1;
    __un_inc(local_2d4,local_2e4);
    pwVar18 = pwVar17;
    if (uVar15 == 99) goto LAB_008a9fc4;
LAB_008a9fbe:
    local_314 = local_314 - 1;
LAB_008a9fc4:
    do {
      if ((local_310 != 0) &&
         (iVar14 = local_2dc + -1, bVar19 = local_2dc == 0, local_2dc = iVar14, bVar19)) {
LAB_008aa3a6:
        if (pwVar18 == pwVar17) break;
        if ((local_2d5 == '\0') && (local_318 = local_318 + 1, uVar15 != 99)) {
          if (local_2e5 == '\0') {
            *(undefined1 *)local_30c = 0;
          }
          else {
            *local_30c = L'\0';
          }
        }
        goto LAB_008aa70c;
      }
      local_2cc = local_2cc + 1;
      wVar6 = __fgetwc_nolock(local_2e4);
      local_2d4 = (uint)(ushort)wVar6;
      if (wVar6 == L'\xffff') {
LAB_008aa392:
        local_2cc = local_2cc - 1;
        __un_inc(local_2d4,local_2e4);
        goto LAB_008aa3a6;
      }
      if (uVar15 != 99) {
        if (uVar15 == 0x73) {
          if ((8 < local_2d4) && (local_2d4 < 0xe)) goto LAB_008aa392;
          if (local_2d4 != 0x20) goto LAB_008aa061;
        }
        if ((uVar15 != 0x7b) ||
           (uVar15 = local_31c,
           ((int)(char)(*(byte *)((uint)((ushort)wVar6 >> 3) + (int)local_328) ^ local_301) &
           1 << ((byte)wVar6 & 7)) == 0)) goto LAB_008aa392;
      }
LAB_008aa061:
      if (local_2d5 == '\0') {
        if (local_314 != 0) {
          if (local_2e5 != '\0') goto code_r0x008aa088;
          local_2f4 = 0;
          eVar11 = _wctomb_s((int *)&local_2f4,(char *)pwVar17,local_314,wVar6);
          if (eVar11 != 0x22) {
            if (0 < (int)local_2f4) {
              pwVar17 = (wchar_t *)((int)pwVar17 + local_2f4);
              local_314 = local_314 - local_2f4;
              local_30c = pwVar17;
            }
            goto LAB_008a9fc4;
          }
        }
        piVar8 = __errno();
        *piVar8 = 0xc;
        if (local_2e5 == '\0') {
          *(undefined1 *)pwVar18 = 0;
        }
        else {
          *pwVar18 = L'\0';
        }
        break;
      }
      pwVar18 = pwVar18 + 1;
    } while( true );
  }
  goto LAB_008aa80f;
code_r0x008aa088:
  *pwVar17 = wVar6;
  pwVar17 = pwVar17 + 1;
  local_30c = pwVar17;
  goto LAB_008a9fbe;
}

