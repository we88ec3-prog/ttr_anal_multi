
void FUN_00690073(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int unaff_EBP;
  int unaff_ESI;
  undefined4 unaff_EDI;
  char in_SF;
  char in_OF;
  
  (**(code **)(*(int *)(unaff_EBP + -4) + 0x90))(in_OF != in_SF);
  FUN_00404ba0();
  *(undefined4 *)(unaff_EBP + 8) = **(undefined4 **)(unaff_ESI + 0x100);
  uVar1 = FUN_004a7810(unaff_EDI);
  iVar2 = FUN_004d43d0();
  (**(code **)(*(int *)(unaff_EBP + 8) + 0x90))((int)(uVar1 & 0xff) < iVar2);
  iVar2 = FUN_0075cdd0();
  if (iVar2 == 3) {
    FUN_00446230();
    iVar2 = FUN_004a7ef0();
    if (iVar2 != 0) {
      FUN_00404ba0();
      *(undefined4 *)(unaff_EBP + -4) = **(undefined4 **)(unaff_ESI + 0x110);
      uVar1 = FUN_00445330(iVar2);
      *(uint *)(unaff_EBP + 8) = uVar1 & 0xff;
      iVar3 = FUN_004d43d0();
      (**(code **)(*(int *)(unaff_EBP + -4) + 0x90))(*(int *)(unaff_EBP + 8) < iVar3);
      FUN_00404ba0();
      *(undefined4 *)(unaff_EBP + 8) = **(undefined4 **)(unaff_ESI + 0x100);
      uVar1 = FUN_00445330(iVar2);
      iVar2 = FUN_004d43d0();
      (**(code **)(*(int *)(unaff_EBP + 8) + 0x90))((int)(uVar1 & 0xff) < iVar2);
    }
  }
  FUN_00691780();
  FUN_006904b0(0);
  return;
}

