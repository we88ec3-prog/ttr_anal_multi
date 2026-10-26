
void FUN_007927f0(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *unaff_ESI;
  uint uVar6;
  uint local_c;
  
  iVar1 = (**(code **)(*unaff_ESI + 0x18))();
  uVar6 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = (**(code **)(*unaff_ESI + 0x24))(uVar6);
      uVar3 = iVar2 >> 7 & 7;
      iVar2 = (**(code **)(*unaff_ESI + 0x24))(uVar6);
      uVar4 = iVar2 >> 10 & 7;
      if (uVar6 == 0) {
        uVar5 = 0xffffffff;
      }
      else {
        iVar2 = (**(code **)(*unaff_ESI + 0x24))(uVar6 - 1);
        uVar5 = iVar2 >> 10 & 7;
      }
      if ((int)uVar6 < iVar1 + -1) {
        iVar2 = (**(code **)(*unaff_ESI + 0x24))(uVar6 + 1);
        local_c = iVar2 >> 7 & 7;
      }
      else {
        local_c = 0xffffffff;
      }
      switch(uVar3) {
      case 1:
        if ((uVar5 == 1) || (uVar6 == 0)) {
          FUN_00792c30();
        }
        else {
          FUN_00792ed0();
        }
        break;
      case 2:
      case 4:
        if ((uint)((unaff_ESI[7] - unaff_ESI[6]) / 0x18) <= uVar6) goto LAB_0079295f;
        *(undefined4 *)(unaff_ESI[6] + 0x10 + uVar6 * 0x18) = 0;
        break;
      case 3:
        FUN_00792af0();
      }
      switch(uVar4) {
      case 1:
        if ((local_c == 1) || (iVar1 + -1 <= (int)uVar6)) {
          FUN_00792b90();
        }
        else {
          FUN_00792cd0();
        }
        break;
      case 2:
      case 4:
        if ((uint)((unaff_ESI[7] - unaff_ESI[6]) / 0x18) <= uVar6) {
LAB_0079295f:
                    /* WARNING: Subroutine does not return */
          FUN_0087db7d("invalid vector<T> subscript");
        }
        *(undefined4 *)(unaff_ESI[6] + 0x14 + uVar6 * 0x18) = 0;
        break;
      case 3:
        FUN_00792a50();
      }
      if ((uVar3 == 0) || (uVar4 == 0)) {
        FUN_00793120();
      }
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < iVar1);
  }
  return;
}

