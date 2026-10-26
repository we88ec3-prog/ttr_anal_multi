
bool FUN_00755c10(int param_1)

{
  int *in_EAX;
  int iVar1;
  
  if ((in_EAX[1] != 0) && (*in_EAX == 100)) {
    iVar1 = (**(code **)(*(int *)in_EAX[1] + 8))();
    return iVar1 == param_1;
  }
  return false;
}

