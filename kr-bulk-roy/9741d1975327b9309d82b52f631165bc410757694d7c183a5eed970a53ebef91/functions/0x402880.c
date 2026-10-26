
void FUN_00402880(undefined4 param_1)

{
  undefined2 *in_ECX;
  
  *(undefined4 *)(in_ECX + 10) = 7;
  *(undefined4 *)(in_ECX + 8) = 0;
  *in_ECX = 0;
  FUN_00402800(param_1);
  return;
}

