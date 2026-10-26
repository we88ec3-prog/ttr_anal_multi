
/* WARNING: Type propagation algorithm not settling */

void FUN_00659bc0(int *param_1)

{
  char cVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  short *******pppppppsVar8;
  undefined4 *puVar9;
  undefined4 **ppuVar10;
  undefined4 *puVar11;
  uint uVar12;
  int *piVar13;
  int *piVar14;
  byte bVar15;
  int unaff_ESI;
  uint *puVar16;
  short *psVar17;
  int iVar18;
  undefined4 auStack_1f4 [2];
  undefined4 uStack_1ec;
  short *psStack_1bc;
  short *******pppppppsStack_1b8;
  char *pcStack_1b4;
  int iStack_1b0;
  short *local_1ac;
  undefined4 *puStack_1a8;
  undefined4 *puStack_1a4;
  undefined4 *puStack_1a0;
  undefined4 uStack_19c;
  undefined4 *local_198;
  undefined4 *puStack_194;
  undefined4 *puStack_190;
  undefined4 *puStack_188;
  undefined4 *puStack_184;
  undefined4 *puStack_180;
  undefined4 *puStack_178;
  undefined4 *puStack_174;
  undefined4 *puStack_170;
  undefined4 *puStack_168;
  int iStack_164;
  int iStack_160;
  undefined4 uStack_15c;
  undefined4 *puStack_150;
  undefined4 uStack_14c;
  int *piStack_144;
  undefined **ppuStack_140;
  int *local_13c;
  undefined4 uStack_138;
  int iStack_130;
  short *psStack_12c;
  undefined4 uStack_128;
  int iStack_120;
  int iStack_11c;
  int iStack_110;
  int iStack_10c;
  short *******apppppppsStack_100 [2];
  undefined4 uStack_f8;
  undefined4 uStack_f0;
  uint uStack_ec;
  uint auStack_e0 [4];
  undefined4 uStack_d0;
  uint uStack_cc;
  uint uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  int iStack_b4;
  uint auStack_b0 [2];
  undefined2 *apuStack_a8 [4];
  undefined1 auStack_98 [116];
  uint uStack_24;
  void *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00948944;
  local_14 = ExceptionList;
  local_1c = (void *)(DAT_00d61f20 ^ (uint)&psStack_1bc);
  ExceptionList = &local_14;
  local_1ac = (short *)0x0;
  local_13c = param_1;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  local_198 = DAT_00fab134;
  if (DAT_00fab134 == (undefined4 *)0x0) {
    (**(code **)(*(int *)param_1[0x56] + 0x94))();
    (**(code **)(*(int *)param_1[0x45] + 0x94))();
    goto LAB_00659c76;
  }
  (**(code **)(*(int *)param_1[0x56] + 0x94))();
  (**(code **)(*(int *)param_1[0x45] + 0x94))();
  FUN_007da5a0();
  local_14 = (void *)0x1;
  uStack_1ec = 0x659ce6;
  _eh_vector_constructor_iterator_
            (auStack_98,0x1c,4,(_func_void_void_ptr *)&LAB_00402140,FUN_004fa440);
  local_14._0_1_ = 2;
  apuStack_a8[0] = (undefined2 *)0x0;
  apuStack_a8[1] = (undefined2 *)0x0;
  apuStack_a8[2] = (undefined2 *)0x0;
  apuStack_a8[3] = (undefined2 *)0x0;
  psVar17 = (short *)((iStack_10c - iStack_110) / 0x14);
  puStack_1a4 = (undefined4 *)&Rsrc_Icon_1_412.field_0x26e85;
  puStack_1a8 = (undefined4 *)0x0;
  if (psVar17 != (short *)0x0) {
    puVar16 = (uint *)(iStack_110 + 0xc);
    local_1ac = psVar17;
    do {
      if ((byte)(*(char *)((int)puVar16 + -1) - 1U) < 2) {
        FUN_006599f0();
        local_14._0_1_ = 3;
        iVar18 = 0;
        if ((ushort)puVar16[-3] < 3) {
          iVar18 = (ushort)puVar16[-3] + 1;
        }
        if ((short)puVar16[-2] == 5) {
          uVar12 = *puVar16;
          *(undefined1 *)((int)&puStack_1a8 + iVar18) = 1;
          auStack_e0[iVar18] = uVar12;
        }
        iStack_1b0 = (int)*(short *)((int)puVar16 + -6);
        pppppppsStack_1b8 = apppppppsStack_100[0];
        if (uStack_ec < 8) {
          pppppppsStack_1b8 = (short *******)apppppppsStack_100;
        }
        pcStack_1b4 = (char *)auStack_1f4;
        auStack_1f4[0]._0_2_ = 0;
        psStack_1bc = (short *)((int)pppppppsStack_1b8 + 2);
        pppppppsVar8 = pppppppsStack_1b8;
        do {
          sVar2 = *(short *)pppppppsVar8;
          pppppppsVar8 = (short *******)((int)pppppppsVar8 + 2);
        } while (sVar2 != 0);
        FUN_00402160(pppppppsStack_1b8,(int)pppppppsVar8 - (int)psStack_1bc >> 1);
        FUN_00659770(&uStack_c4,(short)puVar16[-2],puVar16[1]);
        local_14._0_1_ = 4;
        FUN_004041f0();
        local_14._0_1_ = 3;
        if (7 < auStack_b0[0]) {
          FUN_0089120c();
        }
        auStack_b0[0] = 7;
        iStack_b4 = 0;
        uStack_c4 = uStack_c4 & 0xffff0000;
        FUN_00404300();
        apuStack_a8[iVar18] = (undefined2 *)((int)apuStack_a8[iVar18] + 1);
        if (*(char *)((int)&puStack_1a4 + iVar18) != '\0') {
          *(bool *)((int)&puStack_1a4 + iVar18) =
               (short)puVar16[-1] == *(short *)((int)puVar16 + -6);
        }
        local_14._0_1_ = 2;
        if (7 < uStack_ec) {
          FUN_0089120c();
        }
      }
      puVar16 = puVar16 + 5;
      local_1ac = (short *)((int)local_1ac + -1);
    } while (local_1ac != (short *)0x0);
  }
  iStack_1b0 = 0;
  psStack_1bc = (short *)0x0;
  piVar14 = param_1 + 0x4a;
  do {
    if ((int)apuStack_a8[(int)psStack_1bc] < 1) {
      (**(code **)(*(int *)piVar14[-4] + 0x94))();
      (**(code **)(*(int *)*piVar14 + 0x94))();
    }
    else {
      (**(code **)(*(int *)piVar14[-4] + 0x94))();
      FUN_00749a00();
      (**(code **)(*param_1 + 0x174))();
      FUN_00749c50();
      pcStack_1b4 = pcStack_1b4 + 0x14;
      (**(code **)(*(int *)*piVar14 + 0x94))();
      FUN_00757800();
      FUN_00749a00();
      local_1ac = (short *)(auStack_b0[unaff_ESI] * 0x14);
      FUN_00749d00();
      (**(code **)(*param_1 + 0x174))();
      FUN_00749c50();
      (**(code **)(*(int *)*piVar14 + 200))();
      if ((*(char *)((int)&puStack_1a8 + (int)psStack_1bc) != '\0') && ((DAT_00f94390 & 1) == 0)) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_14._0_1_ = 5;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_14._0_1_ = 2;
      }
      iStack_1b0 = iStack_1b0 + (int)puStack_1a4;
      *(undefined4 *)(*piVar14 + 0x154) = 0xffffffff;
    }
    psStack_1bc = (short *)((int)psStack_1bc + 1);
    piVar14 = piVar14 + 1;
  } while ((int)psStack_1bc < 4);
  FUN_00749d00();
  (**(code **)(*param_1 + 0x174))();
  FUN_00749c50();
  FUN_0065b120();
  local_14._0_1_ = 6;
  uStack_14c = 0;
  puStack_150 = (undefined4 *)FUN_00891268();
  if (puStack_150 == (undefined4 *)0x0) {
    pcStack_1b4 = (char *)0x0;
    std::exception::exception((exception *)&ppuStack_140,&pcStack_1b4);
    ppuStack_140 = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8();
  }
  *puStack_150 = puStack_150;
  puStack_150[1] = puStack_150;
  puStack_150[2] = puStack_150;
  *(undefined1 *)(puStack_150 + 5) = 1;
  *(undefined1 *)((int)puStack_150 + 0x15) = 1;
  iStack_164 = 0;
  iStack_160 = 0;
  uStack_15c = 0;
  apuStack_a8[0] = (undefined2 *)0x0;
  apuStack_a8[1] = (undefined2 *)0x0;
  apuStack_a8[2] = (undefined2 *)0x0;
  local_198 = (undefined4 *)0x0;
  puStack_194 = (undefined4 *)0x0;
  puStack_190 = (undefined4 *)0x0;
  local_14._0_1_ = 10;
  puStack_1a0 = (undefined4 *)0x0;
  uStack_c4 = 0;
  uStack_c0 = 0;
  uStack_bc = 0;
  FUN_0065b5f0();
  iStack_b4 = 0;
  puStack_188 = (undefined4 *)0x0;
  puStack_184 = (undefined4 *)0x0;
  puStack_180 = (undefined4 *)0x0;
  puStack_178 = (undefined4 *)0x0;
  puStack_174 = (undefined4 *)0x0;
  puStack_170 = (undefined4 *)0x0;
  local_14._0_1_ = 0xd;
  pcStack_1b4 = (char *)((iStack_11c - iStack_120) / 0x18);
  pppppppsStack_1b8 = (short *******)0x0;
  if (pcStack_1b4 != (char *)0x0) {
    do {
      iVar18 = (int)*(short *)(iStack_120 + 0x14 + (int)pppppppsStack_1b8 * 0x18);
      puStack_1a8 = (undefined4 *)(iStack_120 + (int)pppppppsStack_1b8 * 0x18);
      cVar1 = *(char *)((int)puStack_150[1] + 0x15);
      puVar9 = (undefined4 *)puStack_150[1];
      puStack_1a0 = puStack_150;
      while (puVar11 = puVar9, cVar1 == '\0') {
        if ((int)puVar11[3] < iVar18) {
          puVar9 = (undefined4 *)puVar11[2];
          puVar11 = puStack_1a0;
        }
        else {
          puVar9 = (undefined4 *)*puVar11;
        }
        cVar1 = *(char *)((int)puVar9 + 0x15);
        puStack_1a0 = puVar11;
      }
      if ((puStack_1a0 == puStack_150) || (iVar18 < (int)puStack_1a0[3])) {
        puStack_1a4 = puStack_150;
        ppuVar10 = &puStack_1a4;
      }
      else {
        ppuVar10 = &puStack_1a0;
      }
      if (*ppuVar10 == puStack_150) {
        local_1ac = (short *)((iStack_160 - iStack_164) / 0x1c);
        iStack_130 = iVar18;
        psStack_12c = local_1ac;
        FUN_0057ef20();
        FUN_0057e850();
        if ((DAT_00fab29c & 1) == 0) {
          DAT_00fab29c = DAT_00fab29c | 1;
          local_14._0_1_ = 0xe;
          FUN_004ffe60();
          _atexit((_func_4879 *)&LAB_00bccf00);
          local_14._0_1_ = 0xd;
        }
        puVar9 = (undefined4 *)(*(undefined4 **)(DAT_00fb114c + 4))[1];
        cVar1 = *(char *)((int)puVar9 + 0xb5);
        puStack_1a0 = *(undefined4 **)(DAT_00fb114c + 4);
        while (cVar1 == '\0') {
          if ((int)puVar9[3] < iVar18) {
            puVar11 = (undefined4 *)puVar9[2];
            puVar9 = puStack_1a0;
          }
          else {
            puVar11 = (undefined4 *)*puVar9;
          }
          puStack_1a0 = puVar9;
          puVar9 = puVar11;
          cVar1 = *(char *)((int)puVar11 + 0xb5);
        }
        puVar9 = *(undefined4 **)(DAT_00fb114c + 4);
        if ((puStack_1a0 == puVar9) || (iVar18 < (int)puStack_1a0[3])) {
          puStack_168 = puVar9;
          ppuVar10 = &puStack_168;
        }
        else {
          ppuVar10 = &puStack_1a0;
        }
        if (*ppuVar10 == puVar9) {
          psStack_1bc = (short *)0x0;
LAB_0065a324:
          uStack_cc = 7;
          uStack_d0 = 0;
          auStack_e0[0] = auStack_e0[0] & 0xffff0000;
          local_14._0_1_ = 0xf;
          FUN_00555920();
          if (7 < uStack_cc) {
            FUN_0089120c();
          }
        }
        else {
          psStack_1bc = (short *)(*ppuVar10 + 4);
          if (psStack_1bc == (short *)0x0) goto LAB_0065a324;
          FUN_0049c120();
        }
        uStack_cc = 7;
        uStack_d0 = 0;
        auStack_e0[0] = auStack_e0[0] & 0xffff0000;
        local_14._0_1_ = 0x10;
        FUN_00555920();
        local_14._0_1_ = 0xd;
        if (7 < uStack_cc) {
          FUN_0089120c();
        }
        if ((&stack0xfffffe40 < puStack_194) && (local_198 <= &stack0xfffffe40)) {
          iVar18 = (int)&stack0xfffffe40 - (int)local_198;
          if (puStack_194 == puStack_190) {
            uVar12 = (int)puStack_194 - (int)local_198 >> 2;
            if (0x3ffffffe < uVar12) goto LAB_0065a97a;
            if ((uint)((int)puStack_190 - (int)local_198 >> 2) < uVar12 + 1) {
              FUN_00797980();
            }
          }
          if (puStack_194 != (undefined4 *)0x0) {
            *puStack_194 = local_198[iVar18 >> 2];
          }
        }
        else {
          if (puStack_194 == puStack_190) {
            uVar12 = (int)puStack_194 - (int)local_198 >> 2;
            if (0x3ffffffe < uVar12) goto LAB_0065a97a;
            if ((uint)((int)puStack_190 - (int)local_198 >> 2) < uVar12 + 1) {
              FUN_00797980();
            }
          }
          if (puStack_194 != (undefined4 *)0x0) {
            *puStack_194 = 0;
          }
        }
        puStack_194 = puStack_194 + 1;
        FUN_0065b550();
        uVar3 = *(undefined4 *)(psStack_1bc + 2);
        if ((&stack0xfffffe40 < puStack_184) && (puStack_188 <= &stack0xfffffe40)) {
          iVar18 = (int)&stack0xfffffe40 - (int)puStack_188;
          if (puStack_184 == puStack_180) {
            uVar12 = (int)puStack_184 - (int)puStack_188 >> 2;
            if (0x3ffffffe < uVar12) goto LAB_0065a97a;
            if ((uint)((int)puStack_180 - (int)puStack_188 >> 2) < uVar12 + 1) {
              FUN_00797980();
            }
          }
          if (puStack_184 != (undefined4 *)0x0) {
            *puStack_184 = puStack_188[iVar18 >> 2];
          }
        }
        else {
          if (puStack_184 == puStack_180) {
            uVar12 = (int)puStack_184 - (int)puStack_188 >> 2;
            if (0x3ffffffe < uVar12) goto LAB_0065a97a;
            if ((uint)((int)puStack_180 - (int)puStack_188 >> 2) < uVar12 + 1) {
              FUN_00797980();
            }
          }
          if (puStack_184 != (undefined4 *)0x0) {
            *puStack_184 = uVar3;
          }
        }
        puStack_184 = puStack_184 + 1;
        uVar3 = *(undefined4 *)(psStack_1bc + 4);
        if ((&stack0xfffffe40 < puStack_174) && (puStack_178 <= &stack0xfffffe40)) {
          iVar18 = (int)&stack0xfffffe40 - (int)puStack_178;
          if (puStack_174 == puStack_170) {
            uVar12 = (int)puStack_174 - (int)puStack_178 >> 2;
            if (0x3ffffffe < uVar12) {
LAB_0065a97a:
                    /* WARNING: Subroutine does not return */
              FUN_0087db30();
            }
            if ((uint)((int)puStack_170 - (int)puStack_178 >> 2) < uVar12 + 1) {
              FUN_00797980();
            }
          }
          if (puStack_174 != (undefined4 *)0x0) {
            *puStack_174 = puStack_178[iVar18 >> 2];
          }
          puStack_174 = puStack_174 + 1;
        }
        else {
          if (puStack_174 == puStack_170) {
            uVar12 = (int)puStack_174 - (int)puStack_178 >> 2;
            if (0x3ffffffe < uVar12) goto LAB_0065a97a;
            if ((uint)((int)puStack_170 - (int)puStack_178 >> 2) < uVar12 + 1) {
              FUN_00797980();
            }
          }
          if (puStack_174 != (undefined4 *)0x0) {
            *puStack_174 = uVar3;
          }
          puStack_174 = puStack_174 + 1;
        }
      }
      else {
        local_1ac = (short *)(*ppuVar10)[4];
      }
      puVar9 = puStack_1a8;
      FUN_006599f0();
      local_14._0_1_ = 0x11;
      puStack_1a0 = auStack_1f4;
      auStack_1f4[0]._0_2_ = 0;
      FUN_004026e0(apppppppsStack_100,0,0xffffffff);
      FUN_00659770(auStack_e0,*(undefined2 *)(puVar9 + 1),puVar9[4]);
      local_14._0_1_ = 0x12;
      FUN_004041f0();
      local_14._0_1_ = 0x11;
      if (7 < uStack_cc) {
        FUN_0089120c();
      }
      FUN_00404300();
      local_198[(int)local_1ac] = local_198[(int)local_1ac] + 1;
      uStack_19c = 0;
      if (((int)local_1ac < 0) && (local_1ac != (short *)0x0)) {
        iVar18 = (-(int)local_1ac - 1U >> 5) * -4 + -4;
      }
      else {
        iVar18 = ((uint)local_1ac >> 5) * 4;
      }
      bVar15 = (byte)local_1ac & 0x1f;
      if ((*(uint *)(uStack_c4 + iVar18) & 1 << bVar15) != 0) {
        uStack_19c = 0;
        if (((int)local_1ac < 0) && (local_1ac != (short *)0x0)) {
          iVar18 = (-(int)local_1ac - 1U >> 5) * -4 + -4;
        }
        else {
          iVar18 = ((uint)local_1ac >> 5) * 4;
        }
        puVar16 = (uint *)(uStack_c4 + iVar18);
        if (*(short *)((int)puStack_1a8 + 6) == *(short *)(puStack_1a8 + 2)) {
          *puVar16 = *puVar16 | 1 << bVar15;
        }
        else {
          *puVar16 = *puVar16 & ~(1 << bVar15);
        }
      }
      uStack_19c = 0;
      local_14._0_1_ = 0xd;
      if (7 < uStack_ec) {
        FUN_0089120c();
      }
      pppppppsStack_1b8 = (short *******)((int)pppppppsStack_1b8 + 1);
    } while (pppppppsStack_1b8 < pcStack_1b4);
  }
  FUN_00749a00();
  (**(code **)(*param_1 + 0x174))();
  FUN_00749c50();
  psVar17 = (short *)((iStack_160 - iStack_164) / 0x1c);
  pppppppsStack_1b8 = (short *******)0x0;
  local_1ac = psVar17;
  if (*(int *)(param_1[0x56] + 0xcc) != 0) {
    FUN_00408920();
  }
  psStack_1bc = (short *)0x0;
  if (psVar17 != (short *)0x0) {
    puStack_1a4 = (undefined4 *)(iStack_164 - (int)apuStack_a8[0]);
    pcStack_1b4 = (char *)((int)local_198 - (int)puStack_178);
    puStack_1a0 = (undefined4 *)((int)puStack_188 - (int)puStack_178);
    puVar9 = puStack_178;
    do {
      iVar18 = *(int *)(piStack_144[0x56] + 0xcc);
      if (((iVar18 == 0) || ((int)psStack_1bc < 0)) ||
         (*(int *)(iVar18 + 0xac) - *(int *)(iVar18 + 0xa8) >> 2 <= (int)psStack_1bc)) {
        iVar18 = 0;
      }
      else {
        iVar18 = *(int *)(*(int *)(iVar18 + 0xa8) + (int)psStack_1bc * 4);
      }
      puStack_1a8 = puVar9;
      if (iVar18 != 0) {
        apppppppsStack_100[0] = (short *******)((uint)apppppppsStack_100[0] & 0xffff0000);
        uStack_ec = 7;
        uStack_f0 = 0;
        FUN_004026e0();
        local_14._0_1_ = 0x13;
        FUN_00757800();
        (**(code **)(**(int **)(iVar18 + 0x248) + 200))();
        local_14._0_1_ = 0xd;
        if (7 < uStack_ec) {
          FUN_0089120c();
        }
        uStack_ec = 7;
        uStack_f0 = 0;
        apppppppsStack_100[0] = (short *******)((uint)apppppppsStack_100[0] & 0xffff0000);
        FUN_004026e0();
        local_14._0_1_ = 0x14;
        FUN_00757800();
        (**(code **)(**(int **)(iVar18 + 0x24c) + 200))();
        local_14._0_1_ = 0xd;
        if (7 < uStack_ec) {
          FUN_0089120c();
        }
        puStack_168 = (undefined4 *)(*(int *)(pcStack_1b4 + (int)puVar9) * 0xe + 10);
        FUN_00749a00();
        FUN_00749d00();
        if (((int)psStack_1bc < 0) && (psStack_1bc != (short *)0x0)) {
          iVar4 = -((-(int)psStack_1bc - 1U >> 5) * 4 + 4);
        }
        else {
          iVar4 = ((uint)psStack_1bc >> 5) * 4;
        }
        *(bool *)(iVar18 + 0x250) =
             (*(uint *)(uStack_c4 + iVar4) & 1 << ((byte)psStack_1bc & 0x1f)) != 0;
        uVar3 = *(undefined4 *)((int)puStack_1a0 + (int)puVar9);
        *(undefined4 *)(iVar18 + 600) = *puVar9;
        iVar4 = *(int *)(iVar18 + 0x248);
        *(undefined4 *)(iVar18 + 0x254) = uVar3;
        iVar5 = *(int *)(iVar18 + 0x24c);
        ppuStack_140 = *(undefined ***)(iVar5 + 8);
        local_13c = *(int **)(iVar5 + 0xc);
        uStack_138 = *(undefined4 *)(iVar5 + 0x10);
        auStack_e0[3] =
             ((*(int *)(iVar5 + 0x14) - (int)local_13c) - *(int *)(iVar4 + 0xc)) +
             *(int *)(iVar4 + 0x14) + (int)pppppppsStack_1b8;
        *(undefined4 *)(iVar18 + 0x25c) = 0;
        *(short ********)(iVar18 + 0x260) = pppppppsStack_1b8;
        *(int *)(iVar18 + 0x264) = *(int *)(iVar18 + 0x10) - *(int *)(iVar18 + 8);
        *(uint *)(iVar18 + 0x268) = auStack_e0[3];
        uStack_f8 = *(undefined4 *)(iVar4 + 0x10);
        apppppppsStack_100[0] = *(short ********)(iVar4 + 8);
        iStack_130 = *(int *)(iVar5 + 8);
        psStack_12c = *(short **)(iVar5 + 0xc);
        uStack_128 = *(undefined4 *)(iVar5 + 0x10);
        pppppppsStack_1b8 =
             (short *******)
             ((int)pppppppsStack_1b8 +
             ((*(int *)(iVar5 + 0x14) - (int)psStack_12c) - *(int *)(iVar4 + 0xc)) +
             *(int *)(iVar4 + 0x14));
        FUN_00657690();
        psVar17 = local_1ac;
      }
      psStack_1bc = (short *)((int)psStack_1bc + 1);
      puVar9 = puStack_1a8 + 1;
      param_1 = piStack_144;
      puStack_1a8 = puVar9;
    } while (psStack_1bc < psVar17);
  }
  puVar7 = apuStack_a8[1];
  *(short ********)(param_1[0x56] + 0xdc) = pppppppsStack_1b8;
  (**(code **)(*param_1 + 0x174))();
  FUN_00749d00();
  (**(code **)(*(int *)param_1[0x56] + 0x128))();
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_14._0_1_ = 0x15;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_14._0_1_ = 0xd;
  }
  if (((uint)param_1[10] >> 8 & 1) != 0) {
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_14._0_1_ = 0x16;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_14._0_1_ = 0xd;
    }
    piVar14 = DAT_00f95bdc;
    if (((DAT_00f95bdc == (int *)0x0) || (piVar13 = (int *)FUN_00443da0(), DAT_00f948b8 < *piVar13))
       || ((piVar13[2] < DAT_00f948b8 ||
           ((DAT_00f948bc < piVar13[1] || (piVar13[3] < DAT_00f948bc)))))) {
LAB_0065ad9d:
      pppppppsStack_1b8 = (short *******)param_1[0x57];
      if ((float)pppppppsStack_1b8 <= 0.0) goto LAB_0065ae3a;
      pcStack_1b4 = (char *)((float)pppppppsStack_1b8 - 0.06666667);
      if ((float)pcStack_1b4 <= 0.0) {
        pcStack_1b4 = (char *)0x0;
      }
    }
    else {
      if (((*(byte *)(piVar14 + 10) & 0x10) == 0) &&
         (piVar13 = piVar14 + 0x18, piVar14 = (int *)0x0, *piVar13 != 0)) {
        piVar14 = (int *)FUN_00745c20();
      }
      if (piVar14 != param_1) goto LAB_0065ad9d;
      pppppppsStack_1b8 = (short *******)param_1[0x57];
      if (1.0 <= (float)pppppppsStack_1b8) goto LAB_0065ae3a;
      pcStack_1b4 = (char *)((float)pppppppsStack_1b8 + 0.06666667);
      if (1.0 <= (float)pcStack_1b4) {
        pcStack_1b4 = (char *)0x3f800000;
      }
    }
    param_1[0x57] = (int)pcStack_1b4;
    (**(code **)(*param_1 + 0xd8))();
    (**(code **)(*(int *)param_1[0x45] + 0xd8))();
    (**(code **)(*(int *)param_1[0x56] + 0xd8))();
    (**(code **)(**(int **)(param_1[0x56] + 0xd0) + 0xd8))();
  }
LAB_0065ae3a:
  (**(code **)(*param_1 + 200))();
  if (puStack_178 != (undefined4 *)0x0) {
    FUN_0089120c();
  }
  if (puStack_188 != (undefined4 *)0x0) {
    FUN_0089120c();
  }
  if (uStack_c4 != 0) {
    FUN_0089120c();
  }
  if (local_198 != (undefined4 *)0x0) {
    FUN_0089120c();
  }
  puVar6 = apuStack_a8[0];
  if (apuStack_a8[0] != (undefined2 *)0x0) {
    for (; puVar6 != puVar7; puVar6 = puVar6 + 0xe) {
      if (7 < *(uint *)(puVar6 + 10)) {
        FUN_0089120c();
      }
      *(undefined4 *)(puVar6 + 10) = 7;
      *(undefined4 *)(puVar6 + 8) = 0;
      *puVar6 = 0;
    }
    FUN_0089120c();
  }
  if (iStack_164 != 0) {
    FUN_0049bf30();
    FUN_0089120c();
  }
  local_14 = (void *)CONCAT31(local_14._1_3_,0x17);
  FUN_005540c0();
  FUN_0089120c();
  if (iStack_120 != 0) {
    FUN_0089120c();
  }
  local_14 = (void *)CONCAT31(local_14._1_3_,1);
  _eh_vector_destructor_iterator_(auStack_98,0x1c,4,FUN_004fa440);
  if (iStack_110 != 0) {
    FUN_0089120c();
  }
LAB_00659c76:
  ExceptionList = local_1c;
  __security_check_cookie(uStack_24 ^ (uint)&stack0xfffffe3c);
  return;
}

