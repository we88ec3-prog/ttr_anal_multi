
void FUN_005030c0(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  short *psVar5;
  short *psVar6;
  int in_ECX;
  int *piVar7;
  int local_54;
  undefined4 *local_50;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00944073;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480(local_14);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  local_50 = (undefined4 *)FUN_00891268(0x18);
  if (local_50 == (undefined4 *)0x0) {
    local_50 = (undefined4 *)0x0;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 4);
    local_50[1] = 0xffffffff;
    local_50[2] = 0xffffffff;
    local_50[3] = 0;
    local_50[4] = 0xf4280;
    *local_50 = FoxUI::FXUIEventI1::vftable;
    local_50[5] = uVar2;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 1;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  FUN_00804260(&local_50);
  if (*(int *)(param_1 + 4) == 0) {
    FUN_005000d0();
    iVar4 = FUN_0040f060();
    FUN_00500240(in_ECX,*(undefined4 *)(iVar4 + 0x8c));
    local_50 = (undefined4 *)(int)*(short *)(param_1 + 2);
    iVar4 = *(int *)(in_ECX + 0x5eac);
    FUN_00503d20(&local_50);
    if ((local_54 != *(int *)(iVar4 + 4)) && (local_54 != -0x10)) {
      iVar4 = FUN_00891268(0xc4);
      local_8 = 2;
      if (iVar4 != 0) {
        piVar7 = (int *)(local_54 + 0x5c);
        if (7 < *(uint *)(local_54 + 0x70)) {
          piVar7 = (int *)*piVar7;
        }
        local_54 = iVar4;
        FUN_005016f0(piVar7,1);
        iVar4 = local_54;
      }
      local_54 = iVar4;
      if ((DAT_00fb7354 & 1) == 0) {
        DAT_00fb7354 = DAT_00fb7354 | 1;
        local_8 = 3;
        FUN_005533d0();
        _atexit((_func_4879 *)&LAB_00bcd100);
      }
      local_8 = 0xffffffff;
      FUN_005536e0(&DAT_00fb7358,0);
      local_54 = 0x14;
      iVar4 = FUN_005855b0();
      FUN_005740f0(&local_54);
      if (local_50 == *(undefined4 **)(iVar4 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      psVar5 = (short *)FUN_004ed610();
      local_8 = 4;
      if (7 < *(uint *)(psVar5 + 10)) {
        psVar5 = *(short **)psVar5;
      }
      local_1c = 7;
      local_20 = 0;
      local_30 = (uint)local_30._2_2_ << 0x10;
      psVar6 = psVar5;
      do {
        sVar1 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar5,(int)psVar6 - (int)(psVar5 + 1) >> 1);
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_8._0_1_ = 6;
        FUN_004d4d10();
        _atexit((_func_4879 *)&LAB_00bccef0);
      }
      local_8 = CONCAT31(local_8._1_3_,5);
      FUN_004d6b30(&local_30);
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      local_1c = 7;
      local_20 = 0;
      local_30 = local_30 & 0xffff0000;
      if (7 < local_38) {
        FUN_0089120c(local_4c);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

