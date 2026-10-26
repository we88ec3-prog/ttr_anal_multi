
int FUN_0082ff10(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00909443;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar2 = FUN_00891268();
  local_8._0_1_ = 1;
  if (iVar2 == 0) {
    local_14 = 0;
  }
  else {
    if (param_2 != (int *)0x0) {
      cVar1 = FUN_0047c250();
      if (cVar1 != '\0') {
        FUN_007a31c0(param_1,param_2);
      }
    }
    local_14 = FUN_0082cbc0();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  piVar3 = (int *)(local_14 + 0x24);
  local_18 = 0x20;
  do {
    if (*(int *)((int)piVar3 + param_1 + (-8 - local_14)) != 0) {
      iVar2 = FUN_00833280();
      if (*piVar3 != 0) {
        FUN_0082cda0();
        *piVar3 = 0;
      }
      *piVar3 = iVar2;
    }
    piVar3 = piVar3 + 1;
    local_18 = local_18 + -1;
  } while (local_18 != 0);
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    LOCK();
    iVar2 = param_2[1] + -1;
    param_2[1] = iVar2;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)*param_2)();
      LOCK();
      iVar2 = param_2[2] + -1;
      param_2[2] = iVar2;
      UNLOCK();
      if (iVar2 == 0) {
        (**(code **)(*param_2 + 4))();
      }
    }
  }
  ExceptionList = local_10;
  return local_14;
}

