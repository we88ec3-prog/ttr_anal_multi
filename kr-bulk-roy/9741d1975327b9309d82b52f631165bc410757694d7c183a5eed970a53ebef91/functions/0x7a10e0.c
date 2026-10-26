
void FUN_007a10e0(int *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  void **ppvVar5;
  uint uVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090a1f8;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  cVar1 = *(char *)((int)param_1 + 0x31);
  ppvVar5 = &local_10;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar5, cVar1 == '\0') {
    FUN_007a10e0(param_1[2]);
    piVar2 = (int *)*param_1;
    local_8 = 0;
    piVar3 = (int *)param_1[0xb];
    if (piVar3 != (int *)0x0) {
      LOCK();
      iVar4 = piVar3[1] + -1;
      piVar3[1] = iVar4;
      UNLOCK();
      if (iVar4 == 0) {
        (**(code **)*piVar3)(uVar6);
        LOCK();
        iVar4 = piVar3[2] + -1;
        piVar3[2] = iVar4;
        UNLOCK();
        if (iVar4 == 0) {
          (**(code **)(*piVar3 + 4))();
        }
      }
    }
    local_8 = 0xffffffff;
    if (0xf < (uint)param_1[8]) {
      FUN_0089120c(param_1[3]);
    }
    param_1[8] = 0xf;
    param_1[7] = 0;
    *(undefined1 *)(param_1 + 3) = 0;
    FUN_0089120c(param_1);
    ppvVar5 = ExceptionList;
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x31);
  }
  ExceptionList = local_10;
  return;
}

