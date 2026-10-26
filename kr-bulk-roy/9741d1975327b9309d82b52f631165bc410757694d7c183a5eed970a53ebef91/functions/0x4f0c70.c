
void FUN_004f0c70(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  
  *in_EAX = 0;
  in_EAX[1] = 0;
  if (in_ECX != (undefined4 *)0x0) {
    *in_EAX = *in_ECX;
    in_EAX[2] = param_3;
    return;
  }
  in_EAX[2] = param_3;
  return;
}

