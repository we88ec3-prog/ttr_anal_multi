
void FUN_005591d0(float param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float *in_ECX;
  float unaff_ESI;
  
  in_ECX[3] = param_1;
  *in_ECX = param_2;
  in_ECX[1] = param_3;
  fVar2 = (float)((int)param_1 / 2) + 120.0;
  in_ECX[5] = (float)((int)unaff_ESI + -0x11c);
  in_ECX[7] = (float)((int)unaff_ESI + -0x11c);
  in_ECX[6] = fVar2;
  fVar1 = (float)((int)param_1 / 2) - 120.0;
  in_ECX[8] = fVar2;
  in_ECX[0xf] = (float)((int)unaff_ESI + -0x200);
  in_ECX[0x11] = (float)((int)unaff_ESI + -0x200);
  in_ECX[0x10] = fVar1;
  in_ECX[0x12] = fVar1;
  in_ECX[2] = unaff_ESI;
  fVar1 = (float)((int)unaff_ESI / 2) - param_2 * 384.0;
  in_ECX[0x1f] = fVar1;
  in_ECX[0x21] = fVar1;
  fVar1 = (float)(int)param_1 - param_3 * 197.0;
  in_ECX[0x20] = fVar1;
  in_ECX[0x22] = fVar1;
  return;
}

