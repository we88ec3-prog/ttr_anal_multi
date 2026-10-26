
void FUN_005f9d60(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  int unaff_EDI;
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
  iVar1 = unaff_EDI + -0x50 + unaff_ESI * 0x50;
  if (iVar1 - 1U < 0x1e0) {
    iVar2 = DAT_00f94300 + 0x23a0 + iVar1 * 0x18;
    if (((*(int *)(DAT_00f94300 + 0x23ac + iVar1 * 0x18) != 0) && (*(int *)(iVar2 + 8) != 0)) &&
       (iVar2 != 0)) {
      if (1 < *(int *)(iVar2 + 8)) {
        FUN_005f5d20(param_1,0xf4371,*(undefined4 *)(iVar2 + 8),*(undefined4 *)(iVar2 + 8),unaff_ESI
                     ,unaff_EDI,param_2,param_3);
        ExceptionList = local_14;
        return;
      }
      FUN_005fa0f0(unaff_ESI,unaff_EDI,1);
    }
    ExceptionList = local_14;
    return;
  }
  FUN_006edb60(&DAT_00c0ddc0);
  ExceptionList = local_14;
  return;
}

