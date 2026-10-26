
void FUN_005ed5e0(int param_1)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  short ****ppppsVar8;
  int iVar9;
  int iVar10;
  short *psVar11;
  undefined4 *puVar12;
  int *piVar13;
  uint uVar14;
  short *psVar15;
  int *piVar16;
  short ****ppppsVar17;
  undefined4 uVar18;
  undefined4 *puVar19;
  uint local_a8 [4];
  undefined4 local_98;
  uint local_94;
  int local_8c;
  uint local_88 [4];
  undefined4 local_78;
  uint local_74;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int *local_5c;
  int local_58;
  int local_54;
  uint local_50;
  short ***local_4c [4];
  undefined4 local_3c;
  uint local_38;
  short ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092ab41;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_58 = param_1;
  local_50 = 0;
  local_14 = uVar5;
  do {
    uVar4 = local_50;
    iVar10 = local_58;
    iVar7 = *(int *)(local_58 + 0x188);
    if ((iVar7 == 0) || ((uint)(*(int *)(iVar7 + 0x48) - *(int *)(iVar7 + 0x44) >> 3) <= local_50))
    {
      iVar7 = *(int *)(local_58 + 0x1b8 + local_50 * 4);
      if ((*(char *)(iVar7 + 0xa4) != '\0') &&
         ((*(int **)(iVar7 + 0x94) != (int *)0x0 &&
          (iVar10 = (**(code **)(**(int **)(iVar7 + 0x94) + 4))(uVar5), iVar10 == 0xbf6b)))) {
        iVar7 = *(int *)(iVar7 + 0x94);
        iVar10 = *(int *)(iVar7 + 0x10);
        if (iVar10 != 0) {
          piVar16 = *(int **)(iVar10 + 8);
          if (piVar16 != (int *)0x0) {
            piVar13 = piVar16 + 0x27;
            *piVar13 = *piVar13 + -1;
            if (*piVar13 == 0) {
              (**(code **)(*piVar16 + 0x28))();
            }
          }
          *(undefined4 *)(iVar7 + 0x10) = 0;
        }
      }
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_8 = 8;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_8 = 0xffffffff;
      }
      local_54 = 5;
      FUN_005740f0(&local_54);
      if (local_68 == DAT_00fe5ac8) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      psVar15 = (short *)(local_68 + 0x10);
      if (7 < *(uint *)(local_68 + 0x24)) {
        psVar15 = *(short **)psVar15;
      }
      local_1c = 7;
      local_20 = 0;
      local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
      psVar11 = psVar15;
      do {
        sVar2 = *psVar11;
        psVar11 = psVar11 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar15,(int)psVar11 - (int)(psVar15 + 1) >> 1);
      iVar7 = *(int *)(local_58 + 0x1c8 + local_50 * 4);
      puVar19 = (undefined4 *)(iVar7 + 0xe8);
      local_8 = 9;
      *(undefined4 *)(iVar7 + 0xf8) = 0;
      puVar12 = puVar19;
      if (7 < *(uint *)(iVar7 + 0xfc)) {
        puVar12 = (undefined4 *)*puVar19;
      }
      *(undefined2 *)puVar12 = 0;
      piVar16 = *(int **)(iVar7 + 0x104);
      piVar13 = (int *)*piVar16;
      *piVar16 = (int)piVar16;
      *(int *)(*(int *)(iVar7 + 0x104) + 4) = *(int *)(iVar7 + 0x104);
      *(undefined4 *)(iVar7 + 0x108) = 0;
      if (piVar13 != *(int **)(iVar7 + 0x104)) {
        do {
          piVar16 = (int *)*piVar13;
          FUN_0089120c(piVar13);
          piVar13 = piVar16;
        } while (piVar16 != (int *)*(int *)(iVar7 + 0x104));
      }
      piVar16 = *(int **)(*(int *)(iVar7 + 0x114) + 4);
      cVar1 = *(char *)((int)piVar16 + 0x21);
      while (local_5c = piVar16, cVar1 == '\0') {
        FUN_008575b0(piVar16[2]);
        piVar16 = (int *)*piVar16;
        FUN_0089120c(local_5c);
        cVar1 = *(char *)((int)piVar16 + 0x21);
      }
      *(int *)(*(int *)(iVar7 + 0x114) + 4) = *(int *)(iVar7 + 0x114);
      *(undefined4 *)*(undefined4 *)(iVar7 + 0x114) = *(undefined4 *)(iVar7 + 0x114);
      *(int *)(*(int *)(iVar7 + 0x114) + 8) = *(int *)(iVar7 + 0x114);
      *(undefined4 *)(iVar7 + 0x118) = 0;
      FUN_00759ed0(puVar19,local_30,0x7b,0x7d);
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_8 = 10;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_8 = 0xffffffff;
      }
      local_54 = 6;
      FUN_005740f0(&local_54);
      if (local_6c == DAT_00fe5ac8) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      psVar15 = (short *)(local_6c + 0x10);
      if (7 < *(uint *)(local_6c + 0x24)) {
        psVar15 = *(short **)psVar15;
      }
      local_a8[0] = local_a8[0] & 0xffff0000;
      local_94 = 7;
      local_98 = 0;
      psVar11 = psVar15;
      do {
        sVar2 = *psVar11;
        psVar11 = psVar11 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar15,(int)psVar11 - (int)(psVar15 + 1) >> 1);
      iVar7 = *(int *)(local_58 + 0x1d0 + local_50 * 4);
      puVar19 = (undefined4 *)(iVar7 + 0xe8);
      local_8 = 0xb;
      *(undefined4 *)(iVar7 + 0xf8) = 0;
      puVar12 = puVar19;
      if (7 < *(uint *)(iVar7 + 0xfc)) {
        puVar12 = (undefined4 *)*puVar19;
      }
      *(undefined2 *)puVar12 = 0;
      piVar16 = *(int **)(iVar7 + 0x104);
      piVar13 = (int *)*piVar16;
      *piVar16 = (int)piVar16;
      *(int *)(*(int *)(iVar7 + 0x104) + 4) = *(int *)(iVar7 + 0x104);
      *(undefined4 *)(iVar7 + 0x108) = 0;
      if (piVar13 != *(int **)(iVar7 + 0x104)) {
        do {
          piVar16 = (int *)*piVar13;
          FUN_0089120c(piVar13);
          piVar13 = piVar16;
        } while (piVar16 != (int *)*(int *)(iVar7 + 0x104));
      }
      piVar16 = *(int **)(*(int *)(iVar7 + 0x114) + 4);
      cVar1 = *(char *)((int)piVar16 + 0x21);
      while (local_5c = piVar16, cVar1 == '\0') {
        FUN_008575b0(piVar16[2]);
        piVar16 = (int *)*piVar16;
        FUN_0089120c(local_5c);
        cVar1 = *(char *)((int)piVar16 + 0x21);
      }
      *(int *)(*(int *)(iVar7 + 0x114) + 4) = *(int *)(iVar7 + 0x114);
      *(undefined4 *)*(undefined4 *)(iVar7 + 0x114) = *(undefined4 *)(iVar7 + 0x114);
      *(int *)(*(int *)(iVar7 + 0x114) + 8) = *(int *)(iVar7 + 0x114);
      *(undefined4 *)(iVar7 + 0x118) = 0;
      FUN_00759ed0(puVar19,local_a8,0x7b,0x7d);
      local_8 = 0xffffffff;
      if (7 < local_94) {
        FUN_0089120c(local_a8[0]);
      }
      uVar4 = local_50;
      iVar7 = local_58;
      local_a8[0] = local_a8[0] & 0xffff0000;
      local_94 = 7;
      local_98 = 0;
      (**(code **)(**(int **)(local_58 + 0x1b8 + local_50 * 4) + 0x94))(0);
      (**(code **)(**(int **)(iVar7 + 0x1c0 + uVar4 * 4) + 0x94))(1);
    }
    else {
      uVar6 = *(int *)(iVar7 + 0x48) - *(int *)(iVar7 + 0x44) >> 3;
      if (uVar6 != 0) {
        uVar14 = 0;
        piVar16 = *(int **)(iVar7 + 0x44);
        do {
          if (*piVar16 == local_50 + 1) {
            local_5c = *(int **)(iVar7 + 0x44) + uVar14 * 2;
            goto LAB_005ed675;
          }
          uVar14 = uVar14 + 1;
          piVar16 = piVar16 + 2;
        } while (uVar14 < uVar6);
      }
      local_5c = (int *)(*(int *)(iVar7 + 0x44) + local_50 * 8);
LAB_005ed675:
      if ((local_5c == (int *)0x0) || (local_5c[1] < 1)) {
        iVar7 = *(int *)(local_58 + 0x1b8 + local_50 * 4);
        if ((*(char *)(iVar7 + 0xa4) != '\0') &&
           ((*(int **)(iVar7 + 0x94) != (int *)0x0 &&
            (iVar9 = (**(code **)(**(int **)(iVar7 + 0x94) + 4))(), iVar9 == 0xbf6b)))) {
          iVar7 = *(int *)(iVar7 + 0x94);
          iVar9 = *(int *)(iVar7 + 0x10);
          if (iVar9 != 0) {
            piVar16 = *(int **)(iVar9 + 8);
            if (piVar16 != (int *)0x0) {
              piVar13 = piVar16 + 0x27;
              *piVar13 = *piVar13 + -1;
              if (*piVar13 == 0) {
                (**(code **)(*piVar16 + 0x28))();
              }
            }
            *(undefined4 *)(iVar7 + 0x10) = 0;
          }
        }
        if ((DAT_00fe5ae4 & 1) == 0) {
          DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
          local_8 = 4;
          FUN_00584c40(&DAT_00fe5ac4);
          _atexit((_func_4879 *)&LAB_00bcf390);
          local_8 = 0xffffffff;
        }
        local_54 = 4;
        FUN_005740f0(&local_54);
        if (local_64 == DAT_00fe5ac8) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        psVar15 = (short *)(local_64 + 0x10);
        if (7 < *(uint *)(local_64 + 0x24)) {
          psVar15 = *(short **)psVar15;
        }
        local_1c = 7;
        local_20 = 0;
        local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
        psVar11 = psVar15;
        do {
          sVar2 = *psVar11;
          psVar11 = psVar11 + 1;
        } while (sVar2 != 0);
        FUN_00402160(psVar15,(int)psVar11 - (int)(psVar15 + 1) >> 1);
        iVar7 = *(int *)(iVar10 + 0x1c8 + uVar4 * 4);
        local_8 = 5;
        FUN_007578f0();
        FUN_00759ed0(iVar7 + 0xe8,local_30,0x7b,0x7d);
        local_8 = 0xffffffff;
        if (7 < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        if ((DAT_00fe5ae4 & 1) == 0) {
          DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
          local_8 = 6;
          FUN_00584c40(&DAT_00fe5ac4);
          _atexit((_func_4879 *)&LAB_00bcf390);
          local_8 = 0xffffffff;
        }
        local_54 = 7;
        FUN_005740f0(&local_54);
        if (local_60 == DAT_00fe5ac8) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        psVar15 = (short *)(local_60 + 0x10);
        if (7 < *(uint *)(local_60 + 0x24)) {
          psVar15 = *(short **)psVar15;
        }
        local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
        local_1c = 7;
        local_20 = 0;
        psVar11 = psVar15;
        do {
          sVar2 = *psVar11;
          psVar11 = psVar11 + 1;
        } while (sVar2 != 0);
        FUN_00402160(psVar15,(int)psVar11 - (int)(psVar15 + 1) >> 1);
        iVar7 = *(int *)(iVar10 + 0x1d0 + uVar4 * 4);
        local_8 = 7;
        FUN_007578f0();
        FUN_00759ed0(iVar7 + 0xe8,local_30,0x7b,0x7d);
        local_8 = 0xffffffff;
        if (7 < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        (**(code **)(**(int **)(iVar10 + 0x1b8 + uVar4 * 4) + 0x94))(0);
        (**(code **)(**(int **)(iVar10 + 0x1c0 + uVar4 * 4) + 0x94))(0);
      }
      else {
        local_54 = local_5c[1];
        iVar7 = FUN_004034e0();
        FUN_008438c0(&local_54);
        if (local_8c == *(int *)(iVar7 + 4)) {
          iVar7 = 0;
        }
        else {
          iVar7 = *(int *)(local_8c + 0x10);
        }
        psVar15 = (short *)(iVar7 + 0x98);
        if (7 < *(uint *)(iVar7 + 0xac)) {
          psVar15 = *(short **)psVar15;
        }
        local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
        local_1c = 7;
        local_20 = 0;
        psVar11 = psVar15;
        do {
          sVar2 = *psVar11;
          psVar11 = psVar11 + 1;
        } while (sVar2 != 0);
        FUN_00402160(psVar15,(int)psVar11 - (int)(psVar15 + 1) >> 1);
        local_8 = 0;
        if (*(uint *)(iVar7 + 200) < 8) {
          psVar15 = (short *)(iVar7 + 0xb4);
        }
        else {
          psVar15 = *(short **)(iVar7 + 0xb4);
        }
        local_38 = 7;
        local_3c = 0;
        local_4c[0] = (short ***)((uint)local_4c[0] & 0xffff0000);
        psVar11 = psVar15;
        do {
          sVar2 = *psVar11;
          psVar11 = psVar11 + 1;
        } while (sVar2 != 0);
        FUN_00402160(psVar15,(int)psVar11 - (int)(psVar15 + 1) >> 1);
        local_8._0_1_ = 1;
        switch(*(undefined4 *)(iVar7 + 0x5c)) {
        case 0:
          uVar18 = 0;
          break;
        case 1:
        case 2:
        case 3:
          uVar18 = 1;
          break;
        case 4:
        case 5:
          uVar18 = 2;
          break;
        case 6:
        case 7:
          uVar18 = 3;
          break;
        case 8:
        case 9:
        case 10:
          uVar18 = 4;
          break;
        default:
          uVar18 = 5;
        }
        FUN_005e1e00(*(undefined4 *)(iVar7 + 8),uVar18);
        FUN_005e1e00(*(undefined4 *)(iVar7 + 8),uVar18);
        FUN_005e1bc0(local_5c[1]);
        FUN_00745060();
        ppppsVar17 = (short ****)local_30[0];
        if (local_1c < 8) {
          ppppsVar17 = local_30;
        }
        local_88[0] = local_88[0] & 0xffff0000;
        local_74 = 7;
        local_78 = 0;
        ppppsVar8 = ppppsVar17;
        do {
          sVar2 = *(short *)ppppsVar8;
          ppppsVar8 = (short ****)((int)ppppsVar8 + 2);
        } while (sVar2 != 0);
        FUN_00402160(ppppsVar17,(int)ppppsVar8 - (int)((int)ppppsVar17 + 2) >> 1);
        uVar4 = local_50;
        iVar10 = local_58;
        iVar7 = *(int *)(local_58 + 0x1c8 + local_50 * 4);
        local_8._0_1_ = 2;
        FUN_007578f0();
        FUN_00759ed0(iVar7 + 0xe8,local_88,0x7b,0x7d);
        local_8._0_1_ = 1;
        if (7 < local_74) {
          FUN_0089120c(local_88[0]);
        }
        ppppsVar17 = (short ****)local_4c[0];
        if (local_38 < 8) {
          ppppsVar17 = local_4c;
        }
        local_88[0] = local_88[0] & 0xffff0000;
        local_74 = 7;
        local_78 = 0;
        ppppsVar8 = ppppsVar17;
        do {
          sVar2 = *(short *)ppppsVar8;
          ppppsVar8 = (short ****)((int)ppppsVar8 + 2);
        } while (sVar2 != 0);
        FUN_00402160(ppppsVar17,(int)ppppsVar8 - (int)((int)ppppsVar17 + 2) >> 1);
        iVar7 = *(int *)(iVar10 + 0x1d0 + uVar4 * 4);
        local_8._0_1_ = 3;
        FUN_007578f0();
        FUN_00759ed0(iVar7 + 0xe8,local_88,0x7b,0x7d);
        local_8 = CONCAT31(local_8._1_3_,1);
        if (7 < local_74) {
          FUN_0089120c(local_88[0]);
        }
        (**(code **)(**(int **)(iVar10 + 0x1b8 + uVar4 * 4) + 0x94))(1);
        (**(code **)(**(int **)(iVar10 + 0x1c0 + uVar4 * 4) + 0x94))(0);
        if (7 < local_38) {
          FUN_0089120c(local_4c[0]);
        }
        local_8 = 0xffffffff;
        local_38 = 7;
        local_3c = 0;
        local_4c[0] = (short ***)((uint)local_4c[0] & 0xffff0000);
        if (7 < local_1c) {
          FUN_0089120c(local_30[0]);
        }
      }
    }
    local_50 = local_50 + 1;
    if (1 < local_50) {
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  } while( true );
}

