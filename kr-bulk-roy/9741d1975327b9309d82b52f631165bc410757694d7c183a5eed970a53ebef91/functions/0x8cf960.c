
undefined2 FUN_008cf960(char *param_1)

{
  char cVar1;
  char *in_EAX;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  
  if ((in_EAX != (char *)0x0) && (in_EAX < param_1)) {
    pcVar6 = in_EAX + 1;
    iVar8 = 0;
    iVar7 = 0x34;
    do {
      iVar2 = iVar7 + iVar8 >> 1;
      pbVar3 = &DAT_00bd9ca0 + CONCAT11((&UNK_00bd9ca2)[iVar2 * 2],(&UNK_00bd9ca3)[iVar2 * 2]);
      if ((*pbVar3 & 0x7f) == (int)*in_EAX) {
        while (pcVar6 < param_1) {
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
          if ((*pbVar3 & 0x80) == 0) {
            pbVar4 = pbVar3 + 1;
            uVar5 = pbVar3[1] & 0x7f;
            if ((char)pbVar3[1] < '\0') {
              pbVar4 = pbVar3 + 3;
            }
            pbVar4 = pbVar4 + 1;
            while( true ) {
              if ((int)uVar5 < 1) {
                return 0;
              }
              pbVar3 = &DAT_00bd9ca0 + CONCAT11(*pbVar4,pbVar4[1]);
              if ((int)cVar1 == (*pbVar3 & 0x7f)) break;
              uVar5 = uVar5 - 1;
              pbVar4 = pbVar4 + 2;
            }
          }
          else {
            pbVar4 = pbVar3 + 1;
            pbVar3 = pbVar3 + 1;
            if ((int)cVar1 != (*pbVar4 & 0x7f)) {
              return 0;
            }
          }
        }
        if ((*pbVar3 & 0x80) != 0) {
          return 0;
        }
        if ((pbVar3[1] & 0x80) == 0) {
          return 0;
        }
        return CONCAT11(pbVar3[2],pbVar3[3]);
      }
      if ((int)(*pbVar3 & 0x7f) < (int)*in_EAX) {
        iVar8 = iVar2 + 1;
        iVar2 = iVar7;
      }
      iVar7 = iVar2;
    } while (iVar8 < iVar2);
  }
  return 0;
}

