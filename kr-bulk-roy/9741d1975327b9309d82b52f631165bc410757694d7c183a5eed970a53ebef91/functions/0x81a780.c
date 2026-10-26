
undefined2 * FUN_0081a780(undefined2 *param_1)

{
  void *_Dst;
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090730b;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 2) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  local_8 = 0;
  *(undefined4 *)(param_1 + 10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *param_1 = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  _Dst = *(void **)(param_1 + 2);
  if (_Dst != *(void **)(param_1 + 4)) {
    FID_conflict__memcpy(_Dst,*(void **)(param_1 + 4),0);
    *(void **)(param_1 + 4) = _Dst;
  }
  FUN_00655ce0(uVar1);
  *(undefined4 *)(param_1 + 10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  ExceptionList = local_10;
  return param_1;
}

