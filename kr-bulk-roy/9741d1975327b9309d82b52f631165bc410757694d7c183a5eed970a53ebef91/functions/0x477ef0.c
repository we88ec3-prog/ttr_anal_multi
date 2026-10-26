
void FUN_00477ef0(int param_1,int param_2,int param_3)

{
  int in_ECX;
  int iVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((param_1 == 1) && (DAT_00f94300 + 0x16f8 != 0)) {
    if (99 < param_2 - 1U) {
      FUN_006edb60(&DAT_00c0ddc0);
      ExceptionList = local_14;
      return;
    }
    iVar1 = param_2 * 0x20 + DAT_00f94300 + 0x16f8;
    if ((((*(int *)(iVar1 + 0xc) != 0) && (*(int *)(iVar1 + 8) != 0)) && (iVar1 != 0)) &&
       ((*(float *)(*(int *)(in_ECX + 0x128) + 0xd0) < 1.0 &&
        (*(int *)(*(int *)(in_ECX + 0xf4 + param_3 * 4) + 0x250) < 1)))) {
      FUN_004451b0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10),
                   *(undefined4 *)(iVar1 + 0x14),1);
      iVar1 = FUN_00891268(0x1c);
      if (iVar1 != 0) {
        FUN_00753e00(0xf4368,param_2);
      }
      FUN_004072a0();
    }
  }
  ExceptionList = local_14;
  return;
}

