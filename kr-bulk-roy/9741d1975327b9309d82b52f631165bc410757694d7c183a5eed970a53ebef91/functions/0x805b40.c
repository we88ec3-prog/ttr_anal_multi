
void FUN_00805b40(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined **local_1c [3];
  char *local_10;
  int local_c;
  int *local_8;
  
  piVar1 = *(int **)(param_1 + 0x28);
  piVar2 = (int *)*piVar1;
  while (piVar3 = piVar2, piVar3 != piVar1) {
    if (*(int *)(piVar3[2] + 0x14) == 0) {
      piVar2 = (int *)*piVar3;
      if (piVar3 != *(int **)(param_1 + 0x28)) {
        *(int **)piVar3[1] = piVar2;
        *(int *)(*piVar3 + 4) = piVar3[1];
        FUN_0089120c(piVar3);
        *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + -1;
      }
    }
    else {
      piVar2 = (int *)*piVar3;
    }
  }
  local_8 = (int *)**(int **)(param_1 + 0x48);
  if (local_8 == *(int **)(param_1 + 0x48)) {
    return;
  }
  do {
    local_c = local_8[2];
    if (*(int *)(local_c + 0xa0b8) == 0) {
      FUN_00805f50();
      if (((*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x20) & 3U) == 0) &&
         (*(uint *)(param_1 + 0x18) <= *(int *)(param_1 + 0x20) + 4U >> 2)) {
        FUN_00636f70(param_1 + 0x10);
      }
      uVar5 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x20);
      uVar6 = uVar5 >> 2;
      if (*(uint *)(param_1 + 0x18) <= uVar6) {
        uVar6 = uVar6 - *(uint *)(param_1 + 0x18);
      }
      if (*(int *)(*(int *)(param_1 + 0x14) + uVar6 * 4) == 0) {
        iVar4 = FUN_00891268(0x10);
        if (iVar4 == 0) {
          local_10 = (char *)0x0;
          std::exception::exception((exception *)local_1c,&local_10);
          local_1c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_1c,&DAT_00c857a8);
        }
        *(int *)(*(int *)(param_1 + 0x14) + uVar6 * 4) = iVar4;
      }
      piVar1 = (int *)(*(int *)(*(int *)(param_1 + 0x14) + uVar6 * 4) + (uVar5 & 3) * 4);
      if (piVar1 != (int *)0x0) {
        *piVar1 = local_c;
      }
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
      piVar1 = (int *)*local_8;
      if (local_8 != *(int **)(param_1 + 0x48)) {
        *(int **)local_8[1] = piVar1;
        *(int *)(*local_8 + 4) = local_8[1];
        FUN_0089120c(local_8);
        *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + -1;
      }
    }
    else {
      piVar1 = (int *)*local_8;
    }
    local_8 = piVar1;
  } while (local_8 != *(int **)(param_1 + 0x48));
  return;
}

