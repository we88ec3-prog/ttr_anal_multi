
void FUN_007d39b0(int param_1)

{
  char cVar1;
  void *_Dst;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iStack_3c;
  char *local_38;
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
  if (local_24 == (int *)0x0) {
    local_38 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_38);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  *local_24 = (int)local_24;
  local_24[1] = (int)local_24;
  local_24[2] = (int)local_24;
  *(undefined1 *)(local_24 + 4) = 1;
  *(undefined1 *)((int)local_24 + 0x11) = 1;
  local_c = 0;
  _Dst = *(void **)(param_1 + 0x88);
  if (_Dst != *(void **)(param_1 + 0x8c)) {
    FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0x8c),0);
    *(void **)(param_1 + 0x8c) = _Dst;
  }
  FUN_007cbbd0(&DAT_00c4fed0,3,*(undefined4 *)(param_1 + 0x10),local_28);
  piVar5 = (int *)*local_24;
  if (piVar5 != local_24) {
    do {
      iVar4 = (**(code **)(*(int *)piVar5[3] + 4))();
      if (*(int *)(iVar4 + 4) == -0x5eed0000) {
        piVar2 = *(int **)(param_1 + 0x8c);
        iVar4 = piVar5[3];
        iStack_3c = iVar4;
        if (&iStack_3c < piVar2) {
          piVar3 = *(int **)(param_1 + 0x88);
          if (&iStack_3c < piVar3) goto LAB_007d3aea;
          if (piVar2 == *(int **)(param_1 + 0x90)) {
            FUN_0079bf10();
          }
          if (*(undefined4 **)(param_1 + 0x8c) != (undefined4 *)0x0) {
            **(undefined4 **)(param_1 + 0x8c) =
                 *(undefined4 *)
                  (*(int *)(param_1 + 0x88) + ((int)&iStack_3c - (int)piVar3 >> 2) * 4);
          }
        }
        else {
LAB_007d3aea:
          if (piVar2 == *(int **)(param_1 + 0x90)) {
            FUN_0079bf10();
          }
          if (*(int **)(param_1 + 0x8c) != (int *)0x0) {
            **(int **)(param_1 + 0x8c) = iVar4;
          }
        }
        *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + 4;
      }
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

