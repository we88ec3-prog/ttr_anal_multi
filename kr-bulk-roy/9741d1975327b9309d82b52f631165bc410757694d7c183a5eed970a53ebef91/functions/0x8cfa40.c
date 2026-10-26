
uint FUN_008cfa40(char *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  if (*param_1 == 'u') {
    pbVar7 = (byte *)(param_1 + 1);
    if ((param_1[1] == 'n') && (param_1[2] == 'i')) {
      uVar6 = 0;
      pbVar8 = (byte *)(param_1 + 3);
      iVar5 = 4;
      do {
        uVar4 = (uint)*pbVar8;
        uVar2 = uVar4 - 0x30;
        if (9 < uVar2) {
          if (5 < uVar4 - 0x41) break;
          uVar2 = uVar4 - 0x37;
        }
        if (0xf < uVar2) break;
        iVar5 = iVar5 + -1;
        uVar6 = uVar6 * 0x10 + uVar2;
        pbVar8 = pbVar8 + 1;
      } while (0 < iVar5);
      if (iVar5 == 0) {
        if (*pbVar8 == 0) {
          return uVar6;
        }
        if (*pbVar8 == 0x2e) {
          return uVar6 | 0x80000000;
        }
      }
    }
    uVar6 = 0;
    iVar5 = 6;
    do {
      uVar4 = (uint)*pbVar7;
      uVar2 = uVar4 - 0x30;
      if (9 < uVar2) {
        if (5 < uVar4 - 0x41) break;
        uVar2 = uVar4 - 0x37;
      }
      if (0xf < uVar2) break;
      iVar5 = iVar5 + -1;
      uVar6 = uVar6 * 0x10 + uVar2;
      pbVar7 = pbVar7 + 1;
    } while (0 < iVar5);
    if (iVar5 < 3) {
      if (*pbVar7 == 0) {
        return uVar6;
      }
      if (*pbVar7 == 0x2e) {
        return uVar6 | 0x80000000;
      }
    }
  }
  cVar1 = *param_1;
  pcVar3 = param_1;
  while( true ) {
    if (cVar1 == '\0') {
      uVar6 = FUN_008cf960(pcVar3);
      return uVar6;
    }
    if ((cVar1 == '.') && (param_1 < pcVar3)) break;
    cVar1 = pcVar3[1];
    pcVar3 = pcVar3 + 1;
  }
  uVar6 = FUN_008cf960(pcVar3);
  return uVar6 | 0x80000000;
}

