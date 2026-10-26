
undefined4 FUN_00864d50(void *param_1,undefined4 param_2)

{
  longlong lVar1;
  void *_Dst;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_2;
  if (*(int *)(in_ECX + 0xc) != 0) {
    FUN_00891d3d(*(int *)(in_ECX + 0xc));
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  lVar1 = (ulonglong)*(uint *)(in_ECX + 8) * 0x14;
  _Dst = (void *)FUN_0087dc3d(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  *(void **)(in_ECX + 0xc) = _Dst;
  FID_conflict__memcpy(_Dst,param_1,*(int *)(in_ECX + 8) * 0x14);
  return 1;
}

