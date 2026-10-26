
undefined4 FUN_00502170(int param_1,int param_2)

{
  void *_Dst;
  int iVar1;
  uint uVar2;
  int in_ECX;
  int local_28 [5];
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009441e6;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  _Dst = *(void **)(in_ECX + 0x5eb0);
  if (_Dst != *(void **)(in_ECX + 0x5eb4)) {
    FID_conflict__memcpy(_Dst,*(void **)(in_ECX + 0x5eb4),0);
    *(void **)(in_ECX + 0x5eb4) = _Dst;
  }
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_c = 0;
  if ((param_2 - 2U & 3) == 0) {
    FUN_0044ab70(param_1 + 2);
  }
  iVar1 = local_28[0];
  FUN_0044aa10(local_28);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c._0_1_ = 1;
    FUN_004dec90(uVar2);
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = (uint)local_c._1_3_ << 8;
  }
  FUN_00500240(in_ECX,DAT_00fab1bc);
  if (iVar1 != 0) {
    FUN_0089120c(iVar1);
  }
  ExceptionList = local_14;
  return 0;
}

