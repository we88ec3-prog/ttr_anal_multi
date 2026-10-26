
void FUN_0071b390(int param_1,uint *param_2,uint param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  byte *in_EAX;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  code *local_10;
  code *local_c;
  uint *local_8;
  
  switch(param_3 >> 4 & 0xf) {
  case 0:
    local_c = FUN_00722280;
    break;
  case 1:
    local_c = FUN_007225e0;
    break;
  case 2:
    local_c = FUN_007221d0;
    break;
  case 3:
    local_c = FUN_00722500;
    break;
  case 4:
  case 6:
    local_c = FUN_00722120;
    break;
  case 5:
  case 7:
    local_c = FUN_00722420;
    break;
  case 8:
  case 10:
  case 0xc:
  case 0xe:
    local_c = FUN_00722000;
    break;
  case 9:
  case 0xb:
  case 0xd:
  case 0xf:
    local_c = FUN_007222d0;
    break;
  default:
    local_c = (code *)0x0;
  }
  switch(param_3 >> 4 & 3) {
  case 0:
    local_10 = FUN_00721d60;
    break;
  case 1:
    local_10 = FUN_00721db0;
    break;
  case 2:
    local_10 = FUN_00721e60;
    break;
  case 3:
    local_10 = FUN_00721f20;
    break;
  default:
    local_10 = (code *)0x0;
  }
  local_8 = param_2;
  bVar2 = *in_EAX;
  if (bVar2 != 0) {
    do {
      if (bVar2 == 0x3c) {
LAB_0071b50a:
        pbVar4 = in_EAX + 1;
LAB_0071b50b:
        bVar2 = *pbVar4;
        if (((&DAT_00c0b650)[bVar2] & 0x80) == 0) {
          if (bVar2 == 0x2f) {
            pbVar5 = (byte *)local_8[2];
            pbVar4 = pbVar4 + 1;
            if (pbVar5 == (byte *)0x0) goto LAB_0071b8a7;
            bVar2 = *pbVar4;
            bVar1 = (&DAT_00c0b650)[bVar2];
            while ((bVar1 & 0x40) != 0) {
              bVar1 = *pbVar5;
              pbVar5 = pbVar5 + 1;
              pbVar4 = pbVar4 + 1;
              if (bVar2 != bVar1) goto LAB_0071b8a7;
              bVar2 = *pbVar4;
              bVar1 = (&DAT_00c0b650)[bVar2];
            }
            if (*pbVar5 != 0) {
              if (((*pbVar4 == 0) && (*pbVar5 == (byte)param_4)) && (pbVar5[1] == 0)) {
LAB_0071b856:
                *(byte **)(param_1 + 8) = pbVar4;
                    /* WARNING: Subroutine does not return */
                FID_conflict____longjmp_internal((int *)(param_1 + 0xc),0xd);
              }
              goto LAB_0071b8a7;
            }
            local_8 = (uint *)local_8[1];
            bVar2 = (&DAT_00c0b650)[*pbVar4];
            while ((bVar2 & 8) != 0) {
              pbVar5 = pbVar4 + 1;
              pbVar4 = pbVar4 + 1;
              bVar2 = (&DAT_00c0b650)[*pbVar5];
            }
            if (*pbVar4 == 0) {
              if ((byte)param_4 != 0x3e) goto LAB_0071b856;
            }
            else {
              if (*pbVar4 != 0x3e) goto LAB_0071b856;
              pbVar4 = pbVar4 + 1;
            }
          }
          else if (bVar2 == 0x3f) {
            pbVar4 = (byte *)FUN_0071b150(param_1,&local_8,param_4);
            if ((*local_8 & 7) == 6) goto LAB_0071b693;
          }
          else {
            if (bVar2 != 0x21) {
              if ((*pbVar4 == 0) && ((byte)param_4 == 0x3f)) {
                *(byte **)(param_1 + 8) = pbVar4;
                    /* WARNING: Subroutine does not return */
                FID_conflict____longjmp_internal((int *)(param_1 + 0xc),6);
              }
              *(byte **)(param_1 + 8) = pbVar4;
                    /* WARNING: Subroutine does not return */
              FID_conflict____longjmp_internal((int *)(param_1 + 0xc),5);
            }
            pbVar4 = (byte *)FUN_0071ade0(param_1,local_8,param_3,param_4);
          }
        }
        else {
          local_8 = (uint *)FUN_0071a530(param_1);
          if (local_8 == (uint *)0x0) {
LAB_0071b836:
            *(byte **)(param_1 + 8) = pbVar4;
                    /* WARNING: Subroutine does not return */
            FID_conflict____longjmp_internal((int *)(param_1 + 0xc),3);
          }
          local_8[2] = (uint)pbVar4;
          bVar2 = (&DAT_00c0b650)[*pbVar4];
          pbVar5 = pbVar4;
          while ((bVar2 & 0x40) != 0) {
            pbVar4 = pbVar5 + 1;
            pbVar5 = pbVar5 + 1;
            bVar2 = (&DAT_00c0b650)[*pbVar4];
          }
          bVar2 = *pbVar5;
          *pbVar5 = 0;
          pbVar4 = pbVar5 + 1;
          if (bVar2 != 0x3e) {
            if (((&DAT_00c0b650)[bVar2] & 8) == 0) {
              if (bVar2 == 0x2f) {
                bVar2 = *pbVar4;
                if ((bVar2 != 0x3e) && ((bVar2 != 0 || ((byte)param_4 != 0x3e)))) {
LAB_0071b5b6:
                  *(byte **)(param_1 + 8) = pbVar4;
                    /* WARNING: Subroutine does not return */
                  FID_conflict____longjmp_internal((int *)(param_1 + 0xc),0xb);
                }
                local_8 = (uint *)local_8[1];
                pbVar4 = pbVar4 + (bVar2 == 0x3e);
              }
              else if ((bVar2 != 0) || (pbVar4 = pbVar5, (byte)param_4 != 0x3e)) goto LAB_0071b5b6;
            }
            else {
LAB_0071b693:
              while( true ) {
                bVar2 = (&DAT_00c0b650)[*pbVar4];
                while ((bVar2 & 8) != 0) {
                  pbVar5 = pbVar4 + 1;
                  pbVar4 = pbVar4 + 1;
                  bVar2 = (&DAT_00c0b650)[*pbVar5];
                }
                if (((&DAT_00c0b650)[*pbVar4] & 0x80) == 0) break;
                iVar3 = FUN_0071a570(local_8);
                if (iVar3 == 0) goto LAB_0071b836;
                *(byte **)(iVar3 + 4) = pbVar4;
                bVar2 = (&DAT_00c0b650)[*pbVar4];
                while ((bVar2 & 0x40) != 0) {
                  pbVar5 = pbVar4 + 1;
                  pbVar4 = pbVar4 + 1;
                  bVar2 = (&DAT_00c0b650)[*pbVar5];
                }
                bVar2 = *pbVar4;
                if (bVar2 == 0) goto LAB_0071b7a4;
                *pbVar4 = 0;
                pbVar5 = pbVar4 + 1;
                pbVar4 = pbVar4 + 1;
                if (*pbVar5 == 0) goto LAB_0071b7a4;
                if (((&DAT_00c0b650)[bVar2] & 8) != 0) {
                  bVar2 = (&DAT_00c0b650)[*pbVar5];
                  while ((bVar2 & 8) != 0) {
                    pbVar5 = pbVar4 + 1;
                    pbVar4 = pbVar4 + 1;
                    bVar2 = (&DAT_00c0b650)[*pbVar5];
                  }
                  bVar2 = *pbVar4;
                  if (bVar2 == 0) goto LAB_0071b7a4;
                  pbVar4 = pbVar4 + 1;
                }
                if (bVar2 != 0x3d) goto LAB_0071b7a4;
                bVar2 = (&DAT_00c0b650)[*pbVar4];
                while ((bVar2 & 8) != 0) {
                  pbVar5 = pbVar4 + 1;
                  pbVar4 = pbVar4 + 1;
                  bVar2 = (&DAT_00c0b650)[*pbVar5];
                }
                bVar2 = *pbVar4;
                if ((bVar2 != 0x22) && (bVar2 != 0x27)) goto LAB_0071b7a4;
                *(byte **)(iVar3 + 8) = pbVar4 + 1;
                pbVar4 = (byte *)(*local_c)(pbVar4 + 1,bVar2);
                if (pbVar4 == (byte *)0x0) {
                  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar3 + 8);
                    /* WARNING: Subroutine does not return */
                  FID_conflict____longjmp_internal((int *)(param_1 + 0xc),0xc);
                }
                if (((&DAT_00c0b650)[*pbVar4] & 0x80) != 0) {
LAB_0071b7a4:
                  *(byte **)(param_1 + 8) = pbVar4;
                    /* WARNING: Subroutine does not return */
                  FID_conflict____longjmp_internal((int *)(param_1 + 0xc),0xc);
                }
              }
              bVar2 = *pbVar4;
              if (bVar2 == 0x2f) {
                pbVar5 = pbVar4 + 1;
                pbVar6 = pbVar4 + 1;
                if (*pbVar5 == 0x3e) {
                  local_8 = (uint *)local_8[1];
                  pbVar4 = pbVar4 + 2;
                }
                else {
                  pbVar4 = pbVar6;
                  if ((*pbVar5 != 0) || ((byte)param_4 != 0x3e)) {
LAB_0071b7f2:
                    *(byte **)(param_1 + 8) = pbVar4;
                    /* WARNING: Subroutine does not return */
                    FID_conflict____longjmp_internal((int *)(param_1 + 0xc),0xb);
                  }
                  local_8 = (uint *)local_8[1];
                }
              }
              else if (bVar2 == 0x3e) {
                pbVar4 = pbVar4 + 1;
              }
              else if ((bVar2 != 0) || ((byte)param_4 != 0x3e)) goto LAB_0071b7f2;
            }
          }
        }
      }
      else {
        bVar2 = (&DAT_00c0b650)[bVar2];
        pbVar4 = in_EAX;
        while ((bVar2 & 8) != 0) {
          pbVar5 = pbVar4 + 1;
          pbVar4 = pbVar4 + 1;
          bVar2 = (&DAT_00c0b650)[*pbVar5];
        }
        if (((param_3 & 8) != 0) && (in_EAX != pbVar4)) {
LAB_0071b49a:
          if (local_8[1] == 0) {
            bVar2 = *in_EAX;
            if (bVar2 != 0) {
              while (bVar2 != 0x3c) {
                bVar2 = in_EAX[1];
                in_EAX = in_EAX + 1;
                pbVar4 = in_EAX;
                if (bVar2 == 0) goto LAB_0071b89f;
              }
            }
            pbVar4 = in_EAX;
            if (*in_EAX != 0) goto LAB_0071b50a;
          }
          else {
            iVar3 = FUN_0071a530(param_1);
            if (iVar3 == 0) {
              *(byte **)(param_1 + 8) = in_EAX;
                    /* WARNING: Subroutine does not return */
              FID_conflict____longjmp_internal((int *)(param_1 + 0xc),3);
            }
            *(byte **)(iVar3 + 0xc) = in_EAX;
            pbVar4 = (byte *)(*local_10)(in_EAX);
            local_8 = *(uint **)(iVar3 + 4);
            if (*pbVar4 != 0) goto LAB_0071b50b;
          }
          break;
        }
        if (*pbVar4 != 0x3c) {
          if (*pbVar4 != 0) goto LAB_0071b49a;
          break;
        }
      }
      bVar2 = *pbVar4;
      in_EAX = pbVar4;
    } while (bVar2 != 0);
LAB_0071b89f:
    if (local_8 != param_2) {
LAB_0071b8a7:
      *(byte **)(param_1 + 8) = pbVar4;
                    /* WARNING: Subroutine does not return */
      FID_conflict____longjmp_internal((int *)(param_1 + 0xc),0xe);
    }
  }
  return;
}

