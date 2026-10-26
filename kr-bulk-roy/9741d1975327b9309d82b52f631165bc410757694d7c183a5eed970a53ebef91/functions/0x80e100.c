
void FUN_0080e100(void)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  HANDLE pvVar4;
  int iVar5;
  LPCRITICAL_SECTION unaff_EDI;
  undefined4 local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (unaff_EDI[2].DebugInfo == (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
    while (EnterCriticalSection(unaff_EDI), unaff_EDI[1].LockSemaphore != (HANDLE)0x0) {
      piVar2 = (int *)FUN_00542210();
      if ((int *)*piVar2 == (int *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)*piVar2;
      }
      uVar3 = piVar2[2];
      if (*(uint *)(iVar5 + 8) <= uVar3) {
        uVar3 = uVar3 - *(uint *)(iVar5 + 8);
      }
      puVar1 = *(undefined4 **)(*(int *)(iVar5 + 4) + uVar3 * 4);
      local_20 = *puVar1;
      local_1c = (undefined4 *)puVar1[1];
      local_18 = puVar1[2];
      local_14 = puVar1[3];
      local_10 = puVar1[4];
      local_c = puVar1[5];
      if (unaff_EDI[1].LockSemaphore != (HANDLE)0x0) {
        unaff_EDI[1].OwningThread = (HANDLE)((int)unaff_EDI[1].OwningThread + 1);
        if ((HANDLE)unaff_EDI[1].RecursionCount <= unaff_EDI[1].OwningThread) {
          unaff_EDI[1].OwningThread = (HANDLE)0x0;
        }
        pvVar4 = (HANDLE)((int)unaff_EDI[1].LockSemaphore + -1);
        unaff_EDI[1].LockSemaphore = pvVar4;
        if (pvVar4 == (HANDLE)0x0) {
          unaff_EDI[1].OwningThread = (HANDLE)0x0;
        }
      }
      LeaveCriticalSection(unaff_EDI);
      if (local_1c != (undefined4 *)0x0) {
        (**(code **)*local_1c)(&local_20);
      }
      Sleep(1);
      if (unaff_EDI[2].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
    LeaveCriticalSection(unaff_EDI);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

