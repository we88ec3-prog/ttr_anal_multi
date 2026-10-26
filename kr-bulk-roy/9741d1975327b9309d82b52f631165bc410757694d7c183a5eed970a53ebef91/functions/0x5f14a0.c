
void FUN_005f14a0(int param_1)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  short ****ppppsVar8;
  int iVar9;
  short *psVar10;
  undefined4 *puVar11;
  int *piVar12;
  uint uVar13;
  short *psVar14;
  int *piVar15;
  short ****ppppsVar16;
  undefined4 uVar17;
  undefined4 *puVar18;
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
  uint local_58;
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
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_5c = param_1;
  local_58 = 0;
  local_14 = uVar6;
  do {
    uVar5 = local_58;
    iVar4 = local_5c;
    iVar7 = *(int *)(local_5c + 0x188);
    if ((iVar7 == 0) || ((uint)(*(int *)(iVar7 + 0x48) - *(int *)(iVar7 + 0x44) >> 3) <= local_58))
    {
      if ((*(int *)(local_5c + 0x180) != 0) &&
         (local_58 < *(byte *)(*(int *)(local_5c + 0x180) + 0x4d))) {
        iVar7 = *(int *)(local_5c + 0x1d4 + local_58 * 4);
        if (((*(char *)(iVar7 + 0xa4) != '\0') && (*(int **)(iVar7 + 0x94) != (int *)0x0)) &&
           (iVar9 = (**(code **)(**(int **)(iVar7 + 0x94) + 4))(), iVar9 == 0xbf6b)) {
          iVar7 = *(int *)(iVar7 + 0x94);
          iVar9 = *(int *)(iVar7 + 0x10);
          if (iVar9 != 0) {
            piVar15 = *(int **)(iVar9 + 8);
            if (piVar15 != (int *)0x0) {
              piVar12 = piVar15 + 0x27;
              *piVar12 = *piVar12 + -1;
              if (*piVar12 == 0) {
                (**(code **)(*piVar15 + 0x28))();
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
        local_50 = 4;
        FUN_005740f0(&local_50);
        if (local_60 == DAT_00fe5ac8) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        psVar14 = (short *)(local_60 + 0x10);
        if (7 < *(uint *)(local_60 + 0x24)) {
          psVar14 = *(short **)psVar14;
        }
        local_1c = 7;
        local_20 = 0;
        local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
        psVar10 = psVar14;
        do {
          sVar2 = *psVar10;
          psVar10 = psVar10 + 1;
        } while (sVar2 != 0);
        FUN_00402160(psVar14,(int)psVar10 - (int)(psVar14 + 1) >> 1);
        iVar7 = *(int *)(iVar4 + 0x1ec + uVar5 * 4);
        local_8 = 9;
        FUN_007578f0();
        FUN_00759ed0(iVar7 + 0xe8,local_30,0x7b,0x7d);
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
        psVar14 = (short *)(local_6c + 0x10);
        if (7 < *(uint *)(local_6c + 0x24)) {
          psVar14 = *(short **)psVar14;
        }
        local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
        local_1c = 7;
        local_20 = 0;
        psVar10 = psVar14;
        do {
          sVar2 = *psVar10;
          psVar10 = psVar10 + 1;
        } while (sVar2 != 0);
        FUN_00402160(psVar14,(int)psVar10 - (int)(psVar14 + 1) >> 1);
        iVar7 = *(int *)(iVar4 + 0x1f8 + uVar5 * 4);
        local_8 = 0xb;
        goto LAB_005f1bff;
      }
      iVar7 = *(int *)(local_5c + 0x1d4 + local_58 * 4);
      if (((*(char *)(iVar7 + 0xa4) != '\0') && (*(int **)(iVar7 + 0x94) != (int *)0x0)) &&
         (iVar9 = (**(code **)(**(int **)(iVar7 + 0x94) + 4))(uVar6), iVar9 == 0xbf6b)) {
        iVar7 = *(int *)(iVar7 + 0x94);
        iVar9 = *(int *)(iVar7 + 0x10);
        if (iVar9 != 0) {
          piVar15 = *(int **)(iVar9 + 8);
          if (piVar15 != (int *)0x0) {
            piVar12 = piVar15 + 0x27;
            *piVar12 = *piVar12 + -1;
            if (*piVar12 == 0) {
              (**(code **)(*piVar15 + 0x28))();
            }
          }
          *(undefined4 *)(iVar7 + 0x10) = 0;
        }
      }
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_8 = 0xc;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_8 = 0xffffffff;
      }
      local_50 = 10;
      FUN_005740f0(&local_50);
      if (local_94 == DAT_00fe5ac8) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      psVar14 = (short *)(local_94 + 0x10);
      if (7 < *(uint *)(local_94 + 0x24)) {
        psVar14 = *(short **)psVar14;
      }
      local_1c = 7;
      local_20 = 0;
      local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
      psVar10 = psVar14;
      do {
        sVar2 = *psVar10;
        psVar10 = psVar10 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar14,(int)psVar10 - (int)(psVar14 + 1) >> 1);
      iVar7 = *(int *)(iVar4 + 0x1ec + uVar5 * 4);
      puVar18 = (undefined4 *)(iVar7 + 0xe8);
      local_8 = 0xd;
      *(undefined4 *)(iVar7 + 0xf8) = 0;
      puVar11 = puVar18;
      if (7 < *(uint *)(iVar7 + 0xfc)) {
        puVar11 = (undefined4 *)*puVar18;
      }
      *(undefined2 *)puVar11 = 0;
      piVar15 = *(int **)(iVar7 + 0x104);
      piVar12 = (int *)*piVar15;
      *piVar15 = (int)piVar15;
      *(int *)(*(int *)(iVar7 + 0x104) + 4) = *(int *)(iVar7 + 0x104);
      *(undefined4 *)(iVar7 + 0x108) = 0;
      if (piVar12 != *(int **)(iVar7 + 0x104)) {
        do {
          piVar15 = (int *)*piVar12;
          FUN_0089120c(piVar12);
          piVar12 = piVar15;
        } while (piVar15 != (int *)*(int *)(iVar7 + 0x104));
      }
      piVar15 = *(int **)(*(int *)(iVar7 + 0x114) + 4);
      cVar1 = *(char *)((int)piVar15 + 0x21);
      while (local_54 = piVar15, cVar1 == '\0') {
        FUN_008575b0(piVar15[2]);
        piVar15 = (int *)*piVar15;
        FUN_0089120c(local_54);
        cVar1 = *(char *)((int)piVar15 + 0x21);
      }
      *(int *)(*(int *)(iVar7 + 0x114) + 4) = *(int *)(iVar7 + 0x114);
      *(undefined4 *)*(undefined4 *)(iVar7 + 0x114) = *(undefined4 *)(iVar7 + 0x114);
      *(int *)(*(int *)(iVar7 + 0x114) + 8) = *(int *)(iVar7 + 0x114);
      *(undefined4 *)(iVar7 + 0x118) = 0;
      FUN_00759ed0(puVar18,local_30,0x7b,0x7d);
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
      local_50 = 0xb;
      FUN_005740f0(&local_50);
      uVar5 = local_58;
      if (local_64 == DAT_00fe5ac8) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      FUN_00420070();
      iVar7 = *(int *)(local_5c + 0x1f8 + uVar5 * 4);
      puVar18 = (undefined4 *)(iVar7 + 0xe8);
      local_8 = 0xf;
      *(undefined4 *)(iVar7 + 0xf8) = 0;
      puVar11 = puVar18;
      if (7 < *(uint *)(iVar7 + 0xfc)) {
        puVar11 = (undefined4 *)*puVar18;
      }
      *(undefined2 *)puVar11 = 0;
      piVar15 = *(int **)(iVar7 + 0x104);
      piVar12 = (int *)*piVar15;
      *piVar15 = (int)piVar15;
      *(int *)(*(int *)(iVar7 + 0x104) + 4) = *(int *)(iVar7 + 0x104);
      *(undefined4 *)(iVar7 + 0x108) = 0;
      if (piVar12 != *(int **)(iVar7 + 0x104)) {
        do {
          piVar15 = (int *)*piVar12;
          FUN_0089120c(piVar12);
          piVar12 = piVar15;
        } while (piVar15 != (int *)*(int *)(iVar7 + 0x104));
      }
      piVar15 = *(int **)(*(int *)(iVar7 + 0x114) + 4);
      cVar1 = *(char *)((int)piVar15 + 0x21);
      while (local_54 = piVar15, cVar1 == '\0') {
        FUN_008575b0(piVar15[2]);
        piVar15 = (int *)*piVar15;
        FUN_0089120c(local_54);
        cVar1 = *(char *)((int)piVar15 + 0x21);
      }
      *(int *)(*(int *)(iVar7 + 0x114) + 4) = *(int *)(iVar7 + 0x114);
      *(undefined4 *)*(undefined4 *)(iVar7 + 0x114) = *(undefined4 *)(iVar7 + 0x114);
      *(int *)(*(int *)(iVar7 + 0x114) + 8) = *(int *)(iVar7 + 0x114);
      *(undefined4 *)(iVar7 + 0x118) = 0;
      FUN_00759ed0(puVar18,local_b0,0x7b,0x7d);
      local_8 = 0xffffffff;
      if (7 < local_9c) {
        FUN_0089120c(local_b0[0]);
      }
      uVar5 = local_58;
      iVar7 = local_5c;
      local_b0[0] = local_b0[0] & 0xffff0000;
      local_9c = 7;
      local_a0 = 0;
      (**(code **)(**(int **)(local_5c + 0x1d4 + local_58 * 4) + 0x94))(0);
      (**(code **)(**(int **)(iVar7 + 0x1e0 + uVar5 * 4) + 0x94))(1);
    }
    else {
      uVar13 = 0;
      if (*(int *)(iVar7 + 0x48) - *(int *)(iVar7 + 0x44) >> 3 != 0) {
        local_54 = *(int **)(iVar7 + 0x44);
        piVar15 = local_54;
        do {
          if (*piVar15 == local_58 + 1) {
            local_54 = local_54 + uVar13 * 2;
            goto LAB_005f153d;
          }
          uVar13 = uVar13 + 1;
          piVar15 = piVar15 + 2;
        } while (uVar13 < (uint)(*(int *)(iVar7 + 0x48) - (int)local_54 >> 3));
      }
      local_54 = (int *)(*(int *)(iVar7 + 0x44) + local_58 * 8);
LAB_005f153d:
      if ((local_54 == (int *)0x0) || (local_54[1] < 1)) {
        iVar7 = *(int *)(local_5c + 0x1d4 + local_58 * 4);
        if ((*(char *)(iVar7 + 0xa4) != '\0') &&
           ((*(int **)(iVar7 + 0x94) != (int *)0x0 &&
            (iVar9 = (**(code **)(**(int **)(iVar7 + 0x94) + 4))(), iVar9 == 0xbf6b)))) {
          iVar7 = *(int *)(iVar7 + 0x94);
          iVar9 = *(int *)(iVar7 + 0x10);
          if (iVar9 != 0) {
            piVar15 = *(int **)(iVar9 + 8);
            if (piVar15 != (int *)0x0) {
              piVar12 = piVar15 + 0x27;
              *piVar12 = *piVar12 + -1;
              if (*piVar12 == 0) {
                (**(code **)(*piVar15 + 0x28))();
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
        local_50 = 4;
        FUN_005740f0(&local_50);
        if (local_68 == DAT_00fe5ac8) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        psVar14 = (short *)(local_68 + 0x10);
        if (7 < *(uint *)(local_68 + 0x24)) {
          psVar14 = *(short **)psVar14;
        }
        local_1c = 7;
        local_20 = 0;
        local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
        psVar10 = psVar14;
        do {
          sVar2 = *psVar10;
          psVar10 = psVar10 + 1;
        } while (sVar2 != 0);
        FUN_00402160(psVar14,(int)psVar10 - (int)(psVar14 + 1) >> 1);
        iVar7 = *(int *)(iVar4 + 0x1ec + uVar5 * 4);
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
        local_50 = 7;
        FUN_005740f0(&local_50);
        if (local_70 == DAT_00fe5ac8) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        psVar14 = (short *)(local_70 + 0x10);
        if (7 < *(uint *)(local_70 + 0x24)) {
          psVar14 = *(short **)psVar14;
        }
        local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
        local_1c = 7;
        local_20 = 0;
        psVar10 = psVar14;
        do {
          sVar2 = *psVar10;
          psVar10 = psVar10 + 1;
        } while (sVar2 != 0);
        FUN_00402160(psVar14,(int)psVar10 - (int)(psVar14 + 1) >> 1);
        iVar7 = *(int *)(iVar4 + 0x1f8 + uVar5 * 4);
        local_8 = 7;
LAB_005f1bff:
        FUN_007578f0();
        FUN_00759ed0(iVar7 + 0xe8,local_30,0x7b,0x7d);
        local_8 = 0xffffffff;
        if (7 < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        (**(code **)(**(int **)(iVar4 + 0x1d4 + uVar5 * 4) + 0x94))(0);
        (**(code **)(**(int **)(iVar4 + 0x1e0 + uVar5 * 4) + 0x94))(0);
      }
      else {
        local_50 = local_54[1];
        iVar7 = FUN_004034e0();
        FUN_008438c0(&local_50);
        if (local_74 == *(int *)(iVar7 + 4)) {
          iVar7 = 0;
        }
        else {
          iVar7 = *(int *)(local_74 + 0x10);
        }
        psVar14 = (short *)(iVar7 + 0x98);
        if (7 < *(uint *)(iVar7 + 0xac)) {
          psVar14 = *(short **)psVar14;
        }
        local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
        local_1c = 7;
        local_20 = 0;
        psVar10 = psVar14;
        do {
          sVar2 = *psVar10;
          psVar10 = psVar10 + 1;
        } while (sVar2 != 0);
        FUN_00402160(psVar14,(int)psVar10 - (int)(psVar14 + 1) >> 1);
        local_8 = 0;
        if (*(uint *)(iVar7 + 200) < 8) {
          psVar14 = (short *)(iVar7 + 0xb4);
        }
        else {
          psVar14 = *(short **)(iVar7 + 0xb4);
        }
        local_38 = 7;
        local_3c = 0;
        local_4c[0] = (short ***)((uint)local_4c[0] & 0xffff0000);
        psVar10 = psVar14;
        do {
          sVar2 = *psVar10;
          psVar10 = psVar10 + 1;
        } while (sVar2 != 0);
        FUN_00402160(psVar14,(int)psVar10 - (int)(psVar14 + 1) >> 1);
        local_8._0_1_ = 1;
        switch(*(undefined4 *)(iVar7 + 0x5c)) {
        case 0:
          uVar17 = 0;
          break;
        case 1:
        case 2:
        case 3:
          uVar17 = 1;
          break;
        case 4:
        case 5:
          uVar17 = 2;
          break;
        case 6:
        case 7:
          uVar17 = 3;
          break;
        case 8:
        case 9:
        case 10:
          uVar17 = 4;
          break;
        default:
          uVar17 = 5;
        }
        FUN_005e1e00(*(undefined4 *)(iVar7 + 8),uVar17);
        FUN_005e1e00(*(undefined4 *)(iVar7 + 8),uVar17);
        FUN_005e1bc0(local_54[1]);
        FUN_00745060();
        ppppsVar16 = (short ****)local_30[0];
        if (local_1c < 8) {
          ppppsVar16 = local_30;
        }
        local_90[0] = local_90[0] & 0xffff0000;
        local_7c = 7;
        local_80 = 0;
        ppppsVar8 = ppppsVar16;
        do {
          sVar2 = *(short *)ppppsVar8;
          ppppsVar8 = (short ****)((int)ppppsVar8 + 2);
        } while (sVar2 != 0);
        FUN_00402160(ppppsVar16,(int)ppppsVar8 - (int)((int)ppppsVar16 + 2) >> 1);
        uVar5 = local_58;
        iVar4 = local_5c;
        iVar7 = *(int *)(local_5c + 0x1ec + local_58 * 4);
        local_8._0_1_ = 2;
        FUN_007578f0();
        FUN_00759ed0(iVar7 + 0xe8,local_90,0x7b,0x7d);
        local_8._0_1_ = 1;
        if (7 < local_7c) {
          FUN_0089120c(local_90[0]);
        }
        ppppsVar16 = (short ****)local_4c[0];
        if (local_38 < 8) {
          ppppsVar16 = local_4c;
        }
        local_90[0] = local_90[0] & 0xffff0000;
        local_7c = 7;
        local_80 = 0;
        ppppsVar8 = ppppsVar16;
        do {
          sVar2 = *(short *)ppppsVar8;
          ppppsVar8 = (short ****)((int)ppppsVar8 + 2);
        } while (sVar2 != 0);
        FUN_00402160(ppppsVar16,(int)ppppsVar8 - (int)((int)ppppsVar16 + 2) >> 1);
        iVar7 = *(int *)(iVar4 + 0x1f8 + uVar5 * 4);
        local_8._0_1_ = 3;
        FUN_007578f0();
        FUN_00759ed0(iVar7 + 0xe8,local_90,0x7b,0x7d);
        local_8 = CONCAT31(local_8._1_3_,1);
        if (7 < local_7c) {
          FUN_0089120c(local_90[0]);
        }
        (**(code **)(**(int **)(iVar4 + 0x1d4 + uVar5 * 4) + 0x94))(1);
        (**(code **)(**(int **)(iVar4 + 0x1e0 + uVar5 * 4) + 0x94))(0);
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
    local_58 = local_58 + 1;
    if (2 < local_58) {
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  } while( true );
}

