
void FUN_006c3d50(int param_1)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  short *psVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  short *psVar10;
  undefined4 uVar11;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093b632;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_8 = 0;
    FUN_004e8010();
    _atexit((_func_4879 *)&LAB_00bcd6b0);
  }
  iVar9 = DAT_00fc0bc8 - DAT_00fc0bc4;
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_8 = 1;
    FUN_004e8010();
    _atexit((_func_4879 *)&LAB_00bcd6b0);
  }
  iVar3 = DAT_00fc0c40 - (int)DAT_00fc0c3c >> 0x1f;
  iVar7 = (DAT_00fc0c40 - (int)DAT_00fc0c3c) / 0xc + iVar3;
  uVar4 = 0;
  piVar8 = DAT_00fc0c3c;
  if (iVar7 != iVar3) {
    do {
      if (*piVar8 == DAT_00fc0be8) {
        if ((uint)(iVar9 >> 2) < (uint)DAT_00fc0c3c[uVar4 * 3 + 1]) {
          if ((DAT_00faadd4 & 1) == 0) {
            DAT_00faadd4 = DAT_00faadd4 | 1;
            local_8 = 5;
            FUN_00587480();
            _atexit((_func_4879 *)&LAB_00bcccc0);
          }
          local_8 = 0xffffffff;
          puVar6 = (undefined4 *)FUN_00891268();
          if (puVar6 != (undefined4 *)0x0) {
            uVar11 = *(undefined4 *)(param_1 + 0xb4);
            puVar6[1] = 0xffffffff;
            puVar6[2] = 0xffffffff;
            puVar6[3] = 0;
            puVar6[4] = 0xf43ea;
            *puVar6 = FoxUI::FXUIEventI1::vftable;
            puVar6[5] = uVar11;
          }
          FUN_00402160();
          local_8._1_3_ = 0;
          if ((DAT_00fb75b0 & 1) == 0) {
            DAT_00fb75b0 = DAT_00fb75b0 | 1;
            local_8._0_1_ = 7;
            local_8._1_3_ = 0;
            FUN_004f3d80();
            _atexit((_func_4879 *)&LAB_00bcd1e0);
          }
          if ((DAT_00fe5b2c & 1) == 0) {
            DAT_00fe5b2c = DAT_00fe5b2c | 1;
            local_8._0_1_ = 8;
            FUN_00584c40();
            _atexit(FUN_00bcf370);
          }
          local_8._0_1_ = 6;
          FUN_005740f0();
          if (local_14 == DAT_00fe5b10) {
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
          }
          FUN_004f6a30();
          FUN_004ed610();
          uVar11 = 0xcf;
          goto LAB_006c407f;
        }
        break;
      }
      uVar4 = uVar4 + 1;
      piVar8 = piVar8 + 3;
    } while (uVar4 < (uint)(iVar7 - iVar3));
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 2;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  FUN_00402160();
  local_8 = 3;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8._0_1_ = 4;
    local_8._1_3_ = 0;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
    local_8 = CONCAT31(local_8._1_3_,3);
  }
  FUN_005740f0();
  if (local_14 == DAT_00fe5b10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar10 = (short *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    psVar10 = *(short **)psVar10;
  }
  psVar5 = psVar10;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar10,(int)psVar5 - (int)(psVar10 + 1) >> 1);
  uVar11 = 0xca;
LAB_006c407f:
  local_8 = 0xffffffff;
  FUN_0058b270(uVar11);
  ExceptionList = local_10;
  return;
}

