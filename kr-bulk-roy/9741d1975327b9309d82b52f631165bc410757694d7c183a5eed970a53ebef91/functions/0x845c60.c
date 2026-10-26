
undefined4 * FUN_00845c60(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *_Dst;
  uint uVar2;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911557;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0077fd70(param_1);
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x15] = 0;
  param_1[0x1b] = 3;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1c] = 0;
  *param_1 = gbGeometry::vftable;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  puVar1 = param_1 + 0x27;
  *puVar1 = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  local_8 = 4;
  param_1[0x2c] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x2b] = 0;
  if (param_1[0x1f] != param_1[0x20]) {
    local_14 = FUN_00848b00(param_1[0x20],param_1[0x1f],param_1,uVar2);
    FUN_00848b60(param_1);
    param_1[0x20] = local_14;
  }
  FUN_0077f820(100);
  local_18 = 0;
  _Dst = (void *)*puVar1;
  if (_Dst != (void *)param_1[0x28]) {
    local_14 = 0;
    FID_conflict__memcpy(_Dst,(void *)param_1[0x28],0);
    param_1[0x28] = local_14 + (int)_Dst;
  }
  FUN_00848740(puVar1,*puVar1,&local_18);
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x23] = 1;
  ExceptionList = local_10;
  return param_1;
}

