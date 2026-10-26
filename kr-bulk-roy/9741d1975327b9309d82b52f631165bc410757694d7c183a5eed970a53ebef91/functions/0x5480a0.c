
uint FUN_005480a0(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + (param_1 * 3 + 3) * 4) == 0) {
    return param_1 & 0xffffff00;
  }
  if (param_1 != 0) {
    uVar1 = FUN_005480e0(in_ECX,param_2);
    return uVar1;
  }
  uVar1 = FUN_00546100(0,param_2);
  return uVar1;
}

