
void FUN_007b7640(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  int *local_1c;
  char *pcStack_18;
  undefined **appuStack_14 [4];
  
  if (*(int *)(param_1 + 0x428) != 0) {
    local_1c = (int *)(param_1 + 0x28);
    do {
      iVar4 = *local_1c;
      if (*(undefined4 **)(iVar4 + 8) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(iVar4 + 8))(1);
        *(undefined4 *)(iVar4 + 8) = 0;
      }
      piVar6 = (int *)(*(int *)(iVar4 + 4) + 8);
      *piVar6 = *piVar6 + -1;
      if (((*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x20) & 3U) == 0) &&
         (*(uint *)(param_1 + 0x18) <= *(int *)(param_1 + 0x20) + 4U >> 2)) {
        FUN_00636f70(param_1 + 0x10);
      }
      uVar5 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x20);
      uVar7 = uVar5 >> 2;
      if (*(uint *)(param_1 + 0x18) <= uVar7) {
        uVar7 = uVar7 - *(uint *)(param_1 + 0x18);
      }
      if (*(int *)(*(int *)(param_1 + 0x14) + uVar7 * 4) == 0) {
        iVar4 = FUN_00891268(0x10);
        if (iVar4 == 0) {
          pcStack_18 = (char *)0x0;
          std::exception::exception((exception *)appuStack_14,&pcStack_18);
          appuStack_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(appuStack_14,&DAT_00c857a8);
        }
        *(int *)(*(int *)(param_1 + 0x14) + uVar7 * 4) = iVar4;
      }
      piVar6 = (int *)(*(int *)(*(int *)(param_1 + 0x14) + uVar7 * 4) + (uVar5 & 3) * 4);
      if (piVar6 != (int *)0x0) {
        *piVar6 = *local_1c;
      }
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
      *local_1c = 0;
      local_1c = local_1c + 1;
      *(int *)(param_1 + 0x428) = *(int *)(param_1 + 0x428) + -1;
    } while (*(int *)(param_1 + 0x428) != 0);
  }
  piVar6 = (int *)**(int **)(param_1 + 4);
  if (piVar6 != *(int **)(param_1 + 4)) {
    do {
      FUN_007dc020(piVar6[10]);
      if (*(char *)((int)piVar6 + 0x2d) == '\0') {
        piVar2 = (int *)piVar6[2];
        if (*(char *)((int)piVar2 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x2d);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x2d);
            piVar6 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar6[1] + 0x2d);
          piVar3 = (int *)piVar6[1];
          piVar2 = piVar6;
          while ((piVar6 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
            cVar1 = *(char *)(piVar6[1] + 0x2d);
            piVar3 = (int *)piVar6[1];
            piVar2 = piVar6;
          }
        }
      }
    } while (piVar6 != *(int **)(param_1 + 4));
  }
  return;
}

