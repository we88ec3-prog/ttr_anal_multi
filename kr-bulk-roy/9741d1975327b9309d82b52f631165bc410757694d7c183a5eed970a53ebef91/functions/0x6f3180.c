
void FUN_006f3180(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *in_EDX;
  
  puVar2 = in_EDX;
  if (7 < (uint)in_EDX[5]) {
    puVar2 = (undefined4 *)*in_EDX;
  }
  piVar1 = in_EDX + 4;
  if (7 < (uint)in_EDX[5]) {
    in_EDX = (undefined4 *)*in_EDX;
  }
  FUN_006f31c0(in_EDX,(int)puVar2 + *piVar1 * 2,param_2,param_2);
  return;
}

