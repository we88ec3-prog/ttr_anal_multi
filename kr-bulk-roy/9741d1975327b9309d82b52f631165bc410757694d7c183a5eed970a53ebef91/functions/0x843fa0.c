
undefined4 FUN_00843fa0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  undefined4 *local_20;
  undefined1 local_1c [4];
  char local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00906cc0;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (in_ECX == (undefined4 *)0x0) {
    return 0;
  }
  ExceptionList = &local_10;
  in_ECX[0x1a] = param_2;
  in_ECX[1] = in_ECX[1] + 1;
  local_8 = 0;
  uVar3 = FUN_00845210(uVar2);
  local_8._0_1_ = 1;
  uVar3 = FUN_00845250(uVar3);
  FUN_00845410(local_1c,uVar3);
  local_8 = (uint)local_8._1_3_ << 8;
  if ((local_20 != (undefined4 *)0x0) && (local_20[1] = local_20[1] + -1, local_20[1] == 0)) {
    (**(code **)*local_20)(1);
  }
  if (local_18 != '\0') {
    local_8 = 0xffffffff;
    piVar1 = in_ECX + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)*in_ECX)(1);
    }
    ExceptionList = local_10;
    return 1;
  }
  FUN_008451d0();
  local_8 = 0xffffffff;
  piVar1 = in_ECX + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    (**(code **)*in_ECX)(1);
  }
  ExceptionList = local_10;
  return 2;
}

