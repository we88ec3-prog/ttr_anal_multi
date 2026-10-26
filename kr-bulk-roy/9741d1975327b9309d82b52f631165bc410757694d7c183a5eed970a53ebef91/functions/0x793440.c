
void FUN_00793440(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *unaff_EDI;
  uint local_c;
  
  iVar2 = (**(code **)(*unaff_EDI + 0x18))();
  uVar7 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = (**(code **)(*unaff_EDI + 0x24))(uVar7);
      uVar4 = iVar3 >> 7 & 7;
      iVar3 = (**(code **)(*unaff_EDI + 0x24))(uVar7);
      uVar5 = iVar3 >> 10 & 7;
      if (uVar7 == 0) {
        uVar6 = 0xffffffff;
      }
      else {
        iVar3 = (**(code **)(*unaff_EDI + 0x24))(uVar7 - 1);
        uVar6 = iVar3 >> 10 & 7;
      }
      if ((int)uVar7 < iVar2 + -1) {
        iVar3 = (**(code **)(*unaff_EDI + 0x24))(uVar7 + 1);
        local_c = iVar3 >> 7 & 7;
      }
      else {
        local_c = 0xffffffff;
      }
      switch(uVar4) {
      case 1:
        if ((uVar6 == 1) || (uVar7 == 0)) {
          FUN_00793c90(uVar7);
        }
        else {
          FUN_00794040();
        }
        break;
      case 2:
        if ((uint)((unaff_EDI[7] - unaff_EDI[6]) / 0x30) <= uVar7) goto LAB_0079368f;
        puVar1 = (undefined4 *)(unaff_EDI[6] + 0x18 + uVar7 * 0x30);
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        break;
      case 3:
        FUN_00793ab0(uVar7);
        break;
      case 4:
        if ((uint)((unaff_EDI[7] - unaff_EDI[6]) / 0x30) <= uVar7) goto LAB_0079368f;
        puVar1 = (undefined4 *)(unaff_EDI[6] + 0x18 + uVar7 * 0x30);
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
      }
      switch(uVar5) {
      case 1:
        if ((local_c == 1) || (iVar2 + -1 <= (int)uVar7)) {
          FUN_00793bb0(uVar7);
        }
        else {
          FUN_00793d80();
        }
        break;
      case 2:
        if ((uint)((unaff_EDI[7] - unaff_EDI[6]) / 0x30) <= uVar7) {
LAB_0079368f:
                    /* WARNING: Subroutine does not return */
          FUN_0087db7d("invalid vector<T> subscript");
        }
        puVar1 = (undefined4 *)(unaff_EDI[6] + 0x24 + uVar7 * 0x30);
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        break;
      case 3:
        FUN_007939b0(uVar7);
        break;
      case 4:
        if ((uint)((unaff_EDI[7] - unaff_EDI[6]) / 0x30) <= uVar7) goto LAB_0079368f;
        puVar1 = (undefined4 *)(unaff_EDI[6] + 0x24 + uVar7 * 0x30);
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
      }
      if ((uVar4 == 0) || (uVar5 == 0)) {
        FUN_00794340(unaff_EDI);
      }
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < iVar2);
  }
  return;
}

