
void FUN_00516210(int *param_1)

{
  int *in_EAX;
  
  for (; in_EAX != param_1; in_EAX = in_EAX + 4) {
    if (*in_EAX != 0) {
      FUN_0089120c(*in_EAX);
    }
    *in_EAX = 0;
    in_EAX[1] = 0;
    in_EAX[2] = 0;
  }
  return;
}

