
void FUN_00858240(int *param_1)

{
  int *in_EAX;
  int *in_ECX;
  
  for (; in_ECX != param_1; in_ECX = in_ECX + 4) {
    if (in_EAX != in_ECX) {
      if (*in_EAX != 0) {
        FUN_0089120c(*in_EAX);
      }
      *in_EAX = 0;
      in_EAX[1] = 0;
      in_EAX[2] = 0;
      *in_EAX = *in_ECX;
      in_EAX[1] = in_ECX[1];
      in_EAX[2] = in_ECX[2];
      *in_ECX = 0;
      in_ECX[1] = 0;
      in_ECX[2] = 0;
    }
    in_EAX = in_EAX + 4;
  }
  return;
}

