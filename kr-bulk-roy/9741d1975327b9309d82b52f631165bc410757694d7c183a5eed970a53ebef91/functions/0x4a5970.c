
void FUN_004a5970(int param_1,char param_2)

{
  char cVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int *piVar9;
  int in_ECX;
  int iVar10;
  undefined4 *puVar11;
  undefined1 auStack_9c [4];
  int *piStack_98;
  int *piStack_94;
  int local_90;
  int *piStack_8c;
  int *piStack_88;
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
  uint uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00940ed4;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_9c;
  ExceptionList = &local_14;
  local_90 = param_1;
  local_84 = in_ECX;
  FUN_00757800();
  *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x154) = *(undefined4 *)(param_1 + 0x6c);
  (**(code **)(**(int **)(in_ECX + 0xf4) + 200))();
  uStack_5c = (uint)uStack_5c._2_2_ << 0x10;
  uStack_48 = 7;
  uStack_4c = 0;
  FUN_004026e0(param_1 + 0x20,0);
  uStack_c._0_1_ = 0;
  uStack_c._1_3_ = 0;
  if ((param_2 == '\0') && (*(int *)(param_1 + 0x70) == 1)) {
    FUN_00402160(&DAT_00c06288);
  }
  if ((DAT_00fd93f4 & 1) == 0) {
    DAT_00fd93f4 = DAT_00fd93f4 | 1;
    piStack_94 = (int *)&stack0xffffff50;
    uStack_c._0_1_ = 1;
    FUN_00828c00();
    _atexit(FUN_00bcde40);
    uStack_c._0_1_ = 0;
  }
  piStack_8c = (int *)FUN_00828b30();
  iVar10 = piStack_8c[1] - *piStack_8c >> 3;
  FUN_00404300(&DAT_00c06290);
  FUN_00404300(L"<#FFFF00>");
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    uStack_c._0_1_ = 2;
    FUN_00584c40();
    _atexit((_func_4879 *)&LAB_00bcf390);
    uStack_c._0_1_ = 0;
  }
  piStack_98 = (int *)0x14e;
  FUN_005740f0();
  if (piStack_88 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  piVar6 = piStack_88 + 4;
  piVar9 = piVar6;
  if (7 < (uint)piStack_88[9]) {
    piVar6 = (int *)*piVar6;
    piVar9 = piVar6;
  }
  do {
    iVar4 = *piVar6;
    piVar6 = (int *)((int)piVar6 + 2);
  } while ((short)iVar4 != 0);
  FUN_00404300(piVar9);
  piStack_98 = (int *)0x0;
  if (0 < iVar10) {
    do {
      FUN_00404300(&DAT_00bfb894);
      piStack_88 = *(int **)(*piStack_8c + (int)piStack_98 * 8);
      FUN_005740f0();
      uVar7 = FUN_004a7240();
      uStack_c._0_1_ = 3;
      FUN_004041f0(uVar7,0);
      uStack_c._0_1_ = 0;
      if (7 < uStack_2c) {
        FUN_0089120c();
      }
      piStack_98 = (int *)((int)piStack_98 + 1);
    } while ((int)piStack_98 < iVar10);
  }
  FUN_00404300(&DAT_00c06290);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    uStack_c._0_1_ = 4;
    FUN_00584c40();
    _atexit((_func_4879 *)&LAB_00bcf390);
    uStack_c._0_1_ = 0;
  }
  piStack_94 = (int *)0x1bd;
  FUN_005740f0();
  if (piStack_8c == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  piVar6 = piStack_8c + 4;
  piVar9 = piVar6;
  if (7 < (uint)piStack_8c[9]) {
    piVar6 = (int *)*piVar6;
    piVar9 = piVar6;
  }
  do {
    iVar10 = *piVar6;
    piVar6 = (int *)((int)piVar6 + 2);
  } while ((short)iVar10 != 0);
  FUN_00404300(piVar9);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    uStack_c._0_1_ = 5;
    FUN_00584c40();
    _atexit((_func_4879 *)&LAB_00bcf390);
    uStack_c._0_1_ = 0;
  }
  piStack_94 = (int *)0x14d;
  FUN_005740f0();
  if (piStack_8c == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  piVar6 = piStack_8c + 4;
  piVar9 = piVar6;
  if (7 < (uint)piStack_8c[9]) {
    piVar6 = (int *)*piVar6;
    piVar9 = piVar6;
  }
  do {
    iVar10 = *piVar6;
    piVar6 = (int *)((int)piVar6 + 2);
  } while ((short)iVar10 != 0);
  FUN_00404300(piVar9);
  FUN_00404300(&DAT_00bfb894);
  iVar10 = local_90;
  FUN_004041f0(local_90 + 0x3c,0);
  if (*(int *)(iVar10 + 0x5c) != 0) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      uStack_c._0_1_ = 6;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      uStack_c._0_1_ = 0;
    }
    iVar4 = DAT_00f93950;
    iVar10 = *(int *)(iVar10 + 0x5c);
    FUN_00404300(&DAT_00c06290);
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      uStack_c._0_1_ = 7;
      FUN_00584c40();
      _atexit((_func_4879 *)&LAB_00bcf390);
      uStack_c._0_1_ = 0;
    }
    local_90 = 0x194;
    FUN_005740f0();
    if (piStack_94 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    piVar6 = piStack_94 + 4;
    piVar9 = piVar6;
    if (7 < (uint)piStack_94[9]) {
      piVar6 = (int *)*piVar6;
      piVar9 = piVar6;
    }
    do {
      iVar5 = *piVar6;
      piVar6 = (int *)((int)piVar6 + 2);
    } while ((short)iVar5 != 0);
    FUN_00404300(piVar9);
    piStack_98 = (int *)(iVar10 - iVar4);
    __gmtime32_s(&tStack_80,(__time32_t *)&piStack_98);
    bVar3 = true;
    if ((tStack_80.tm_yday != 0) || (tStack_80.tm_year != 0x46 && -1 < tStack_80.tm_year + -0x46)) {
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        uStack_c._0_1_ = 8;
        FUN_00584c40();
        _atexit((_func_4879 *)&LAB_00bcf390);
        uStack_c._0_1_ = 0;
      }
      local_90 = 0x34;
      FUN_005740f0();
      if (piStack_94 == DAT_00fe5ac8) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      uVar7 = FUN_004068f0();
      uStack_c._0_1_ = 9;
      FUN_004041f0(uVar7,0);
      uStack_c._0_1_ = 0;
      if (7 < uStack_2c) {
        FUN_0089120c();
      }
      FUN_00404300(&DAT_00bf3a70);
      bVar3 = false;
    }
    if (tStack_80.tm_hour != 0) {
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        uStack_c._0_1_ = 10;
        FUN_00584c40();
        _atexit((_func_4879 *)&LAB_00bcf390);
        uStack_c._0_1_ = 0;
      }
      local_90 = 0x35;
      FUN_005740f0();
      if (piStack_94 == DAT_00fe5ac8) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      uVar7 = FUN_004068f0();
      uStack_c._0_1_ = 0xb;
      FUN_004041f0(uVar7,0);
      uStack_c._0_1_ = 0;
      if (7 < uStack_2c) {
        FUN_0089120c();
      }
      FUN_00404300(&DAT_00bf3a70);
      bVar3 = false;
    }
    if (tStack_80.tm_min == 0) {
      if (!bVar3) goto LAB_004a6182;
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        uStack_c._0_1_ = 0xe;
        FUN_00584c40();
        _atexit((_func_4879 *)&LAB_00bcf390);
        uStack_c._0_1_ = 0;
      }
      local_90 = 0x37;
      FUN_005740f0();
      if (piStack_94 == DAT_00fe5ac8) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      uVar7 = FUN_004068f0();
      uStack_c._0_1_ = 0xf;
      FUN_004041f0(uVar7,0);
    }
    else {
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        uStack_c._0_1_ = 0xc;
        FUN_00584c40();
        _atexit((_func_4879 *)&LAB_00bcf390);
        uStack_c._0_1_ = 0;
      }
      local_90 = 0x36;
      FUN_005740f0();
      if (piStack_94 == DAT_00fe5ac8) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      uVar7 = FUN_004068f0();
      uStack_c._0_1_ = 0xd;
      FUN_004041f0(uVar7,0);
    }
    uStack_c._0_1_ = 0;
    if (7 < uStack_2c) {
      uStack_c._0_1_ = 0;
      FUN_0089120c();
    }
  }
LAB_004a6182:
  auStack_40[0] = auStack_40[0] & 0xffff0000;
  uStack_2c = 7;
  uStack_30 = 0;
  FUN_004026e0(&uStack_5c,0);
  iVar10 = *(int *)(local_84 + 0xf8);
  puVar11 = (undefined4 *)(iVar10 + 0xe8);
  uStack_c = CONCAT31(uStack_c._1_3_,0x10);
  *(undefined4 *)(iVar10 + 0xf8) = 0;
  puVar8 = puVar11;
  if (7 < *(uint *)(iVar10 + 0xfc)) {
    puVar8 = (undefined4 *)*puVar11;
  }
  *(undefined2 *)puVar8 = 0;
  piVar6 = *(int **)(iVar10 + 0x104);
  piVar9 = (int *)*piVar6;
  *piVar6 = (int)piVar6;
  *(int *)(*(int *)(iVar10 + 0x104) + 4) = *(int *)(iVar10 + 0x104);
  *(undefined4 *)(iVar10 + 0x108) = 0;
  if (piVar9 != *(int **)(iVar10 + 0x104)) {
    do {
      piVar9 = (int *)*piVar9;
      FUN_0089120c();
    } while (piVar9 != (int *)*(int *)(iVar10 + 0x104));
  }
  piVar6 = *(int **)(*(int *)(iVar10 + 0x114) + 4);
  cVar1 = *(char *)((int)piVar6 + 0x21);
  while (piStack_98 = piVar6, cVar1 == '\0') {
    FUN_008575b0();
    piVar6 = (int *)*piVar6;
    FUN_0089120c();
    cVar1 = *(char *)((int)piVar6 + 0x21);
  }
  *(int *)(*(int *)(iVar10 + 0x114) + 4) = *(int *)(iVar10 + 0x114);
  *(undefined4 *)*(undefined4 *)(iVar10 + 0x114) = *(undefined4 *)(iVar10 + 0x114);
  *(int *)(*(int *)(iVar10 + 0x114) + 8) = *(int *)(iVar10 + 0x114);
  *(undefined4 *)(iVar10 + 0x118) = 0;
  FUN_00759ed0(puVar11,auStack_40,0x7b);
  uStack_c = uStack_c & 0xffffff00;
  if (7 < uStack_2c) {
    FUN_0089120c();
  }
  (**(code **)(**(int **)(local_84 + 0xf8) + 200))();
  if (7 < uStack_48) {
    FUN_0089120c();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_9c);
  return;
}

