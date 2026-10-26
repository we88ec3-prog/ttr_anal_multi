
void FUN_0062f580(int param_1)

{
  void *_Dst;
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094698e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _Dst = *(void **)(param_1 + 0x114);
  if (_Dst != *(void **)(param_1 + 0x118)) {
    FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0x118),0);
    *(void **)(param_1 + 0x118) = _Dst;
  }
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_8 = 0;
    FUN_004ffe60(uVar1);
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_8 = 0xffffffff;
  }
  FUN_00500e00(&DAT_00fab2a0,*(undefined4 *)(param_1 + 0xf8),param_1 + 0x114);
  FUN_0062fa90();
  ExceptionList = local_10;
  return;
}

