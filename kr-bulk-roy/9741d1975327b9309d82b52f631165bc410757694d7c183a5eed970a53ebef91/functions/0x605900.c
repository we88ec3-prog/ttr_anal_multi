
void FUN_00605900(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_78;
  undefined4 local_74;
  int local_70;
  int *local_6c;
  undefined4 local_68;
  uint local_54;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092dfbe;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar4 = param_2[0x15];
  if (iVar4 == 0) goto LAB_00605c12;
  local_78 = *(undefined4 *)(param_1 + 0x10);
  local_74 = *(undefined4 *)(param_1 + 0x14);
  iVar1 = FUN_00409560(local_14);
  FUN_004dd400(iVar1,&local_70,&local_78);
  if ((local_70 == *(int *)(iVar1 + 4)) || (iVar1 = *(int *)(local_70 + 0x18), iVar1 == 0)) {
    iVar1 = *(int *)(iVar4 + 8);
    iVar2 = -1;
    if (iVar1 == 0xb) {
      switch(*(undefined4 *)(iVar4 + 0x5c)) {
      case 0:
        iVar4 = 0;
        break;
      case 1:
      case 2:
      case 3:
        iVar4 = 1;
        break;
      case 4:
      case 5:
        iVar4 = 2;
        break;
      case 6:
      case 7:
        iVar4 = 3;
        break;
      case 8:
      case 9:
      case 10:
        iVar4 = 4;
        break;
      default:
        goto switchD_00605991_default;
      }
                    /* WARNING: Could not recover jumptable at 0x006059b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&DAT_00605c50)[iVar4])();
      return;
    }
    if ((iVar1 == 0x1c) || (iVar1 == 0x10)) {
      switch(*(undefined4 *)(iVar4 + 0x68)) {
      case 0:
        iVar2 = -1;
        break;
      case 1:
        iVar2 = -0x100;
        break;
      case 2:
        iVar2 = -0xa50088;
        break;
      case 3:
        iVar2 = -0xff4423;
        break;
      case 4:
        iVar2 = -0x1dbc01;
      }
    }
switchD_00605991_default:
    local_6c[0x55] = iVar2;
    if ((uint)param_2[5] < 8) {
      FUN_00757710();
    }
    else {
      FUN_00757710();
    }
  }
  else {
    iVar2 = -1;
    if (*(int *)(iVar4 + 8) == 0xf) {
      iVar2 = -0x333334;
    }
    else {
      switch(*(undefined4 *)(iVar1 + 0x10)) {
      case 0:
        iVar2 = -1;
        break;
      case 1:
        iVar2 = -0x100;
        break;
      case 2:
        iVar2 = -0xa50088;
        break;
      case 3:
        iVar2 = -0xff4423;
        break;
      case 4:
        iVar2 = -0x1dbc01;
      }
    }
    local_6c[0x55] = iVar2;
    local_1c = 7;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffff0000;
    local_8._1_3_ = 0;
    iVar1 = *(int *)(iVar1 + 0x30);
    if ((DAT_00faaffc & 1) == 0) {
      DAT_00faaffc = DAT_00faaffc | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_008132e0();
      _atexit((_func_4879 *)&LAB_00bccce0);
    }
    local_8._0_1_ = 0;
    local_70 = *(int *)(iVar4 + 8);
    piVar3 = (int *)FUN_008438c0(&local_70);
    if ((*piVar3 == DAT_00fab014) || (*(int *)(*piVar3 + 0x10) == 0)) {
      if (iVar1 == 0) {
        FUN_0041f490(local_30);
      }
      else {
        if (7 < (uint)param_2[5]) {
          param_2 = (undefined4 *)*param_2;
        }
        uVar5 = 0x18;
        FUN_00585620(0x18,param_2);
        FUN_00585330(uVar5);
        uVar5 = FUN_00483f00();
        local_8._0_1_ = 4;
        FUN_00402800(uVar5);
        local_8._0_1_ = 0;
        FUN_004fa440();
      }
    }
    else {
      uVar5 = 0xc;
      FUN_00585620(0xc);
      FUN_00585330(uVar5);
      uVar5 = FUN_004068f0();
      local_8._0_1_ = 2;
      uVar5 = FUN_00447f50(uVar5);
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_00402800(uVar5);
      if (7 < local_38) {
        FUN_0089120c(local_4c);
      }
      local_8._0_1_ = 0;
      local_38 = 7;
      local_3c = 0;
      local_4c = local_4c & 0xffff0000;
      if (7 < local_54) {
        FUN_0089120c(local_68);
      }
    }
    FUN_00757800(local_30);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    local_1c = 7;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffff0000;
  }
  (**(code **)(*local_6c + 200))();
LAB_00605c12:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

