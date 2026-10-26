
undefined4 * FUN_006a5940(undefined4 *param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091ae20;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[1] = 0;
  param_1[2] = 0;
  local_8 = 0;
  *param_1 = FUI::UICachingData<253,FUI::CGuildInfoInside>::vftable;
  pvVar2 = _malloc(0x118);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_006a7140(uVar1);
  }
  param_1[3] = uVar3;
  param_1[1] = 0xfd;
  ExceptionList = local_10;
  return param_1;
}

