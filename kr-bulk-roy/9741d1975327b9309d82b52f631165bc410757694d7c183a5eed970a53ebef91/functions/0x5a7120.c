
/* WARNING: Removing unreachable block (ram,0x005a740f) */

void FUN_005a7120(void)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00943bd8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00596010();
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_005a8530();
  FUN_005a9f40();
  FUN_005a8610();
  FUN_005a9f40();
  FUN_005a86f0();
  FUN_005a9f40();
  FUN_005a87d0();
  FUN_005a9f40();
  FUN_005a88b0();
  FUN_005a9f40();
  FUN_005a8990();
  FUN_005a9f40();
  FUN_005a8a70();
  FUN_005a9f40();
  FUN_005a8b50();
  FUN_005a9f40();
  FUN_005a8c30();
  FUN_005a9f40();
  FUN_005a8d10();
  FUN_005a9f40();
  FUN_005a8df0();
  FUN_005a9f40();
  FUN_005a8ed0();
  FUN_005a9f40();
  FUN_005a8fb0();
  FUN_005a9f40();
  FUN_0040b670();
  (**(code **)(**(int **)(in_ECX + 0x134) + 0xd0))();
  if ((DAT_00fbacd0 & 1) == 0) {
    DAT_00fbacd0 = DAT_00fbacd0 | 1;
    local_8._0_1_ = 2;
    DAT_00fbacd4 = 0;
    DAT_00fbacd4 = FUN_006d6300();
    _atexit((_func_4879 *)&LAB_00bcd670);
    local_8._0_1_ = 1;
  }
  if ((DAT_00fbacd4 == 0) || (*(int *)(DAT_00fbacd4 + 0x28) != 3)) {
    if ((DAT_00fbacd0 & 1) == 0) {
      DAT_00fbacd0 = DAT_00fbacd0 | 1;
      local_8._0_1_ = 5;
      DAT_00fbacd4 = 0;
      DAT_00fbacd4 = FUN_006d6300();
      _atexit((_func_4879 *)&LAB_00bcd670);
      local_8._0_1_ = 1;
    }
    if ((DAT_00fbacd4 != 0) && (*(int *)(DAT_00fbacd4 + 0x28) == 1)) {
      (**(code **)(**(int **)(in_ECX + 0x138) + 0xd0))();
    }
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x148) + 0xd0))();
    if ((DAT_00fc0d44 & 1) == 0) {
      DAT_00fc0d44 = DAT_00fc0d44 | 1;
      local_8._0_1_ = 3;
      FUN_00462200();
      _atexit(FUN_00bcd800);
      local_8._0_1_ = 1;
    }
    FUN_00468f50(*(undefined4 *)(in_ECX + 0x148));
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8._0_1_ = 4;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_8._0_1_ = 1;
    }
    if (DAT_00fb9326 != 0) {
      FUN_00461dd0();
      iVar1 = FUN_00401140();
      if (iVar1 == 0) {
        (**(code **)(**(int **)(in_ECX + 0x14c) + 0xd4))();
      }
      else {
        (**(code **)(**(int **)(in_ECX + 0x14c) + 0xd0))();
        FUN_00462010();
      }
    }
  }
  ExceptionList = local_10;
  return;
}

