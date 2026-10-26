
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b9850(int param_1)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  short *psVar5;
  undefined4 uVar6;
  int *in_ECX;
  undefined *puVar7;
  int *local_30;
  int local_2c;
  int iStack_28;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00933670;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (in_ECX != (int *)0x0) {
    iVar3 = (**(code **)(*in_ECX + 4))();
    local_30 = in_ECX;
    if (iVar3 == 0x105bf) goto LAB_005b98b1;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  local_30 = (int *)0x0;
LAB_005b98b1:
  FUN_008438c0();
  if (local_2c == *(int *)(param_1 + 0x2ec)) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      uStack_c = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      uStack_c = 0xffffffff;
    }
    puVar4 = (undefined4 *)FUN_00891268();
    if (puVar4 != (undefined4 *)0x0) {
      iVar3 = local_30[5];
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf43e0;
      *puVar4 = FoxUI::FXUIEventI1::vftable;
      puVar4[5] = iVar3;
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      uStack_c = 1;
      FUN_00584c40();
      _atexit((_func_4879 *)&LAB_00bcf390);
      uStack_c = 0xffffffff;
    }
    FUN_005740f0();
    if (iStack_28 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar5 = (short *)(iStack_28 + 0x10);
    if (7 < *(uint *)(iStack_28 + 0x24)) {
      psVar5 = *(short **)psVar5;
    }
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160();
    uStack_c._1_3_ = 0;
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      uStack_c._0_1_ = 3;
      uStack_c._1_3_ = 0;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      uStack_c._0_1_ = 4;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
    }
    uStack_c._0_1_ = 2;
    FUN_005740f0();
    if (DAT_00fe5b10 == 0x1e) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    puVar7 = (&PTR_DAT_00d6a0d4)[local_30[7]];
    uVar6 = FUN_004f6a30(local_30[5]);
    FUN_005c22d0(uVar6,puVar7);
    uStack_c = 0xffffffff;
    FUN_0058b270(0xcf);
    FUN_0057ef20();
    FUN_0057e850();
  }
  ExceptionList = local_14;
  return;
}

