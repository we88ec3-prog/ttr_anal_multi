
undefined4 FUN_008605b0(int param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00906938;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar1 = *(int **)(param_1 + 0x7c);
  piVar3 = *(int **)(param_1 + 0x78);
  if (piVar3 != piVar1) {
    do {
      if ((undefined4 *)*piVar3 == in_EDX) break;
      piVar3 = piVar3 + 1;
    } while (piVar3 != piVar1);
    if (piVar3 != piVar1) {
      return 0;
    }
  }
  ExceptionList = &local_10;
  if (in_EDX != (undefined4 *)0x0) {
    in_EDX[1] = in_EDX[1] + 1;
  }
  local_8 = 0;
  FUN_0077f8f0(uVar2);
  local_8 = 0xffffffff;
  if (in_EDX != (undefined4 *)0x0) {
    piVar1 = in_EDX + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)*in_EDX)(1);
    }
  }
  ExceptionList = local_10;
  return 1;
}

