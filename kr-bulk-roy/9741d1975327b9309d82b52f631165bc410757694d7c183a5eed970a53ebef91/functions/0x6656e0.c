
void FUN_006656e0(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int unaff_EDI;
  undefined4 local_38;
  int local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092cd36;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004adcd0(local_14);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_38 = 0x15d;
  FUN_005740f0(&local_38);
  if (local_34 != DAT_00fe5ac8) {
    uVar2 = FUN_00420070();
    local_8 = 1;
    FUN_00757800(uVar2);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    local_30 = local_30 & 0xffff0000;
    local_1c = 7;
    local_20 = 0;
    (**(code **)(**(int **)(unaff_EDI + 0x104) + 200))();
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

