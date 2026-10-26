
void FUN_00463510(int param_1,short param_2)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  short *psVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *unaff_EDI;
  int iStack_d0;
  undefined4 *puStack_cc;
  uint *puStack_c8;
  short *psStack_c4;
  undefined4 uStack_ac;
  int *local_a8;
  int local_a4;
  int local_a0;
  uint local_9c;
  int iStack_98;
  int iStack_94;
  int iStack_90;
  int iStack_8c;
  int iStack_88;
  uint uStack_84;
  int iStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_74;
  undefined4 uStack_64;
  uint uStack_60;
  uint auStack_58 [4];
  undefined4 uStack_48;
  uint uStack_44;
  uint uStack_40;
  void *pvStack_38;
  int iStack_30;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009415a2;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_ac;
  ExceptionList = &local_14;
  local_a4 = param_1;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    psStack_c4 = (short *)0x46358a;
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_9c = DAT_00f9430c;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_c = 1;
    FUN_005c3de0();
    psStack_c4 = (short *)0x4635c3;
    _atexit((_func_4879 *)&LAB_00bccc30);
  }
  local_c = 0xffffffff;
  iVar4 = FUN_005c7190();
  if (iVar4 != 0) {
    local_a8 = (int *)(int)param_2;
    psStack_c4 = (short *)0x4635fa;
    FUN_0082ef00();
  }
  iVar4 = local_a4;
  FUN_00745060();
  (**(code **)(**(int **)(iVar4 + 0x15c) + 200))();
  FUN_00462900();
  local_c = 2;
  psStack_c4 = (short *)0x463653;
  FUN_00757800();
  local_c = 0xffffffff;
  if (7 < uStack_44) {
    psStack_c4 = (short *)0x46366f;
    FUN_0089120c();
  }
  (**(code **)(**(int **)(local_a4 + 0x160) + 200))();
  local_a0 = 0;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 3;
    FUN_004dec90();
    psStack_c4 = (short *)0x4636b6;
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  iVar4 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  if (iVar4 != 0) {
    local_a0 = *(int *)(iVar4 + 0x3d4);
  }
  uStack_60 = 7;
  uStack_64 = 0;
  uStack_74 = (short *)((uint)uStack_74._2_2_ << 0x10);
  uStack_84 = 0;
  iStack_80 = 0;
  uStack_7c = 0;
  local_c._0_1_ = 5;
  local_c._1_3_ = 0;
  psStack_c4 = (short *)0x46371f;
  FUN_00462840();
  iVar4 = (int)(iStack_80 - uStack_84) / 0x14;
  if (iVar4 != 0) {
    local_9c = (int)param_2 - 1;
    piVar8 = (int *)(uStack_84 + 8);
    local_a8 = (int *)iVar4;
    do {
      if (local_9c < 3) {
        if ((*piVar8 == 0) && (piVar8[1] == 0)) {
          if ((DAT_00fe5ae4 & 1) == 0) {
            DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
            local_c._0_1_ = 6;
            psStack_c4 = (short *)0x46378f;
            FUN_00584c40();
            psStack_c4 = (short *)0x463799;
            _atexit((_func_4879 *)&LAB_00bcf390);
            local_c._0_1_ = 5;
          }
          uStack_ac = 0x1c3;
          psStack_c4 = (short *)0x4637bf;
          FUN_005740f0();
          if (iStack_88 == DAT_00fe5ac8) {
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          psVar7 = (short *)(iStack_88 + 0x10);
          psStack_c4 = psVar7;
          if (7 < *(uint *)(iStack_88 + 0x24)) {
            psVar7 = *(short **)psVar7;
            psStack_c4 = psVar7;
          }
          do {
            sVar2 = *psVar7;
            psVar7 = psVar7 + 1;
          } while (sVar2 != 0);
          puStack_c8 = (uint *)0x4637fd;
          FUN_00404300();
          if ((DAT_00fe5ae4 & 1) == 0) {
            DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
            local_c._0_1_ = 7;
            psStack_c4 = (short *)0x46381f;
            FUN_00584c40();
            psStack_c4 = (short *)0x463829;
            _atexit((_func_4879 *)&LAB_00bcf390);
            local_c._0_1_ = 5;
          }
          uStack_ac = 0x151;
          psStack_c4 = (short *)0x46384f;
          FUN_005740f0();
          if (iStack_98 == DAT_00fe5ac8) {
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          if (*(uint *)(iStack_98 + 0x24) < 8) {
            psVar7 = (short *)(iStack_98 + 0x10);
            psStack_c4 = psVar7;
          }
          else {
            psVar7 = *(short **)(iStack_98 + 0x10);
            psStack_c4 = psVar7;
          }
          do {
            sVar2 = *psVar7;
            psVar7 = psVar7 + 1;
          } while (sVar2 != 0);
          puStack_c8 = (uint *)0x463890;
          FUN_00404300();
        }
        else {
          if ((local_a0 < *piVar8) || (piVar8[1] < local_a0)) {
            if ((DAT_00fe5ae4 & 1) == 0) {
              DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
              local_c._0_1_ = 8;
              psStack_c4 = (short *)0x463919;
              FUN_00584c40();
              psStack_c4 = (short *)0x463923;
              _atexit((_func_4879 *)&LAB_00bcf390);
              local_c._0_1_ = 5;
            }
            uStack_ac = 0x1c2;
            psStack_c4 = (short *)0x463949;
            FUN_005740f0();
            if (iStack_90 == DAT_00fe5ac8) {
              pcVar3 = (code *)swi(3);
              (*pcVar3)();
              return;
            }
            if (*(uint *)(iStack_90 + 0x24) < 8) {
              psVar7 = (short *)(iStack_90 + 0x10);
              psStack_c4 = psVar7;
            }
            else {
              psVar7 = *(short **)(iStack_90 + 0x10);
              psStack_c4 = psVar7;
            }
            do {
              sVar2 = *psVar7;
              psVar7 = psVar7 + 1;
            } while (sVar2 != 0);
          }
          else {
            uStack_ac = 0x1c3;
            iVar4 = FUN_00585620();
            psStack_c4 = (short *)0x4638c1;
            FUN_005740f0();
            if (iStack_8c == *(int *)(iVar4 + 4)) {
              pcVar3 = (code *)swi(3);
              (*pcVar3)();
              return;
            }
            if (*(uint *)(iStack_8c + 0x24) < 8) {
              psVar7 = (short *)(iStack_8c + 0x10);
              psStack_c4 = psVar7;
            }
            else {
              psVar7 = *(short **)(iStack_8c + 0x10);
              psStack_c4 = psVar7;
            }
            do {
              sVar2 = *psVar7;
              psVar7 = psVar7 + 1;
            } while (sVar2 != 0);
          }
          puStack_c8 = (uint *)0x46398a;
          FUN_00404300();
          if ((DAT_00fe5ae4 & 1) == 0) {
            DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
            local_c._0_1_ = 9;
            psStack_c4 = (short *)0x4639ac;
            FUN_00584c40();
            psStack_c4 = (short *)0x4639b6;
            _atexit((_func_4879 *)&LAB_00bcf390);
            local_c._0_1_ = 5;
          }
          uStack_ac = 0x152;
          psStack_c4 = (short *)0x4639dc;
          FUN_005740f0();
          if (iStack_94 == DAT_00fe5ac8) {
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          psStack_c4 = (short *)0x463a0d;
          puStack_c8 = (uint *)FUN_0040e460();
          psStack_c4 = (short *)0x0;
          local_c._0_1_ = 10;
          puStack_cc = (undefined4 *)0x463a25;
          FUN_004041f0();
          local_c._0_1_ = 5;
          if (7 < uStack_24) {
            psStack_c4 = (short *)0x463a44;
            FUN_0089120c();
          }
          uStack_24 = 7;
          uStack_28 = 0;
          pvStack_38 = (void *)((uint)pvStack_38 & 0xffff0000);
        }
        FUN_008fed10();
        puStack_c8 = (uint *)FUN_00463d00();
        psStack_c4 = (short *)0x0;
        local_c._0_1_ = 0xb;
        puStack_cc = (undefined4 *)0x463aa9;
        FUN_004041f0();
        local_c._0_1_ = 5;
        if (7 < uStack_44) {
          psStack_c4 = (short *)0x463ac2;
          FUN_0089120c();
        }
      }
      piVar8 = piVar8 + 5;
      local_a8 = (int *)((int)local_a8 + -1);
    } while (local_a8 != (int *)0x0);
  }
  psStack_c4 = uStack_74;
  if (uStack_60 < 8) {
    psStack_c4 = (short *)&uStack_74;
  }
  uStack_44 = 7;
  uStack_48 = 0;
  auStack_58[0] = auStack_58[0] & 0xffff0000;
  psVar7 = psStack_c4;
  do {
    sVar2 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar2 != 0);
  puStack_c8 = (uint *)0x463b1a;
  FUN_00402160();
  iVar4 = *(int *)(local_a4 + 0x168);
  puVar9 = (undefined4 *)(iVar4 + 0xe8);
  local_c = CONCAT31(local_c._1_3_,0xc);
  *(undefined4 *)(iVar4 + 0xf8) = 0;
  puVar5 = puVar9;
  if (7 < *(uint *)(iVar4 + 0xfc)) {
    puVar5 = (undefined4 *)*puVar9;
  }
  *(undefined2 *)puVar5 = 0;
  piVar8 = *(int **)(iVar4 + 0x104);
  piVar6 = (int *)*piVar8;
  *piVar8 = (int)piVar8;
  *(int *)(*(int *)(iVar4 + 0x104) + 4) = *(int *)(iVar4 + 0x104);
  *(undefined4 *)(iVar4 + 0x108) = 0;
  if (piVar6 != *(int **)(iVar4 + 0x104)) {
    do {
      piVar6 = (int *)*piVar6;
      psStack_c4 = (short *)0x463b68;
      FUN_0089120c();
    } while (piVar6 != (int *)*(int *)(iVar4 + 0x104));
  }
  piVar8 = *(int **)(*(int *)(iVar4 + 0x114) + 4);
  cVar1 = *(char *)((int)piVar8 + 0x21);
  while (local_a8 = piVar8, cVar1 == '\0') {
    psStack_c4 = (short *)0x463b8e;
    FUN_008575b0();
    piVar8 = (int *)*piVar8;
    psStack_c4 = (short *)0x463b9a;
    FUN_0089120c();
    cVar1 = *(char *)((int)piVar8 + 0x21);
  }
  *(int *)(*(int *)(iVar4 + 0x114) + 4) = *(int *)(iVar4 + 0x114);
  *(undefined4 *)*(undefined4 *)(iVar4 + 0x114) = *(undefined4 *)(iVar4 + 0x114);
  psStack_c4 = (short *)0x7b;
  puStack_c8 = auStack_58;
  *(int *)(*(int *)(iVar4 + 0x114) + 8) = *(int *)(iVar4 + 0x114);
  *(undefined4 *)(iVar4 + 0x118) = 0;
  iStack_d0 = 0x463bce;
  puStack_cc = puVar9;
  FUN_00759ed0();
  local_c = CONCAT31(local_c._1_3_,5);
  if (7 < uStack_44) {
    psStack_c4 = (short *)0x463be7;
    FUN_0089120c();
  }
  iVar4 = local_a4;
  (**(code **)(**(int **)(local_a4 + 0x168) + 200))();
  piVar8 = *(int **)(iVar4 + 0x168);
  psStack_c4 = (short *)0x463c18;
  (**(code **)(*piVar8 + 0x178))();
  puStack_cc = (undefined4 *)piVar8[3];
  iStack_d0 = piVar8[2];
  psStack_c4 = (short *)(((piVar8[0x30] + piVar8[0x31] * 2 + piVar8[0x2e]) - (int)pvStack_38) +
                         iStack_30 + (int)puStack_cc);
  puStack_c8 = (uint *)piVar8[4];
  (**(code **)(*piVar8 + 0xbc))();
  uStack_40 = *(int *)(unaff_EDI[0x5a] + 0x14) + 0xf + unaff_EDI[3];
  (**(code **)(*unaff_EDI + 0xbc))(unaff_EDI[2],unaff_EDI[3],unaff_EDI[4],uStack_40);
  if (local_a8 != (int *)0x0) {
    FUN_0089120c(local_a8);
  }
  if (7 < uStack_84) {
    FUN_0089120c(iStack_98);
  }
  ExceptionList = pvStack_38;
  __security_check_cookie(uStack_40 ^ (uint)&iStack_d0);
  return;
}

