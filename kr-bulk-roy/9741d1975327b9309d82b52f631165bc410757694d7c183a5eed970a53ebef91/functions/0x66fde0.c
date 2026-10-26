
void FUN_0066fde0(void)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093b7ac;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xcc);
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 0xdc);
    if (iVar1 == 0) {
      iVar1 = -1;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x20);
    }
    if ((iVar1 != -1) &&
       (iVar1 = *(int *)(*(int *)(in_ECX + 0x114 + iVar1 * 4) + 0x248), iVar1 != 0)) {
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_8 = 0;
        FUN_004f3d80(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
        _atexit((_func_4879 *)&LAB_00bcd1e0);
      }
      if ((DAT_00fbad10 & 1) == 0) {
        DAT_00fbad10 = DAT_00fbad10 | 1;
        local_8 = 1;
        FUN_004e8010();
        _atexit((_func_4879 *)&LAB_00bcd6b0);
      }
      local_8 = 0xffffffff;
      FUN_004f6a30(iVar1);
      FUN_004ecb20(&DAT_00fbad18);
    }
  }
  ExceptionList = local_10;
  return;
}

