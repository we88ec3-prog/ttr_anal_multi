
int FUN_006ff660(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  uint *unaff_ESI;
  int local_8;
  
  uVar1 = *unaff_ESI;
  iVar6 = 0;
  FUN_006fef80(uVar1);
  iVar2 = *(int *)unaff_ESI[0xe];
  *(int *)unaff_ESI[0xe] = iVar2 + -1;
  if (iVar2 == 0) {
    piVar3 = (int *)unaff_ESI[0xe];
    pbVar4 = (byte *)(*(code *)piVar3[2])(piVar3[4],piVar3[3],&local_8);
    if ((pbVar4 == (byte *)0x0) || (local_8 == 0)) {
      uVar5 = 0xffffffff;
    }
    else {
      piVar3[1] = (int)pbVar4;
      *piVar3 = local_8 + -1;
      uVar5 = (uint)*pbVar4;
      piVar3[1] = (int)(pbVar4 + 1);
    }
  }
  else {
    pbVar4 = *(byte **)(unaff_ESI[0xe] + 4);
    uVar5 = (uint)*pbVar4;
    *(byte **)(unaff_ESI[0xe] + 4) = pbVar4 + 1;
  }
  *unaff_ESI = uVar5;
  while (uVar5 == 0x3d) {
    FUN_006fef80(*unaff_ESI);
    iVar2 = *(int *)unaff_ESI[0xe];
    *(int *)unaff_ESI[0xe] = iVar2 + -1;
    if (iVar2 == 0) {
      piVar3 = (int *)unaff_ESI[0xe];
      pbVar4 = (byte *)(*(code *)piVar3[2])(piVar3[4],piVar3[3],&local_8);
      if ((pbVar4 == (byte *)0x0) || (local_8 == 0)) {
        uVar5 = 0xffffffff;
      }
      else {
        piVar3[1] = (int)pbVar4;
        *piVar3 = local_8 + -1;
        uVar5 = (uint)*pbVar4;
        piVar3[1] = (int)(pbVar4 + 1);
      }
    }
    else {
      pbVar4 = *(byte **)(unaff_ESI[0xe] + 4);
      uVar5 = (uint)*pbVar4;
      *(byte **)(unaff_ESI[0xe] + 4) = pbVar4 + 1;
    }
    iVar6 = iVar6 + 1;
    *unaff_ESI = uVar5;
  }
  if (*unaff_ESI != uVar1) {
    return -1 - iVar6;
  }
  return iVar6;
}

