
undefined4 FUN_004eb9e0(int param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092fb7a;
  local_10 = ExceptionList;
  if (*(char *)(param_1 + 2) == '\0') {
    ExceptionList = &local_10;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
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
    if (local_14 == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
    piVar3 = (int *)(local_14 + 0x10);
    piVar5 = piVar3;
    if (7 < *(uint *)(local_14 + 0x24)) {
      piVar3 = (int *)*piVar3;
      piVar5 = piVar3;
    }
    do {
      iVar4 = *piVar3;
      piVar3 = (int *)((int)piVar3 + 2);
    } while ((short)iVar4 != 0);
  }
  else {
    if (*(char *)(param_1 + 2) != '\x01') {
      return 0;
    }
    ExceptionList = &local_10;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 3;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    FUN_00402160();
    local_8 = 4;
    iVar4 = FUN_005854b0();
    FUN_005740f0();
    if (local_14 == *(int *)(iVar4 + 4)) {
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
    piVar3 = (int *)(local_14 + 0x10);
    piVar5 = piVar3;
    if (7 < *(uint *)(local_14 + 0x24)) {
      piVar3 = (int *)*piVar3;
      piVar5 = piVar3;
    }
    do {
      iVar4 = *piVar3;
      piVar3 = (int *)((int)piVar3 + 2);
    } while ((short)iVar4 != 0);
  }
  FUN_00402160(piVar5,(int)piVar3 - ((int)piVar5 + 2) >> 1);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
  ExceptionList = local_10;
  return 0;
}

