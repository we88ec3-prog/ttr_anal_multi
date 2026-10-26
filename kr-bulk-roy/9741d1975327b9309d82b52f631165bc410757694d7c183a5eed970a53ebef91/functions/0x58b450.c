
void FUN_0058b450(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009169be;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0;
    FUN_0074d990(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  piVar1 = DAT_00f95bd4;
  local_8 = 0xffffffff;
  if (DAT_00f95bd4 != (int *)0x0) {
    iVar2 = (**(code **)(*DAT_00f95bd4 + 4))();
    if (iVar2 != 55000) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      ExceptionList = local_10;
      return;
    }
    FUN_005968f0(piVar1,param_1);
  }
  ExceptionList = local_10;
  return;
}

