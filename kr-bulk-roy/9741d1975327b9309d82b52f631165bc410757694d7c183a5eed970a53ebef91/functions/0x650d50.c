
void FUN_00650d50(void)

{
  int iVar1;
  int *unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00941e6e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar1 == 0x105bd) goto LAB_00650da0;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_00650da0:
  if (unaff_ESI[5] == 0x6a7) {
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      local_8 = 0;
      FUN_00539c20();
      _atexit((_func_4879 *)&LAB_00bccfb0);
      local_8 = 0xffffffff;
    }
    if (DAT_00fb7258 != 0) {
      FUN_0053ba20();
    }
  }
  ExceptionList = local_10;
  return;
}

