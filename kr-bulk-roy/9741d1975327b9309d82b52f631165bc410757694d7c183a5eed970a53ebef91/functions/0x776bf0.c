
undefined4 FUN_00776bf0(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *unaff_ESI;
  
  uVar2 = FUN_00764bb0();
  uVar3 = (**(code **)(*unaff_ESI + 4))();
  FUN_00776b00(uVar3);
  (**(code **)(*unaff_ESI + 0xc))();
  FUN_00764810(uVar2);
  cVar1 = (**(code **)(*unaff_ESI + 0x18))(uVar2);
  if (cVar1 != '\0') {
    FUN_0072e0d0();
    return 1;
  }
  return 0;
}

