
void FUN_00655f70(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 *in_EAX;
  
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    if (in_EAX != (undefined1 *)0x0) {
      *in_EAX = *param_1;
    }
    in_EAX = in_EAX + 1;
  }
  return;
}

