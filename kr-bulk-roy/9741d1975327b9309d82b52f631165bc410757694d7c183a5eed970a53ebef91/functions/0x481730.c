
void FUN_00481730(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int unaff_EDI;
  
  puVar3 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar3 != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(unaff_EDI + 0x128);
    uVar2 = *(undefined4 *)(unaff_EDI + 0x124);
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0xffffffff;
    puVar3[3] = 0;
    puVar3[4] = 0xf4369;
    *puVar3 = FoxUI::FXUIEventI2::vftable;
    puVar3[5] = uVar2;
    puVar3[6] = uVar1;
  }
  FUN_004072a0();
  (**(code **)(**(int **)(unaff_EDI + 0xf8) + 0x19c))(0xffffffff,0xffffffff,0,0);
  (**(code **)(**(int **)(unaff_EDI + 0xf8) + 200))();
  *(undefined4 *)(unaff_EDI + 0x124) = 0xffffffff;
  *(undefined4 *)(unaff_EDI + 0x128) = 0xffffffff;
  return;
}

