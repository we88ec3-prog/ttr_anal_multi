
undefined4 * FUN_005a6ef0(undefined4 *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093f710;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[1] = 0;
  param_1[2] = 0;
  local_8 = 0;
  *param_1 = FUI::UICachingData<14,FUI::CExpeditionDialog>::vftable;
  pvVar1 = _malloc(0xf0);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00672ae0(pvVar1);
  }
  param_1[3] = uVar2;
  param_1[1] = 0xe;
  ExceptionList = local_10;
  return param_1;
}

