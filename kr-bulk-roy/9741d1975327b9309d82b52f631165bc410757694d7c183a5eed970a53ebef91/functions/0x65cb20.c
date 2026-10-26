
void FUN_0065cb20(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *in_EAX;
  
  for (; param_1 != param_2; param_1 = param_1 + 5) {
    if (in_EAX != (undefined4 *)0x0) {
      *in_EAX = *param_1;
      in_EAX[1] = param_1[1];
      in_EAX[2] = param_1[2];
      in_EAX[3] = param_1[3];
      in_EAX[4] = param_1[4];
    }
    in_EAX = in_EAX + 5;
  }
  return;
}

