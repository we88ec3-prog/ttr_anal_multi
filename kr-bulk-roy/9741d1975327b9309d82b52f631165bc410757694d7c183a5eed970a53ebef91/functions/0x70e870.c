
void FUN_0070e870(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_EAX;
  int *unaff_EDI;
  
  if (unaff_EDI[9] != 0) {
    iVar1 = *unaff_EDI;
    if ((iVar1 != 0xd) && (iVar1 != 0xe)) {
      if (iVar1 != 0) {
        FUN_00712630();
      }
      FUN_00713410();
      return;
    }
    FUN_007121b0(0xffffffff);
    uVar2 = *(uint *)(unaff_EDI[6] + 8);
    iVar1 = (unaff_EDI[8] + -1) / 0x32 + 1;
    uVar3 = *(undefined4 *)(*(int *)(in_EAX + 0xc) + 8);
    if (iVar1 < 0x200) {
      FUN_00713370((iVar1 * 0x100 | uVar2) << 6 | 0x22,uVar3);
      *(uint *)(in_EAX + 0x24) = uVar2 + 1;
      unaff_EDI[8] = unaff_EDI[8] + -1;
      return;
    }
    FUN_00713370(uVar2 << 6 | 0x22,uVar3);
    FUN_00713370(iVar1,*(undefined4 *)(*(int *)(in_EAX + 0xc) + 8));
    *(uint *)(in_EAX + 0x24) = uVar2 + 1;
    unaff_EDI[8] = unaff_EDI[8] + -1;
  }
  return;
}

