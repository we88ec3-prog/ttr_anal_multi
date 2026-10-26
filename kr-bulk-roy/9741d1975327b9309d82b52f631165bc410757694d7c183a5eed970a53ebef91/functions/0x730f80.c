
void FUN_00730f80(byte *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  int *unaff_EDI;
  
  if (0 < unaff_EDI[3]) {
    iVar4 = unaff_EDI[1];
    iVar7 = *unaff_EDI;
    pbVar5 = (byte *)unaff_EDI[2];
joined_r0x00730f9a:
    pbVar3 = pbVar5;
    if (pbVar3 < param_1) {
      switch((uint)*pbVar3) {
      case 0:
        goto switchD_00730fb6_caseD_0;
      default:
        if (param_2 == 1) {
          iVar6 = *(int *)(&DAT_00c07d58 + (uint)*pbVar3 * 4);
          if (iVar6 == 0) {
            iVar6 = 1;
          }
          pbVar5 = pbVar3 + iVar6;
        }
        else {
LAB_00731048:
          pbVar5 = pbVar3 + 1;
        }
        goto LAB_00731049;
      case 9:
        iVar4 = (iVar4 / unaff_EDI[3] + 1) * unaff_EDI[3];
        pbVar5 = pbVar3 + 1;
        goto joined_r0x00730f9a;
      case 10:
        iVar7 = iVar7 + 1;
        iVar4 = 0;
        pbVar5 = pbVar3 + 1;
        if (pbVar3[1] == 0xd) {
          pbVar5 = pbVar3 + 2;
        }
        goto joined_r0x00730f9a;
      case 0xd:
        iVar7 = iVar7 + 1;
        iVar4 = 0;
        pbVar5 = pbVar3 + 1;
        if (pbVar3[1] == 10) {
          pbVar5 = pbVar3 + 2;
        }
        goto joined_r0x00730f9a;
      case 0xef:
        goto switchD_00730fb6_caseD_ef;
      }
    }
    *unaff_EDI = iVar7;
    unaff_EDI[1] = iVar4;
    unaff_EDI[2] = (int)pbVar3;
switchD_00730fb6_caseD_0:
  }
  return;
switchD_00730fb6_caseD_ef:
  if (param_2 != 1) goto LAB_00731048;
  bVar1 = pbVar3[1];
  pbVar5 = pbVar3;
  if ((bVar1 != 0) && (bVar2 = pbVar3[2], bVar2 != 0)) {
    if ((bVar1 == 0xbb) && (bVar2 == 0xbf)) {
      pbVar5 = pbVar3 + 3;
      goto joined_r0x00730f9a;
    }
    if (bVar1 == 0xbf) {
      if (bVar2 == 0xbe) {
        pbVar5 = pbVar3 + 3;
        goto joined_r0x00730f9a;
      }
      if (bVar2 == 0xbf) {
        pbVar5 = pbVar3 + 3;
        goto joined_r0x00730f9a;
      }
    }
    pbVar5 = pbVar3 + 3;
LAB_00731049:
    iVar4 = iVar4 + 1;
  }
  goto joined_r0x00730f9a;
}

