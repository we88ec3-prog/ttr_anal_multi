
void FUN_008dbb10(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  char cVar8;
  char *in_ECX;
  byte *pbVar9;
  char *local_110;
  char local_109;
  byte local_108 [256];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar2 = *(int *)(param_3 + 0x68);
  iVar4 = FUN_008b97e0(iVar2,param_2);
  if (iVar4 == 0) {
    pbVar9 = local_108;
    local_109 = '\x01';
    bVar3 = false;
    pbVar7 = pbVar9;
    local_110 = in_ECX;
    while (local_110 < in_ECX + param_1) {
      if (pbVar7 <= pbVar9) {
        iVar4 = FUN_008b9850(iVar2);
        uVar5 = *(int *)(iVar2 + 4) - iVar4;
        if (uVar5 == 0) goto LAB_008dbc7d;
        if (0xff < uVar5) {
          uVar5 = 0x100;
        }
        iVar6 = FUN_008bab70(iVar2,local_108,uVar5);
        if (iVar6 != 0) break;
        pbVar9 = local_108;
        iVar6 = FUN_008b9850(iVar2);
        pbVar7 = pbVar9 + (iVar6 - iVar4);
      }
      bVar1 = *pbVar9;
      if (bVar1 - 0x30 < 10) {
        cVar8 = bVar1 - 0x30;
LAB_008dbc21:
        if (local_109 == '\0') {
          *local_110 = *local_110 + cVar8;
          local_110 = local_110 + 1;
        }
        else {
          *local_110 = cVar8 << 4;
        }
        local_109 = '\x01' - local_109;
        if (bVar3) break;
      }
      else {
        if ((0x60 < bVar1) && (bVar1 < 0x67)) {
          cVar8 = bVar1 + 0x9f;
          goto LAB_008dbc21;
        }
        if ((0x40 < bVar1) && (bVar1 < 0x47)) {
          cVar8 = bVar1 - 0x37;
          goto LAB_008dbc21;
        }
        if ((((bVar1 != 0x20) && (bVar1 != 9)) && (bVar1 != 0xd)) &&
           (((bVar1 != 10 && (bVar1 != 0xc)) && (bVar1 != 0)))) {
          if (bVar1 != 0x3e) {
LAB_008dbc7d:
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
            return;
          }
          cVar8 = '\0';
          bVar3 = true;
          goto LAB_008dbc21;
        }
      }
      pbVar9 = pbVar9 + 1;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

