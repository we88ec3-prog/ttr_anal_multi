
void FUN_0053bb20(void)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EDI;
  undefined4 uVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 0x5ed8) != 0) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    iVar1 = FUN_00539aa0(DAT_00f93930);
    if ((iVar1 != 0) && (*(char *)(iVar1 + 6) != '\0')) {
      uVar2 = unaff_EDI;
      FUN_00425330();
      iVar1 = FUN_004f6dc0(uVar2);
      FUN_00414680();
      if (iVar1 != -1) {
        FUN_004a3ee0(0);
        ExceptionList = local_14;
        return;
      }
      FUN_004a3f20(unaff_EDI);
    }
  }
  ExceptionList = local_14;
  return;
}

