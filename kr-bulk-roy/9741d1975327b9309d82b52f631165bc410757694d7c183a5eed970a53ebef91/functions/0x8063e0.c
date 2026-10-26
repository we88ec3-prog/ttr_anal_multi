
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008063e0(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  undefined **local_28 [3];
  char *local_1c;
  int *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009098fe;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)(param_1 + 0xa0d4));
  local_18 = *(int **)(param_1 + 0xa074);
  piVar5 = (int *)*local_18;
  if (piVar5 != local_18) {
    do {
      if ((DAT_00fe3354 & 1) == 0) {
        DAT_00fe3354 = DAT_00fe3354 | 1;
        local_8 = 0;
        FUN_00807120(uVar2);
        _atexit((_func_4879 *)&LAB_00bd0b90);
        local_8 = 0xffffffff;
      }
      puVar1 = (undefined4 *)piVar5[2];
      local_14 = puVar1;
      EnterCriticalSection(DAT_00fe3380);
      *puVar1 = 0;
      puVar1[1] = 0;
      if (((DAT_00fe3370 + DAT_00fe3374 & 3U) == 0) && (DAT_00fe336c <= DAT_00fe3374 + 4U >> 2)) {
        FUN_00636f70(&DAT_00fe3364);
      }
      uVar7 = DAT_00fe3370 + DAT_00fe3374;
      uVar6 = uVar7 >> 2;
      if (DAT_00fe336c <= uVar6) {
        uVar6 = uVar6 - DAT_00fe336c;
      }
      if (*(int *)(DAT_00fe3368 + uVar6 * 4) == 0) {
        iVar3 = FUN_00891268(0x10);
        if (iVar3 == 0) {
          local_1c = (char *)0x0;
          std::exception::exception((exception *)local_28,&local_1c);
          local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_28,&DAT_00c857a8);
        }
        *(int *)(DAT_00fe3368 + uVar6 * 4) = iVar3;
      }
      puVar1 = (undefined4 *)(*(int *)(DAT_00fe3368 + uVar6 * 4) + (uVar7 & 3) * 4);
      if (puVar1 != (undefined4 *)0x0) {
        *puVar1 = local_14;
      }
      DAT_00fe3374 = DAT_00fe3374 + 1;
      _DAT_00fe337c = _DAT_00fe337c + -1;
      LeaveCriticalSection(DAT_00fe3380);
      piVar5 = (int *)*piVar5;
    } while (piVar5 != local_18);
  }
  piVar5 = *(int **)(param_1 + 0xa074);
  piVar4 = (int *)*piVar5;
  *piVar5 = (int)piVar5;
  *(int *)(*(int *)(param_1 + 0xa074) + 4) = *(int *)(param_1 + 0xa074);
  *(undefined4 *)(param_1 + 0xa078) = 0;
  if (piVar4 != *(int **)(param_1 + 0xa074)) {
    do {
      piVar5 = (int *)*piVar4;
      FUN_0089120c(piVar4);
      piVar4 = piVar5;
    } while (piVar5 != (int *)*(int *)(param_1 + 0xa074));
  }
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(param_1 + 0xa0d4));
  ExceptionList = local_10;
  return;
}

