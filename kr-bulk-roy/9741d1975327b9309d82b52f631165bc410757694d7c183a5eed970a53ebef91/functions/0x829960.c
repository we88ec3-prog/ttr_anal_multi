
int * FUN_00829960(char *param_1,int *param_2)

{
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int local_40;
  undefined1 local_3c [4];
  undefined4 *local_38;
  undefined4 *local_28;
  undefined4 local_24;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pcVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090e812;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar4 = *(int **)(param_1 + 4);
  if (*(char *)(piVar4[1] + 0x21) == '\0') {
    piVar2 = (int *)piVar4[1];
    do {
      if (piVar2[3] < *param_2) {
        piVar3 = (int *)piVar2[2];
      }
      else {
        piVar3 = (int *)*piVar2;
        piVar4 = piVar2;
      }
      piVar2 = piVar3;
    } while (*(char *)((int)piVar3 + 0x21) == '\0');
  }
  if ((piVar4 == *(int **)(param_1 + 4)) || (*param_2 < piVar4[3])) {
    local_24 = 0;
    local_28 = (undefined4 *)FUN_00891268(0x18,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (local_28 == (undefined4 *)0x0) {
      param_1 = (char *)0x0;
      std::exception::exception((exception *)local_1c,&param_1);
      local_1c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_1c,&DAT_00c857a8);
    }
    *local_28 = local_28;
    local_28[1] = local_28;
    local_28[2] = local_28;
    *(undefined1 *)(local_28 + 5) = 1;
    *(undefined1 *)((int)local_28 + 0x15) = 1;
    local_8 = 0;
    local_40 = *param_2;
    FUN_0082a020(local_3c);
    local_8._0_1_ = 1;
    FUN_00518d80(&local_40);
    FUN_0082a0f0(pcVar1,piVar4);
    piVar4 = param_2;
    param_2 = (int *)local_3c;
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_005540c0(*local_38,local_38);
    FUN_0089120c(local_38);
    local_8 = 3;
    FUN_005540c0(*local_28,local_28);
    FUN_0089120c(local_28);
  }
  ExceptionList = local_10;
  return piVar4 + 4;
}

