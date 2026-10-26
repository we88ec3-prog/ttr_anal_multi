
void FUN_006a4f60(void)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *in_ECX;
  int in_EDX;
  int local_2c;
  int iStack_28;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00932940;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (in_ECX != (int *)0x0) {
    iVar3 = (**(code **)(*in_ECX + 4))();
    if (iVar3 == 0x105ba) goto LAB_006a4fbc;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_006a4fbc:
  FUN_008438c0();
  if (local_2c == *(int *)(in_EDX + 0x110)) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      uStack_c = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      uStack_c = 0xffffffff;
    }
    puVar4 = (undefined4 *)FUN_00891268();
    if (puVar4 != (undefined4 *)0x0) {
      iVar3 = in_ECX[6];
      iVar1 = in_ECX[5];
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf43e7;
      *puVar4 = FoxUI::FXUIEventI2::vftable;
      puVar4[5] = iVar1;
      puVar4[6] = iVar3;
    }
    FUN_00402160();
    uStack_c._1_3_ = 0;
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      uStack_c._0_1_ = 2;
      uStack_c._1_3_ = 0;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        uStack_c._0_1_ = 3;
        FUN_004f3d80();
        _atexit((_func_4879 *)&LAB_00bcd1e0);
      }
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      uStack_c._0_1_ = 4;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
    }
    uStack_c._0_1_ = 1;
    FUN_005740f0();
    if (iStack_28 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_004f7370();
    uVar5 = FUN_004f6a30(in_ECX[5]);
    FUN_00498ef0(uVar5);
    uStack_c = 0xffffffff;
    FUN_0058b270(0xcf);
    FUN_0057ef20();
    FUN_0057e850();
  }
  ExceptionList = local_14;
  return;
}

