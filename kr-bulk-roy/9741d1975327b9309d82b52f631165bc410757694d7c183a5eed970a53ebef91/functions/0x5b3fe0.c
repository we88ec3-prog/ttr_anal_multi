
void FUN_005b3fe0(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *in_ECX;
  int iStack_b4;
  int iStack_b0;
  undefined4 *puStack_ac;
  uint uStack_a8;
  undefined4 uStack_98;
  uint uStack_94;
  undefined1 auStack_8c [56];
  undefined1 auStack_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0092915a;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_b4;
  ExceptionList = &local_14;
  if (in_ECX != (int *)0x0) {
    iVar2 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xffffff40);
    if (iVar2 == 0x105b9) goto LAB_005b404e;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_005b404e:
  puStack_ac = (undefined4 *)FUN_00891268(0x18);
  if (puStack_ac == (undefined4 *)0x0) {
    puStack_ac = (undefined4 *)0x0;
  }
  else {
    iVar2 = in_ECX[5];
    puStack_ac[1] = 0xffffffff;
    puStack_ac[2] = 0xffffffff;
    puStack_ac[3] = 0;
    puStack_ac[4] = 0xf43fc;
    *puStack_ac = FoxUI::FXUIEventI1::vftable;
    puStack_ac[5] = iVar2;
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    uStack_c = 0;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
    uStack_c = 0xffffffff;
  }
  iStack_b0 = 0x196;
  FUN_005740f0(&iStack_b0);
  if (iStack_b4 != DAT_00fe5b10) {
    puVar3 = (undefined4 *)(iStack_b4 + 0x10);
    if (7 < *(uint *)(iStack_b4 + 0x24)) {
      puVar3 = (undefined4 *)*puVar3;
    }
    FUN_007572f0(puVar3);
    uStack_c._1_3_ = 0;
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      uStack_c._0_1_ = 2;
      uStack_c._1_3_ = 0;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      uStack_c._0_1_ = 3;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
    }
    uStack_c._0_1_ = 1;
    iStack_b4 = 0x54;
    FUN_005740f0(&iStack_b4);
    if (iStack_b0 != DAT_00fe5b10) {
      FUN_004f6a30(in_ECX[5]);
      uVar4 = FUN_004ed610();
      uStack_c._0_1_ = 4;
      FUN_007574a0(uVar4);
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        uStack_c._0_1_ = 6;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
      }
      uStack_c._0_1_ = 5;
      FUN_007531a0(&DAT_00f94810,auStack_8c,auStack_54,puStack_ac,param_1);
      uStack_c = CONCAT31(uStack_c._1_3_,4);
      FUN_00757640(auStack_8c);
      if (7 < uStack_94) {
        FUN_0089120c(uStack_a8);
      }
      uStack_94 = 7;
      uStack_98 = 0;
      uStack_a8 = uStack_a8 & 0xffff0000;
      uStack_c = 0xffffffff;
      FUN_00757640(auStack_54);
      ExceptionList = local_14;
      __security_check_cookie(local_1c ^ (uint)&iStack_b4);
      return;
    }
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

