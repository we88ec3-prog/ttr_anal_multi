
void FUN_007da4d0(undefined4 param_1,float param_2)

{
  int iVar1;
  float fVar2;
  int in_ECX;
  float *pfVar3;
  int iVar4;
  uint uVar5;
  float10 fVar6;
  float local_10;
  
  local_10 = 0.0;
  iVar1 = *(int *)(in_ECX + 0xc0);
  uVar5 = 0;
  if (iVar1 != *(int *)(in_ECX + 0xc4)) {
    fVar2 = *(float *)(iVar1 + 0x10) + *(float *)(iVar1 + 0xc);
    if (fVar2 < param_2) {
      iVar4 = 0;
      pfVar3 = (float *)(*(int *)(in_ECX + 0xc0) + 0xc);
      do {
        if (uVar5 < (*(int *)(in_ECX + 0xc4) - iVar1) / 0x14 - 1U) {
          local_10 = *(float *)(iVar4 + 0x1c + *(int *)(in_ECX + 0xc0));
          iVar4 = iVar4 + 0x14;
          uVar5 = uVar5 + 1;
          pfVar3 = pfVar3 + 5;
        }
        fVar2 = pfVar3[1] + *pfVar3 + fVar2;
      } while (fVar2 < param_2);
    }
    fVar6 = (float10)FUN_007d9630();
    if ((float10)param_2 <= fVar6) {
      param_2 = param_2 + local_10;
    }
  }
  FUN_007da460(param_2);
  return;
}

