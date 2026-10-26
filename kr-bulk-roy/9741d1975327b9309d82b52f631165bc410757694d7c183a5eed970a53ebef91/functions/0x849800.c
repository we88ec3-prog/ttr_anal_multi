
void FUN_00849800(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 *in_EAX;
  undefined4 in_ECX;
  
  in_EAX[1] = 0x3f800000;
  in_EAX[2] = 0x3f800000;
  in_EAX[3] = 0x3f800000;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  in_EAX[6] = 0;
  *in_EAX = in_ECX;
  in_EAX[7] = param_7;
  in_EAX[4] = param_4;
  in_EAX[5] = param_5;
  in_EAX[1] = param_1;
  in_EAX[6] = param_6;
  in_EAX[2] = param_2;
  in_EAX[3] = param_3;
  in_EAX[8] = 1;
  return;
}

