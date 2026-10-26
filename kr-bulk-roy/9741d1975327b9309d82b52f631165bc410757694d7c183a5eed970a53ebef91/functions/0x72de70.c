
void FUN_0072de70(void)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  int iVar7;
  undefined4 *unaff_EDI;
  undefined4 uVar8;
  char local_28 [32];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar4 = unaff_EDI[4];
  iVar7 = 0;
  if (0 < iVar4) {
    do {
      uVar3 = unaff_EDI[5];
      puVar5 = unaff_EDI;
      if (0xf < uVar3) {
        puVar5 = (undefined4 *)*unaff_EDI;
      }
      bVar1 = *(byte *)((int)puVar5 + iVar7);
      if (bVar1 == 0x26) {
        if (iVar4 + -2 <= iVar7) {
LAB_0072df19:
          FUN_00401fc0(PTR_s__amp__00d63ccc,DAT_00d63cd0);
          goto LAB_0072dfea;
        }
        puVar5 = unaff_EDI;
        if (0xf < uVar3) {
          puVar5 = (undefined4 *)*unaff_EDI;
        }
        if (*(char *)((int)puVar5 + iVar7 + 1) != '#') goto LAB_0072df19;
        puVar5 = unaff_EDI;
        if (0xf < uVar3) {
          puVar5 = (undefined4 *)*unaff_EDI;
        }
        if (*(char *)((int)puVar5 + iVar7 + 2) != 'x') goto LAB_0072df19;
        if (iVar7 < iVar4 + -1) {
          do {
            uVar8 = 1;
            iVar4 = FUN_00403030(1);
            FUN_00401fc0(iVar4 + iVar7,uVar8);
            iVar7 = iVar7 + 1;
            puVar5 = unaff_EDI;
            if (0xf < (uint)unaff_EDI[5]) {
              puVar5 = (undefined4 *)*unaff_EDI;
            }
          } while ((*(char *)((int)puVar5 + iVar7) != ';') && (iVar7 < unaff_EDI[4] + -1));
        }
      }
      else {
        if (bVar1 == 0x3c) {
          FUN_00401fc0(PTR_DAT_00d63cd8,DAT_00d63cdc);
        }
        else if (bVar1 == 0x3e) {
          FUN_00401fc0(PTR_DAT_00d63ce4,DAT_00d63ce8);
        }
        else if (bVar1 == 0x22) {
          FUN_00401fc0(PTR_s__quot__00d63cf0,DAT_00d63cf4);
        }
        else if (bVar1 == 0x27) {
          FUN_00401fc0(PTR_s__apos__00d63cfc,DAT_00d63d00);
        }
        else if (bVar1 < 0x20) {
          FUN_00730d60(local_28,"&#x%02X;",bVar1);
          pcVar6 = local_28;
          do {
            cVar2 = *pcVar6;
            pcVar6 = pcVar6 + 1;
          } while (cVar2 != '\0');
          FUN_00401fc0(local_28,(int)pcVar6 - (int)(local_28 + 1));
        }
        else {
          FUN_00429630(1,bVar1);
        }
LAB_0072dfea:
        iVar7 = iVar7 + 1;
      }
      iVar4 = unaff_EDI[4];
    } while (iVar7 < iVar4);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

