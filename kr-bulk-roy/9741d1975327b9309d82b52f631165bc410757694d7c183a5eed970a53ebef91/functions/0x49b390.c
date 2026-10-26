
void FUN_0049b390(void)

{
  int iVar1;
  float fVar2;
  DWORD DVar3;
  uint uVar4;
  int *unaff_ESI;
  
  DVar3 = timeGetTime();
  *unaff_ESI = *unaff_ESI + 1;
  iVar1 = *unaff_ESI;
  uVar4 = DVar3 - unaff_ESI[1];
  unaff_ESI[2] = DVar3;
  if (999 < uVar4) {
    fVar2 = (float)(int)uVar4;
    if ((int)uVar4 < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    *unaff_ESI = 0;
    unaff_ESI[1] = DVar3;
    unaff_ESI[6] = (int)((float)(iVar1 * 1000) / fVar2);
    FUN_00440830("%3.1f / %3.1f (%3.1f)",(double)(float)unaff_ESI[6],(double)(float)unaff_ESI[7],
                 (double)(float)unaff_ESI[0x1b]);
  }
  return;
}

