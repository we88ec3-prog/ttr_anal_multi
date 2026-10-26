
undefined * FUN_008be080(undefined1 param_1,int *param_2)

{
  char cVar1;
  undefined *puVar2;
  char *pcVar3;
  int *unaff_EBX;
  int iVar4;
  uint uVar5;
  
  *param_2 = 0;
  if ((unaff_EBX == (int *)0x0) || (unaff_EBX[2] == 0)) {
    return (undefined *)0x0;
  }
  puVar2 = *(undefined **)*unaff_EBX;
  iVar4 = 0;
  uVar5 = 0;
  if (unaff_EBX[2] != 0) {
    do {
      pcVar3 = *(char **)(*unaff_EBX + uVar5 * 4);
      cVar1 = *pcVar3;
      while (cVar1 != '\0') {
        pcVar3 = pcVar3 + 1;
        puVar2[iVar4] = cVar1;
        iVar4 = iVar4 + 1;
        cVar1 = *pcVar3;
      }
      uVar5 = uVar5 + 1;
      if ((uint)unaff_EBX[2] <= uVar5) break;
      puVar2[iVar4] = param_1;
      iVar4 = iVar4 + 1;
    } while (uVar5 < (uint)unaff_EBX[2]);
  }
  if (puVar2 != &DAT_00bd7a24) {
    puVar2[iVar4] = 0;
  }
  *param_2 = iVar4;
  return puVar2;
}

