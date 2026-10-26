
undefined4 FUN_007cc0a0(undefined4 param_1)

{
  int *piVar1;
  size_t sVar2;
  void *_Dst;
  void *_Src;
  undefined4 uVar3;
  size_t _Size;
  
  uVar3 = 0;
  piVar1 = (int *)FUN_00714770();
  if (piVar1 != (int *)0x0) {
    sVar2 = (**(code **)(*piVar1 + 0x2c))();
    _Dst = (void *)FUN_0087dc3d(sVar2);
    _Size = sVar2;
    _Src = (void *)(**(code **)(*piVar1 + 0x38))();
    FID_conflict__memcpy(_Dst,_Src,_Size);
    uVar3 = FUN_007cc120(param_1,sVar2);
    FUN_00891d3d(_Dst);
    (**(code **)(*piVar1 + 4))();
  }
  return uVar3;
}

