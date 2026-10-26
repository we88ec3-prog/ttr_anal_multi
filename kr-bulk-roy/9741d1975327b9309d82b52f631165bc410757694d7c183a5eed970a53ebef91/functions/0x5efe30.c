
void FUN_005efe30(int param_1)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  short ****ppppsVar7;
  int iVar8;
  short *psVar9;
  undefined4 *puVar10;
  int *piVar11;
  uint uVar12;
  short *psVar13;
  int *piVar14;
  short ****ppppsVar15;
  undefined4 uVar16;
  undefined4 *puVar17;
  uint local_b0 [4];
  undefined4 local_a0;
  uint local_9c;
  int local_94;
  uint local_90 [4];
  undefined4 local_80;
  uint local_7c;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int *local_54;
  int local_50;
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
  puStack_c = &LAB_0092ac5d;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_5c = param_1;
  local_14 = uVar5;
  do {
    iVar4 = local_5c;
    local_58 = 0;
    iVar6 = *(int *)(local_5c + 0x188);
    if ((iVar6 == 0) || (*(int *)(iVar6 + 0x48) - *(int *)(iVar6 + 0x44) >> 3 == 0)) {
      if ((*(int *)(local_5c + 0x180) != 0) &&
         (*(char *)(*(int *)(local_5c + 0x180) + 0x4d) != '\0')) {
        iVar6 = *(int *)(local_5c + 0x1b4);
        if (((*(char *)(iVar6 + 0xa4) != '\0') && (*(int **)(iVar6 + 0x94) != (int *)0x0)) &&
           (iVar8 = (**(code **)(**(int **)(iVar6 + 0x94) + 4))(), iVar8 == 0xbf6b)) {
          iVar6 = *(int *)(iVar6 + 0x94);
          iVar8 = *(int *)(iVar6 + 0x10);
          if (iVar8 != 0) {
            piVar14 = *(int **)(iVar8 + 8);
            if (piVar14 != (int *)0x0) {
              piVar11 = piVar14 + 0x27;
              *piVar11 = *piVar11 + -1;
              if (*piVar11 == 0) {
                (**(code **)(*piVar14 + 0x28))();
              }
            }
            *(undefined4 *)(iVar6 + 0x10) = 0;
          }
        }
        if ((DAT_00fe5ae4 & 1) == 0) {
          DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
          local_8 = 8;
          FUN_00584c40(&DAT_00fe5ac4);
          _atexit((_func_4879 *)&LAB_00bcf390);
          local_8 = 0xffffffff;
        }
        local_50 = 4;
        FUN_005740f0(&local_50);
        if (local_60 == DAT_00fe5ac8) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        psVar13 = (short *)(local_60 + 0x10);
        if (7 < *(uint *)(local_60 + 0x24)) {
          psVar13 = *(short **)psVar13;
        }
        local_1c = 7;
        local_20 = 0;
        local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
        psVar9 = psVar13;
        do {
          sVar2 = *psVar9;
          psVar9 = psVar9 + 1;
        } while (sVar2 != 0);
        FUN_00402160(psVar13,(int)psVar9 - (int)(psVar13 + 1) >> 1);
        iVar6 = *(int *)(iVar4 + 0x1bc);
        local_8 = 9;
        FUN_007578f0();
        FUN_00759ed0(iVar6 + 0xe8,local_30,0x7b,0x7d);
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
        local_50 = 7;
        FUN_005740f0(&local_50);
        if (local_6c == DAT_00fe5ac8) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        psVar13 = (short *)(local_6c + 0x10);
        if (7 < *(uint *)(local_6c + 0x24)) {
          psVar13 = *(short **)psVar13;
        }
        local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
        local_1c = 7;
        local_20 = 0;
        psVar9 = psVar13;
        do {
          sVar2 = *psVar9;
          psVar9 = psVar9 + 1;
        } while (sVar2 != 0);
        FUN_00402160(psVar13,(int)psVar9 - (int)(psVar13 + 1) >> 1);
        iVar6 = *(int *)(iVar4 + 0x1c0);
        local_8 = 0xb;
        goto LAB_005f039d;
      }
      iVar6 = *(int *)(local_5c + 0x1b4);
      if (((*(char *)(iVar6 + 0xa4) != '\0') && (*(int **)(iVar6 + 0x94) != (int *)0x0)) &&
         (iVar8 = (**(code **)(**(int **)(iVar6 + 0x94) + 4))(uVar5), iVar8 == 0xbf6b)) {
        iVar6 = *(int *)(iVar6 + 0x94);
        iVar8 = *(int *)(iVar6 + 0x10);
        if (iVar8 != 0) {
          piVar14 = *(int **)(iVar8 + 8);
          if (piVar14 != (int *)0x0) {
            piVar11 = piVar14 + 0x27;
            *piVar11 = *piVar11 + -1;
            if (*piVar11 == 0) {
              (**(code **)(*piVar14 + 0x28))();
            }
          }
          *(undefined4 *)(iVar6 + 0x10) = 0;
        }
      }
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_8 = 0xc;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_8 = 0xffffffff;
      }
      local_50 = 5;
      FUN_005740f0(&local_50);
      if (local_70 == DAT_00fe5ac8) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      psVar13 = (short *)(local_70 + 0x10);
      if (7 < *(uint *)(local_70 + 0x24)) {
        psVar13 = *(short **)psVar13;
      }
      local_1c = 7;
      local_20 = 0;
      local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
      psVar9 = psVar13;
      do {
        sVar2 = *psVar9;
        psVar9 = psVar9 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar13,(int)psVar9 - (int)(psVar13 + 1) >> 1);
      iVar6 = *(int *)(iVar4 + 0x1bc);
      puVar17 = (undefined4 *)(iVar6 + 0xe8);
      local_8 = 0xd;
      *(undefined4 *)(iVar6 + 0xf8) = 0;
      puVar10 = puVar17;
      if (7 < *(uint *)(iVar6 + 0xfc)) {
        puVar10 = (undefined4 *)*puVar17;
      }
      *(undefined2 *)puVar10 = 0;
      piVar14 = *(int **)(iVar6 + 0x104);
      piVar11 = (int *)*piVar14;
      *piVar14 = (int)piVar14;
      *(int *)(*(int *)(iVar6 + 0x104) + 4) = *(int *)(iVar6 + 0x104);
      *(undefined4 *)(iVar6 + 0x108) = 0;
      if (piVar11 != *(int **)(iVar6 + 0x104)) {
        do {
          piVar14 = (int *)*piVar11;
          FUN_0089120c(piVar11);
          piVar11 = piVar14;
        } while (piVar14 != (int *)*(int *)(iVar6 + 0x104));
      }
      piVar14 = *(int **)(*(int *)(iVar6 + 0x114) + 4);
      cVar1 = *(char *)((int)piVar14 + 0x21);
      while (local_54 = piVar14, cVar1 == '\0') {
        FUN_008575b0(piVar14[2]);
        piVar14 = (int *)*piVar14;
        FUN_0089120c(local_54);
        cVar1 = *(char *)((int)piVar14 + 0x21);
      }
      *(int *)(*(int *)(iVar6 + 0x114) + 4) = *(int *)(iVar6 + 0x114);
      *(undefined4 *)*(undefined4 *)(iVar6 + 0x114) = *(undefined4 *)(iVar6 + 0x114);
      *(int *)(*(int *)(iVar6 + 0x114) + 8) = *(int *)(iVar6 + 0x114);
      *(undefined4 *)(iVar6 + 0x118) = 0;
      FUN_00759ed0(puVar17,local_30,0x7b,0x7d);
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_8 = 0xe;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_8 = 0xffffffff;
      }
      local_50 = 6;
      FUN_005740f0(&local_50);
      if (local_64 == DAT_00fe5ac8) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      psVar13 = (short *)(local_64 + 0x10);
      if (7 < *(uint *)(local_64 + 0x24)) {
        psVar13 = *(short **)psVar13;
      }
      local_9c = 7;
      local_a0 = 0;
      local_b0[0] = local_b0[0] & 0xffff0000;
      psVar9 = psVar13;
      do {
        sVar2 = *psVar9;
        psVar9 = psVar9 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar13,(int)psVar9 - (int)(psVar13 + 1) >> 1);
      iVar6 = *(int *)(local_5c + 0x1c0 + local_58 * 4);
      puVar17 = (undefined4 *)(iVar6 + 0xe8);
      local_8 = 0xf;
      *(undefined4 *)(iVar6 + 0xf8) = 0;
      puVar10 = puVar17;
      if (7 < *(uint *)(iVar6 + 0xfc)) {
        puVar10 = (undefined4 *)*puVar17;
      }
      *(undefined2 *)puVar10 = 0;
      piVar14 = *(int **)(iVar6 + 0x104);
      piVar11 = (int *)*piVar14;
      *piVar14 = (int)piVar14;
      *(int *)(*(int *)(iVar6 + 0x104) + 4) = *(int *)(iVar6 + 0x104);
      *(undefined4 *)(iVar6 + 0x108) = 0;
      if (piVar11 != *(int **)(iVar6 + 0x104)) {
        do {
          piVar14 = (int *)*piVar11;
          FUN_0089120c(piVar11);
          piVar11 = piVar14;
        } while (piVar14 != (int *)*(int *)(iVar6 + 0x104));
      }
      piVar14 = *(int **)(*(int *)(iVar6 + 0x114) + 4);
      cVar1 = *(char *)((int)piVar14 + 0x21);
      while (local_54 = piVar14, cVar1 == '\0') {
        FUN_008575b0(piVar14[2]);
        piVar14 = (int *)*piVar14;
        FUN_0089120c(local_54);
        cVar1 = *(char *)((int)piVar14 + 0x21);
      }
      *(int *)(*(int *)(iVar6 + 0x114) + 4) = *(int *)(iVar6 + 0x114);
      *(undefined4 *)*(undefined4 *)(iVar6 + 0x114) = *(undefined4 *)(iVar6 + 0x114);
      *(int *)(*(int *)(iVar6 + 0x114) + 8) = *(int *)(iVar6 + 0x114);
      *(undefined4 *)(iVar6 + 0x118) = 0;
      FUN_00759ed0(puVar17,local_b0,0x7b,0x7d);
      local_8 = 0xffffffff;
      if (7 < local_9c) {
        FUN_0089120c(local_b0[0]);
      }
      iVar4 = local_58;
      iVar6 = local_5c;
      local_b0[0] = local_b0[0] & 0xffff0000;
      local_9c = 7;
      local_a0 = 0;
      (**(code **)(**(int **)(local_5c + 0x1b4 + local_58 * 4) + 0x94))(0);
      iVar6 = **(int **)(iVar6 + 0x1b8 + iVar4 * 4);
      uVar16 = 1;
LAB_005f0968:
      (**(code **)(iVar6 + 0x94))(uVar16);
    }
    else {
      uVar12 = 0;
      if (*(int *)(iVar6 + 0x48) - *(int *)(iVar6 + 0x44) >> 3 != 0) {
        local_54 = *(int **)(iVar6 + 0x44);
        piVar14 = local_54;
        do {
          if (*piVar14 == 1) {
            local_54 = local_54 + uVar12 * 2;
            goto LAB_005efecd;
          }
          uVar12 = uVar12 + 1;
          piVar14 = piVar14 + 2;
        } while (uVar12 < (uint)(*(int *)(iVar6 + 0x48) - (int)local_54 >> 3));
      }
      local_54 = *(int **)(iVar6 + 0x44);
LAB_005efecd:
      if ((local_54 == (int *)0x0) || (local_54[1] < 1)) {
        iVar6 = *(int *)(local_5c + 0x1b4);
        if ((*(char *)(iVar6 + 0xa4) != '\0') &&
           ((*(int **)(iVar6 + 0x94) != (int *)0x0 &&
            (iVar8 = (**(code **)(**(int **)(iVar6 + 0x94) + 4))(), iVar8 == 0xbf6b)))) {
          iVar6 = *(int *)(iVar6 + 0x94);
          iVar8 = *(int *)(iVar6 + 0x10);
          if (iVar8 != 0) {
            piVar14 = *(int **)(iVar8 + 8);
            if (piVar14 != (int *)0x0) {
              piVar11 = piVar14 + 0x27;
              *piVar11 = *piVar11 + -1;
              if (*piVar11 == 0) {
                (**(code **)(*piVar14 + 0x28))();
              }
            }
            *(undefined4 *)(iVar6 + 0x10) = 0;
          }
        }
        if ((DAT_00fe5ae4 & 1) == 0) {
          DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
          local_8 = 4;
          FUN_00584c40(&DAT_00fe5ac4);
          _atexit((_func_4879 *)&LAB_00bcf390);
          local_8 = 0xffffffff;
        }
        local_50 = 4;
        FUN_005740f0(&local_50);
        if (local_68 == DAT_00fe5ac8) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        psVar13 = (short *)(local_68 + 0x10);
        if (7 < *(uint *)(local_68 + 0x24)) {
          psVar13 = *(short **)psVar13;
        }
        local_1c = 7;
        local_20 = 0;
        local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
        psVar9 = psVar13;
        do {
          sVar2 = *psVar9;
          psVar9 = psVar9 + 1;
        } while (sVar2 != 0);
        FUN_00402160(psVar13,(int)psVar9 - (int)(psVar13 + 1) >> 1);
        iVar6 = *(int *)(iVar4 + 0x1bc);
        local_8 = 5;
        FUN_007578f0();
        FUN_00759ed0(iVar6 + 0xe8,local_30,0x7b,0x7d);
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
        local_50 = 7;
        FUN_005740f0(&local_50);
        if (local_94 == DAT_00fe5ac8) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        psVar13 = (short *)(local_94 + 0x10);
        if (7 < *(uint *)(local_94 + 0x24)) {
          psVar13 = *(short **)psVar13;
        }
        local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
        local_1c = 7;
        local_20 = 0;
        psVar9 = psVar13;
        do {
          sVar2 = *psVar9;
          psVar9 = psVar9 + 1;
        } while (sVar2 != 0);
        FUN_00402160(psVar13,(int)psVar9 - (int)(psVar13 + 1) >> 1);
        iVar6 = *(int *)(iVar4 + 0x1c0);
        local_8 = 7;
LAB_005f039d:
        FUN_007578f0();
        FUN_00759ed0(iVar6 + 0xe8,local_30,0x7b,0x7d);
        local_8 = 0xffffffff;
        if (7 < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        (**(code **)(**(int **)(iVar4 + 0x1b4) + 0x94))(0);
        iVar6 = **(int **)(iVar4 + 0x1b8);
        uVar16 = 0;
        goto LAB_005f0968;
      }
      local_50 = local_54[1];
      iVar6 = FUN_004034e0();
      FUN_008438c0(&local_50);
      if (local_74 == *(int *)(iVar6 + 4)) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(local_74 + 0x10);
      }
      psVar13 = (short *)(iVar6 + 0x98);
      if (7 < *(uint *)(iVar6 + 0xac)) {
        psVar13 = *(short **)psVar13;
      }
      local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
      local_1c = 7;
      local_20 = 0;
      psVar9 = psVar13;
      do {
        sVar2 = *psVar9;
        psVar9 = psVar9 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar13,(int)psVar9 - (int)(psVar13 + 1) >> 1);
      local_8 = 0;
      if (*(uint *)(iVar6 + 200) < 8) {
        psVar13 = (short *)(iVar6 + 0xb4);
      }
      else {
        psVar13 = *(short **)(iVar6 + 0xb4);
      }
      local_38 = 7;
      local_3c = 0;
      local_4c[0] = (short ***)((uint)local_4c[0] & 0xffff0000);
      psVar9 = psVar13;
      do {
        sVar2 = *psVar9;
        psVar9 = psVar9 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar13,(int)psVar9 - (int)(psVar13 + 1) >> 1);
      local_8._0_1_ = 1;
      switch(*(undefined4 *)(iVar6 + 0x5c)) {
      case 0:
        uVar16 = 0;
        break;
      case 1:
      case 2:
      case 3:
        uVar16 = 1;
        break;
      case 4:
      case 5:
        uVar16 = 2;
        break;
      case 6:
      case 7:
        uVar16 = 3;
        break;
      case 8:
      case 9:
      case 10:
        uVar16 = 4;
        break;
      default:
        uVar16 = 5;
      }
      FUN_005e1e00(*(undefined4 *)(iVar6 + 8),uVar16);
      FUN_005e1e00(*(undefined4 *)(iVar6 + 8),uVar16);
      FUN_005e1bc0(local_54[1]);
      FUN_00745060();
      ppppsVar15 = (short ****)local_30[0];
      if (local_1c < 8) {
        ppppsVar15 = local_30;
      }
      local_90[0] = local_90[0] & 0xffff0000;
      local_7c = 7;
      local_80 = 0;
      ppppsVar7 = ppppsVar15;
      do {
        sVar2 = *(short *)ppppsVar7;
        ppppsVar7 = (short ****)((int)ppppsVar7 + 2);
      } while (sVar2 != 0);
      FUN_00402160(ppppsVar15,(int)ppppsVar7 - (int)((int)ppppsVar15 + 2) >> 1);
      iVar8 = local_58;
      iVar4 = local_5c;
      iVar6 = *(int *)(local_5c + 0x1bc + local_58 * 4);
      local_8._0_1_ = 2;
      FUN_007578f0();
      FUN_00759ed0(iVar6 + 0xe8,local_90,0x7b,0x7d);
      local_8._0_1_ = 1;
      if (7 < local_7c) {
        FUN_0089120c(local_90[0]);
      }
      ppppsVar15 = (short ****)local_4c[0];
      if (local_38 < 8) {
        ppppsVar15 = local_4c;
      }
      local_90[0] = local_90[0] & 0xffff0000;
      local_7c = 7;
      local_80 = 0;
      ppppsVar7 = ppppsVar15;
      do {
        sVar2 = *(short *)ppppsVar7;
        ppppsVar7 = (short ****)((int)ppppsVar7 + 2);
      } while (sVar2 != 0);
      FUN_00402160(ppppsVar15,(int)ppppsVar7 - (int)((int)ppppsVar15 + 2) >> 1);
      iVar6 = *(int *)(iVar4 + 0x1c0 + iVar8 * 4);
      local_8._0_1_ = 3;
      FUN_007578f0();
      FUN_00759ed0(iVar6 + 0xe8,local_90,0x7b,0x7d);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (7 < local_7c) {
        FUN_0089120c(local_90[0]);
      }
      (**(code **)(**(int **)(iVar4 + 0x1b4 + iVar8 * 4) + 0x94))(1);
      (**(code **)(**(int **)(iVar4 + 0x1b8 + iVar8 * 4) + 0x94))(0);
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
    local_58 = local_58 + 1;
    if (local_58 != 0) {
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  } while( true );
}

