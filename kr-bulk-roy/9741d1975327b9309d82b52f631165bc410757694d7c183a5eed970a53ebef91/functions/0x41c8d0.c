
undefined4 * FUN_0041c8d0(undefined4 *param_1)

{
  void *_Dst;
  undefined4 *puVar1;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00927d44;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0064b9e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  *param_1 = FUI::CCastleMapInside::vftable;
  puVar1 = param_1 + 0x38;
  *puVar1 = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  local_8 = 1;
  if ((DAT_00fb725c & 1) == 0) {
    DAT_00fb725c = DAT_00fb725c | 1;
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    FUN_004a79a0();
    _atexit((_func_4879 *)&DAT_00bccf80);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  local_18 = 0;
  _Dst = (void *)*puVar1;
  if (_Dst != (void *)param_1[0x39]) {
    local_14 = 0;
    FID_conflict__memcpy(_Dst,(void *)param_1[0x39],0);
    param_1[0x39] = local_14 + (int)_Dst;
  }
  FUN_006492c0(puVar1,*puVar1,&local_18);
  ExceptionList = local_10;
  return param_1;
}

