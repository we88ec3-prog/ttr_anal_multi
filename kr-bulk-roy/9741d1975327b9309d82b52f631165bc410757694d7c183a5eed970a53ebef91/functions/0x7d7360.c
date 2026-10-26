
void FUN_007d7360(float *param_1,float *param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  float fVar2;
  char cVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined4 in_EAX;
  char *pcVar8;
  char *in_ECX;
  undefined4 *unaff_ESI;
  float *unaff_EDI;
  
  *unaff_ESI = in_EAX;
  unaff_ESI[1] = *param_1;
  unaff_ESI[2] = param_1[1];
  unaff_ESI[3] = param_1[2];
  unaff_ESI[4] = *param_2;
  unaff_ESI[5] = param_2[1];
  unaff_ESI[6] = param_2[2];
  pcVar8 = in_ECX;
  do {
    cVar3 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar3 != '\0');
  FUN_00402a70(in_ECX,(int)pcVar8 - (int)(in_ECX + 1));
  fVar4 = param_2[1] * unaff_EDI[2] - param_2[2] * unaff_EDI[1];
  fVar5 = param_2[2] * *unaff_EDI - unaff_EDI[2] * *param_2;
  fVar6 = unaff_EDI[1] * *param_2 - param_2[1] * *unaff_EDI;
  fVar7 = unaff_EDI[2] * param_1[2] + *param_1 * *unaff_EDI + unaff_EDI[1] * param_1[1];
  fVar1 = unaff_EDI[1];
  fVar2 = unaff_EDI[2];
  unaff_ESI[0x12] = *unaff_EDI;
  unaff_ESI[0x13] = fVar1;
  unaff_ESI[0x14] = fVar2;
  unaff_ESI[0x15] = param_3 * 0.5 - fVar7;
  fVar1 = unaff_EDI[1];
  fVar2 = unaff_EDI[2];
  unaff_ESI[0x16] = -*unaff_EDI;
  unaff_ESI[0x17] = -fVar1;
  unaff_ESI[0x18] = -fVar2;
  unaff_ESI[0x19] = fVar7 + param_3 * 0.5;
  fVar1 = fVar5 * param_1[1] + fVar4 * *param_1 + fVar6 * param_1[2];
  unaff_ESI[0x1a] = fVar4;
  unaff_ESI[0x1b] = fVar5;
  unaff_ESI[0x1c] = fVar6;
  unaff_ESI[0x1d] = param_4 * 0.5 - fVar1;
  unaff_ESI[0x1e] = -fVar4;
  unaff_ESI[0x1f] = -fVar5;
  unaff_ESI[0x20] = -fVar6;
  unaff_ESI[0x21] = fVar1 + param_4 * 0.5;
  fVar7 = param_2[2] * param_1[2] + *param_1 * *param_2 + param_2[1] * param_1[1];
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  unaff_ESI[0x22] = -*param_2;
  unaff_ESI[0x23] = -fVar1;
  unaff_ESI[0x24] = -fVar2;
  unaff_ESI[0x25] = param_5 + fVar7;
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  unaff_ESI[0x26] = *param_2;
  unaff_ESI[0x27] = fVar1;
  unaff_ESI[0x28] = fVar2;
  unaff_ESI[0x2a] = 0;
  unaff_ESI[0x29] = param_5 - fVar7;
  unaff_ESI[0x2b] = 0;
  unaff_ESI[10] = *unaff_EDI;
  unaff_ESI[0xb] = unaff_EDI[1];
  fVar1 = unaff_EDI[2];
  unaff_ESI[0xd] = fVar4;
  unaff_ESI[0xc] = fVar1;
  unaff_ESI[0xe] = fVar5;
  unaff_ESI[0xf] = fVar6;
  unaff_ESI[7] = *param_1;
  unaff_ESI[8] = param_1[1];
  fVar1 = param_1[2];
  unaff_ESI[0x10] = param_3;
  unaff_ESI[9] = fVar1;
  unaff_ESI[0x11] = param_4;
  return;
}

