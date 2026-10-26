
void FUN_007bb240(void)

{
  void *_Dst;
  uint uVar1;
  uint uVar2;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092b79e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = *(int *)(unaff_ESI + 0xb8) - *(int *)(unaff_ESI + 0xb4) >> 2;
  uVar2 = *(uint *)(unaff_ESI + 0xc4);
  if (uVar1 < *(uint *)(unaff_ESI + 0xc4)) {
    uVar2 = uVar1;
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  FUN_007bb3b0(*(int *)(unaff_ESI + 0xb4),*(int *)(unaff_ESI + 0xb4) + uVar2 * 4,
               *(undefined4 *)(unaff_ESI + 0xb8),*(undefined4 *)(DAT_00fb76e8 + 0xc),
               *(undefined4 *)(DAT_00fb76e8 + 0x10),*(undefined4 *)(DAT_00fb76e8 + 0x14));
  uVar1 = 0;
  if (uVar2 != 0) {
    do {
      (**(code **)(**(int **)(*(int *)(unaff_ESI + 0xb4) + uVar1 * 4) + 4))();
      uVar1 = uVar1 + 1;
    } while (uVar1 < uVar2);
  }
  _Dst = *(void **)(unaff_ESI + 0xb4);
  if (_Dst != *(void **)(unaff_ESI + 0xb8)) {
    FID_conflict__memcpy(_Dst,*(void **)(unaff_ESI + 0xb8),0);
    *(void **)(unaff_ESI + 0xb8) = _Dst;
  }
  ExceptionList = local_10;
  return;
}

