
void FUN_004e74d0(void)

{
  undefined4 uVar1;
  uint uVar2;
  BOOL BVar3;
  undefined4 unaff_EDI;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffe0;
  ExceptionList = &local_14;
  BVar3 = PathIsDirectoryW(L"./Emblem");
  if (BVar3 != 0) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(uVar2);
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    uVar1 = DAT_00f94208;
    FUN_004e7590(unaff_EDI,DAT_00f94208);
    FUN_004e77a0(uVar1);
    ExceptionList = local_14;
    return;
  }
  CreateDirectoryW(L"./Emblem",(LPSECURITY_ATTRIBUTES)0x0);
  ExceptionList = local_14;
  return;
}

