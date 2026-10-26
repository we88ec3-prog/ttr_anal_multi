
uint * FUN_00537640(uint *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  void *pvVar6;
  uint uVar7;
  byte *pbVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  byte *pbVar12;
  char *pcVar13;
  byte *pbVar14;
  bool bVar15;
  int local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pvVar6 = ExceptionList;
  puStack_c = &LAB_009084a9;
  local_10 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  local_8 = 0;
  local_1c[2] = 1;
  if (((param_2 == 0) || (iVar9 = *(int *)(param_2 + 0x94), iVar9 == param_2 + 0x44)) ||
     (param_2 = iVar9, iVar9 == 0)) {
    ExceptionList = pvVar6;
    return param_1;
  }
  do {
    uVar2 = *(uint *)(param_2 + 0x28);
    pbVar14 = (byte *)(param_2 + 0x14);
    pbVar8 = pbVar14;
    if (0xf < uVar2) {
      pbVar8 = *(byte **)pbVar14;
    }
    pbVar12 = &DAT_00c0f280;
    do {
      bVar1 = *pbVar8;
      bVar15 = bVar1 < *pbVar12;
      if (bVar1 != *pbVar12) {
LAB_005376f0:
        iVar9 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
        goto LAB_005376f5;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar8[1];
      bVar15 = bVar1 < pbVar12[1];
      if (bVar1 != pbVar12[1]) goto LAB_005376f0;
      pbVar8 = pbVar8 + 2;
      pbVar12 = pbVar12 + 2;
    } while (bVar1 != 0);
    iVar9 = 0;
LAB_005376f5:
    if (iVar9 == 0) {
      iVar9 = 0;
    }
    else {
      pbVar8 = pbVar14;
      if (0xf < uVar2) {
        pbVar8 = *(byte **)pbVar14;
      }
      pcVar13 = "PRODUCTNO";
      do {
        bVar1 = *pbVar8;
        bVar15 = bVar1 < (byte)*pcVar13;
        if (bVar1 != *pcVar13) {
LAB_00537730:
          iVar9 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
          goto LAB_00537735;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar8[1];
        bVar15 = bVar1 < (byte)pcVar13[1];
        if (bVar1 != pcVar13[1]) goto LAB_00537730;
        pbVar8 = pbVar8 + 2;
        pcVar13 = pcVar13 + 2;
      } while (bVar1 != 0);
      iVar9 = 0;
LAB_00537735:
      if (iVar9 == 0) {
        iVar9 = 1;
      }
      else {
        pbVar8 = pbVar14;
        if (0xf < uVar2) {
          pbVar8 = *(byte **)pbVar14;
        }
        pbVar12 = &DAT_00c02328;
        do {
          bVar1 = *pbVar8;
          bVar15 = bVar1 < *pbVar12;
          if (bVar1 != *pbVar12) {
LAB_00537773:
            iVar9 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
            goto LAB_00537778;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar8[1];
          bVar15 = bVar1 < pbVar12[1];
          if (bVar1 != pbVar12[1]) goto LAB_00537773;
          pbVar8 = pbVar8 + 2;
          pbVar12 = pbVar12 + 2;
        } while (bVar1 != 0);
        iVar9 = 0;
LAB_00537778:
        if (iVar9 == 0) {
          iVar9 = 2;
        }
        else {
          pbVar8 = pbVar14;
          if (0xf < uVar2) {
            pbVar8 = *(byte **)pbVar14;
          }
          pbVar12 = &DAT_00c0f294;
          do {
            bVar1 = *pbVar8;
            bVar15 = bVar1 < *pbVar12;
            if (bVar1 != *pbVar12) {
LAB_005377b6:
              iVar9 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
              goto LAB_005377bb;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar15 = bVar1 < pbVar12[1];
            if (bVar1 != pbVar12[1]) goto LAB_005377b6;
            pbVar8 = pbVar8 + 2;
            pbVar12 = pbVar12 + 2;
          } while (bVar1 != 0);
          iVar9 = 0;
LAB_005377bb:
          if (iVar9 == 0) {
            iVar9 = 3;
          }
          else {
            pbVar8 = pbVar14;
            if (0xf < uVar2) {
              pbVar8 = *(byte **)pbVar14;
            }
            pbVar12 = &DAT_00c0e1d8;
            do {
              bVar1 = *pbVar8;
              bVar15 = bVar1 < *pbVar12;
              if (bVar1 != *pbVar12) {
LAB_00537800:
                iVar9 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
                goto LAB_00537805;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar8[1];
              bVar15 = bVar1 < pbVar12[1];
              if (bVar1 != pbVar12[1]) goto LAB_00537800;
              pbVar8 = pbVar8 + 2;
              pbVar12 = pbVar12 + 2;
            } while (bVar1 != 0);
            iVar9 = 0;
LAB_00537805:
            if (iVar9 == 0) {
              iVar9 = 4;
            }
            else {
              pbVar8 = pbVar14;
              if (0xf < uVar2) {
                pbVar8 = *(byte **)pbVar14;
              }
              pcVar13 = "GRADE";
              do {
                bVar1 = *pbVar8;
                bVar15 = bVar1 < (byte)*pcVar13;
                if (bVar1 != *pcVar13) {
LAB_00537843:
                  iVar9 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
                  goto LAB_00537848;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar8[1];
                bVar15 = bVar1 < (byte)pcVar13[1];
                if (bVar1 != pcVar13[1]) goto LAB_00537843;
                pbVar8 = pbVar8 + 2;
                pcVar13 = pcVar13 + 2;
              } while (bVar1 != 0);
              iVar9 = 0;
LAB_00537848:
              if (iVar9 == 0) {
                iVar9 = 5;
              }
              else {
                pbVar8 = pbVar14;
                if (0xf < uVar2) {
                  pbVar8 = *(byte **)pbVar14;
                }
                pcVar13 = "ORIGIN";
                do {
                  bVar1 = *pbVar8;
                  bVar15 = bVar1 < (byte)*pcVar13;
                  if (bVar1 != *pcVar13) {
LAB_00537886:
                    iVar9 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
                    goto LAB_0053788b;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar8[1];
                  bVar15 = bVar1 < (byte)pcVar13[1];
                  if (bVar1 != pcVar13[1]) goto LAB_00537886;
                  pbVar8 = pbVar8 + 2;
                  pcVar13 = pcVar13 + 2;
                } while (bVar1 != 0);
                iVar9 = 0;
LAB_0053788b:
                if (iVar9 == 0) {
                  iVar9 = 6;
                }
                else {
                  pbVar8 = pbVar14;
                  if (0xf < uVar2) {
                    pbVar8 = *(byte **)pbVar14;
                  }
                  pcVar13 = "ORIGINCLS";
                  do {
                    bVar1 = *pbVar8;
                    bVar15 = bVar1 < (byte)*pcVar13;
                    if (bVar1 != *pcVar13) {
LAB_005378d0:
                      iVar9 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
                      goto LAB_005378d5;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar8[1];
                    bVar15 = bVar1 < (byte)pcVar13[1];
                    if (bVar1 != pcVar13[1]) goto LAB_005378d0;
                    pbVar8 = pbVar8 + 2;
                    pcVar13 = pcVar13 + 2;
                  } while (bVar1 != 0);
                  iVar9 = 0;
LAB_005378d5:
                  if (iVar9 == 0) {
                    iVar9 = 7;
                  }
                  else {
                    pbVar8 = pbVar14;
                    if (0xf < uVar2) {
                      pbVar8 = *(byte **)pbVar14;
                    }
                    pbVar12 = &DAT_00c0dfac;
                    do {
                      bVar1 = *pbVar8;
                      bVar15 = bVar1 < *pbVar12;
                      if (bVar1 != *pbVar12) {
LAB_00537910:
                        iVar9 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
                        goto LAB_00537915;
                      }
                      if (bVar1 == 0) break;
                      bVar1 = pbVar8[1];
                      bVar15 = bVar1 < pbVar12[1];
                      if (bVar1 != pbVar12[1]) goto LAB_00537910;
                      pbVar8 = pbVar8 + 2;
                      pbVar12 = pbVar12 + 2;
                    } while (bVar1 != 0);
                    iVar9 = 0;
LAB_00537915:
                    if (iVar9 == 0) {
                      iVar9 = 8;
                    }
                    else {
                      if (0xf < uVar2) {
                        pbVar14 = *(byte **)pbVar14;
                      }
                      pbVar8 = &DAT_00c0dfb4;
                      do {
                        bVar1 = *pbVar14;
                        bVar15 = bVar1 < *pbVar8;
                        if (bVar1 != *pbVar8) {
LAB_00537950:
                          iVar9 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
                          goto LAB_00537955;
                        }
                        if (bVar1 == 0) break;
                        bVar1 = pbVar14[1];
                        bVar15 = bVar1 < pbVar8[1];
                        if (bVar1 != pbVar8[1]) goto LAB_00537950;
                        pbVar14 = pbVar14 + 2;
                        pbVar8 = pbVar8 + 2;
                      } while (bVar1 != 0);
                      iVar9 = 0;
LAB_00537955:
                      iVar9 = (iVar9 != 0) + 9;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    puVar10 = (undefined4 *)(param_2 + 0x30);
    if (0xf < *(uint *)(param_2 + 0x44)) {
      puVar10 = (undefined4 *)*puVar10;
    }
    local_1c[0] = iVar9;
    iVar11 = FUN_008917b4(puVar10,uVar7);
    piVar3 = (int *)param_1[1];
    local_1c[1] = iVar11;
    if (local_1c < piVar3) {
      piVar4 = (int *)*param_1;
      if (local_1c < piVar4) goto LAB_005379c9;
      if (piVar3 == (int *)param_1[2]) {
        FUN_00539180();
      }
      puVar10 = (undefined4 *)(*param_1 + ((int)local_1c - (int)piVar4 >> 3) * 8);
      puVar5 = (undefined4 *)param_1[1];
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = *puVar10;
        puVar5[1] = puVar10[1];
      }
      param_1[1] = param_1[1] + 8;
    }
    else {
LAB_005379c9:
      if (piVar3 == (int *)param_1[2]) {
        FUN_00539180();
      }
      piVar3 = (int *)param_1[1];
      if (piVar3 != (int *)0x0) {
        *piVar3 = iVar9;
        piVar3[1] = iVar11;
      }
      param_1[1] = param_1[1] + 8;
    }
    param_2 = *(int *)(param_2 + 0x50);
    if ((*(int *)(param_2 + 0x40) == 0) && (*(int *)(param_2 + 0x24) == 0)) {
      param_2 = 0;
    }
    if (param_2 == 0) {
      ExceptionList = local_10;
      return param_1;
    }
  } while( true );
}

