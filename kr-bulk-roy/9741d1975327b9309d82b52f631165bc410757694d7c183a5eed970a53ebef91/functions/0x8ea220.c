
int FUN_008ea220(undefined4 param_1,undefined4 *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  short sVar4;
  int *piVar5;
  short sVar6;
  short sVar7;
  undefined4 uVar8;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  undefined2 extraout_var;
  char *pcVar12;
  byte *pbVar13;
  char *pcVar14;
  int iVar15;
  bool bVar16;
  undefined4 *local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  *param_2 = 1;
  local_8 = FUN_008b8ff0(param_2[0x18],"postscript-cmaps");
  param_2[0x79] = local_8;
  local_c = FUN_008b8fc0(*(undefined4 *)(param_2[0x18] + 4),"psaux");
  param_2[0x7a] = local_c;
  if (local_c == 0) {
    return 0xb;
  }
  uVar8 = FUN_008b8fc0(*(undefined4 *)(param_2[0x18] + 4),"pshinter");
  param_2[0x89] = uVar8;
  iVar9 = FUN_008e8170();
  if (iVar9 != 0) {
    return iVar9;
  }
  if (param_3 < 0) {
    return 0;
  }
  if (0 < param_3) {
    return 6;
  }
  param_2[2] = param_2[2] | 0xa11;
  param_2[4] = param_2[0x68];
  param_2[1] = 0;
  if (*(char *)(param_2 + 0x27) != '\0') {
    param_2[2] = param_2[2] | 4;
  }
  if (param_2[0x84] != 0) {
    param_2[2] = param_2[2] | 0x100;
  }
  pcVar14 = (char *)param_2[0x24];
  param_2[5] = pcVar14;
  param_2[6] = 0;
  if (pcVar14 == (char *)0x0) {
    if (param_2[0x5b] != 0) {
      param_2[5] = param_2[0x5b];
    }
  }
  else {
    pcVar12 = (char *)param_2[0x23];
    if (pcVar12 != (char *)0x0) {
      cVar1 = *pcVar12;
      while (cVar1 != '\0') {
        cVar2 = *pcVar14;
        if (cVar1 == cVar2) {
          pcVar14 = pcVar14 + 1;
LAB_008ea31f:
          pcVar12 = pcVar12 + 1;
        }
        else {
          if ((cVar1 == ' ') || (cVar1 == '-')) goto LAB_008ea31f;
          if ((cVar2 != ' ') && (cVar2 != '-')) {
            if (*pcVar14 == '\0') {
              param_2[6] = pcVar12;
            }
            goto LAB_008ea357;
          }
          pcVar14 = pcVar14 + 1;
        }
        cVar1 = *pcVar12;
      }
      param_2[6] = "Regular";
    }
  }
LAB_008ea357:
  if (param_2[6] == 0) {
    if (param_2[0x25] == 0) {
      param_2[6] = "Regular";
    }
    else {
      param_2[6] = param_2[0x25];
    }
  }
  param_2[3] = 0;
  if (param_2[0x26] != 0) {
    param_2[3] = 1;
  }
  pbVar11 = (byte *)param_2[0x25];
  if (pbVar11 != (byte *)0x0) {
    pbVar13 = &DAT_00c4651c;
    pbVar10 = pbVar11;
    do {
      bVar3 = *pbVar10;
      bVar16 = bVar3 < *pbVar13;
      if (bVar3 != *pbVar13) {
LAB_008ea3b7:
        iVar9 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
        goto LAB_008ea3bc;
      }
      if (bVar3 == 0) break;
      bVar3 = pbVar10[1];
      bVar16 = bVar3 < pbVar13[1];
      if (bVar3 != pbVar13[1]) goto LAB_008ea3b7;
      pbVar10 = pbVar10 + 2;
      pbVar13 = pbVar13 + 2;
    } while (bVar3 != 0);
    iVar9 = 0;
LAB_008ea3bc:
    if (iVar9 != 0) {
      pcVar14 = "Black";
      do {
        bVar3 = *pbVar11;
        bVar16 = bVar3 < (byte)*pcVar14;
        if (bVar3 != *pcVar14) {
LAB_008ea3e7:
          iVar9 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
          goto LAB_008ea3ec;
        }
        if (bVar3 == 0) break;
        bVar3 = pbVar11[1];
        bVar16 = bVar3 < (byte)pcVar14[1];
        if (bVar3 != pcVar14[1]) goto LAB_008ea3e7;
        pbVar11 = pbVar11 + 2;
        pcVar14 = pcVar14 + 2;
      } while (bVar3 != 0);
      iVar9 = 0;
LAB_008ea3ec:
      if (iVar9 != 0) goto LAB_008ea3f4;
    }
    param_2[3] = param_2[3] | 2;
  }
LAB_008ea3f4:
  param_2[7] = 0;
  param_2[8] = 0;
  param_2[0xd] = (int)*(short *)((int)param_2 + 0x1ce);
  param_2[0xe] = (int)*(short *)((int)param_2 + 0x1d2);
  param_2[0xf] = param_2[0x75] + 0xffff >> 0x10;
  param_2[0x10] = param_2[0x76] + 0xffff >> 0x10;
  if (*(short *)(param_2 + 0x11) == 0) {
    *(undefined2 *)(param_2 + 0x11) = 1000;
  }
  sVar4 = *(short *)(param_2 + 0xe);
  sVar6 = (short)((uint)(param_2[0x76] + 0xffff) >> 0x10);
  sVar7 = (short)(((uint)*(ushort *)(param_2 + 0x11) * 0xc) / 10);
  *(short *)((int)param_2 + 0x4a) = sVar7;
  *(short *)((int)param_2 + 0x46) = sVar6;
  *(short *)(param_2 + 0x12) = sVar4;
  if ((int)sVar7 < (int)sVar6 - (int)sVar4) {
    *(short *)((int)param_2 + 0x4a) = sVar6 - sVar4;
  }
  *(undefined2 *)(param_2 + 0x13) = *(undefined2 *)(param_2 + 0xf);
  iVar9 = FUN_008e92b0();
  if (iVar9 == 0) {
    FUN_008b7c80(param_2);
    *(undefined2 *)(param_2 + 0x13) = extraout_var;
  }
  iVar9 = 0;
  *(undefined2 *)((int)param_2 + 0x4e) = *(undefined2 *)((int)param_2 + 0x4a);
  *(undefined2 *)(param_2 + 0x14) = *(undefined2 *)((int)param_2 + 0x9e);
  *(undefined2 *)((int)param_2 + 0x52) = *(undefined2 *)(param_2 + 0x28);
  if (local_8 != 0) {
    piVar5 = *(int **)(local_c + 0x14);
    local_18 = param_2;
    local_10 = 0x10003;
    local_14 = 0x756e6963;
    iVar9 = FUN_008bcc30(piVar5[3],0,&local_18,0);
    if ((iVar9 == 0) || ((char)iVar9 == -0x5d)) {
      iVar9 = 0;
      switch(param_2[0x5c]) {
      case 1:
        local_14 = 0x41444243;
        local_10 = 0x20007;
        iVar15 = piVar5[2];
        break;
      case 2:
        local_14 = 0x41444f42;
        local_10 = 7;
        iVar15 = *piVar5;
        break;
      case 3:
        local_14 = 0x6c617431;
        local_10 = 0x30007;
        iVar15 = piVar5[3];
        break;
      case 4:
        local_14 = 0x41444245;
        local_10 = 0x10007;
        iVar15 = piVar5[1];
        break;
      default:
        goto switchD_008ea52b_default;
      }
      if (iVar15 != 0) {
        iVar9 = FUN_008bcc30(iVar15,0,&local_18,0);
      }
    }
  }
switchD_008ea52b_default:
  return iVar9;
}

