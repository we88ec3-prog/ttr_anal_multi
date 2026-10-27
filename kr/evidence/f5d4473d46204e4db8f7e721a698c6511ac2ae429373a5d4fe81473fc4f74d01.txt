
undefined4 FUN_00838860(float param_1,float param_2,float param_3,float param_4)

{
  uint uVar1;
  int in_EDX;
  float *pfVar2;
  
  uVar1 = 0;
  pfVar2 = (float *)(in_EDX + 8);
  do {
    if (param_4 < *pfVar2 * param_3 + pfVar2[-1] * param_2 + pfVar2[-2] * param_1 + pfVar2[1]) {
      return 0;
    }
    uVar1 = uVar1 + 1;
    pfVar2 = pfVar2 + 4;
  } while (uVar1 < 6);
  return 1;
}

