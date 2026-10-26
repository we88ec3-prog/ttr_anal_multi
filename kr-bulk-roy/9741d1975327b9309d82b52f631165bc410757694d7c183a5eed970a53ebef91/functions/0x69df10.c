
void FUN_0069df10(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined1 auStack_a8 [12];
  undefined4 uStack_9c;
  int iStack_98;
  int *piStack_94;
  undefined4 ***pppuStack_90;
  uint uStack_8c;
  undefined4 local_78;
  undefined1 *local_74;
  int local_70;
  int local_6c;
  undefined4 ***local_30 [5];
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
  if ((param_2 == (undefined4 *)0x0) || (iVar4 = param_2[0x15], iVar4 == 0)) goto LAB_0069e190;
  local_78 = *(undefined4 *)(param_1 + 8);
  local_74 = *(undefined1 **)(param_1 + 0xc);
  pppuStack_90 = (undefined4 ***)0x69df68;
  iVar1 = FUN_00409560();
  pppuStack_90 = (undefined4 ***)&local_78;
  piStack_94 = &local_70;
  uStack_9c = 0x69df78;
  iStack_98 = iVar1;
  FUN_004dd400();
  if ((local_70 == *(int *)(iVar1 + 4)) || (iVar1 = *(int *)(local_70 + 0x18), iVar1 == 0)) {
    iVar1 = *(int *)(iVar4 + 8);
    uVar2 = 0xffffffff;
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
        goto switchD_0069dfa7_default;
      }
                    /* WARNING: Could not recover jumptable at 0x0069dfcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&DAT_0069e1d0)[iVar4])();
      return;
    }
    if ((iVar1 == 0x1c) || (iVar1 == 0x10)) {
      switch(*(undefined4 *)(iVar4 + 0x68)) {
      case 0:
        uVar2 = 0xffffffff;
        break;
      case 1:
        uVar2 = 0xffffff00;
        break;
      case 2:
        uVar2 = 0xff5aff78;
        break;
      case 3:
        uVar2 = 0xff00bbdd;
        break;
      case 4:
        uVar2 = 0xffe243ff;
      }
    }
switchD_0069dfa7_default:
    *(undefined4 *)(local_6c + 0x154) = uVar2;
    if ((uint)param_2[5] < 8) {
      pppuStack_90 = (undefined4 ****)0x69e039;
      FUN_00757710();
    }
    else {
      pppuStack_90 = (undefined4 ****)0x69e027;
      FUN_00757710();
    }
    goto LAB_0069e190;
  }
  uVar2 = 0xffffffff;
  if (*(int *)(iVar4 + 8) == 0xf) {
    uVar2 = 0xffcccccc;
  }
  else {
    switch(*(undefined4 *)(iVar1 + 0x10)) {
    case 0:
      uVar2 = 0xffffffff;
      break;
    case 1:
      uVar2 = 0xffffff00;
      break;
    case 2:
      uVar2 = 0xff5aff78;
      break;
    case 3:
      uVar2 = 0xff00bbdd;
      break;
    case 4:
      uVar2 = 0xffe243ff;
    }
  }
  *(undefined4 *)(local_6c + 0x154) = uVar2;
  if (7 < (uint)param_2[5]) {
    param_2 = (undefined4 *)*param_2;
  }
  piStack_94 = (int *)0x69e09a;
  pppuStack_90 = (undefined4 ***)param_2;
  FUN_00402250();
  local_8 = 0;
  local_70 = *(int *)(iVar4 + 8);
  iVar4 = *(int *)(iVar1 + 0x30);
  pppuStack_90 = (undefined4 ***)0x69e0af;
  iVar1 = FUN_00409490();
  pppuStack_90 = (undefined4 ***)&local_70;
  piStack_94 = (int *)0x69e0c0;
  piVar3 = (int *)FUN_008438c0();
  if ((*piVar3 == *(int *)(iVar1 + 0x14)) || (*(int *)(*piVar3 + 0x10) == 0)) {
    if (iVar4 != 0) {
      local_74 = auStack_a8;
      FUN_00402110(local_30);
      uVar2 = 0x18;
      local_8._0_1_ = 3;
      FUN_00585620(0x18);
      uVar2 = FUN_00585330(uVar2);
      local_8._0_1_ = 0;
      pppuStack_90 = (undefined4 ***)FUN_00460780(uVar2);
      local_8 = CONCAT31(local_8._1_3_,4);
      piStack_94 = (int *)0x69e160;
      FUN_00402800();
      goto LAB_0069e160;
    }
  }
  else {
    pppuStack_90 = (undefined4 ***)0xc;
    piStack_94 = (int *)0x69e0d4;
    FUN_00585620();
    piStack_94 = (int *)0x69e0db;
    FUN_00585330();
    pppuStack_90 = (undefined4 ***)0x69e0e8;
    pppuStack_90 = (undefined4 ***)FUN_004068f0();
    local_8._0_1_ = 1;
    piStack_94 = (int *)0x69e101;
    pppuStack_90 = (undefined4 ***)FUN_00447f50();
    local_8 = CONCAT31(local_8._1_3_,2);
    piStack_94 = (int *)0x69e111;
    FUN_00402800();
    pppuStack_90 = (undefined4 ***)0x69e118;
    FUN_004fa440();
LAB_0069e160:
    local_8 = local_8 & 0xffffff00;
    pppuStack_90 = (undefined4 ***)0x69e16c;
    FUN_004fa440();
  }
  pppuStack_90 = local_30;
  piStack_94 = (int *)0x69e17e;
  FUN_00757800();
  if (7 < local_1c) {
    pppuStack_90 = local_30[0];
    piStack_94 = (int *)0x69e18d;
    FUN_0089120c();
  }
LAB_0069e190:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

