
void FUN_006bd050(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  code *pcVar5;
  int *piVar6;
  int iVar7;
  int local_3c;
  int local_38;
  int local_34;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092bf42;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0xa0) != 0) {
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 0;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
    }
    local_8 = 0xffffffff;
    iVar4 = FUN_005c7190();
    if (iVar4 != 0) {
      FUN_0082ef00();
    }
    FUN_00745060();
    (**(code **)(**(int **)(param_1 + 0x88) + 200))();
    iVar4 = DAT_00fe1bd0;
    FUN_005274d0();
    if (local_34 == *(int *)(iVar4 + 0x1c)) {
      local_38 = 0;
    }
    else {
      local_38 = local_34 + 0x10;
      if (local_38 != 0) {
        FUN_00405300();
        (**(code **)(**(int **)(param_1 + 0x84) + 200))();
        iVar4 = DAT_00fe1bd0;
      }
    }
    iVar1 = **(int **)(param_1 + 0xa0);
    FUN_008438c0();
    if (local_3c == *(int *)(iVar4 + 0xc)) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)(local_3c + 0x10);
      if (iVar7 != 0) {
        FUN_00757800();
        (**(code **)(**(int **)(param_1 + 0x80) + 200))();
        iVar4 = DAT_00fe1bd0;
      }
    }
    iVar2 = *(int *)(local_38 + 0x24);
    FUN_008438c0();
    if ((iVar1 != *(int *)(iVar4 + 0xc)) && (iVar4 = *(int *)(iVar1 + 0x10), iVar4 != 0)) {
      for (piVar6 = *(int **)(iVar4 + 0x6c); piVar6 != *(int **)(iVar4 + 0x70); piVar6 = piVar6 + 4)
      {
        if (*piVar6 == iVar2) {
          (**(code **)(**(int **)(param_1 + 0x8c) + 0xd0))();
          FUN_00403040(iVar7 + 0x50,0,0xffffffff);
          FUN_0046e3c0();
          local_8 = 1;
          if ((DAT_00f94394 & 1) == 0) {
            DAT_00f94394 = DAT_00f94394 | 1;
            local_8._0_1_ = 2;
            local_8._1_3_ = 0;
            FUN_005c3de0();
            _atexit((_func_4879 *)&LAB_00bccc30);
            local_8 = CONCAT31(local_8._1_3_,1);
          }
          iVar4 = FUN_005c7190();
          if (iVar4 != 0) {
            FUN_0082ef00();
          }
          FUN_00745060();
          local_8 = 0xffffffff;
          if (7 < local_1c) {
            FUN_0089120c();
          }
          FUN_00749c50();
          FUN_00749d00();
          FUN_00749a00();
          pcVar5 = *(code **)(**(int **)(param_1 + 0x8c) + 200);
          goto LAB_006bd230;
        }
      }
    }
    pcVar5 = *(code **)(**(int **)(param_1 + 0x8c) + 0xd4);
LAB_006bd230:
    (*pcVar5)();
    if ((DAT_00fb72a4 & 1) == 0) {
      DAT_00fb72a4 = DAT_00fb72a4 | 1;
      local_8 = 3;
      FUN_0049f850();
      _atexit((_func_4879 *)&LAB_00bccfe0);
      local_8 = 0xffffffff;
    }
    FUN_0049fed0();
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}

