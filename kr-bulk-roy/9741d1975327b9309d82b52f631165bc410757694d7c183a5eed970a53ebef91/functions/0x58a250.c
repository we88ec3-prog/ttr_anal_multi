
void FUN_0058a250(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  HWND pHVar3;
  int iVar4;
  undefined4 *puVar5;
  int extraout_EDX;
  int extraout_EDX_00;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int aiStack_154 [59];
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  char *local_44;
  tagPOINT local_40;
  undefined **appuStack_34 [4];
  undefined4 uStack_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093f9da;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (param_1[6] != -1) {
    if ((((char *)param_1[5] != (char *)0xffffffff) &&
        (iVar2 = param_1[0xb], local_44 = (char *)param_1[5], FUN_0082ef00(),
        (undefined4 *)local_40.x != *(undefined4 **)(iVar2 + 8))) &&
       (piVar6 = *(int **)(local_40.x + 0x10), piVar6 != (int *)0x0)) {
      (**(code **)(*piVar6 + 0x174))();
      FUN_00746c10();
      FUN_00746b80();
      FUN_00404aa0();
      FUN_0074e9d0();
      FUN_00761060();
      FUN_00746780();
      (**(code **)(*piVar6 + 0x10c))();
      iVar2 = FUN_00404aa0();
      if (*(int *)(iVar2 + 0x13c4) != 0) {
        FUN_007486f0();
        *(undefined4 *)(extraout_EDX + 0x13c4) = 0;
      }
      (**(code **)(*piVar6 + 0x17c))();
    }
    if ((((undefined4 *)param_1[6] != (undefined4 *)0xffffffff) &&
        (iVar2 = param_1[0xb], local_40.x = (LONG)param_1[6], FUN_0082ef00(),
        local_44 != *(char **)(iVar2 + 8))) &&
       (piVar6 = *(int **)(local_44 + 0x10), piVar6 != (int *)0x0)) {
      (**(code **)(*piVar6 + 0x170))();
      iVar2 = FUN_00404aa0();
      if (*(int **)(iVar2 + 0x13c4) != piVar6) {
        if (*(int **)(iVar2 + 0x13c4) != (int *)0x0) {
          FUN_007486f0();
        }
        FUN_007486f0();
        *(int **)(extraout_EDX_00 + 0x13c4) = piVar6;
      }
      (**(code **)(*piVar6 + 0x108))();
      FUN_00404aa0();
      FUN_0074e9d0();
      local_40.x = *(int *)(param_1[9] + 0xa0);
      uStack_64 = 0;
      uStack_60 = 0;
      uStack_24 = 0;
      uStack_68 = 0x58a3f0;
      (**(code **)(*piVar6 + 0xbc))();
      uStack_68 = 0x58a3f7;
      FUN_00746bd0();
      uStack_68 = 0x58a3fe;
      FUN_00746b30();
      uStack_68 = 0x58a40a;
      (**(code **)(*piVar6 + 0x178))();
      uStack_68 = 0x58a416;
      (**(code **)(*piVar6 + 200))();
      FUN_00404aa0();
      FUN_00753780();
    }
    param_1[5] = param_1[6];
    param_1[6] = -1;
    if ((int *)param_1[0xe] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0xe] + 0x20))();
    }
  }
  pHVar3 = GetForegroundWindow();
  if (pHVar3 == (HWND)*param_1) {
    GetCursorPos(&local_40);
    uStack_60 = 0x58a45e;
    ScreenToClient((HWND)*param_1,&local_40);
    iVar2 = DAT_00fba80c;
    param_1[0x4f] = local_40.x;
    param_1[0x50] = local_40.y;
    if (iVar2 == 0) {
      iVar2 = FUN_00891268();
      if (iVar2 == 0) {
        DAT_00fba80c = 0;
      }
      else {
        DAT_00fba80c = FUN_006f1370();
      }
    }
    iVar2 = FUN_006f1bc0();
    param_1[0x51] = *(int *)(iVar2 + 8);
  }
  iVar7 = 0;
  iVar2 = DAT_00fba80c;
  do {
    if ((DAT_00fb131c & 1) == 0) {
      DAT_00fb131c = DAT_00fb131c | 1;
      uStack_c = 0;
      FUN_00570ec0();
      _atexit((_func_4879 *)&LAB_00bccf50);
      uStack_c = 0xffffffff;
      iVar2 = DAT_00fba80c;
    }
    if (DAT_00fb132c == 0) {
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        uStack_c = 1;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        uStack_c = 0xffffffff;
        iVar2 = DAT_00fba80c;
      }
      if (DAT_00f942a4 == '\0') goto LAB_0058a580;
      if (iVar2 == 0) {
        iVar2 = FUN_00891268();
        if (iVar2 == 0) {
          iVar2 = 0;
          DAT_00fba80c = iVar2;
        }
        else {
          iVar2 = FUN_006f1370();
          DAT_00fba80c = iVar2;
        }
      }
      iVar4 = iVar2 + 0x260;
      if (*(int *)(iVar2 + 0x20) != 0) {
        iVar4 = iVar2 + 0x60;
      }
      *(bool *)((int)param_1 + iVar7 + 0x3c) = *(char *)(iVar4 + iVar7) != '\0';
    }
    else {
LAB_0058a580:
      *(undefined1 *)((int)param_1 + iVar7 + 0x3c) = 0;
    }
    iVar7 = iVar7 + 1;
    if (0xff < iVar7) {
      if ((DAT_00fb131c & 1) == 0) {
        DAT_00fb131c = DAT_00fb131c | 1;
        uStack_c = 2;
        FUN_00570ec0();
        _atexit((_func_4879 *)&LAB_00bccf50);
        uStack_c = 0xffffffff;
      }
      if (DAT_00fb132c != 0) {
        local_40.y = 0;
        puVar5 = (undefined4 *)FUN_00891268();
        if (puVar5 == (undefined4 *)0x0) {
          local_44 = (char *)0x0;
          std::exception::exception((exception *)appuStack_34,&local_44);
          appuStack_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          uStack_60 = 0x58a7b8;
          __CxxThrowException_8();
        }
        *puVar5 = puVar5;
        puVar5[1] = puVar5;
        uStack_c = 3;
        uStack_60 = 0x58a60c;
        local_40.x = (LONG)puVar5;
        FUN_006d4a30();
        param_1[0x4f] = 0;
        param_1[0x50] = 0;
        param_1[0x51] = 0;
        *(undefined2 *)(param_1 + 0x52) = 0;
        *(undefined1 *)((int)param_1 + 0x14a) = 0;
        uStack_c = 0xffffffff;
        puVar1 = (undefined4 *)*puVar5;
        *puVar5 = puVar5;
        puVar5[1] = puVar5;
        while (puVar1 != puVar5) {
          puVar1 = (undefined4 *)*puVar1;
          FUN_0089120c();
        }
        FUN_0089120c();
      }
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        uStack_c = 4;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        uStack_c = 0xffffffff;
      }
      if (DAT_00f942a4 == '\0') {
        *(undefined1 *)(param_1 + 0x52) = 0;
        *(undefined1 *)((int)param_1 + 0x14b) = 0;
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        uStack_c = 5;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
        uStack_c = 0xffffffff;
      }
      iVar2 = param_1[0x50];
      piVar6 = param_1 + 0xf;
      piVar8 = aiStack_154;
      for (iVar7 = 0x40; iVar7 != 0; iVar7 = iVar7 + -1) {
        *piVar8 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar8 = piVar8 + 1;
      }
      FUN_00750550(0x3d088889,param_1[0x4f],iVar2,param_1[0x51],param_1[0x52],param_1[0x53]);
      *(undefined2 *)((int)param_1 + 0x14b) = 0;
      *(undefined1 *)((int)param_1 + 0x14d) = 0;
      FUN_0058b5c0();
      if (*(char *)((int)param_1 + 0x22) != '\0') {
        if ((DAT_00fb7c14 & 1) == 0) {
          DAT_00fb7c14 = DAT_00fb7c14 | 1;
          uStack_c = 6;
          FUN_006d0750();
          _atexit((_func_4879 *)&LAB_00bcd530);
        }
        DAT_00fb8830 = DAT_00fb8830 | 8;
        ExceptionList = local_14;
        return;
      }
      if ((DAT_00fb7c14 & 1) == 0) {
        DAT_00fb7c14 = DAT_00fb7c14 | 1;
        uStack_c = 7;
        FUN_006d0750();
        _atexit((_func_4879 *)&LAB_00bcd530);
      }
      DAT_00fb8830 = DAT_00fb8830 & 0xfffffff7;
      ExceptionList = local_14;
      return;
    }
  } while( true );
}

