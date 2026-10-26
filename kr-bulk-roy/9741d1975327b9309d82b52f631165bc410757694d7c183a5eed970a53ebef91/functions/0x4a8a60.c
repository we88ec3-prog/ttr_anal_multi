
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a8a60(void)

{
  undefined2 local_18;
  undefined4 local_16;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a44c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  DAT_00fba7a0 = 0;
  FUN_00823850(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_00851420();
  if ((DAT_00fb7354 & 1) == 0) {
    DAT_00fb7354 = DAT_00fb7354 | 1;
    local_8 = 0;
    FUN_005533d0();
    _atexit((_func_4879 *)&LAB_00bcd100);
    local_8 = 0xffffffff;
  }
  _DAT_00fb73b4 = 1;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  if (DAT_00faadec == 0xf) {
    FUN_0058a9a0();
  }
  else {
    _DAT_00faadf0 = 0xf;
  }
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_18 = 0xc;
  local_16 = 1;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_18,6);
  }
  FUN_006f4a50("Event/TutorialMain.lua");
  FUN_006f4dd0("Tutorial_EntryPoint",0,0);
  ExceptionList = local_10;
  return;
}

