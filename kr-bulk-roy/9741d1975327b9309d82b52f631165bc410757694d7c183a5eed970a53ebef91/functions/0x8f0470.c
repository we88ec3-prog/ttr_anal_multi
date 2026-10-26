
int FUN_008f0470(uint *param_1)

{
  undefined4 uVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int unaff_EDI;
  int local_10;
  int local_c;
  uint local_8;
  
  uVar1 = *(undefined4 *)(unaff_EDI + 0x1c);
  local_10 = 0;
  uVar6 = FUN_008b9940();
  uVar7 = uVar6 & 0xff;
  *param_1 = uVar7;
  if (uVar7 == 0) {
    return -1;
  }
  if ((char)uVar6 < '\0') {
    local_8 = uVar7;
    uVar7 = FUN_008b9940();
    uVar7 = uVar7 & 0xff | (uVar6 & 0x7f) << 8;
  }
  local_8 = uVar7;
  local_c = FUN_008bc7d0(uVar1,2,0,uVar7,0,&local_10);
  if (local_10 != 0) {
    return 0;
  }
  iVar8 = 0;
  if (uVar7 != 0) {
    do {
      uVar7 = FUN_008b9940();
      uVar6 = uVar7 & 0xff;
      if ((char)uVar7 < '\0') {
        uVar7 = uVar7 & 0x7f;
        sVar2 = FUN_008b9960();
        *(short *)(local_c + iVar8 * 2) = sVar2;
        iVar8 = iVar8 + 1;
        if (uVar7 == 0) {
          return local_c;
        }
        if ((int)local_8 <= (int)(uVar7 + iVar8)) {
          return local_c;
        }
        for (; uVar7 != 0; uVar7 = uVar7 - 1) {
          sVar3 = FUN_008b9960();
          sVar2 = sVar2 + sVar3;
          *(short *)(local_c + iVar8 * 2) = sVar2;
          iVar8 = iVar8 + 1;
        }
      }
      else {
        uVar4 = FUN_008b9940();
        uVar4 = uVar4 & 0xff;
        *(ushort *)(local_c + iVar8 * 2) = uVar4;
        iVar8 = iVar8 + 1;
        if (uVar6 == 0) {
          return local_c;
        }
        if ((int)local_8 <= (int)(uVar6 + iVar8)) {
          return local_c;
        }
        for (; uVar6 != 0; uVar6 = uVar6 - 1) {
          uVar5 = FUN_008b9940();
          uVar4 = uVar4 + (uVar5 & 0xff);
          *(ushort *)(local_c + iVar8 * 2) = uVar4;
          iVar8 = iVar8 + 1;
        }
      }
    } while (iVar8 < (int)local_8);
  }
  return local_c;
}

