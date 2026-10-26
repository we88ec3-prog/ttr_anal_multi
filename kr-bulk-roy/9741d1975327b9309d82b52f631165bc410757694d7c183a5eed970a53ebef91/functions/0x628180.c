
undefined4 * FUN_00628180(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091ae20;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[1] = 0;
  param_1[2] = 0;
  local_8 = 0;
  *param_1 = FUI::UICachingData<190,FUI::CKeyOptionComWnd>::vftable;
  puVar1 = _malloc(0x11c);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    FUN_00629e40(puVar1);
    *puVar1 = FUI::CKeyOptionComWnd::vftable;
  }
  param_1[3] = puVar1;
  param_1[1] = 0xbe;
  ExceptionList = local_10;
  return param_1;
}

