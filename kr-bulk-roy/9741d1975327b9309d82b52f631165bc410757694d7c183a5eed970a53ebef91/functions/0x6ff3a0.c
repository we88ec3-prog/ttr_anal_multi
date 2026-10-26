
undefined4 FUN_006ff3a0(void)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  byte *pbVar4;
  uint *unaff_EDI;
  int local_8;
  
  FUN_006fef80(*unaff_EDI);
  iVar2 = *(int *)unaff_EDI[0xe];
  *(int *)unaff_EDI[0xe] = iVar2 + -1;
  if (iVar2 != 0) {
    pbVar4 = *(byte **)(unaff_EDI[0xe] + 4);
    bVar1 = *pbVar4;
    *(byte **)(unaff_EDI[0xe] + 4) = pbVar4 + 1;
    *unaff_EDI = (uint)bVar1;
    return 1;
  }
  piVar3 = (int *)unaff_EDI[0xe];
  pbVar4 = (byte *)(*(code *)piVar3[2])(piVar3[4],piVar3[3],&local_8);
  if ((pbVar4 != (byte *)0x0) && (local_8 != 0)) {
    piVar3[1] = (int)pbVar4;
    *piVar3 = local_8 + -1;
    bVar1 = *pbVar4;
    piVar3[1] = (int)(pbVar4 + 1);
    *unaff_EDI = (uint)bVar1;
    return 1;
  }
  *unaff_EDI = 0xffffffff;
  return 1;
}

