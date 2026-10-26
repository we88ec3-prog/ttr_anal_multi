
undefined4 FUN_004a1230(undefined4 param_1)

{
  int *piVar1;
  size_t sVar2;
  void *_Dst;
  void *_Src;
  undefined4 uVar3;
  size_t _Size;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a97e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = (int *)FUN_00714770(param_1,&DAT_00bed1e0,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (piVar1 != (int *)0x0) {
    sVar2 = (**(code **)(*piVar1 + 0x2c))();
    _Dst = (void *)FUN_0087dc3d(sVar2 + 1);
    _Size = sVar2;
    _Src = (void *)(**(code **)(*piVar1 + 0x38))();
    FID_conflict__memcpy(_Dst,_Src,_Size);
    *(undefined1 *)(sVar2 + (int)_Dst) = 0;
    (**(code **)(*piVar1 + 0x2c))();
    if ((DAT_00fdf3d4 & 1) == 0) {
      DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
      local_8 = 0;
      FUN_006f4380();
      _atexit((_func_4879 *)&LAB_00bce6d0);
      local_8 = 0xffffffff;
    }
    uVar3 = FUN_006f4c20(_Dst);
    (**(code **)(*piVar1 + 4))();
    FUN_00891d3d(_Dst);
    ExceptionList = local_10;
    return uVar3;
  }
  ExceptionList = local_10;
  return 0;
}

