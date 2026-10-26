
byte * FUN_0071b150(int param_1,int *param_2,char param_3)

{
  byte *pbVar1;
  bool bVar2;
  byte bVar3;
  uint in_EAX;
  uint uVar4;
  int iVar5;
  int in_ECX;
  byte *pbVar6;
  byte *pbVar7;
  
  pbVar7 = (byte *)(in_ECX + 1);
  if (((&DAT_00c0b650)[*(byte *)(in_ECX + 1)] & 0x80) != 0) {
    bVar3 = (&DAT_00c0b650)[*pbVar7];
    pbVar6 = pbVar7;
    while ((bVar3 & 0x40) != 0) {
      pbVar1 = pbVar6 + 1;
      pbVar6 = pbVar6 + 1;
      bVar3 = (&DAT_00c0b650)[*pbVar1];
    }
    if (*pbVar6 == 0) {
      *(byte **)(param_1 + 8) = pbVar6;
                    /* WARNING: Subroutine does not return */
      FID_conflict____longjmp_internal((int *)(param_1 + 0xc),6);
    }
    if (((((*pbVar7 | 0x20) == 0x78) && ((*(byte *)(in_ECX + 2) | 0x20) == 0x6d)) &&
        ((*(byte *)(in_ECX + 3) | 0x20) == 0x6c)) && ((byte *)(in_ECX + 4) == pbVar6)) {
      bVar2 = true;
      uVar4 = in_EAX & 0x100;
    }
    else {
      bVar2 = false;
      uVar4 = in_EAX & 1;
    }
    if (uVar4 == 0) {
      bVar3 = *pbVar6;
      if (bVar3 == 0) {
LAB_0071b35e:
        *(byte **)(param_1 + 8) = pbVar6;
        iVar5 = 6;
      }
      else {
        do {
          if ((bVar3 == 0x3f) && ((pbVar6[1] == 0x3e || ((pbVar6[1] == 0 && (param_3 == '>')))))) {
            if (*pbVar6 != 0) {
              bVar3 = pbVar6[1];
              *param_2 = *param_2;
              return pbVar6 + (bVar3 == 0x3e) + 1;
            }
            goto LAB_0071b35e;
          }
          bVar3 = pbVar6[1];
          pbVar6 = pbVar6 + 1;
        } while (bVar3 != 0);
        *(byte **)(param_1 + 8) = pbVar6;
        iVar5 = 6;
      }
    }
    else {
      if ((bVar2) && (*(int *)(*param_2 + 4) != 0)) {
        *(byte **)(param_1 + 8) = pbVar6;
                    /* WARNING: Subroutine does not return */
        FID_conflict____longjmp_internal((int *)(param_1 + 0xc),6);
      }
      iVar5 = FUN_0071a530(param_1);
      if (iVar5 == 0) {
        *(byte **)(param_1 + 8) = pbVar6;
        iVar5 = 3;
      }
      else {
        *(byte **)(iVar5 + 8) = pbVar7;
        bVar3 = *pbVar6;
        *pbVar6 = 0;
        pbVar7 = pbVar6 + 1;
        if (bVar3 == 0x3f) {
          bVar3 = *pbVar7;
          if ((bVar3 == 0x3e) || ((bVar3 == 0 && (param_3 == '>')))) {
            *param_2 = *(int *)(iVar5 + 4);
            return pbVar7 + (bVar3 == 0x3e);
          }
          *(byte **)(param_1 + 8) = pbVar7;
          iVar5 = 6;
        }
        else {
          if (((&DAT_00c0b650)[bVar3] & 8) == 0) goto LAB_0071b16e;
          bVar3 = (&DAT_00c0b650)[*pbVar7];
          while ((bVar3 & 8) != 0) {
            pbVar6 = pbVar7 + 1;
            pbVar7 = pbVar7 + 1;
            bVar3 = (&DAT_00c0b650)[*pbVar6];
          }
          pbVar6 = pbVar7;
          if (*pbVar7 != 0) {
            do {
              if ((*pbVar6 == 0x3f) &&
                 ((pbVar6[1] == 0x3e || ((pbVar6[1] == 0 && (param_3 == '>')))))) break;
              pbVar6 = pbVar6 + 1;
            } while (*pbVar6 != 0);
            if (*pbVar6 != 0) {
              if (!bVar2) {
                *(byte **)(iVar5 + 0xc) = pbVar7;
                iVar5 = *(int *)(iVar5 + 4);
                *pbVar6 = 0;
                bVar3 = pbVar6[1];
                *param_2 = iVar5;
                return pbVar6 + 1 + (bVar3 == 0x3e);
              }
              *pbVar6 = 0x2f;
              *param_2 = iVar5;
              return pbVar7;
            }
          }
          *(byte **)(param_1 + 8) = pbVar6;
          iVar5 = 6;
        }
      }
    }
                    /* WARNING: Subroutine does not return */
    FID_conflict____longjmp_internal((int *)(param_1 + 0xc),iVar5);
  }
LAB_0071b16e:
  *(byte **)(param_1 + 8) = pbVar7;
                    /* WARNING: Subroutine does not return */
  FID_conflict____longjmp_internal((int *)(param_1 + 0xc),6);
}

