
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00490fe0(int *param_1)

{
  int iVar1;
  code *pcVar2;
  undefined *puVar3;
  int *piVar4;
  char cVar5;
  SHORT SVar6;
  uint uVar7;
  int iVar8;
  DWORD DVar9;
  int iVar10;
  LPCWSTR lpText;
  HWND pHVar11;
  DWORD DVar12;
  undefined4 uVar13;
  int *piVar14;
  int *piVar15;
  LPCWSTR lpCaption;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  undefined1 auStack_354 [4];
  int *local_350;
  int local_34c;
  int *local_348;
  int *local_344;
  _SYSTEMTIME _Stack_340;
  undefined1 auStack_330 [264];
  undefined1 auStack_228 [524];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009498d0;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_354;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffca0;
  ExceptionList = &local_14;
  local_344 = param_1;
  if (DAT_00fba858 == (undefined *)0x0) {
    if (DAT_00fba85c == 0) {
      FUN_0049b000(uVar7);
    }
    else {
      FUN_0049af60();
    }
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)(DAT_00fba858 + 0x34));
  if (DAT_00fba858 == (undefined *)0x0) {
    if (DAT_00fba85c == 0) {
      FUN_0049b000(uVar7);
    }
    else {
      FUN_0049af60();
    }
  }
  piVar15 = *(int **)(DAT_00fba858 + 0x28);
  local_350 = (int *)*piVar15;
  local_348 = piVar15;
  if (local_350 != piVar15) {
    do {
      iVar10 = local_350[2];
      if (*(int *)(iVar10 + 0xa0ac) == 0) {
        local_350 = (int *)*local_350;
      }
      else {
        DAT_00fdf704 = DAT_00fdf704 + 1;
        FUN_00893164("[%d] Disconnected.\n",DAT_00fdf704);
        if (local_344[0x2fd6] == iVar10) {
          if ((DAT_00fbacd0 & 1) == 0) {
            DAT_00fbacd0 = DAT_00fbacd0 | 1;
            local_c = 0;
            DAT_00fbacd4 = (int *)0x0;
            DAT_00fbacd4 = (int *)FUN_006d6300();
            _atexit((_func_4879 *)&LAB_00bcd670);
            local_c = 0xffffffff;
          }
          if (DAT_00fbacd4 != (int *)0x0) {
            (**(code **)(*DAT_00fbacd4 + 0x10))(1);
          }
        }
        if (DAT_00fba858 == (undefined *)0x0) {
          if (DAT_00fba85c == 0) {
            if ((DAT_00fc1200 & 1) == 0) {
              DAT_00fc1200 = DAT_00fc1200 | 1;
              local_c = 1;
              FUN_00805460(&DAT_00fc1208);
              _atexit((_func_4879 *)&LAB_00bce670);
              local_c = 0xffffffff;
            }
            DAT_00fba858 = &DAT_00fc1208;
          }
          else {
            FUN_0049af60();
          }
        }
        puVar3 = DAT_00fba858;
        *(int *)(DAT_00fba858 + 0x44) = *(int *)(DAT_00fba858 + 0x44) + -1;
        iVar1 = *(int *)(puVar3 + 0x48);
        local_34c = iVar10;
        iVar8 = FUN_0074d700(iVar1,*(undefined4 *)(iVar1 + 4),&local_34c);
        if (*(int *)(puVar3 + 0x4c) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("list<T> too long");
        }
        *(int *)(puVar3 + 0x4c) = *(int *)(puVar3 + 0x4c) + 1;
        *(int *)(iVar1 + 4) = iVar8;
        **(int **)(iVar8 + 4) = iVar8;
        *(undefined4 *)(iVar10 + 0x14) = 0;
        local_350 = (int *)*local_350;
        piVar15 = local_348;
      }
    } while (local_350 != piVar15);
  }
  if (DAT_00fba858 == (undefined *)0x0) {
    if (DAT_00fba85c == 0) {
      FUN_0049b000(uVar7);
    }
    else {
      FUN_0049af60();
    }
  }
  FUN_00805b40(DAT_00fba858);
  if (DAT_00fba858 == (undefined *)0x0) {
    if (DAT_00fba85c == 0) {
      FUN_0049b000();
    }
    else {
      FUN_0049af60();
    }
  }
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(DAT_00fba858 + 0x34));
  _DAT_00f7dd78 = _DAT_00f7dd78 + -1;
  if (_DAT_00f7dd78 == 0) {
    _fflush(DAT_00fba804);
    _DAT_00f7dd78 = 0x78;
  }
  if ((_DAT_00fd8bf8 & 1) == 0) {
    _DAT_00fd8bf8 = _DAT_00fd8bf8 | 1;
    _DAT_00fd8bfc = 0;
    _atexit((_func_4879 *)&DAT_00bce310);
  }
  DVar12 = _DAT_00fd8bfc;
  if ((DAT_00fd8c00 != 0) &&
     (DVar9 = timeGetTime(), DVar12 = _DAT_00fd8bfc, 59999 < DVar9 - _DAT_00fd8bfc)) {
    local_350 = (int *)CONCAT22(local_350._2_2_,0xa7);
    DVar12 = DVar9;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_350,2);
    }
  }
  _DAT_00fd8bfc = DVar12;
  local_34c = 0;
  if ((DAT_00fc0fc0 & 1) == 0) {
    DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
    local_c = 2;
    FUN_006d8e50();
    _atexit((_func_4879 *)&LAB_00bcdbb0);
    local_c = 0xffffffff;
  }
  FUN_006d9f00();
  if ((_DAT_00fc1698 & 1) == 0) {
    _DAT_00fc1698 = _DAT_00fc1698 | 1;
    FUN_0080c8a0();
    _atexit((_func_4879 *)&LAB_00bce320);
  }
  FUN_0080ca10();
  if ((DAT_00fdf6f4 & 1) == 0) {
    DAT_00fdf6f4 = DAT_00fdf6f4 | 1;
    local_c = 3;
    FUN_0049b490();
    local_c = 0xffffffff;
  }
  if ((_DAT_00fe48d8 & 1) == 0) {
    _DAT_00fe48d8 = _DAT_00fe48d8 | 1;
    FUN_0049b310();
  }
  FUN_0049b390();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 4;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  DAT_00f9423c = timeGetTime();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 5;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  FUN_004e1c60();
  if (DAT_00fba80c == 0) {
    iVar10 = FUN_00891268(0x57c);
    if (iVar10 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  FUN_006f16b0(DAT_00fba80c);
  if ((DAT_00fc1a70 & 1) == 0) {
    DAT_00fc1a70 = DAT_00fc1a70 | 1;
    local_c = 6;
    FUN_006cfc50();
    local_c = 0xffffffff;
  }
  FUN_006cfcf0(&DAT_00fc1a78);
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_c = 7;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
    local_c = 0xffffffff;
  }
  FUN_006d1480();
  if ((DAT_00fdf3ec & 1) == 0) {
    DAT_00fdf3ec = DAT_00fdf3ec | 1;
    local_c = 8;
    FUN_006d1da0();
    _atexit((_func_4879 *)&LAB_00bce330);
    local_c = 0xffffffff;
  }
  FUN_006d3e70(&DAT_00fdf3f0);
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 9;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  FUN_0058a250(&DAT_00faadd8);
  FUN_00490d40();
  piVar15 = local_344;
  FUN_00490e20();
  if (DAT_00fba80c == 0) {
    iVar10 = FUN_00891268(0x57c);
    if (iVar10 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  if ((*(int *)(DAT_00fba80c + 0x20) != 0) && (*(char *)(DAT_00fba80c + 0x19b) == '\x01')) {
    if (*(char *)(DAT_00fba80c + 0x17d) != '\0') {
      if (*(char *)(DAT_00fba80c + 0x198) != '\0') {
        (**(code **)(*piVar15 + 0xc))(piVar15);
        (**(code **)(*piVar15 + 0x10))(piVar15);
        (**(code **)(*piVar15 + 4))(piVar15);
        (**(code **)(*piVar15 + 8))(piVar15);
        goto LAB_00491ff5;
      }
      if (((*(char *)(DAT_00fba80c + 0x17d) != '\0') &&
          (iVar10 = FUN_00443dc0(), *(int *)(iVar10 + 0x20) != 0)) &&
         (*(char *)(iVar10 + 0x18a) != '\0')) {
        iVar10 = FUN_00434740();
        FUN_007b31c0(*(undefined4 *)(iVar10 + 0x9c));
        iVar10 = FUN_00434740();
        FUN_007b3190(*(undefined4 *)(iVar10 + 0x9c));
        goto LAB_004916ba;
      }
    }
    if (DAT_00fba80c == 0) {
      iVar10 = FUN_00891268(0x57c);
      if (iVar10 == 0) {
        DAT_00fba80c = 0;
      }
      else {
        DAT_00fba80c = FUN_006f1370();
      }
    }
    if (((((*(int *)(DAT_00fba80c + 0x20) != 0) && (*(char *)(DAT_00fba80c + 0x17d) != '\0')) &&
         ((iVar10 = FUN_00443dc0(), *(int *)(iVar10 + 0x20) == 0 ||
          (*(char *)(iVar10 + 0x198) == '\0')))) &&
        ((iVar10 = FUN_00443dc0(), piVar15 = DAT_00fba7a4, *(int *)(iVar10 + 0x20) == 0 ||
         (*(char *)(iVar10 + 0x18a) == '\0')))) &&
       ((DAT_00fba7a4 != (int *)0x0 && (iVar10 = (**(code **)(*DAT_00fba7a4 + 0x20))(), iVar10 != 0)
        ))) {
      (**(code **)(*piVar15 + 0x20))();
      FUN_0040f060();
      iVar10 = FUN_004dfad0();
      if ((iVar10 != 0) && (1 < *(byte *)(iVar10 + 0x20))) {
        iVar10 = FUN_00489b90();
        *(int *)(iVar10 + 8) = *(int *)(iVar10 + 8) + 1;
        if (3 < *(int *)(iVar10 + 8)) {
          *(undefined4 *)(iVar10 + 8) = 0;
        }
      }
    }
  }
LAB_004916ba:
  if (DAT_00fba80c == 0) {
    iVar10 = FUN_00891268(0x57c);
    if (iVar10 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  piVar15 = DAT_00fba7a4;
  if ((((*(int *)(DAT_00fba80c + 0x20) != 0) && (*(char *)(DAT_00fba80c + 0x19c) == '\x01')) &&
      (DAT_00fba7a4 != (int *)0x0)) && (iVar10 = (**(code **)(*DAT_00fba7a4 + 0x20))(), iVar10 != 0)
     ) {
    iVar10 = (**(code **)(*piVar15 + 0x20))();
    piVar15 = *(int **)(iVar10 + 0x9c);
    iVar10 = FUN_0040f060();
    local_348 = piVar15;
    FUN_008438c0(&local_348);
    if (((local_350 != *(int **)(iVar10 + 0x1c)) && (local_350[4] != 0)) &&
       (4 < *(byte *)(local_350[4] + 0x20))) {
      iVar10 = FUN_00404ba0();
      switch(*(undefined4 *)(iVar10 + 0x5f4c)) {
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 0x17:
      case 0x18:
        if (DAT_00fdf708 == 0) {
          DAT_00fba830 = 0;
          iVar10 = FUN_00489fe0();
          *(undefined4 *)(iVar10 + 0xbc) = 0;
          DAT_00fdf708 = 1;
        }
        else if (DAT_00fdf708 == 1) {
          iVar10 = FUN_00489f40();
          *(undefined4 *)(iVar10 + 0x4d4c) = 0;
          DAT_00fdf708 = 2;
        }
        else if (DAT_00fdf708 == 2) {
          iVar10 = FUN_00489f40();
          *(undefined4 *)(iVar10 + 0x4d4c) = 1;
          iVar10 = FUN_00489fe0();
          *(undefined4 *)(iVar10 + 0xbc) = 1;
          goto LAB_00491802;
        }
        break;
      default:
        iVar10 = FUN_00489f40();
        *(undefined4 *)(iVar10 + 0x4d4c) = 1;
LAB_00491802:
        DAT_00fba830 = 1;
        DAT_00fdf708 = 0;
      }
    }
  }
  SVar6 = GetAsyncKeyState(0x2c);
  if ((char)SVar6 != '\0') {
    GetLocalTime(&_Stack_340);
    CreateDirectoryW(L"ScreenShot",(LPSECURITY_ATTRIBUTES)0x0);
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 10;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    if (DAT_00fb9225 == '\x01') {
      FUN_00498ed0(L"ScreenShot/%d-%d-%d %d_%d_%d.bmp");
      local_350 = (int *)0x0;
      (**(code **)(*(int *)local_344[4] + 0x48))((int *)local_344[4],0,0,0,&local_350);
      D3DXSaveSurfaceToFileW(auStack_228,0,local_350,0,0);
    }
    else {
      FUN_00401d90("ScreenShot/%d-%d-%d %d_%d_%d.jpg",_Stack_340.wYear,_Stack_340.wMonth,
                   _Stack_340.wDay,_Stack_340.wHour,_Stack_340.wMinute,_Stack_340.wSecond);
      local_350 = (int *)0x0;
      (**(code **)(*(int *)local_344[4] + 0x48))((int *)local_344[4],0,0,0,&local_350);
      FUN_006d7840(auStack_330);
    }
    if (local_350 != (int *)0x0) {
      (**(code **)(*local_350 + 8))(local_350);
    }
  }
  if ((DAT_00fbacd0 & 1) == 0) {
    DAT_00fbacd0 = DAT_00fbacd0 | 1;
    local_c = 0xb;
    DAT_00fbacd4 = (int *)0x0;
    DAT_00fbacd4 = (int *)FUN_006d6300();
    _atexit((_func_4879 *)&LAB_00bcd670);
    local_c = 0xffffffff;
  }
  if (DAT_00fbacd4 != (int *)0x0) {
    (**(code **)(*DAT_00fbacd4 + 8))();
  }
  piVar4 = local_344;
  piVar15 = local_344 + 0x50;
  FUN_00804740(piVar15);
  if ((DAT_00fc10cc & 1) == 0) {
    DAT_00fc10cc = DAT_00fc10cc | 1;
    local_c = 0xc;
    FUN_00803ff0();
    _atexit((_func_4879 *)&LAB_00bcdc90);
    local_c = 0xffffffff;
  }
  iVar10 = *(int *)(&DAT_00fc1140 + (uint)DAT_00fc11fa * 0x18);
  if ((DAT_00fc10cc & 1) == 0) {
    DAT_00fc10cc = DAT_00fc10cc | 1;
    local_c = 0xd;
    FUN_00803ff0();
    _atexit((_func_4879 *)&LAB_00bcdc90);
    local_c = 0xffffffff;
  }
  if (piVar4[0x3008] != 0) {
    piVar4[0x301a] =
         piVar4[0x301a] + *(int *)(&DAT_00fc1140 + (uint)(DAT_00fc11fa == 0) * 0x18) + iVar10;
  }
  FUN_006daef0();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0xe;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (DAT_00f93934 < 5) {
    iVar10 = piVar4[0x2fda];
    if ((iVar10 != -1) && (DAT_00fba7ac != 0)) {
      if (iVar10 < 0x22) {
        piVar4[0x2fda] = 4000;
        local_350 = (int *)CONCAT22(local_350._2_2_,0x10);
        if (DAT_00fba798 == 0) {
          (**(code **)(*DAT_00fba854 + 0x10))(0,&local_350,2);
        }
        DVar12 = timeGetTime();
        piVar4[0x2fd9] = DVar12;
        iVar10 = FUN_00404ba0();
        *(int *)(iVar10 + 0x5f54) = *(int *)(iVar10 + 0x5f54) + 1;
      }
      else {
        piVar4[0x2fda] = iVar10 + -0x21;
      }
    }
    if (piVar4[0x2ff3] == 0) {
      FUN_0040f060();
      FUN_004e0060();
      uVar13 = FUN_00489c60();
      FUN_00489530(uVar13);
      piVar14 = (int *)FUN_00434130();
      if ((int *)*piVar14 != (int *)0x0) {
        (**(code **)(*(int *)*piVar14 + 0x14))();
      }
      iVar10 = FUN_00489cb0();
      if (*(int **)(iVar10 + 0x5eac) == (int *)0x0) {
        local_34c = 0;
      }
      else {
        local_34c = (**(code **)(**(int **)(iVar10 + 0x5eac) + 0x18))();
      }
      uVar13 = FUN_0049b140();
      FUN_00550ec0(uVar13);
    }
    if ((DAT_00fd94d8 & 1) == 0) {
      DAT_00fd94d8 = DAT_00fd94d8 | 1;
      local_c = 0x12;
      FUN_007b5430();
      _atexit((_func_4879 *)&LAB_00bce660);
      local_c = 0xffffffff;
    }
    FUN_007b6330(&DAT_00fd9420);
    if ((_DAT_00fd9408 & 1) == 0) {
      _DAT_00fd9408 = _DAT_00fd9408 | 1;
      DAT_00fd940c = 0;
      _DAT_00fd9410 = 0;
      DAT_00fd9414 = 0;
      _DAT_00fd9418 = 0.0;
    }
    else if (0 < DAT_00fd940c) {
      DAT_00fd940c = DAT_00fd940c + -1;
    }
    _DAT_00fd9418 = _DAT_00fd9418 + 0.39999598;
    if (6.0 <= _DAT_00fd9418) {
      _DAT_00fd9418 = 0.0;
    }
    if ((DAT_00fc1c80 & 1) == 0) {
      DAT_00fc1c80 = DAT_00fc1c80 | 1;
      local_c = 0x13;
      FUN_0056b690();
      _atexit((_func_4879 *)&LAB_00bce500);
      local_c = 0xffffffff;
    }
    FUN_0056b990(&DAT_00fc1c84);
    if ((DAT_00fc1ac0 & 1) == 0) {
      DAT_00fc1ac0 = DAT_00fc1ac0 | 1;
      local_c = 0x14;
      FUN_00558100();
      _atexit((_func_4879 *)&LAB_00bcdea0);
      local_c = 0xffffffff;
    }
    FUN_005582d0(&DAT_00fc1ac4);
    if ((DAT_00fb744c & 1) == 0) {
      DAT_00fb744c = DAT_00fb744c | 1;
      local_c = 0x15;
      FUN_004eec60();
      _atexit(FUN_00bcd140);
      local_c = 0xffffffff;
    }
    FUN_004eeb60();
    if (local_344[0x2ff3] == 0) {
      uVar13 = FUN_0048a1d0();
      FUN_0055af80(uVar13);
      uVar13 = FUN_00489fb0();
      FUN_0056cf10(uVar13);
      iVar10 = FUN_0043ffa0();
      *(int *)(iVar10 + 0x40) = *(int *)(iVar10 + 0x40) + 1;
      (**(code **)(**(int **)(iVar10 + 8) + 0x24))();
      if (0 < *(int *)(iVar10 + 0x3c)) {
        *(int *)(iVar10 + 0x3c) = *(int *)(iVar10 + 0x3c) + -1;
      }
      if (*(int *)(iVar10 + 0x3c) == 0) {
        *(undefined4 *)(iVar10 + 0x3c) = *(undefined4 *)(iVar10 + 0x50);
        FUN_00735530();
      }
      FUN_00422f40();
      FUN_00561520();
      FUN_0048a0b0();
      FUN_0055f9d0();
      FUN_0048a120();
      FUN_00581f70();
      if ((_DAT_00fd8f0c & 1) == 0) {
        _DAT_00fd8f0c = _DAT_00fd8f0c | 1;
        FUN_00559120();
        _atexit((_func_4879 *)&DAT_00bcdf60);
      }
      FUN_00559390();
      FUN_0048a190();
      FUN_005541e0();
      uVar13 = FUN_00422ed0();
      FUN_005537f0(uVar13);
      FUN_00414720();
      FUN_005714d0();
      FUN_00434740();
    }
    if ((DAT_00fb72a4 & 1) == 0) {
      DAT_00fb72a4 = DAT_00fb72a4 | 1;
      local_c = 0x16;
      FUN_0049f850();
      _atexit((_func_4879 *)&LAB_00bccfe0);
      local_c = 0xffffffff;
    }
    FUN_0049fa50(&DAT_00fb72a8);
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_c = 0x17;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_c = 0xffffffff;
    }
    FUN_0080b410(&DAT_00fab028);
    FUN_00425330();
    FUN_004f6b80();
    if ((char)piVar4[0x74] == '\0') {
      FUN_00804a40(piVar15);
    }
    else {
      FUN_00804c70();
    }
    FUN_00804fc0(piVar15);
  }
  else {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0xf;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    _DAT_00f93938 = 1;
    (**(code **)(*DAT_00fba854 + 0x20))(0,1);
    (**(code **)(*DAT_00fba854 + 0x20))(1,1);
    (**(code **)(*DAT_00fba854 + 0x20))(2,1);
    FUN_006deda0();
    FUN_006edd00(&DAT_00c05900);
    cVar5 = FUN_006ea3d0();
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 0x10;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_c = 0xffffffff;
    }
    local_348 = (int *)0x199;
    FUN_005740f0(&local_348);
    if (local_34c == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if (*(uint *)(local_34c + 0x24) < 8) {
      lpCaption = (LPCWSTR)(local_34c + 0x10);
    }
    else {
      lpCaption = *(LPCWSTR *)(local_34c + 0x10);
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 0x11;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_c = 0xffffffff;
    }
    local_348 = (int *)0x18d;
    FUN_005740f0(&local_348);
    if (local_34c == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    lpText = (LPCWSTR)(local_34c + 0x10);
    if (7 < *(uint *)(local_34c + 0x24)) {
      lpText = *(LPCWSTR *)lpText;
    }
    uVar7 = (cVar5 != '\0') - 1 & 0x40000;
    pHVar11 = (HWND)FUN_006dfd60();
    MessageBoxW(pHVar11,lpText,lpCaption,uVar7);
    lParam = 1;
    wParam = 0;
    Msg = 0x10;
    pHVar11 = (HWND)FUN_006dfd60();
    PostMessageW(pHVar11,Msg,wParam,lParam);
  }
LAB_00491ff5:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_354);
  return;
}

