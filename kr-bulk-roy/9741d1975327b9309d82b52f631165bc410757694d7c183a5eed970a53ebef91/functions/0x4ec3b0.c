
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ec3b0(void)

{
  size_t _Size;
  size_t sVar1;
  int unaff_ESI;
  undefined2 local_100e;
  undefined2 local_100c;
  undefined1 uStack_100a;
  undefined1 uStack_1009;
  undefined2 local_1008;
  undefined1 local_1006;
  undefined1 local_1005 [4089];
  uint local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(int *)(unaff_ESI + 0x5f14) == 0) {
    FUN_006edb60(&DAT_00c0d2d8);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (*(uint *)(unaff_ESI + 0x5f10) <= *(uint *)(unaff_ESI + 0x5f1c)) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_100e = 0xbc9;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(2,&local_100e,2);
    }
    if (*(int *)(unaff_ESI + 0x5f14) != 0) {
      FUN_00891d3d(*(int *)(unaff_ESI + 0x5f14));
      *(undefined4 *)(unaff_ESI + 0x5f14) = 0;
    }
    *(undefined4 *)(unaff_ESI + 0x5f10) = 0;
    *(undefined4 *)(unaff_ESI + 0x5f18) = 0;
    *(undefined4 *)(unaff_ESI + 0x5f1c) = 0;
    *(undefined4 *)(unaff_ESI + 0x5f20) = 0;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_100c = 0xbc8;
  uStack_100a = *(undefined1 *)(unaff_ESI + 0x5f18);
  _Size = *(uint *)(unaff_ESI + 0x5f10) - *(uint *)(unaff_ESI + 0x5f1c);
  local_c = 7;
  if (0x400 < _Size) {
    _Size = 0x400;
  }
  uStack_1009 = (undefined1)_Size;
  local_1008 = (undefined2)(_Size >> 8);
  local_1006 = (undefined1)(_Size >> 0x18);
  sVar1 = _Size;
  if (_Size + 7 < 0x1001) {
    FID_conflict__memcpy(local_1005,*(void **)(unaff_ESI + 0x5f20),_Size);
    sVar1 = CONCAT13(local_1006,CONCAT21(local_1008,uStack_1009));
    local_c = local_c + _Size;
  }
  if (7 < local_c) {
    (**(code **)(*DAT_00fba854 + 0x10))(2,&local_100c,local_c);
    sVar1 = CONCAT13(local_1006,CONCAT21(local_1008,uStack_1009));
  }
  *(int *)(unaff_ESI + 0x5f1c) = *(int *)(unaff_ESI + 0x5f1c) + sVar1;
  *(int *)(unaff_ESI + 0x5f20) = *(int *)(unaff_ESI + 0x5f20) + sVar1;
  *(int *)(unaff_ESI + 0x5f18) = *(int *)(unaff_ESI + 0x5f18) + 1;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

