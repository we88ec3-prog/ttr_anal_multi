
void FUN_008422a0(float *param_1,float *param_2,float param_3,float param_4,float param_5)

{
  float *pfVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float local_60 [4];
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  
  pfVar1 = param_1;
  if (param_1 != param_2) {
    while (pfVar1 = pfVar1 + 0x14, pfVar1 != param_2) {
      pfVar4 = pfVar1;
      pfVar3 = local_60;
      for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pfVar3 = *pfVar4;
        pfVar4 = pfVar4 + 1;
        pfVar3 = pfVar3 + 1;
      }
      local_10 = local_60[2] * param_5 + param_4 * local_60[1] + local_60[0] * param_3;
      local_c = param_5 * param_1[2] + param_4 * param_1[1] + *param_1 * param_3;
      if (local_c <= local_10) {
        pfVar3 = pfVar1 + 4;
        pfVar4 = pfVar1;
        while (local_10 <
               pfVar3[-0x16] * param_5 + pfVar3[-0x18] * param_3 + pfVar3[-0x17] * param_4) {
          if (pfVar4 != pfVar3 + -0x18) {
            *pfVar4 = pfVar3[-0x18];
            pfVar4[1] = pfVar3[-0x17];
            pfVar4[2] = pfVar3[-0x16];
            if (pfVar4 + 3 != pfVar3 + -0x15) {
              pfVar4[6] = pfVar3[-0x12];
              pfVar4[3] = pfVar3[-0x15];
              pfVar4[4] = pfVar3[-0x14];
              pfVar4[5] = pfVar3[-0x13];
            }
            pfVar4[7] = pfVar3[-0x11];
            pfVar4[8] = pfVar3[-0x10];
            pfVar4[9] = pfVar3[-0xf];
            pfVar4[10] = pfVar3[-0xe];
          }
          pfVar4[0xb] = pfVar3[-0xd];
          pfVar4[0xc] = pfVar3[-0xc];
          pfVar4[0xd] = pfVar3[-0xb];
          pfVar4[0xe] = pfVar3[-10];
          pfVar4[0xf] = pfVar3[-9];
          pfVar4[0x10] = pfVar3[-8];
          pfVar4[0x11] = pfVar3[-7];
          pfVar4[0x12] = pfVar3[-6];
          pfVar4[0x13] = pfVar3[-5];
          pfVar4 = pfVar3 + -0x18;
          pfVar3 = pfVar3 + -0x14;
        }
        if (pfVar4 != local_60) {
          *pfVar4 = local_60[0];
          pfVar4[1] = local_60[1];
          pfVar4[2] = local_60[2];
          if (pfVar4 + 3 != local_60 + 3) {
            pfVar4[6] = local_48;
            pfVar4[3] = local_60[3];
            pfVar4[4] = local_50;
            pfVar4[5] = local_4c;
          }
          pfVar4[7] = local_44;
          pfVar4[8] = local_40;
          pfVar4[9] = local_3c;
          pfVar4[10] = local_38;
        }
        pfVar4[0xf] = local_24;
        pfVar4[0xb] = local_34;
        pfVar4[0xc] = local_30;
        pfVar4[0xd] = local_2c;
        pfVar4[0xe] = local_28;
        pfVar4[0x10] = local_20;
        pfVar4[0x11] = local_1c;
        pfVar4[0x12] = local_18;
        pfVar4[0x13] = local_14;
      }
      else {
        FUN_00842de0(param_1,param_2);
        if (param_1 != local_60) {
          *param_1 = local_60[0];
          param_1[1] = local_60[1];
          param_1[2] = local_60[2];
          if (param_1 + 3 != local_60 + 3) {
            param_1[6] = local_48;
            param_1[3] = local_60[3];
            param_1[4] = local_50;
            param_1[5] = local_4c;
          }
          param_1[7] = local_44;
          param_1[8] = local_40;
          param_1[9] = local_3c;
          param_1[10] = local_38;
        }
        param_1[0xf] = local_24;
        param_1[0xb] = local_34;
        param_1[0xc] = local_30;
        param_1[0xd] = local_2c;
        param_1[0xe] = local_28;
        param_1[0x10] = local_20;
        param_1[0x11] = local_1c;
        param_1[0x12] = local_18;
        param_1[0x13] = local_14;
      }
    }
  }
  return;
}

