
undefined4 FUN_007cc280(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  size_t _Size;
  void *_Dst;
  void *_Src;
  undefined4 uVar2;
  
  uVar2 = 0;
  piVar1 = (int *)FUN_00714770();
  if (piVar1 != (int *)0x0) {
    _Size = (**(code **)(*piVar1 + 0x2c))();
    _Dst = (void *)FUN_0087dc3d(_Size);
    _Src = (void *)(**(code **)(*piVar1 + 0x38))();
    FID_conflict__memcpy(_Dst,_Src,_Size);
    uVar2 = FUN_007cc300(param_1,param_2);
    FUN_00891d3d(_Dst);
    (**(code **)(*piVar1 + 4))();
  }
  return uVar2;
}

