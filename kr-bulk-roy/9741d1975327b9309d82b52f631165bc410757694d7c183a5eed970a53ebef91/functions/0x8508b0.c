
void FUN_008508b0(int *param_1)

{
  int *in_EAX;
  
  for (; in_EAX != param_1; in_EAX = in_EAX + 5) {
    if (*in_EAX != 0) {
      FUN_0089120c(*in_EAX);
    }
    *in_EAX = 0;
    in_EAX[1] = 0;
    in_EAX[2] = 0;
  }
  return;
}

