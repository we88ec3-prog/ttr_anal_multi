
undefined4 FUN_0080be60(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  iVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_009073f3;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  lpCriticalSection = (LPCRITICAL_SECTION)(unaff_EDI + 0x8c);
  EnterCriticalSection(lpCriticalSection);
  local_8 = 0;
  if ((iVar1 == 0) || (0xff < *(uint *)(unaff_EDI + 0x60))) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_10;
    return 0;
  }
  param_1 = FUN_00891268(0x28,uVar2);
  local_8._0_1_ = 1;
  if (param_1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0080cb50();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  iVar1 = *(int *)(unaff_EDI + 0x5c);
  param_1 = uVar3;
  iVar4 = FUN_0074d700(iVar1,*(undefined4 *)(iVar1 + 4),&param_1);
  if (*(int *)(unaff_EDI + 0x60) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(unaff_EDI + 0x60) = *(int *)(unaff_EDI + 0x60) + 1;
  *(int *)(iVar1 + 4) = iVar4;
  **(int **)(iVar4 + 4) = iVar4;
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_10;
  return uVar3;
}

