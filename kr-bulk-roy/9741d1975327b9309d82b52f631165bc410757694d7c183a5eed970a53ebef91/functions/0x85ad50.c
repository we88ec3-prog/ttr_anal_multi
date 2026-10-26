
void FUN_0085ad50(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  char *pcVar6;
  byte *pbVar7;
  int in_EDX;
  bool bVar8;
  undefined4 local_ac;
  byte *local_a8;
  int local_a4;
  undefined4 local_a0;
  uint local_98 [4];
  undefined4 local_88;
  uint local_84;
  undefined1 local_7c [104];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a2e6;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = (**(code **)(**(int **)(in_EDX + 4) + 0x4c))(*(int **)(in_EDX + 4));
  if (iVar2 == 0) goto LAB_0085b2b6;
  local_ac = 0;
  (**(code **)(**(int **)(in_EDX + 4) + 0xcc))(*(int **)(in_EDX + 4),iVar2,&local_ac);
  local_a8 = (byte *)0x0;
  local_a4 = 0;
  local_a0 = 0;
  local_8 = 0;
  FUN_00858990(local_ac);
  iVar2 = (local_a4 - (int)local_a8) / 0x1c;
  pbVar5 = local_a8;
  if (0xf < *(uint *)(local_a8 + 0x14)) {
    pbVar5 = *(byte **)local_a8;
  }
  if (iVar2 == 2) {
    local_84 = 0xf;
    local_88 = 0;
    local_98[0] = local_98[0] & 0xffffff00;
    FUN_00403040(local_a8 + 0x1c,0,0xffffffff);
    local_8 = CONCAT31(local_8._1_3_,1);
    _memset(local_7c,0,100);
    iVar2 = FUN_00440930(local_98,&DAT_00c54630,1);
    iVar3 = FUN_00440930(local_98,&DAT_00c54634,1);
    if ((iVar2 != -1) && (iVar3 != -1)) {
      FUN_007b1680(local_7c,(iVar3 - iVar2) + -1);
      FUN_008917b4(local_7c);
      uVar4 = FUN_00402c80(iVar2,0xffffffff);
      FUN_00403040(uVar4,0,0xffffffff);
    }
    FUN_0085df80();
    iVar2 = FUN_00870f10();
    local_8 = local_8 & 0xffffff00;
    if (0xf < local_84) {
      FUN_0089120c(local_98[0]);
    }
LAB_0085b242:
    if (iVar2 != 0) {
      FUN_0085df00();
      pbVar5 = local_a8;
      FUN_00440a80();
      FUN_0089120c(pbVar5);
      goto LAB_0085b2b6;
    }
  }
  else if (iVar2 == 3) {
    pcVar6 = "material";
    do {
      bVar1 = *pbVar5;
      bVar8 = bVar1 < (byte)*pcVar6;
      if (bVar1 != *pcVar6) {
LAB_0085af50:
        iVar2 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_0085af55;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar8 = bVar1 < (byte)pcVar6[1];
      if (bVar1 != pcVar6[1]) goto LAB_0085af50;
      pbVar5 = pbVar5 + 2;
      pcVar6 = pcVar6 + 2;
    } while (bVar1 != 0);
    iVar2 = 0;
LAB_0085af55:
    if (iVar2 == 0) {
      pbVar5 = local_a8 + 0x1c;
      if (0xf < *(uint *)(local_a8 + 0x30)) {
        pbVar5 = *(byte **)pbVar5;
      }
      pcVar6 = "diffusemap";
      pbVar7 = pbVar5;
      do {
        bVar1 = *pbVar7;
        bVar8 = bVar1 < (byte)*pcVar6;
        if (bVar1 != *pcVar6) {
LAB_0085afa0:
          iVar2 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_0085afa5;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar7[1];
        bVar8 = bVar1 < (byte)pcVar6[1];
        if (bVar1 != pcVar6[1]) goto LAB_0085afa0;
        pbVar7 = pbVar7 + 2;
        pcVar6 = pcVar6 + 2;
      } while (bVar1 != 0);
      iVar2 = 0;
LAB_0085afa5:
      if (iVar2 != 0) {
        pcVar6 = "ambientmap";
        pbVar7 = pbVar5;
        do {
          bVar1 = *pbVar7;
          bVar8 = bVar1 < (byte)*pcVar6;
          if (bVar1 != *pcVar6) {
LAB_0085afe0:
            iVar2 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
            goto LAB_0085afe5;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar7[1];
          bVar8 = bVar1 < (byte)pcVar6[1];
          if (bVar1 != pcVar6[1]) goto LAB_0085afe0;
          pbVar7 = pbVar7 + 2;
          pcVar6 = pcVar6 + 2;
        } while (bVar1 != 0);
        iVar2 = 0;
LAB_0085afe5:
        if (iVar2 != 0) {
          pcVar6 = "specularmap";
          pbVar7 = pbVar5;
          do {
            bVar1 = *pbVar7;
            bVar8 = bVar1 < (byte)*pcVar6;
            if (bVar1 != *pcVar6) {
LAB_0085b020:
              iVar2 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
              goto LAB_0085b025;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar7[1];
            bVar8 = bVar1 < (byte)pcVar6[1];
            if (bVar1 != pcVar6[1]) goto LAB_0085b020;
            pbVar7 = pbVar7 + 2;
            pcVar6 = pcVar6 + 2;
          } while (bVar1 != 0);
          iVar2 = 0;
LAB_0085b025:
          if (iVar2 != 0) {
            pcVar6 = "emissivemap";
            pbVar7 = pbVar5;
            do {
              bVar1 = *pbVar7;
              bVar8 = bVar1 < (byte)*pcVar6;
              if (bVar1 != *pcVar6) {
LAB_0085b060:
                iVar2 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                goto LAB_0085b065;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar7[1];
              bVar8 = bVar1 < (byte)pcVar6[1];
              if (bVar1 != pcVar6[1]) goto LAB_0085b060;
              pbVar7 = pbVar7 + 2;
              pcVar6 = pcVar6 + 2;
            } while (bVar1 != 0);
            iVar2 = 0;
LAB_0085b065:
            if (iVar2 != 0) {
              pcVar6 = "opacitymap";
              pbVar7 = pbVar5;
              do {
                bVar1 = *pbVar7;
                bVar8 = bVar1 < (byte)*pcVar6;
                if (bVar1 != *pcVar6) {
LAB_0085b0a0:
                  iVar2 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                  goto LAB_0085b0a5;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar7[1];
                bVar8 = bVar1 < (byte)pcVar6[1];
                if (bVar1 != pcVar6[1]) goto LAB_0085b0a0;
                pbVar7 = pbVar7 + 2;
                pcVar6 = pcVar6 + 2;
              } while (bVar1 != 0);
              iVar2 = 0;
LAB_0085b0a5:
              if (iVar2 != 0) {
                pcVar6 = "normalmap";
                pbVar7 = pbVar5;
                do {
                  bVar1 = *pbVar7;
                  bVar8 = bVar1 < (byte)*pcVar6;
                  if (bVar1 != *pcVar6) {
LAB_0085b0e0:
                    iVar2 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                    goto LAB_0085b0e5;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar7[1];
                  bVar8 = bVar1 < (byte)pcVar6[1];
                  if (bVar1 != pcVar6[1]) goto LAB_0085b0e0;
                  pbVar7 = pbVar7 + 2;
                  pcVar6 = pcVar6 + 2;
                } while (bVar1 != 0);
                iVar2 = 0;
LAB_0085b0e5:
                if (iVar2 != 0) {
                  pcVar6 = "heightmap";
                  pbVar7 = pbVar5;
                  do {
                    bVar1 = *pbVar7;
                    bVar8 = bVar1 < (byte)*pcVar6;
                    if (bVar1 != *pcVar6) {
LAB_0085b120:
                      iVar2 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                      goto LAB_0085b125;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar7[1];
                    bVar8 = bVar1 < (byte)pcVar6[1];
                    if (bVar1 != pcVar6[1]) goto LAB_0085b120;
                    pbVar7 = pbVar7 + 2;
                    pcVar6 = pcVar6 + 2;
                  } while (bVar1 != 0);
                  iVar2 = 0;
LAB_0085b125:
                  if (iVar2 != 0) {
                    pcVar6 = "refractionmap";
                    pbVar7 = pbVar5;
                    do {
                      bVar1 = *pbVar7;
                      bVar8 = bVar1 < (byte)*pcVar6;
                      if (bVar1 != *pcVar6) {
LAB_0085b160:
                        iVar2 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                        goto LAB_0085b165;
                      }
                      if (bVar1 == 0) break;
                      bVar1 = pbVar7[1];
                      bVar8 = bVar1 < (byte)pcVar6[1];
                      if (bVar1 != pcVar6[1]) goto LAB_0085b160;
                      pbVar7 = pbVar7 + 2;
                      pcVar6 = pcVar6 + 2;
                    } while (bVar1 != 0);
                    iVar2 = 0;
LAB_0085b165:
                    if (iVar2 != 0) {
                      pcVar6 = "environmantmap";
                      pbVar7 = pbVar5;
                      do {
                        bVar1 = *pbVar7;
                        bVar8 = bVar1 < (byte)*pcVar6;
                        if (bVar1 != *pcVar6) {
LAB_0085b1a0:
                          iVar2 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                          goto LAB_0085b1a5;
                        }
                        if (bVar1 == 0) break;
                        bVar1 = pbVar7[1];
                        bVar8 = bVar1 < (byte)pcVar6[1];
                        if (bVar1 != pcVar6[1]) goto LAB_0085b1a0;
                        pbVar7 = pbVar7 + 2;
                        pcVar6 = pcVar6 + 2;
                      } while (bVar1 != 0);
                      iVar2 = 0;
LAB_0085b1a5:
                      if (iVar2 != 0) {
                        pcVar6 = "environmantnormalmap";
                        pbVar7 = pbVar5;
                        do {
                          bVar1 = *pbVar7;
                          bVar8 = bVar1 < (byte)*pcVar6;
                          if (bVar1 != *pcVar6) {
LAB_0085b1d7:
                            iVar2 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                            goto LAB_0085b1dc;
                          }
                          if (bVar1 == 0) break;
                          bVar1 = pbVar7[1];
                          bVar8 = bVar1 < (byte)pcVar6[1];
                          if (bVar1 != pcVar6[1]) goto LAB_0085b1d7;
                          pbVar7 = pbVar7 + 2;
                          pcVar6 = pcVar6 + 2;
                        } while (bVar1 != 0);
                        iVar2 = 0;
LAB_0085b1dc:
                        if (iVar2 != 0) {
                          pcVar6 = "displacementmap";
                          do {
                            bVar1 = *pbVar5;
                            bVar8 = bVar1 < (byte)*pcVar6;
                            if (bVar1 != *pcVar6) {
LAB_0085b210:
                              iVar2 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                              goto LAB_0085b215;
                            }
                            if (bVar1 == 0) break;
                            bVar1 = pbVar5[1];
                            bVar8 = bVar1 < (byte)pcVar6[1];
                            if (bVar1 != pcVar6[1]) goto LAB_0085b210;
                            pbVar5 = pbVar5 + 2;
                            pcVar6 = pcVar6 + 2;
                          } while (bVar1 != 0);
                          iVar2 = 0;
LAB_0085b215:
                          if (iVar2 != 0) goto LAB_0085b298;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      FUN_0085df80();
      iVar2 = FUN_00870f10();
      goto LAB_0085b242;
    }
  }
LAB_0085b298:
  pbVar5 = local_a8;
  FUN_00440a80();
  FUN_0089120c(pbVar5);
LAB_0085b2b6:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

