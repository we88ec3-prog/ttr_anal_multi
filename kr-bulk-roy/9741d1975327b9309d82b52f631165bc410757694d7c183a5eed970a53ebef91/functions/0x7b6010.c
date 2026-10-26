
undefined4 FUN_007b6010(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint uVar1;
  int *piVar2;
  HANDLE pvVar3;
  int iVar4;
  int unaff_EDI;
  LPCRITICAL_SECTION local_20;
  int local_1c;
  HANDLE local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009351b8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pvVar3 = (HANDLE)0x0;
  local_14 = 0;
  iVar4 = 0;
  local_18 = (HANDLE)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba6d0);
  if (*(int *)(unaff_EDI + 8) != 0) {
    local_14 = 1;
    *(undefined4 *)(unaff_EDI + 0x98) = 1;
    piVar2 = (int *)**(int **)(unaff_EDI + 4);
    if (piVar2 != *(int **)(unaff_EDI + 4)) {
      iVar4 = piVar2[4];
      FUN_007b6890(unaff_EDI,&local_20,piVar2);
    }
    FUN_0082ef00(iVar4 + 4);
    if (local_20 != *(LPCRITICAL_SECTION *)(unaff_EDI + 0x14)) {
      pvVar3 = local_20->LockSemaphore;
      local_18 = pvVar3;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba6d0);
  if (iVar4 != 0) {
    if (pvVar3 == (HANDLE)0x0) {
      if (0xf < *(uint *)(iVar4 + 0x24)) {
        FUN_0089120c(*(undefined4 *)(iVar4 + 0x10),uVar1);
      }
      *(undefined4 *)(iVar4 + 0x24) = 0xf;
      *(undefined4 *)(iVar4 + 0x20) = 0;
      *(undefined1 *)(iVar4 + 0x10) = 0;
      FUN_0089120c(iVar4,uVar1);
    }
    else {
      pvVar3 = (HANDLE)FUN_007b5980(unaff_EDI);
      if (pvVar3 == (HANDLE)0x0) {
        piVar2 = (int *)(iVar4 + 0x10);
        if (0xf < *(uint *)(iVar4 + 0x24)) {
          piVar2 = (int *)*piVar2;
        }
        FUN_006edd00("Animation Load failed: %s",piVar2);
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba6d0);
        FUN_0082ef00(&local_18);
        if (local_20 != *(LPCRITICAL_SECTION *)(unaff_EDI + 0x24)) {
          FUN_007b6890(unaff_EDI + 0x20,&local_20,local_20);
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba6d0);
        FUN_007b61a0();
      }
      else {
        lpCriticalSection = (LPCRITICAL_SECTION)(unaff_EDI + 0x60);
        local_20 = lpCriticalSection;
        local_1c = iVar4;
        local_18 = pvVar3;
        EnterCriticalSection(lpCriticalSection);
        local_8 = 0;
        FUN_007b6e80(&local_1c);
        LeaveCriticalSection(lpCriticalSection);
      }
    }
  }
  *(undefined4 *)(unaff_EDI + 0x98) = 0;
  ExceptionList = local_10;
  return local_14;
}

