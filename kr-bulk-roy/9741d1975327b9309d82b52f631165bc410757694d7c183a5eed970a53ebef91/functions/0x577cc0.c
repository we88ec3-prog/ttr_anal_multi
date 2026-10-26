
void FUN_00577cc0(float param_1)

{
  float fVar1;
  int in_EAX;
  float *pfVar2;
  int iVar3;
  
  pfVar2 = (float *)(in_EAX + 0x18);
  iVar3 = 3;
  do {
    fVar1 = *pfVar2 - pfVar2[1] * param_1;
    *pfVar2 = fVar1;
    if (fVar1 <= 0.0) {
      *pfVar2 = fVar1 + 192.0;
    }
    pfVar2[3] = (float)(int)*pfVar2;
    pfVar2[5] = (float)((int)*pfVar2 + 0x5e);
    pfVar2 = pfVar2 + 7;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

