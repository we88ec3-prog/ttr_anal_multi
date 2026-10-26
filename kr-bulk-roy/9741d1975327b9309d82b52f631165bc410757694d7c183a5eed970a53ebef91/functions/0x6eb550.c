
void FUN_006eb550(double *param_1,double *param_2,float *param_3)

{
  uint uVar1;
  int iVar3;
  int unaff_ESI;
  float10 fVar4;
  uint local_18;
  int iStack_14;
  float fStack_c;
  uint uVar2;
  
  uVar1 = *(uint *)(unaff_ESI + 0x10);
  iVar3 = *(int *)(unaff_ESI + 0x14);
  if (*(uint *)(unaff_ESI + 0x10) == 0 && *(int *)(unaff_ESI + 0x14) == 0) {
    FUN_006eb3c0(&local_18);
    uVar1 = local_18;
    iVar3 = iStack_14;
  }
  iStack_14 = iVar3;
  local_18 = uVar1;
  fVar4 = (float10)*(longlong *)(unaff_ESI + 8);
  uVar1 = *(uint *)(unaff_ESI + 0x18);
  uVar2 = *(uint *)(unaff_ESI + 0x18);
  iVar3 = *(int *)(unaff_ESI + 0x1c);
  *(uint *)(unaff_ESI + 0x18) = local_18;
  *(int *)(unaff_ESI + 0x1c) = iStack_14;
  fStack_c = (float)((float10)CONCAT44((iStack_14 - iVar3) - (uint)(local_18 < uVar1),
                                       local_18 - uVar2) / fVar4);
  if (fStack_c < 0.0) {
    fStack_c = 0.0;
  }
  uVar1 = *(uint *)(unaff_ESI + 0x20);
  uVar2 = *(uint *)(unaff_ESI + 0x20);
  iVar3 = *(int *)(unaff_ESI + 0x24);
  *param_2 = (double)((float10)CONCAT44(iStack_14,local_18) / fVar4);
  *param_1 = (double)((float10)CONCAT44((iStack_14 - iVar3) - (uint)(local_18 < uVar1),
                                        local_18 - uVar2) / fVar4);
  *param_3 = fStack_c;
  return;
}

