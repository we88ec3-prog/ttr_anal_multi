
undefined4 FUN_004b9d30(int param_1)

{
  undefined4 *puVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(char *)(param_1 + 2) == '\x1b') {
    puVar1 = (undefined4 *)FUN_00891268(0xbd58,DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_004add50();
      *puVar1 = Scene::CDailyDungeonRoom::vftable;
      puVar1[0x2f55] = 0;
      DAT_00d6a674 = 0x44414452;
      FUN_00424310();
    }
    FUN_004b7d50();
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    if (DAT_00f9392c != *(byte *)(param_1 + 2)) {
      DAT_00f9392c = (uint)*(byte *)(param_1 + 2);
    }
    ExceptionList = local_14;
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_006edc70("Invalid GameMode %d",*(char *)(param_1 + 2));
}

