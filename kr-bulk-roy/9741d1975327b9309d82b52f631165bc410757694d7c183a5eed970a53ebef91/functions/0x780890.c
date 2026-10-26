
void FUN_00780890(void)

{
  int iVar1;
  int iVar2;
  float *in_ECX;
  float *unaff_ESI;
  uint uVar3;
  float10 fVar4;
  int local_14 [4];
  
  local_14[3] = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14[0] = 1;
  local_14[1] = 2;
  local_14[2] = 0;
  if (*unaff_ESI + unaff_ESI[4] + unaff_ESI[8] <= 0.0) {
    uVar3 = (uint)(*unaff_ESI < unaff_ESI[4]);
    if (unaff_ESI[uVar3 * 4] < unaff_ESI[8]) {
      uVar3 = 2;
    }
    iVar1 = local_14[uVar3];
    fVar4 = (float10)FUN_004ad080((unaff_ESI[uVar3 * 4] -
                                  (unaff_ESI[local_14[iVar1] * 4] + unaff_ESI[iVar1 * 4])) + 1.0);
    in_ECX[uVar3] = (float)(fVar4 * (float10)0.5);
    if (fVar4 != (float10)0) {
      fVar4 = (float10)0.5 / fVar4;
    }
    iVar2 = local_14[iVar1];
    in_ECX[3] = (float)(((float10)unaff_ESI[iVar1 * 3 + iVar2] -
                        (float10)unaff_ESI[iVar2 * 3 + iVar1]) * fVar4);
    in_ECX[iVar1] =
         (float)(((float10)unaff_ESI[uVar3 * 3 + iVar1] + (float10)unaff_ESI[iVar1 * 3 + uVar3]) *
                fVar4);
    in_ECX[iVar2] =
         (float)(((float10)unaff_ESI[uVar3 * 3 + iVar2] + (float10)unaff_ESI[iVar2 * 3 + uVar3]) *
                fVar4);
    __security_check_cookie(local_14[3] ^ (uint)&stack0xfffffffc);
    return;
  }
  fVar4 = (float10)FUN_008ff870();
  in_ECX[3] = (float)(fVar4 * (float10)0.5);
  fVar4 = (float10)0.5 / fVar4;
  *in_ECX = (float)(((float10)unaff_ESI[5] - (float10)unaff_ESI[7]) * fVar4);
  in_ECX[1] = (float)(((float10)unaff_ESI[6] - (float10)unaff_ESI[2]) * fVar4);
  in_ECX[2] = (float)(((float10)unaff_ESI[1] - (float10)unaff_ESI[3]) * fVar4);
  __security_check_cookie(local_14[3] ^ (uint)&stack0xfffffffc);
  return;
}

