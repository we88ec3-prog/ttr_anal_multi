
void FUN_00871670(char *param_1,char *param_2)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  uint extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  uint uVar8;
  int *unaff_EDI;
  bool bVar9;
  undefined8 uVar10;
  double dVar11;
  char **ppcVar12;
  uint *puVar13;
  undefined1 *puVar14;
  char *local_378;
  undefined4 local_36c;
  undefined1 local_34c [28];
  uint local_330;
  char *local_320;
  float *local_31c;
  uint local_318;
  byte local_314 [520];
  byte local_10c [260];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_320 = param_1;
  iVar5 = -(int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)(local_10c + iVar5)] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  __strlwr((char *)local_10c);
  puVar14 = local_34c;
  (**(code **)(*unaff_EDI + 0x10))();
  local_318 = 0;
  uVar6 = extraout_EDX;
  if (local_330 != 0) {
    do {
      uVar8 = local_318;
      uVar10 = (**(code **)(*unaff_EDI + 0x48))();
      uVar6 = (uint)((ulonglong)uVar10 >> 0x20);
      if ((int)uVar10 != 0) {
        (**(code **)(*unaff_EDI + 0x10))();
        pcVar3 = local_378;
        do {
          cVar1 = *pcVar3;
          pcVar3[(int)(local_314 + -(int)local_378)] = cVar1;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        __strlwr((char *)local_314);
        pbVar7 = local_10c;
        pbVar4 = local_314;
        do {
          bVar2 = *pbVar4;
          uVar6 = (uint)bVar2;
          bVar9 = bVar2 < *pbVar7;
          if (bVar2 != *pbVar7) {
LAB_00871760:
            iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
            goto LAB_00871765;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar4[1];
          uVar6 = (uint)bVar2;
          bVar9 = bVar2 < pbVar7[1];
          if (bVar2 != pbVar7[1]) goto LAB_00871760;
          pbVar4 = pbVar4 + 2;
          pbVar7 = pbVar7 + 2;
        } while (bVar2 != 0);
        iVar5 = 0;
LAB_00871765:
        if (iVar5 == 0) {
          pbVar7 = local_314;
          do {
            bVar2 = *pbVar7;
            pbVar7 = pbVar7 + 1;
          } while (bVar2 != 0);
          uVar6 = (int)pbVar7 - (int)(local_314 + 1);
          pbVar7 = local_10c;
          do {
            bVar2 = *pbVar7;
            pbVar7 = pbVar7 + 1;
          } while (bVar2 != 0);
          uVar8 = local_318;
          if (uVar6 == (int)pbVar7 - (int)(local_10c + 1)) {
            switch(local_36c) {
            case 1:
              puVar13 = &local_318;
              local_318 = 0;
              (**(code **)(*unaff_EDI + 0x5c))();
              if (local_318 == 0) {
                *local_31c = 0.0;
                __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX_02,puVar13);
                return;
              }
              *local_31c = 1.0;
              __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX_02,puVar13);
              return;
            case 2:
              puVar13 = &local_318;
              local_318 = 0;
              (**(code **)(*unaff_EDI + 0x6c))();
              *local_31c = (float)(int)local_318;
              __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX_00,puVar13);
              return;
            case 3:
              (**(code **)(*unaff_EDI + 0x7c))();
              __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX_01,local_31c);
              return;
            case 4:
              ppcVar12 = &local_320;
              (**(code **)(*unaff_EDI + 0xcc))();
              dVar11 = _atof(local_320);
              *local_31c = (float)dVar11;
              __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,local_31c,ppcVar12);
              return;
            }
            goto switchD_008717d4_default;
          }
        }
      }
      local_318 = uVar8 + 1;
    } while (local_318 < local_330);
  }
  *local_31c = 0.0;
switchD_008717d4_default:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,uVar6,puVar14);
  return;
}

