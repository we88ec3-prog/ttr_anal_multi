
void FUN_007e9bc0(undefined4 *param_1)

{
  undefined4 *in_EAX;
  undefined4 *in_EDX;
  
  for (; param_1 != in_EDX; param_1 = (undefined4 *)((int)param_1 + 6)) {
    if (in_EAX != (undefined4 *)0x0) {
      *in_EAX = *param_1;
      *(undefined2 *)(in_EAX + 1) = *(undefined2 *)(param_1 + 1);
    }
    in_EAX = (undefined4 *)((int)in_EAX + 6);
  }
  return;
}

