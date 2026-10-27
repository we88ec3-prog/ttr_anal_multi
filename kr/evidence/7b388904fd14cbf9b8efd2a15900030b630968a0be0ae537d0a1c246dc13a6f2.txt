
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a89c0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a47e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  DAT_00fba7a0 = 0;
  FUN_00851420(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if ((DAT_00fb7354 & 1) == 0) {
    DAT_00fb7354 = DAT_00fb7354 | 1;
    local_8 = 0;
    FUN_005533d0();
    _atexit((_func_4879 *)&LAB_00bcd100);
    local_8 = 0xffffffff;
  }
  _DAT_00fb73b4 = 1;
  FUN_006f4a50("Event/TutorialMain.lua");
  FUN_006f4dd0("Synopsis_EntryPoint",0,0);
  ExceptionList = local_10;
  return;
}

