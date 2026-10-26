
void FUN_008a4983(int param_1,ushort *param_2,localeinfo_struct *param_3,wchar_t *param_4)

{
  ushort uVar1;
  wchar_t wVar2;
  short *psVar3;
  short sVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  code *pcVar8;
  int extraout_ECX;
  uint uVar9;
  size_t sVar10;
  wchar_t *pwVar11;
  ushort *puVar12;
  bool bVar13;
  longlong lVar14;
  uint *puVar15;
  wchar_t *pwVar16;
  undefined4 uVar17;
  localeinfo_struct *plVar18;
  uint local_474;
  uint local_470;
  undefined4 local_46c;
  int *local_468;
  ushort *local_464;
  uint local_460;
  wchar_t *local_45c;
  int local_458;
  int local_454;
  localeinfo_struct local_450;
  int local_448;
  char local_444;
  uint local_440;
  char local_43c [4];
  undefined2 local_438;
  short local_436;
  int local_434;
  int local_430;
  uint local_42c;
  int local_428;
  uint local_424;
  wchar_t *local_420;
  int local_41c;
  size_t local_418;
  wchar_t *local_414;
  uint local_410;
  uint local_40c;
  wchar_t local_408 [255];
  undefined2 local_209;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_430 = param_1;
  local_420 = param_4;
  local_458 = 0;
  local_40c = 0;
  local_42c = 0;
  local_410 = 0;
  local_428 = 0;
  local_454 = 0;
  local_434 = 0;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_450,param_3);
  local_468 = __errno();
  if ((param_1 == 0) || (param_2 == (ushort *)0x0)) {
LAB_008a49f9:
    piVar5 = __errno();
    *piVar5 = 0x16;
    FUN_00893343();
    if (local_444 != '\0') {
      *(uint *)(local_448 + 0x70) = *(uint *)(local_448 + 0x70) & 0xfffffffd;
    }
  }
  else {
    local_424 = (uint)*param_2;
    local_41c = 0;
    local_418 = 0;
    local_440 = 0;
    local_45c = (wchar_t *)0x0;
    if (*param_2 != 0) {
      do {
        puVar12 = param_2 + 1;
        local_464 = puVar12;
        if (local_41c < 0) break;
        sVar4 = (short)local_424;
        if ((ushort)(sVar4 - 0x20U) < 0x59) {
          uVar6 = (byte)(&DAT_00bd4430)[local_424] & 0xf;
        }
        else {
          uVar6 = 0;
        }
        local_440 = (uint)((byte)(&DAT_00bd4450)[local_440 + uVar6 * 9] >> 4);
        if (local_440 == 8) goto LAB_008a49f9;
        pwVar11 = local_420;
        switch(local_440) {
        case 0:
switchD_008a4ab3_caseD_0:
          local_434 = 1;
          write_char(local_424);
          pwVar11 = param_4;
          break;
        case 1:
          local_410 = 0xffffffff;
          local_46c = 0;
          local_454 = 0;
          local_42c = 0;
          local_428 = 0;
          local_40c = 0;
          local_434 = 0;
          pwVar11 = param_4;
          break;
        case 2:
          if (local_424 == 0x20) {
            local_40c = local_40c | 2;
            pwVar11 = param_4;
          }
          else if (local_424 == 0x23) {
            local_40c = local_40c | 0x80;
            pwVar11 = param_4;
          }
          else if (local_424 == 0x2b) {
            local_40c = local_40c | 1;
            pwVar11 = param_4;
          }
          else if (local_424 == 0x2d) {
            local_40c = local_40c | 4;
            pwVar11 = param_4;
          }
          else if (local_424 == 0x30) {
            local_40c = local_40c | 8;
            pwVar11 = param_4;
          }
          break;
        case 3:
          if (sVar4 == 0x2a) {
            local_42c = *(uint *)param_4;
            local_420 = param_4 + 2;
            pwVar11 = local_420;
            if ((int)local_42c < 0) {
              local_40c = local_40c | 4;
              local_42c = -local_42c;
            }
          }
          else {
            local_42c = local_42c * 10 + -0x30 + local_424;
            pwVar11 = param_4;
          }
          break;
        case 4:
          local_410 = 0;
          pwVar11 = param_4;
          break;
        case 5:
          if (sVar4 == 0x2a) {
            local_410 = *(uint *)param_4;
            local_420 = param_4 + 2;
            pwVar11 = local_420;
            if ((int)local_410 < 0) {
              local_410 = 0xffffffff;
            }
          }
          else {
            local_410 = local_410 * 10 + -0x30 + local_424;
            pwVar11 = param_4;
          }
          break;
        case 6:
          if (local_424 == 0x49) {
            uVar1 = *puVar12;
            if ((uVar1 == 0x36) && (param_2[2] == 0x34)) {
              local_40c = local_40c | 0x8000;
              pwVar11 = param_4;
              puVar12 = param_2 + 3;
            }
            else if ((uVar1 == 0x33) && (param_2[2] == 0x32)) {
              local_40c = local_40c & 0xffff7fff;
              pwVar11 = param_4;
              puVar12 = param_2 + 3;
            }
            else {
              pwVar11 = param_4;
              if (((((uVar1 != 100) && (uVar1 != 0x69)) && (uVar1 != 0x6f)) &&
                  ((uVar1 != 0x75 && (uVar1 != 0x78)))) && (uVar1 != 0x58)) {
                local_440 = 0;
                goto switchD_008a4ab3_caseD_0;
              }
            }
          }
          else if (local_424 == 0x68) {
            local_40c = local_40c | 0x20;
            pwVar11 = param_4;
          }
          else if (local_424 == 0x6c) {
            if (*puVar12 == 0x6c) {
              local_40c = local_40c | 0x1000;
              pwVar11 = param_4;
              puVar12 = param_2 + 2;
            }
            else {
              local_40c = local_40c | 0x10;
              pwVar11 = param_4;
            }
          }
          else {
            pwVar11 = param_4;
            if (local_424 == 0x77) {
              local_40c = local_40c | 0x800;
            }
          }
          break;
        case 7:
          if (local_424 < 0x65) {
            if (local_424 == 100) {
LAB_008a4fad:
              local_40c = local_40c | 0x40;
LAB_008a4fb4:
              local_424 = 10;
LAB_008a4fbe:
              if (((local_40c & 0x8000) == 0) && ((local_40c & 0x1000) == 0)) {
                local_420 = param_4 + 2;
                if ((local_40c & 0x20) == 0) {
                  uVar6 = *(uint *)param_4;
                  if ((local_40c & 0x40) == 0) {
                    uVar9 = 0;
                  }
                  else {
                    uVar9 = (int)uVar6 >> 0x1f;
                  }
                }
                else {
                  if ((local_40c & 0x40) == 0) {
                    uVar6 = (uint)(ushort)*param_4;
                  }
                  else {
                    uVar6 = (uint)*param_4;
                  }
                  uVar9 = (int)uVar6 >> 0x1f;
                }
              }
              else {
                local_420 = param_4 + 4;
                uVar6 = *(uint *)param_4;
                uVar9 = *(uint *)(param_4 + 2);
              }
              if ((((local_40c & 0x40) != 0) && ((int)uVar9 < 1)) && ((int)uVar9 < 0)) {
                bVar13 = uVar6 != 0;
                uVar6 = -uVar6;
                uVar9 = -(uVar9 + bVar13);
                local_40c = local_40c | 0x100;
              }
              if ((local_40c & 0x9000) == 0) {
                uVar9 = 0;
              }
              lVar14 = CONCAT44(uVar9,uVar6);
              if ((int)local_410 < 0) {
                local_410 = 1;
              }
              else {
                local_40c = local_40c & 0xfffffff7;
                if (0x200 < (int)local_410) {
                  local_410 = 0x200;
                }
              }
              if (uVar6 == 0 && uVar9 == 0) {
                local_428 = 0;
              }
              pwVar11 = &local_209;
              while( true ) {
                uVar6 = local_410 - 1;
                if (((int)local_410 < 1) && (lVar14 == 0)) break;
                local_410 = uVar6;
                lVar14 = __aulldvrm(lVar14,local_424,(int)local_424 >> 0x1f);
                iVar7 = extraout_ECX + 0x30;
                if (0x39 < iVar7) {
                  iVar7 = iVar7 + local_458;
                }
                *(byte *)pwVar11 = (byte)iVar7;
                pwVar11 = (wchar_t *)((int)pwVar11 + -1);
              }
              local_418 = (int)&local_209 + -(int)pwVar11;
              local_414 = (wchar_t *)((int)pwVar11 + 1);
              local_410 = uVar6;
              if (((local_40c & 0x200) != 0) && ((local_418 == 0 || (*(byte *)local_414 != 0x30))))
              {
                local_418 = (int)&local_209 + -(int)pwVar11 + 1;
                *(byte *)pwVar11 = 0x30;
                local_414 = pwVar11;
              }
            }
            else if (local_424 < 0x54) {
              if (local_424 == 0x53) {
                if ((local_40c & 0x830) == 0) {
                  local_40c = local_40c | 0x20;
                }
                goto LAB_008a4d8b;
              }
              if (local_424 != 0x41) {
                if (local_424 == 0x43) {
                  if ((local_40c & 0x830) == 0) {
                    local_40c = local_40c | 0x20;
                  }
LAB_008a4e35:
                  wVar2 = *param_4;
                  local_460 = (uint)(ushort)wVar2;
                  local_420 = param_4 + 2;
                  local_434 = 1;
                  if ((local_40c & 0x20) == 0) {
                    local_408[0] = wVar2;
                  }
                  else {
                    local_43c[0] = (char)wVar2;
                    local_43c[1] = 0;
                    iVar7 = __mbtowc_l(local_408,local_43c,
                                       (size_t)(local_450.locinfo)->locale_name[3],&local_450);
                    if (iVar7 < 0) {
                      local_454 = 1;
                    }
                  }
                  local_418 = 1;
                  local_414 = local_408;
                  goto LAB_008a52ef;
                }
                if ((local_424 != 0x45) && (local_424 != 0x47)) goto LAB_008a52ef;
              }
              local_424 = local_424 + 0x20;
              local_46c = 1;
LAB_008a4d21:
              local_40c = local_40c | 0x40;
              local_418 = 0x200;
              pwVar11 = local_408;
              sVar10 = local_418;
              pwVar16 = local_408;
              if ((int)local_410 < 0) {
                local_410 = 6;
              }
              else if (local_410 == 0) {
                if ((short)local_424 == 0x67) {
                  local_410 = 1;
                }
              }
              else {
                if (0x200 < (int)local_410) {
                  local_410 = 0x200;
                }
                if (0xa3 < (int)local_410) {
                  sVar10 = local_410 + 0x15d;
                  local_414 = local_408;
                  local_45c = __malloc_crt(sVar10);
                  pwVar11 = local_45c;
                  pwVar16 = local_45c;
                  if (local_45c == (wchar_t *)0x0) {
                    local_410 = 0xa3;
                    pwVar11 = local_408;
                    sVar10 = local_418;
                    pwVar16 = local_414;
                  }
                }
              }
              local_414 = pwVar16;
              local_418 = sVar10;
              local_474 = *(uint *)param_4;
              local_420 = param_4 + 4;
              local_470 = *(uint *)(param_4 + 2);
              plVar18 = &local_450;
              iVar7 = (int)(char)local_424;
              puVar15 = &local_474;
              pwVar16 = pwVar11;
              sVar10 = local_418;
              uVar6 = local_410;
              uVar17 = local_46c;
              pcVar8 = DecodePointer(PTR_LAB_00d629c0);
              (*pcVar8)(puVar15,pwVar16,sVar10,iVar7,uVar6,uVar17,plVar18);
              uVar6 = local_40c & 0x80;
              if ((uVar6 != 0) && (local_410 == 0)) {
                plVar18 = &local_450;
                pwVar16 = pwVar11;
                pcVar8 = DecodePointer(PTR_LAB_00d629cc);
                (*pcVar8)(pwVar16,plVar18);
              }
              if (((short)local_424 == 0x67) && (uVar6 == 0)) {
                plVar18 = &local_450;
                pwVar16 = pwVar11;
                pcVar8 = DecodePointer(PTR_LAB_00d629c8);
                (*pcVar8)(pwVar16,plVar18);
              }
              if ((byte)*pwVar11 == 0x2d) {
                local_40c = local_40c | 0x100;
                pwVar11 = (wchar_t *)((int)pwVar11 + 1);
                local_414 = pwVar11;
              }
LAB_008a4f0e:
              local_418 = _strlen((char *)pwVar11);
            }
            else {
              if (local_424 == 0x58) goto LAB_008a50fb;
              if (local_424 == 0x5a) {
                psVar3 = *(short **)param_4;
                local_420 = param_4 + 2;
                if ((psVar3 == (short *)0x0) ||
                   (local_414 = *(wchar_t **)(psVar3 + 2), local_414 == (wchar_t *)0x0)) {
                  local_414 = (wchar_t *)PTR_DAT_00d62090;
                  pwVar11 = (wchar_t *)PTR_DAT_00d62090;
                  goto LAB_008a4f0e;
                }
                local_418 = (size_t)*psVar3;
                if ((local_40c & 0x800) != 0) {
                  iVar7 = local_418 - ((int)local_418 >> 0x1f);
                  goto LAB_008a52e7;
                }
                local_434 = 0;
              }
              else {
                if (local_424 == 0x61) goto LAB_008a4d21;
                if (local_424 == 99) goto LAB_008a4e35;
              }
            }
LAB_008a52ef:
            if (local_454 == 0) {
              if ((local_40c & 0x40) != 0) {
                if ((local_40c & 0x100) == 0) {
                  if ((local_40c & 1) == 0) {
                    if ((local_40c & 2) == 0) goto LAB_008a5331;
                    local_438 = 0x20;
                  }
                  else {
                    local_438 = 0x2b;
                  }
                }
                else {
                  local_438 = 0x2d;
                }
                local_428 = 1;
              }
LAB_008a5331:
              uVar6 = (local_42c - local_418) - local_428;
              local_424 = uVar6;
              if ((local_40c & 0xc) == 0) {
                do {
                  if ((int)uVar6 < 1) break;
                  uVar6 = uVar6 - 1;
                  write_char(0x20);
                } while (local_41c != -1);
              }
              FUN_008a491c(&local_438,local_428);
              if (((local_40c & 8) != 0) && (uVar6 = local_424, (local_40c & 4) == 0)) {
                do {
                  if ((int)uVar6 < 1) break;
                  write_char(0x30);
                  uVar6 = uVar6 - 1;
                } while (local_41c != -1);
              }
              if ((local_434 == 0) && (sVar10 = local_418, pwVar11 = local_414, 0 < (int)local_418))
              {
                do {
                  sVar10 = sVar10 - 1;
                  iVar7 = __mbtowc_l((wchar_t *)&local_460,(char *)pwVar11,
                                     (size_t)(local_450.locinfo)->locale_name[3],&local_450);
                  if (iVar7 < 1) {
                    local_41c = -1;
                    break;
                  }
                  write_char(local_460);
                  pwVar11 = (wchar_t *)((int)pwVar11 + iVar7);
                } while (0 < (int)sVar10);
              }
              else {
                FUN_008a491c(local_414,local_418);
              }
              if ((-1 < local_41c) && (uVar6 = local_424, (local_40c & 4) != 0)) {
                do {
                  if ((int)uVar6 < 1) break;
                  write_char(0x20);
                  uVar6 = uVar6 - 1;
                } while (local_41c != -1);
              }
            }
          }
          else {
            if (0x70 < local_424) {
              if (local_424 == 0x73) {
LAB_008a4d8b:
                uVar6 = local_410;
                if (local_410 == 0xffffffff) {
                  uVar6 = 0x7fffffff;
                }
                local_420 = param_4 + 2;
                local_414 = *(wchar_t **)param_4;
                if ((local_40c & 0x20) == 0) {
                  pwVar11 = local_414;
                  if (local_414 == (wchar_t *)0x0) {
                    local_414 = (wchar_t *)PTR_u__null__00d62094;
                    pwVar11 = (wchar_t *)PTR_u__null__00d62094;
                  }
                  for (; (uVar6 != 0 && (uVar6 = uVar6 - 1, *pwVar11 != L'\0'));
                      pwVar11 = pwVar11 + 1) {
                  }
                  iVar7 = (int)pwVar11 - (int)local_414;
LAB_008a52e7:
                  local_420 = param_4 + 2;
                  local_434 = 1;
                  local_418 = iVar7 >> 1;
                }
                else {
                  if (local_414 == (wchar_t *)0x0) {
                    local_414 = (wchar_t *)PTR_DAT_00d62090;
                  }
                  local_418 = 0;
                  pwVar11 = local_414;
                  if (0 < (int)uVar6) {
                    do {
                      if ((byte)*pwVar11 == 0) break;
                      iVar7 = __isleadbyte_l((uint)(byte)*pwVar11,&local_450);
                      if (iVar7 != 0) {
                        pwVar11 = (wchar_t *)((int)pwVar11 + 1);
                      }
                      pwVar11 = (wchar_t *)((int)pwVar11 + 1);
                      local_418 = local_418 + 1;
                    } while ((int)local_418 < (int)uVar6);
                  }
                }
                goto LAB_008a52ef;
              }
              if (local_424 == 0x75) goto LAB_008a4fb4;
              if (local_424 != 0x78) goto LAB_008a52ef;
              local_458 = 0x27;
LAB_008a512b:
              local_424 = 0x10;
              if ((local_40c & 0x80) != 0) {
                local_438 = 0x30;
                local_436 = (short)local_458 + 0x51;
                local_428 = 2;
              }
              goto LAB_008a4fbe;
            }
            if (local_424 == 0x70) {
              local_410 = 8;
LAB_008a50fb:
              local_458 = 7;
              goto LAB_008a512b;
            }
            if (local_424 < 0x65) goto LAB_008a52ef;
            if (local_424 < 0x68) goto LAB_008a4d21;
            if (local_424 == 0x69) goto LAB_008a4fad;
            if (local_424 != 0x6e) {
              if (local_424 != 0x6f) goto LAB_008a52ef;
              local_424 = 8;
              if ((local_40c & 0x80) != 0) {
                local_40c = local_40c | 0x200;
              }
              goto LAB_008a4fbe;
            }
            local_420 = param_4 + 2;
            piVar5 = *(int **)param_4;
            iVar7 = FUN_0089317c();
            if (iVar7 == 0) goto LAB_008a49f9;
            if ((local_40c & 0x20) == 0) {
              *piVar5 = local_41c;
            }
            else {
              *(undefined2 *)piVar5 = (undefined2)local_41c;
            }
            local_454 = 1;
          }
          pwVar11 = local_420;
          puVar12 = local_464;
          if (local_45c != (wchar_t *)0x0) {
            _free(local_45c);
            local_45c = (wchar_t *)0x0;
            pwVar11 = local_420;
            puVar12 = local_464;
          }
        }
        local_424 = (uint)*puVar12;
        param_4 = pwVar11;
        param_2 = puVar12;
      } while (*puVar12 != 0);
      if ((local_440 != 0) && (local_440 != 7)) goto LAB_008a49f9;
    }
    if (local_444 != '\0') {
      *(uint *)(local_448 + 0x70) = *(uint *)(local_448 + 0x70) & 0xfffffffd;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

