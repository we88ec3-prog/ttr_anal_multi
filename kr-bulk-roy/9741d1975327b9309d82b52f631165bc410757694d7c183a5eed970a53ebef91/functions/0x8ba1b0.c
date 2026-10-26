
undefined4 FUN_008ba1b0(int param_1,uint param_2,byte param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int unaff_EDI;
  
  if ((param_3 & 1) == 0) {
    iVar1 = *(int *)(param_1 + 0x58);
    if (iVar1 == 0) {
      return 0x24;
    }
    if ((param_3 & 0x10) == 0) {
      uVar3 = *(undefined4 *)(iVar1 + 0x10);
    }
    else {
      uVar3 = *(undefined4 *)(iVar1 + 0x14);
    }
    uVar4 = 0;
    if (param_2 != 0) {
      do {
        uVar2 = FUN_008b7dc0(*(undefined4 *)(unaff_EDI + uVar4 * 4),uVar3,0x40);
        *(undefined4 *)(unaff_EDI + uVar4 * 4) = uVar2;
        uVar4 = uVar4 + 1;
      } while (uVar4 < param_2);
    }
  }
  return 0;
}

