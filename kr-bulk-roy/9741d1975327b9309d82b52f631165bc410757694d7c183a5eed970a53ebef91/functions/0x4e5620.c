
undefined4 FUN_004e5620(int param_1,uint param_2)

{
  void *_Dst;
  int iVar1;
  int iVar2;
  int in_ECX;
  
  if ((((*(uint *)(param_1 + 2) < 10) &&
       (iVar1 = *(uint *)(param_1 + 2) * 0x210 + *(int *)(in_ECX + 0x6924),
       *(int *)(iVar1 + 0x5c) != 0)) && (iVar1 != 0)) && (iVar1 != -500)) {
    iVar2 = FUN_00404ba0();
    if (((*(byte *)(param_1 + 2) < 10) &&
        (iVar2 = (uint)*(byte *)(param_1 + 2) * 0x210 + *(int *)(iVar2 + 0x6924),
        *(int *)(iVar2 + 0x5c) != 0)) && (iVar2 != 0)) {
      *(undefined1 *)(iVar2 + 0xd8) = *(undefined1 *)(param_1 + 6);
    }
    _Dst = *(void **)(iVar1 + 0x1f8);
    if (_Dst != *(void **)(iVar1 + 0x1fc)) {
      FID_conflict__memcpy(_Dst,*(void **)(iVar1 + 0x1fc),0);
      *(void **)(iVar1 + 0x1fc) = _Dst;
    }
    if (param_2 < 8) {
      iVar1 = 0;
    }
    else {
      iVar1 = param_2 - 8;
    }
    if (iVar1 != 0) {
      param_1 = param_1 + 8;
      do {
        if (param_1 != 0) {
          FUN_00655ce0();
        }
        param_1 = param_1 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    return 0;
  }
  return 0x80004005;
}

