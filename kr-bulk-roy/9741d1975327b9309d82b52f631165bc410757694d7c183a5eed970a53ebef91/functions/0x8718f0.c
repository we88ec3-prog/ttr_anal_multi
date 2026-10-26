
void FUN_008718f0(undefined4 param_1,char *param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined4 extraout_EDX;
  uint uVar7;
  int *unaff_EDI;
  bool bVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined1 *puVar11;
  undefined1 local_390 [28];
  uint local_374;
  char *local_364;
  int local_358;
  undefined4 local_350;
  undefined4 local_338;
  undefined4 *local_334;
  uint local_330;
  undefined4 local_32c;
  undefined4 local_328;
  undefined4 local_324;
  undefined4 local_320;
  byte local_31c [520];
  byte local_114 [268];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_338 = param_1;
  iVar3 = -(int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)(local_114 + iVar3)] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  __strlwr((char *)local_114);
  puVar11 = local_390;
  (**(code **)(*unaff_EDI + 0x10))();
  local_330 = 0;
  if (local_374 != 0) {
    do {
      uVar7 = local_330;
      iVar3 = (**(code **)(*unaff_EDI + 0x48))();
      if (iVar3 != 0) {
        (**(code **)(*unaff_EDI + 0x10))();
        pcVar4 = local_364;
        do {
          cVar1 = *pcVar4;
          pcVar4[(int)(local_31c + -(int)local_364)] = cVar1;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        __strlwr((char *)local_31c);
        pbVar6 = local_114;
        pbVar5 = local_31c;
        do {
          bVar2 = *pbVar5;
          bVar8 = bVar2 < *pbVar6;
          if (bVar2 != *pbVar6) {
LAB_008719e0:
            iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
            goto LAB_008719e5;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar5[1];
          bVar8 = bVar2 < pbVar6[1];
          if (bVar2 != pbVar6[1]) goto LAB_008719e0;
          pbVar5 = pbVar5 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar2 != 0);
        iVar3 = 0;
LAB_008719e5:
        if (iVar3 == 0) {
          pbVar6 = local_31c;
          do {
            bVar2 = *pbVar6;
            pbVar6 = pbVar6 + 1;
          } while (bVar2 != 0);
          iVar3 = (int)pbVar6 - (int)(local_31c + 1);
          pbVar6 = local_114;
          do {
            bVar2 = *pbVar6;
            pbVar6 = pbVar6 + 1;
          } while (bVar2 != 0);
          uVar7 = local_330;
          if (iVar3 == (int)pbVar6 - (int)(local_114 + 1)) {
            if (local_358 == 3) {
              local_334[2] = 0;
              local_334[1] = 0;
              puVar9 = &local_32c;
              *local_334 = 0;
              local_334[3] = 0;
              uVar10 = local_350;
              (**(code **)(*unaff_EDI + 0x84))();
              switch(local_350) {
              case 1:
                local_334[3] = local_32c;
                local_334[2] = local_32c;
                local_334[1] = local_32c;
                *local_334 = local_32c;
                __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX,puVar9,uVar10)
                ;
                return;
              case 2:
                *local_334 = local_32c;
                local_334[1] = local_328;
                __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX,puVar9,uVar10)
                ;
                return;
              case 3:
                *local_334 = local_32c;
                local_334[1] = local_328;
                local_334[2] = local_324;
                __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX,puVar9,uVar10)
                ;
                return;
              case 4:
                *local_334 = local_32c;
                local_334[1] = local_328;
                local_334[2] = local_324;
                local_334[3] = local_320;
              }
              __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX,puVar9,uVar10);
              return;
            }
            goto LAB_00871a6f;
          }
        }
      }
      local_330 = uVar7 + 1;
    } while (local_330 < local_374);
  }
  local_32c = 0;
  local_328 = 0;
  local_324 = 0;
  *local_334 = 0;
  local_320 = 0;
  local_334[1] = 0;
  iVar3 = 0;
  local_334[2] = 0;
  local_334[3] = 0;
LAB_00871a6f:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,iVar3,puVar11);
  return;
}

