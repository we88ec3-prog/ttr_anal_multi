
void FUN_007a3850(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907993;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_006d7120(**(undefined4 **)(param_1 + 0x1c),*(undefined4 **)(param_1 + 0x1c));
  FUN_0089120c(*(undefined4 *)(param_1 + 0x1c),uVar3);
  local_8 = 0xffffffff;
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    LOCK();
    iVar2 = piVar1[1] + -1;
    piVar1[1] = iVar2;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)*piVar1)();
      LOCK();
      iVar2 = piVar1[2] + -1;
      piVar1[2] = iVar2;
      UNLOCK();
      if (iVar2 == 0) {
        (**(code **)(*piVar1 + 4))();
      }
    }
  }
  ExceptionList = local_10;
  return;
}

