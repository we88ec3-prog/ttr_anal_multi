
void FUN_006bc330(int param_1)

{
  char cVar1;
  code *pcVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int **ppiVar6;
  undefined4 uVar7;
  wchar_t *_Str2;
  int iVar8;
  int *piVar9;
  wchar_t *_Str1;
  int *piVar10;
  undefined4 *puVar11;
  int *piStack_64;
  int *local_60;
  int *piStack_5c;
  int *local_58;
  undefined4 uStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 uStack_38;
  uint uStack_24;
  uint uStack_20;
  uint local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093bf72;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&piStack_64;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff90;
  ExceptionList = &local_14;
  local_60 = (int *)0x1;
  do {
    piVar10 = local_60;
    iVar8 = *(int *)(param_1 + 0xe8);
    piVar4 = (int *)FUN_004364c0(&local_60);
    (**(code **)(**(int **)(param_1 + 0x94 + (int)piVar10 * 4) + 0x90))(*piVar4 != iVar8,uVar3);
    local_60 = (int *)((int)piVar10 + 1);
  } while ((int)local_60 < 10);
  (**(code **)(**(int **)(param_1 + 0x90) + 200))();
  piVar10 = (int *)(*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4) >> 2);
  piStack_5c = (int *)(-0xc0 - param_1);
  local_60 = (int *)0x0;
  puVar11 = (undefined4 *)(param_1 + 0xc0);
  do {
    (**(code **)(*(int *)*puVar11 + 0x90))(local_60 < piVar10);
    if (piStack_64 < piVar10) {
      (**(code **)(*(int *)*puVar11 + 0x198))
                (*(undefined4 *)((int)local_60 + (int)puVar11 + *(int *)(param_1 + 0xf4)));
    }
    else {
      (**(code **)(*(int *)*puVar11 + 0x1a0))();
    }
    local_60 = (int *)((int)local_60 + 1);
    puVar11 = puVar11 + 1;
  } while (local_60 < (int *)0x5);
  piVar10 = *(int **)(param_1 + 0xbc);
  piVar4 = (int *)piVar10[0x19];
  piVar9 = (int *)*piVar4;
  piStack_5c = piVar4;
  if (piVar9 != piVar4) {
    do {
      iVar8 = piVar9[2];
      if ((*(int *)(iVar8 + 0x60) != 0) && ((*(int **)(iVar8 + 0x1c))[2] != 6)) {
        (**(code **)(**(int **)(iVar8 + 0x1c) + 0x30))(iVar8);
        piVar4 = piStack_5c;
      }
      piVar9 = (int *)*piVar9;
    } while (piVar9 != piVar4);
  }
  (**(code **)(*piVar10 + 0x128))();
  (**(code **)(**(int **)(param_1 + 0xbc) + 200))();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    uStack_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    uStack_c = 0xffffffff;
  }
  if (((*(uint *)(param_1 + 0xdc) < 10) &&
      (iVar5 = *(uint *)(param_1 + 0xdc) * 0x210, iVar8 = iVar5 + DAT_00f94304,
      *(int *)(iVar5 + 0x5c + DAT_00f94304) != 0)) && (iVar8 != 0)) {
    local_58 = *(int **)(iVar8 + 8);
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      uStack_c = 1;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      uStack_c = 0xffffffff;
    }
    cVar1 = *(char *)(DAT_00fe5ac8[1] + 0x2d);
    piVar10 = (int *)DAT_00fe5ac8[1];
    piStack_5c = DAT_00fe5ac8;
    while (piVar4 = piVar10, cVar1 == '\0') {
      if (piVar4[3] < 0x155) {
        piVar10 = (int *)piVar4[2];
        piVar4 = piStack_5c;
      }
      else {
        piVar10 = (int *)*piVar4;
      }
      cVar1 = *(char *)((int)piVar10 + 0x2d);
      piStack_5c = piVar4;
    }
    if ((piStack_5c == DAT_00fe5ac8) || (0x155 < piStack_5c[3])) {
      local_60 = DAT_00fe5ac8;
      ppiVar6 = &local_60;
    }
    else {
      ppiVar6 = &piStack_5c;
    }
    if (*ppiVar6 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    uVar7 = FUN_0067d6a0(iVar8 + 0xc);
    uStack_c = 2;
    FUN_00757800(uVar7);
    uStack_c = 0xffffffff;
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
    (**(code **)(**(int **)(param_1 + 0x84) + 200))();
  }
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    uStack_c = 3;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    uStack_c = 0xffffffff;
  }
  local_60 = *(int **)(param_1 + 0xdc);
  uStack_40 = 7;
  uStack_44 = 0;
  uStack_54 = (wchar_t *)((uint)uStack_54._2_2_ << 0x10);
  FUN_00402160(L"Scenario_Talk",0xd);
  local_58 = (int *)FUN_005c7610();
  if (local_58 != DAT_00f943a0) {
    _Str2 = (wchar_t *)(local_58 + 3);
    if (7 < (uint)local_58[8]) {
      _Str2 = *(wchar_t **)_Str2;
    }
    _Str1 = uStack_54;
    if (uStack_40 < 8) {
      _Str1 = (wchar_t *)&uStack_54;
    }
    iVar8 = __wcsicmp(_Str1,_Str2);
    if (iVar8 < 1) {
      ppiVar6 = &local_58;
      goto LAB_006bc6b1;
    }
  }
  piStack_5c = DAT_00f943a0;
  ppiVar6 = &piStack_5c;
LAB_006bc6b1:
  piVar10 = *ppiVar6;
  if (7 < uStack_40) {
    FUN_0089120c(uStack_54);
  }
  uStack_40 = 7;
  uStack_44 = 0;
  uStack_54 = (wchar_t *)((uint)uStack_54 & 0xffff0000);
  if ((piVar10 != DAT_00f943a0) && (iVar8 = piVar10[10], iVar8 != 0)) {
    piVar10 = *(int **)(iVar8 + 0xc);
    cVar1 = *(char *)(piVar10[1] + 0x15);
    local_58 = piVar10;
    piVar4 = (int *)piVar10[1];
    while (cVar1 == '\0') {
      if ((int *)piVar4[3] < local_60) {
        piVar9 = (int *)piVar4[2];
        piVar4 = local_58;
      }
      else {
        piVar9 = (int *)*piVar4;
      }
      local_58 = piVar4;
      piVar4 = piVar9;
      cVar1 = *(char *)((int)piVar9 + 0x15);
    }
    if ((local_58 == piVar10) || (local_60 < (int *)local_58[3])) {
      piStack_5c = piVar10;
    }
  }
  FUN_00745060();
  (**(code **)(**(int **)(param_1 + 0x80) + 200))();
  (**(code **)(**(int **)(param_1 + 0x88) + 0x90))
            (*(int *)(param_1 + 0xf4) != *(int *)(param_1 + 0xf8));
  ExceptionList = pvStack_18;
  __security_check_cookie(uStack_20 ^ (uint)&stack0xffffff98);
  return;
}

