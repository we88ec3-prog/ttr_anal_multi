
undefined4 FUN_004ec7c0(undefined2 *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined2 local_68 [8];
  undefined4 local_58;
  undefined2 *local_54;
  undefined2 local_4c [8];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 *puStack_34;
  undefined4 uStack_30;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009404e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)((int)param_1 + 0x5ec0) == 0) {
    if ((DAT_00fb75c0 & 1) == 0) {
      DAT_00fb75c0 = DAT_00fb75c0 | 1;
      local_8 = 3;
      FUN_0081e5f0();
      uStack_30 = 0x4ec936;
      _atexit((_func_4879 *)&LAB_00bcd250);
    }
    local_8 = 0xffffffff;
    uStack_30 = 0x4ec950;
    iVar4 = FUN_0081ec70();
    if (iVar4 != 0) {
      iVar4 = FUN_00404ba0();
      if (99999 < *(int *)(iVar4 + 0x6864)) {
        FUN_00414680();
        uStack_30 = 0x4ecaa0;
        FUN_004a4350();
        ExceptionList = local_10;
        return 1;
      }
      FUN_004054c0();
      uStack_30 = 0;
      param_1 = local_4c;
      local_54 = (undefined2 *)0x4eca6a;
      FUN_00402250();
      local_8 = 6;
      local_54 = (undefined2 *)0x4eca78;
      FUN_005854b0();
      local_54 = (undefined2 *)0x4eca7f;
      uVar2 = FUN_00585330();
      FUN_00402250(uVar2);
      goto LAB_004ec8ed;
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 4;
      FUN_00587480();
      uStack_30 = 0x4ec97e;
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    uStack_30 = 0;
    param_1 = (undefined2 *)0x1ba;
    puStack_34 = (undefined4 *)0x4ec992;
    iVar4 = FUN_005854b0();
    puStack_34 = &param_1;
    local_38 = 0x4ec9a2;
    FUN_005740f0();
    if (local_14 == *(int *)(iVar4 + 4)) {
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
    FUN_004068f0();
    local_8 = 5;
    param_1 = (undefined2 *)0x72;
    iVar4 = FUN_005854b0();
    local_54 = (undefined2 *)0x4ec9f8;
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
  else {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      uStack_30 = 0x4ec81f;
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    uStack_30 = 0;
    local_38 = 7;
    local_3c = 0;
    local_54 = &DAT_00bed1fc;
    local_4c[0] = 0;
    local_58 = 0x4ec84e;
    FUN_00402160();
    local_8 = 1;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 2;
      local_8._1_3_ = 0;
      local_54 = (undefined2 *)0x4ec86e;
      FUN_00584c40();
      local_54 = (undefined2 *)0x4ec878;
      _atexit(FUN_00bcf370);
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    param_1 = (undefined2 *)0x76;
    local_54 = (undefined2 *)0x4ec897;
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
  param_1 = local_68;
  local_54 = (undefined2 *)0x7;
  local_58 = 0;
  local_68[0] = 0;
  FUN_00402160(piVar5,(int)piVar3 - ((int)piVar5 + 2) >> 1);
LAB_004ec8ed:
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
  ExceptionList = local_10;
  return 0;
}

