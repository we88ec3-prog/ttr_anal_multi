
void FUN_00871ba0(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  byte *pbVar5;
  char *pcVar6;
  byte *pbVar7;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int *unaff_EDI;
  bool bVar8;
  char **ppcVar9;
  undefined1 *puVar10;
  char *local_358;
  int local_34c;
  undefined1 local_32c [8];
  char *local_324;
  undefined4 local_320;
  undefined4 local_31c;
  char *local_318;
  byte local_314 [520];
  byte local_10c [260];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_31c = param_2;
  local_320 = param_1;
  iVar3 = 0;
  do {
    bVar1 = "script"[iVar3];
    local_10c[iVar3] = bVar1;
    iVar3 = iVar3 + 1;
  } while (bVar1 != 0);
  __strlwr((char *)local_10c);
  puVar10 = local_32c;
  (**(code **)(*unaff_EDI + 0x14))();
  local_318 = (char *)0x0;
  if (local_324 == (char *)0x0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX,puVar10);
    return;
  }
  do {
    pcVar6 = local_318;
    iVar3 = (**(code **)(*unaff_EDI + 0x48))();
    if (iVar3 != 0) {
      (**(code **)(*unaff_EDI + 0x10))();
      pcVar4 = local_358;
      do {
        cVar2 = *pcVar4;
        pcVar4[(int)(local_314 + -(int)local_358)] = cVar2;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      __strlwr((char *)local_314);
      if (local_34c == 4) {
        pbVar7 = local_10c;
        pbVar5 = local_314;
        do {
          bVar1 = *pbVar5;
          bVar8 = bVar1 < *pbVar7;
          if (bVar1 != *pbVar7) {
LAB_00871cb0:
            iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
            goto LAB_00871cb5;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar5[1];
          bVar8 = bVar1 < pbVar7[1];
          if (bVar1 != pbVar7[1]) goto LAB_00871cb0;
          pbVar5 = pbVar5 + 2;
          pbVar7 = pbVar7 + 2;
        } while (bVar1 != 0);
        iVar3 = 0;
LAB_00871cb5:
        if (iVar3 == 0) {
          pbVar7 = local_314;
          do {
            bVar1 = *pbVar7;
            pbVar7 = pbVar7 + 1;
          } while (bVar1 != 0);
          pbVar5 = local_10c;
          do {
            bVar1 = *pbVar5;
            pbVar5 = pbVar5 + 1;
          } while (bVar1 != 0);
          pcVar6 = local_318;
          if ((int)pbVar7 - (int)(local_314 + 1) == (int)pbVar5 - (int)(local_10c + 1)) {
            ppcVar9 = &local_318;
            local_318 = (char *)0x0;
            (**(code **)(*unaff_EDI + 0xcc))();
            pcVar6 = local_318;
            do {
              cVar2 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar2 != '\0');
            FUN_00402a70(local_318,(int)pcVar6 - (int)(local_318 + 1));
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX_00,ppcVar9);
            return;
          }
        }
      }
    }
    local_318 = pcVar6 + 1;
    if (local_324 <= local_318) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  } while( true );
}

