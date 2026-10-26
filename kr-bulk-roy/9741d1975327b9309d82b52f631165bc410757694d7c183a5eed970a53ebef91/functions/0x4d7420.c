
void FUN_004d7420(short *param_1)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  
  psVar2 = param_1;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  iVar3 = (int)psVar2 - (int)(param_1 + 1) >> 1;
  iVar6 = 0;
  if (0 < iVar3) {
    puVar5 = (ushort *)(param_1 + 2);
    psVar2 = param_1 + 3;
    do {
      if ((((iVar6 < iVar3 + -3) && (param_1[iVar6] == 0x3c)) && (*psVar2 == 0x3e)) &&
         ((iVar4 = _tolower((uint)(ushort)param_1[iVar6 + 1]), iVar4 == 0x62 &&
          (iVar4 = _tolower((uint)*puVar5), iVar4 == 0x72)))) {
        iVar6 = iVar6 + 3;
        psVar2 = psVar2 + 3;
        puVar5 = puVar5 + 3;
      }
      else {
        FUN_00440010(1,param_1[iVar6]);
      }
      iVar6 = iVar6 + 1;
      psVar2 = psVar2 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar6 < iVar3);
  }
  return;
}

