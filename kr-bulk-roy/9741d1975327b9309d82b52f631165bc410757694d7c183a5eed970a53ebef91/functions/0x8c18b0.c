
void FUN_008c18b0(void)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  int *in_ECX;
  int iVar3;
  int unaff_EBX;
  int *piVar4;
  int iVar5;
  int local_c;
  int local_8;
  
  *(int *)(unaff_EBX + 0x4c) = *in_EAX * 4;
  piVar4 = (int *)(unaff_EBX + 0x4c);
  *(int *)(unaff_EBX + 0x50) = in_EAX[1] * 4;
  iVar2 = *in_ECX;
  *(int *)(unaff_EBX + 0x54) = iVar2 * 4;
  *(int *)(unaff_EBX + 0x58) = in_ECX[1] * 4;
  iVar3 = *(int *)(unaff_EBX + 0x40);
  *(int *)(unaff_EBX + 0x5c) = iVar3;
  iVar1 = *(int *)(unaff_EBX + 0x44);
  *(int *)(unaff_EBX + 0x60) = iVar1;
  iVar5 = 0;
  local_8 = *piVar4 + iVar2 * -8 + iVar3;
  if (local_8 < 0) {
    local_8 = (iVar2 * 8 - *piVar4) - iVar3;
  }
  iVar2 = *(int *)(unaff_EBX + 0x50) + *(int *)(unaff_EBX + 0x58) * -2 + iVar1;
  if (iVar2 < 0) {
    iVar2 = (*(int *)(unaff_EBX + 0x58) * 2 - *(int *)(unaff_EBX + 0x50)) - iVar1;
  }
  if (local_8 < iVar2) {
    local_8 = iVar2;
  }
  if (local_8 < 0x40) goto LAB_008c1987;
  iVar2 = *(int *)(unaff_EBX + 0x50);
  iVar3 = *(int *)(unaff_EBX + 0x58);
  local_c = iVar2;
  if (iVar3 < iVar2) {
    local_c = iVar3;
  }
  if (iVar2 < iVar3) {
    iVar2 = iVar3;
  }
  iVar3 = iVar1;
  if (local_c <= iVar1) {
    iVar3 = local_c;
  }
  if (iVar2 < iVar1) {
    iVar2 = iVar1;
  }
  if (*(int *)(unaff_EBX + 0x14) <= iVar3 >> 8) goto LAB_008c1987;
  if (iVar2 >> 8 < *(int *)(unaff_EBX + 0x10)) goto LAB_008c1987;
  iVar2 = 0;
  do {
    local_8 = local_8 >> 2;
    iVar2 = iVar2 + 1;
  } while (0x40 < local_8);
  *(int *)(unaff_EBX + 0x354) = iVar2;
  do {
    iVar2 = *(int *)(unaff_EBX + 0x354 + iVar5 * 4);
    if (iVar2 < 1) {
LAB_008c1987:
      FUN_008c15f0(*piVar4,piVar4[1]);
      iVar5 = iVar5 + -1;
      piVar4 = piVar4 + -4;
    }
    else {
      FUN_008c1850();
      iVar5 = iVar5 + 1;
      piVar4 = piVar4 + 4;
      iVar2 = iVar2 + -1;
      *(int *)(unaff_EBX + 0x350 + iVar5 * 4) = iVar2;
      *(int *)(unaff_EBX + 0x354 + iVar5 * 4) = iVar2;
    }
  } while (-1 < iVar5);
  return;
}

