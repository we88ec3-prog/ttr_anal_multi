
undefined4 FUN_004e27b0(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  wchar_t *_Src;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00929b6e;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffe0;
  ExceptionList = &local_14;
  if (param_2 < 2) {
    uVar3 = 0;
  }
  else {
    uVar3 = (param_2 - 2) / 0x2e;
  }
  if (uVar3 != 0) {
    _Src = (wchar_t *)(param_1 + 2);
    do {
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_c = 0;
        FUN_004f3d80(uVar1);
        _atexit((_func_4879 *)&LAB_00bcd1e0);
        local_c = 0xffffffff;
      }
      FUN_004f6950(*(undefined4 *)(_Src + 0x15),_Src);
      iVar2 = FUN_00404ba0();
      if (*(int *)(_Src + 0x15) == *(int *)(iVar2 + 0x5f50)) {
        iVar2 = FUN_00404ba0();
        _wcsncpy_s((wchar_t *)(iVar2 + 0x5f12),0x15,_Src,0x14);
      }
      _Src = _Src + 0x17;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  ExceptionList = local_14;
  return 0;
}

