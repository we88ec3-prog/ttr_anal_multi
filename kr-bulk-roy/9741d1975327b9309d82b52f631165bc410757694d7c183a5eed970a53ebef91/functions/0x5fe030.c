
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fe030(int param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  DWORD DVar3;
  int *piVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  undefined1 uVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  undefined8 uVar11;
  undefined1 auStack_10a4 [4];
  int *local_10a0;
  undefined1 local_109a [2];
  uint local_1098;
  int local_1094;
  int *local_1090;
  int *local_108c;
  int *local_1088;
  int local_1080;
  int local_107c;
  undefined1 *local_1078;
  undefined1 *local_1074;
  undefined1 *local_1070;
  int local_1068 [6];
  undefined1 local_1050;
  uint local_1048;
  uint local_1044;
  int local_1040;
  int local_103c;
  char *local_1038;
  undefined **local_1034 [3];
  undefined4 local_1028;
  int local_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093e935;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_10a4;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffef50;
  ExceptionList = &local_14;
  local_1080 = in_ECX;
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  DVar3 = timeGetTime();
  if (DVar3 - _DAT_00fb1310 < 0x1f5) goto LAB_005fe718;
  local_1078 = (undefined1 *)0x0;
  local_1074 = (undefined1 *)0x0;
  local_1070 = (undefined1 *)0x0;
  local_1090 = (int *)0x0;
  local_108c = (int *)0x0;
  local_1088 = (int *)0x0;
  local_c = 1;
  _DAT_00fb1310 = DVar3;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c._0_1_ = 2;
    local_c._1_3_ = 0;
    FUN_004e1590(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = CONCAT31(local_c._1_3_,1);
  }
  if (*(int *)(in_ECX + 0x118) == 0) {
    local_1098 = DAT_00f94300 + 0x16f8;
    if (local_1098 == 0) goto LAB_005fe151;
    local_10a0 = *(int **)(DAT_00f94300 + 0x2398);
  }
  else {
    local_1098 = 0;
LAB_005fe151:
    local_10a0 = (int *)0x0;
  }
  uVar2 = local_1098;
  local_1068[0] = 0;
  local_1068[1] = 0;
  local_1068[2] = 0;
  local_1068[3] = 0;
  local_1068[4] = 0;
  local_1068[5] = 0;
  local_1050 = 0;
  FUN_005feb50();
  if (local_108c != (int *)0x0) {
    piVar4 = local_1068;
    piVar9 = local_108c;
    for (iVar5 = 8; uVar2 = local_1098, in_ECX = local_1080, iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar9 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar9 = piVar9 + 1;
    }
  }
  local_1098 = (int)local_10a0 + 1;
  piVar4 = local_108c + 8;
  local_1094 = 1;
  if (1 < (int)local_1098) {
    piVar9 = (int *)(uVar2 + 0x28);
    do {
      local_10a0 = piVar9;
      local_108c = piVar4;
      if (local_1094 - 1U < 100) {
        if ((piVar9[1] == 0) || (*piVar9 == 0)) goto LAB_005fe1ea;
        piVar8 = piVar9 + -2;
      }
      else {
        FUN_006edb60(&DAT_00c0ddc0);
LAB_005fe1ea:
        piVar8 = (int *)0x0;
      }
      if (piVar8 == (int *)0x0) {
        local_1068[0] = 0;
        local_1068[1] = 0;
        local_1068[2] = 0;
        local_1068[3] = 0;
        local_1068[4] = 0;
        local_1068[5] = 0;
        local_1050 = 0;
        piVar8 = local_1068;
      }
      if ((piVar8 < piVar4) && (local_1090 <= piVar8)) {
        uVar2 = (int)piVar8 - (int)local_1090;
        if (piVar4 == local_1088) {
          FUN_005feb50();
          piVar4 = local_108c;
        }
        piVar8 = (int *)((uVar2 & 0xffffffe0) + (int)local_1090);
      }
      else if (piVar4 == local_1088) {
        FUN_005feb50();
        piVar4 = local_108c;
      }
      if (piVar4 != (int *)0x0) {
        piVar10 = piVar4;
        for (iVar5 = 8; piVar9 = local_10a0, iVar5 != 0; iVar5 = iVar5 + -1) {
          *piVar10 = *piVar8;
          piVar8 = piVar8 + 1;
          piVar10 = piVar10 + 1;
        }
      }
      local_1094 = local_1094 + 1;
      piVar4 = piVar4 + 8;
      piVar9 = piVar9 + 8;
      in_ECX = local_1080;
      local_10a0 = piVar9;
    } while (local_1094 < (int)local_1098);
  }
  uVar2 = (int)piVar4 - (int)local_1090 >> 5;
  local_1044 = *(uint *)(in_ECX + 0x18c + param_1 * 8);
  local_1048 = *(uint *)(in_ECX + 0x188 + param_1 * 8);
  local_107c = 1;
  local_1094 = 1;
  local_1098 = uVar2;
  local_108c = piVar4;
  if (1 < (int)uVar2) {
    piVar4 = local_1090 + 8;
    local_10a0 = piVar4;
    do {
      if (piVar4[3] != 0) {
        if ((DAT_00f8d9a8 & 1) == 0) {
          DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
          local_c._0_1_ = 3;
          DAT_00f8d9b4 = 0;
          iVar5 = FUN_00891268(0x18);
          if (iVar5 == 0) {
            local_1038 = (char *)0x0;
            std::exception::exception((exception *)local_1034,&local_1038);
            local_1034[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(local_1034,&DAT_00c857a8);
          }
          DAT_00f8d9b0 = iVar5;
          *(int *)iVar5 = iVar5;
          *(int *)(DAT_00f8d9b0 + 4) = DAT_00f8d9b0;
          *(int *)(DAT_00f8d9b0 + 8) = DAT_00f8d9b0;
          *(undefined1 *)(DAT_00f8d9b0 + 0x14) = 1;
          *(undefined1 *)(DAT_00f8d9b0 + 0x15) = 1;
          local_c._0_1_ = 4;
          FUN_00521080(&DAT_00f8d9bc);
          _atexit((_func_4879 *)&LAB_00bccc50);
          local_c = CONCAT31(local_c._1_3_,1);
        }
        local_103c = piVar4[1];
        FUN_008438c0(&local_103c);
        if (((local_1040 != DAT_00f8d9b0) && (*(int *)(local_1040 + 0x10) != 0)) &&
           (uVar11 = __allshl(),
           ((uint)uVar11 & local_1048) != 0 || ((uint)((ulonglong)uVar11 >> 0x20) & local_1044) != 0
           )) {
          if (local_107c != local_1094) {
            local_109a[0] = (undefined1)local_1094;
            local_109a[1] = (undefined1)local_107c;
            FUN_00523480();
            piVar9 = local_10a0;
            piVar8 = local_1068;
            for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
              *piVar8 = *piVar9;
              piVar9 = piVar9 + 1;
              piVar8 = piVar8 + 1;
            }
            piVar9 = piVar4;
            piVar8 = local_10a0;
            for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
              *piVar8 = *piVar9;
              piVar9 = piVar9 + 1;
              piVar8 = piVar8 + 1;
            }
            piVar9 = local_1068;
            piVar8 = piVar4;
            for (iVar5 = 8; uVar2 = local_1098, iVar5 != 0; iVar5 = iVar5 + -1) {
              *piVar8 = *piVar9;
              piVar9 = piVar9 + 1;
              piVar8 = piVar8 + 1;
            }
          }
          local_107c = local_107c + 1;
          local_10a0 = local_10a0 + 8;
        }
      }
      local_1094 = local_1094 + 1;
      piVar4 = piVar4 + 8;
    } while (local_1094 < (int)uVar2);
  }
  local_1094 = 1;
  if (1 < (int)uVar2) {
    local_10a0 = local_1090 + 8;
    do {
      if (local_10a0[3] == 0) {
        if ((int)local_1098 <= local_1094 + 1) break;
        piVar4 = local_1090 + local_1098 * 8 + 3;
        uVar2 = local_1098;
        while( true ) {
          piVar4 = piVar4 + -8;
          uVar2 = uVar2 - 1;
          if (*piVar4 != 0) break;
          if ((int)uVar2 <= local_1094 + 1) goto LAB_005fe468;
        }
        piVar4 = local_1090 + uVar2 * 8;
        piVar9 = local_10a0;
        for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
          *piVar9 = *piVar4;
          piVar4 = piVar4 + 1;
          piVar9 = piVar9 + 1;
        }
        local_1068[0] = 0;
        local_1068[1] = 0;
        local_1068[2] = 0;
        local_1068[3] = 0;
        local_1068[4] = 0;
        local_1068[5] = 0;
        local_1050 = 0;
        piVar4 = local_1068;
        piVar9 = local_1090 + uVar2 * 8;
        for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
          *piVar9 = *piVar4;
          piVar4 = piVar4 + 1;
          piVar9 = piVar9 + 1;
        }
        uVar7 = (undefined1)uVar2;
        local_109a[1] = (undefined1)local_1094;
        local_109a[0] = uVar7;
        if ((local_109a < local_1074) && (local_1078 <= local_109a)) {
          iVar5 = (int)local_109a - (int)local_1078 >> 1;
          if (local_1074 == local_1070) {
            uVar2 = (int)local_1074 - (int)local_1078 >> 1;
            if (0x7ffffffe < uVar2) {
LAB_005fe691:
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            uVar2 = uVar2 + 1;
            uVar6 = (int)local_1070 - (int)local_1078 >> 1;
            if (uVar6 < uVar2) {
              if (0x7fffffff - (uVar6 >> 1) < uVar6) {
                uVar6 = 0;
              }
              else {
                uVar6 = uVar6 + (uVar6 >> 1);
              }
              if (uVar6 < uVar2) {
                uVar6 = uVar2;
              }
              FUN_005235d0(uVar6);
            }
          }
          if (local_1074 != (undefined1 *)0x0) {
            *local_1074 = local_1078[iVar5 * 2];
            local_1074[1] = local_1078[iVar5 * 2 + 1];
          }
        }
        else {
          if (local_1074 == local_1070) {
            uVar2 = (int)local_1074 - (int)local_1078 >> 1;
            if (0x7ffffffe < uVar2) goto LAB_005fe691;
            uVar2 = uVar2 + 1;
            uVar6 = (int)local_1070 - (int)local_1078 >> 1;
            if (uVar6 < uVar2) {
              if (0x7fffffff - (uVar6 >> 1) < uVar6) {
                uVar6 = 0;
              }
              else {
                uVar6 = uVar6 + (uVar6 >> 1);
              }
              if (uVar6 < uVar2) {
                uVar6 = uVar2;
              }
              FUN_005235d0(uVar6);
            }
          }
          if (local_1074 != (undefined1 *)0x0) {
            *local_1074 = uVar7;
            local_1074[1] = (char)local_1094;
          }
        }
        local_1074 = local_1074 + 2;
      }
      local_10a0 = local_10a0 + 8;
      local_1094 = local_1094 + 1;
    } while (local_1094 < (int)local_1098);
  }
LAB_005fe468:
  puVar1 = local_1078;
  if (local_1078 == local_1074) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c._0_1_ = 5;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = CONCAT31(local_c._1_3_,1);
    }
    FUN_0058aad0(0xf4365);
  }
  else {
    local_1098 = 0xdc;
    iVar5 = 4;
    local_1028 = CONCAT13(*(char *)(local_1080 + 0x118) + '\x01',0xdc);
    uVar2 = 0;
    uVar6 = (int)local_1074 - (int)local_1078 >> 1;
    local_28 = 4;
    if (uVar6 != 0) {
      do {
        local_1098 = (uint)CONCAT12(local_1078[uVar2 * 2 + 1],(ushort)(byte)local_1078[uVar2 * 2]);
        if (iVar5 + 4U < 0x1001) {
          *(uint *)((int)&local_1028 + iVar5) = local_1098;
          iVar5 = local_28 + 4;
          local_28 = iVar5;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar6);
    }
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_1028,iVar5);
  }
  iVar5 = **(int **)(local_1080 + 0x104);
  *(uint *)(iVar5 + 0x108) = local_1048;
  *(uint *)(iVar5 + 0x10c) = local_1044;
  if (local_1090 != (int *)0x0) {
    FUN_0089120c(local_1090);
  }
  if (puVar1 != (undefined1 *)0x0) {
    FUN_0089120c(puVar1);
  }
LAB_005fe718:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_10a4);
  return;
}

