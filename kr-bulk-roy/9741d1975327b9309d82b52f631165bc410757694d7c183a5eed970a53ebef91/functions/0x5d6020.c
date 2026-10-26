
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d6020(void)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  short *psVar4;
  int *in_ECX;
  short *psVar5;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933524;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX[0x41] + 0x24c) != 0) {
    iVar3 = *(int *)(*(int *)(in_ECX[0x41] + 0x24c) + 0xcc);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0xdc);
    }
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0x20) != -1)) {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))();
      }
      (**(code **)(*in_ECX + 0x90))();
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_8 = 0;
        FUN_00587480();
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_8 = 0xffffffff;
      }
      FUN_00402160();
      local_8 = 1;
      if ((DAT_00fe5b2c & 1) == 0) {
        DAT_00fe5b2c = DAT_00fe5b2c | 1;
        local_8._0_1_ = 2;
        local_8._1_3_ = 0;
        FUN_00584c40();
        _atexit(FUN_00bcf370);
        local_8 = CONCAT31(local_8._1_3_,1);
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
      psVar4 = psVar5;
      do {
        sVar1 = *psVar4;
        psVar4 = psVar4 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar5,(int)psVar4 - (int)(psVar5 + 1) >> 1);
      local_8 = 0xffffffff;
      FUN_0058b270(0xca);
    }
  }
  ExceptionList = local_10;
  return;
}

