
void FUN_006f09c0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  void **ppvVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int in_ECX;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905b28;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  cVar1 = *(char *)(in_ECX + 0x1a8);
  ppvVar6 = &local_10;
  local_10 = ExceptionList;
  do {
    ExceptionList = ppvVar6;
    if (cVar1 != '\0') {
      ExceptionList = local_10;
      return;
    }
    if (*(char *)(in_ECX + 0x1d0) == '\0') {
      cVar1 = *(char *)(in_ECX + 0x68);
      EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x1c));
      local_8 = 0;
      puVar2 = *(undefined4 **)(in_ECX + 0x4c);
      for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
        iVar4 = *(int *)(in_ECX + 0x58);
        local_14 = puVar3[2];
        iVar8 = FUN_0074d700(iVar4,*(undefined4 *)(iVar4 + 4),&local_14);
        if (*(int *)(in_ECX + 0x5c) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("list<T> too long",uVar7);
        }
        *(int *)(in_ECX + 0x5c) = *(int *)(in_ECX + 0x5c) + 1;
        *(int *)(iVar4 + 4) = iVar8;
        **(int **)(iVar8 + 4) = iVar8;
      }
      piVar5 = *(int **)(in_ECX + 0x4c);
      piVar9 = (int *)*piVar5;
      *piVar5 = (int)piVar5;
      *(int *)(*(int *)(in_ECX + 0x4c) + 4) = *(int *)(in_ECX + 0x4c);
      *(undefined4 *)(in_ECX + 0x50) = 0;
      if (piVar9 != *(int **)(in_ECX + 0x4c)) {
        do {
          piVar5 = (int *)*piVar9;
          FUN_0089120c(piVar9);
          piVar9 = piVar5;
        } while (piVar5 != (int *)*(int *)(in_ECX + 0x4c));
      }
      local_8 = 0xffffffff;
      LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x1c));
      puVar2 = *(undefined4 **)(in_ECX + 0x58);
      for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
        FUN_006f0d00(puVar3[2]);
      }
      puVar2 = *(undefined4 **)(in_ECX + 0x58);
      for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
        if (puVar3[2] != 0) {
          FUN_0089120c(puVar3[2]);
        }
      }
      piVar5 = *(int **)(in_ECX + 0x58);
      piVar9 = (int *)*piVar5;
      *piVar5 = (int)piVar5;
      *(int *)(*(int *)(in_ECX + 0x58) + 4) = *(int *)(in_ECX + 0x58);
      *(undefined4 *)(in_ECX + 0x5c) = 0;
      if (piVar9 != *(int **)(in_ECX + 0x58)) {
        do {
          piVar5 = (int *)*piVar9;
          FUN_0089120c(piVar9);
          piVar9 = piVar5;
        } while (piVar5 != (int *)*(int *)(in_ECX + 0x58));
      }
      if (cVar1 != '\0') {
        *(undefined1 *)(in_ECX + 0x68) = 0;
        SetEvent(*(HANDLE *)(in_ECX + 0x6c));
      }
    }
    WaitForSingleObject(*(HANDLE *)(in_ECX + 0x70),0x32);
    cVar1 = *(char *)(in_ECX + 0x1a8);
    ppvVar6 = ExceptionList;
  } while( true );
}

