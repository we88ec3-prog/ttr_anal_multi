
void FUN_005a4b90(uint param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 local_30;
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00943c84;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (0x2af9 < param_1) {
    if (param_1 == 0x2afa) {
      FUN_005a4af0(local_14);
      goto LAB_005a50ea;
    }
    goto switchD_005a4be9_caseD_284e;
  }
  if (param_1 == 0x2af9) {
    cVar1 = FUN_005a5240();
    if (cVar1 != '\0') goto LAB_005a50ea;
    goto switchD_005a4be9_caseD_284e;
  }
  switch(param_1) {
  case 0x283c:
    FUN_005a5330(0);
    FUN_00597380(param_1);
    break;
  case 0x283d:
    FUN_005a5330(1);
    FUN_00597380(param_1);
    break;
  case 0x283e:
    FUN_005a5330(2);
    FUN_00597380(param_1);
    break;
  case 0x283f:
    FUN_005a5330(3);
    FUN_00597380(param_1);
    break;
  case 0x2840:
    FUN_005a5330(4);
    FUN_00597380(param_1);
    break;
  case 0x2841:
    FUN_005a5330(5);
    FUN_00597380(param_1);
    break;
  case 0x2842:
    FUN_005a5330(6);
    FUN_00597380(param_1);
    break;
  case 0x2843:
    FUN_005a5330(7);
    FUN_00597380(param_1);
    break;
  case 0x2844:
    FUN_005a5330(8);
    FUN_00597380(param_1);
    break;
  case 0x2845:
    FUN_005a5330(9);
    FUN_00597380(param_1);
    break;
  case 0x2846:
    FUN_005a5330(10);
    FUN_00597380(param_1);
    break;
  case 0x2847:
    FUN_005a5330(0xb);
    FUN_00597380(param_1);
    break;
  case 0x2848:
    FUN_005a5330(0xc);
    FUN_00597380(param_1);
    break;
  case 0x2849:
    FUN_005a5330(0xd);
    FUN_00597380(param_1);
    break;
  case 0x284a:
    FUN_005a5330(0xe);
    FUN_00597380(param_1);
    break;
  case 0x284b:
    FUN_005a5330(0xf);
    FUN_00597380(param_1);
    break;
  case 0x284c:
    FUN_005a5330(0x10);
    FUN_00597380(param_1);
    break;
  case 0x284d:
    FUN_005a5330(0x11);
    FUN_00597380(param_1);
    break;
  default:
    goto switchD_005a4be9_caseD_284e;
  case 0x28a0:
    FUN_005a54a0(0);
    FUN_00597380(param_1);
    break;
  case 0x28a1:
    local_1c = 7;
    local_20 = 0;
    local_30 = (undefined4 *)((uint)local_30._2_2_ << 0x10);
    uVar4 = 0x7f;
    local_8 = 0;
    FUN_00585620(0x7f);
    FUN_00585330(uVar4);
    FUN_0041f490(&local_30);
    if (local_20 != 0) {
      puVar3 = local_30;
      if (local_1c < 8) {
        puVar3 = &local_30;
      }
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_8._0_1_ = 1;
        FUN_004d4d10();
        _atexit((_func_4879 *)&LAB_00bccef0);
        local_8 = (uint)local_8._1_3_ << 8;
      }
LAB_005a4dec:
      FUN_004d5ae0(&DAT_00fb11e8,0,puVar3);
    }
    goto LAB_005a4e03;
  case 0x28a2:
    local_1c = 7;
    local_20 = 0;
    local_30 = (undefined4 *)((uint)local_30._2_2_ << 0x10);
    uVar2 = 2;
    uVar4 = 0x80;
    local_8 = 2;
    FUN_00585620(0x80);
    FUN_00585330(uVar4);
    FUN_0041f490(&local_30);
    if (local_20 != 0) {
      puVar3 = local_30;
      if (local_1c < 8) {
        puVar3 = &local_30;
      }
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_8._0_1_ = 3;
LAB_005a4e84:
        FUN_004d4d10();
        _atexit((_func_4879 *)&LAB_00bccef0);
        local_8 = CONCAT31(local_8._1_3_,uVar2);
      }
      goto LAB_005a4dec;
    }
    goto LAB_005a4e03;
  case 0x28a3:
    local_1c = 7;
    local_20 = 0;
    local_30 = (undefined4 *)((uint)local_30._2_2_ << 0x10);
    uVar2 = 4;
    uVar4 = 0x81;
    local_8 = 4;
    FUN_00585620(0x81);
    FUN_00585330(uVar4);
    FUN_0041f490(&local_30);
    if (local_20 != 0) {
      puVar3 = local_30;
      if (local_1c < 8) {
        puVar3 = &local_30;
      }
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_8._0_1_ = 5;
        goto LAB_005a4e84;
      }
      goto LAB_005a4dec;
    }
    goto LAB_005a4e03;
  case 0x28a4:
    local_1c = 7;
    local_20 = 0;
    local_30 = (undefined4 *)((uint)local_30._2_2_ << 0x10);
    uVar2 = 6;
    uVar4 = 0x82;
    local_8 = 6;
    FUN_00585620(0x82);
    FUN_00585330(uVar4);
    FUN_0041f490(&local_30);
    if (local_20 != 0) {
      puVar3 = local_30;
      if (local_1c < 8) {
        puVar3 = &local_30;
      }
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_8._0_1_ = 7;
        goto LAB_005a4e84;
      }
      goto LAB_005a4dec;
    }
    goto LAB_005a4e03;
  case 0x28a5:
    local_1c = 7;
    local_20 = 0;
    local_30 = (undefined4 *)((uint)local_30._2_2_ << 0x10);
    uVar4 = 0x83;
    local_8 = 8;
    FUN_00585620(0x83);
    FUN_00585330(uVar4);
    FUN_0041f490(&local_30);
    if (local_20 != 0) {
      puVar3 = local_30;
      if (local_1c < 8) {
        puVar3 = &local_30;
      }
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_8._0_1_ = 9;
        FUN_004d4d10();
        _atexit((_func_4879 *)&LAB_00bccef0);
        local_8 = CONCAT31(local_8._1_3_,8);
      }
      FUN_004d5ae0(&DAT_00fb11e8,0,puVar3);
    }
LAB_005a4e03:
    local_8 = 0xffffffff;
    if (local_1c < 8) {
switchD_005a4be9_caseD_284e:
      FUN_00597380(param_1);
    }
    else {
      FUN_0089120c(local_30);
      FUN_00597380(param_1);
    }
    break;
  case 0x28a6:
    local_1c = 7;
    local_20 = 0;
    local_30 = (undefined4 *)((uint)local_30._2_2_ << 0x10);
    uVar4 = 0x84;
    local_8 = 10;
    FUN_00585620(0x84);
    FUN_00585330(uVar4);
    FUN_0041f490(&local_30);
    if (local_20 != 0) {
      puVar3 = local_30;
      if (local_1c < 8) {
        puVar3 = &local_30;
      }
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_8._0_1_ = 0xb;
        FUN_004d4d10();
        _atexit((_func_4879 *)&LAB_00bccef0);
        local_8 = CONCAT31(local_8._1_3_,10);
      }
      FUN_004d5ae0(&DAT_00fb11e8,0,puVar3);
    }
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    local_20 = 0;
    local_30 = (undefined4 *)((uint)local_30 & 0xffff0000);
    local_1c = 7;
    FUN_00597380(param_1);
  }
LAB_005a50ea:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

