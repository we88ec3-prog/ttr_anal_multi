
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_00807830(byte *param_1,uint param_2)

{
  uint uVar1;
  short sVar2;
  short sVar3;
  byte bVar4;
  byte bVar5;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *puVar6;
  uint uVar7;
  byte *pbVar8;
  undefined4 *in_ECX;
  int iVar9;
  ushort local_100c;
  byte local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  lpCriticalSection = (LPCRITICAL_SECTION)*in_ECX;
  EnterCriticalSection(lpCriticalSection);
  uVar1 = param_2 + 6;
  if (((uVar1 < 0x1001) && (param_2 != 0)) && (in_ECX[0x1403] + uVar1 < 0x4001)) {
    puVar6 = (undefined4 *)in_ECX[0x1401];
    if (((in_ECX + 1 <= puVar6) && (puVar6 < in_ECX + 0x1401)) &&
       ((in_ECX + 1 <= (undefined4 *)(uVar1 + (int)puVar6) &&
        ((undefined4 *)(uVar1 + (int)puVar6) < in_ECX + 0x1401)))) {
      sVar2 = 0;
      sVar3 = 0;
      bVar4 = *param_1;
      local_1008[0] = bVar4 ^ 0xb6;
      local_100c = (ushort)bVar4;
      uVar7 = 1;
      if (1 < param_2) {
        if (1 < (int)(param_2 - 1)) {
          uVar7 = param_2 - 3 >> 1;
          iVar9 = uVar7 + 1;
          uVar7 = uVar7 + 2 + iVar9;
          pbVar8 = param_1 + 1;
          do {
            sVar2 = sVar2 + (ushort)*pbVar8;
            bVar5 = pbVar8[1];
            pbVar8[(int)(local_1008 + -(int)param_1)] =
                 (pbVar8 + (int)(local_1008 + -(int)param_1))[(int)param_1 - (int)(local_1008 + 1)]
                 ^ *pbVar8;
            sVar3 = sVar3 + (ushort)bVar5;
            pbVar8[(int)(local_1008 + 1) - (int)param_1] = *pbVar8 ^ bVar5;
            pbVar8 = pbVar8 + 2;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
        if (uVar7 < param_2) {
          local_100c = (ushort)bVar4;
          local_100c = local_100c + param_1[uVar7];
          local_1008[uVar7] = param_1[uVar7 - 1] ^ param_1[uVar7];
        }
        local_100c = local_100c + sVar3 + sVar2;
      }
      *puVar6 = CONCAT22(0xbbb,(short)param_2);
      *(ushort *)(puVar6 + 1) = local_100c;
      FID_conflict__memcpy((void *)(in_ECX[0x1401] + 6),local_1008,param_2);
      in_ECX[0x1403] = in_ECX[0x1403] + uVar1;
      in_ECX[0x1401] = in_ECX[0x1401] + uVar1;
      LeaveCriticalSection(lpCriticalSection);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

