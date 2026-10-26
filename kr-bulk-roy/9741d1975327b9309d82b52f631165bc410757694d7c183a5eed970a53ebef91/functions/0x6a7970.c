
void FUN_006a7970(void)

{
  int iVar1;
  int *unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b73e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar1 == 0x105bd) goto LAB_006a79c0;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_006a79c0:
  if (unaff_ESI[5] == 0x6a7) {
    if ((DAT_00fbad10 & 1) == 0) {
      DAT_00fbad10 = DAT_00fbad10 | 1;
      local_8 = 0;
      FUN_004e8010();
      _atexit((_func_4879 *)&LAB_00bcd6b0);
      local_8 = 0xffffffff;
    }
    if (DAT_00fc0bd8 != 0) {
      FUN_004ecac0();
    }
  }
  ExceptionList = local_10;
  return;
}

