
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008061a0(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined **local_34 [3];
  char *local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090992e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = 1;
  local_1c = 0;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)(param_1 + 0xa0d4));
  piVar3 = (int *)**(int **)(param_1 + 0xa074);
  if (piVar3 != *(int **)(param_1 + 0xa074)) {
    do {
      puVar5 = (undefined4 *)piVar3[2];
      local_24 = puVar5[1];
      local_14 = puVar5 + 2;
      local_18 = puVar5;
      if (((*(char *)(param_1 + 0xa02c) == '\0') ||
          (iVar2 = FUN_00807830(local_14,local_24), iVar2 == 0)) &&
         (iVar2 = FUN_00807a70(local_14,local_24), puVar5 = local_18, iVar2 == 0)) {
        if ((*(int *)(param_1 + 0xa0b4) == 1) && (local_1c == 0)) {
          local_20 = 0;
        }
        break;
      }
      local_14 = (int *)*piVar3;
      if (piVar3 != *(int **)(param_1 + 0xa074)) {
        *(int **)piVar3[1] = local_14;
        *(int *)(*piVar3 + 4) = piVar3[1];
        FUN_0089120c(piVar3,uVar1);
        *(int *)(param_1 + 0xa078) = *(int *)(param_1 + 0xa078) + -1;
      }
      piVar3 = local_14;
      if ((DAT_00fe3354 & 1) == 0) {
        DAT_00fe3354 = DAT_00fe3354 | 1;
        local_8 = 0;
        FUN_00807120();
        _atexit((_func_4879 *)&LAB_00bd0b90);
        local_8 = 0xffffffff;
      }
      EnterCriticalSection(DAT_00fe3380);
      *puVar5 = 0;
      puVar5[1] = 0;
      if (((DAT_00fe3370 + DAT_00fe3374 & 3U) == 0) && (DAT_00fe336c <= DAT_00fe3374 + 4U >> 2)) {
        FUN_00636f70(&DAT_00fe3364);
      }
      uVar6 = DAT_00fe3370 + DAT_00fe3374;
      uVar4 = uVar6 >> 2;
      if (DAT_00fe336c <= uVar4) {
        uVar4 = uVar4 - DAT_00fe336c;
      }
      if (*(int *)(DAT_00fe3368 + uVar4 * 4) == 0) {
        iVar2 = FUN_00891268(0x10);
        if (iVar2 == 0) {
          local_28 = (char *)0x0;
          std::exception::exception((exception *)local_34,&local_28);
          local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_34,&DAT_00c857a8);
        }
        *(int *)(DAT_00fe3368 + uVar4 * 4) = iVar2;
      }
      puVar5 = (undefined4 *)(*(int *)(DAT_00fe3368 + uVar4 * 4) + (uVar6 & 3) * 4);
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = local_18;
      }
      DAT_00fe3374 = DAT_00fe3374 + 1;
      _DAT_00fe337c = _DAT_00fe337c + -1;
      LeaveCriticalSection(DAT_00fe3380);
      local_1c = 1;
    } while (local_14 != *(int **)(param_1 + 0xa074));
  }
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(param_1 + 0xa0d4));
  ExceptionList = local_10;
  return local_20;
}

