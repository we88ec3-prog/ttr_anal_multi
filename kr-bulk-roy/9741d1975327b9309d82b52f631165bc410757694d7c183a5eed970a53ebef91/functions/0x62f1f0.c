
void FUN_0062f1f0(void)

{
  code *pcVar1;
  int iVar2;
  int unaff_EDI;
  undefined4 uVar3;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092d26e;
  local_10 = ExceptionList;
  iVar2 = *(int *)(unaff_EDI + 0xf4);
  if (iVar2 == 0) {
    ExceptionList = &local_10;
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8 = 0xffffffff;
    local_14 = 0x284;
    FUN_005740f0(&local_14);
    if (local_18 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  else if (iVar2 == 1) {
    local_18 = 0x285;
    ExceptionList = &local_10;
    iVar2 = FUN_00585620();
    FUN_005740f0(&local_18);
    if (local_14 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  else {
    if (iVar2 != 2) {
      return;
    }
    uVar3 = 0x286;
    ExceptionList = &local_10;
    FUN_00585620(0x286,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    FUN_00585330(uVar3);
  }
  FUN_00757710();
  ExceptionList = local_10;
  return;
}

