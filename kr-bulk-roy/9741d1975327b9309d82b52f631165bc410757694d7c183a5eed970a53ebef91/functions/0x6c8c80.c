
void FUN_006c8c80(undefined4 param_1,undefined4 param_2)

{
  void *_Dst;
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919cb7;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _Dst = (void *)*in_ECX;
  if (_Dst != (void *)in_ECX[1]) {
    FID_conflict__memcpy(_Dst,(void *)in_ECX[1],0);
    in_ECX[1] = _Dst;
  }
  FUN_004a8680(uVar2);
  puVar3 = (undefined4 *)FUN_00891268(0x20);
  if (puVar3 != (undefined4 *)0x0) {
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
      }
    }
    uVar1 = DAT_00f948b8;
    puVar3[6] = DAT_00f948bc;
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0xffffffff;
    puVar3[3] = 0;
    puVar3[4] = 0xf431d;
    *puVar3 = FoxUI::FXUIEventI3::vftable;
    puVar3[5] = uVar1;
    puVar3[7] = param_2;
  }
  local_8 = 0xffffffff;
  FUN_004072a0();
  ExceptionList = local_10;
  return;
}

