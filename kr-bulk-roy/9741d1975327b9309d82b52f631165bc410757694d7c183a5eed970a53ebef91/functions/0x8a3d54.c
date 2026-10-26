
void FUN_008a3d54(int param_1,ushort *param_2,localeinfo_struct *param_3,wchar_t *param_4)

{
  ushort uVar1;
  wchar_t wVar2;
  short *psVar3;
  wchar_t *pwVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  code *pcVar8;
  int extraout_ECX;
  uint uVar9;
  wchar_t *pwVar10;
  size_t sVar11;
  wchar_t *pwVar12;
  bool bVar13;
  longlong lVar14;
  uint *puVar15;
  undefined4 uVar16;
  localeinfo_struct *plVar17;
  uint local_474;
  uint local_470;
  undefined4 local_46c;
  int *local_468;
  int local_464;
  uint local_460;
  localeinfo_struct local_45c;
  int local_454;
  char local_450;
  int local_44c;
  int local_448;
  ushort *local_444;
  wchar_t *local_440;
  char local_43c;
  undefined1 local_43b;
  undefined2 local_438;
  short local_436;
  uint local_434;
  int local_430;
  int local_42c;
  int local_428;
  wchar_t *local_424;
  uint local_420;
  int local_41c;
  size_t local_418;
  wchar_t *local_414;
  uint local_410;
  uint local_40c;
  wchar_t local_408 [255];
  undefined2 local_209;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_428 = param_1;
  local_424 = param_4;
  local_448 = 0;
  local_40c = 0;
  local_434 = 0;
  local_410 = 0;
  local_42c = 0;
  local_44c = 0;
  local_430 = 0;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_45c,param_3);
  local_468 = __errno();
  if ((local_428 == 0) || (param_2 == (ushort *)0x0)) {
    piVar5 = __errno();
    *piVar5 = 0x16;
    FUN_00893343();
LAB_008a3de4:
    if (local_450 != '\0') {
      *(uint *)(local_454 + 0x70) = *(uint *)(local_454 + 0x70) & 0xfffffffd;
    }
  }
  else {
    uVar1 = *param_2;
    local_41c = 0;
    local_418 = 0;
    local_440 = (wchar_t *)0x0;
    iVar7 = 0;
    while (local_420 = (uint)uVar1, uVar1 != 0) {
      local_444 = param_2 + 1;
      if (local_41c < 0) break;
      if ((ushort)(uVar1 - 0x20) < 0x59) {
        uVar6 = (int)"UTF-16LE"[local_420 + 8] & 0xf;
      }
      else {
        uVar6 = 0;
      }
      local_464 = (int)(char)(&DAT_00bd43f0)[uVar6 * 8 + iVar7] >> 4;
      switch(local_464) {
      case 0:
switchD_008a3e70_caseD_0:
        local_430 = 1;
        write_char(local_420);
        break;
      case 1:
        local_410 = 0xffffffff;
        local_46c = 0;
        local_44c = 0;
        local_434 = 0;
        local_42c = 0;
        local_40c = 0;
        local_430 = 0;
        break;
      case 2:
        if (local_420 == 0x20) {
          local_40c = local_40c | 2;
        }
        else if (local_420 == 0x23) {
          local_40c = local_40c | 0x80;
        }
        else if (local_420 == 0x2b) {
          local_40c = local_40c | 1;
        }
        else if (local_420 == 0x2d) {
          local_40c = local_40c | 4;
        }
        else if (local_420 == 0x30) {
          local_40c = local_40c | 8;
        }
        break;
      case 3:
        if (uVar1 == 0x2a) {
          local_424 = param_4 + 2;
          local_434 = *(uint *)param_4;
          if ((int)local_434 < 0) {
            local_40c = local_40c | 4;
            local_434 = -local_434;
          }
        }
        else {
          local_434 = local_434 * 10 + -0x30 + local_420;
        }
        break;
      case 4:
        local_410 = 0;
        break;
      case 5:
        if (uVar1 == 0x2a) {
          local_424 = param_4 + 2;
          local_410 = *(uint *)param_4;
          if ((int)local_410 < 0) {
            local_410 = 0xffffffff;
          }
        }
        else {
          local_410 = local_410 * 10 + -0x30 + local_420;
        }
        break;
      case 6:
        if (local_420 == 0x49) {
          uVar1 = *local_444;
          if ((uVar1 == 0x36) && (param_2[2] == 0x34)) {
            local_444 = param_2 + 3;
            local_40c = local_40c | 0x8000;
          }
          else if ((uVar1 == 0x33) && (param_2[2] == 0x32)) {
            local_444 = param_2 + 3;
            local_40c = local_40c & 0xffff7fff;
          }
          else if (((((uVar1 != 100) && (uVar1 != 0x69)) && (uVar1 != 0x6f)) &&
                   ((uVar1 != 0x75 && (uVar1 != 0x78)))) && (uVar1 != 0x58)) {
            local_464 = 0;
            goto switchD_008a3e70_caseD_0;
          }
        }
        else if (local_420 == 0x68) {
          local_40c = local_40c | 0x20;
        }
        else if (local_420 == 0x6c) {
          if (*local_444 == 0x6c) {
            local_444 = param_2 + 2;
            local_40c = local_40c | 0x1000;
          }
          else {
            local_40c = local_40c | 0x10;
          }
        }
        else if (local_420 == 0x77) {
          local_40c = local_40c | 0x800;
        }
        break;
      case 7:
        if (local_420 < 0x65) {
          if (local_420 == 100) {
LAB_008a4380:
            local_40c = local_40c | 0x40;
LAB_008a4387:
            local_420 = 10;
LAB_008a4391:
            if (((local_40c & 0x8000) == 0) && ((local_40c & 0x1000) == 0)) {
              local_424 = param_4 + 2;
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
              uVar6 = *(uint *)param_4;
              uVar9 = *(uint *)(param_4 + 2);
              local_424 = param_4 + 4;
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
              local_42c = 0;
            }
            pwVar12 = &local_209;
            while ((uVar6 = local_410 - 1, 0 < (int)local_410 || (lVar14 != 0))) {
              local_410 = uVar6;
              lVar14 = __aulldvrm(lVar14,local_420,(int)local_420 >> 0x1f);
              iVar7 = extraout_ECX + 0x30;
              if (0x39 < iVar7) {
                iVar7 = iVar7 + local_448;
              }
              *(byte *)pwVar12 = (byte)iVar7;
              pwVar12 = (wchar_t *)((int)pwVar12 + -1);
            }
            local_418 = (int)&local_209 + -(int)pwVar12;
            local_414 = (wchar_t *)((int)pwVar12 + 1);
            local_410 = uVar6;
            if (((local_40c & 0x200) != 0) && ((local_418 == 0 || (*(byte *)local_414 != 0x30)))) {
              local_418 = (int)&local_209 + -(int)pwVar12 + 1;
              *(byte *)pwVar12 = 0x30;
              local_414 = pwVar12;
            }
          }
          else if (local_420 < 0x54) {
            if (local_420 == 0x53) {
              if ((local_40c & 0x830) == 0) {
                local_40c = local_40c | 0x20;
              }
              goto LAB_008a415c;
            }
            if (local_420 != 0x41) {
              if (local_420 == 0x43) {
                if ((local_40c & 0x830) == 0) {
                  local_40c = local_40c | 0x20;
                }
LAB_008a4205:
                wVar2 = *param_4;
                local_460 = (uint)(ushort)wVar2;
                local_424 = param_4 + 2;
                local_430 = 1;
                if ((local_40c & 0x20) == 0) {
                  local_408[0] = wVar2;
                }
                else {
                  local_43c = (char)wVar2;
                  local_43b = 0;
                  iVar7 = __mbtowc_l(local_408,&local_43c,
                                     (size_t)(local_45c.locinfo)->locale_name[3],&local_45c);
                  if (iVar7 < 0) {
                    local_44c = 1;
                  }
                }
                local_418 = 1;
                local_414 = local_408;
                goto LAB_008a46bf;
              }
              if ((local_420 != 0x45) && (local_420 != 0x47)) goto LAB_008a46bf;
            }
            local_420 = local_420 + 0x20;
            local_46c = 1;
LAB_008a40f3:
            local_40c = local_40c | 0x40;
            local_418 = 0x200;
            pwVar10 = local_408;
            sVar11 = local_418;
            pwVar12 = local_408;
            if ((int)local_410 < 0) {
              local_410 = 6;
            }
            else if (local_410 == 0) {
              if ((short)local_420 == 0x67) {
                local_410 = 1;
              }
            }
            else {
              if (0x200 < (int)local_410) {
                local_410 = 0x200;
              }
              if (0xa3 < (int)local_410) {
                sVar11 = local_410 + 0x15d;
                local_414 = local_408;
                local_440 = __malloc_crt(sVar11);
                pwVar10 = local_440;
                pwVar12 = local_440;
                if (local_440 == (wchar_t *)0x0) {
                  local_410 = 0xa3;
                  pwVar10 = local_408;
                  sVar11 = local_418;
                  pwVar12 = local_414;
                }
              }
            }
            local_414 = pwVar12;
            local_418 = sVar11;
            local_474 = *(uint *)param_4;
            local_424 = param_4 + 4;
            local_470 = *(uint *)(param_4 + 2);
            plVar17 = &local_45c;
            iVar7 = (int)(char)local_420;
            puVar15 = &local_474;
            pwVar12 = pwVar10;
            sVar11 = local_418;
            uVar6 = local_410;
            uVar16 = local_46c;
            pcVar8 = DecodePointer(PTR_LAB_00d629c0);
            (*pcVar8)(puVar15,pwVar12,sVar11,iVar7,uVar6,uVar16,plVar17);
            uVar6 = local_40c & 0x80;
            if ((uVar6 != 0) && (local_410 == 0)) {
              plVar17 = &local_45c;
              pwVar12 = pwVar10;
              pcVar8 = DecodePointer(PTR_LAB_00d629cc);
              (*pcVar8)(pwVar12,plVar17);
            }
            if (((short)local_420 == 0x67) && (uVar6 == 0)) {
              plVar17 = &local_45c;
              pwVar12 = pwVar10;
              pcVar8 = DecodePointer(PTR_LAB_00d629c8);
              (*pcVar8)(pwVar12,plVar17);
            }
            pwVar12 = pwVar10;
            pwVar4 = local_414;
            if ((byte)*pwVar10 == 0x2d) {
              local_40c = local_40c | 0x100;
              pwVar12 = (wchar_t *)((int)pwVar10 + 1);
              pwVar4 = (wchar_t *)((int)pwVar10 + 1);
            }
LAB_008a42de:
            local_414 = pwVar4;
            local_418 = _strlen((char *)pwVar12);
          }
          else {
            if (local_420 == 0x58) goto LAB_008a44e2;
            if (local_420 == 0x5a) {
              psVar3 = *(short **)param_4;
              local_424 = param_4 + 2;
              pwVar12 = (wchar_t *)PTR_DAT_00d62090;
              pwVar4 = (wchar_t *)PTR_DAT_00d62090;
              if ((psVar3 == (short *)0x0) ||
                 (local_414 = *(wchar_t **)(psVar3 + 2), pwVar4 = (wchar_t *)PTR_DAT_00d62090,
                 local_414 == (wchar_t *)0x0)) goto LAB_008a42de;
              local_418 = (size_t)*psVar3;
              if ((local_40c & 0x800) != 0) {
                iVar7 = local_418 - ((int)local_418 >> 0x1f);
                goto LAB_008a46b7;
              }
              local_430 = 0;
            }
            else {
              if (local_420 == 0x61) goto LAB_008a40f3;
              if (local_420 == 99) goto LAB_008a4205;
            }
          }
LAB_008a46bf:
          if (local_44c == 0) {
            if ((local_40c & 0x40) != 0) {
              if ((local_40c & 0x100) == 0) {
                if ((local_40c & 1) == 0) {
                  if ((local_40c & 2) == 0) goto LAB_008a4701;
                  local_438 = 0x20;
                }
                else {
                  local_438 = 0x2b;
                }
              }
              else {
                local_438 = 0x2d;
              }
              local_42c = 1;
            }
LAB_008a4701:
            uVar6 = (local_434 - local_418) - local_42c;
            local_420 = uVar6;
            if ((local_40c & 0xc) == 0) {
              do {
                if ((int)uVar6 < 1) break;
                uVar6 = uVar6 - 1;
                write_char(0x20);
              } while (local_41c != -1);
            }
            FUN_008a491c(&local_438,local_42c);
            if (((local_40c & 8) != 0) && (uVar6 = local_420, (local_40c & 4) == 0)) {
              do {
                if ((int)uVar6 < 1) break;
                write_char(0x30);
                uVar6 = uVar6 - 1;
              } while (local_41c != -1);
            }
            if ((local_430 == 0) && (sVar11 = local_418, pwVar12 = local_414, 0 < (int)local_418)) {
              do {
                sVar11 = sVar11 - 1;
                iVar7 = __mbtowc_l((wchar_t *)&local_460,(char *)pwVar12,
                                   (size_t)(local_45c.locinfo)->locale_name[3],&local_45c);
                if (iVar7 < 1) {
                  local_41c = -1;
                  break;
                }
                write_char(local_460);
                pwVar12 = (wchar_t *)((int)pwVar12 + iVar7);
              } while (0 < (int)sVar11);
            }
            else {
              FUN_008a491c(local_414,local_418);
            }
            if ((-1 < local_41c) && (uVar6 = local_420, (local_40c & 4) != 0)) {
              do {
                if ((int)uVar6 < 1) break;
                write_char(0x20);
                uVar6 = uVar6 - 1;
              } while (local_41c != -1);
            }
          }
        }
        else {
          if (0x70 < local_420) {
            if (local_420 == 0x73) {
LAB_008a415c:
              uVar6 = local_410;
              if (local_410 == 0xffffffff) {
                uVar6 = 0x7fffffff;
              }
              local_424 = param_4 + 2;
              local_414 = *(wchar_t **)param_4;
              if ((local_40c & 0x20) == 0) {
                pwVar12 = local_414;
                if (local_414 == (wchar_t *)0x0) {
                  pwVar12 = (wchar_t *)PTR_u__null__00d62094;
                  local_414 = (wchar_t *)PTR_u__null__00d62094;
                }
                for (; (uVar6 != 0 && (uVar6 = uVar6 - 1, *pwVar12 != L'\0')); pwVar12 = pwVar12 + 1
                    ) {
                }
                iVar7 = (int)pwVar12 - (int)local_414;
LAB_008a46b7:
                local_424 = param_4 + 2;
                local_430 = 1;
                local_418 = iVar7 >> 1;
              }
              else {
                if (local_414 == (wchar_t *)0x0) {
                  local_414 = (wchar_t *)PTR_DAT_00d62090;
                }
                local_418 = 0;
                pwVar12 = local_414;
                if (0 < (int)uVar6) {
                  do {
                    if ((byte)*pwVar12 == 0) break;
                    iVar7 = __isleadbyte_l((uint)(byte)*pwVar12,&local_45c);
                    if (iVar7 != 0) {
                      pwVar12 = (wchar_t *)((int)pwVar12 + 1);
                    }
                    pwVar12 = (wchar_t *)((int)pwVar12 + 1);
                    local_418 = local_418 + 1;
                  } while ((int)local_418 < (int)uVar6);
                }
              }
              goto LAB_008a46bf;
            }
            if (local_420 == 0x75) goto LAB_008a4387;
            if (local_420 != 0x78) goto LAB_008a46bf;
            local_448 = 0x27;
LAB_008a450e:
            local_420 = 0x10;
            if ((local_40c & 0x80) != 0) {
              local_438 = 0x30;
              local_436 = (short)local_448 + 0x51;
              local_42c = 2;
            }
            goto LAB_008a4391;
          }
          if (local_420 == 0x70) {
            local_410 = 8;
LAB_008a44e2:
            local_448 = 7;
            goto LAB_008a450e;
          }
          if (local_420 < 0x65) goto LAB_008a46bf;
          if (local_420 < 0x68) goto LAB_008a40f3;
          if (local_420 == 0x69) goto LAB_008a4380;
          if (local_420 != 0x6e) {
            if (local_420 != 0x6f) goto LAB_008a46bf;
            local_420 = 8;
            if ((local_40c & 0x80) != 0) {
              local_40c = local_40c | 0x200;
            }
            goto LAB_008a4391;
          }
          piVar5 = *(int **)param_4;
          local_424 = param_4 + 2;
          iVar7 = FUN_0089317c();
          if (iVar7 == 0) {
            piVar5 = __errno();
            *piVar5 = 0x16;
            FUN_00893343();
            goto LAB_008a3de4;
          }
          if ((local_40c & 0x20) == 0) {
            *piVar5 = local_41c;
          }
          else {
            *(undefined2 *)piVar5 = (undefined2)local_41c;
          }
          local_44c = 1;
        }
        if (local_440 != (wchar_t *)0x0) {
          _free(local_440);
          local_440 = (wchar_t *)0x0;
        }
      }
      iVar7 = local_464;
      param_2 = local_444;
      param_4 = local_424;
      uVar1 = *local_444;
    }
    if (local_450 != '\0') {
      *(uint *)(local_454 + 0x70) = *(uint *)(local_454 + 0x70) & 0xfffffffd;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

