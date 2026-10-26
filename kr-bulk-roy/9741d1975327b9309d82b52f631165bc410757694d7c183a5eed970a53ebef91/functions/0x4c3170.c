
void FUN_004c3170(void)

{
  DWORD DVar1;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091769e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fbacd0 & 1) == 0) {
    DAT_00fbacd0 = DAT_00fbacd0 | 1;
    local_8 = 0;
    DAT_00fbacd4 = (int *)0x0;
    DAT_00fbacd4 = (int *)FUN_006d6300(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd670);
  }
  local_8 = 0xffffffff;
  if (DAT_00fbacd4 != (int *)0x0) {
    (**(code **)(*DAT_00fbacd4 + 0x14))(1);
  }
  *(undefined4 *)(unaff_EDI + 0xbd54) = 1;
  DVar1 = timeGetTime();
  *(DWORD *)(unaff_EDI + 0xbd58) = DVar1;
  FUN_0058aad0(0xf4241);
  ExceptionList = local_10;
  return;
}

