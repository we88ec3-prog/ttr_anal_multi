
void FUN_006b1a80(void)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  ushort *puVar5;
  code *pcVar6;
  int *piVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  short *psVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  undefined4 **ppuVar14;
  int in_ECX;
  undefined4 *puVar15;
  short *psVar16;
  undefined4 *puVar17;
  int iVar18;
  undefined1 auStack_f4 [4];
  uint local_f0;
  uint local_ec;
  int local_e8;
  undefined4 *local_e4;
  undefined4 *local_e0;
  undefined4 *local_dc;
  undefined4 *local_d8;
  uint local_70 [4];
  undefined4 local_60;
  uint local_5c;
  uint local_54 [4];
  undefined4 local_44;
  uint local_40;
  undefined4 local_38;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c17e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_f4;
  ExceptionList = &local_14;
  local_e8 = in_ECX;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffff00);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  uVar10 = *(uint *)(DAT_00fab130 + 0x5eac);
  if ((DAT_00fe17b8 & 1) == 0) {
    DAT_00fe17b8 = DAT_00fe17b8 | 1;
    local_c = 1;
    FUN_0050caf0();
    _atexit((_func_4879 *)&LAB_00bce7e0);
  }
  local_c = 0xffffffff;
  local_f0 = uVar10;
  FUN_005366c0(&local_f0);
  if ((local_e4 != DAT_00fe17e4) && (local_d8 = local_e4 + 4, local_d8 != (undefined4 *)0x0)) {
    puVar17 = local_e4 + 10;
    iVar18 = local_e4[0xb];
    iVar4 = *(int *)(*(int *)(in_ECX + 0xfc) + 0xcc);
    local_e4 = (undefined4 *)*puVar17;
    if (iVar4 != 0) {
      FUN_006438f0(iVar4);
    }
    local_dc = *(undefined4 **)(iVar18 + 0x30);
    puVar17 = (undefined4 *)0x0;
    if (local_dc != (undefined4 *)0x0) {
      local_ec = iVar18 + 0x20;
      do {
        puVar12 = puVar17;
        FUN_00542210(puVar17);
        piVar7 = (int *)FUN_0050b4b0(puVar12);
        if ((int *)*piVar7 == (int *)0x0) {
          iVar18 = 0;
        }
        else {
          iVar18 = *(int *)*piVar7;
        }
        uVar10 = piVar7[2];
        uVar8 = uVar10 >> 2;
        if (*(uint *)(iVar18 + 8) <= uVar8) {
          uVar8 = uVar8 - *(uint *)(iVar18 + 8);
        }
        iVar18 = *(int *)(*(int *)(iVar18 + 4) + uVar8 * 4);
        if ((DAT_00fb9390 & 1) == 0) {
          DAT_00fb9390 = DAT_00fb9390 | 1;
          local_c = 2;
          FUN_0044ad70();
          _atexit((_func_4879 *)&LAB_00bcd610);
          local_c = 0xffffffff;
        }
        puVar12 = (undefined4 *)DAT_00fb9398[1];
        cVar1 = *(char *)((int)puVar12 + 0x15);
        puVar15 = puVar12;
        while (cVar1 == '\0') {
          if ((int)puVar15[3] < 7) {
            puVar15 = (undefined4 *)puVar15[2];
          }
          else {
            puVar15 = (undefined4 *)*puVar15;
          }
          cVar1 = *(char *)((int)puVar15 + 0x15);
        }
        puVar15 = DAT_00fb9398;
        if (*(char *)((int)puVar12 + 0x15) == '\0') {
          do {
            if ((int)puVar12[3] < 6) {
              puVar9 = (undefined4 *)puVar12[2];
            }
            else {
              puVar9 = (undefined4 *)*puVar12;
              puVar15 = puVar12;
            }
            puVar12 = puVar9;
          } while (*(char *)((int)puVar9 + 0x15) == '\0');
          if ((puVar15 == DAT_00fb9398) ||
             (iVar4 = *(int *)(puVar15[4] + 8), local_f0 = **(uint **)(iVar18 + (uVar10 & 3) * 4),
             piVar7 = (int *)FUN_0044b540(&local_f0), *piVar7 == iVar4)) goto LAB_006b1cae;
        }
        else {
LAB_006b1cae:
          puVar12 = puVar17;
          FUN_00542210(puVar17);
          piVar7 = (int *)FUN_0050b4b0(puVar12);
          if ((int *)*piVar7 == (int *)0x0) {
            iVar18 = 0;
          }
          else {
            iVar18 = *(int *)*piVar7;
          }
          uVar10 = (uint)piVar7[2] >> 2;
          if (*(uint *)(iVar18 + 8) <= uVar10) {
            uVar10 = uVar10 - *(uint *)(iVar18 + 8);
          }
          iVar18 = *(int *)(*(int *)(*(int *)(iVar18 + 4) + uVar10 * 4) + (piVar7[2] & 3U) * 4);
          if (*(uint *)(iVar18 + 0x18) < 8) {
            psVar16 = (short *)(iVar18 + 4);
          }
          else {
            psVar16 = *(short **)(iVar18 + 4);
          }
          local_5c = 7;
          local_60 = 0;
          local_70[0] = local_70[0] & 0xffff0000;
          psVar11 = psVar16;
          do {
            sVar2 = *psVar11;
            psVar11 = psVar11 + 1;
          } while (sVar2 != 0);
          FUN_00402160(psVar16,(int)psVar11 - (int)(psVar16 + 1) >> 1);
          local_c._0_1_ = 5;
          local_c._1_3_ = 0;
          puVar12 = puVar17;
          FUN_00542210(puVar17);
          FUN_0050b4b0(puVar12);
          puVar12 = puVar17;
          FUN_00542210(puVar17);
          FUN_0050b4b0(puVar12);
          if ((DAT_00fe5ae4 & 1) == 0) {
            DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
            local_c._0_1_ = 6;
            FUN_00584c40(&DAT_00fe5ac4);
            _atexit((_func_4879 *)&LAB_00bcf390);
            local_c._0_1_ = 5;
          }
          local_f0 = 0x153;
          FUN_005740f0(&local_f0);
          if (local_e0 == DAT_00fe5ac8) {
            pcVar6 = (code *)swi(3);
            (*pcVar6)();
            return;
          }
          puVar12 = local_e0 + 4;
          if (7 < (uint)local_e0[9]) {
            puVar12 = (undefined4 *)*puVar12;
          }
          puVar12 = (undefined4 *)FUN_0040e460(puVar12);
          local_c._0_1_ = 7;
          if (7 < (uint)puVar12[5]) {
            puVar12 = (undefined4 *)*puVar12;
          }
          uVar13 = FUN_00633110(local_54,local_70,puVar12);
          local_c = CONCAT31(local_c._1_3_,8);
          FUN_00402800(uVar13);
          if (7 < local_40) {
            FUN_0089120c(local_54[0]);
          }
          local_c = CONCAT31(local_c._1_3_,5);
          local_40 = 7;
          local_44 = 0;
          local_54[0] = local_54[0] & 0xffff0000;
          if (7 < local_24) {
            FUN_0089120c(local_38);
          }
          iVar18 = *(int *)(*(int *)(local_e8 + 0xfc) + 0xcc);
          if (iVar18 != 0) {
            FUN_00412c70(*(undefined4 *)(iVar18 + 0xe4));
          }
          FUN_00757710();
          local_c = 0xffffffff;
          if (7 < local_5c) {
            FUN_0089120c(local_70[0]);
          }
        }
        puVar17 = (undefined4 *)((int)puVar17 + 1);
      } while (puVar17 < local_dc);
    }
    iVar18 = local_e8;
    FUN_00749920(*(undefined4 *)(local_e8 + 0xfc));
    if (*(int *)(*(int *)(iVar18 + 0xfc) + 0xcc) != 0) {
      FUN_0042c8e0(*local_e4);
    }
    (**(code **)(**(int **)(iVar18 + 0xfc) + 200))();
    puVar17 = (undefined4 *)(iVar18 + 0x124);
    iVar18 = 4;
    do {
      (**(code **)(*(int *)*puVar17 + 0x90))(0);
      puVar17 = puVar17 + 1;
      iVar18 = iVar18 + -1;
    } while (iVar18 != 0);
    local_f0 = 4;
    uVar10 = (int)(local_e4[0x12] - local_e4[0x11]) >> 2;
    local_ec = 0;
    if (uVar10 != 0) {
      local_ec = 0;
      puVar17 = DAT_00f942f0;
      do {
        puVar5 = *(ushort **)(local_e4[0x11] + local_ec * 4);
        uVar8 = *(uint *)(puVar5 + 2);
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c = 9;
          FUN_004e1590();
          _atexit((_func_4879 *)&LAB_00bccc80);
          local_c = 0xffffffff;
          puVar17 = DAT_00f942f0;
        }
        uVar3 = *puVar5;
        cVar1 = *(char *)((int)puVar17[1] + 0xf);
        puVar12 = (undefined4 *)puVar17[1];
        local_dc = puVar17;
        while (puVar15 = puVar12, cVar1 == '\0') {
          if (*(ushort *)(puVar15 + 3) < uVar3) {
            puVar12 = (undefined4 *)puVar15[2];
            puVar15 = local_dc;
          }
          else {
            puVar12 = (undefined4 *)*puVar15;
          }
          cVar1 = *(char *)((int)puVar12 + 0xf);
          local_dc = puVar15;
        }
        if ((local_dc == puVar17) || (uVar3 < *(ushort *)(local_dc + 3))) {
          local_e0 = puVar17;
          ppuVar14 = &local_e0;
        }
        else {
          ppuVar14 = &local_dc;
        }
        if ((*ppuVar14 != puVar17) &&
           ((**(code **)(**(int **)(local_e8 + 0x124 + uVar8 * 4) + 0x90))(1),
           puVar17 = DAT_00f942f0, uVar8 < local_f0)) {
          local_f0 = uVar8;
        }
        local_ec = local_ec + 1;
      } while (local_ec < uVar10);
    }
    if ((int)local_d8[1] < 4) {
      (**(code **)(**(int **)(local_e8 + 0x124 + local_d8[1] * 4) + 0xa0))(1);
    }
    iVar18 = 4;
    (**(code **)(**(int **)(local_e8 + 0x11c) + 0x90))(local_f0 != 4);
    puVar17 = (undefined4 *)(local_e8 + 0x124);
    do {
      (**(code **)(*(int *)*puVar17 + 200))();
      puVar17 = puVar17 + 1;
      iVar18 = iVar18 + -1;
    } while (iVar18 != 0);
    (**(code **)(**(int **)(local_e8 + 0x11c) + 200))();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_f4);
  return;
}

