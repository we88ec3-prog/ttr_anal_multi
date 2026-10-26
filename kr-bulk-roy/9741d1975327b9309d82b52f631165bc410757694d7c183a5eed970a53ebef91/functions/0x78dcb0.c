
void FUN_0078dcb0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int unaff_EDI;
  
  iVar1 = unaff_EDI;
  if (unaff_EDI != param_1) {
    while (iVar7 = iVar1 + 0x18, iVar7 != param_1) {
      uVar2 = *(undefined4 *)(iVar1 + 0x1c);
      iVar5 = *(int *)(iVar1 + 0x20);
      uVar3 = *(undefined4 *)(iVar1 + 0x28);
      uVar4 = *(undefined4 *)(iVar1 + 0x2c);
      if (iVar5 < *(int *)(unaff_EDI + 8)) {
        FUN_00790190();
        *(undefined4 *)(unaff_EDI + 4) = uVar2;
        *(int *)(unaff_EDI + 8) = iVar5;
        *(undefined4 *)(unaff_EDI + 0x10) = uVar3;
        *(undefined4 *)(unaff_EDI + 0xc) = 0;
        *(undefined4 *)(unaff_EDI + 0x14) = uVar4;
        iVar1 = iVar7;
      }
      else {
        iVar1 = *(int *)(iVar1 + 8);
        iVar6 = iVar7;
        while (iVar5 < iVar1) {
          *(undefined4 *)(iVar6 + 4) = *(undefined4 *)(iVar6 + -0x14);
          *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar6 + -0x10);
          *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar6 + -0xc);
          *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar6 + -8);
          *(undefined4 *)(iVar6 + 0x14) = *(undefined4 *)(iVar6 + -4);
          iVar1 = *(int *)(iVar6 + -0x28);
          iVar6 = iVar6 + -0x18;
        }
        *(int *)(iVar6 + 8) = iVar5;
        *(undefined4 *)(iVar6 + 4) = uVar2;
        *(undefined4 *)(iVar6 + 0xc) = 0;
        *(undefined4 *)(iVar6 + 0x10) = uVar3;
        *(undefined4 *)(iVar6 + 0x14) = uVar4;
        iVar1 = iVar7;
      }
    }
  }
  return;
}

