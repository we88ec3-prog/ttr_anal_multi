
undefined4 FUN_007392e0(int *param_1,int param_2,float *param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int *unaff_ESI;
  int unaff_EDI;
  
  iVar4 = *(int *)(unaff_EDI + 0x14) - *(int *)(unaff_EDI + 0x10);
  iVar3 = iVar4 >> 0x1f;
  iVar4 = iVar4 / 0x24 + iVar3;
  if ((iVar4 != iVar3) && (in_ECX <= iVar4 - iVar3)) {
    iVar4 = in_ECX * 0x24;
    piVar1 = (int *)(*(int *)(unaff_EDI + 0x10) + iVar4);
    iVar2 = param_2 / piVar1[2];
    param_2 = param_2 % piVar1[2];
    *unaff_ESI = piVar1[4] * param_2 + *piVar1;
    iVar3 = *(int *)(unaff_EDI + 0x10) + iVar4;
    unaff_ESI[1] = *(int *)(iVar3 + 0x14) * iVar2 + *(int *)(iVar3 + 4);
    unaff_ESI[2] = (param_2 + 1) * *(int *)(*(int *)(unaff_EDI + 0x10) + 0x10 + iVar4) +
                   *(int *)(*(int *)(unaff_EDI + 0x10) + iVar4);
    iVar3 = iVar4 + *(int *)(unaff_EDI + 0x10);
    unaff_ESI[3] = (iVar2 + 1) * *(int *)(iVar3 + 0x14) + *(int *)(iVar3 + 4);
    if (param_1[3] != -1) {
      if (0 < *param_1) {
        *unaff_ESI = *unaff_ESI + *param_1;
      }
      if (param_1[2] + *unaff_ESI <= unaff_ESI[2]) {
        unaff_ESI[2] = param_1[2] + *unaff_ESI;
      }
      iVar3 = param_1[1];
      if (0 < iVar3) {
        unaff_ESI[1] = unaff_ESI[1] + iVar3;
      }
      if (param_1[3] + unaff_ESI[1] <= unaff_ESI[3]) {
        unaff_ESI[3] = param_1[3] + unaff_ESI[1];
      }
      *param_3 = (float)*param_1 + *param_3;
      param_3[1] = (float)param_1[1] + param_3[1];
    }
    iVar4 = iVar4 + *(int *)(unaff_EDI + 0x10);
    *param_4 = *(undefined4 *)(iVar4 + 0x18);
    param_4[1] = *(undefined4 *)(iVar4 + 0x1c);
    param_4[2] = 0;
    return 1;
  }
  return 0;
}

