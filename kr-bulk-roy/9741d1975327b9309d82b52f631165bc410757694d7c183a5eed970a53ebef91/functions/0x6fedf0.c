
uint FUN_006fedf0(void)

{
  byte bVar1;
  byte *pbVar2;
  int *unaff_ESI;
  int local_8;
  
  pbVar2 = (byte *)(*(code *)unaff_ESI[2])(unaff_ESI[4],unaff_ESI[3],&local_8);
  if ((pbVar2 != (byte *)0x0) && (local_8 != 0)) {
    unaff_ESI[1] = (int)pbVar2;
    *unaff_ESI = local_8 + -1;
    bVar1 = *pbVar2;
    unaff_ESI[1] = (int)(pbVar2 + 1);
    return (uint)bVar1;
  }
  return 0xffffffff;
}

