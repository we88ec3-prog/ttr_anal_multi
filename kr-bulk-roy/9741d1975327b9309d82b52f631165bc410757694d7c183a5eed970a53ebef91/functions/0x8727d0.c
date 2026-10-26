
undefined4 FUN_008727d0(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00906938;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar1 = *(int **)(in_ECX + 0x188);
  piVar3 = *(int **)(in_ECX + 0x184);
  if (piVar3 != piVar1) {
    do {
      if ((undefined4 *)*piVar3 == param_1) break;
      piVar3 = piVar3 + 1;
    } while (piVar3 != piVar1);
    if (piVar3 != piVar1) {
      return 0;
    }
  }
  ExceptionList = &local_10;
  if (param_1 != (undefined4 *)0x0) {
    param_1[1] = param_1[1] + 1;
  }
  local_8 = 0;
  FUN_0077f8f0(uVar2);
  local_8 = 0xffffffff;
  if (param_1 != (undefined4 *)0x0) {
    piVar1 = param_1 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)*param_1)(1);
    }
  }
  ExceptionList = local_10;
  return 1;
}

