
undefined4 FUN_007b6af0(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  LPCRITICAL_SECTION unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009119a8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  EnterCriticalSection(unaff_EDI);
  local_8 = 0;
  if (unaff_EDI[1].LockSemaphore == (HANDLE)0x0) {
    LeaveCriticalSection(unaff_EDI);
    ExceptionList = local_10;
    return 0;
  }
  piVar2 = (int *)FUN_00542210(uVar1);
  iVar3 = 0;
  if ((int *)*piVar2 != (int *)0x0) {
    iVar3 = *(int *)*piVar2;
  }
  uVar1 = piVar2[2];
  if (*(uint *)(iVar3 + 8) <= uVar1) {
    uVar1 = uVar1 - *(uint *)(iVar3 + 8);
  }
  FUN_00403040(*(undefined4 *)(*(int *)(iVar3 + 4) + uVar1 * 4),0,0xffffffff);
  FUN_006df1f0();
  LeaveCriticalSection(unaff_EDI);
  ExceptionList = local_10;
  return 1;
}

