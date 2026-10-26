
void FUN_00841950(undefined4 *param_1,float *param_2,float *param_3,float param_4,float param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float *local_8;
  
  local_8 = param_2 + (((int)param_3 - (int)param_2) / 0xa0) * 0x14;
  FUN_00841eb0(local_8,param_3 + -0x14,param_4,param_5,param_6);
  pfVar6 = local_8 + 0x14;
  if (param_2 < local_8) {
    pfVar3 = local_8 + -0x12;
    do {
      fVar2 = pfVar3[0x14] * param_6 + *local_8 * param_4 + pfVar3[0x13] * param_5;
      fVar1 = *pfVar3 * param_6 + pfVar3[-2] * param_4 + pfVar3[-1] * param_5;
      if ((fVar1 < fVar2) || (fVar2 < fVar1)) break;
      local_8 = local_8 + -0x14;
      pfVar3 = pfVar3 + -0x14;
    } while (param_2 < local_8);
  }
  pfVar3 = pfVar6;
  pfVar5 = local_8;
  if (pfVar6 < param_3) {
    if (3 < ((int)param_3 + (0x4f - (int)pfVar6)) / 0x50) {
      fVar1 = local_8[2] * param_6 + *local_8 * param_4 + local_8[1] * param_5;
      do {
        fVar2 = pfVar6[2] * param_6 + *pfVar6 * param_4 + pfVar6[1] * param_5;
        pfVar3 = pfVar6;
        if ((fVar2 < fVar1) || (fVar1 < fVar2)) goto joined_r0x00841bb6;
        fVar2 = pfVar6[0x16] * param_6 + pfVar6[0x14] * param_4 + pfVar6[0x15] * param_5;
        if ((fVar2 < fVar1) || (fVar1 < fVar2)) {
          pfVar6 = pfVar6 + 0x14;
          pfVar3 = pfVar6;
          goto joined_r0x00841bb6;
        }
        fVar2 = pfVar6[0x2a] * param_6 + pfVar6[0x28] * param_4 + pfVar6[0x29] * param_5;
        if ((fVar2 < fVar1) || (fVar1 < fVar2)) {
          pfVar6 = pfVar6 + 0x28;
          pfVar3 = pfVar6;
          goto joined_r0x00841bb6;
        }
        fVar2 = pfVar6[0x3e] * param_6 + pfVar6[0x3c] * param_4 + pfVar6[0x3d] * param_5;
        if ((fVar2 < fVar1) || (fVar1 < fVar2)) {
          pfVar6 = pfVar6 + 0x3c;
          pfVar3 = pfVar6;
          goto joined_r0x00841bb6;
        }
        pfVar6 = pfVar6 + 0x50;
      } while ((int)pfVar6 < (int)(param_3 + -0x3c));
    }
    pfVar3 = pfVar6;
    if (pfVar6 < param_3) {
      fVar1 = local_8[2] * param_6 + *local_8 * param_4 + local_8[1] * param_5;
      do {
        fVar2 = pfVar6[2] * param_6 + *pfVar6 * param_4 + pfVar6[1] * param_5;
        pfVar3 = pfVar6;
        if ((fVar2 < fVar1) || (fVar1 < fVar2)) break;
        pfVar6 = pfVar6 + 0x14;
        pfVar3 = pfVar6;
      } while (pfVar6 < param_3);
    }
  }
joined_r0x00841bb6:
  do {
    if (param_3 <= pfVar6) {
LAB_00841c29:
      if (param_2 < local_8) {
        pfVar4 = local_8 + -0x12;
        do {
          fVar2 = pfVar5[2] * param_6 + *pfVar5 * param_4 + pfVar5[1] * param_5;
          fVar1 = *pfVar4 * param_6 + pfVar4[-2] * param_4 + pfVar4[-1] * param_5;
          if (fVar2 <= fVar1) {
            if (fVar2 < fVar1) break;
            pfVar5 = pfVar5 + -0x14;
            FUN_00842710(pfVar5,pfVar4 + -2);
          }
          local_8 = local_8 + -0x14;
          pfVar4 = pfVar4 + -0x14;
        } while (param_2 < local_8);
      }
      if (local_8 == param_2) {
        if (pfVar6 == param_3) {
          param_1[1] = pfVar3;
          *param_1 = pfVar5;
          return;
        }
        if (pfVar3 != pfVar6) {
          FUN_00842710(pfVar5,pfVar3);
        }
        FUN_00842710(pfVar5,pfVar6);
        pfVar6 = pfVar6 + 0x14;
        pfVar3 = pfVar3 + 0x14;
        pfVar5 = pfVar5 + 0x14;
      }
      else {
        local_8 = local_8 + -0x14;
        if (pfVar6 == param_3) {
          pfVar5 = pfVar5 + -0x14;
          if (local_8 != pfVar5) {
            FUN_00842710(local_8,pfVar5);
          }
          FUN_00842710(pfVar5,pfVar3 + -0x14);
          pfVar3 = pfVar3 + -0x14;
        }
        else {
          FUN_00842710(pfVar6,local_8);
          pfVar6 = pfVar6 + 0x14;
        }
      }
      goto joined_r0x00841bb6;
    }
    fVar2 = pfVar6[2] * param_6 + param_4 * *pfVar6 + pfVar6[1] * param_5;
    fVar1 = pfVar5[2] * param_6 + pfVar5[1] * param_5 + *pfVar5 * param_4;
    if (fVar2 <= fVar1) {
      if (fVar2 < fVar1) goto LAB_00841c29;
      FUN_00842710(pfVar3,pfVar6);
      pfVar3 = pfVar3 + 0x14;
    }
    pfVar6 = pfVar6 + 0x14;
  } while( true );
}

