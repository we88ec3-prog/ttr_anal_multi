
/* WARNING: Removing unreachable block (ram,0x0079e726) */
/* WARNING: Removing unreachable block (ram,0x0079e732) */
/* WARNING: Removing unreachable block (ram,0x0079e746) */

void FUN_0079e5a0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint local_28;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009392f8;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  *(undefined1 *)(param_1 + 200) = 1;
  WaitForSingleObject(*(HANDLE *)(param_1 + 0xcc),0xffffffff);
  piVar1 = (int *)(param_1 + 0xb0);
  if (*(int *)(param_1 + 0xb0) == *(int *)(param_1 + 0xb4)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x98));
    uVar6 = 0;
    local_c = 0;
    if (*(int *)(param_1 + 0x8c) - *(int *)(param_1 + 0x88) >> 3 != 0) {
      do {
        FUN_007a0f60();
        uVar6 = uVar6 + 1;
      } while (uVar6 < (uint)(*(int *)(param_1 + 0x8c) - *(int *)(param_1 + 0x88) >> 3));
    }
    if (*(int *)(param_1 + 0x88) != *(int *)(param_1 + 0x8c)) {
      uVar4 = FUN_007a3720(*(int *)(param_1 + 0x8c));
      FUN_007a37a0();
      *(undefined4 *)(param_1 + 0x8c) = uVar4;
    }
    local_c = 0xffffffff;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x98));
  }
  local_28 = 0;
  if (*(int *)(param_1 + 0xb4) - *piVar1 >> 3 != 0) {
    do {
      iVar2 = *(int *)(*piVar1 + local_28 * 8 + 4);
      if (iVar2 != 0) {
        iVar3 = *(int *)(iVar2 + 4);
        while (iVar3 != 0) {
          LOCK();
          iVar5 = *(int *)(iVar2 + 4);
          if (iVar3 == iVar5) {
            *(int *)(iVar2 + 4) = iVar3 + 1;
            iVar5 = iVar3;
          }
          UNLOCK();
          if (iVar5 == iVar3) break;
          iVar3 = *(int *)(iVar2 + 4);
        }
      }
      FUN_007a9a70(*(undefined4 *)(*(int *)(*(int *)(local_28 * 8 + *piVar1) + 8) + 0x68));
      local_28 = local_28 + 1;
    } while (local_28 < (uint)(*(int *)(param_1 + 0xb4) - *piVar1 >> 3));
  }
  *(undefined1 *)(param_1 + 200) = 1;
  WaitForSingleObject(*(HANDLE *)(param_1 + 0xcc),0xffffffff);
  ExceptionList = local_14;
  return;
}

