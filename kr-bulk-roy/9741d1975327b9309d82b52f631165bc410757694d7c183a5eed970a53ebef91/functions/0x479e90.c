
void FUN_00479e90(void)

{
  short sVar1;
  short *psVar2;
  undefined4 *in_EAX;
  short *psVar3;
  
  psVar2 = (short *)*in_EAX;
  psVar3 = psVar2;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  FUN_00404300(psVar2,(int)psVar3 - (int)(psVar2 + 1) >> 1);
  return;
}

