
void FUN_00853960(int param_1)

{
  undefined4 *in_EAX;
  
  for (; param_1 != 0; param_1 = param_1 + -1) {
    if (in_EAX != (undefined4 *)0x0) {
      *in_EAX = 0;
      in_EAX[1] = 0;
      in_EAX[2] = 0;
      in_EAX[3] = 0;
      in_EAX[4] = 0;
    }
    in_EAX = in_EAX + 5;
  }
  return;
}

