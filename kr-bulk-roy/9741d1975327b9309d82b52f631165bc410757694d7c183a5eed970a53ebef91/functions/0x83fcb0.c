
void FUN_0083fcb0(undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *in_EAX;
  
  if (param_2 != param_3) {
    do {
      if (*param_2 == *in_EAX) break;
      param_2 = param_2 + 1;
    } while (param_2 != param_3);
  }
  piVar1 = param_2;
  if (param_2 == param_3) {
    *param_1 = param_2;
    return;
  }
  while (piVar1 = piVar1 + 1, piVar1 != param_3) {
    if (*piVar1 != *in_EAX) {
      *param_2 = *piVar1;
      param_2 = param_2 + 1;
    }
  }
  *param_1 = param_2;
  return;
}

