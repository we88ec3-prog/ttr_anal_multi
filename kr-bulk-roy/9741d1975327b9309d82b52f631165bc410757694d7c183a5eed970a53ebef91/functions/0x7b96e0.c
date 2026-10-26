
void FUN_007b96e0(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  void *_Dst;
  uint uVar4;
  int in_ECX;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093803e;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*(int *)(in_ECX + 0x3c) == 1) && (*(int *)(in_ECX + 0x40) != 0)) {
    FUN_007e5c70(*(int *)(in_ECX + 0x40));
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0(uVar4);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    FUN_007e0be0();
    local_14 = 0;
    if (*(int *)(in_ECX + 0xa8) - *(int *)(in_ECX + 0xa4) >> 2 != 0) {
      do {
        iVar1 = *(int *)(*(int *)(in_ECX + 0xa4) + local_14 * 4);
        iVar2 = *(int *)(iVar1 + 0x34);
        if (iVar2 != 0) {
          FUN_007d7300();
          FUN_0089120c(iVar2);
          *(undefined4 *)(iVar1 + 0x34) = 0;
        }
        local_14 = local_14 + 1;
      } while (local_14 < (uint)(*(int *)(in_ECX + 0xa8) - *(int *)(in_ECX + 0xa4) >> 2));
    }
    FUN_007e2fc0(in_ECX + 0x90);
    uVar4 = 0;
    if (*(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c) >> 2 != 0) {
      do {
        FUN_007e4260(*(undefined4 *)(*(int *)(in_ECX + 0x7c) + uVar4 * 4));
        uVar4 = uVar4 + 1;
      } while (uVar4 < (uint)(*(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c) >> 2));
    }
    FUN_007e2740();
    uVar4 = 0;
    if (*(int *)(in_ECX + 0xcc) - *(int *)(in_ECX + 200) >> 2 != 0) {
      do {
        if (*(int *)(*(int *)(in_ECX + 200) + uVar4 * 4) != 0) {
          piVar3 = *(int **)(*(int *)(in_ECX + 200) + uVar4 * 4);
          if (piVar3 != (int *)0x0) {
            (**(code **)(*piVar3 + 4))(1);
          }
          *(undefined4 *)(*(int *)(in_ECX + 200) + uVar4 * 4) = 0;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < (uint)(*(int *)(in_ECX + 0xcc) - *(int *)(in_ECX + 200) >> 2));
    }
    _Dst = *(void **)(in_ECX + 200);
    if (_Dst != *(void **)(in_ECX + 0xcc)) {
      FID_conflict__memcpy(_Dst,*(void **)(in_ECX + 0xcc),0);
      *(void **)(in_ECX + 0xcc) = _Dst;
    }
    *(undefined4 *)(in_ECX + 0x3c) = 0;
  }
  ExceptionList = local_10;
  return;
}

