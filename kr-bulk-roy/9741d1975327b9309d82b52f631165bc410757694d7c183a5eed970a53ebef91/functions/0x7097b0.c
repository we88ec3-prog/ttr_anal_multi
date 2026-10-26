
void FUN_007097b0(int param_1)

{
  byte bVar1;
  uint *puVar2;
  undefined4 *puVar3;
  tm *_Tm;
  byte *pbVar4;
  int iVar5;
  undefined4 uVar6;
  size_t sVar7;
  byte *pbVar8;
  byte *pbVar9;
  bool bVar10;
  undefined1 auStack_30c [4];
  byte *local_308;
  char local_304;
  byte local_303;
  undefined1 local_302;
  __time64_t local_300;
  undefined4 local_2f8 [2];
  undefined4 local_2f0;
  byte *local_2e8;
  int local_2e4;
  int local_2e0;
  byte local_2dc [512];
  byte local_dc [4];
  char local_d8 [204];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_30c;
  puVar3 = *(undefined4 **)(param_1 + 0xc);
  if (((puVar3 < *(undefined4 **)(param_1 + 8)) && (puVar3 != &DAT_00c0bfc8)) &&
     (0 < (int)puVar3[2])) {
    local_308 = (byte *)FUN_006f6210(param_1);
  }
  else {
    local_308 = &DAT_00c41240;
  }
  pbVar9 = local_308;
  puVar3 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  if (((puVar3 < *(undefined4 **)(param_1 + 8)) && (puVar3 != &DAT_00c0bfc8)) &&
     (0 < *(int *)(*(int *)(param_1 + 0xc) + 0x18))) {
    FUN_006f6290(param_1,2);
    local_300 = FUN_008fed46();
  }
  else {
    local_300 = __time64((__time64_t *)0x0);
  }
  if (*pbVar9 == 0x21) {
    _Tm = __gmtime64(&local_300);
    pbVar9 = pbVar9 + 1;
    local_308 = pbVar9;
  }
  else {
    _Tm = FID_conflict___localtime64((__time32_t *)&local_300);
  }
  if (_Tm == (tm *)0x0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  }
  else {
    pbVar8 = &DAT_00c43974;
    pbVar4 = pbVar9;
    do {
      bVar1 = *pbVar4;
      bVar10 = bVar1 < *pbVar8;
      if (bVar1 != *pbVar8) {
LAB_007098a2:
        iVar5 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_007098a7;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar10 = bVar1 < pbVar8[1];
      if (bVar1 != pbVar8[1]) goto LAB_007098a2;
      pbVar4 = pbVar4 + 2;
      pbVar8 = pbVar8 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_007098a7:
    if (iVar5 == 0) {
      if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44))
      {
        FUN_006fb3a0();
      }
      puVar3 = *(undefined4 **)(param_1 + 8);
      uVar6 = FUN_006f99a0(param_1,0,9);
      *puVar3 = uVar6;
      puVar3[2] = 5;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      FUN_00709600(_Tm->tm_sec);
      FUN_00709600(_Tm->tm_min);
      FUN_00709600(_Tm->tm_hour);
      FUN_00709600(_Tm->tm_mday);
      FUN_00709600(_Tm->tm_mon + 1);
      FUN_00709600(_Tm->tm_year + 0x76c);
      FUN_00709600(_Tm->tm_wday + 1);
      FUN_00709600(_Tm->tm_yday + 1);
      iVar5 = _Tm->tm_isdst;
      if (-1 < iVar5) {
        puVar2 = *(uint **)(param_1 + 8);
        puVar2[2] = 1;
        *puVar2 = (uint)(iVar5 != 0);
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        iVar5 = *(int *)(param_1 + 8);
        local_2f8[0] = FUN_006fec70(param_1,"isdst",5);
        local_2f0 = 4;
        FUN_006fb9a0(param_1,iVar5 + -0x20,local_2f8,*(int *)(param_1 + 8) + -0x10);
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
      }
    }
    else {
      bVar1 = *pbVar9;
      local_2e8 = local_2dc;
      local_304 = '%';
      local_302 = 0;
      local_2e4 = 0;
      pbVar4 = local_308;
      while (local_308 = pbVar9, local_2e0 = param_1, bVar1 != 0) {
        if ((bVar1 == 0x25) && (local_308[1] != 0)) {
          local_303 = local_308[1];
          pbVar9 = local_308 + 1;
          local_308 = pbVar9;
          sVar7 = _strftime(local_d8,200,&local_304,_Tm);
          FUN_006f6c40(local_d8,sVar7);
          local_308 = pbVar9;
        }
        else {
          if (local_dc <= local_2e8) {
            local_308 = pbVar4;
            iVar5 = FUN_006f6af0();
            if (iVar5 != 0) {
              FUN_006f6b60(&local_2e8);
            }
          }
          *local_2e8 = *local_308;
          local_2e8 = local_2e8 + 1;
        }
        pbVar4 = local_308 + 1;
        pbVar9 = pbVar4;
        param_1 = local_2e0;
        bVar1 = local_308[1];
      }
      iVar5 = (int)local_2e8 - (int)local_2dc;
      local_308 = pbVar4;
      if (iVar5 != 0) {
        if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)
           ) {
          FUN_006fb3a0();
        }
        puVar3 = *(undefined4 **)(param_1 + 8);
        uVar6 = FUN_006fec70(param_1,local_2dc,iVar5);
        *puVar3 = uVar6;
        puVar3[2] = 4;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        local_2e8 = local_2dc;
        local_2e4 = local_2e4 + 1;
      }
      FUN_006f5bb0();
    }
  }
  __security_check_cookie(local_c ^ (uint)auStack_30c);
  return;
}

