
void FUN_00750720(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  int iVar3;
  int *unaff_ESI;
  
  iVar2 = in_EAX[1];
  iVar3 = in_EAX[2];
  *unaff_ESI = *in_EAX;
  iVar1 = in_EAX[3];
  unaff_ESI[1] = iVar2;
  unaff_ESI[2] = iVar3;
  unaff_ESI[3] = iVar1;
  iVar2 = FUN_008fed10();
  iVar3 = FUN_008fed10();
  if (iVar2 < in_EAX[2] + 0x14) {
    iVar2 = *in_EAX;
    iVar1 = in_EAX[2];
    param_2 = (iVar2 - iVar1) + -0x14 + param_2;
    *unaff_ESI = param_2;
    unaff_ESI[2] = param_2 + (iVar1 - iVar2);
  }
  else {
    *unaff_ESI = *unaff_ESI + 0x14;
    unaff_ESI[2] = unaff_ESI[2] + 0x14;
  }
  if (iVar3 < in_EAX[3] + 0x14) {
    iVar2 = in_EAX[1];
    iVar3 = in_EAX[3];
    param_3 = (iVar2 - iVar3) + -0x14 + param_3;
    unaff_ESI[1] = param_3;
    unaff_ESI[3] = param_3 + (iVar3 - iVar2);
    return;
  }
  unaff_ESI[1] = unaff_ESI[1] + 0x14;
  unaff_ESI[3] = unaff_ESI[3] + 0x14;
  return;
}

