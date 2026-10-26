
void FUN_007fd3d0(int *param_1)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  char *pcVar6;
  LPCSTR ***lpText;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  char *pcVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined4 in_stack_00000034;
  undefined4 auStack_120 [7];
  undefined4 uStack_104;
  undefined4 local_b0 [11];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  uint local_78;
  int local_74;
  int local_6c;
  int local_68;
  int *local_64;
  uint local_60;
  uint local_4c;
  undefined4 local_44 [4];
  LPCSTR **local_34 [4];
  int local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009345e2;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_7c = in_stack_00000034;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
  }
  local_8 = 0xffffffff;
  local_84 = DAT_00fb76a8;
  iVar3 = (**(code **)(*param_1 + 4))();
  iVar3 = *(int *)(iVar3 + 4);
  if (iVar3 == -0x5eed0000) {
    iVar3 = param_1[0xf];
    iVar12 = 0;
    if (0 < iVar3) {
      do {
        piVar4 = (int *)FUN_007800e0();
        if ((piVar4 != (int *)0x0) && ((**(code **)(*piVar4 + 0x1c))(), 0 < local_68))
        goto LAB_007fd897;
        iVar12 = iVar12 + 1;
      } while (iVar12 < iVar3);
    }
    FUN_0077ef30();
    FUN_0077e910();
    local_60 = 0;
    if (0 < (int)(param_1[0x37] - param_1[0x36] & 0xfffffffcU)) {
      do {
        if (local_60 < (uint)(param_1[0x37] - param_1[0x36] >> 2)) {
          uVar8 = *(undefined4 *)(param_1[0x36] + local_60 * 4);
        }
        else {
          uVar8 = 0;
        }
        puVar11 = local_44;
        puVar13 = auStack_120;
        for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar13 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar13 = puVar13 + 1;
        }
        FUN_007fd3d0(uVar8);
        local_60 = local_60 + 1;
      } while ((int)local_60 < param_1[0x37] - param_1[0x36] >> 2);
    }
    local_60 = 0;
    iVar3 = (**(code **)(*param_1 + 0x34))();
    if (iVar3 != 0) {
      do {
        pcVar2 = *(code **)(*param_1 + 0x30);
        puVar11 = local_44;
        puVar13 = auStack_120;
        for (iVar3 = 0xb; uVar5 = local_60, iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar13 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar13 = puVar13 + 1;
        }
        uVar9 = local_60;
        uVar8 = (*pcVar2)(local_60);
        FUN_007fd3d0(uVar8,uVar9);
        local_60 = uVar5 + 1;
        uVar9 = (**(code **)(*param_1 + 0x34))();
      } while (uVar5 + 1 < uVar9);
    }
  }
  else if (((iVar3 != -0x5edf0000) && (iVar3 == -0x5edc0000)) && (param_1[0x1c] == 0)) {
    iVar3 = param_1[0xf];
    iVar12 = 0;
    if (0 < iVar3) {
      do {
        piVar4 = (int *)FUN_007800e0();
        if ((piVar4 != (int *)0x0) && ((**(code **)(*piVar4 + 0x1c))(), 0 < local_68))
        goto LAB_007fd897;
        iVar12 = iVar12 + 1;
      } while (iVar12 < iVar3);
    }
    if ((int *)param_1[0x1d] != (int *)0x0) {
      local_60 = (**(code **)(*(int *)param_1[0x1d] + 0x38))();
      if (local_60 == 0) {
        local_60 = 1;
      }
      local_74 = 0;
      if (0 < (int)local_60) {
        do {
          iVar3 = local_74;
          if ((int *)param_1[0x1d] == (int *)0x0) goto LAB_007fd897;
          iVar12 = (**(code **)(*(int *)param_1[0x1d] + 0x24))();
          if (iVar12 == 0) {
            if (iVar3 != 0) goto LAB_007fd897;
            iVar3 = param_1[0x1d];
          }
          else {
            iVar12 = (**(code **)(*(int *)param_1[0x1d] + 0x38))();
            if (iVar12 <= iVar3) goto LAB_007fd897;
            iVar3 = (**(code **)(*(int *)param_1[0x1d] + 0x28))();
          }
          if (iVar3 == 0) goto LAB_007fd897;
          iVar3 = FUN_00840100();
          local_80 = 0x1b;
          FUN_008438c0();
          if ((local_78 != *(uint *)(iVar3 + 4)) && (*(int *)(local_78 + 0x10) != 0))
          goto LAB_007fd897;
          local_6c = 0;
          local_68 = 0;
          FUN_007c5f40();
          uVar9 = local_68 - local_6c >> 0x1f;
          uVar5 = local_68 - local_6c ^ uVar9;
          if (uVar5 != uVar9 && -1 < (int)(uVar5 - uVar9)) goto LAB_007fd897;
          local_74 = local_74 + 1;
        } while (local_74 < (int)local_60);
      }
      iVar3 = param_1[0x1e];
      if (iVar3 != 0) {
        local_64 = (int *)0x0;
        if ((DAT_00fb79e8 & 1) == 0) {
          DAT_00fb79e8 = DAT_00fb79e8 | 1;
          local_8 = 2;
          FUN_00798de0();
          _atexit((_func_4879 *)&LAB_00bcd2e0);
          local_8 = 0xffffffff;
        }
        FUN_0079a5f0();
        iVar12 = FUN_008629e0();
        if (iVar12 == 0) {
          local_20 = 0xf;
          local_34[0] = (LPCSTR **)((uint)local_34[0] & 0xffffff00);
          local_24 = iVar12;
          FUN_00402a70();
          local_8 = 3;
          FUN_00401ed0();
          pcVar10 = (char *)(iVar3 + 8);
          pcVar6 = pcVar10;
          if (0xf < *(uint *)(iVar3 + 0x1c)) {
            pcVar6 = *(char **)pcVar10;
          }
          if (pcVar6 != (char *)0x0) {
            FUN_00401fc0();
            if (0xf < *(uint *)(iVar3 + 0x1c)) {
              pcVar10 = *(char **)pcVar10;
            }
            do {
              cVar1 = *pcVar10;
              pcVar10 = pcVar10 + 1;
            } while (cVar1 != '\0');
            FUN_00401fc0();
          }
          lpText = (LPCSTR ***)local_34[0];
          if (local_20 < 0x10) {
            lpText = local_34;
          }
          uStack_104 = 0x7fd6ce;
          MessageBoxA((HWND)0x0,(LPCSTR)lpText,"StaticMesh Conversion Error",0);
          if (0xf < local_20) {
            FUN_0089120c();
          }
        }
        else {
          piVar4 = *(int **)(iVar3 + 0x44);
          if (piVar4 != (int *)0x0) {
            (**(code **)(*local_64 + 0x34))();
            if (local_64 != (int *)0x0) {
              (**(code **)(*local_64 + 8))();
              local_64 = (int *)0x0;
            }
            iVar3 = piVar4[1];
            iVar12 = *piVar4;
            iVar7 = FUN_007b89e0();
            if ((local_4c / local_78 < *(uint *)(iVar7 + 0x2c)) &&
               (iVar7 = FUN_007b89e0(),
               (uint)(((iVar3 - iVar12) / 0x14) * 3) < *(uint *)(iVar7 + 0x30))) {
              puVar11 = (undefined4 *)&stack0x00000008;
              puVar13 = local_b0;
              for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
                *puVar13 = *puVar11;
                puVar11 = puVar11 + 1;
                puVar13 = puVar13 + 1;
              }
              FUN_007fdbd0();
            }
          }
        }
      }
    }
  }
LAB_007fd897:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

