
void FUN_00695c20(undefined2 *param_1,undefined2 *param_2)

{
  undefined2 *in_EAX;
  
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    if (in_EAX != (undefined2 *)0x0) {
      *in_EAX = *param_1;
    }
    in_EAX = in_EAX + 1;
  }
  return;
}

