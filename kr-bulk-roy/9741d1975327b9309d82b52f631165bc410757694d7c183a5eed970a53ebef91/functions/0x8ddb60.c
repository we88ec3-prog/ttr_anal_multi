
int FUN_008ddb60(void)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  int *unaff_EDI;
  int local_8;
  
  iVar2 = *unaff_EDI;
  local_8 = 0;
  uVar3 = *(undefined4 *)(iVar2 + 0x1c);
  if ((unaff_EDI[2] == 0) || (unaff_EDI[6] != 0)) {
    return 0;
  }
  uVar7 = (uint)*(byte *)(unaff_EDI + 3);
  iVar4 = unaff_EDI[2] + 1;
  iVar8 = uVar7 * iVar4;
  iVar4 = FUN_008bc7d0(uVar3,4,0,iVar4,0,&local_8);
  unaff_EDI[6] = iVar4;
  if (((local_8 == 0) && (local_8 = FUN_008b97e0(iVar2,unaff_EDI[1] + 3), local_8 == 0)) &&
     (local_8 = FUN_008babe0(iVar2,iVar8), local_8 == 0)) {
    pbVar5 = *(byte **)(iVar2 + 0x20);
    puVar6 = (uint *)unaff_EDI[6];
    pbVar1 = pbVar5 + iVar8;
    if (uVar7 == 1) {
      for (; pbVar5 < pbVar1; pbVar5 = pbVar5 + 1) {
        *puVar6 = (uint)*pbVar5;
        puVar6 = puVar6 + 1;
      }
    }
    else if (uVar7 == 2) {
      for (; pbVar5 < pbVar1; pbVar5 = pbVar5 + 2) {
        *puVar6 = (uint)CONCAT11(*pbVar5,pbVar5[1]);
        puVar6 = puVar6 + 1;
      }
    }
    else if (uVar7 == 3) {
      for (; pbVar5 < pbVar1; pbVar5 = pbVar5 + 3) {
        *puVar6 = (uint)CONCAT21(CONCAT11(*pbVar5,pbVar5[1]),pbVar5[2]);
        puVar6 = puVar6 + 1;
      }
    }
    else {
      for (; pbVar5 < pbVar1; pbVar5 = pbVar5 + 4) {
        *puVar6 = CONCAT31(CONCAT21(CONCAT11(*pbVar5,pbVar5[1]),pbVar5[2]),pbVar5[3]);
        puVar6 = puVar6 + 1;
      }
    }
    FUN_008baca0(iVar2);
    if (local_8 == 0) {
      return 0;
    }
  }
  FUN_008b9f80(uVar3,unaff_EDI[6]);
  unaff_EDI[6] = 0;
  return local_8;
}

