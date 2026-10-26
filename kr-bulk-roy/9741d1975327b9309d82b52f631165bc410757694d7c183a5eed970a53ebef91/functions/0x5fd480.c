
void FUN_005fd480(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined2 auStack_104 [8];
  undefined4 uStack_f4;
  undefined2 *puStack_f0;
  undefined2 auStack_e8 [6];
  undefined4 uStack_dc;
  undefined *puStack_d8;
  undefined1 *puStack_d4;
  undefined1 *puStack_d0;
  undefined4 *puStack_cc;
  undefined2 *puStack_b4;
  undefined2 *puStack_b0;
  int iStack_ac;
  int iStack_a8;
  int iStack_a4;
  int iStack_a0;
  int iStack_9c;
  int iStack_98;
  int *local_94;
  int iStack_90;
  undefined1 auStack_8c [44];
  undefined2 *puStack_60;
  undefined1 auStack_54 [20];
  uint uStack_40;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093eadd;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&puStack_b4;
  ExceptionList = &local_14;
  local_94 = param_1;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    puStack_cc = (undefined4 *)0x5fd4f4;
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  iVar3 = DAT_00f94300;
  local_c = 0xffffffff;
  iVar2 = (**(code **)(*param_1 + 0x1ac))();
  if (iVar2 == 1) {
    piVar4 = (int *)(iVar3 + 0x16f8);
  }
  else {
    piVar4 = (int *)0x0;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    puStack_cc = (undefined4 *)0x5fd552;
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  iStack_90 = 0;
  if (DAT_00f94300 != -0x16f8) {
    iStack_90 = *(int *)(DAT_00f94300 + 0x2398);
  }
  iStack_a8 = 0;
  iStack_a4 = 0;
  iStack_ac = 0;
  iStack_9c = 0;
  if (piVar4 != (int *)0x0) {
    iStack_98 = 1;
    if (0 < iStack_90) {
      do {
        piVar6 = piVar4 + 8;
        if (iStack_98 - 1U < 100) {
          if ((((piVar4[0xb] != 0) && (piVar4[10] != 0)) && (piVar6 != (int *)0x0)) &&
             ((*piVar6 == 0x10 || (*piVar6 == 0x19)))) {
            if ((DAT_00f8d9a4 & 1) == 0) {
              DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
              local_c = 2;
              FUN_0051c120();
              puStack_cc = (undefined4 *)0x5fd60c;
              _atexit((_func_4879 *)&LAB_00bccc90);
              local_c = 0xffffffff;
            }
            iStack_a0 = piVar4[0xb];
            puStack_cc = (undefined4 *)0x5fd630;
            FUN_008438c0();
            if (puStack_b0 == DAT_00f8d91c) {
              iVar3 = 0;
            }
            else {
              iVar3 = *(int *)(puStack_b0 + 8);
            }
            if ((DAT_00f8d9a4 & 1) == 0) {
              DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
              local_c = 3;
              FUN_0051c120();
              puStack_cc = (undefined4 *)0x5fd67f;
              _atexit((_func_4879 *)&LAB_00bccc90);
              local_c = 0xffffffff;
            }
            iStack_a0 = *(undefined4 *)(iVar3 + 0x50);
            puStack_cc = (undefined4 *)0x5fd6a3;
            FUN_008438c0();
            if ((puStack_b4 == DAT_00f8d91c) || (*(int *)(puStack_b4 + 8) == 0)) {
              iVar3 = FUN_008fed10();
            }
            else {
              iVar3 = FUN_008fed10();
            }
            iStack_a8 = iVar3;
            if ((DAT_00f94390 & 1) == 0) {
              DAT_00f94390 = DAT_00f94390 | 1;
              local_c = 4;
              FUN_004e1590();
              puStack_cc = (undefined4 *)0x5fd712;
              _atexit((_func_4879 *)&LAB_00bccc80);
              local_c = 0xffffffff;
            }
            if (iVar3 <= DAT_00f94244) {
              iStack_ac = iStack_ac + 1;
              iStack_a4 = iVar3;
            }
            iStack_9c = iStack_9c + 1;
          }
        }
        else {
          puStack_cc = (undefined4 *)0x5fd64b;
          FUN_006edb60();
        }
        iStack_98 = iStack_98 + 1;
        piVar4 = piVar6;
      } while (iStack_98 <= iStack_90);
    }
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 5;
      FUN_004e1590();
      puStack_cc = (undefined4 *)0x5fd774;
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    if (DAT_00f94244 < iStack_a4) {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_c = 6;
        FUN_00587480();
        puStack_cc = (undefined4 *)0x5fd7bc;
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_c = 0xffffffff;
      }
      puStack_cc = (undefined4 *)0x0;
      local_94 = (int *)auStack_e8;
      puStack_d4 = (undefined1 *)0x7;
      puStack_d8 = (undefined *)0x0;
      puStack_f0 = &DAT_00bed1fc;
      auStack_e8[0] = 0;
      uStack_f4 = 0x5fd7f2;
      FUN_00402160();
      local_c = 7;
      if ((DAT_00fe5b2c & 1) == 0) {
        DAT_00fe5b2c = DAT_00fe5b2c | 1;
        local_c._0_1_ = 8;
        local_c._1_3_ = 0;
        puStack_f0 = (undefined2 *)0x5fd81b;
        FUN_00584c40();
        puStack_f0 = (undefined2 *)0x5fd825;
        _atexit(FUN_00bcf370);
        local_c = CONCAT31(local_c._1_3_,7);
      }
      puStack_b4 = (undefined2 *)0xc;
      puStack_f0 = (undefined2 *)0x5fd84a;
      FUN_005740f0();
      if (puStack_b0 == DAT_00fe5b10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      piVar4 = (int *)(puStack_b0 + 8);
      piVar6 = piVar4;
      if (7 < *(uint *)(puStack_b0 + 0x12)) {
        piVar4 = (int *)*piVar4;
        piVar6 = piVar4;
      }
      do {
        iVar3 = *piVar4;
        piVar4 = (int *)((int)piVar4 + 2);
      } while ((short)iVar3 != 0);
    }
    else {
      if (iStack_ac != 0) {
        if ((DAT_00fe5b2c & 1) == 0) {
          DAT_00fe5b2c = DAT_00fe5b2c | 1;
          local_c = 0xc;
          puStack_cc = (undefined4 *)0x5fd9f4;
          FUN_00584c40();
          puStack_cc = (undefined4 *)0x5fd9fe;
          _atexit(FUN_00bcf370);
          local_c = 0xffffffff;
        }
        puStack_b4 = (undefined2 *)0xeb;
        puStack_cc = (undefined4 *)0x5fda23;
        FUN_005740f0();
        if (puStack_b0 == DAT_00fe5b10) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        puStack_cc = (undefined4 *)0x5fda50;
        FUN_007572f0();
        local_c = 0xd;
        puStack_b4 = (undefined2 *)0x0;
        puStack_cc = (undefined4 *)0x5fda75;
        FUN_00848020();
        if (puStack_b0 != puStack_60) {
          *(undefined4 *)(puStack_b0 + 0xc) = 0xffffbb00;
          *(undefined1 *)(puStack_b0 + 0xe) = 1;
          puStack_d0 = *(undefined1 **)(puStack_b0 + 8);
          puStack_cc = (undefined4 *)(*(int *)(puStack_b0 + 10) - (int)puStack_d0);
          puStack_d4 = (undefined1 *)0x5fda9d;
          FUN_007591a0();
        }
        FUN_00412df0();
        local_c._0_1_ = 0xe;
        puStack_cc = (undefined4 *)0x5fdac6;
        FUN_00759ac0();
        local_c = CONCAT31(local_c._1_3_,0xd);
        if (7 < uStack_40) {
          puStack_cc = (undefined4 *)0x5fdae1;
          FUN_0089120c();
        }
        puStack_b4 = (undefined2 *)0x1;
        puStack_cc = (undefined4 *)0x5fdafe;
        FUN_00848020();
        if (puStack_b0 != puStack_60) {
          *(undefined4 *)(puStack_b0 + 0xc) = 0xffffbb00;
          *(undefined1 *)(puStack_b0 + 0xe) = 1;
          puStack_d0 = *(undefined1 **)(puStack_b0 + 8);
          puStack_cc = (undefined4 *)(*(int *)(puStack_b0 + 10) - (int)puStack_d0);
          puStack_d4 = (undefined1 *)0x5fdb23;
          FUN_007591a0();
        }
        FUN_00412df0();
        local_c._0_1_ = 0xf;
        puStack_cc = (undefined4 *)0x5fdb4c;
        FUN_00759ac0();
        local_c = CONCAT31(local_c._1_3_,0xd);
        if (7 < uStack_40) {
          puStack_cc = (undefined4 *)0x5fdb67;
          FUN_0089120c();
        }
        puStack_b4 = (undefined2 *)0x2;
        puStack_cc = (undefined4 *)0x5fdb84;
        FUN_00848020();
        if (puStack_b0 != puStack_60) {
          *(undefined4 *)(puStack_b0 + 0xc) = 0xffffbb00;
          *(undefined1 *)(puStack_b0 + 0xe) = 1;
          puStack_d0 = *(undefined1 **)(puStack_b0 + 8);
          puStack_cc = (undefined4 *)(*(int *)(puStack_b0 + 10) - (int)puStack_d0);
          puStack_d4 = (undefined1 *)0x5fdba9;
          FUN_007591a0();
        }
        FUN_00412df0();
        local_c._0_1_ = 0x10;
        puStack_cc = (undefined4 *)0x5fdbd2;
        FUN_00759ac0();
        local_c._0_1_ = 0xd;
        if (7 < uStack_40) {
          puStack_cc = (undefined4 *)0x5fdbed;
          FUN_0089120c();
        }
        puStack_cc = (undefined4 *)0x5fdbf7;
        puVar5 = (undefined4 *)FUN_00891268();
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          *puVar5 = FoxUI::FXUIEvent::vftable;
          puVar5[1] = 0xffffffff;
          puVar5[2] = 0xffffffff;
          puVar5[3] = 0;
          puVar5[4] = 0xf4386;
        }
        puStack_cc = (undefined4 *)0x5fdc2f;
        FUN_007572f0();
        if ((DAT_00faadd0 & 1) == 0) {
          DAT_00faadd0 = DAT_00faadd0 | 1;
          local_c._0_1_ = 0x12;
          FUN_0074d990();
          puStack_cc = (undefined4 *)0x5fdc5f;
          _atexit((_func_4879 *)&LAB_00bccc70);
        }
        local_c._0_1_ = 0x11;
        puStack_d0 = auStack_54;
        puStack_d4 = auStack_8c;
        puStack_d8 = &DAT_00f94810;
        uStack_dc = 0x5fdc88;
        puStack_cc = puVar5;
        FUN_007531a0();
        local_c = CONCAT31(local_c._1_3_,0xd);
        puStack_cc = (undefined4 *)0x5fdc9a;
        FUN_00757640();
        local_c = 0xffffffff;
        puStack_cc = (undefined4 *)0x5fdcaf;
        FUN_00757640();
        goto LAB_005fdcaf;
      }
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_c = 9;
        FUN_00587480();
        puStack_cc = (undefined4 *)0x5fd8ec;
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_c = 0xffffffff;
      }
      puStack_cc = (undefined4 *)0x0;
      local_94 = (int *)auStack_e8;
      puStack_d4 = (undefined1 *)0x7;
      puStack_d8 = (undefined *)0x0;
      puStack_f0 = &DAT_00bed1fc;
      auStack_e8[0] = 0;
      uStack_f4 = 0x5fd922;
      FUN_00402160();
      local_c = 10;
      if ((DAT_00fe5b2c & 1) == 0) {
        DAT_00fe5b2c = DAT_00fe5b2c | 1;
        local_c._0_1_ = 0xb;
        local_c._1_3_ = 0;
        puStack_f0 = (undefined2 *)0x5fd94f;
        FUN_00584c40();
        puStack_f0 = (undefined2 *)0x5fd959;
        _atexit(FUN_00bcf370);
        local_c = CONCAT31(local_c._1_3_,10);
      }
      puStack_b4 = (undefined2 *)0xec;
      puStack_f0 = (undefined2 *)0x5fd97f;
      FUN_005740f0();
      if (puStack_b0 == DAT_00fe5b10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      piVar4 = (int *)(puStack_b0 + 8);
      piVar6 = piVar4;
      if (7 < *(uint *)(puStack_b0 + 0x12)) {
        piVar4 = (int *)*piVar4;
        piVar6 = piVar4;
      }
      do {
        iVar3 = *piVar4;
        piVar4 = (int *)((int)piVar4 + 2);
      } while ((short)iVar3 != 0);
    }
    puStack_b4 = auStack_104;
    puStack_f0 = (undefined2 *)0x7;
    uStack_f4 = 0;
    auStack_104[0] = 0;
    FUN_00402160(piVar6,(int)piVar4 - ((int)piVar6 + 2) >> 1);
    local_c = 0xffffffff;
    FUN_0058b270(0xca);
  }
LAB_005fdcaf:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&puStack_b4);
  return;
}

