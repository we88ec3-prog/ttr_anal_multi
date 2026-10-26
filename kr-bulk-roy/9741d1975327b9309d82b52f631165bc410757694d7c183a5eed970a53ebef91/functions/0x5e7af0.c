
void FUN_005e7af0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  code *pcVar1;
  int in_ECX;
  int unaff_EDI;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092d23a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (unaff_EDI != 0) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8 = 0xffffffff;
    local_14 = 0x256;
    FUN_005740f0(&local_14);
    if (local_18 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (in_ECX != 0) {
      FUN_005e48e0(param_1,*(undefined4 *)(unaff_EDI + 0x1c),param_4);
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 1;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_18 = 599;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (param_2 != 0) {
      FUN_005e48e0(param_1,*(undefined4 *)(unaff_EDI + 0x34),param_5);
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 2;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_18 = 600;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (param_3 != 0) {
      FUN_005e48e0(param_1,*(undefined4 *)(unaff_EDI + 0x4c),param_6);
    }
  }
  ExceptionList = local_10;
  return;
}

