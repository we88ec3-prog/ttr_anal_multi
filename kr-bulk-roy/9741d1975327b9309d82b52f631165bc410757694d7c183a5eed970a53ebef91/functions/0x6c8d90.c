
void FUN_006c8d90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *_Dst;
  undefined4 *in_EAX;
  undefined4 *puVar1;
  
  _Dst = (void *)*in_EAX;
  if (_Dst != (void *)in_EAX[1]) {
    FID_conflict__memcpy(_Dst,(void *)in_EAX[1],0);
    in_EAX[1] = _Dst;
  }
  FUN_004a8680();
  puVar1 = (undefined4 *)FUN_00891268(0x20);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[5] = param_2;
    puVar1[3] = 0;
    puVar1[4] = 0xf431d;
    *puVar1 = FoxUI::FXUIEventI3::vftable;
    puVar1[6] = param_3;
    puVar1[7] = param_4;
    FUN_004072a0();
    return;
  }
  FUN_004072a0();
  return;
}

