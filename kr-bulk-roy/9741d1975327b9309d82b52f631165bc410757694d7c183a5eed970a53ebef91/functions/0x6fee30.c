
uint FUN_006fee30(void)

{
  byte bVar1;
  byte *pbVar2;
  int *unaff_ESI;
  int local_8;
  
  if (*unaff_ESI != 0) {
LAB_006fee78:
    return (uint)*(byte *)unaff_ESI[1];
  }
  pbVar2 = (byte *)(*(code *)unaff_ESI[2])(unaff_ESI[4],unaff_ESI[3],&local_8);
  if ((pbVar2 != (byte *)0x0) && (local_8 != 0)) {
    unaff_ESI[1] = (int)pbVar2;
    *unaff_ESI = local_8 + -1;
    bVar1 = *pbVar2;
    unaff_ESI[1] = (int)(pbVar2 + 1);
    if (bVar1 != 0xffffffff) {
      *unaff_ESI = local_8;
      unaff_ESI[1] = (int)pbVar2;
      goto LAB_006fee78;
    }
  }
  return 0xffffffff;
}

