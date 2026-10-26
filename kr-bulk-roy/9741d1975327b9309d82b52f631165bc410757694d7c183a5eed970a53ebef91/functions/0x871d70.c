
void FUN_00871d70(undefined4 param_1,undefined4 param_2)

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
  char *local_364;
  int local_358;
  undefined1 local_338 [4];
  char *local_334;
  undefined4 local_328;
  undefined4 local_324;
  char *local_320;
  byte local_31c [520];
  byte local_114 [268];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_324 = param_2;
  local_328 = param_1;
  iVar3 = 0;
  do {
    bVar1 = "script"[iVar3];
    local_114[iVar3] = bVar1;
    iVar3 = iVar3 + 1;
  } while (bVar1 != 0);
  __strlwr((char *)local_114);
  puVar10 = local_338;
  (**(code **)(*unaff_EDI + 0x18))();
  local_320 = (char *)0x0;
  if (local_334 == (char *)0x0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX,puVar10);
    return;
  }
  do {
    pcVar6 = local_320;
    iVar3 = (**(code **)(*unaff_EDI + 0x48))();
    if (iVar3 != 0) {
      (**(code **)(*unaff_EDI + 0x10))();
      pcVar4 = local_364;
      do {
        cVar2 = *pcVar4;
        pcVar4[(int)(local_31c + -(int)local_364)] = cVar2;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      __strlwr((char *)local_31c);
      if (local_358 == 4) {
        pbVar7 = local_114;
        pbVar5 = local_31c;
        do {
          bVar1 = *pbVar5;
          bVar8 = bVar1 < *pbVar7;
          if (bVar1 != *pbVar7) {
LAB_00871e80:
            iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
            goto LAB_00871e85;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar5[1];
          bVar8 = bVar1 < pbVar7[1];
          if (bVar1 != pbVar7[1]) goto LAB_00871e80;
          pbVar5 = pbVar5 + 2;
          pbVar7 = pbVar7 + 2;
        } while (bVar1 != 0);
        iVar3 = 0;
LAB_00871e85:
        if (iVar3 == 0) {
          pbVar7 = local_31c;
          do {
            bVar1 = *pbVar7;
            pbVar7 = pbVar7 + 1;
          } while (bVar1 != 0);
          pbVar5 = local_114;
          do {
            bVar1 = *pbVar5;
            pbVar5 = pbVar5 + 1;
          } while (bVar1 != 0);
          pcVar6 = local_320;
          if ((int)pbVar7 - (int)(local_31c + 1) == (int)pbVar5 - (int)(local_114 + 1)) {
            ppcVar9 = &local_320;
            local_320 = (char *)0x0;
            (**(code **)(*unaff_EDI + 0xcc))();
            pcVar6 = local_320;
            do {
              cVar2 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar2 != '\0');
            FUN_00402a70(local_320,(int)pcVar6 - (int)(local_320 + 1));
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX_00,ppcVar9);
            return;
          }
        }
      }
    }
    local_320 = pcVar6 + 1;
    if (local_334 <= local_320) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  } while( true );
}

