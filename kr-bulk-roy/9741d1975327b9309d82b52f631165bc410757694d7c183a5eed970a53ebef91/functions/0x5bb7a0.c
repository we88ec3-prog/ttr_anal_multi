
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005bb7a0(int param_1)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  int *in_ECX;
  int iStack_24;
  int iStack_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00947236;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (in_ECX != (int *)0x0) {
    iVar3 = (**(code **)(*in_ECX + 4))();
    if (iVar3 == 0x105d0) goto LAB_005bb7f9;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_005bb7f9:
  if (((uint)(*(int **)(param_1 + 0x224))[10] >> 8 & 1) != 0) {
    (**(code **)(**(int **)(param_1 + 0x224) + 0xd4))();
  }
  FUN_004361e0();
  if (in_ECX[5] == 0) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      uStack_c = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      uStack_c = 0xffffffff;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      uStack_c = 1;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      uStack_c = 0xffffffff;
    }
    FUN_005740f0();
    if (iStack_20 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar5 = (short *)(iStack_20 + 0x10);
    if (7 < *(uint *)(iStack_20 + 0x24)) {
      psVar5 = *(short **)psVar5;
    }
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160();
    uStack_c = 2;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      uStack_c._0_1_ = 3;
      uStack_c._1_3_ = 0;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      uStack_c = CONCAT31(uStack_c._1_3_,2);
    }
    FUN_005740f0();
    if (DAT_00fe5b10 == 0x19b) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar5 = (short *)&DAT_000001ab;
    if (7 < _DAT_000001bf) {
      psVar5 = _DAT_000001ab;
    }
    psVar4 = psVar5;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar5,(int)psVar4 - (int)(psVar5 + 1) >> 1);
  }
  else {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      uStack_c = 4;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      uStack_c = 0xffffffff;
    }
    iVar3 = FUN_004d43d0();
    if (0x27 < iVar3) {
      if ((*(uint *)(*(int *)(param_1 + 700) + 0x28) >> 8 & 1) == 0) {
        FUN_00596e00();
      }
      ExceptionList = local_14;
      return;
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      uStack_c = 5;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      uStack_c = 0xffffffff;
    }
    iVar3 = FUN_005854b0();
    FUN_005740f0();
    if (iStack_24 == *(int *)(iVar3 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar5 = (short *)(iStack_24 + 0x10);
    if (7 < *(uint *)(iStack_24 + 0x24)) {
      psVar5 = *(short **)psVar5;
    }
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160();
    uStack_c = 6;
    iVar3 = FUN_005854b0();
    FUN_005740f0();
    if (iStack_24 == *(int *)(iVar3 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_004068f0();
  }
  uStack_c = 0xffffffff;
  FUN_0058b270(0xca);
  ExceptionList = local_14;
  return;
}

