
void FUN_004da690(uint param_1)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  int in_ECX;
  int in_EDX;
  ushort *puVar8;
  undefined1 auStack_74 [4];
  undefined4 *local_70;
  ushort *local_6c;
  int local_68;
  uint local_64;
  uint local_60;
  int local_5c;
  undefined4 local_58 [2];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 local_38;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009304ea;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_74;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff80;
  ExceptionList = &local_14;
  local_5c = 0;
  if (param_1 < 2) {
    uVar3 = 0;
  }
  else {
    uVar3 = param_1 - 2 >> 1;
  }
  if (uVar3 != 0) {
    local_6c = (ushort *)(in_ECX + 2);
    local_58[0] = 0xe;
    local_68 = in_EDX;
    local_60 = uVar3;
    do {
      local_64 = (uint)*local_6c;
      FUN_004dae30(&local_64);
      if ((DAT_00fe5b08 & 1) == 0) {
        DAT_00fe5b08 = DAT_00fe5b08 | 1;
        local_c = 0;
        FUN_00584c40(&DAT_00fe5ae8);
        _atexit((_func_4879 *)&LAB_00bcf380);
        local_c = 0xffffffff;
      }
      FUN_005740f0(local_58);
      if (local_70 == DAT_00fe5aec) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      uVar4 = FUN_004ed610();
      local_c._1_3_ = 0;
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_c._0_1_ = 2;
        local_c._1_3_ = 0;
        FUN_004d4d10();
        _atexit((_func_4879 *)&LAB_00bccef0);
      }
      local_c._0_1_ = 1;
      puVar5 = (undefined4 *)FUN_00891268(0x24);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        puVar5[7] = 7;
        puVar5[6] = 0;
        *(undefined2 *)(puVar5 + 2) = 0;
      }
      *puVar5 = 0;
      *(undefined1 *)(puVar5 + 1) = 1;
      FUN_004026e0(uVar4,0,0xffffffff);
      FUN_004d7b00(&DAT_00fb11e8);
      if (DAT_00fb1308 == 0) {
        FUN_004d4fa0();
        piVar6 = (int *)FUN_00891268(0x14);
        if (piVar6 == (int *)0x0) {
          piVar6 = (int *)0x0;
        }
        else {
          *piVar6 = (int)FoxUI::FXUIEvent::vftable;
          piVar6[1] = -1;
          piVar6[2] = -1;
          piVar6[3] = 0;
          piVar6[4] = 0xf4366;
        }
        if ((DAT_00faadd0 & 1) == 0) {
          DAT_00faadd0 = DAT_00faadd0 | 1;
          local_c._0_1_ = 3;
          FUN_0074d990();
          _atexit((_func_4879 *)&LAB_00bccc70);
          local_c._0_1_ = 1;
        }
        if (DAT_00f95bd4 != (int *)0x0) {
          (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar6);
        }
        if (piVar6 != (int *)0x0) {
          (**(code **)(*piVar6 + 0x10))(1);
        }
      }
      local_c = 0xffffffff;
      if (7 < local_24) {
        FUN_0089120c(local_38);
      }
      puVar8 = local_6c;
      if (*local_6c == 0xc) {
        local_5c = 1;
        FUN_004dafd0(&uStack_48,local_6c);
        FUN_005540c0(uStack_48,uStack_44);
        if ((DAT_00faadd4 & 1) == 0) {
          DAT_00faadd4 = DAT_00faadd4 | 1;
          local_c = 4;
          FUN_00587480();
          _atexit((_func_4879 *)&LAB_00bcccc0);
          local_c = 0xffffffff;
        }
        FUN_0058aad0(0xf42d5);
        puVar8 = local_6c;
      }
      else {
        local_64 = local_68 + 0x10;
        FUN_004dafd0(&uStack_50,local_6c);
        FUN_005540c0(uStack_50,uStack_4c);
      }
      local_6c = puVar8 + 1;
      local_60 = local_60 - 1;
    } while (local_60 != 0);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 5;
    FUN_00587480(uVar2);
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  FUN_0058aad0(0xf4288);
  if (local_5c != 0) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 6;
      FUN_00587480(uVar2);
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    puVar5 = (undefined4 *)FUN_00891268(0x1c);
    local_70 = (undefined4 *)0x0;
    if (puVar5 != (undefined4 *)0x0) {
      puVar5[3] = 0;
      puVar5[1] = 0xffffffff;
      puVar5[2] = 0xffffffff;
      puVar5[4] = 0xf42a4;
      *puVar5 = FoxUI::FXUIEventI2::vftable;
      puVar5[5] = 1;
      puVar5[6] = 1;
      local_70 = puVar5;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 7;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    FUN_00804260(&local_70);
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 8;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    puVar7 = (undefined4 *)FUN_00891268(0x1c);
    puVar5 = (undefined4 *)0x0;
    if (puVar7 != (undefined4 *)0x0) {
      puVar7[3] = 0;
      puVar7[1] = 0xffffffff;
      puVar7[2] = 0xffffffff;
      puVar7[4] = 0xf42a4;
      *puVar7 = FoxUI::FXUIEventI2::vftable;
      puVar7[5] = 2;
      puVar7[6] = 1;
      puVar5 = puVar7;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 9;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    local_70 = puVar5;
    FUN_00804260(&local_70);
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 10;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    puVar7 = (undefined4 *)FUN_00891268(0x1c);
    puVar5 = (undefined4 *)0x0;
    if (puVar7 != (undefined4 *)0x0) {
      puVar7[3] = 0;
      puVar7[1] = 0xffffffff;
      puVar7[2] = 0xffffffff;
      puVar7[4] = 0xf42a4;
      *puVar7 = FoxUI::FXUIEventI2::vftable;
      puVar7[5] = 3;
      puVar7[6] = 1;
      puVar5 = puVar7;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 0xb;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    local_70 = puVar5;
    FUN_00804260(&local_70);
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 0xc;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    puVar7 = (undefined4 *)FUN_00891268(0x1c);
    puVar5 = (undefined4 *)0x0;
    if (puVar7 != (undefined4 *)0x0) {
      puVar7[3] = 0;
      puVar7[6] = 0;
      puVar7[1] = 0xffffffff;
      puVar7[2] = 0xffffffff;
      puVar7[4] = 0xf42a4;
      *puVar7 = FoxUI::FXUIEventI2::vftable;
      puVar7[5] = 4;
      puVar5 = puVar7;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 0xd;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    local_70 = puVar5;
    FUN_00804260(&local_70);
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 0xe;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    puVar7 = (undefined4 *)FUN_00891268(0x1c);
    puVar5 = (undefined4 *)0x0;
    if (puVar7 != (undefined4 *)0x0) {
      puVar7[3] = 0;
      puVar7[6] = 0;
      puVar7[1] = 0xffffffff;
      puVar7[2] = 0xffffffff;
      puVar7[4] = 0xf42a4;
      *puVar7 = FoxUI::FXUIEventI2::vftable;
      puVar7[5] = 5;
      puVar5 = puVar7;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 0xf;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    local_70 = puVar5;
    FUN_00804260(&local_70);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_74);
  return;
}

