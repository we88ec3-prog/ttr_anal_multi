
void FUN_008eb6e0(void)

{
  int iVar1;
  int *unaff_ESI;
  
  iVar1 = *unaff_ESI;
  if (iVar1 != 0) {
    FUN_008b9f80(iVar1,unaff_ESI[7]);
    unaff_ESI[7] = 0;
    FUN_008b9f80(iVar1,unaff_ESI[6]);
    unaff_ESI[6] = 0;
    FUN_008b9f80(iVar1,unaff_ESI[4]);
    unaff_ESI[4] = 0;
    FUN_008b9f80(iVar1,unaff_ESI[3]);
    unaff_ESI[3] = 0;
    FUN_008b9f80(iVar1,unaff_ESI[5]);
    unaff_ESI[5] = 0;
    unaff_ESI[2] = 0;
    unaff_ESI[1] = 0;
    *unaff_ESI = 0;
  }
  return;
}

