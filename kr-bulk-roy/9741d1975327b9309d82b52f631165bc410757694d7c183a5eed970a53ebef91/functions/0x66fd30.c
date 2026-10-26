
void FUN_0066fd30(void)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009472de;
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
      if ((DAT_00fb1378 & 1) == 0) {
        DAT_00fb1378 = DAT_00fb1378 | 1;
        local_8 = 0;
        FUN_00539c20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
        _atexit((_func_4879 *)&LAB_00bccfb0);
      }
      local_8 = 0xffffffff;
      FUN_0053bc00(iVar1,0);
    }
  }
  ExceptionList = local_10;
  return;
}

