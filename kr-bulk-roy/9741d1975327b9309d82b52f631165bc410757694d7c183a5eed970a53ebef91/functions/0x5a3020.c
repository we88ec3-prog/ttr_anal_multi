
undefined4 * FUN_005a3020(undefined4 *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091f7e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[1] = 0;
  param_1[2] = 0;
  local_8 = 0;
  *param_1 = FUI::UICachingData<218,FUI::CBuyPracticeActiveWnd>::vftable;
  pvVar1 = _malloc(0x22c);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0061b780(pvVar1);
  }
  param_1[3] = uVar2;
  param_1[1] = 0xda;
  ExceptionList = local_10;
  return param_1;
}

