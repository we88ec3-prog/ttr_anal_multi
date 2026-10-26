
void FUN_005b9b10(void)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  short *psVar5;
  int *in_ECX;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933610;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX != (int *)0x0) {
    iVar3 = (**(code **)(*in_ECX + 4))();
    local_14 = in_ECX;
    if (iVar3 == 0x105ba) goto LAB_005b9b68;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  local_14 = (int *)0x0;
LAB_005b9b68:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  puVar4 = (undefined4 *)FUN_00891268();
  if (puVar4 != (undefined4 *)0x0) {
    iVar3 = local_14[6];
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[3] = 0;
    puVar4[4] = 0xf43e1;
    *puVar4 = FoxUI::FXUIEventI1::vftable;
    puVar4[5] = iVar3;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 1;
    FUN_00584c40();
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  FUN_005740f0();
  if (local_18 != DAT_00fe5ac8) {
    psVar5 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar5 = *(short **)psVar5;
    }
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160();
    local_8._1_3_ = 0;
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_8._0_1_ = 3;
      local_8._1_3_ = 0;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 4;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
    }
    local_8._0_1_ = 2;
    FUN_005740f0();
    if (local_18 != DAT_00fe5b10) {
      FUN_004f6a30();
      FUN_004ed610();
      local_8 = 0xffffffff;
      FUN_0058b270(0xcf);
      ExceptionList = local_10;
      return;
    }
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

