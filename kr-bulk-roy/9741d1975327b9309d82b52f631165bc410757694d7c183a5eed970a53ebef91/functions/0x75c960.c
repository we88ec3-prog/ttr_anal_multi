
void FUN_0075c960(void)

{
  int iVar1;
  int *piVar2;
  int *unaff_ESI;
  
  (**(code **)(*unaff_ESI + 0x198))();
  piVar2 = (int *)FUN_00891268(0x18);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    iVar1 = unaff_ESI[8];
    piVar2[1] = -1;
    piVar2[2] = -1;
    piVar2[3] = 0;
    piVar2[4] = 0x641;
    *piVar2 = (int)FoxUI::FXUIEventI1::vftable;
    piVar2[5] = iVar1;
  }
  if (unaff_ESI[0x18] != 0) {
    piVar2[1] = unaff_ESI[8];
    piVar2[2] = unaff_ESI[0x12];
    (**(code **)(*(int *)unaff_ESI[0x18] + 0x148))(piVar2);
  }
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x10))(1);
  }
  return;
}

