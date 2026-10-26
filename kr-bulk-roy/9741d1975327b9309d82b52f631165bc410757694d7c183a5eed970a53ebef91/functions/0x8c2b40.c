
void FUN_008c2b40(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  short sVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  int unaff_EBX;
  int unaff_ESI;
  short local_24;
  int local_18;
  int local_10;
  uint local_c;
  
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_24 = 0;
  bVar1 = false;
  bVar2 = false;
  bVar3 = false;
  iVar7 = FUN_008b97e0();
  if (iVar7 == 0) {
    uVar5 = 0;
    sVar4 = 0;
    if (*(short *)(unaff_EBX + 4) != 0) {
      do {
        local_24 = sVar4;
        iVar7 = FUN_008bacd0();
        if (iVar7 != 0) {
          *(ushort *)(unaff_EBX + 4) = uVar5 - 1;
          break;
        }
        if (local_c + local_10 <= *(uint *)(unaff_ESI + 4)) {
          local_24 = local_24 + 1;
          if ((local_18 == 0x68656164) || (local_18 == 0x62686564)) {
            bVar1 = true;
            if (local_c < 0x36) goto LAB_008c2c7c;
            iVar7 = FUN_008b97e0();
            if (iVar7 != 0) goto LAB_008c2ca4;
            FUN_008b9c00();
            iVar7 = FUN_008b97e0();
            if (iVar7 != 0) goto LAB_008c2ca4;
          }
          else if (local_18 == 0x53494e47) {
            bVar2 = true;
          }
          else if (local_18 == 0x4d455441) {
            bVar3 = true;
          }
        }
        uVar5 = uVar5 + 1;
        sVar4 = local_24;
      } while (uVar5 < *(ushort *)(unaff_EBX + 4));
    }
    *(short *)(unaff_EBX + 4) = local_24;
    if (local_24 == 0) {
      __security_check_cookie(uVar6 ^ (uint)&stack0xfffffffc);
      return;
    }
    if ((!bVar1) && ((!bVar2 || (!bVar3)))) {
LAB_008c2c7c:
      __security_check_cookie(uVar6 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
LAB_008c2ca4:
  __security_check_cookie(uVar6 ^ (uint)&stack0xfffffffc);
  return;
}

