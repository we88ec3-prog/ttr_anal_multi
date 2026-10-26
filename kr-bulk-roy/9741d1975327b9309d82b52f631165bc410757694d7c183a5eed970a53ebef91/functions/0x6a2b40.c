
bool FUN_006a2b40(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int in_EDX;
  int local_24;
  int local_20;
  undefined4 local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((in_EDX == 1) && (iVar2 = DAT_00f94300 + 0x16f8, iVar2 != 0)) {
    if (99 < in_ECX - 1U) {
      FUN_006edb60(&DAT_00c0ddc0);
      ExceptionList = local_14;
      return false;
    }
    iVar1 = in_ECX * 0x20 + iVar2;
    if (((*(int *)(in_ECX * 0x20 + 0xc + iVar2) != 0) && (*(int *)(iVar1 + 8) != 0)) && (iVar1 != 0)
       ) {
      local_20 = *(int *)(iVar1 + 0x10);
      local_1c = *(undefined4 *)(iVar1 + 0x14);
      iVar2 = FUN_00409560();
      FUN_004dd400(iVar2,&local_24,&local_20);
      if (((local_24 == *(int *)(iVar2 + 4)) || (*(int *)(local_24 + 0x18) == 0)) ||
         (*(char *)(*(int *)(local_24 + 0x18) + 0x15) == '\0')) {
        iVar2 = *(int *)(iVar1 + 0xc);
        FUN_00404c10();
        local_24 = iVar2;
        FUN_008438c0(&local_24);
        iVar2 = FUN_0051bfc0();
        ExceptionList = local_14;
        return iVar2 == 0;
      }
    }
  }
  ExceptionList = local_14;
  return false;
}

