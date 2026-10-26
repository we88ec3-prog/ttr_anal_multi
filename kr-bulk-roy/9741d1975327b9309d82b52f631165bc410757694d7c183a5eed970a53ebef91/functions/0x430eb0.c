
void FUN_00430eb0(undefined4 param_1,undefined4 param_2)

{
  undefined2 *in_ECX;
  
  *(undefined4 *)(in_ECX + 10) = 7;
  *(undefined4 *)(in_ECX + 8) = 0;
  *in_ECX = 0;
  FUN_00402160(param_1,param_2);
  return;
}

