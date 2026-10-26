
undefined4 * FUN_00648830(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *_Dst;
  int local_2c;
  int local_1c;
  void *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00926bca;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0064b9e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  puVar1 = param_1 + 0x38;
  *param_1 = FUI::CTownWorldMapInside::vftable;
  param_1[0x37] = 0;
  *puVar1 = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  puVar2 = param_1 + 0x3c;
  *puVar2 = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  local_8._1_3_ = 0;
  if ((DAT_00fb725c & 1) == 0) {
    DAT_00fb725c = DAT_00fb725c | 1;
    local_8._0_1_ = 3;
    local_8._1_3_ = 0;
    FUN_004a79a0();
    _atexit((_func_4879 *)&DAT_00bccf80);
  }
  local_8._0_1_ = 2;
  FUN_00450340();
  local_8 = CONCAT31(local_8._1_3_,4);
  local_18 = (void *)*puVar1;
  local_1c = 0;
  if (local_18 != (void *)param_1[0x39]) {
    local_14 = 0;
    FID_conflict__memcpy(local_18,(void *)param_1[0x39],0);
    param_1[0x39] = local_14 + (int)local_18;
  }
  FUN_006492c0(puVar1,*puVar1,&local_1c);
  _Dst = (void *)*puVar2;
  local_18 = (void *)0x0;
  if (_Dst != (void *)param_1[0x3d]) {
    local_1c = 0;
    FID_conflict__memcpy(_Dst,(void *)param_1[0x3d],0);
    param_1[0x3d] = local_1c + (int)_Dst;
  }
  FUN_006492c0(puVar2,*puVar2,&local_18);
  param_1[0x36] = 0;
  if (local_2c != 0) {
    FUN_0089120c(local_2c);
  }
  ExceptionList = local_10;
  return param_1;
}

