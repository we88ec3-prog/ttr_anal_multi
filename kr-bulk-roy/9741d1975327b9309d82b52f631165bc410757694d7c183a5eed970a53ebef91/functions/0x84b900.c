
void FUN_0084b900(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  void **ppvVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00904d93;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ppvVar3 = &local_10;
  local_10 = ExceptionList;
  for (; ExceptionList = ppvVar3, param_1 != param_2; param_1 = param_1 + 5) {
    local_8 = 1;
    puVar2 = (undefined4 *)*param_1;
    if (puVar2 != (undefined4 *)0x0) {
      piVar1 = puVar2 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)*puVar2)(1,uVar4);
      }
    }
    *param_1 = 0;
    _free((void *)param_1[3]);
    local_8 = 0xffffffff;
    puVar2 = (undefined4 *)*param_1;
    if (puVar2 != (undefined4 *)0x0) {
      piVar1 = puVar2 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)*puVar2)(1);
      }
    }
    ppvVar3 = ExceptionList;
  }
  ExceptionList = local_10;
  return;
}

