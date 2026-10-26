
int * FUN_00515b90(char *param_1,int *param_2)

{
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int local_44;
  char local_40 [4];
  undefined4 *local_3c;
  undefined4 *local_2c;
  undefined4 local_28;
  undefined **local_20 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pcVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_009171c2;
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
    local_28 = 0;
    local_2c = (undefined4 *)FUN_00891268(0x24,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (local_2c == (undefined4 *)0x0) {
      param_1 = (char *)0x0;
      std::exception::exception((exception *)local_20,&param_1);
      local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_20,&DAT_00c857a8);
    }
    *local_2c = local_2c;
    local_2c[1] = local_2c;
    local_2c[2] = local_2c;
    *(undefined1 *)(local_2c + 8) = 1;
    *(undefined1 *)((int)local_2c + 0x21) = 1;
    local_8 = 0;
    local_44 = *param_2;
    FUN_00517550(local_40);
    local_8._0_1_ = 1;
    FUN_00518f90(&local_44);
    FUN_00517ac0(pcVar1,piVar4);
    param_1 = local_40;
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00515e70(*local_3c,local_3c);
    FUN_0089120c(local_3c);
    local_8 = 3;
    FUN_00515e70(*local_2c,local_2c);
    FUN_0089120c(local_2c);
    piVar4 = param_2;
  }
  ExceptionList = local_10;
  return piVar4 + 4;
}

