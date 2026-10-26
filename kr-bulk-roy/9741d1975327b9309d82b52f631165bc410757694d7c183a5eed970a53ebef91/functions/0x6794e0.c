
void FUN_006794e0(short *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  int *local_50;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092c9f0;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_50 = param_4;
  if (param_1 == (short *)0x0) goto LAB_00679737;
  iVar5 = *(int *)(param_1 + 0x2a);
  local_5c = param_2;
  local_58 = param_3;
  iVar2 = FUN_00409560(local_14);
  FUN_004dd400(iVar2,&local_54,&local_5c);
  piVar6 = local_50;
  if ((local_54 == *(int *)(iVar2 + 4)) || (iVar2 = *(int *)(local_54 + 0x18), iVar2 == 0)) {
    iVar2 = *(int *)(iVar5 + 8);
    iVar3 = -1;
    if (iVar2 == 0xb) {
      switch(*(undefined4 *)(iVar5 + 0x5c)) {
      case 0:
        iVar5 = 0;
        break;
      case 1:
      case 2:
      case 3:
        iVar5 = 1;
        break;
      case 4:
      case 5:
        iVar5 = 2;
        break;
      case 6:
      case 7:
        iVar5 = 3;
        break;
      case 8:
      case 9:
      case 10:
        iVar5 = 4;
        break;
      default:
        goto switchD_00679571_default;
      }
                    /* WARNING: Could not recover jumptable at 0x00679596. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&DAT_00679774)[iVar5])();
      return;
    }
    if ((iVar2 == 0x1c) || (iVar2 == 0x10)) {
      switch(*(undefined4 *)(iVar5 + 0x68)) {
      case 0:
        iVar3 = -1;
        break;
      case 1:
        iVar3 = -0x100;
        break;
      case 2:
        iVar3 = -0xa50088;
        break;
      case 3:
        iVar3 = -0xff4423;
        break;
      case 4:
        iVar3 = -0x1dbc01;
      }
    }
switchD_00679571_default:
    local_50[0x55] = iVar3;
    FUN_00757710();
  }
  else {
    iVar3 = -1;
    if (*(int *)(iVar5 + 8) == 0xf) {
      iVar3 = -0x333334;
    }
    else {
      switch(*(undefined4 *)(iVar2 + 0x10)) {
      case 0:
        iVar3 = -1;
        break;
      case 1:
        iVar3 = -0x100;
        break;
      case 2:
        iVar3 = -0xa50088;
        break;
      case 3:
        iVar3 = -0xff4423;
        break;
      case 4:
        iVar3 = -0x1dbc01;
      }
    }
    local_50[0x55] = iVar3;
    local_1c = 7;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffff0000;
    local_8 = 0;
    if (*(int *)(iVar2 + 0x30) == 0) {
      if (7 < *(uint *)(param_1 + 10)) {
        param_1 = *(short **)param_1;
      }
      psVar4 = param_1;
      do {
        sVar1 = *psVar4;
        psVar4 = psVar4 + 1;
      } while (sVar1 != 0);
      FUN_00402160(param_1,(int)psVar4 - (int)(param_1 + 1) >> 1);
    }
    else {
      if (7 < *(uint *)(param_1 + 10)) {
        param_1 = *(short **)param_1;
      }
      uVar7 = 0x18;
      FUN_00585620(0x18,param_1);
      FUN_00585330(uVar7);
      uVar7 = FUN_00483f00();
      local_8._0_1_ = 1;
      FUN_00402800(uVar7);
      local_8 = (uint)local_8._1_3_ << 8;
      if (7 < local_38) {
        FUN_0089120c(local_4c);
      }
      local_38 = 7;
      local_3c = 0;
      local_4c = local_4c & 0xffff0000;
    }
    FUN_00757800(local_30);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    local_1c = 7;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffff0000;
    piVar6 = local_50;
  }
  (**(code **)(*piVar6 + 200))();
LAB_00679737:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

