
/* WARNING: Removing unreachable block (ram,0x0047b796) */
/* WARNING: Removing unreachable block (ram,0x0047b7a1) */
/* WARNING: Removing unreachable block (ram,0x0047b806) */
/* WARNING: Removing unreachable block (ram,0x0047b812) */
/* WARNING: Removing unreachable block (ram,0x0047b826) */

void FUN_0047b6b0(int param_1)

{
  undefined4 *puVar1;
  HANDLE hHandle;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00938f5c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fc0f80 & 1) == 0) {
    DAT_00fc0f80 = DAT_00fc0f80 | 1;
    local_c = 0;
    FUN_0047aeb0();
    _atexit((_func_4879 *)&LAB_00bcdb70);
  }
  local_c = 0xffffffff;
  FUN_004ad0a0(DAT_00fc0f84);
  FUN_004a9db0();
  *(undefined1 *)(param_1 + 0x26c) = 0;
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
  local_c._1_3_ = 0;
  if ((DAT_00fc0f60 & 1) == 0) {
    DAT_00fc0f60 = DAT_00fc0f60 | 1;
    local_c._1_3_ = 0;
    local_c._0_1_ = 3;
    FUN_0079cf40();
    _atexit((_func_4879 *)&LAB_00bcdb80);
  }
  local_c = CONCAT31(local_c._1_3_,1);
  hHandle = (HANDLE)FUN_0079dce0();
  WaitForSingleObject(hHandle,0xffffffff);
  CloseHandle(hHandle);
  ExceptionList = local_14;
  return;
}

