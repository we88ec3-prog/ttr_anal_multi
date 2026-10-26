
void FUN_006c5890(void)

{
  int iVar1;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00946cfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX != (int *)0x0) {
    iVar1 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar1 == 0x105bd) goto LAB_006c58e4;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_006c58e4:
  if (in_ECX[5] == 0x6a7) {
    if (((int *)in_ECX[6] != (int *)0x0) &&
       (iVar1 = (**(code **)(*(int *)in_ECX[6] + 4))(), iVar1 != 0x105b9)) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    }
    if ((DAT_00fc1cbc & 1) == 0) {
      DAT_00fc1cbc = DAT_00fc1cbc | 1;
      local_8 = 0;
      FUN_004fdac0();
      _atexit(FUN_00bce150);
      local_8 = 0xffffffff;
    }
    FUN_004fdc50(&DAT_00fc1cc0);
  }
  ExceptionList = local_10;
  return;
}

