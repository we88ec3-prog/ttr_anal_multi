
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a58c0(void)

{
  int iVar1;
  int in_ECX;
  int *in_EDX;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00936096;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((in_EDX != (int *)0x0) && (iVar1 = (**(code **)(*in_EDX + 4))(), iVar1 != 0x105bc)) {
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  local_30 = (uint)local_30._2_2_ << 0x10;
  local_1c = 7;
  local_20 = 0;
  FUN_004026e0();
  local_8 = 0;
  FUN_004026e0(&local_30,0,0xffffffff);
  FUN_00643300(*(undefined4 *)(in_ECX + 0x144));
  iVar1 = *(int *)(in_ECX + 0x144);
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  _DAT_00f95bec = *(undefined4 *)(iVar1 + 0x138);
  DAT_00f95be9 = 1;
  *(undefined1 *)(iVar1 + 0x144) = 1;
  if (7 < local_1c) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

