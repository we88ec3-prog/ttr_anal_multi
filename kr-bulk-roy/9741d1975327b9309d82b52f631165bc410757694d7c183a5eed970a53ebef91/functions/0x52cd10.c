
int FUN_0052cd10(int param_1,short param_2,int param_3,int param_4,int param_5,int param_6,
                int param_7)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined **local_28 [3];
  char *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009100c3;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = *(int **)(param_1 + 0x24);
  piVar6 = (int *)*local_18;
  if (piVar6 != local_18) {
    do {
      if ((DAT_00f8d9a8 & 1) == 0) {
        DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
        local_8 = 0;
        DAT_00f8d9b4 = 0;
        iVar5 = FUN_00891268(0x18,uVar4);
        if (iVar5 == 0) {
          local_1c = (char *)0x0;
          std::exception::exception((exception *)local_28,&local_1c);
          local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_28,&DAT_00c857a8);
        }
        DAT_00f8d9b0 = iVar5;
        *(int *)iVar5 = iVar5;
        *(int *)(DAT_00f8d9b0 + 4) = DAT_00f8d9b0;
        *(int *)(DAT_00f8d9b0 + 8) = DAT_00f8d9b0;
        *(undefined1 *)(DAT_00f8d9b0 + 0x14) = 1;
        *(undefined1 *)(DAT_00f8d9b0 + 0x15) = 1;
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_00521080(&DAT_00f8d9bc);
        _atexit((_func_4879 *)&LAB_00bccc50);
        local_8 = 0xffffffff;
      }
      param_1 = piVar6[6];
      FUN_008438c0(&param_1);
      if (local_14 == DAT_00f8d9b0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(local_14 + 0x10);
      }
      if ((((((short)piVar6[7] == param_2) && (piVar6[10] == param_5)) && (piVar6[0xb] == param_6))
          && ((piVar6[8] == param_3 && (piVar6[9] == param_4)))) &&
         (*(int *)(iVar5 + 0x6c) == param_7)) {
        ExceptionList = local_10;
        return piVar6[6];
      }
      if (*(char *)((int)piVar6 + 0x39) == '\0') {
        piVar2 = (int *)piVar6[2];
        if (*(char *)((int)piVar2 + 0x39) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x39);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x39);
            piVar6 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar6[1] + 0x39);
          piVar3 = (int *)piVar6[1];
          piVar2 = piVar6;
          while ((piVar6 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
            cVar1 = *(char *)(piVar6[1] + 0x39);
            piVar3 = (int *)piVar6[1];
            piVar2 = piVar6;
          }
        }
      }
    } while (piVar6 != local_18);
  }
  ExceptionList = local_10;
  return 0;
}

