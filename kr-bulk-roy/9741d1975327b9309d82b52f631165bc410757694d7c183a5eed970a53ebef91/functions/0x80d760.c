
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0080d760(void)

{
  int iVar1;
  int unaff_EDI;
  undefined4 local_2c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918534;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(unaff_EDI + 0x3c) == 0) {
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8 = 0;
      FUN_0080a3a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bccdd0);
    }
    local_8 = 0xffffffff;
    iVar1 = FUN_0080bde0();
    *(int *)(unaff_EDI + 0x3c) = iVar1;
    if (iVar1 == 0) {
      ExceptionList = local_10;
      return;
    }
  }
  if ((DAT_00fe33c4 & 1) == 0) {
    DAT_00fe33c4 = DAT_00fe33c4 | 1;
    local_8 = 1;
    FUN_0080e030();
    _DAT_00fe33f8 = 0;
    _atexit((_func_4879 *)&LAB_00bd0bd0);
  }
  local_2c = 1;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fe33c8);
  local_8 = 2;
  FUN_0080cdb0(&local_2c);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fe33c8);
  ExceptionList = local_10;
  return;
}

