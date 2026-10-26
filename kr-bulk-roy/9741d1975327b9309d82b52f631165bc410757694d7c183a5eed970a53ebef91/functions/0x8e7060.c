
bool FUN_008e7060(int *param_1,int *param_2,char param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int *unaff_ESI;
  
  pbVar1 = (byte *)unaff_ESI[2];
  (*(code *)unaff_ESI[7])();
  if (((byte *)*unaff_ESI < pbVar1) && (*(byte *)*unaff_ESI - 0x30 < 10)) {
    iVar3 = (*(code *)unaff_ESI[9])();
    (*(code *)unaff_ESI[8])();
    iVar2 = *unaff_ESI;
    *param_2 = iVar2 + 1;
    if ((-1 < iVar3) && (iVar3 < (int)pbVar1 - (iVar2 + 1))) {
      *unaff_ESI = *unaff_ESI + iVar3 + 1;
      *param_1 = iVar3;
      return unaff_ESI[3] == 0;
    }
  }
  if (param_3 == '\0') {
    unaff_ESI[3] = 3;
  }
  return false;
}

