
/* WARNING: Removing unreachable block (ram,0x0079f8fe) */
/* WARNING: Removing unreachable block (ram,0x0079f900) */
/* WARNING: Removing unreachable block (ram,0x0079f920) */

undefined1 ** FUN_0079efc0(undefined1 **param_1,int *param_2,int param_3,int *param_4)

{
  char cVar1;
  ushort uVar2;
  int *piVar3;
  undefined4 uVar4;
  char *pcVar5;
  ushort *puVar6;
  int *piVar7;
  int *piVar8;
  int **ppiVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  undefined1 *puVar14;
  uint uVar15;
  uint uVar16;
  int *piVar17;
  char *pcVar18;
  undefined **local_9c [3];
  undefined1 local_90 [4];
  int *local_8c;
  undefined4 local_80;
  int *local_7c;
  int *local_78;
  undefined4 local_74;
  undefined1 local_6c [4];
  undefined4 *local_68;
  undefined4 local_64;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int *local_4c;
  int *local_48;
  undefined4 local_44 [3];
  int local_38;
  char *local_34;
  char *local_30;
  int local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  undefined1 *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00938bab;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_80 = 0;
  local_8 = 1;
  local_30 = (char *)FUN_00891268(0x28,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8._0_1_ = 2;
  if (local_30 == (char *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_0079ce90(local_30);
  }
  local_8._0_1_ = 1;
  local_1c = (undefined1 *)0x0;
  local_18 = (int *)0x0;
  FUN_007a3400(&local_1c,uVar4);
  puVar14 = local_1c;
  local_8._0_1_ = 3;
  *local_1c = 1;
  FUN_007a0da0();
  *(int **)(puVar14 + 4) = param_2;
  FUN_007c5be0();
  piVar7 = (int *)**(int **)(param_3 + 0x4c);
  if (piVar7 != *(int **)(param_3 + 0x4c)) {
    do {
      FUN_007c5100(param_2,(short)piVar7[3],*(undefined2 *)((int)piVar7 + 0xe),puVar14 + 0x10);
      if (*(char *)((int)piVar7 + 0x11) == '\0') {
        piVar13 = (int *)piVar7[2];
        if (*(char *)((int)piVar13 + 0x11) == '\0') {
          cVar1 = *(char *)(*piVar13 + 0x11);
          piVar7 = piVar13;
          piVar13 = (int *)*piVar13;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar13 + 0x11);
            piVar7 = piVar13;
            piVar13 = (int *)*piVar13;
          }
        }
        else {
          cVar1 = *(char *)(piVar7[1] + 0x11);
          piVar8 = (int *)piVar7[1];
          piVar13 = piVar7;
          while ((piVar7 = piVar8, cVar1 == '\0' && (piVar13 == (int *)piVar7[2]))) {
            cVar1 = *(char *)(piVar7[1] + 0x11);
            piVar8 = (int *)piVar7[1];
            piVar13 = piVar7;
          }
        }
      }
    } while (piVar7 != *(int **)(param_3 + 0x4c));
  }
  piVar7 = (int *)**(int **)(param_3 + 0x5c);
  iVar10 = param_3;
  if (piVar7 != *(int **)(param_3 + 0x5c)) {
    do {
      if ((DAT_00fe1bc0 & 1) == 0) {
        DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
        local_8._0_1_ = 4;
        FUN_007bef00();
        _atexit((_func_4879 *)&LAB_00bcec50);
        local_8._0_1_ = 3;
        iVar10 = param_3;
      }
      local_54 = piVar7[6];
      local_50 = piVar7[7];
      FUN_004dd400(&DAT_00fe1b60,&local_14,&local_54);
      if ((local_14 != DAT_00fe1b64) &&
         (piVar13 = (int *)local_14[6], local_24 = piVar13, piVar13 != (int *)0x0)) {
        pcVar5 = (char *)FUN_00891268(0x50);
        local_30 = pcVar5;
        if (pcVar5 == (char *)0x0) {
          pcVar5 = (char *)0x0;
        }
        else {
          if ((DAT_00fe1bc0 & 1) == 0) {
            DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
            local_8._0_1_ = 6;
            FUN_007bef00();
            _atexit((_func_4879 *)&LAB_00bcec50);
          }
          local_8._0_1_ = 5;
          local_5c = piVar7[6];
          local_58 = piVar7[7];
          puVar6 = (ushort *)FUN_007c0140();
          local_20 = (int *)(uint)*puVar6;
          if ((DAT_00fe1bc0 & 1) == 0) {
            DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
            local_8._0_1_ = 7;
            FUN_007bef00();
            _atexit((_func_4879 *)&LAB_00bcec50);
            local_8._0_1_ = 5;
          }
          local_2c = piVar7[6];
          local_28 = (int *)piVar7[7];
          puVar6 = (ushort *)FUN_007c0140();
          uVar2 = *puVar6;
          iVar10 = piVar7[6];
          iVar12 = piVar7[7];
          *(int *)(pcVar5 + 0x10) = piVar7[4];
          *(int *)(pcVar5 + 8) = iVar10;
          *(int *)(pcVar5 + 0xc) = iVar12;
          pcVar5[0x14] = '\0';
          pcVar5[0x15] = '\0';
          pcVar5[0x16] = '\0';
          pcVar5[0x17] = '\0';
          *(undefined ***)pcVar5 = IS3D::CItem::vftable;
          pcVar5[0x18] = '\0';
          pcVar5[0x19] = '\0';
          pcVar5[0x1a] = '\0';
          pcVar5[0x1b] = '\0';
          pcVar5[0x1c] = '\0';
          pcVar5[0x1d] = '\0';
          pcVar5[0x1e] = '\0';
          pcVar5[0x1f] = '\0';
          pcVar5[0x20] = '\0';
          pcVar5[0x21] = '\0';
          pcVar5[0x22] = '\0';
          pcVar5[0x23] = '\0';
          *(uint *)(pcVar5 + 0x44) = (uint)uVar2;
          *(uint *)(pcVar5 + 0x48) = (uint)local_20 & 0xffff;
          piVar13 = local_24;
        }
        local_8._0_1_ = 3;
        FUN_007d4fa0(piVar13);
        local_38 = piVar7[4];
        puVar14 = local_1c + 0x18;
        local_34 = pcVar5;
        uVar4 = FUN_007a34a0();
        FUN_007c0b70(puVar14,uVar4);
        iVar10 = param_3;
      }
      if (*(char *)((int)piVar7 + 0x21) == '\0') {
        piVar13 = (int *)piVar7[2];
        if (*(char *)((int)piVar13 + 0x21) == '\0') {
          cVar1 = *(char *)(*piVar13 + 0x21);
          piVar7 = piVar13;
          piVar13 = (int *)*piVar13;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar13 + 0x21);
            piVar7 = piVar13;
            piVar13 = (int *)*piVar13;
          }
        }
        else {
          cVar1 = *(char *)(piVar7[1] + 0x21);
          piVar8 = (int *)piVar7[1];
          piVar13 = piVar7;
          while ((piVar7 = piVar8, cVar1 == '\0' && (piVar13 == (int *)piVar7[2]))) {
            cVar1 = *(char *)(piVar7[1] + 0x21);
            piVar8 = (int *)piVar7[1];
            piVar13 = piVar7;
          }
        }
      }
    } while (piVar7 != *(int **)(iVar10 + 0x5c));
  }
  puVar14 = local_1c;
  if (*(int *)(local_1c + 0x10) != 0) {
    local_7c = (int *)0x0;
    local_78 = (int *)0x0;
    local_74 = 0;
    local_8 = CONCAT31(local_8._1_3_,8);
    piVar7 = (int *)**(int **)(local_1c + 0x1c);
    if (piVar7 != *(int **)(local_1c + 0x1c)) {
      do {
        FUN_007d2ca0(piVar7[6]);
        if (*(char *)((int)piVar7 + 0x21) == '\0') {
          piVar13 = (int *)piVar7[2];
          if (*(char *)((int)piVar13 + 0x21) == '\0') {
            cVar1 = *(char *)(*piVar13 + 0x21);
            piVar7 = piVar13;
            piVar13 = (int *)*piVar13;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar13 + 0x21);
              piVar7 = piVar13;
              piVar13 = (int *)*piVar13;
            }
          }
          else {
            cVar1 = *(char *)(piVar7[1] + 0x21);
            piVar8 = (int *)piVar7[1];
            piVar13 = piVar7;
            while ((piVar7 = piVar8, cVar1 == '\0' && (piVar13 == (int *)piVar7[2]))) {
              cVar1 = *(char *)(piVar7[1] + 0x21);
              piVar8 = (int *)piVar7[1];
              piVar13 = piVar7;
            }
          }
        }
        iVar10 = param_3;
      } while (piVar7 != *(int **)(puVar14 + 0x1c));
    }
    local_28 = (int *)**(int **)(puVar14 + 0x1c);
    if (local_28 != *(int **)(puVar14 + 0x1c)) {
      do {
        iVar10 = *(int *)(local_28[6] + 8);
        pcVar5 = *(char **)(local_28[6] + 0xc);
        if ((DAT_00fe1bc0 & 1) == 0) {
          DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
          local_8._0_1_ = 9;
          FUN_007bef00();
          _atexit((_func_4879 *)&LAB_00bcec50);
          local_8 = CONCAT31(local_8._1_3_,8);
        }
        local_38 = iVar10;
        local_34 = pcVar5;
        local_14 = (int *)FUN_007c01e0(&DAT_00fe1bb0);
        iVar10 = *local_14;
        uVar16 = 0;
        if (local_14[1] - iVar10 >> 2 != 0) {
          do {
            local_54 = *(int *)(iVar10 + uVar16 * 4);
            iVar12 = *(int *)(local_1c + 0x1c);
            local_50 = 0;
            piVar7 = (int *)FUN_004dd400(local_1c + 0x18,&local_30,&local_54);
            if (*piVar7 != iVar12) {
              local_5c = *(int *)(iVar10 + uVar16 * 4);
              local_58 = 0;
              piVar7 = (int *)FUN_004dd400(local_1c + 0x18,&local_20,&local_5c);
              *(undefined4 *)(*(int *)(*piVar7 + 0x18) + 0x14) = 1;
            }
            iVar10 = *local_14;
            uVar16 = uVar16 + 1;
          } while (uVar16 < (uint)(local_14[1] - iVar10 >> 2));
        }
        if (*(char *)((int)local_28 + 0x21) == '\0') {
          piVar7 = (int *)local_28[2];
          if (*(char *)((int)piVar7 + 0x21) == '\0') {
            cVar1 = *(char *)(*piVar7 + 0x21);
            local_28 = piVar7;
            piVar7 = (int *)*piVar7;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar7 + 0x21);
              local_28 = piVar7;
              piVar7 = (int *)*piVar7;
            }
          }
          else {
            cVar1 = *(char *)(local_28[1] + 0x21);
            piVar13 = (int *)local_28[1];
            piVar7 = local_28;
            while ((local_28 = piVar13, cVar1 == '\0' && (piVar7 == (int *)local_28[2]))) {
              cVar1 = *(char *)(local_28[1] + 0x21);
              piVar13 = (int *)local_28[1];
              piVar7 = local_28;
            }
          }
        }
        iVar10 = param_3;
      } while (local_28 != *(int **)(local_1c + 0x1c));
    }
    piVar7 = *(int **)(iVar10 + 0x4c);
    cVar1 = *(char *)(piVar7[1] + 0x11);
    local_14 = piVar7;
    piVar13 = (int *)piVar7[1];
    while (cVar1 == '\0') {
      if (*(ushort *)(piVar13 + 3) < 9) {
        piVar8 = (int *)piVar13[2];
        piVar13 = local_14;
      }
      else {
        piVar8 = (int *)*piVar13;
      }
      local_14 = piVar13;
      piVar13 = piVar8;
      cVar1 = *(char *)((int)piVar8 + 0x11);
    }
    if ((local_14 == piVar7) || (9 < *(ushort *)(local_14 + 3))) {
      local_20 = piVar7;
      ppiVar9 = &local_20;
    }
    else {
      ppiVar9 = &local_14;
    }
    if ((*ppiVar9 != piVar7) &&
       (piVar7 = (int *)**(int **)(local_1c + 0x1c), piVar7 != *(int **)(local_1c + 0x1c))) {
      do {
        iVar10 = piVar7[6];
        local_44[0] = *(undefined4 *)(iVar10 + 8);
        if (((char)((uint)*(undefined4 *)(iVar10 + 0xc) >> 0x18) != '\0') &&
           ((short)*(undefined4 *)(iVar10 + 0xc) != 9)) {
          *(undefined4 *)(iVar10 + 0x14) = 1;
        }
        if (*(char *)((int)piVar7 + 0x21) == '\0') {
          piVar13 = (int *)piVar7[2];
          if (*(char *)((int)piVar13 + 0x21) == '\0') {
            cVar1 = *(char *)(*piVar13 + 0x21);
            piVar7 = piVar13;
            piVar13 = (int *)*piVar13;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar13 + 0x21);
              piVar7 = piVar13;
              piVar13 = (int *)*piVar13;
            }
          }
          else {
            cVar1 = *(char *)(piVar7[1] + 0x21);
            piVar8 = (int *)piVar7[1];
            piVar13 = piVar7;
            while ((piVar7 = piVar8, cVar1 == '\0' && (piVar13 == (int *)piVar7[2]))) {
              cVar1 = *(char *)(piVar7[1] + 0x21);
              piVar8 = (int *)piVar7[1];
              piVar13 = piVar7;
            }
          }
        }
      } while (piVar7 != *(int **)(local_1c + 0x1c));
    }
    local_64 = 0;
    local_68 = (undefined4 *)FUN_00891268(0x2c);
    if (local_68 == (undefined4 *)0x0) {
      local_30 = (char *)0x0;
      std::exception::exception((exception *)local_9c,&local_30);
      local_9c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_9c,&DAT_00c857a8);
    }
    *local_68 = local_68;
    local_68[1] = local_68;
    local_68[2] = local_68;
    *(undefined1 *)(local_68 + 10) = 1;
    *(undefined1 *)((int)local_68 + 0x29) = 1;
    local_8._0_1_ = 10;
    piVar7 = (int *)(((int)local_78 - (int)local_7c) / 0x1c);
    piVar8 = local_7c;
    for (piVar13 = piVar7; piVar3 = local_7c, piVar17 = local_20, puVar14 = local_1c,
        piVar11 = local_14, piVar13 != (int *)0x0; piVar13 = (int *)((int)piVar13 + -1)) {
      uVar4 = FUN_007a2660(piVar8);
      FUN_004ad530(local_6c,local_44,uVar4);
      piVar8 = piVar8 + 7;
    }
    while (local_14 = piVar7, local_20 = piVar3, local_1c = puVar14, local_14 != (int *)0x0) {
      piVar7 = local_20;
      if (0xf < (uint)local_20[5]) {
        piVar7 = (int *)*local_20;
      }
      FUN_007d4030(*(undefined4 *)(puVar14 + 0x10),piVar7);
      local_28 = (int *)**(undefined4 **)(puVar14 + 0x1c);
      if (local_28 != *(int **)(puVar14 + 0x1c)) {
        do {
          iVar10 = local_28[6];
          local_4c = (int *)0x0;
          local_48 = (int *)0x0;
          local_44[0] = 0;
          local_8._0_1_ = 0xb;
          FUN_007d2ca0(iVar10);
          FUN_007a1470(local_90,local_6c);
          local_8 = CONCAT31(local_8._1_3_,0xc);
          local_24 = local_4c;
          if (local_4c != local_48) {
            do {
              FUN_007a1b10(local_90,&local_38,local_24);
              FUN_004ad180(local_38,local_34);
              local_24 = local_24 + 7;
            } while (local_24 != local_48);
          }
          iVar12 = *(int *)(iVar10 + 0x18);
          uVar16 = 0;
          if (*(int *)(iVar10 + 0x1c) - iVar12 >> 2 != 0) {
            do {
              (**(code **)(**(int **)(iVar12 + uVar16 * 4) + 0x18))();
              iVar12 = *(int *)(iVar10 + 0x18);
              uVar16 = uVar16 + 1;
            } while (uVar16 < (uint)(*(int *)(iVar10 + 0x1c) - iVar12 >> 2));
          }
          piVar7 = (int *)*local_8c;
          if (piVar7 != local_8c) {
            iVar12 = *(int *)(iVar10 + 0x18);
            uVar16 = *(int *)(iVar10 + 0x1c) - iVar12 >> 2;
            do {
              local_24 = piVar7 + 3;
              if (0xf < (uint)piVar7[8]) {
                local_24 = (int *)*local_24;
              }
              uVar15 = 0;
              if (uVar16 != 0) {
                do {
                  (**(code **)(**(int **)(iVar12 + uVar15 * 4) + 0x10))(local_24);
                  iVar12 = *(int *)(iVar10 + 0x18);
                  uVar15 = uVar15 + 1;
                  uVar16 = *(int *)(iVar10 + 0x1c) - iVar12 >> 2;
                } while (uVar15 < uVar16);
              }
              if (*(char *)((int)piVar7 + 0x29) == '\0') {
                piVar13 = (int *)piVar7[2];
                if (*(char *)((int)piVar13 + 0x29) == '\0') {
                  cVar1 = *(char *)(*piVar13 + 0x29);
                  piVar7 = piVar13;
                  piVar13 = (int *)*piVar13;
                  while (cVar1 == '\0') {
                    cVar1 = *(char *)(*piVar13 + 0x29);
                    piVar7 = piVar13;
                    piVar13 = (int *)*piVar13;
                  }
                }
                else {
                  cVar1 = *(char *)(piVar7[1] + 0x29);
                  piVar8 = (int *)piVar7[1];
                  piVar13 = piVar7;
                  while ((piVar7 = piVar8, cVar1 == '\0' && (piVar13 == (int *)piVar7[2]))) {
                    cVar1 = *(char *)(piVar7[1] + 0x29);
                    piVar8 = (int *)piVar7[1];
                    piVar13 = piVar7;
                  }
                }
              }
            } while (piVar7 != local_8c);
          }
          local_8._0_1_ = 0xd;
          FUN_004ad180(*local_8c,local_8c);
          FUN_0089120c(local_8c);
          piVar13 = local_48;
          local_8._0_1_ = 10;
          piVar7 = local_4c;
          if (local_4c != (int *)0x0) {
            for (; piVar7 != piVar13; piVar7 = piVar7 + 7) {
              if (0xf < (uint)piVar7[5]) {
                FUN_0089120c(*piVar7);
              }
              piVar7[5] = 0xf;
              piVar7[4] = 0;
              *(undefined1 *)piVar7 = 0;
            }
            FUN_0089120c(local_4c);
          }
          local_4c = (int *)0x0;
          local_48 = (int *)0x0;
          local_44[0] = 0;
          if (*(char *)((int)local_28 + 0x21) == '\0') {
            piVar7 = (int *)local_28[2];
            if (*(char *)((int)piVar7 + 0x21) == '\0') {
              cVar1 = *(char *)(*piVar7 + 0x21);
              local_28 = piVar7;
              piVar7 = (int *)*piVar7;
              while (cVar1 == '\0') {
                cVar1 = *(char *)(*piVar7 + 0x21);
                local_28 = piVar7;
                piVar7 = (int *)*piVar7;
              }
            }
            else {
              cVar1 = *(char *)(local_28[1] + 0x21);
              piVar13 = (int *)local_28[1];
              piVar7 = local_28;
              while ((local_28 = piVar13, cVar1 == '\0' && (piVar7 == (int *)local_28[2]))) {
                cVar1 = *(char *)(local_28[1] + 0x21);
                piVar13 = (int *)local_28[1];
                piVar7 = local_28;
              }
            }
          }
        } while (local_28 != *(int **)(local_1c + 0x1c));
      }
      local_20 = local_20 + 7;
      local_14 = (int *)((int)local_14 + -1);
      piVar3 = local_20;
      piVar17 = local_20;
      puVar14 = local_1c;
      piVar11 = local_14;
      piVar7 = local_14;
    }
    iVar10 = param_2[0x39];
    piVar7 = *(int **)(iVar10 + 0x38);
    cVar1 = *(char *)(piVar7[1] + 0x15);
    param_2 = piVar7;
    piVar13 = (int *)piVar7[1];
    while (cVar1 == '\0') {
      if (piVar13[3] == 0) {
        piVar8 = (int *)piVar13[2];
        piVar13 = param_2;
      }
      else {
        piVar8 = (int *)*piVar13;
      }
      param_2 = piVar13;
      piVar13 = piVar8;
      cVar1 = *(char *)((int)piVar8 + 0x15);
    }
    if ((param_2 == piVar7) || (1 < (uint)param_2[3])) {
      local_14 = piVar7;
      ppiVar9 = &local_14;
    }
    else {
      ppiVar9 = &param_2;
      local_14 = piVar11;
    }
    local_20 = piVar17;
    if (*ppiVar9 != piVar7) {
      piVar13 = (int *)FUN_00891268(0x18);
      puVar14 = local_1c;
      piVar7 = (int *)0x0;
      if (piVar13 != (int *)0x0) {
        piVar13[3] = 0;
        piVar13[2] = 0;
        *piVar13 = iVar10;
        piVar13[4] = 1;
        piVar13[5] = 1;
        piVar7 = *(int **)(iVar10 + 0x38);
        cVar1 = *(char *)(piVar7[1] + 0x15);
        piVar8 = piVar7;
        piVar17 = (int *)piVar7[1];
        while (cVar1 == '\0') {
          if (piVar17[3] == 0) {
            piVar11 = (int *)piVar17[2];
            piVar17 = piVar8;
          }
          else {
            piVar11 = (int *)*piVar17;
          }
          piVar8 = piVar17;
          piVar17 = piVar11;
          cVar1 = *(char *)((int)piVar11 + 0x15);
        }
        if ((piVar8 == piVar7) || (1 < (uint)piVar8[3])) {
          local_14 = piVar7;
          ppiVar9 = &local_14;
        }
        else {
          ppiVar9 = &param_2;
        }
        if (*ppiVar9 == piVar7) {
          iVar12 = 0;
        }
        else {
          iVar12 = (*ppiVar9)[4];
        }
        param_2 = *(int **)(iVar12 + 4);
        piVar13[1] = (int)param_2;
        piVar7 = piVar13;
      }
      *(int *)(iVar10 + 0x2c) = *(int *)(iVar10 + 0x2c) + 1;
      *(int **)(local_1c + 0x14) = piVar7;
      iVar10 = FUN_007c6700(*(undefined4 *)(*(int *)(local_1c + 0x10) + 0x10),"Face.SKIN");
      piVar7[3] = iVar10;
    }
    param_2 = *(int **)(puVar14 + 0x10);
    iVar10 = param_2[0x1d];
    *(undefined4 *)(iVar10 + 0x14) = 0;
    *(undefined4 *)(iVar10 + 0x18) = 0;
    if (*(int *)(iVar10 + 4) != *(int *)(iVar10 + 8)) {
      *(int *)(iVar10 + 8) = *(int *)(iVar10 + 4);
    }
    FUN_007ee9a0(param_2[4]);
    FUN_007eebf0();
    if (*(int *)(puVar14 + 0x10) != 0) {
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8._0_1_ = 0xe;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8._0_1_ = 10;
      }
      if (DAT_00fb774c == 3) {
        if ((DAT_00fb79e8 & 1) == 0) {
          DAT_00fb79e8 = DAT_00fb79e8 | 1;
          local_8._0_1_ = 0xf;
          FUN_00798de0();
          _atexit((_func_4879 *)&LAB_00bcd2e0);
          local_8._0_1_ = 10;
        }
        piVar7 = DAT_00fb7744;
        local_14 = *(int **)(puVar14 + 0x10);
        uVar16 = DAT_00fb7744[1] - *DAT_00fb7744 >> 2;
        uVar15 = 0;
        if (uVar16 != 0) {
LAB_0079f9c2:
          pcVar18 = "SHADER-Cell";
          pcVar5 = (char *)(**(code **)(**(int **)(*piVar7 + uVar15 * 4) + 8))();
          iVar10 = __stricmp(pcVar5,pcVar18);
          if (iVar10 != 0) goto code_r0x0079f9e0;
          iVar10 = **(int **)(*piVar7 + uVar15 * 4);
          piVar7 = local_14;
LAB_0079fa6f:
          (**(code **)(iVar10 + 0xc))(piVar7);
        }
      }
      else {
        if ((DAT_00fb79e8 & 1) == 0) {
          DAT_00fb79e8 = DAT_00fb79e8 | 1;
          local_8._0_1_ = 0x10;
          FUN_00798de0();
          _atexit((_func_4879 *)&LAB_00bcd2e0);
          local_8._0_1_ = 10;
        }
        piVar7 = DAT_00fb7744;
        param_2 = *(int **)(local_1c + 0x10);
        uVar16 = DAT_00fb7744[1] - *DAT_00fb7744 >> 2;
        uVar15 = 0;
        if (uVar16 != 0) {
          do {
            pcVar18 = "Fixed";
            pcVar5 = (char *)(**(code **)(**(int **)(*piVar7 + uVar15 * 4) + 8))();
            iVar10 = __stricmp(pcVar5,pcVar18);
            if (iVar10 == 0) {
              iVar10 = **(int **)(*piVar7 + uVar15 * 4);
              piVar7 = param_2;
              goto LAB_0079fa6f;
            }
            uVar15 = uVar15 + 1;
          } while (uVar15 < uVar16);
        }
      }
    }
LAB_0079fa75:
    FUN_007d3bd0(*(undefined4 *)(local_1c + 0x10));
    local_8._0_1_ = 0x11;
    FUN_004ad180(*local_68,local_68);
    FUN_0089120c(local_68);
    piVar13 = local_78;
    piVar7 = local_7c;
    if (local_7c != (int *)0x0) {
      for (; piVar7 != piVar13; piVar7 = piVar7 + 7) {
        if (0xf < (uint)piVar7[5]) {
          FUN_0089120c(*piVar7);
        }
        piVar7[5] = 0xf;
        piVar7[4] = 0;
        *(undefined1 *)piVar7 = 0;
      }
      FUN_0089120c(local_7c);
    }
  }
  *param_1 = (undefined1 *)0x0;
  param_1[1] = (undefined1 *)0x0;
  piVar7 = local_18;
  if (param_1 != &local_1c) {
    piVar7 = (int *)param_1[1];
    param_1[1] = (undefined1 *)local_18;
    *param_1 = local_1c;
  }
  local_80 = 1;
  local_8._0_1_ = 1;
  if (piVar7 != (int *)0x0) {
    LOCK();
    iVar10 = piVar7[1] + -1;
    piVar7[1] = iVar10;
    UNLOCK();
    if (iVar10 == 0) {
      (**(code **)*piVar7)();
      LOCK();
      iVar10 = piVar7[2] + -1;
      piVar7[2] = iVar10;
      UNLOCK();
      if (iVar10 == 0) {
        (**(code **)(*piVar7 + 4))();
      }
    }
  }
  piVar7 = param_4;
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_4 != (int *)0x0) {
    LOCK();
    iVar10 = param_4[1] + -1;
    param_4[1] = iVar10;
    UNLOCK();
    if (iVar10 == 0) {
      (**(code **)*param_4)();
      piVar13 = piVar7 + 2;
      LOCK();
      iVar10 = *piVar13 + -1;
      *piVar13 = iVar10;
      UNLOCK();
      if (iVar10 == 0) {
        (**(code **)(*piVar7 + 4))();
      }
    }
  }
  ExceptionList = local_10;
  return param_1;
code_r0x0079f9e0:
  uVar15 = uVar15 + 1;
  if (uVar16 <= uVar15) goto LAB_0079fa75;
  goto LAB_0079f9c2;
}

