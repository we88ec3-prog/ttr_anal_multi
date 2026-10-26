
void FUN_00549530(int param_1)

{
  void *_Dst;
  int in_EAX;
  int iVar1;
  int *piVar2;
  int local_8;
  
  if (in_EAX != 0) {
    if (in_EAX == 1) {
      *(undefined4 *)(param_1 + 0x54) = 0;
      *(undefined4 *)(param_1 + 0x50) = 0;
      *(undefined4 *)(param_1 + 0x58) = 0;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      *(undefined4 *)(param_1 + 0x60) = 0;
    }
    return;
  }
  piVar2 = (int *)(param_1 + 0xd8);
  local_8 = 3;
  do {
    if (*piVar2 != 0) {
      iVar1 = FUN_00549630();
      iVar1 = param_1 + iVar1 * 0x10;
      *(int *)(iVar1 + 0xa8) = *piVar2;
      *(int *)(iVar1 + 0xac) = piVar2[1];
      *(int *)(iVar1 + 0xb0) = piVar2[2];
      *(int *)(iVar1 + 0xb4) = piVar2[3];
      _Dst = *(void **)(iVar1 + 0x10);
      if (_Dst != *(void **)(iVar1 + 0x14)) {
        FID_conflict__memcpy(_Dst,*(void **)(iVar1 + 0x14),0);
        *(void **)(iVar1 + 0x14) = _Dst;
      }
    }
    piVar2 = piVar2 + 4;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  return;
}

