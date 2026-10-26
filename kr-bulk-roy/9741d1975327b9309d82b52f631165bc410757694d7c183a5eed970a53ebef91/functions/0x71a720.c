
undefined4 FUN_0071a720(undefined4 *param_1,size_t *param_2)

{
  int in_EAX;
  size_t sVar1;
  void *_Dst;
  undefined4 uVar2;
  void *in_ECX;
  size_t unaff_ESI;
  undefined4 local_8;
  
  if (in_EAX == 1) {
    sVar1 = unaff_ESI;
    if (unaff_ESI == 0) {
      sVar1 = 1;
    }
    _Dst = (void *)(*(code *)PTR_FUN_00d63d48)(sVar1);
    if (_Dst != (void *)0x0) {
      FID_conflict__memcpy(_Dst,in_ECX,unaff_ESI);
      *param_1 = _Dst;
      *param_2 = unaff_ESI;
      return 1;
    }
    return 0;
  }
  local_8._1_3_ = (uint3)((uint)in_ECX >> 8);
  if (in_EAX == 3) {
    local_8 = (uint)local_8._1_3_ << 8;
    uVar2 = FUN_00722710(param_1,param_2,local_8);
    return uVar2;
  }
  if (in_EAX == 2) {
    local_8 = (uint)local_8._1_3_ << 8;
    uVar2 = FUN_007226c0(param_1,param_2,local_8);
    return uVar2;
  }
  if (in_EAX == 6) {
    local_8 = (uint)local_8._1_3_ << 8;
    uVar2 = FUN_007227b0(param_1,param_2,local_8);
    return uVar2;
  }
  if (in_EAX == 5) {
    local_8 = (uint)local_8._1_3_ << 8;
    uVar2 = FUN_00722760(param_1,param_2,local_8);
    return uVar2;
  }
  return 0;
}

