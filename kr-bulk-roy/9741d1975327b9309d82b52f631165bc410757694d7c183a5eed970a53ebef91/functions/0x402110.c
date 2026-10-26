
void FUN_00402110(undefined4 param_1)

{
  undefined2 *in_ECX;
  
  *(undefined4 *)(in_ECX + 10) = 7;
  *(undefined4 *)(in_ECX + 8) = 0;
  *in_ECX = 0;
  FUN_004026e0(param_1,0,0xffffffff);
  return;
}

