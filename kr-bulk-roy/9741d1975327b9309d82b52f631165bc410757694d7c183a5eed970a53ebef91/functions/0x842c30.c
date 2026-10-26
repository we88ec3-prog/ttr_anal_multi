
void FUN_00842c30(int param_1,int param_2,float param_3,float param_4,float param_5)

{
  int in_EAX;
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  float *unaff_EDI;
  
  while (param_2 < in_EAX) {
    iVar3 = (in_EAX + -1) / 2;
    pfVar2 = (float *)(iVar3 * 0x50 + param_1);
    if (unaff_EDI[2] * param_5 + *unaff_EDI * param_3 + unaff_EDI[1] * param_4 <=
        pfVar2[2] * param_5 + param_3 * *pfVar2 + pfVar2[1] * param_4) break;
    pfVar1 = (float *)(in_EAX * 0x50 + param_1);
    if (pfVar1 != pfVar2) {
      *pfVar1 = *pfVar2;
      pfVar1[1] = pfVar2[1];
      pfVar1[2] = pfVar2[2];
      if (pfVar1 + 3 != pfVar2 + 3) {
        pfVar1[6] = pfVar2[6];
        pfVar1[3] = pfVar2[3];
        pfVar1[4] = pfVar2[4];
        pfVar1[5] = pfVar2[5];
      }
      pfVar1[7] = pfVar2[7];
      pfVar1[8] = pfVar2[8];
      pfVar1[9] = pfVar2[9];
      pfVar1[10] = pfVar2[10];
    }
    pfVar1[0xb] = pfVar2[0xb];
    pfVar1[0xc] = pfVar2[0xc];
    pfVar1[0xd] = pfVar2[0xd];
    pfVar1[0xe] = pfVar2[0xe];
    pfVar1[0xf] = pfVar2[0xf];
    pfVar1[0x10] = pfVar2[0x10];
    pfVar1[0x11] = pfVar2[0x11];
    pfVar1[0x12] = pfVar2[0x12];
    pfVar1[0x13] = pfVar2[0x13];
    in_EAX = iVar3;
  }
  pfVar2 = (float *)(in_EAX * 0x50 + param_1);
  if (pfVar2 != unaff_EDI) {
    *pfVar2 = *unaff_EDI;
    pfVar2[1] = unaff_EDI[1];
    pfVar2[2] = unaff_EDI[2];
    if (pfVar2 + 3 != unaff_EDI + 3) {
      pfVar2[6] = unaff_EDI[6];
      pfVar2[3] = unaff_EDI[3];
      pfVar2[4] = unaff_EDI[4];
      pfVar2[5] = unaff_EDI[5];
    }
    pfVar2[7] = unaff_EDI[7];
    pfVar2[8] = unaff_EDI[8];
    pfVar2[9] = unaff_EDI[9];
    pfVar2[10] = unaff_EDI[10];
  }
  pfVar2[0xb] = unaff_EDI[0xb];
  pfVar2[0xc] = unaff_EDI[0xc];
  pfVar2[0xd] = unaff_EDI[0xd];
  pfVar2[0xe] = unaff_EDI[0xe];
  pfVar2[0xf] = unaff_EDI[0xf];
  pfVar2[0x10] = unaff_EDI[0x10];
  pfVar2[0x11] = unaff_EDI[0x11];
  pfVar2[0x12] = unaff_EDI[0x12];
  pfVar2[0x13] = unaff_EDI[0x13];
  return;
}

