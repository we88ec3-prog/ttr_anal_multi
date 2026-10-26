
void FUN_004093d0(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *unaff_EDI;
  
  puVar3 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar3 != (undefined4 *)0x0) {
    iVar1 = unaff_EDI[0xa7];
    iVar2 = unaff_EDI[0xa6];
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0xffffffff;
    puVar3[3] = 0;
    puVar3[4] = 0xf4369;
    *puVar3 = FoxUI::FXUIEventI2::vftable;
    puVar3[5] = iVar2;
    puVar3[6] = iVar1;
  }
  FUN_004072a0();
  unaff_EDI[0xa6] = -1;
  unaff_EDI[0xa7] = -1;
  FUN_005d7240(0xffffffff,0xffffffff,0,0);
  (**(code **)(*unaff_EDI + 200))();
  if (unaff_EDI[0xa8] != 0) {
    FUN_00408610();
  }
  return;
}

