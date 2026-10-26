
float10 FUN_00719fe0(int param_1,float param_2)

{
  undefined4 in_EAX;
  float10 fVar1;
  
  FUN_0071baa0(in_EAX);
  if (param_1 != 0) {
    if (*(int *)(param_1 + 8) != 0) {
      fVar1 = (float10)FUN_00898a3f(*(int *)(param_1 + 8),0);
      return (float10)(float)fVar1;
    }
    param_2 = 0.0;
  }
  return (float10)param_2;
}

