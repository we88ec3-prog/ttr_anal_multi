
/* WARNING: Removing unreachable block (ram,0x004c1f59) */
/* WARNING: Removing unreachable block (ram,0x004c1f62) */
/* WARNING: Removing unreachable block (ram,0x004c2011) */
/* WARNING: Removing unreachable block (ram,0x004c201d) */
/* WARNING: Removing unreachable block (ram,0x004c2031) */

void FUN_004c1e10(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  HANDLE hHandle;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093a59c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  puVar2 = (undefined4 *)FUN_00891268();
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 0;
    *(undefined1 *)(puVar2 + 2) = 1;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
  }
  FUN_0047c0d0();
  local_c = 0;
  uRam00000008 = 1;
  uRam00000004 = 3;
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
  uVar1 = local_c >> 8;
  if ((DAT_00fc0f60 & 1) == 0) {
    DAT_00fc0f60 = DAT_00fc0f60 | 1;
    local_c._0_1_ = 2;
    FUN_0079cf40();
    _atexit((_func_4879 *)&LAB_00bcdb80);
    uVar1 = (uint)local_c._1_3_;
  }
  local_c = uVar1 << 8;
  hHandle = (HANDLE)FUN_0079dce0();
  WaitForSingleObject(hHandle,0xffffffff);
  CloseHandle(hHandle);
  uVar1 = DAT_00fc0f80 & 1;
  *(undefined4 *)(param_1 + 0xbd78) = 1;
  if (uVar1 == 0) {
    DAT_00fc0f80 = DAT_00fc0f80 | 1;
    local_c._0_1_ = 3;
    FUN_0047aeb0();
    _atexit((_func_4879 *)&LAB_00bcdb70);
    local_c = (uint)local_c._1_3_ << 8;
  }
  FUN_004a89c0();
  ExceptionList = local_14;
  return;
}

