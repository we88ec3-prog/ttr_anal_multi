
/* WARNING: Removing unreachable block (ram,0x004c2128) */
/* WARNING: Removing unreachable block (ram,0x004c2133) */
/* WARNING: Removing unreachable block (ram,0x004c2193) */
/* WARNING: Removing unreachable block (ram,0x004c219f) */
/* WARNING: Removing unreachable block (ram,0x004c21b3) */

void FUN_004c2050(int param_1)

{
  undefined4 *puVar1;
  HANDLE hHandle;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009396cc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc0f80 & 1) == 0) {
    DAT_00fc0f80 = DAT_00fc0f80 | 1;
    local_8 = 0;
    FUN_0047aeb0();
    _atexit((_func_4879 *)&LAB_00bcdb70);
  }
  local_8 = 0xffffffff;
  FUN_004ad0a0(DAT_00fc0f84);
  FUN_004a9db0();
  *(undefined4 *)(param_1 + 0xbd78) = 0;
  puVar1 = (undefined4 *)FUN_00891268();
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    *(undefined1 *)(puVar1 + 2) = 1;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
  }
  FUN_0047c0d0();
  uRam00000008 = 1;
  uRam00000004 = 3;
  local_8._1_3_ = 0;
  if ((DAT_00fc0f60 & 1) == 0) {
    DAT_00fc0f60 = DAT_00fc0f60 | 1;
    local_8._1_3_ = 0;
    local_8._0_1_ = 3;
    FUN_0079cf40();
    _atexit((_func_4879 *)&LAB_00bcdb80);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  hHandle = (HANDLE)FUN_0079dce0();
  WaitForSingleObject(hHandle,0xffffffff);
  CloseHandle(hHandle);
  ExceptionList = local_10;
  return;
}

