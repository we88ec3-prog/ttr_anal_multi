
void FUN_0069f210(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_a8 [12];
  undefined4 uStack_9c;
  int iStack_98;
  int *piStack_94;
  uint *puStack_90;
  uint uStack_8c;
  undefined4 local_78;
  undefined1 *local_74;
  int local_70;
  int *local_6c;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092c568;
  local_10 = ExceptionList;
  uStack_8c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uStack_8c;
  if ((param_2 == (undefined4 *)0x0) || (iVar4 = param_2[0x15], iVar4 == 0)) goto LAB_0069f4ba;
  local_78 = *(undefined4 *)(param_1 + 8);
  local_74 = *(undefined1 **)(param_1 + 0xc);
  puStack_90 = (uint *)0x69f268;
  iVar1 = FUN_00409560();
  puStack_90 = &local_78;
  piStack_94 = &local_70;
  uStack_9c = 0x69f278;
  iStack_98 = iVar1;
  FUN_004dd400();
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
        goto switchD_0069f2a7_default;
      }
                    /* WARNING: Could not recover jumptable at 0x0069f2cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&DAT_0069f4f8)[iVar4])();
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
switchD_0069f2a7_default:
    local_6c[0x55] = iVar2;
    if ((uint)param_2[5] < 8) {
      puStack_90 = (uint *)0x69f339;
      FUN_00757710();
    }
    else {
      puStack_90 = (uint *)0x69f327;
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
    if (7 < (uint)param_2[5]) {
      param_2 = (undefined4 *)*param_2;
    }
    piStack_94 = (int *)0x69f39a;
    puStack_90 = param_2;
    FUN_00402250();
    local_8 = 0;
    local_70 = *(int *)(iVar4 + 8);
    iVar4 = *(int *)(iVar1 + 0x30);
    puStack_90 = (uint *)0x69f3af;
    iVar1 = FUN_00409490();
    puStack_90 = (uint *)&local_70;
    piStack_94 = (int *)0x69f3c0;
    piVar3 = (int *)FUN_008438c0();
    if ((*piVar3 == *(int *)(iVar1 + 0x14)) || (*(int *)(*piVar3 + 0x10) == 0)) {
      if (iVar4 != 0) {
        local_74 = auStack_a8;
        FUN_00402110(local_30);
        uVar5 = 0x18;
        local_8._0_1_ = 3;
        FUN_00585620(0x18);
        uVar5 = FUN_00585330(uVar5);
        local_8._0_1_ = 0;
        puStack_90 = (uint *)FUN_00460780(uVar5);
        local_8 = CONCAT31(local_8._1_3_,4);
        piStack_94 = (int *)0x69f460;
        FUN_00402800();
        goto LAB_0069f460;
      }
    }
    else {
      puStack_90 = (uint *)0xc;
      piStack_94 = (int *)0x69f3d4;
      FUN_00585620();
      piStack_94 = (int *)0x69f3db;
      FUN_00585330();
      puStack_90 = (uint *)0x69f3e8;
      puStack_90 = (uint *)FUN_004068f0();
      local_8._0_1_ = 1;
      piStack_94 = (int *)0x69f401;
      puStack_90 = (uint *)FUN_00447f50();
      local_8 = CONCAT31(local_8._1_3_,2);
      piStack_94 = (int *)0x69f411;
      FUN_00402800();
      puStack_90 = (uint *)0x69f418;
      FUN_004fa440();
LAB_0069f460:
      local_8 = local_8 & 0xffffff00;
      puStack_90 = (uint *)0x69f46c;
      FUN_004fa440();
    }
    puStack_90 = local_30;
    piStack_94 = (int *)0x69f47e;
    FUN_00757800();
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      puStack_90 = (uint *)local_30[0];
      piStack_94 = (int *)0x69f494;
      FUN_0089120c();
    }
    local_1c = 7;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffff0000;
  }
  puStack_90 = (uint *)0x69f4ba;
  (**(code **)(*local_6c + 200))();
LAB_0069f4ba:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

