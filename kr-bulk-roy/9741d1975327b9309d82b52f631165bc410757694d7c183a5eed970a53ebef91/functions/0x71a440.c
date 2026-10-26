
int FUN_0071a440(int *param_1)

{
  int iVar1;
  int *unaff_ESI;
  uint unaff_EDI;
  
  iVar1 = FUN_0071a3e0(unaff_ESI);
  if (iVar1 == 0) {
    return 0;
  }
  if (unaff_EDI < 0x2001) {
    *(int *)(*unaff_ESI + 0x10) = unaff_ESI[1];
    *(int *)(iVar1 + 8) = *unaff_ESI;
    *(int *)(*unaff_ESI + 0xc) = iVar1;
    *unaff_ESI = iVar1;
    unaff_ESI[1] = unaff_EDI;
    *(uint *)(iVar1 + 0x10) = unaff_EDI;
    *param_1 = iVar1;
    return iVar1 + 0x18;
  }
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(*unaff_ESI + 8);
  *(int *)(iVar1 + 0xc) = *unaff_ESI;
  *(int *)(*(int *)(*unaff_ESI + 8) + 0xc) = iVar1;
  *(int *)(*unaff_ESI + 8) = iVar1;
  *(uint *)(iVar1 + 0x10) = unaff_EDI;
  *param_1 = iVar1;
  return iVar1 + 0x18;
}

