
void FUN_004091b0(void)

{
  int iVar1;
  int *in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((in_ECX[0xa6] == 1) && (DAT_00f94300 + 0x16f8 != 0)) {
    if (99 < in_ECX[0xa7] - 1U) {
      FUN_006edb60(&DAT_00c0ddc0);
      ExceptionList = local_14;
      return;
    }
    iVar1 = in_ECX[0xa7] * 0x20 + DAT_00f94300 + 0x16f8;
    if (((*(int *)(iVar1 + 0xc) != 0) && (*(int *)(iVar1 + 8) != 0)) && (iVar1 != 0)) {
      FUN_005d7240(*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 0xc),
                   *(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14));
      (**(code **)(*in_ECX + 200))();
      if (in_ECX[0xa8] != 0) {
        FUN_00408610();
      }
    }
  }
  ExceptionList = local_14;
  return;
}

