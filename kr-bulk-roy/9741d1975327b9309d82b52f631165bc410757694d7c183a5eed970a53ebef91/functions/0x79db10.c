
/* WARNING: Removing unreachable block (ram,0x0079dcb2) */

void FUN_0079db10(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined4 uVar5;
  DWORD DVar6;
  int iVar7;
  int iVar8;
  DWORD DVar9;
  int in_ECX;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918f40;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = (int *)(in_ECX + 0xb0);
  if (*(int *)(in_ECX + 0xb0) == *(int *)(in_ECX + 0xb4)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x98));
    local_8 = 0;
    FUN_007a0e20();
    if (*(int *)(in_ECX + 0x88) != *(int *)(in_ECX + 0x8c)) {
      uVar5 = FUN_007a3720(*(int *)(in_ECX + 0x8c));
      FUN_007a37a0();
      *(undefined4 *)(in_ECX + 0x8c) = uVar5;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x98));
  }
  local_8 = 1;
  DVar6 = timeGetTime();
  iVar7 = *piVar1;
  bVar4 = false;
  local_18 = 0;
  if (*(int *)(in_ECX + 0xb4) - iVar7 >> 3 != 0) {
    do {
      if (bVar4) {
        FUN_007a0f60();
      }
      else {
        iVar2 = local_18 * 8;
        iVar3 = *(int *)(iVar7 + 4 + iVar2);
        uVar5 = *(undefined4 *)(iVar7 + iVar2);
        if (iVar3 != 0) {
          iVar7 = *(int *)(iVar3 + 4);
          while (iVar7 != 0) {
            LOCK();
            iVar8 = *(int *)(iVar3 + 4);
            if (iVar7 == iVar8) {
              *(int *)(iVar3 + 4) = iVar7 + 1;
              iVar8 = iVar7;
            }
            UNLOCK();
            if (iVar8 == iVar7) {
              FUN_007a31c0(uVar5,iVar3);
              break;
            }
            iVar7 = *(int *)(iVar3 + 4);
          }
        }
        FUN_007a90f0(*(undefined4 *)(*(int *)(*(int *)(*piVar1 + iVar2) + 8) + 0x68));
        DVar9 = timeGetTime();
        if (3 < DVar9 - DVar6) {
          bVar4 = true;
        }
      }
      iVar7 = *piVar1;
      local_18 = local_18 + 1;
    } while (local_18 < (uint)(*(int *)(in_ECX + 0xb4) - iVar7 >> 3));
  }
  FUN_007a0e20();
  ExceptionList = local_10;
  return;
}

