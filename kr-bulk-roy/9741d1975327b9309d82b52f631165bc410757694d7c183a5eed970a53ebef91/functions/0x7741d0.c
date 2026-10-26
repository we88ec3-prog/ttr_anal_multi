
void FUN_007741d0(int param_1)

{
  void *_Dst;
  uint uVar1;
  int iVar2;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090a577;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0077dc90(param_1 + 4);
  iVar2 = *(int *)(param_1 + 0x268);
  local_14 = 0;
  if (*(int *)(param_1 + 0x26c) - iVar2 >> 2 != 0) {
    do {
      if (*(int *)(iVar2 + local_14 * 4) != 0) {
        iVar2 = *(int *)(iVar2 + local_14 * 4);
        if (iVar2 != 0) {
          local_8 = 0;
          FUN_0077dc90(iVar2);
          local_8 = 1;
          FUN_0057ffd0(**(undefined4 **)(iVar2 + 0x210),*(undefined4 **)(iVar2 + 0x210));
          local_8 = 0xffffffff;
          FUN_0089120c(*(undefined4 *)(iVar2 + 0x210),uVar1);
          FUN_0089120c(iVar2);
        }
        *(undefined4 *)(*(int *)(param_1 + 0x268) + local_14 * 4) = 0;
      }
      iVar2 = *(int *)(param_1 + 0x268);
      local_14 = local_14 + 1;
    } while (local_14 < (uint)(*(int *)(param_1 + 0x26c) - iVar2 >> 2));
  }
  _Dst = *(void **)(param_1 + 0x268);
  if (_Dst != *(void **)(param_1 + 0x26c)) {
    FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0x26c),0);
    *(void **)(param_1 + 0x26c) = _Dst;
  }
  ExceptionList = local_10;
  return;
}

