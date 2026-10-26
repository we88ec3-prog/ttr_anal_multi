
undefined4 * FUN_004c97f0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  int in_EDX;
  
  if ((*(int *)(in_EDX + 0x15c) != 0) && (*(int *)(in_EDX + 0x370) != 0)) {
    FUN_007a8630(param_2);
    return param_1;
  }
  uVar1 = in_ECX[1];
  *param_1 = *in_ECX;
  uVar2 = in_ECX[2];
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  return param_1;
}

