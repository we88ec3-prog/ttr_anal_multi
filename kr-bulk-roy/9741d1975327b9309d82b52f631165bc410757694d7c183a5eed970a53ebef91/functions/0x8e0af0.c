
void FUN_008e0af0(undefined4 param_1)

{
  undefined4 *in_EAX;
  undefined4 in_EDX;
  
  in_EAX[2] = 0;
  in_EAX[4] = 0;
  in_EAX[7] = 0;
  in_EAX[5] = param_1;
  in_EAX[6] = in_EDX;
  *in_EAX = FUN_008e0a20;
  in_EAX[1] = FUN_008e0a40;
  in_EAX[3] = FUN_008e0a80;
  return;
}

