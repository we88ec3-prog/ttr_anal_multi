
void FUN_0045ab80(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
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
  if ((param_2 == 1) && (DAT_00f94300 + 0x16f8 != 0)) {
    if (99 < in_ECX - 1U) {
      FUN_006edb60(&DAT_00c0ddc0);
      ExceptionList = local_14;
      return;
    }
    iVar1 = DAT_00f94300 + 0x16f8 + in_ECX * 0x20;
    if (((*(int *)(iVar1 + 0xc) != 0) && (*(int *)(iVar1 + 8) != 0)) && (iVar1 != 0)) {
      if (1 < *(int *)(iVar1 + 8)) {
        FUN_0045a7b0(param_1,*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 8),1,in_ECX,
                     unaff_EDI);
        ExceptionList = local_14;
        return;
      }
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xf0) + unaff_EDI * 4) + 0x2a8) = 1;
      FUN_00459f20();
      piVar2 = (int *)FUN_00408810();
      (**(code **)(*piVar2 + 200))();
    }
  }
  ExceptionList = local_14;
  return;
}

