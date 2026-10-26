
void FUN_00849730(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  undefined4 *in_EAX;
  undefined4 in_ECX;
  
  in_EAX[1] = 0x3f800000;
  in_EAX[2] = 0x3f800000;
  in_EAX[3] = 0x3f800000;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  in_EAX[6] = 0;
  in_EAX[7] = 0;
  in_EAX[8] = 0;
  in_EAX[9] = 0;
  in_EAX[1] = param_1;
  in_EAX[10] = param_10;
  *in_EAX = in_ECX;
  in_EAX[0xb] = param_11;
  in_EAX[2] = param_2;
  in_EAX[0xc] = param_12;
  in_EAX[3] = param_3;
  in_EAX[4] = param_4;
  in_EAX[5] = param_5;
  in_EAX[7] = param_7;
  in_EAX[6] = param_6;
  in_EAX[8] = param_8;
  in_EAX[9] = param_9;
  in_EAX[0xd] = 1;
  return;
}

