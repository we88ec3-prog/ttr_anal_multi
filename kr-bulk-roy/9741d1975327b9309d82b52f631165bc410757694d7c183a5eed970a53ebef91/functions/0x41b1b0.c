
void FUN_0041b1b0(int param_1)

{
  void *_Dst;
  uint uVar1;
  int iVar2;
  uint local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009458dc;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  _Dst = *(void **)(param_1 + 0x118);
  if (_Dst != *(void **)(param_1 + 0x11c)) {
    FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0x11c),0);
    *(void **)(param_1 + 0x11c) = _Dst;
  }
  if ((*(uint *)(*(int *)(param_1 + 0x110) + 0x28) >> 9 & 1) == 0) {
    FUN_0041b470(uVar1);
  }
  else {
    if ((DAT_00fb725c & 1) == 0) {
      DAT_00fb725c = DAT_00fb725c | 1;
      local_c = 0;
      FUN_004a79a0();
      _atexit((_func_4879 *)&DAT_00bccf80);
      local_c = 0xffffffff;
    }
    local_20 = 0;
    if (DAT_00fb7294 - DAT_00fb7290 >> 2 != 0) {
      do {
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c = 1;
          FUN_004e1590();
          _atexit((_func_4879 *)&LAB_00bccc80);
          local_c = 0xffffffff;
        }
        uVar1 = FUN_004a7810(*(undefined4 *)(DAT_00fb7290 + local_20 * 4));
        iVar2 = FUN_004d43d0();
        if ((int)(uVar1 & 0xff) <= iVar2) {
          if (*(char *)(*(int *)(DAT_00fb7290 + local_20 * 4) + 9) == '\0') {
            FUN_00443d10();
          }
          else {
            FUN_0044a480((undefined4 *)(param_1 + 0x118),*(undefined4 *)(param_1 + 0x118));
          }
        }
        local_20 = local_20 + 1;
      } while (local_20 < (uint)(DAT_00fb7294 - DAT_00fb7290 >> 2));
    }
  }
  FUN_0041b5a0(param_1);
  FUN_00749920(*(undefined4 *)(param_1 + 0x100));
  (**(code **)(**(int **)(param_1 + 0x100) + 200))();
  ExceptionList = local_14;
  return;
}

