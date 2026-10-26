
int * FUN_0084a830(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00904623;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  local_8 = 1;
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)*param_2) {
    if (puVar1 != (undefined4 *)0x0) {
      piVar2 = puVar1 + 1;
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) {
        (**(code **)*puVar1)(1,uVar3);
      }
    }
    piVar2 = (int *)*param_2;
    *param_1 = (int)piVar2;
    if (piVar2 != (int *)0x0) {
      iVar4 = (**(code **)(*piVar2 + 8))();
      if (iVar4 == 0) {
        iVar4 = (**(code **)(*(int *)*param_1 + 0xc))();
        *param_1 = iVar4;
      }
      *(int *)(*param_1 + 4) = *(int *)(*param_1 + 4) + 1;
    }
  }
  param_1[4] = param_2[4];
  _free((void *)param_1[3]);
  param_1[3] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  ExceptionList = local_10;
  return param_1;
}

