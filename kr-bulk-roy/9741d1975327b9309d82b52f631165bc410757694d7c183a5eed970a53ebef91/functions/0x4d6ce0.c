
void FUN_004d6ce0(undefined4 param_1)

{
  wchar_t wVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  wchar_t *****_Source;
  wchar_t *pwVar5;
  undefined4 uVar6;
  _locale_t plVar7;
  wchar_t *pwVar8;
  undefined4 *puVar9;
  int in_ECX;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int *piVar10;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  int local_ac;
  undefined4 local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  wchar_t ****local_8c [5];
  uint local_78;
  undefined1 auStack_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936994;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_ac;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff48;
  ExceptionList = &local_14;
  local_a8 = param_1;
  if ((*(char *)(in_ECX + 6) != '\x02') && (*(char *)(in_ECX + 6) != '\x03')) {
    pwVar5 = (wchar_t *)(in_ECX + 8);
    local_a4 = in_ECX;
    iVar3 = _wcsncmp(pwVar5,L"//",2);
    if (iVar3 == 0) {
      iVar3 = *(int *)(in_ECX + 2);
      iVar4 = FUN_0040f060();
      local_a0 = iVar3;
      FUN_008438c0(&local_a0);
      if (((local_ac == *(int *)(iVar4 + 0x1c)) || (*(int *)(local_ac + 0x10) == 0)) ||
         (*(byte *)(*(int *)(local_ac + 0x10) + 0x20) < 5)) {
        FUN_004d74c0(local_a8);
        if (local_78 < 8) {
          local_8c[0] = (wchar_t ****)local_8c;
        }
        _wcsncpy(pwVar5,(wchar_t *)local_8c[0],0x32);
        FUN_004fa440();
      }
    }
    else {
      FUN_004d74c0(param_1);
      _Source = (wchar_t *****)local_8c[0];
      if (local_78 < 8) {
        _Source = local_8c;
      }
      _wcsncpy(pwVar5,(wchar_t *)_Source,0x32);
      if (7 < local_78) {
        FUN_0089120c(local_8c[0],uVar2);
      }
    }
    pwVar5 = _wcsstr(pwVar5,L"/");
    while (pwVar5 != (wchar_t *)0x0) {
      local_ac = 0;
      if ((DAT_00fb72e8 & 1) == 0) {
        DAT_00fb72e8 = DAT_00fb72e8 | 1;
        DAT_00fb72ec = 0;
        DAT_00fb72f0 = 0;
        DAT_00fb72f4 = 0;
        local_c = 1;
        FUN_0049ef70();
        _atexit(FUN_00bccff0);
        local_c = 0xffffffff;
      }
      iVar3 = FUN_0049f420(pwVar5);
      if (iVar3 == 0) {
        if ((DAT_00fe1aa8 & 1) == 0) {
          DAT_00fe1aa8 = DAT_00fe1aa8 | 1;
          DAT_00fe1aac = 0;
          DAT_00fe1ab0 = 0;
          DAT_00fe1ab4 = 0;
          local_c = 5;
          FUN_004fcff0();
          _atexit((_func_4879 *)&LAB_00bcea20);
          local_c = 0xffffffff;
        }
        local_90 = FUN_004fd4b0(pwVar5);
        iVar3 = local_ac;
        if (local_90 != 0) {
          pwVar8 = pwVar5 + *(int *)(local_90 + 0x2c);
          iVar3 = (int)pwVar5 - (int)pwVar8;
          do {
            wVar1 = *pwVar8;
            *(wchar_t *)(iVar3 + (int)pwVar8) = wVar1;
            pwVar8 = pwVar8 + 1;
          } while (wVar1 != L'\0');
          if ((DAT_00fab22c & 1) == 0) {
            DAT_00fab22c = DAT_00fab22c | 1;
            local_c = 6;
            FUN_004dec90();
            _atexit((_func_4879 *)&LAB_00bcce30);
            local_c = 0xffffffff;
          }
          local_ac = *(int *)(local_a4 + 2);
          FUN_008438c0(&local_ac);
          if ((local_9c != DAT_00fab14c) &&
             (puVar9 = *(undefined4 **)(local_9c + 0x10), puVar9 != (undefined4 *)0x0)) {
            iVar3 = puVar9[1];
            if ((DAT_00fab22c & 1) == 0) {
              DAT_00fab22c = DAT_00fab22c | 1;
              local_c = 7;
              FUN_004dec90();
              _atexit((_func_4879 *)&LAB_00bcce30);
              local_c = 0xffffffff;
            }
            local_ac = iVar3;
            FUN_0082ef00(&local_ac);
            iVar3 = local_90;
            if (((local_98 != DAT_00fab13c) &&
                (piVar10 = *(int **)(local_98 + 0x10), piVar10 != (int *)0x0)) &&
               ((*(int *)(piVar10[0x56] + 8) == 1 &&
                ((**(code **)(*piVar10 + 0x68))(*(undefined4 *)(local_90 + 0x38),0x3f800000),
                *(int *)(iVar3 + 0x4c) != 0)))) {
              uVar6 = *puVar9;
              FUN_00425330(extraout_ECX_00,uVar6);
              uVar6 = FUN_004f6a30(uVar6);
              piVar10 = (int *)(iVar3 + 0x3c);
              if (7 < *(uint *)(iVar3 + 0x50)) {
                piVar10 = (int *)*piVar10;
              }
              FUN_004d6c70(piVar10,uVar6);
            }
          }
          iVar3 = 1;
        }
        plVar7 = __get_current_locale();
        iVar4 = __wcsnicmp_l(L"/a",pwVar5,2,plVar7);
        if (iVar4 == 0) {
          pwVar8 = pwVar5 + 2;
          iVar3 = (int)pwVar5 - (int)pwVar8;
          do {
            wVar1 = *pwVar8;
            *(wchar_t *)(iVar3 + (int)pwVar8) = wVar1;
            pwVar8 = pwVar8 + 1;
          } while (wVar1 != L'\0');
          FUN_0040f060();
          puVar9 = (undefined4 *)FUN_004dfad0();
          if (puVar9 == (undefined4 *)0x0) break;
          uVar6 = *puVar9;
          FUN_00425330(extraout_ECX_01,uVar6);
          FUN_004f6a30(uVar6);
          uVar6 = 0x77;
          FUN_005855b0(0x77);
          FUN_00585330(uVar6);
          puVar9 = (undefined4 *)FUN_004ed610();
          local_c = 8;
          if (7 < (uint)puVar9[5]) {
            puVar9 = (undefined4 *)*puVar9;
          }
          FUN_00402250(puVar9);
          local_c = CONCAT31(local_c._1_3_,9);
LAB_004d72a0:
          FUN_004d6b30(local_8c);
          FUN_004fa440();
        }
        else {
          plVar7 = __get_current_locale();
          iVar4 = __wcsnicmp_l(L"/b",pwVar5,2,plVar7);
          if (iVar4 == 0) {
            pwVar8 = pwVar5 + 2;
            iVar3 = (int)pwVar5 - (int)pwVar8;
            do {
              wVar1 = *pwVar8;
              *(wchar_t *)(iVar3 + (int)pwVar8) = wVar1;
              pwVar8 = pwVar8 + 1;
            } while (wVar1 != L'\0');
            FUN_0040f060();
            puVar9 = (undefined4 *)FUN_004dfad0();
            if (puVar9 == (undefined4 *)0x0) break;
            uVar6 = *puVar9;
            FUN_00425330(extraout_ECX_02,uVar6);
            FUN_004f6a30(uVar6);
            uVar6 = 0x78;
            FUN_005855b0(0x78);
            FUN_00585330(uVar6);
            puVar9 = (undefined4 *)FUN_004ed610();
            local_c = 10;
            if (7 < (uint)puVar9[5]) {
              puVar9 = (undefined4 *)*puVar9;
            }
            FUN_00402250(puVar9);
            local_c = CONCAT31(local_c._1_3_,0xb);
            goto LAB_004d72a0;
          }
          plVar7 = __get_current_locale();
          iVar4 = __wcsnicmp_l(L"/c",pwVar5,2,plVar7);
          if (iVar4 != 0) {
            if (iVar3 != 0) goto LAB_004d71ef;
            break;
          }
          pwVar8 = pwVar5 + 2;
          iVar3 = (int)pwVar5 - (int)pwVar8;
          do {
            wVar1 = *pwVar8;
            *(wchar_t *)(iVar3 + (int)pwVar8) = wVar1;
            pwVar8 = pwVar8 + 1;
          } while (wVar1 != L'\0');
          FUN_0040f060();
          puVar9 = (undefined4 *)FUN_004dfad0();
          if (puVar9 == (undefined4 *)0x0) break;
          uVar6 = *puVar9;
          FUN_00425330(extraout_ECX_03,uVar6);
          FUN_004f6a30(uVar6);
          uVar6 = 0x79;
          FUN_005855b0(0x79);
          FUN_00585330(uVar6);
          puVar9 = (undefined4 *)FUN_004ed610();
          local_c = 0xc;
          if (7 < (uint)puVar9[5]) {
            puVar9 = (undefined4 *)*puVar9;
          }
          FUN_00402250(puVar9);
          local_c = CONCAT31(local_c._1_3_,0xd);
          FUN_004d6b30(auStack_54);
          FUN_004fa440();
        }
        FUN_004fa440();
        break;
      }
      pwVar8 = pwVar5 + *(int *)(iVar3 + 0x10);
      iVar4 = (int)pwVar5 - (int)pwVar8;
      do {
        wVar1 = *pwVar8;
        *(wchar_t *)(iVar4 + (int)pwVar8) = wVar1;
        pwVar8 = pwVar8 + 1;
      } while (wVar1 != L'\0');
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        local_c = 2;
        FUN_004dec90();
        _atexit((_func_4879 *)&LAB_00bcce30);
        local_c = 0xffffffff;
      }
      local_ac = *(int *)(local_a4 + 2);
      FUN_008438c0(&local_ac);
      if ((local_a0 != DAT_00fab14c) &&
         (puVar9 = *(undefined4 **)(local_a0 + 0x10), puVar9 != (undefined4 *)0x0)) {
        iVar4 = puVar9[1];
        if ((DAT_00fab22c & 1) == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 3;
          FUN_004dec90();
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        local_ac = iVar4;
        FUN_0082ef00(&local_ac);
        if (((local_94 != DAT_00fab13c) && (*(int **)(local_94 + 0x10) != (int *)0x0)) &&
           ((**(code **)(**(int **)(local_94 + 0x10) + 0x6c))(*(undefined4 *)(iVar3 + 0x1c),0),
           *(int *)(iVar3 + 0x30) != 0)) {
          uVar6 = *puVar9;
          FUN_00425330(extraout_ECX,uVar6);
          uVar6 = FUN_004f6a30(uVar6);
          piVar10 = (int *)(iVar3 + 0x20);
          if (7 < *(uint *)(iVar3 + 0x34)) {
            piVar10 = (int *)*piVar10;
          }
          FUN_004d6c70(piVar10,uVar6);
        }
      }
LAB_004d71ef:
      pwVar5 = _wcsstr((wchar_t *)(local_a4 + 8),L"/");
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_ac);
  return;
}

