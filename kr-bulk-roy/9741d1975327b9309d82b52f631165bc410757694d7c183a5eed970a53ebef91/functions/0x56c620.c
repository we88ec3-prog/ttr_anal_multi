
void FUN_0056c620(void)

{
  short sVar1;
  wchar_t wVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined3 uVar5;
  uint uVar6;
  short *psVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int iVar10;
  wchar_t *pwVar11;
  undefined4 *in_ECX;
  short *in_EDX;
  rsize_t _MaxCount;
  int iVar12;
  undefined1 auStack_874 [4];
  undefined4 *puStack_870;
  int iStack_86c;
  undefined4 *puStack_868;
  uint uStack_864;
  int *piStack_860;
  int *piStack_85c;
  int *piStack_858;
  undefined4 *puStack_850;
  undefined4 *puStack_84c;
  undefined4 uStack_848;
  undefined4 *puStack_840;
  undefined4 uStack_83c;
  undefined4 uStack_82c;
  uint uStack_828;
  wchar_t wStack_820;
  undefined1 auStack_81e [2050];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0092aee8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_874;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffff780;
  ExceptionList = &local_14;
  in_ECX[10] = 0;
  if (in_ECX[0x11] != 0) {
    FUN_0089120c(in_ECX[0x11],uVar6);
    in_ECX[0x11] = 0;
  }
  in_ECX[10] = 1;
  psVar7 = in_EDX;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(in_EDX,(int)psVar7 - (int)(in_EDX + 1) >> 1);
  uVar6 = in_ECX[4];
  uStack_864 = uVar6;
  uVar8 = FUN_0087dc3d(-(uint)((int)((ulonglong)uVar6 * 4 >> 0x20) != 0) |
                       (uint)((ulonglong)uVar6 * 4));
  in_ECX[0x11] = uVar8;
  puStack_850 = (undefined4 *)0x0;
  puStack_84c = (undefined4 *)0x0;
  uStack_848 = 0;
  piStack_860 = (int *)0x0;
  piStack_85c = (int *)0x0;
  piStack_858 = (int *)0x0;
  uStack_c._1_3_ = 0;
  uVar5 = uStack_c._1_3_;
  uStack_c._0_1_ = 1;
  uStack_c._1_3_ = 0;
  iStack_86c = 0;
  puStack_870 = (undefined4 *)0x0;
  if (0 < (int)uVar6) {
    puStack_840 = (undefined4 *)(uVar6 - 1);
    do {
      puVar9 = in_ECX;
      if (7 < (uint)in_ECX[5]) {
        puVar9 = (undefined4 *)*in_ECX;
      }
      if ((*(short *)((int)puVar9 + (int)puStack_870 * 2) == 10) || (puStack_870 == puStack_840)) {
        _MaxCount = ((int)puStack_870 - iStack_86c < 1) - 1 & (int)puStack_870 - iStack_86c;
        if (puStack_870 == puStack_840) {
          _MaxCount = _MaxCount + 1;
        }
        wStack_820 = L'\0';
        _memset(auStack_81e,0,0x7fe);
        iVar10 = FUN_004026d0();
        iVar12 = iStack_86c;
        _wcsncpy_s(&wStack_820,0x400,(wchar_t *)(iVar10 + iStack_86c * 2),_MaxCount);
        if ((&iStack_86c < piStack_85c) && (piStack_860 <= &iStack_86c)) {
          iVar12 = (int)&iStack_86c - (int)piStack_860;
          if (piStack_85c == piStack_858) {
            FUN_006d6240();
          }
          if (piStack_85c != (int *)0x0) {
            *piStack_85c = piStack_860[iVar12 >> 2];
          }
        }
        else {
          if (piStack_85c == piStack_858) {
            FUN_006d6240();
          }
          if (piStack_85c != (int *)0x0) {
            *piStack_85c = iVar12;
          }
        }
        piStack_85c = piStack_85c + 1;
        pwVar11 = &wStack_820;
        uStack_83c = (undefined4 *)((uint)uStack_83c._2_2_ << 0x10);
        uStack_828 = 7;
        uStack_82c = 0;
        do {
          wVar2 = *pwVar11;
          pwVar11 = pwVar11 + 1;
        } while (wVar2 != L'\0');
        FUN_00402160(&wStack_820,(int)pwVar11 - (int)auStack_81e >> 1);
        uStack_c._0_1_ = 2;
        FUN_00555920();
        uStack_c._0_1_ = 1;
        if (7 < uStack_828) {
          FUN_0089120c(uStack_83c);
        }
        iStack_86c = (int)puStack_870 + 1;
      }
      else {
        puVar9 = in_ECX;
        if (7 < (uint)in_ECX[5]) {
          puVar9 = (undefined4 *)*in_ECX;
        }
        puStack_868 = (undefined4 *)(uint)*(ushort *)((int)puVar9 + (int)puStack_870 * 2);
        if ((DAT_00fb7bc8 & 1) == 0) {
          DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
          uStack_c._0_1_ = 3;
          FUN_00734ef0();
          _atexit((_func_4879 *)&LAB_00bcd4f0);
          uStack_c._0_1_ = 1;
        }
        uVar8 = in_ECX[0x10];
        FUN_0073ce20();
        uStack_c._0_1_ = 4;
        puVar9 = uStack_83c;
        if (uStack_828 < 8) {
          puVar9 = &uStack_83c;
        }
        FUN_00735620(&DAT_00fb7b70,uVar8,puVar9,0);
        uStack_c._0_1_ = 1;
        if (7 < uStack_828) {
          FUN_0089120c(uStack_83c);
        }
      }
      puStack_870 = (undefined4 *)((int)puStack_870 + 1);
      uVar5 = uStack_c._1_3_;
    } while ((int)puStack_870 < (int)uStack_864);
  }
  uStack_c._1_3_ = uVar5;
  uStack_864 = ((int)puStack_84c - (int)puStack_850) / 0x1c;
  uVar6 = 0;
  puVar9 = puStack_850;
  if (uStack_864 != 0) {
    do {
      iVar12 = piStack_860[uVar6];
      iVar10 = in_ECX[0x11];
      puStack_868 = puVar9;
      if (7 < (uint)puVar9[5]) {
        puStack_868 = (undefined4 *)*puVar9;
      }
      puStack_870 = puVar9;
      if ((DAT_00fb7bc8 & 1) == 0) {
        DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
        uStack_c._0_1_ = 5;
        FUN_00734ef0();
        _atexit((_func_4879 *)&LAB_00bcd4f0);
        uStack_c._0_1_ = 1;
      }
      (**(code **)(*DAT_00fb7b78 + 0x38))(in_ECX[0x10],puStack_868,0x400,iVar10 + iVar12 * 4,0);
      uVar6 = uVar6 + 1;
      puStack_870 = puStack_870 + 7;
      puVar9 = puStack_870;
    } while (uVar6 < uStack_864);
  }
  puVar9 = puStack_84c;
  in_ECX[0xd] = 0;
  in_ECX[0xf] = 0;
  if (piStack_860 != (int *)0x0) {
    FUN_0089120c(piStack_860);
  }
  puVar4 = puStack_850;
  puVar3 = puStack_850;
  if (puStack_850 != (undefined4 *)0x0) {
    for (; puVar3 != puVar9; puVar3 = puVar3 + 7) {
      if (7 < (uint)puVar3[5]) {
        FUN_0089120c(*puVar3);
      }
      puVar3[5] = 7;
      puVar3[4] = 0;
      *(undefined2 *)puVar3 = 0;
    }
    FUN_0089120c(puVar4);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_874);
  return;
}

