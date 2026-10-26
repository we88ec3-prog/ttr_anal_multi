
void FUN_005f96c0(undefined2 *param_1)

{
  undefined2 *in_EAX;
  undefined2 *in_EDX;
  
  for (; param_1 != in_EDX; param_1 = param_1 + 2) {
    if (in_EAX != (undefined2 *)0x0) {
      *in_EAX = *param_1;
      in_EAX[1] = param_1[1];
    }
    in_EAX = in_EAX + 2;
  }
  return;
}

