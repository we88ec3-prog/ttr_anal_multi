
undefined1 FUN_005498c0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x50) + 0x88);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if ((((uVar2 < 10) &&
       (iVar3 = uVar2 * 0x210, iVar1 = iVar3 + DAT_00f94304,
       *(int *)(iVar3 + 0x5c + DAT_00f94304) != 0)) && (iVar1 != 0)) && (iVar1 + 500 != 0)) {
    ExceptionList = local_14;
    return *(undefined1 *)((uint)(*(char *)(iVar1 + 0x1f6) != '\0') + iVar1 + 500);
  }
  ExceptionList = local_14;
  return 0;
}

