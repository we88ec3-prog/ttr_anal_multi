
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b9500(int param_1)

{
  int iVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094911a;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(char *)(param_1 + 2) == '\x05') {
    iVar1 = FUN_00891268(0xbd64,DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    if (iVar1 != 0) {
      FUN_004be3c0();
    }
    FUN_004b7d50();
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    if (DAT_00f9392c != *(byte *)(param_1 + 2)) {
      DAT_00f9392c = (uint)*(byte *)(param_1 + 2);
    }
    if ((DAT_00fc0f60 & 1) == 0) {
      DAT_00fc0f60 = DAT_00fc0f60 | 1;
      local_c = 1;
      FUN_0079cf40();
      _atexit((_func_4879 *)&LAB_00bcdb80);
      local_c = 0xffffffff;
    }
    FUN_0079d9c0(&DAT_00fc0e90,2);
    if ((DAT_00fd94d8 & 1) == 0) {
      DAT_00fd94d8 = DAT_00fd94d8 | 1;
      local_c = 2;
      FUN_007b5430();
      _atexit((_func_4879 *)&LAB_00bce660);
    }
    _DAT_00fd94b0 = 2;
    ExceptionList = local_14;
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_006edc70("Invalid GameMode %d",*(char *)(param_1 + 2));
}

