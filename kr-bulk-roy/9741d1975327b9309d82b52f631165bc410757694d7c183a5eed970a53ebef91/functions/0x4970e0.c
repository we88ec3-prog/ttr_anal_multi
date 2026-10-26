
/* WARNING: Type propagation algorithm not settling */

void FUN_004970e0(int param_1,uint param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 *******pppppppuVar3;
  undefined4 *puVar4;
  uint uVar5;
  int *piVar6;
  undefined4 local_88;
  uint local_84;
  int local_80;
  undefined4 *local_7c;
  undefined4 *local_78;
  int *local_74;
  undefined4 *local_70;
  uint local_6c;
  undefined4 local_68;
  uint local_54;
  undefined4 *******local_4c [4];
  undefined4 local_3c;
  uint local_38;
  undefined4 *******local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00934085;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_80 = param_1;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (undefined4 *******)((uint)local_30[0] & 0xffff0000);
  uStack_7 = 0;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 1;
    uStack_7 = 0;
    FUN_004f3d80(local_14);
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_8 = 0;
  local_74 = *(int **)(param_1 + 7);
  FUN_008438c0(&local_74);
  if (local_6c == DAT_00fb7574) {
    local_20 = 0;
    pppppppuVar3 = local_30[0];
    if (local_1c < 8) {
      pppppppuVar3 = local_30;
    }
    *(undefined2 *)pppppppuVar3 = 0;
  }
  else {
    FUN_004026e0(*(undefined4 *)(local_6c + 0x10),0,0xffffffff);
  }
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 2;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_8 = 0;
  }
  local_74 = *(int **)(param_1 + 2);
  FUN_008438c0(&local_74);
  if ((local_6c != DAT_00f8d91c) &&
     (piVar6 = *(int **)(local_6c + 0x10), local_74 = piVar6, piVar6 != (int *)0x0)) {
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8 = 3;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
    }
    DAT_00fb1308 = DAT_00fb1308 + 1;
    if (7 < (uint)piVar6[5]) {
      piVar6 = (int *)*piVar6;
    }
    if ((DAT_00fe5b08 & 1) == 0) {
      DAT_00fe5b08 = DAT_00fe5b08 | 1;
      local_8 = 5;
      FUN_00584c40(&DAT_00fe5ae8);
      _atexit((_func_4879 *)&LAB_00bcf380);
    }
    local_8 = 4;
    local_6c = 0x36;
    FUN_005740f0(&local_6c);
    if (local_70 == DAT_00fe5aec) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar2 = FUN_00498f10(piVar6);
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8 = 7;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
    }
    local_8 = 6;
    FUN_004d6b30(uVar2);
    local_8 = 4;
    if (7 < local_38) {
      FUN_0089120c(local_4c[0]);
    }
    if (param_2 < 0xf) {
      uVar5 = 0;
    }
    else {
      uVar5 = (param_2 - 0xf) / 5;
    }
    if (uVar5 != 0) {
      local_70 = (undefined4 *)(local_80 + 0xf);
      local_7c = (undefined4 *)0x37;
      local_6c = uVar5;
      do {
        local_38 = 7;
        local_3c = 0;
        local_4c[0] = (undefined4 *******)((uint)local_4c[0] & 0xffff0000);
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          local_8 = 9;
          FUN_004f3d80();
          _atexit((_func_4879 *)&LAB_00bcd1e0);
        }
        local_8 = 8;
        local_88 = *local_70;
        FUN_008438c0(&local_88);
        if (local_84 == DAT_00fb7574) {
          local_3c = 0;
          pppppppuVar3 = local_4c[0];
          if (local_38 < 8) {
            pppppppuVar3 = local_4c;
          }
          *(undefined2 *)pppppppuVar3 = 0;
        }
        else {
          FUN_004026e0(*(undefined4 *)(local_84 + 0x10),0,0xffffffff);
        }
        pppppppuVar3 = local_4c[0];
        if (local_38 < 8) {
          pppppppuVar3 = local_4c;
        }
        if ((DAT_00fe5b08 & 1) == 0) {
          DAT_00fe5b08 = DAT_00fe5b08 | 1;
          local_8 = 10;
          FUN_00584c40(&DAT_00fe5ae8);
          _atexit((_func_4879 *)&LAB_00bcf380);
          local_8 = 8;
        }
        FUN_005740f0(&local_7c);
        if (local_78 == DAT_00fe5aec) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        uVar2 = FUN_00498f10(pppppppuVar3);
        if ((DAT_00fb11e0 & 1) == 0) {
          DAT_00fb11e0 = DAT_00fb11e0 | 1;
          local_8 = 0xc;
          FUN_004d4d10();
          _atexit((_func_4879 *)&LAB_00bccef0);
        }
        _local_8 = CONCAT31(uStack_7,0xb);
        puVar4 = (undefined4 *)FUN_00891268(0x24);
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          puVar4[7] = 7;
          puVar4[6] = 0;
          *(undefined2 *)(puVar4 + 2) = 0;
        }
        *puVar4 = 0;
        *(undefined1 *)(puVar4 + 1) = 1;
        FUN_004026e0(uVar2,0,0xffffffff);
        FUN_004d7b00(&DAT_00fb11e8);
        if (DAT_00fb1308 == 0) {
          FUN_004d4fa0();
          puVar4 = (undefined4 *)FUN_00891268(0x14);
          if (puVar4 != (undefined4 *)0x0) {
            *puVar4 = FoxUI::FXUIEvent::vftable;
            puVar4[1] = 0xffffffff;
            puVar4[2] = 0xffffffff;
            puVar4[3] = 0;
            puVar4[4] = 0xf4366;
          }
          FUN_004072a0();
        }
        if (7 < local_54) {
          FUN_0089120c(local_68);
        }
        local_8 = 4;
        if (7 < local_38) {
          FUN_0089120c(local_4c[0]);
        }
        local_70 = (undefined4 *)((int)local_70 + 5);
        local_6c = local_6c - 1;
      } while (local_6c != 0);
    }
    pppppppuVar3 = local_30[0];
    if (local_1c < 8) {
      pppppppuVar3 = local_30;
    }
    piVar6 = local_74;
    if (7 < (uint)local_74[5]) {
      piVar6 = (int *)*local_74;
    }
    if ((DAT_00fe5b08 & 1) == 0) {
      DAT_00fe5b08 = DAT_00fe5b08 | 1;
      local_8 = 0xd;
      FUN_00584c40(&DAT_00fe5ae8);
      _atexit((_func_4879 *)&LAB_00bcf380);
      local_8 = 4;
    }
    local_78 = (undefined4 *)0x38;
    FUN_005740f0(&local_78);
    if (local_7c == DAT_00fe5aec) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar2 = FUN_00498f30(piVar6,pppppppuVar3);
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8 = 0xf;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
    }
    _local_8 = CONCAT31(uStack_7,0xe);
    puVar4 = (undefined4 *)FUN_00891268(0x24);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[7] = 7;
      puVar4[6] = 0;
      *(undefined2 *)(puVar4 + 2) = 0;
    }
    *puVar4 = 0;
    *(undefined1 *)(puVar4 + 1) = 1;
    FUN_004026e0(uVar2,0,0xffffffff);
    FUN_004d7b00(&DAT_00fb11e8);
    if (DAT_00fb1308 == 0) {
      FUN_004d4fa0();
      puVar4 = (undefined4 *)FUN_00891268(0x14);
      if (puVar4 == (undefined4 *)0x0) {
        FUN_004072a0();
      }
      else {
        *puVar4 = FoxUI::FXUIEvent::vftable;
        puVar4[1] = 0xffffffff;
        puVar4[2] = 0xffffffff;
        puVar4[3] = 0;
        puVar4[4] = 0xf4366;
        FUN_004072a0();
      }
    }
    local_8 = 4;
    if (7 < local_54) {
      FUN_0089120c(local_68);
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0x10;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 4;
    }
    puVar4 = (undefined4 *)FUN_00891268(0x18);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf42af;
      *puVar4 = FoxUI::FXUIEventP1::vftable;
      puVar4[5] = local_74;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 0x11;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 4;
    }
    local_78 = puVar4;
    FUN_00804260(&local_78);
    local_8 = 0;
    FUN_0048a440();
  }
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

