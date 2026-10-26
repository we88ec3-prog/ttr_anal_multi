
void FUN_0068f900(void)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009169be;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = (int *)FUN_00891268(0x14,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar1 = (int)FoxUI::FXUIEvent::vftable;
    piVar1[1] = -1;
    piVar1[2] = -1;
    piVar1[3] = 0;
    piVar1[4] = 0xf42e3;
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

