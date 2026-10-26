
void FUN_00556df0(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  char *pcVar7;
  int *piVar8;
  undefined1 local_64 [4];
  undefined4 *local_60;
  undefined4 local_5c;
  undefined1 local_54 [4];
  int *local_50;
  undefined4 local_4c;
  undefined1 local_44 [4];
  int *local_40;
  undefined4 local_3c;
  undefined **local_34 [3];
  undefined **local_28 [3];
  char *local_1c;
  undefined4 local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933a51;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_5c = 0;
  local_60 = (undefined4 *)FUN_00891268(0x18,uVar4);
  if (local_60 == (undefined4 *)0x0) {
    local_1c = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_1c);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  *local_60 = local_60;
  local_60[1] = local_60;
  local_60[2] = local_60;
  *(undefined1 *)(local_60 + 5) = 1;
  *(undefined1 *)((int)local_60 + 0x15) = 1;
  local_8 = 0;
  piVar8 = *(int **)*param_2;
  if (piVar8 != (int *)*param_2) {
    do {
      local_14 = (char *)piVar8[2];
      local_18 = CONCAT22(local_18._2_2_,*(undefined2 *)(local_14 + 4));
      uVar5 = FUN_00557d10();
      FUN_0082f200(local_64,uVar5);
      piVar8 = (int *)*piVar8;
    } while (piVar8 != (int *)*param_2);
  }
  local_4c = 0;
  local_50 = (int *)FUN_00891268(0x18,uVar4);
  if (local_50 != (int *)0x0) {
    *local_50 = (int)local_50;
    local_50[1] = (int)local_50;
    local_50[2] = (int)local_50;
    *(undefined1 *)(local_50 + 5) = 1;
    *(undefined1 *)((int)local_50 + 0x15) = 1;
    local_8._0_1_ = 1;
    local_3c = 0;
    local_40 = (int *)FUN_00891268(0x18,uVar4);
    if (local_40 != (int *)0x0) {
      *local_40 = (int)local_40;
      local_40[1] = (int)local_40;
      local_40[2] = (int)local_40;
      *(undefined1 *)(local_40 + 5) = 1;
      *(undefined1 *)((int)local_40 + 0x15) = 1;
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_00556bd0(param_1,local_64,local_54,local_44);
      piVar8 = (int *)*local_40;
      if (piVar8 != local_40) {
        do {
          piVar6 = (int *)FUN_00831f50();
          iVar2 = *piVar6;
          if (iVar2 != 0) {
            if (*(int **)(iVar2 + 4) != (int *)0x0) {
              (**(code **)(**(int **)(iVar2 + 4) + 8))();
              *(undefined4 *)(iVar2 + 4) = 0;
            }
            FUN_0089120c(iVar2);
          }
          FUN_007b6ce0(&local_18,piVar8 + 3);
          FUN_005540c0(local_18,local_14);
          if (*(char *)((int)piVar8 + 0x15) == '\0') {
            piVar6 = (int *)piVar8[2];
            if (*(char *)((int)piVar6 + 0x15) == '\0') {
              cVar1 = *(char *)(*piVar6 + 0x15);
              piVar8 = piVar6;
              piVar6 = (int *)*piVar6;
              while (cVar1 == '\0') {
                cVar1 = *(char *)(*piVar6 + 0x15);
                piVar8 = piVar6;
                piVar6 = (int *)*piVar6;
              }
            }
            else {
              cVar1 = *(char *)(piVar8[1] + 0x15);
              piVar3 = (int *)piVar8[1];
              piVar6 = piVar8;
              while ((piVar8 = piVar3, cVar1 == '\0' && (piVar6 == (int *)piVar8[2]))) {
                cVar1 = *(char *)(piVar8[1] + 0x15);
                piVar3 = (int *)piVar8[1];
                piVar6 = piVar8;
              }
            }
          }
        } while (piVar8 != local_40);
      }
      piVar8 = (int *)*local_50;
      if (piVar8 != local_50) {
        do {
          pcVar7 = (char *)FUN_00891268(0x28);
          local_8._0_1_ = 3;
          local_1c = pcVar7;
          if (pcVar7 == (char *)0x0) {
            local_14 = (char *)0x0;
          }
          else {
            pcVar7[4] = '\0';
            pcVar7[5] = '\0';
            pcVar7[6] = '\0';
            pcVar7[7] = '\0';
            pcVar7[0x24] = '\0';
            pcVar7[0x25] = '\0';
            pcVar7[0x26] = '\0';
            pcVar7[0x27] = '\0';
            FUN_00556770(pcVar7);
            local_14 = pcVar7;
          }
          local_8 = CONCAT31(local_8._1_3_,2);
          local_18 = CONCAT22(local_18._2_2_,*(undefined2 *)(piVar8[4] + 4));
          uVar5 = FUN_00557d10();
          FUN_0082f200(param_1,uVar5);
          if (*(char *)((int)piVar8 + 0x15) == '\0') {
            piVar6 = (int *)piVar8[2];
            if (*(char *)((int)piVar6 + 0x15) == '\0') {
              cVar1 = *(char *)(*piVar6 + 0x15);
              piVar8 = piVar6;
              piVar6 = (int *)*piVar6;
              while (cVar1 == '\0') {
                cVar1 = *(char *)(*piVar6 + 0x15);
                piVar8 = piVar6;
                piVar6 = (int *)*piVar6;
              }
            }
            else {
              cVar1 = *(char *)(piVar8[1] + 0x15);
              piVar3 = (int *)piVar8[1];
              piVar6 = piVar8;
              while ((piVar8 = piVar3, cVar1 == '\0' && (piVar6 == (int *)piVar8[2]))) {
                cVar1 = *(char *)(piVar8[1] + 0x15);
                piVar3 = (int *)piVar8[1];
                piVar6 = piVar8;
              }
            }
          }
        } while (piVar8 != local_50);
      }
      if (*(int *)(param_1 + 8) <= *(int *)(param_1 + 0x10)) {
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 8) + -1;
      }
      local_8._0_1_ = 4;
      FUN_005540c0(*local_40,local_40);
      FUN_0089120c(local_40);
      local_8 = CONCAT31(local_8._1_3_,5);
      FUN_005540c0(*local_50,local_50);
      FUN_0089120c(local_50);
      local_8 = 6;
      FUN_005540c0(*local_60,local_60);
      FUN_0089120c(local_60);
      ExceptionList = local_10;
      return;
    }
    param_2 = (int *)0x0;
    std::exception::exception((exception *)local_34,(char **)&param_2);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

