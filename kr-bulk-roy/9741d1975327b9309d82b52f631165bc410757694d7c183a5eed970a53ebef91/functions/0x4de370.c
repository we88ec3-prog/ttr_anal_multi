
undefined4 FUN_004de370(int param_1,uint param_2)

{
  void *_Dst;
  uint uVar1;
  int in_ECX;
  int *piVar2;
  
  *(undefined4 *)(in_ECX + 0x5ef8) = *(undefined4 *)(param_1 + 2);
  _Dst = *(void **)(in_ECX + 0x5ee8);
  if (_Dst != *(void **)(in_ECX + 0x5eec)) {
    FID_conflict__memcpy(_Dst,*(void **)(in_ECX + 0x5eec),0);
    *(void **)(in_ECX + 0x5eec) = _Dst;
  }
  if (param_2 < 6) {
    uVar1 = 0;
  }
  else {
    uVar1 = param_2 - 6 >> 2;
  }
  if (uVar1 != 0) {
    piVar2 = (int *)(param_1 + 6);
    do {
      if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
        FUN_004a8680();
      }
      piVar2 = piVar2 + 1;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return 0;
}

