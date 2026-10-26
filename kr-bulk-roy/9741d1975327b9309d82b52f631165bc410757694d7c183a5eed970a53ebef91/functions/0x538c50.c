
bool FUN_00538c50(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined **local_28 [3];
  char *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar1 = param_2;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912ca1;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (int *)*param_2;
  piVar5 = (int *)*local_18;
  if (piVar5 != local_18) {
    do {
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_8 = 0;
        FUN_0051c120(uVar2);
        _atexit((_func_4879 *)&LAB_00bccc90);
        local_8 = 0xffffffff;
      }
      iVar3 = FUN_0051d700(piVar5[2]);
      if (iVar3 == 0) {
        piVar6 = (int *)*piVar5;
        if (piVar5 != (int *)*piVar1) {
          *(int **)piVar5[1] = piVar6;
          *(int *)(*piVar5 + 4) = piVar5[1];
LAB_00538df3:
          FUN_0089120c(piVar5);
          piVar1[1] = piVar1[1] + -1;
        }
      }
      else if (*(int *)(iVar3 + 0x60) == 0) {
        if ((*(int *)(iVar3 + 0x78) <= param_3) && ((*(int *)(iVar3 + 0x7c) != 0 || (-1 < param_3)))
           ) goto LAB_00538ddc;
        piVar6 = (int *)*piVar5;
        if (piVar5 != (int *)*piVar1) {
          *(int **)piVar5[1] = piVar6;
          *(int *)(*piVar5 + 4) = piVar5[1];
          goto LAB_00538df3;
        }
      }
      else {
        if ((DAT_00f8d9a8 & 1) == 0) {
          DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
          local_8 = 1;
          DAT_00f8d9b4 = 0;
          iVar4 = FUN_00891268(0x18);
          if (iVar4 == 0) {
            local_1c = (char *)0x0;
            std::exception::exception((exception *)local_28,&local_1c);
            local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(local_28,&DAT_00c857a8);
          }
          DAT_00f8d9b0 = iVar4;
          *(int *)iVar4 = iVar4;
          *(int *)(DAT_00f8d9b0 + 4) = DAT_00f8d9b0;
          *(int *)(DAT_00f8d9b0 + 8) = DAT_00f8d9b0;
          *(undefined1 *)(DAT_00f8d9b0 + 0x14) = 1;
          *(undefined1 *)(DAT_00f8d9b0 + 0x15) = 1;
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_00521080(&DAT_00f8d9bc);
          _atexit((_func_4879 *)&LAB_00bccc50);
          local_8 = 0xffffffff;
        }
        param_2 = *(int **)(iVar3 + 0x60);
        FUN_008438c0(&param_2);
        if (local_14 == DAT_00f8d9b0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(local_14 + 0x10);
        }
        if ((param_3 < *(int *)(iVar3 + 0x78)) || ((*(int *)(iVar3 + 0x7c) == 0 && (param_3 < 0))))
        {
          piVar6 = (int *)*piVar5;
          if (piVar5 != (int *)*piVar1) {
            *(int **)piVar5[1] = piVar6;
            *(int *)(*piVar5 + 4) = piVar5[1];
            goto LAB_00538df3;
          }
        }
        else {
LAB_00538ddc:
          piVar6 = (int *)*piVar5;
        }
      }
      piVar5 = piVar6;
    } while (piVar6 != local_18);
  }
  ExceptionList = local_10;
  return (uint)piVar1[1] <= *(uint *)(param_1 + 0x20);
}

