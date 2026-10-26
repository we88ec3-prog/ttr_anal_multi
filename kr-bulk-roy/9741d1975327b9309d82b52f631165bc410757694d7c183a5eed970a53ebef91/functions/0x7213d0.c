
void FUN_007213d0(undefined4 *param_1)

{
  undefined4 *in_EAX;
  int *in_EDX;
  
  if (*in_EDX != 0) {
    *in_EAX = *param_1;
    in_EAX[1] = *in_EDX;
    return;
  }
  *in_EAX = 0;
  in_EAX[1] = *in_EDX;
  return;
}

