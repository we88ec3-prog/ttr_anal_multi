
void FUN_0059db20(void)

{
  int iVar1;
  int *in_ECX;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009474ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX != (int *)0x0) {
    iVar1 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar1 == 0x105c4) goto LAB_0059db6d;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_0059db6d:
  if ((char)in_ECX[5] != '\0') {
    if ((DAT_00faaf34 & 1) == 0) {
      DAT_00faaf34 = DAT_00faaf34 | 1;
      local_8 = 0;
      FUN_004073c0();
      _atexit((_func_4879 *)&LAB_00bcccd0);
    }
    DAT_00faaf45 = (char)in_ECX[5];
    ExceptionList = local_10;
    return;
  }
  FUN_00596e00(unaff_EDI,*(undefined4 *)(unaff_EDI + 0x208));
  ExceptionList = local_10;
  return;
}

