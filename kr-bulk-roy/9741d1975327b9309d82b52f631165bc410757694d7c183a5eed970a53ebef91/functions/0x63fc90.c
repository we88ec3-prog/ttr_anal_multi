
void FUN_0063fc90(void)

{
  short sVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  short *psVar6;
  int *in_ECX;
  int local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093331e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX == (int *)0x0) {
    local_18 = (int *)0x0;
  }
  else {
    iVar4 = (**(code **)(*in_ECX + 4))();
    local_18 = in_ECX;
    if (iVar4 != 0x105bb) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      local_18 = (int *)0x0;
    }
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  puVar5 = (undefined4 *)FUN_00891268();
  if (puVar5 != (undefined4 *)0x0) {
    iVar4 = local_18[5];
    iVar2 = local_18[6];
    puVar5[3] = 0;
    puVar5[1] = 0xffffffff;
    puVar5[2] = 0xffffffff;
    puVar5[4] = 0xf43c6;
    *puVar5 = FoxUI::FXUIEventI2::vftable;
    puVar5[5] = iVar4;
    puVar5[6] = (uint)(iVar2 == 0);
  }
  if (local_18[6] == 0) {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 1;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    FUN_005740f0();
    if (local_1c == DAT_00fe5b10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
  }
  else {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 2;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    local_1c = 0x113;
    FUN_005740f0();
    if (local_14 == DAT_00fe5b10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 3;
    FUN_00584c40();
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  FUN_005740f0();
  if (local_1c == DAT_00fe5ac8) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  psVar6 = (short *)(local_1c + 0x10);
  if (7 < *(uint *)(local_1c + 0x24)) {
    psVar6 = *(short **)psVar6;
  }
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  FUN_00402160();
  local_8 = 4;
  if ((uint)local_18[0xc] < 8) {
    local_18 = local_18 + 7;
  }
  else {
    local_18 = (int *)local_18[7];
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8._0_1_ = 5;
    local_8._1_3_ = 0;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
    local_8 = CONCAT31(local_8._1_3_,4);
  }
  FUN_005740f0();
  if (local_1c == DAT_00fe5b10) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  FUN_00498ef0(local_18);
  local_8 = 0xffffffff;
  FUN_0058b270(0xcf);
  ExceptionList = local_10;
  return;
}

