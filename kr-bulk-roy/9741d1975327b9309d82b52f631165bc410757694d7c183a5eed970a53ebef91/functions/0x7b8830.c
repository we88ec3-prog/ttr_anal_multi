
void FUN_007b8830(undefined4 *param_1)

{
  int in_EAX;
  undefined4 *in_EDX;
  
  for (; in_EAX != 0; in_EAX = in_EAX + -1) {
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = *in_EDX;
    }
    param_1 = param_1 + 1;
  }
  return;
}

