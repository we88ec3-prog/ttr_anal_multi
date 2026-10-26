
void FUN_00687930(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  undefined4 *puVar5;
  short *psVar6;
  int *unaff_EDI;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  int iStack_8c;
  undefined1 *puStack_88;
  short *psStack_84;
  undefined1 auStack_60 [8];
  uint uStack_58;
  uint uStack_54;
  void *pvStack_50;
  uint uStack_34;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0092c7ac;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_60;
  ExceptionList = &local_14;
  puVar5 = (undefined4 *)FUN_00891268();
  if (puVar5 != (undefined4 *)0x0) {
    iVar2 = unaff_EDI[0x3e];
    iVar3 = unaff_EDI[0x3d];
    puVar5[1] = 0xffffffff;
    puVar5[2] = 0xffffffff;
    puVar5[3] = 0;
    puVar5[4] = 0xf4369;
    *puVar5 = FoxUI::FXUIEventI2::vftable;
    puVar5[5] = iVar3;
    puVar5[6] = iVar2;
  }
  FUN_004072a0();
  (**(code **)(*(int *)unaff_EDI[0x4b] + 0x19c))();
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_1c = 0;
    psStack_84 = (short *)0x6879fc;
    FUN_00584c40();
    psStack_84 = (short *)0x687a06;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_1c = 0xffffffff;
  }
  psStack_84 = (short *)0x687a28;
  FUN_005740f0();
  if (DAT_00fe5ac8 != 0) {
    FUN_004068f0();
    local_1c = 1;
    psStack_84 = (short *)0x687a6c;
    FUN_00757800();
    local_1c = 0xffffffff;
    if (7 < uStack_34) {
      psStack_84 = (short *)0x687a81;
      FUN_0089120c();
    }
    FUN_00757710();
    (**(code **)(*(int *)unaff_EDI[0x5a] + 200))();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_1c = 2;
      psStack_84 = (short *)0x687acc;
      FUN_00584c40();
      psStack_84 = (short *)0x687ad6;
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_1c = 0xffffffff;
    }
    psStack_84 = (short *)0x687af8;
    FUN_005740f0();
    if (DAT_00fe5ac8 != 0x1a) {
      psStack_84 = (short *)0x2a;
      if (7 < uRam0000003e) {
        psStack_84 = psRam0000002a;
      }
      uStack_54 = 7;
      uStack_58 = 0;
      psVar6 = psStack_84;
      do {
        sVar1 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar1 != 0);
      puStack_88 = (undefined1 *)0x687b4d;
      FUN_00402160();
      iVar2 = unaff_EDI[0x5b];
      local_1c = 3;
      FUN_007578f0();
      psStack_84 = (short *)0x7b;
      puStack_88 = &stack0xffffff98;
      uStack_90 = 0x687b75;
      iStack_8c = iVar2 + 0xe8;
      FUN_00759ed0();
      local_1c = 0xffffffff;
      if (7 < uStack_54) {
        psStack_84 = (short *)0x687b8a;
        FUN_0089120c();
      }
      uStack_54 = 7;
      uStack_58 = 0;
      (**(code **)(*(int *)unaff_EDI[0x5b] + 200))();
      psStack_84 = (short *)0x687bc2;
      FUN_0075cd30();
      psStack_84 = (short *)0x687bd0;
      FUN_0075cd30();
      psStack_84 = (short *)0x687be2;
      (**(code **)(*(int *)unaff_EDI[0x53] + 0x90))();
      psStack_84 = (short *)0x0;
      puStack_88 = (undefined1 *)0x687bf4;
      (**(code **)(*(int *)unaff_EDI[0x54] + 0x90))();
      puStack_88 = (undefined1 *)0x0;
      iStack_8c = 0x687c06;
      (**(code **)(*(int *)unaff_EDI[0x55] + 0x90))();
      iStack_8c = 0x687c16;
      (**(code **)(*(int *)unaff_EDI[0x53] + 200))();
      iStack_8c = 0x687c26;
      (**(code **)(*(int *)unaff_EDI[0x54] + 200))();
      iStack_8c = 0x687c36;
      (**(code **)(*(int *)unaff_EDI[0x55] + 200))();
      iStack_8c = 0;
      uStack_90 = 0x687c48;
      (**(code **)(*(int *)unaff_EDI[0x56] + 0x90))();
      uStack_90 = 0;
      uStack_94 = 0x687c5a;
      (**(code **)(*(int *)unaff_EDI[0x57] + 0x90))();
      uStack_94 = 0;
      uStack_98 = 0x687c6c;
      (**(code **)(*(int *)unaff_EDI[0x58] + 0x90))();
      uStack_98 = 0x687c7c;
      (**(code **)(*(int *)unaff_EDI[0x56] + 200))();
      uStack_98 = 0x687c8c;
      (**(code **)(*(int *)unaff_EDI[0x57] + 200))();
      uStack_98 = 0x687c9c;
      (**(code **)(*(int *)unaff_EDI[0x58] + 200))();
      uStack_98 = 0;
      uStack_9c = 0x687cae;
      (**(code **)(*(int *)unaff_EDI[0x51] + 0x94))();
      uStack_9c = 0;
      (**(code **)(*(int *)unaff_EDI[0x50] + 0x94))();
      unaff_EDI[0x3d] = -1;
      unaff_EDI[0x3e] = -1;
      (**(code **)(*(int *)unaff_EDI[0x4e] + 0x90))(0);
      (**(code **)(*(int *)unaff_EDI[0x4f] + 0x90))(1);
      if (*(int *)(unaff_EDI[0x59] + 0xcc) != 0) {
        FUN_006438f0(*(int *)(unaff_EDI[0x59] + 0xcc));
      }
      FUN_00749920(unaff_EDI[0x59]);
      (**(code **)(*(int *)unaff_EDI[0x59] + 200))();
      FUN_00757710();
      (**(code **)(*(int *)unaff_EDI[0x52] + 0x94))(0);
      (**(code **)(*unaff_EDI + 200))();
      *(undefined2 *)((int)unaff_EDI + 0x171) = 0;
      unaff_EDI[0x5f] = -1;
      unaff_EDI[0x5e] = -1;
      ExceptionList = pvStack_50;
      __security_check_cookie(uStack_58 ^ (uint)&uStack_9c);
      return;
    }
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}

