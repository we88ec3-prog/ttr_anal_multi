
void FUN_0078e0c0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int unaff_EDI;
  
  iVar1 = unaff_EDI;
  if (unaff_EDI != param_1) {
    while (iVar12 = iVar1 + 0x2c, iVar12 != param_1) {
      uVar2 = *(undefined4 *)(iVar1 + 0x30);
      iVar10 = *(int *)(iVar1 + 0x34);
      uVar11 = *(undefined4 *)(iVar1 + 0x38);
      uVar3 = *(undefined4 *)(iVar1 + 0x3c);
      uVar4 = *(undefined4 *)(iVar1 + 0x40);
      uVar5 = *(undefined4 *)(iVar1 + 0x44);
      uVar6 = *(undefined4 *)(iVar1 + 0x48);
      uVar7 = *(undefined4 *)(iVar1 + 0x4c);
      uVar8 = *(undefined4 *)(iVar1 + 0x50);
      uVar9 = *(undefined4 *)(iVar1 + 0x54);
      if (iVar10 < *(int *)(unaff_EDI + 8)) {
        FUN_00790290();
        *(undefined4 *)(unaff_EDI + 4) = uVar2;
        *(undefined4 *)(unaff_EDI + 0x10) = uVar3;
        *(int *)(unaff_EDI + 8) = iVar10;
        *(undefined4 *)(unaff_EDI + 0xc) = uVar11;
        *(undefined4 *)(unaff_EDI + 0x14) = uVar4;
        *(undefined4 *)(unaff_EDI + 0x18) = uVar5;
        *(undefined4 *)(unaff_EDI + 0x1c) = uVar6;
        *(undefined4 *)(unaff_EDI + 0x20) = uVar7;
        *(undefined4 *)(unaff_EDI + 0x24) = uVar8;
        *(undefined4 *)(unaff_EDI + 0x28) = uVar9;
        iVar1 = iVar12;
      }
      else {
        iVar1 = *(int *)(iVar1 + 8);
        iVar13 = iVar12;
        while (iVar10 < iVar1) {
          *(undefined4 *)(iVar13 + 4) = *(undefined4 *)(iVar13 + -0x28);
          *(undefined4 *)(iVar13 + 8) = *(undefined4 *)(iVar13 + -0x24);
          *(undefined4 *)(iVar13 + 0xc) = *(undefined4 *)(iVar13 + -0x20);
          *(undefined4 *)(iVar13 + 0x10) = *(undefined4 *)(iVar13 + -0x1c);
          *(undefined4 *)(iVar13 + 0x14) = *(undefined4 *)(iVar13 + -0x18);
          *(undefined4 *)(iVar13 + 0x18) = *(undefined4 *)(iVar13 + -0x14);
          *(undefined4 *)(iVar13 + 0x1c) = *(undefined4 *)(iVar13 + -0x10);
          *(undefined4 *)(iVar13 + 0x20) = *(undefined4 *)(iVar13 + -0xc);
          *(undefined4 *)(iVar13 + 0x24) = *(undefined4 *)(iVar13 + -8);
          *(undefined4 *)(iVar13 + 0x28) = *(undefined4 *)(iVar13 + -4);
          iVar1 = *(int *)(iVar13 + -0x50);
          iVar13 = iVar13 + -0x2c;
        }
        *(undefined4 *)(iVar13 + 4) = uVar2;
        *(int *)(iVar13 + 8) = iVar10;
        *(undefined4 *)(iVar13 + 0xc) = uVar11;
        *(undefined4 *)(iVar13 + 0x10) = uVar3;
        *(undefined4 *)(iVar13 + 0x14) = uVar4;
        *(undefined4 *)(iVar13 + 0x18) = uVar5;
        *(undefined4 *)(iVar13 + 0x1c) = uVar6;
        *(undefined4 *)(iVar13 + 0x20) = uVar7;
        *(undefined4 *)(iVar13 + 0x24) = uVar8;
        *(undefined4 *)(iVar13 + 0x28) = uVar9;
        iVar1 = iVar12;
      }
    }
  }
  return;
}

