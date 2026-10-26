
int FUN_00856de0(int param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  void *_Dst;
  undefined4 uVar7;
  int *piVar8;
  undefined **local_2c [3];
  undefined1 local_20 [8];
  char *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00908fca;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 8) = 0;
  iVar5 = FUN_00891268(0x24,uVar4);
  if (iVar5 != 0) {
    *(int *)(param_1 + 4) = iVar5;
    *(int *)iVar5 = iVar5;
    *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
    *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
    *(undefined1 *)(*(int *)(param_1 + 4) + 0x20) = 1;
    *(undefined1 *)(*(int *)(param_1 + 4) + 0x21) = 1;
    local_8 = 0;
    local_14 = *(int **)(param_2 + 4);
    piVar8 = (int *)*local_14;
    if (piVar8 != local_14) {
      do {
        iVar5 = piVar8[6];
        switch(piVar8[4]) {
        case 0:
        case 4:
        case 5:
        case 6:
          iVar6 = 4;
          break;
        case 1:
        case 7:
          iVar6 = 8;
          break;
        case 2:
          iVar6 = 0xc;
          break;
        case 3:
          iVar6 = 0x10;
          break;
        default:
          iVar6 = 0;
        }
        _Dst = (void *)FUN_0087dc3d(iVar6 * iVar5);
        FID_conflict__memcpy(_Dst,(void *)piVar8[7],iVar6 * iVar5);
        uVar7 = FUN_0054f7d0();
        FUN_008575f0(local_20,uVar7);
        if (*(char *)((int)piVar8 + 0x21) == '\0') {
          piVar2 = (int *)piVar8[2];
          if (*(char *)((int)piVar2 + 0x21) == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x21);
            piVar8 = piVar2;
            piVar2 = (int *)*piVar2;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar2 + 0x21);
              piVar8 = piVar2;
              piVar2 = (int *)*piVar2;
            }
          }
          else {
            cVar1 = *(char *)(piVar8[1] + 0x21);
            piVar3 = (int *)piVar8[1];
            piVar2 = piVar8;
            while ((piVar8 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar8[2]))) {
              cVar1 = *(char *)(piVar8[1] + 0x21);
              piVar3 = (int *)piVar8[1];
              piVar2 = piVar8;
            }
          }
        }
      } while (piVar8 != local_14);
    }
    ExceptionList = local_10;
    return param_1;
  }
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_2c,&local_18);
  local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_2c,&DAT_00c857a8);
}

