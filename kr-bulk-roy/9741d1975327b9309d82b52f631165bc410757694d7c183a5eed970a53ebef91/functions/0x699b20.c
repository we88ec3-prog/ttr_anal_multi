
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00699b20(int param_1)

{
  undefined4 *puVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 **ppuVar9;
  undefined4 *puVar10;
  int iVar11;
  int *piVar12;
  undefined4 *puVar13;
  int *local_78;
  int local_70;
  int local_6c;
  undefined4 *local_68;
  undefined4 *local_64;
  char *local_60;
  char *local_5c;
  char *local_58;
  undefined **local_54 [3];
  undefined **local_48 [3];
  undefined **local_3c [3];
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined1 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093c969;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff78;
  ExceptionList = &local_14;
  if (*(int *)(param_1 + 0x110) != *(int *)(param_1 + 0x114)) {
    uVar5 = FUN_00606b70(*(int *)(param_1 + 0x114));
    *(undefined4 *)(param_1 + 0x114) = uVar5;
  }
  uVar3 = DAT_00f94390 & 1;
  *(undefined4 *)(param_1 + 0x124) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x128) = 0xffffffff;
  *(undefined4 *)(param_1 + 300) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x130) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x134) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x138) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x13c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x140) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x144) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x148) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x14c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x150) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x154) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x158) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x15c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x160) = 0xffffffff;
  if (uVar3 == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar4);
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (*(int *)(param_1 + 0x120) - 1U < 0xf) {
    iVar6 = *(int *)(param_1 + 0x120) * 0x108 + DAT_00f94300;
  }
  else {
    iVar6 = 0;
  }
  local_78 = (int *)(param_1 + 0x128);
  iVar11 = 1;
  piVar12 = (int *)(iVar6 + 0x18);
  do {
    if ((iVar11 < 3) || (5 < iVar11)) {
      if (iVar11 - 1U < 0xf) {
        if ((piVar12 != (int *)0x8) && (*piVar12 != 0)) {
          local_28 = *piVar12;
          local_30 = piVar12[-1];
          local_2c = piVar12[-2];
          local_24 = piVar12[1];
          *local_78 = (*(int *)(param_1 + 0x114) - *(int *)(param_1 + 0x110)) / 0x18;
          local_20 = 1;
          FUN_005f84f0();
        }
      }
      else {
        FUN_006edb60(&DAT_00c0dddc,iVar11);
      }
    }
    local_78 = local_78 + 1;
    iVar11 = iVar11 + 1;
    piVar12 = piVar12 + 4;
  } while (iVar11 < 0x10);
  local_78 = (int *)0x1;
  local_6c = 0xca8;
  puVar7 = DAT_00f8d9b0;
  do {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
      puVar7 = DAT_00f8d9b0;
    }
    if ((local_78 == (int *)0x1) &&
       (puVar1 = (undefined4 *)(local_6c + 0xa50 + DAT_00f94300), puVar1 != (undefined4 *)0x0)) {
      local_70 = 1;
      do {
        puVar13 = puVar1 + 8;
        if (local_70 - 1U < 100) {
          if ((((puVar1[0xb] != 0) && (puVar1[10] != 0)) && (puVar13 != (undefined4 *)0x0)) &&
             (puVar1[0xc] != 0)) {
            if ((DAT_00f8d9a8 & 1) == 0) {
              DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
              local_c = 2;
              DAT_00f8d9b4 = 0;
              puVar7 = (undefined4 *)FUN_00891268(0x18);
              if (puVar7 == (undefined4 *)0x0) {
                local_58 = (char *)0x0;
                std::exception::exception((exception *)local_3c,&local_58);
                local_3c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
                __CxxThrowException_8(local_3c,&DAT_00c857a8);
              }
              DAT_00f8d9b0 = puVar7;
              *puVar7 = puVar7;
              DAT_00f8d9b0[1] = DAT_00f8d9b0;
              DAT_00f8d9b0[2] = DAT_00f8d9b0;
              *(undefined1 *)(DAT_00f8d9b0 + 5) = 1;
              *(undefined1 *)((int)DAT_00f8d9b0 + 0x15) = 1;
              local_c._0_1_ = 3;
              local_68 = (undefined4 *)&DAT_00f8d9bc;
              _DAT_00f8d9c4 = 0;
              iVar6 = FUN_00891268(0x24);
              if (iVar6 == 0) {
                local_5c = (char *)0x0;
                std::exception::exception((exception *)local_48,&local_5c);
                local_48[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
                __CxxThrowException_8(local_48,&DAT_00c857a8);
              }
              DAT_00f8d9c0 = iVar6;
              *(int *)iVar6 = iVar6;
              *(int *)(DAT_00f8d9c0 + 4) = DAT_00f8d9c0;
              *(int *)(DAT_00f8d9c0 + 8) = DAT_00f8d9c0;
              *(undefined1 *)(DAT_00f8d9c0 + 0x20) = 1;
              *(undefined1 *)(DAT_00f8d9c0 + 0x21) = 1;
              local_c = CONCAT31(local_c._1_3_,4);
              _DAT_00f8d9d4 = 0;
              iVar6 = FUN_00891268(0x24);
              if (iVar6 == 0) {
                local_60 = (char *)0x0;
                std::exception::exception((exception *)local_54,&local_60);
                local_54[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
                __CxxThrowException_8(local_54,&DAT_00c857a8);
              }
              DAT_00f8d9d0 = iVar6;
              *(int *)iVar6 = iVar6;
              *(int *)(DAT_00f8d9d0 + 4) = DAT_00f8d9d0;
              *(int *)(DAT_00f8d9d0 + 8) = DAT_00f8d9d0;
              *(undefined1 *)(DAT_00f8d9d0 + 0x20) = 1;
              *(undefined1 *)(DAT_00f8d9d0 + 0x21) = 1;
              _atexit((_func_4879 *)&LAB_00bccc50);
              local_c = 0xffffffff;
              puVar7 = DAT_00f8d9b0;
            }
            cVar2 = *(char *)((int)puVar7[1] + 0x15);
            puVar8 = (undefined4 *)puVar7[1];
            local_68 = puVar7;
            while (puVar10 = puVar8, cVar2 == '\0') {
              if ((int)puVar10[3] < (int)puVar1[9]) {
                puVar8 = (undefined4 *)puVar10[2];
                puVar10 = local_68;
              }
              else {
                puVar8 = (undefined4 *)*puVar10;
              }
              cVar2 = *(char *)((int)puVar8 + 0x15);
              local_68 = puVar10;
            }
            if ((local_68 == puVar7) || ((int)puVar1[9] < (int)local_68[3])) {
              local_64 = puVar7;
              ppuVar9 = &local_64;
            }
            else {
              ppuVar9 = &local_68;
            }
            if (*ppuVar9 == puVar7) {
              iVar6 = 0;
            }
            else {
              iVar6 = (*ppuVar9)[4];
            }
            switch(*puVar13) {
            case 1:
            case 2:
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x20:
            case 0x24:
            case 0x25:
            case 0x2a:
            case 0x2b:
              if ((*(int *)(iVar6 + 4) == 0) || (*(int *)(iVar6 + 4) == *(int *)(param_1 + 0x120)))
              {
                local_30 = puVar1[0xb];
                local_2c = puVar1[9];
                local_28 = puVar1[0xc];
                local_24 = puVar1[0xd];
                local_20 = 0;
                FUN_005f84f0();
                puVar7 = DAT_00f8d9b0;
              }
            }
          }
        }
        else {
          FUN_006edb60(&DAT_00c0ddc0);
          puVar7 = DAT_00f8d9b0;
        }
        local_70 = local_70 + 1;
        puVar1 = puVar13;
      } while (local_70 < 0x65);
    }
    local_78 = (int *)((int)local_78 + 1);
    local_6c = local_6c + 0xca8;
    if (0x194f < local_6c) {
      ExceptionList = local_14;
      return;
    }
  } while( true );
}

