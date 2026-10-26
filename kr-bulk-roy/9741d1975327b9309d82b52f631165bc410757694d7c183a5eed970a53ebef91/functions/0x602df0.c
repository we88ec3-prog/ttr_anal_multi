
void FUN_00602df0(int param_1,int param_2)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009169ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = (int *)FUN_00891268(0x1c,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[1] = -1;
    piVar1[2] = -1;
    piVar1[3] = 0;
    piVar1[4] = 0xf43b2;
    *piVar1 = (int)FoxUI::FXUIEventI2::vftable;
    piVar1[5] = param_1;
    piVar1[6] = param_2;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  if (DAT_00f95bd4 != (int *)0x0) {
    (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar1);
  }
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(1);
  }
  ExceptionList = local_10;
  return;
}

