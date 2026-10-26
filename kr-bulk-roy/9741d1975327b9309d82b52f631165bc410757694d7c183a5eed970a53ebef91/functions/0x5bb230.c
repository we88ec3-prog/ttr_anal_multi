
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005bb230(void)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  int *in_ECX;
  int in_EDX;
  short *psVar6;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009472a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX != (int *)0x0) {
    iVar4 = (**(code **)(*in_ECX + 4))();
    if (iVar4 == 0x105ba) goto LAB_005bb283;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_005bb283:
  if (((uint)(*(int **)(in_EDX + 0x224))[10] >> 8 & 1) != 0) {
    (**(code **)(**(int **)(in_EDX + 0x224) + 0xd4))();
  }
  iVar4 = *(int *)(in_EDX + 0x2b4);
  iVar3 = in_ECX[6];
  *(char *)(iVar4 + 0x17b) = (char)in_ECX[5];
  *(char *)(iVar4 + 0x17c) = (char)iVar3;
  iVar4 = in_ECX[6];
  if (iVar4 == 0) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = iVar4;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 1;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    FUN_005740f0();
    if (local_18 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar5 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar5 = *(short **)psVar5;
    }
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160();
    local_8 = 2;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 3;
      local_8._1_3_ = 0;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_8 = CONCAT31(local_8._1_3_,2);
    }
    FUN_005740f0();
    if (DAT_00fe5b10 == 0x19a) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar5 = (short *)&DAT_000001aa;
    psVar6 = (short *)&DAT_000001aa;
    if (7 < _DAT_000001be) {
      psVar5 = _DAT_000001aa;
      psVar6 = _DAT_000001aa;
    }
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
  }
  else {
    if (in_ECX[5] != iVar4) {
      if ((*(uint *)(*(int *)(in_EDX + 0x2b4) + 0x28) >> 8 & 1) == 0) {
        FUN_00596e00();
      }
      ExceptionList = local_10;
      return;
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 4;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    iVar4 = FUN_005854b0();
    FUN_005740f0();
    if (local_14 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar5 = (short *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar5 = *(short **)psVar5;
    }
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160();
    local_8 = 5;
    iVar4 = FUN_005854b0();
    FUN_005740f0();
    if (local_14 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar5 = (short *)(local_14 + 0x10);
    psVar6 = psVar5;
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar5 = *(short **)psVar5;
      psVar6 = psVar5;
    }
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
  }
  FUN_00402160(psVar6,(int)psVar5 - (int)(psVar6 + 1) >> 1);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
  ExceptionList = local_10;
  return;
}

