
void FUN_006ff200(void)

{
  int iVar1;
  int *piVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  uint *unaff_EDI;
  int local_8;
  
  iVar1 = *(int *)unaff_EDI[0xe];
  uVar4 = *unaff_EDI;
  *(int *)unaff_EDI[0xe] = iVar1 + -1;
  if (iVar1 == 0) {
    piVar2 = (int *)unaff_EDI[0xe];
    pbVar3 = (byte *)(*(code *)piVar2[2])(piVar2[4],piVar2[3],&local_8);
    if ((pbVar3 == (byte *)0x0) || (local_8 == 0)) {
      uVar5 = 0xffffffff;
    }
    else {
      piVar2[1] = (int)pbVar3;
      *piVar2 = local_8 + -1;
      uVar5 = (uint)*pbVar3;
      piVar2[1] = (int)(pbVar3 + 1);
    }
  }
  else {
    pbVar3 = *(byte **)(unaff_EDI[0xe] + 4);
    uVar5 = (uint)*pbVar3;
    *(byte **)(unaff_EDI[0xe] + 4) = pbVar3 + 1;
  }
  *unaff_EDI = uVar5;
  if (((uVar5 == 10) || (uVar5 == 0xd)) && (uVar5 != uVar4)) {
    iVar1 = *(int *)unaff_EDI[0xe];
    *(int *)unaff_EDI[0xe] = iVar1 + -1;
    if (iVar1 == 0) {
      uVar4 = FUN_006fedf0();
    }
    else {
      pbVar3 = *(byte **)(unaff_EDI[0xe] + 4);
      uVar4 = (uint)*pbVar3;
      *(byte **)(unaff_EDI[0xe] + 4) = pbVar3 + 1;
    }
    *unaff_EDI = uVar4;
  }
  unaff_EDI[1] = unaff_EDI[1] + 1;
  if (0x7ffffffc < (int)unaff_EDI[1]) {
                    /* WARNING: Subroutine does not return */
    FUN_006ff130();
  }
  return;
}

