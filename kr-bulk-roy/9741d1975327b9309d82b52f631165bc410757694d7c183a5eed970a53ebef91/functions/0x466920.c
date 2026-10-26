
bool FUN_00466920(void)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  short *unaff_ESI;
  
  psVar2 = unaff_ESI;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  iVar3 = FUN_0044df20(0,unaff_ESI,(int)psVar2 - (int)(unaff_ESI + 1) >> 1);
  return iVar3 == 0;
}

