
void FUN_006771d0(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined1 auStack_e4 [20];
  undefined4 uStack_d0;
  undefined2 *puStack_cc;
  undefined4 uStack_c8;
  undefined1 auStack_c0 [12];
  undefined4 uStack_b4;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined1 *local_94;
  undefined1 *local_90;
  uint local_78;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00948da5;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_94;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    uStack_ac = 0x67723e;
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  *(undefined4 *)(DAT_00f94300 + 0x50f0) = 0;
  FUN_006767d0();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    uStack_ac = 0x677287;
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  local_94 = auStack_c0;
  FUN_00412df0();
  local_c = 2;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c._0_1_ = 3;
    local_c._1_3_ = 0;
    uStack_c8 = 0x6772d5;
    FUN_00584c40();
    uStack_c8 = 0x6772df;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = CONCAT31(local_c._1_3_,2);
  }
  local_90 = (undefined1 *)0x1a;
  uStack_c8 = 0x677305;
  FUN_005740f0();
  if (local_94 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  local_c = 0xffffffff;
  uStack_c8 = 0x67733d;
  FUN_00424c80();
  local_c = 4;
  uStack_ac = 0x67735d;
  FUN_00757800();
  local_c = 0xffffffff;
  if (7 < local_78) {
    uStack_ac = 0x677378;
    FUN_0089120c();
  }
  (**(code **)(**(int **)(param_1 + 0x128) + 200))();
  switch(param_2) {
  case 0:
    uStack_ac = 0x6773b1;
    FUN_00506a60();
    uStack_ac = 0x6773b8;
    puVar3 = (undefined4 *)FUN_00519640();
    if (puVar3 != (undefined4 *)0x0) {
      local_b0 = *(undefined4 *)(*(int *)(param_1 + 0x184) + 0x11c);
      uStack_ac = *puVar3;
      uStack_b4 = 0x6773db;
      FUN_0045f4b0();
    }
    iVar1 = *(int *)(param_1 + 300);
    *(undefined4 *)(iVar1 + 0x98) = *(undefined4 *)(iVar1 + 0xa0);
    *(undefined4 *)(iVar1 + 0x94) = 2;
    *(undefined4 *)(iVar1 + 0xb0) = 0;
    *(undefined4 *)(iVar1 + 0x90) = 0;
    if (param_3 < param_4) {
      *(undefined4 *)(iVar1 + 0xa8) = 1;
      FUN_0068a540();
      FUN_0040b3c0();
      local_c = 5;
      FUN_0040b3f0();
      uStack_ac = 0x677447;
      piVar4 = (int *)FUN_0080ab00();
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x14))();
      }
      local_c = 0xffffffff;
      FUN_007cf450();
    }
    else {
      *(undefined4 *)(iVar1 + 0xa8) = 0;
      FUN_0068a590();
      FUN_0040b3c0();
      local_c = 6;
      FUN_0040b3f0();
      uStack_ac = 0x6774a2;
      piVar4 = (int *)FUN_0080ab00();
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x14))();
      }
      local_c = 0xffffffff;
      FUN_007cf450();
    }
    goto switchD_0067739e_caseD_2;
  case 1:
    iVar1 = *(int *)(param_1 + 300);
    *(undefined4 *)(iVar1 + 0x98) = *(undefined4 *)(iVar1 + 0xa0);
    *(undefined4 *)(iVar1 + 0x94) = 2;
    *(undefined4 *)(iVar1 + 0xa8) = 1;
    *(undefined4 *)(iVar1 + 0xb0) = 0;
    *(undefined4 *)(iVar1 + 0x90) = 0;
    FUN_0068a540();
    FUN_0040b3c0();
    local_c = 7;
    FUN_0040b3f0();
    uStack_ac = 0x67752c;
    piVar4 = (int *)FUN_0080ab00();
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x14))();
    }
    local_c = 0xffffffff;
    FUN_007cf450();
  default:
    goto switchD_0067739e_caseD_2;
  case 4:
    FUN_004054c0();
    uStack_ac = 0;
    local_94 = (undefined1 *)&uStack_c8;
    puStack_cc = &DAT_00bed1fc;
    uStack_d0 = 0x67756e;
    FUN_00402250();
    local_c = 8;
    puStack_cc = (undefined2 *)0x10;
    break;
  case 5:
    FUN_004054c0();
    uStack_ac = 0;
    local_94 = (undefined1 *)&uStack_c8;
    puStack_cc = &DAT_00bed1fc;
    uStack_d0 = 0x677598;
    FUN_00402250();
    local_c = 9;
    puStack_cc = (undefined2 *)0xb;
    break;
  case 6:
    FUN_004054c0();
    uStack_ac = 0;
    local_94 = (undefined1 *)&uStack_c8;
    puStack_cc = &DAT_00bed1fc;
    uStack_d0 = 0x6775c6;
    FUN_00402250();
    local_c = 10;
    puStack_cc = (undefined2 *)0x11;
    break;
  case 7:
    FUN_004054c0();
    uStack_ac = 0;
    local_94 = (undefined1 *)&uStack_c8;
    puStack_cc = &DAT_00bed1fc;
    uStack_d0 = 0x6775f4;
    FUN_00402250();
    local_c = 0xb;
    puStack_cc = (undefined2 *)0x8;
    break;
  case 8:
    FUN_004054c0();
    uStack_ac = 0;
    local_94 = (undefined1 *)&uStack_c8;
    puStack_cc = &DAT_00bed1fc;
    uStack_d0 = 0x677621;
    FUN_00402250();
    local_c = 0xc;
    puStack_cc = (undefined2 *)0x10;
    break;
  case 9:
    FUN_004054c0();
    uStack_ac = 0;
    local_94 = (undefined1 *)&uStack_c8;
    puStack_cc = &DAT_00bed1fc;
    uStack_d0 = 0x67767a;
    FUN_00402250();
    local_c = 0xe;
    puStack_cc = (undefined2 *)0x9;
    break;
  case 0x12:
    FUN_004054c0();
    uStack_ac = 0;
    local_94 = (undefined1 *)&uStack_c8;
    puStack_cc = &DAT_00bed1fc;
    uStack_d0 = 0x67764c;
    FUN_00402250();
    local_c = 0xd;
    puStack_cc = (undefined2 *)0xe8;
  }
  uStack_d0 = 0x67768c;
  FUN_005854b0();
  uStack_d0 = 0x677693;
  uVar5 = FUN_00585330();
  local_90 = auStack_e4;
  FUN_00402250(uVar5);
  local_c = 0xffffffff;
  FUN_0058b270(0xca);
  FUN_0068a350();
switchD_0067739e_caseD_2:
  uStack_ac = 0x6776cb;
  FUN_00675b10();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_94);
  return;
}

