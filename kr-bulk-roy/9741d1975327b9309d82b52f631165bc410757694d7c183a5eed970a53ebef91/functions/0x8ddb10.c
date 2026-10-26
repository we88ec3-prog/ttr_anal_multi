
void FUN_008ddb10(void)

{
  int iVar1;
  undefined4 uVar2;
  int *unaff_ESI;
  
  iVar1 = *unaff_ESI;
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x1c);
    if (unaff_ESI[7] != 0) {
      FUN_008bab90(iVar1,unaff_ESI + 7);
    }
    FUN_008b9f80(uVar2,unaff_ESI[6]);
    unaff_ESI[6] = 0;
    *unaff_ESI = 0;
    unaff_ESI[1] = 0;
    unaff_ESI[2] = 0;
    unaff_ESI[3] = 0;
    unaff_ESI[4] = 0;
    unaff_ESI[5] = 0;
    unaff_ESI[6] = 0;
    unaff_ESI[7] = 0;
  }
  return;
}

