
void FUN_007aa9a0(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0090a0b7;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 2;
  piVar1 = *(int **)(param_1 + 0x6c);
  if (piVar1 != (int *)0x0) {
    LOCK();
    iVar2 = piVar1[1] + -1;
    piVar1[1] = iVar2;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)*piVar1)(uVar3);
      LOCK();
      iVar2 = piVar1[2] + -1;
      piVar1[2] = iVar2;
      UNLOCK();
      if (iVar2 == 0) {
        (**(code **)(*piVar1 + 4))();
      }
    }
  }
  local_8._0_1_ = 1;
  FUN_007a5120(param_1 + 0x48);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_007a5120(param_1 + 0x28);
  local_8 = 0xffffffff;
  FUN_007a5120(param_1 + 8);
  ExceptionList = local_10;
  return;
}

