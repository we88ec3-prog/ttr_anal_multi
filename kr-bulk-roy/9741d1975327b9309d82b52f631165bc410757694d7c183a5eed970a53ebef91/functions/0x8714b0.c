
void FUN_008714b0(char *param_1,char *param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  uint uVar7;
  int *unaff_EDI;
  bool bVar8;
  char **ppcVar9;
  undefined1 *puVar10;
  undefined1 local_378 [28];
  uint local_35c;
  char *local_34c;
  int local_340;
  uint local_31c;
  char *local_318;
  byte local_314 [520];
  byte local_10c [260];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_318 = param_1;
  iVar3 = -(int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)(local_10c + iVar3)] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  __strlwr((char *)local_10c);
  puVar10 = local_378;
  (**(code **)(*unaff_EDI + 0x10))();
  local_31c = 0;
  if (local_35c == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX,puVar10);
    return;
  }
  do {
    uVar7 = local_31c;
    iVar3 = (**(code **)(*unaff_EDI + 0x48))();
    if (iVar3 != 0) {
      (**(code **)(*unaff_EDI + 0x10))();
      pcVar4 = local_34c;
      do {
        cVar1 = *pcVar4;
        pcVar4[(int)(local_314 + -(int)local_34c)] = cVar1;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      __strlwr((char *)local_314);
      if (local_340 == 4) {
        pbVar6 = local_10c;
        pbVar5 = local_314;
        do {
          bVar2 = *pbVar5;
          bVar8 = bVar2 < *pbVar6;
          if (bVar2 != *pbVar6) {
LAB_008715b6:
            iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
            goto LAB_008715bb;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar5[1];
          bVar8 = bVar2 < pbVar6[1];
          if (bVar2 != pbVar6[1]) goto LAB_008715b6;
          pbVar5 = pbVar5 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar2 != 0);
        iVar3 = 0;
LAB_008715bb:
        if (iVar3 == 0) {
          pbVar6 = local_314;
          do {
            bVar2 = *pbVar6;
            pbVar6 = pbVar6 + 1;
          } while (bVar2 != 0);
          pbVar5 = local_10c;
          do {
            bVar2 = *pbVar5;
            pbVar5 = pbVar5 + 1;
          } while (bVar2 != 0);
          uVar7 = local_31c;
          if ((int)pbVar6 - (int)(local_314 + 1) == (int)pbVar5 - (int)(local_10c + 1)) {
            ppcVar9 = &local_318;
            (**(code **)(*unaff_EDI + 0xcc))();
            pcVar4 = local_318;
            do {
              cVar1 = *pcVar4;
              pcVar4 = pcVar4 + 1;
            } while (cVar1 != '\0');
            FUN_00402a70(local_318,(int)pcVar4 - (int)(local_318 + 1));
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX_00,ppcVar9);
            return;
          }
        }
      }
    }
    local_31c = uVar7 + 1;
    if (local_35c <= local_31c) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  } while( true );
}

