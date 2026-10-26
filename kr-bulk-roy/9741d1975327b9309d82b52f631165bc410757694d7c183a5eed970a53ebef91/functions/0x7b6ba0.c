
undefined4 FUN_007b6ba0(LPCRITICAL_SECTION param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  HANDLE pvVar4;
  int iVar5;
  
  EnterCriticalSection(param_1);
  if (param_1[1].LockSemaphore == (HANDLE)0x0) {
    LeaveCriticalSection(param_1);
    return 0;
  }
  piVar2 = (int *)FUN_00542210();
  if ((int *)*piVar2 == (int *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)*piVar2;
  }
  uVar3 = (uint)piVar2[2] >> 1;
  if (*(uint *)(iVar5 + 8) <= uVar3) {
    uVar3 = uVar3 - *(uint *)(iVar5 + 8);
  }
  puVar1 = (undefined4 *)(*(int *)(*(int *)(iVar5 + 4) + uVar3 * 4) + (piVar2[2] & 1U) * 8);
  *param_2 = *puVar1;
  param_2[1] = puVar1[1];
  if (param_1[1].LockSemaphore != (HANDLE)0x0) {
    param_1[1].OwningThread = (HANDLE)((int)param_1[1].OwningThread + 1);
    if ((HANDLE)(param_1[1].RecursionCount * 2) <= param_1[1].OwningThread) {
      param_1[1].OwningThread = (HANDLE)0x0;
    }
    pvVar4 = (HANDLE)((int)param_1[1].LockSemaphore + -1);
    param_1[1].LockSemaphore = pvVar4;
    if (pvVar4 == (HANDLE)0x0) {
      param_1[1].OwningThread = (HANDLE)0x0;
    }
  }
  LeaveCriticalSection(param_1);
  return 1;
}

