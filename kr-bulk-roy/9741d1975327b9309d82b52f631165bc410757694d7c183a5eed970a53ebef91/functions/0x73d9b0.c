
void FUN_0073d9b0(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_ECX;
  undefined4 in_EDX;
  float10 fVar1;
  float local_48 [17];
  
  FUN_0073d790(param_1,param_2,in_EDX,in_ECX,0,0,0,local_48);
  local_48[0] = (float)(int)local_48[0] * 0.015625;
  fVar1 = (float10)FUN_00892d30((double)local_48[0]);
  local_48[0] = (float)fVar1;
  FUN_008fed10();
  return;
}

