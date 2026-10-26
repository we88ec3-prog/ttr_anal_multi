
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00450b80(int param_1)

{
  undefined4 *puVar1;
  char cVar2;
  undefined1 uVar3;
  code *pcVar4;
  uint uVar5;
  char *pcVar6;
  char **ppcVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined2 uVar10;
  byte bVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  char *local_cc;
  int iStack_c8;
  char *local_c4 [2];
  undefined4 uStack_bc;
  char *pcStack_b8;
  uint uStack_b4;
  float local_b0;
  char *local_ac;
  int iStack_a8;
  uint uStack_a4;
  int iStack_a0;
  uint uStack_9c;
  char *local_98;
  char *pcStack_94;
  char *pcStack_90;
  char *pcStack_8c;
  char *pcStack_88;
  char *pcStack_84;
  char *pcStack_80;
  int iStack_7c;
  int local_78;
  undefined **appuStack_6c [3];
  undefined **appuStack_60 [3];
  undefined **appuStack_54 [3];
  undefined **appuStack_48 [4];
  undefined4 local_38 [5];
  uint local_24;
  void *pvStack_18;
  void *local_14;
  undefined1 uStack_10;
  undefined3 uStack_f;
  undefined4 local_c;
  
  uStack_10 = 0xe2;
  uStack_f = 0x93ba;
  local_14 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xffffff28;
  ExceptionList = &local_14;
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_c = 0;
    FUN_004e8010(uVar5);
    _atexit((_func_4879 *)&LAB_00bcd6b0);
  }
  bVar11 = DAT_00fc0c4c;
  uStack_bc = (char *)CONCAT13(DAT_00fc0c4c,(undefined3)uStack_bc);
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_c = 1;
    FUN_004e8010(uVar5);
    _atexit((_func_4879 *)&LAB_00bcd6b0);
  }
  local_ac = DAT_00fc0c50;
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_c = 2;
    FUN_004e8010(uVar5);
    _atexit((_func_4879 *)&LAB_00bcd6b0);
  }
  if ((DAT_00fb725c & 1) == 0) {
    DAT_00fb725c = DAT_00fb725c | 1;
    local_c = 3;
    FUN_004a79a0();
    _atexit((_func_4879 *)&DAT_00bccf80);
  }
  local_c = 0xffffffff;
  FUN_00450340();
  local_c._1_3_ = 0;
  if ((DAT_00fb725c & 1) == 0) {
    DAT_00fb725c = DAT_00fb725c | 1;
    local_c._0_1_ = 5;
    local_c._1_3_ = 0;
    FUN_004a79a0();
    _atexit((_func_4879 *)&DAT_00bccf80);
  }
  if ((DAT_00fbace4 & 1) == 0) {
    DAT_00fbace4 = DAT_00fbace4 | 1;
    local_c._0_1_ = 6;
    FUN_00825080();
    _atexit((_func_4879 *)&LAB_00bcd6d0);
    if ((DAT_00fbace4 & 1) == 0) {
      DAT_00fbace4 = DAT_00fbace4 | 1;
      local_c._0_1_ = 7;
      FUN_00825080();
      _atexit((_func_4879 *)&LAB_00bcd6d0);
    }
  }
  local_cc = (char *)(uint)bVar11;
  if (local_cc < (char *)(DAT_00fbacf4 - DAT_00fbacf0 >> 2)) {
    iVar12 = (int)*(short *)(DAT_00fbacf0 + (int)local_cc * 4);
  }
  else {
    iVar12 = 0;
  }
  if ((DAT_00fbace4 & 1) == 0) {
    DAT_00fbace4 = DAT_00fbace4 | 1;
    local_c._0_1_ = 8;
    FUN_00825080();
    _atexit((_func_4879 *)&LAB_00bcd6d0);
  }
  if ((uint)(byte)(uStack_bc._3_1_ + 1) < (uint)(DAT_00fbacf4 - DAT_00fbacf0 >> 2)) {
    iVar13 = (int)*(short *)(DAT_00fbacf0 + (uint)(byte)(uStack_bc._3_1_ + 1) * 4);
  }
  else {
    iVar13 = 0;
  }
  local_c4[0] = (char *)0x0;
  if (iVar13 != 0) {
    local_b0 = (float)(iVar13 - iVar12);
    local_c4[0] = (char *)((float)((int)local_ac - iVar12) / (float)(int)local_b0);
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c._0_1_ = 9;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
  }
  local_c._0_1_ = 4;
  local_b0 = 4.65231e-43;
  FUN_005740f0(&local_b0);
  if (local_98 != DAT_00fe5ac8) {
    pcVar6 = local_98 + 0x10;
    if (7 < *(uint *)(local_98 + 0x24)) {
      pcVar6 = *(char **)pcVar6;
    }
    FUN_0040e460(pcVar6);
    local_c._0_1_ = 10;
    if (*(int *)(*(int *)(param_1 + 0xec) + 0xcc) != 0) {
      FUN_00757800(local_38);
    }
    local_c = CONCAT31(local_c._1_3_,4);
    if (7 < local_24) {
      FUN_0089120c(local_38[0]);
    }
    pcVar4 = *(code **)(**(int **)(param_1 + 0xec) + 0x128);
    (*(int **)(param_1 + 0xec))[0x34] = (int)local_c4[0];
    (*pcVar4)();
    (**(code **)(**(int **)(param_1 + 0xec) + 200))();
    (**(code **)(**(int **)(param_1 + 0xf4) + 0x94))(DAT_00fbace8 <= uStack_bc._3_1_);
    (**(code **)(**(int **)(param_1 + 0xf4) + 200))();
    FUN_007597b0(0);
    (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
    uStack_b4 = DAT_00fb7284 - DAT_00fb7280 >> 2;
    uVar5 = local_78 - iStack_7c >> 2;
    iVar12 = *(int *)(*(int *)(param_1 + 0xf0) + 0xcc);
    uStack_9c = uVar5;
    if (iVar12 != 0) {
      FUN_00408920(iVar12,uVar5 + uStack_b4);
    }
    local_b0 = 0.0;
    uVar14 = 0;
    if (uVar5 != 0) {
      do {
        iVar12 = *(int *)(*(int *)(param_1 + 0xf0) + 0xcc);
        if (((iVar12 == 0) || ((int)uVar14 < 0)) ||
           (*(int *)(iVar12 + 0xac) - *(int *)(iVar12 + 0xa8) >> 2 <= (int)uVar14)) {
          iVar12 = 0;
        }
        else {
          iVar12 = *(int *)(*(int *)(iVar12 + 0xa8) + uVar14 * 4);
        }
        cVar2 = (*(char **)(DAT_00fc0c58 + 4))[0x19];
        bVar11 = **(byte **)(iStack_7c + uVar14 * 4);
        iStack_c8 = iVar12;
        pcVar6 = *(char **)(DAT_00fc0c58 + 4);
        uStack_bc = DAT_00fc0c58;
        while (pcVar8 = pcVar6, cVar2 == '\0') {
          if ((byte)pcVar8[0xc] < bVar11) {
            pcVar6 = *(char **)(pcVar8 + 8);
            pcVar8 = uStack_bc;
          }
          else {
            pcVar6 = *(char **)pcVar8;
          }
          cVar2 = pcVar6[0x19];
          uStack_bc = pcVar8;
        }
        if ((uStack_bc == DAT_00fc0c58) || (bVar11 < (byte)uStack_bc[0xc])) {
          pcStack_90 = DAT_00fc0c58;
          ppcVar7 = &pcStack_90;
        }
        else {
          ppcVar7 = (char **)&uStack_bc;
        }
        pcVar6 = *ppcVar7;
        if (pcVar6 == DAT_00fc0c58) {
          if ((DAT_00fbace4 & 1) == 0) {
            DAT_00fbace4 = DAT_00fbace4 | 1;
            uStack_10 = 0xe;
            FUN_00825080();
            _atexit((_func_4879 *)&LAB_00bcd6d0);
            uStack_10 = 4;
          }
          bVar11 = **(byte **)(iStack_7c + uVar14 * 4);
          cVar2 = (*(char **)(DAT_00fbad04 + 4))[0x25];
          pcVar6 = *(char **)(DAT_00fbad04 + 4);
          pcStack_b8 = DAT_00fbad04;
          while (pcVar8 = pcVar6, cVar2 == '\0') {
            if ((byte)pcVar8[0xc] < bVar11) {
              pcVar6 = *(char **)(pcVar8 + 8);
              pcVar8 = pcStack_b8;
            }
            else {
              pcVar6 = *(char **)pcVar8;
            }
            cVar2 = pcVar6[0x25];
            pcStack_b8 = pcVar8;
          }
          if ((pcStack_b8 == DAT_00fbad04) || (bVar11 < (byte)pcStack_b8[0xc])) {
            local_cc = DAT_00fbad04;
            ppcVar7 = &local_cc;
          }
          else {
            ppcVar7 = &pcStack_b8;
          }
          pcVar6 = *ppcVar7;
          if (((pcVar6 == DAT_00fbad04) || (pcVar6 == (char *)0xfffffff0)) ||
             ((uint)((*(int *)(pcVar6 + 0x18) - *(int *)(pcVar6 + 0x14)) / 0xc) < 2)) {
            uVar9 = 0;
          }
          else {
            uVar9 = *(undefined4 *)(*(int *)(pcVar6 + 0x14) + 0x10);
          }
          uVar3 = **(undefined1 **)(iStack_7c + uVar14 * 4);
          *(undefined4 *)(iVar12 + 0x264) = uVar9;
          *(undefined1 *)(iVar12 + 0x259) = 0;
          *(undefined1 *)(iVar12 + 600) = uVar3;
          *(undefined4 *)(iVar12 + 0x25c) = 0;
          *(undefined4 *)(iVar12 + 0x260) = 0;
          (**(code **)(**(int **)(iVar12 + 0x250) + 0x94))(0);
          (**(code **)(**(int **)(iVar12 + 0x250) + 200))();
        }
        else {
          local_ac = *(char **)(pcVar6 + 0x10);
          iStack_a8 = *(int *)(pcVar6 + 0x14);
          if ((DAT_00fbace4 & 1) == 0) {
            DAT_00fbace4 = DAT_00fbace4 | 1;
            uStack_10 = 0xb;
            FUN_00825080();
            _atexit((_func_4879 *)&LAB_00bcd6d0);
            uStack_10 = 4;
          }
          cVar2 = (*(char **)(DAT_00fbad04 + 4))[0x25];
          pcVar6 = *(char **)(DAT_00fbad04 + 4);
          uStack_bc = DAT_00fbad04;
          while (pcVar8 = pcVar6, cVar2 == '\0') {
            if ((byte)pcVar8[0xc] < (byte)local_ac) {
              pcVar6 = *(char **)(pcVar8 + 8);
              pcVar8 = uStack_bc;
            }
            else {
              pcVar6 = *(char **)pcVar8;
            }
            cVar2 = pcVar6[0x25];
            uStack_bc = pcVar8;
          }
          if ((uStack_bc == DAT_00fbad04) || ((byte)local_ac < (byte)uStack_bc[0xc])) {
            pcStack_94 = DAT_00fbad04;
            ppcVar7 = &pcStack_94;
          }
          else {
            ppcVar7 = (char **)&uStack_bc;
          }
          if (*ppcVar7 == DAT_00fbad04) {
            uStack_bc = (char *)0x0;
          }
          else {
            uStack_bc = *ppcVar7 + 0x10;
          }
          if ((DAT_00fbace4 & 1) == 0) {
            DAT_00fbace4 = DAT_00fbace4 | 1;
            uStack_10 = 0xc;
            FUN_00825080();
            _atexit((_func_4879 *)&LAB_00bcd6d0);
            uStack_10 = 4;
          }
          cVar2 = (*(char **)(DAT_00fbad04 + 4))[0x25];
          pcVar6 = *(char **)(DAT_00fbad04 + 4);
          local_c4[0] = DAT_00fbad04;
          while (pcVar8 = pcVar6, cVar2 == '\0') {
            if ((byte)pcVar8[0xc] < (byte)local_ac) {
              pcVar6 = *(char **)(pcVar8 + 8);
              pcVar8 = local_c4[0];
            }
            else {
              pcVar6 = *(char **)pcVar8;
            }
            cVar2 = pcVar6[0x25];
            local_c4[0] = pcVar8;
          }
          if ((local_c4[0] == DAT_00fbad04) || ((byte)local_ac < (byte)local_c4[0][0xc])) {
            pcStack_8c = DAT_00fbad04;
            ppcVar7 = &pcStack_8c;
          }
          else {
            ppcVar7 = local_c4;
          }
          pcVar6 = *ppcVar7;
          uVar10 = SUB42(local_ac,0);
          if (((pcVar6 == DAT_00fbad04) || (pcVar6 == (char *)0xfffffff0)) ||
             (uVar5 = (uint)local_ac >> 8 & 0xff,
             (uint)((*(int *)(pcVar6 + 0x18) - *(int *)(pcVar6 + 0x14)) / 0xc) <= uVar5)) {
            local_c4[0] = (char *)0x0;
          }
          else {
            local_c4[0] = *(char **)(*(int *)(pcVar6 + 0x14) + 4 + uVar5 * 0xc);
          }
          if ((DAT_00fbace4 & 1) == 0) {
            DAT_00fbace4 = DAT_00fbace4 | 1;
            uStack_10 = 0xd;
            FUN_00825080();
            _atexit((_func_4879 *)&LAB_00bcd6d0);
            uStack_10 = 4;
            uVar10 = SUB42(local_ac,0);
          }
          iVar12 = iStack_c8;
          cVar2 = (*(char **)(DAT_00fbad04 + 4))[0x25];
          pcVar6 = *(char **)(DAT_00fbad04 + 4);
          pcStack_b8 = DAT_00fbad04;
          while (pcVar8 = pcVar6, cVar2 == '\0') {
            if ((byte)pcVar8[0xc] < (byte)uVar10) {
              pcVar6 = *(char **)(pcVar8 + 8);
              pcVar8 = pcStack_b8;
            }
            else {
              pcVar6 = *(char **)pcVar8;
            }
            cVar2 = pcVar6[0x25];
            pcStack_b8 = pcVar8;
          }
          if ((pcStack_b8 == DAT_00fbad04) || ((byte)uVar10 < (byte)pcStack_b8[0xc])) {
            local_98 = DAT_00fbad04;
            ppcVar7 = &local_98;
          }
          else {
            ppcVar7 = &pcStack_b8;
          }
          pcVar6 = *ppcVar7;
          pcVar8 = local_c4[0];
          if ((pcVar6 != DAT_00fbad04) && (pcVar6 != (char *)0xfffffff0)) {
            uVar5 = (uint)(byte)((char)((ushort)uVar10 >> 8) + 1);
            uVar10 = SUB42(local_ac,0);
            if ((uVar5 < (uint)((*(int *)(pcVar6 + 0x18) - *(int *)(pcVar6 + 0x14)) / 0xc)) &&
               (pcVar6 = *(char **)(*(int *)(pcVar6 + 0x14) + 4 + uVar5 * 0xc),
               pcVar6 != (char *)0x0)) {
              pcStack_b8 = pcVar6 + -(int)local_c4[0];
              local_b0 = (float)(iStack_a8 - (int)local_c4[0]) / (float)(int)pcStack_b8;
              pcVar8 = pcVar6;
            }
          }
          *(char **)(iStack_c8 + 0x264) = pcVar8;
          *(int *)(iStack_c8 + 0x260) = iStack_a8;
          *(char *)(iStack_c8 + 600) = (char)uVar10;
          bVar11 = (byte)((ushort)uVar10 >> 8);
          *(byte *)(iStack_c8 + 0x259) = bVar11;
          *(float *)(iStack_c8 + 0x25c) = local_b0;
          pcStack_88 = (char *)CONCAT31(pcStack_88._1_3_,(byte)uStack_bc[1] <= bVar11);
          (**(code **)(**(int **)(iStack_c8 + 0x250) + 0x94))(pcStack_88);
          (**(code **)(**(int **)(iVar12 + 0x250) + 200))();
        }
        FUN_004504b0();
        uVar14 = uVar14 + 1;
      } while (uVar14 < uStack_9c);
    }
    uVar5 = 0;
    if (uStack_b4 != 0) {
      do {
        iVar12 = *(int *)(*(int *)(param_1 + 0xf0) + 0xcc);
        iVar13 = uVar5 + uStack_9c;
        if (((iVar12 == 0) || (iVar13 < 0)) ||
           (*(int *)(iVar12 + 0xac) - *(int *)(iVar12 + 0xa8) >> 2 <= iVar13)) {
          iVar12 = 0;
        }
        else {
          iVar12 = *(int *)(*(int *)(iVar12 + 0xa8) + iVar13 * 4);
        }
        puVar1 = (undefined4 *)(DAT_00fb7280 + uVar5 * 4);
        bVar11 = **(byte **)(DAT_00fb7280 + uVar5 * 4);
        cVar2 = (*(char **)(DAT_00fc0c58 + 4))[0x19];
        iStack_c8 = iVar12;
        pcVar6 = *(char **)(DAT_00fc0c58 + 4);
        local_cc = DAT_00fc0c58;
        while (pcVar8 = pcVar6, cVar2 == '\0') {
          if ((byte)pcVar8[0xc] < bVar11) {
            pcVar6 = *(char **)(pcVar8 + 8);
            pcVar8 = local_cc;
          }
          else {
            pcVar6 = *(char **)pcVar8;
          }
          cVar2 = pcVar6[0x19];
          local_cc = pcVar8;
        }
        if ((local_cc == DAT_00fc0c58) || (bVar11 < (byte)local_cc[0xc])) {
          pcStack_88 = DAT_00fc0c58;
          ppcVar7 = &pcStack_88;
        }
        else {
          ppcVar7 = &local_cc;
        }
        pcVar6 = *ppcVar7;
        if (pcVar6 == DAT_00fc0c58) {
          if ((DAT_00fbace4 & 1) == 0) {
            DAT_00fbace4 = DAT_00fbace4 | 1;
            DAT_00fbacf0 = 0;
            DAT_00fbacf4 = 0;
            _DAT_00fbacf8 = 0;
            uStack_10 = 0x16;
            _DAT_00fbad08 = 0;
            pcVar6 = (char *)FUN_00891268(0x28);
            if (pcVar6 == (char *)0x0) {
              local_ac = (char *)0x0;
              std::exception::exception((exception *)appuStack_60,&local_ac);
              appuStack_60[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
              __CxxThrowException_8(appuStack_60,&DAT_00c857a8);
            }
            DAT_00fbad04 = pcVar6;
            *(char **)pcVar6 = pcVar6;
            *(char **)(DAT_00fbad04 + 4) = DAT_00fbad04;
            *(char **)(DAT_00fbad04 + 8) = DAT_00fbad04;
            DAT_00fbad04[0x24] = '\x01';
            DAT_00fbad04[0x25] = '\x01';
            _atexit((_func_4879 *)&LAB_00bcd6d0);
            uStack_10 = 4;
          }
          bVar11 = *(byte *)*puVar1;
          cVar2 = (*(char **)(DAT_00fbad04 + 4))[0x25];
          pcVar6 = *(char **)(DAT_00fbad04 + 4);
          local_cc = DAT_00fbad04;
          while (pcVar8 = pcVar6, cVar2 == '\0') {
            if ((byte)pcVar8[0xc] < bVar11) {
              pcVar6 = *(char **)(pcVar8 + 8);
              pcVar8 = local_cc;
            }
            else {
              pcVar6 = *(char **)pcVar8;
            }
            cVar2 = pcVar6[0x25];
            local_cc = pcVar8;
          }
          if ((local_cc == DAT_00fbad04) || (bVar11 < (byte)local_cc[0xc])) {
            pcStack_94 = DAT_00fbad04;
            ppcVar7 = &pcStack_94;
          }
          else {
            ppcVar7 = &local_cc;
          }
          pcVar6 = *ppcVar7;
          if (((pcVar6 == DAT_00fbad04) || (pcVar6 == (char *)0xfffffff0)) ||
             ((uint)((*(int *)(pcVar6 + 0x18) - *(int *)(pcVar6 + 0x14)) / 0xc) < 2)) {
            uVar9 = 0;
          }
          else {
            uVar9 = *(undefined4 *)(*(int *)(pcVar6 + 0x14) + 0x10);
          }
          uVar3 = **(undefined1 **)(DAT_00fb7280 + uVar5 * 4);
          *(undefined4 *)(iVar12 + 0x264) = uVar9;
          *(undefined1 *)(iVar12 + 600) = uVar3;
          *(undefined1 *)(iVar12 + 0x259) = 0;
          *(undefined4 *)(iVar12 + 0x25c) = 0;
          *(undefined4 *)(iVar12 + 0x260) = 0;
          (**(code **)(**(int **)(iVar12 + 0x250) + 0x94))(0);
          (**(code **)(**(int **)(iVar12 + 0x250) + 200))();
        }
        else {
          uStack_a4 = *(uint *)(pcVar6 + 0x10);
          iStack_a0 = *(int *)(pcVar6 + 0x14);
          if ((DAT_00fbace4 & 1) == 0) {
            DAT_00fbace4 = DAT_00fbace4 | 1;
            DAT_00fbacf0 = 0;
            DAT_00fbacf4 = 0;
            _DAT_00fbacf8 = 0;
            uStack_10 = 0x10;
            _DAT_00fbad08 = 0;
            pcVar6 = (char *)FUN_00891268(0x28);
            if (pcVar6 == (char *)0x0) {
              pcStack_90 = (char *)0x0;
              std::exception::exception((exception *)appuStack_6c,&pcStack_90);
              appuStack_6c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
              __CxxThrowException_8(appuStack_6c,&DAT_00c857a8);
            }
            DAT_00fbad04 = pcVar6;
            *(char **)pcVar6 = pcVar6;
            *(char **)(DAT_00fbad04 + 4) = DAT_00fbad04;
            *(char **)(DAT_00fbad04 + 8) = DAT_00fbad04;
            DAT_00fbad04[0x24] = '\x01';
            DAT_00fbad04[0x25] = '\x01';
            _atexit((_func_4879 *)&LAB_00bcd6d0);
            uStack_10 = 4;
          }
          cVar2 = (*(char **)(DAT_00fbad04 + 4))[0x25];
          pcVar6 = *(char **)(DAT_00fbad04 + 4);
          local_cc = DAT_00fbad04;
          while (pcVar8 = pcVar6, cVar2 == '\0') {
            if ((byte)pcVar8[0xc] < (byte)uStack_a4) {
              pcVar6 = *(char **)(pcVar8 + 8);
              pcVar8 = local_cc;
            }
            else {
              pcVar6 = *(char **)pcVar8;
            }
            cVar2 = pcVar6[0x25];
            local_cc = pcVar8;
          }
          if ((local_cc == DAT_00fbad04) || ((byte)uStack_a4 < (byte)local_cc[0xc])) {
            local_98 = DAT_00fbad04;
            ppcVar7 = &local_98;
          }
          else {
            ppcVar7 = &local_cc;
          }
          if (*ppcVar7 == DAT_00fbad04) {
            uStack_bc = (char *)0x0;
          }
          else {
            uStack_bc = *ppcVar7 + 0x10;
          }
          if ((DAT_00fbace4 & 1) == 0) {
            DAT_00fbace4 = DAT_00fbace4 | 1;
            DAT_00fbacf0 = 0;
            DAT_00fbacf4 = 0;
            _DAT_00fbacf8 = 0;
            uStack_10 = 0x12;
            _DAT_00fbad08 = 0;
            pcVar6 = (char *)FUN_00891268(0x28);
            if (pcVar6 == (char *)0x0) {
              pcStack_80 = (char *)0x0;
              std::exception::exception((exception *)appuStack_54,&pcStack_80);
              appuStack_54[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
              __CxxThrowException_8(appuStack_54,&DAT_00c857a8);
            }
            DAT_00fbad04 = pcVar6;
            *(char **)pcVar6 = pcVar6;
            *(char **)(DAT_00fbad04 + 4) = DAT_00fbad04;
            *(char **)(DAT_00fbad04 + 8) = DAT_00fbad04;
            DAT_00fbad04[0x24] = '\x01';
            DAT_00fbad04[0x25] = '\x01';
            _atexit((_func_4879 *)&LAB_00bcd6d0);
            uStack_10 = 4;
          }
          cVar2 = (*(char **)(DAT_00fbad04 + 4))[0x25];
          pcVar6 = *(char **)(DAT_00fbad04 + 4);
          local_cc = DAT_00fbad04;
          while (pcVar8 = pcVar6, cVar2 == '\0') {
            if ((byte)pcVar8[0xc] < (byte)uStack_a4) {
              pcVar6 = *(char **)(pcVar8 + 8);
              pcVar8 = local_cc;
            }
            else {
              pcVar6 = *(char **)pcVar8;
            }
            cVar2 = pcVar6[0x25];
            local_cc = pcVar8;
          }
          if ((local_cc == DAT_00fbad04) || ((byte)uStack_a4 < (byte)local_cc[0xc])) {
            pcStack_b8 = DAT_00fbad04;
            ppcVar7 = &pcStack_b8;
          }
          else {
            ppcVar7 = &local_cc;
          }
          pcVar6 = *ppcVar7;
          if ((pcVar6 == DAT_00fbad04) || (pcVar6 == (char *)0xfffffff0)) {
            local_c4[0] = (char *)0x0;
          }
          else {
            uVar14 = uStack_a4 >> 8 & 0xff;
            if (uVar14 < (uint)((*(int *)(pcVar6 + 0x18) - *(int *)(pcVar6 + 0x14)) / 0xc)) {
              local_c4[0] = *(char **)(*(int *)(pcVar6 + 0x14) + 4 + uVar14 * 0xc);
            }
            else {
              local_c4[0] = (char *)0x0;
            }
          }
          uVar10 = (undefined2)uStack_a4;
          if ((DAT_00fbace4 & 1) == 0) {
            DAT_00fbace4 = DAT_00fbace4 | 1;
            DAT_00fbacf0 = 0;
            DAT_00fbacf4 = 0;
            _DAT_00fbacf8 = 0;
            uStack_10 = 0x14;
            _DAT_00fbad08 = 0;
            pcVar6 = (char *)FUN_00891268(0x28);
            if (pcVar6 == (char *)0x0) {
              pcStack_84 = (char *)0x0;
              std::exception::exception((exception *)appuStack_48,&pcStack_84);
              appuStack_48[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
              __CxxThrowException_8(appuStack_48,&DAT_00c857a8);
            }
            DAT_00fbad04 = pcVar6;
            *(char **)pcVar6 = pcVar6;
            *(char **)(DAT_00fbad04 + 4) = DAT_00fbad04;
            *(char **)(DAT_00fbad04 + 8) = DAT_00fbad04;
            DAT_00fbad04[0x24] = '\x01';
            DAT_00fbad04[0x25] = '\x01';
            _atexit((_func_4879 *)&LAB_00bcd6d0);
            uStack_10 = 4;
            uVar10 = (undefined2)uStack_a4;
          }
          iVar12 = iStack_c8;
          cVar2 = (*(char **)(DAT_00fbad04 + 4))[0x25];
          pcVar6 = *(char **)(DAT_00fbad04 + 4);
          local_cc = DAT_00fbad04;
          while (pcVar8 = pcVar6, cVar2 == '\0') {
            if ((byte)pcVar8[0xc] < (byte)uVar10) {
              pcVar6 = *(char **)(pcVar8 + 8);
              pcVar8 = local_cc;
            }
            else {
              pcVar6 = *(char **)pcVar8;
            }
            cVar2 = pcVar6[0x25];
            local_cc = pcVar8;
          }
          if ((local_cc == DAT_00fbad04) || ((byte)uVar10 < (byte)local_cc[0xc])) {
            pcStack_8c = DAT_00fbad04;
            ppcVar7 = &pcStack_8c;
          }
          else {
            ppcVar7 = &local_cc;
          }
          pcVar6 = *ppcVar7;
          pcVar8 = local_c4[0];
          if ((pcVar6 != DAT_00fbad04) && (pcVar6 != (char *)0xfffffff0)) {
            uVar14 = (uint)(byte)((char)((ushort)uVar10 >> 8) + 1);
            uVar10 = (undefined2)uStack_a4;
            if ((uVar14 < (uint)((*(int *)(pcVar6 + 0x18) - *(int *)(pcVar6 + 0x14)) / 0xc)) &&
               (pcVar6 = *(char **)(*(int *)(pcVar6 + 0x14) + 4 + uVar14 * 0xc),
               pcVar6 != (char *)0x0)) {
              local_cc = pcVar6 + -(int)local_c4[0];
              local_b0 = (float)(iStack_a0 - (int)local_c4[0]) / (float)(int)local_cc;
              pcVar8 = pcVar6;
            }
          }
          *(char *)(iStack_c8 + 600) = (char)uVar10;
          bVar11 = (byte)((ushort)uVar10 >> 8);
          *(byte *)(iStack_c8 + 0x259) = bVar11;
          *(int *)(iStack_c8 + 0x260) = iStack_a0;
          *(char **)(iStack_c8 + 0x264) = pcVar8;
          *(float *)(iStack_c8 + 0x25c) = local_b0;
          (**(code **)(**(int **)(iStack_c8 + 0x250) + 0x94))((byte)uStack_bc[1] <= bVar11);
          (**(code **)(**(int **)(iVar12 + 0x250) + 200))();
        }
        FUN_004506e0();
        uVar5 = uVar5 + 1;
      } while (uVar5 < uStack_b4);
    }
    FUN_00749920(*(undefined4 *)(param_1 + 0xf0));
    (**(code **)(**(int **)(param_1 + 0xf0) + 200))();
    if (iStack_7c != 0) {
      FUN_0089120c(iStack_7c);
    }
    ExceptionList = pvStack_18;
    return;
  }
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}

