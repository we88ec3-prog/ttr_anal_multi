
void FUN_006d7560(int param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  DWORD DVar4;
  int iVar5;
  char *pcVar6;
  undefined4 ****ppppuVar7;
  char *pcVar8;
  byte *pbVar9;
  uint uVar10;
  bool bVar11;
  undefined1 local_1b0 [12];
  byte local_1a4 [368];
  undefined4 ***local_34 [4];
  uint local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00921785;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar3;
  if (param_1 != 0) {
    DVar4 = GetFileAttributesA("Master.stp");
    if (DVar4 == 0xffffffff) goto LAB_006d77e3;
    FUN_00715270(local_1b0);
    local_8 = 0;
    iVar5 = FUN_00715620(0);
    if (iVar5 != 0) {
      local_8 = 0xffffffff;
      FUN_00715380(local_1b0);
      goto LAB_006d77e3;
    }
    pbVar9 = local_1a4;
    pcVar8 = "Master0z";
    do {
      bVar1 = *pcVar8;
      bVar11 = bVar1 < *pbVar9;
      if (bVar1 != *pbVar9) {
LAB_006d7610:
        iVar5 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_006d7614;
      }
      if (bVar1 == 0) break;
      bVar1 = pcVar8[1];
      bVar11 = bVar1 < pbVar9[1];
      if (bVar1 != pbVar9[1]) goto LAB_006d7610;
      pcVar8 = pcVar8 + 2;
      pbVar9 = pbVar9 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_006d7614:
    local_8 = 0xffffffff;
    if (iVar5 != 0) {
      FUN_00715380(local_1b0);
      goto LAB_006d77e3;
    }
    FUN_00715380(local_1b0);
  }
  uVar10 = 0;
  do {
    pcVar8 = *(char **)((int)&PTR_s_Character_Cha_Accessory_Body_Bag_00f882e8 + uVar10);
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = (undefined4 ***)((uint)local_34[0] & 0xffffff00);
    pcVar6 = pcVar8;
    do {
      cVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar2 != '\0');
    FUN_00402a70(pcVar8,(int)pcVar6 - (int)(pcVar8 + 1));
    local_8 = 1;
    ppppuVar7 = (undefined4 ****)local_34[0];
    if (local_20 < 0x10) {
      ppppuVar7 = local_34;
    }
    iVar5 = FUN_00714550(ppppuVar7,uVar3);
    if (iVar5 == 0) {
      if (4 < local_24) {
        ppppuVar7 = (undefined4 ****)local_34[0];
        if (local_20 < 0x10) {
          ppppuVar7 = local_34;
        }
        iVar5 = __stricmp((char *)((int)ppppuVar7 + (local_24 - 4)),".gb3");
        if (iVar5 == 0) {
          ppppuVar7 = (undefined4 ****)local_34[0];
          if (local_20 < 0x10) {
            ppppuVar7 = local_34;
          }
          pcVar8 = ".emf";
          do {
            cVar2 = *pcVar8;
            pcVar8[(int)ppppuVar7 + (local_24 - 0xc40f6c)] = cVar2;
            pcVar8 = pcVar8 + 1;
          } while (cVar2 != '\0');
          ppppuVar7 = (undefined4 ****)local_34[0];
          if (local_20 < 0x10) {
            ppppuVar7 = local_34;
          }
          iVar5 = FUN_00714550(ppppuVar7);
          if (iVar5 != 0) goto LAB_006d778a;
          if (0xf < local_20) {
            FUN_0089120c(local_34[0]);
          }
          goto LAB_006d77e3;
        }
        if (4 < local_24) {
          ppppuVar7 = (undefined4 ****)local_34[0];
          if (local_20 < 0x10) {
            ppppuVar7 = local_34;
          }
          iVar5 = __stricmp((char *)((int)ppppuVar7 + (local_24 - 4)),".dds");
          if (iVar5 == 0) {
            ppppuVar7 = (undefined4 ****)local_34[0];
            if (local_20 < 0x10) {
              ppppuVar7 = local_34;
            }
            pcVar8 = ".etf";
            do {
              cVar2 = *pcVar8;
              pcVar8[(int)ppppuVar7 + (local_24 - 0xc1010c)] = cVar2;
              pcVar8 = pcVar8 + 1;
            } while (cVar2 != '\0');
            ppppuVar7 = (undefined4 ****)local_34[0];
            if (local_20 < 0x10) {
              ppppuVar7 = local_34;
            }
            iVar5 = FUN_00714550(ppppuVar7);
            if (iVar5 != 0) goto LAB_006d778a;
            if (0xf < local_20) {
              FUN_0089120c(local_34[0]);
            }
            goto LAB_006d77e3;
          }
        }
      }
      if (0xf < local_20) {
        FUN_0089120c(local_34[0]);
      }
      goto LAB_006d77e3;
    }
LAB_006d778a:
    local_8 = 0xffffffff;
    if (0xf < local_20) {
      FUN_0089120c(local_34[0]);
    }
    uVar10 = uVar10 + 4;
  } while (uVar10 < 0x6c);
  if (param_1 != 0) {
    uVar3 = 0;
    do {
      DVar4 = GetFileAttributesA(*(LPCSTR *)((int)&PTR_s_Table_stp_00f88354 + uVar3));
      if (DVar4 == 0xffffffff) break;
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x38);
  }
LAB_006d77e3:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

