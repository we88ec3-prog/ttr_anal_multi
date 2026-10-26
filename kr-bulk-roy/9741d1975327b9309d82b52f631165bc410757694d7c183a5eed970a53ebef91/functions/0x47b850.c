
/* WARNING: Removing unreachable block (ram,0x0047b9b0) */
/* WARNING: Removing unreachable block (ram,0x0047b9b3) */
/* WARNING: Removing unreachable block (ram,0x0047b9ba) */
/* WARNING: Removing unreachable block (ram,0x0047b9ea) */
/* WARNING: Removing unreachable block (ram,0x0047b9ef) */
/* WARNING: Removing unreachable block (ram,0x0047b9fb) */
/* WARNING: Removing unreachable block (ram,0x0047ba02) */
/* WARNING: Removing unreachable block (ram,0x0047b9c0) */
/* WARNING: Removing unreachable block (ram,0x0047b9cc) */
/* WARNING: Removing unreachable block (ram,0x0047b9d8) */
/* WARNING: Removing unreachable block (ram,0x0047b9e4) */
/* WARNING: Removing unreachable block (ram,0x0047ba06) */
/* WARNING: Removing unreachable block (ram,0x0047ba12) */
/* WARNING: Removing unreachable block (ram,0x0047bb0b) */
/* WARNING: Removing unreachable block (ram,0x0047ba2b) */
/* WARNING: Removing unreachable block (ram,0x0047ba33) */
/* WARNING: Removing unreachable block (ram,0x0047ba35) */
/* WARNING: Removing unreachable block (ram,0x0047ba3c) */
/* WARNING: Removing unreachable block (ram,0x0047bb28) */
/* WARNING: Removing unreachable block (ram,0x0047ba48) */
/* WARNING: Removing unreachable block (ram,0x0047ba4e) */
/* WARNING: Removing unreachable block (ram,0x0047badb) */
/* WARNING: Removing unreachable block (ram,0x0047bae7) */
/* WARNING: Removing unreachable block (ram,0x0047bafb) */

void FUN_0047b850(int param_1)

{
  undefined4 *puVar1;
  HANDLE hHandle;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093a4e2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc0e40 & 1) == 0) {
    DAT_00fc0e40 = DAT_00fc0e40 | 1;
    local_8 = 0;
    FUN_00540770();
    _atexit((_func_4879 *)&LAB_00bcdb60);
  }
  local_8 = 1;
  FUN_004a8680();
  FUN_004a8680();
  FUN_004a8680();
  FUN_004a8680();
  FUN_004a8680();
  FUN_004a8680();
  FUN_004a8680();
  FUN_004a8680();
  FUN_004a8680();
  FUN_004a8680();
  FUN_004a8680();
  *(undefined1 *)(param_1 + 0x26c) = 1;
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
  if ((DAT_00fc0f60 & 1) == 0) {
    DAT_00fc0f60 = DAT_00fc0f60 | 1;
    local_8._0_1_ = 4;
    FUN_0079cf40();
    _atexit((_func_4879 *)&LAB_00bcdb80);
  }
  local_8._0_1_ = 2;
  hHandle = (HANDLE)FUN_0079dce0();
  WaitForSingleObject(hHandle,0xffffffff);
  CloseHandle(hHandle);
  if ((DAT_00fc0f80 & 1) == 0) {
    DAT_00fc0f80 = DAT_00fc0f80 | 1;
    local_8._0_1_ = 5;
    FUN_0047aeb0();
    _atexit((_func_4879 *)&LAB_00bcdb70);
    local_8._0_1_ = 2;
  }
  FUN_004a89c0();
  ExceptionList = local_10;
  return;
}

