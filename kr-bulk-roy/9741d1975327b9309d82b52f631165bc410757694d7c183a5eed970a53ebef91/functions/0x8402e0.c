
void FUN_008402e0(int *param_1,int *param_2,int *param_3)

{
  undefined4 *in_EAX;
  
  if (param_1 == param_2) {
    *in_EAX = param_1;
    return;
  }
  do {
    if (*param_1 == *param_3) break;
    param_1 = param_1 + 1;
  } while (param_1 != param_2);
  *in_EAX = param_1;
  return;
}

