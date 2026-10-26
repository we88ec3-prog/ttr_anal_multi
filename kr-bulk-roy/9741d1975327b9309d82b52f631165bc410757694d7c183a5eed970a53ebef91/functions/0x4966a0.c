
/* WARNING: Removing unreachable block (ram,0x004968f1) */

void FUN_004966a0(int param_1)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00930ffd;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  switch(*(undefined4 *)(param_1 + 2)) {
  case 0:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 0;
    FUN_005854b0();
    uVar3 = FUN_00585330();
    goto LAB_004969b9;
  case 1:
  case 6:
    local_8 = 1;
    if (*(int *)(param_1 + 6) == 0) {
      FUN_005854b0();
      FUN_00585330();
LAB_0049676e:
      FUN_0041f490();
    }
    else if (*(int *)(param_1 + 6) == 1) {
      FUN_005854b0();
      FUN_00585330();
      goto LAB_0049676e;
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = local_30 & 0xffff0000;
    local_8._0_1_ = 2;
    FUN_00425330();
    FUN_004f6b20();
    local_38 = 7;
    local_3c = 0;
    local_4c = (undefined4 *)((uint)local_4c._2_2_ << 0x10);
    local_8._0_1_ = 3;
    uVar1 = (undefined1)local_8;
    local_8._0_1_ = 3;
    if (*(int *)(param_1 + 2) == 1) {
      local_8._0_1_ = uVar1;
      FUN_005854b0();
      FUN_00585330();
      FUN_00498ef0();
      local_8 = CONCAT31(local_8._1_3_,4);
      FUN_00402800();
LAB_00496851:
      local_8._0_1_ = 3;
      FUN_004fa440();
      uVar1 = (undefined1)local_8;
    }
    else if (*(int *)(param_1 + 2) == 6) {
      FUN_005854b0();
      FUN_00585330();
      FUN_00498ef0();
      local_8 = CONCAT31(local_8._1_3_,5);
      FUN_00402800();
      goto LAB_00496851;
    }
    local_8._0_1_ = uVar1;
    FUN_004054c0();
    FUN_00402250();
    local_8._0_1_ = 6;
    puVar2 = local_4c;
    if (local_38 < 8) {
      puVar2 = &local_4c;
    }
    FUN_00402250(puVar2);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_0058b270(0xca);
    if (7 < local_38) {
      FUN_0089120c();
    }
    local_38 = 7;
    local_3c = 0;
    local_4c = (undefined4 *)((uint)local_4c & 0xffff0000);
    if (7 < local_1c) {
      FUN_0089120c();
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = local_30 & 0xffff0000;
    goto switchD_004966dd_default;
  case 2:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 7;
    break;
  case 3:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 8;
    break;
  case 4:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 9;
    break;
  case 5:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 10;
    break;
  default:
    goto switchD_004966dd_default;
  }
  FUN_005854b0();
  uVar3 = FUN_00585330();
LAB_004969b9:
  FUN_00402250(uVar3);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
switchD_004966dd_default:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

