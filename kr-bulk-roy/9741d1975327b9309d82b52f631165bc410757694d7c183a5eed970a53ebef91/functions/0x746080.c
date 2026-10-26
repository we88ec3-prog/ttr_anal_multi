
void FUN_00746080(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *in_ECX;
  undefined4 *extraout_EDX;
  
  if ((char)param_1 == '\0') {
    if ((char)in_ECX[10] < '\0') {
      in_ECX[10] = in_ECX[10] ^ 0x80;
    }
  }
  else {
    in_ECX[10] = in_ECX[10] | 0x80;
  }
  puVar1 = (undefined4 *)in_ECX[0x19];
  puVar2 = (undefined4 *)*puVar1;
  while (puVar2 != puVar1) {
    FUN_00746450(0x80,param_1,0);
    puVar2 = (undefined4 *)*extraout_EDX;
  }
  (**(code **)(*in_ECX + 200))();
  return;
}

