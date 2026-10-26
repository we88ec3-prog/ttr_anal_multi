
void FUN_004a6900(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  int *piVar8;
  undefined1 auStack_9c [4];
  undefined1 *local_98;
  __time32_t _Stack_94;
  int *piStack_90;
  int *piStack_8c;
  int local_88;
  int local_84;
  tm tStack_80;
  undefined4 uStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  uint auStack_40 [4];
  undefined4 uStack_30;
  uint uStack_2c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00940de2;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_9c;
  ExceptionList = &local_14;
  local_84 = in_ECX;
  if ((DAT_00fd93f4 & 1) == 0) {
    DAT_00fd93f4 = DAT_00fd93f4 | 1;
    local_98 = &stack0xffffff50;
    local_c = 0;
    FUN_00828c00();
    _atexit(FUN_00bcde40);
  }
  local_c = 0xffffffff;
  iVar5 = FUN_00828ad0();
  local_88 = iVar5;
  if (iVar5 == 0) goto LAB_004a7211;
  FUN_00757800();
  *(undefined4 *)(*(int *)(in_ECX + 0x15c) + 0x154) = *(undefined4 *)(iVar5 + 0x6c);
  (**(code **)(**(int **)(in_ECX + 0x15c) + 200))();
  uStack_5c = (uint)uStack_5c._2_2_ << 0x10;
  uStack_48 = 7;
  uStack_4c = 0;
  FUN_004026e0(iVar5 + 0x20,0);
  local_c._0_1_ = 1;
  local_c._1_3_ = 0;
  if (*(int *)(iVar5 + 0x70) == 1) {
    FUN_00402160(&DAT_00c06288);
  }
  if ((DAT_00fd93f4 & 1) == 0) {
    DAT_00fd93f4 = DAT_00fd93f4 | 1;
    local_98 = &stack0xffffff50;
    local_c._0_1_ = 2;
    FUN_00828c00();
    _atexit(FUN_00bcde40);
    local_c._0_1_ = 1;
  }
  piStack_90 = (int *)FUN_00828b30();
  iVar5 = piStack_90[1] - *piStack_90 >> 3;
  FUN_00404300(&DAT_00c06290);
  FUN_00404300(L"<#FFFF00>");
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c._0_1_ = 3;
    FUN_00584c40();
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c._0_1_ = 1;
  }
  _Stack_94 = 0x14e;
  FUN_005740f0();
  if (piStack_8c == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  piVar6 = piStack_8c + 4;
  piVar8 = piVar6;
  if (7 < (uint)piStack_8c[9]) {
    piVar6 = (int *)*piVar6;
    piVar8 = piVar6;
  }
  do {
    iVar3 = *piVar6;
    piVar6 = (int *)((int)piVar6 + 2);
  } while ((short)iVar3 != 0);
  FUN_00404300(piVar8);
  _Stack_94 = 0;
  if (0 < iVar5) {
    do {
      FUN_00404300(&DAT_00bfb894);
      piStack_8c = *(int **)(*piStack_90 + _Stack_94 * 8);
      FUN_005740f0();
      uVar7 = FUN_004a7240();
      local_c._0_1_ = 4;
      FUN_004041f0(uVar7,0);
      local_c._0_1_ = 1;
      if (7 < uStack_2c) {
        FUN_0089120c();
      }
      _Stack_94 = _Stack_94 + 1;
    } while (_Stack_94 < iVar5);
  }
  FUN_00404300(&DAT_00c06290);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c._0_1_ = 5;
    FUN_00584c40();
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c._0_1_ = 1;
  }
  local_98 = (undefined1 *)0x1bd;
  FUN_005740f0();
  if (piStack_90 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  piVar6 = piStack_90 + 4;
  piVar8 = piVar6;
  if (7 < (uint)piStack_90[9]) {
    piVar6 = (int *)*piVar6;
    piVar8 = piVar6;
  }
  do {
    iVar5 = *piVar6;
    piVar6 = (int *)((int)piVar6 + 2);
  } while ((short)iVar5 != 0);
  FUN_00404300(piVar8);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c._0_1_ = 6;
    FUN_00584c40();
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c._0_1_ = 1;
  }
  local_98 = (undefined1 *)0x14d;
  FUN_005740f0();
  if (piStack_90 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  piVar6 = piStack_90 + 4;
  piVar8 = piVar6;
  if (7 < (uint)piStack_90[9]) {
    piVar6 = (int *)*piVar6;
    piVar8 = piVar6;
  }
  do {
    iVar5 = *piVar6;
    piVar6 = (int *)((int)piVar6 + 2);
  } while ((short)iVar5 != 0);
  FUN_00404300(piVar8);
  FUN_00404300(&DAT_00bfb894);
  iVar5 = local_88;
  FUN_004041f0(local_88 + 0x3c,0);
  if (*(int *)(iVar5 + 0x5c) != 0) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c._0_1_ = 7;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c._0_1_ = 1;
    }
    iVar3 = DAT_00f93950;
    iVar5 = *(int *)(local_88 + 0x5c);
    FUN_00404300(&DAT_00c06290);
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 8;
      FUN_00584c40();
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_c._0_1_ = 1;
    }
    local_98 = (undefined1 *)0x194;
    FUN_005740f0();
    if (piStack_90 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    piVar6 = piStack_90 + 4;
    piVar8 = piVar6;
    if (7 < (uint)piStack_90[9]) {
      piVar6 = (int *)*piVar6;
      piVar8 = piVar6;
    }
    do {
      iVar4 = *piVar6;
      piVar6 = (int *)((int)piVar6 + 2);
    } while ((short)iVar4 != 0);
    FUN_00404300(piVar8);
    _Stack_94 = iVar5 - iVar3;
    __gmtime32_s(&tStack_80,&_Stack_94);
    bVar2 = true;
    if ((tStack_80.tm_yday != 0) || (tStack_80.tm_year != 0x46 && -1 < tStack_80.tm_year + -0x46)) {
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_c._0_1_ = 9;
        FUN_00584c40();
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_c._0_1_ = 1;
      }
      local_98 = (undefined1 *)0x34;
      FUN_005740f0();
      if (piStack_90 == DAT_00fe5ac8) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      uVar7 = FUN_004068f0();
      local_c._0_1_ = 10;
      FUN_004041f0(uVar7,0);
      local_c._0_1_ = 1;
      if (7 < uStack_2c) {
        FUN_0089120c();
      }
      FUN_00404300(&DAT_00bf3a70);
      bVar2 = false;
    }
    if (tStack_80.tm_hour != 0) {
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_c._0_1_ = 0xb;
        FUN_00584c40();
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_c._0_1_ = 1;
      }
      local_98 = (undefined1 *)0x35;
      FUN_005740f0();
      if (piStack_90 == DAT_00fe5ac8) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      uVar7 = FUN_004068f0();
      local_c._0_1_ = 0xc;
      FUN_004041f0(uVar7,0);
      local_c._0_1_ = 1;
      if (7 < uStack_2c) {
        FUN_0089120c();
      }
      FUN_00404300(&DAT_00bf3a70);
      bVar2 = false;
    }
    if (tStack_80.tm_min == 0) {
      if (!bVar2) goto LAB_004a716c;
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_c._0_1_ = 0xf;
        FUN_00584c40();
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_c._0_1_ = 1;
      }
      local_98 = (undefined1 *)0x37;
      FUN_005740f0();
      if (piStack_90 == DAT_00fe5ac8) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      uVar7 = FUN_004068f0();
      local_c._0_1_ = 0x10;
      FUN_004041f0(uVar7,0);
    }
    else {
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_c._0_1_ = 0xd;
        FUN_00584c40();
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_c._0_1_ = 1;
      }
      local_98 = (undefined1 *)0x36;
      FUN_005740f0();
      if (piStack_90 == DAT_00fe5ac8) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      uVar7 = FUN_004068f0();
      local_c._0_1_ = 0xe;
      FUN_004041f0(uVar7,0);
    }
    local_c._0_1_ = 1;
    if (7 < uStack_2c) {
      local_c._0_1_ = 1;
      FUN_0089120c();
    }
  }
LAB_004a716c:
  uStack_2c = 7;
  uStack_30 = 0;
  auStack_40[0] = auStack_40[0] & 0xffff0000;
  FUN_004026e0(&uStack_5c,0);
  iVar5 = *(int *)(local_84 + 0x160);
  local_c._0_1_ = 0x11;
  FUN_007578f0();
  FUN_00759ed0(iVar5 + 0xe8,auStack_40,0x7b);
  local_c = CONCAT31(local_c._1_3_,1);
  if (7 < uStack_2c) {
    FUN_0089120c();
  }
  (**(code **)(**(int **)(local_84 + 0x160) + 200))();
  FUN_004a7450();
  if (7 < uStack_48) {
    FUN_0089120c();
  }
LAB_004a7211:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_9c);
  return;
}

