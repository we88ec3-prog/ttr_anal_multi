
undefined4 FUN_0079e7c0(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915f38;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  lpCriticalSection = (LPCRITICAL_SECTION)(unaff_ESI + 0x70);
  EnterCriticalSection(lpCriticalSection);
  uVar3 = 0;
  local_8 = 0;
  if (*(int *)(unaff_ESI + 0x28) != *(int *)(unaff_ESI + 0x2c)) {
    if (*(int *)(unaff_ESI + 0x2c) - *(int *)(unaff_ESI + 0x28) >> 3 != 0) {
      do {
        FUN_007a1220(*(int *)(unaff_ESI + 0x28) + uVar3 * 8);
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uint)(*(int *)(unaff_ESI + 0x2c) - *(int *)(unaff_ESI + 0x28) >> 3));
    }
    if (*(int *)(unaff_ESI + 0x28) != *(int *)(unaff_ESI + 0x2c)) {
      uVar2 = FUN_007a3720(*(int *)(unaff_ESI + 0x2c),*(int *)(unaff_ESI + 0x28),param_1,uVar1);
      FUN_007a37a0(*(undefined4 *)(unaff_ESI + 0x2c),param_1);
      *(undefined4 *)(unaff_ESI + 0x2c) = uVar2;
    }
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_10;
    return 1;
  }
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_10;
  return 0;
}

