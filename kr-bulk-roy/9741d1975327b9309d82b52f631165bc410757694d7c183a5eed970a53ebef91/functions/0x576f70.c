
void FUN_00576f70(float param_1)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x70) != 0) && (param_1 <= 1.0)) {
    FUN_005776d0(in_ECX,param_1);
    FUN_00577cc0(param_1);
    FUN_00577d20(in_ECX);
  }
  return;
}

