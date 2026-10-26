
void FUN_008d9440(char param_1)

{
  int iVar1;
  int *in_EAX;
  int *in_ECX;
  
  *in_EAX = in_ECX[3];
  in_EAX[1] = in_ECX[2];
  in_EAX[2] = in_ECX[1];
  iVar1 = *in_ECX;
  in_EAX[4] = in_EAX[2] * iVar1;
  in_EAX[3] = iVar1;
  if (param_1 == '\0') {
    *in_EAX = *in_EAX + (*in_ECX + -1) * in_EAX[1];
    in_EAX[1] = -in_EAX[1];
  }
  return;
}

