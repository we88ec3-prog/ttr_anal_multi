
undefined4 FUN_004b9260(int param_1)

{
  int iVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(char *)(param_1 + 2) == 1) {
    iVar1 = FUN_00891268(0xbd54,DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    if (iVar1 != 0) {
      FUN_004c4ac0();
    }
    FUN_004b7d50();
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    if (DAT_00f9392c != *(char *)(param_1 + 2)) {
      DAT_00f9392c = (int)*(char *)(param_1 + 2);
    }
    ExceptionList = local_14;
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_006edc70("Invalid GameMode %d",(int)*(char *)(param_1 + 2));
}

