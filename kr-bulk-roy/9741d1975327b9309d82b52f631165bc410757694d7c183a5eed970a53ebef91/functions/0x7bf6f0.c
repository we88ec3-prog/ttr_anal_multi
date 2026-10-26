
void FUN_007bf6f0(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  char *local_40 [3];
  undefined **local_34 [3];
  undefined1 local_28 [4];
  int *local_24;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00907762;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_20 = 0;
  local_24 = (int *)FUN_00891268(0x14,DAT_00d61f20 ^ (uint)&stack0xffffffb8);
  if (local_24 != (int *)0x0) {
    *local_24 = (int)local_24;
    local_24[1] = (int)local_24;
    local_24[2] = (int)local_24;
    *(undefined1 *)(local_24 + 4) = 1;
    *(undefined1 *)((int)local_24 + 0x11) = 1;
    local_c = 0;
    piVar5 = (int *)**(int **)(param_1 + 4);
    if (piVar5 != *(int **)(param_1 + 4)) {
      do {
        uVar4 = FUN_006bde40(piVar5 + 6);
        FUN_0044bbd0(local_28,uVar4);
        if (*(char *)((int)piVar5 + 0x21) == '\0') {
          piVar2 = (int *)piVar5[2];
          if (*(char *)((int)piVar2 + 0x21) == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x21);
            piVar5 = piVar2;
            piVar2 = (int *)*piVar2;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar2 + 0x21);
              piVar5 = piVar2;
              piVar2 = (int *)*piVar2;
            }
          }
          else {
            cVar1 = *(char *)(piVar5[1] + 0x21);
            piVar3 = (int *)piVar5[1];
            piVar2 = piVar5;
            while ((piVar5 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar5[2]))) {
              cVar1 = *(char *)(piVar5[1] + 0x21);
              piVar3 = (int *)piVar5[1];
              piVar2 = piVar5;
            }
          }
        }
      } while (piVar5 != *(int **)(param_1 + 4));
    }
    piVar5 = (int *)*local_24;
    if (piVar5 != local_24) {
      do {
        (**(code **)(*(int *)piVar5[3] + 8))();
        if (*(char *)((int)piVar5 + 0x11) == '\0') {
          piVar2 = (int *)piVar5[2];
          if (*(char *)((int)piVar2 + 0x11) == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x11);
            piVar5 = piVar2;
            piVar2 = (int *)*piVar2;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar2 + 0x11);
              piVar5 = piVar2;
              piVar2 = (int *)*piVar2;
            }
          }
          else {
            cVar1 = *(char *)(piVar5[1] + 0x11);
            piVar3 = (int *)piVar5[1];
            piVar2 = piVar5;
            while ((piVar5 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar5[2]))) {
              cVar1 = *(char *)(piVar5[1] + 0x11);
              piVar3 = (int *)piVar5[1];
              piVar2 = piVar5;
            }
          }
        }
      } while (piVar5 != local_24);
    }
    local_c = 1;
    FUN_004ca160(*local_24,local_24);
    FUN_0089120c(local_24);
    ExceptionList = local_14;
    return;
  }
  local_40[0] = (char *)0x0;
  std::exception::exception((exception *)local_34,local_40);
  local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_34,&DAT_00c857a8);
}

