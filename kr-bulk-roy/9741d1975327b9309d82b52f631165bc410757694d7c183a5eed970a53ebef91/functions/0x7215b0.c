
char * FUN_007215b0(char *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  undefined **local_1c;
  int *local_18;
  code *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00932708;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[0] = '\0';
  param_1[1] = '\0';
  param_1[2] = '\0';
  param_1[3] = '\0';
  pcVar5 = param_1 + 4;
  *(char **)pcVar5 = "Internal error";
  param_1[8] = '\0';
  param_1[9] = '\0';
  param_1[10] = '\0';
  param_1[0xb] = '\0';
  piVar2 = (int *)(*(code *)PTR_FUN_00d63d48)(0x1010,uVar1);
  if (piVar2 == (int *)0x0) {
    param_1 = "bad allocation";
    std::exception::exception((exception *)&local_1c,&param_1,1);
    local_1c = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&local_1c,&DAT_00c857a8);
  }
  *piVar2 = 0;
  piVar2[1] = (int)(piVar2 + 3);
  piVar2[2] = 0;
  piVar2[3] = 0;
  local_14 = FUN_00721390;
  local_8 = 0;
  local_18 = piVar2;
  iVar3 = FUN_00721300(pcVar5);
  *piVar2 = iVar3;
  piVar4 = local_18;
  if (iVar3 != 0) {
    *(int **)param_1 = piVar2;
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    piVar4 = (int *)0x0;
  }
  local_8 = 0xffffffff;
  if (piVar4 != (int *)0x0) {
    FUN_00721390(piVar4);
  }
  ExceptionList = local_10;
  return param_1;
}

