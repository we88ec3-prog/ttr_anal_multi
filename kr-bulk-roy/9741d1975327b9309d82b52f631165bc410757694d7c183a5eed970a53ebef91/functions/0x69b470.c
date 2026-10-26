
void FUN_0069b470(void)

{
  int iVar1;
  int *in_ECX;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00926a3e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX != (int *)0x0) {
    iVar1 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar1 == 0x105b9) goto LAB_0069b4c0;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_0069b4c0:
  if ((DAT_00fb1350 & 1) == 0) {
    DAT_00fb1350 = DAT_00fb1350 | 1;
    local_8 = 0;
    FUN_00511ca0();
    _atexit((_func_4879 *)&LAB_00bccf40);
    local_8 = 0xffffffff;
  }
  local_14 = in_ECX[5];
  FUN_008438c0(&local_14);
  if ((local_18 != DAT_00fb136c) && (*(int *)(local_18 + 0x10) != 0)) {
    FUN_0069b060();
  }
  ExceptionList = local_10;
  return;
}

