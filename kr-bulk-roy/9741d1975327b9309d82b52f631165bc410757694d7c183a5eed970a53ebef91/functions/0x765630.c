
int * FUN_00765630(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  piVar1 = _malloc(0x10);
  piVar2 = (int *)0x0;
  if (piVar1 != (int *)0x0) {
    DAT_00fba828 = DAT_00fba828 + 1;
    piVar1[2] = 0;
    piVar1[1] = DAT_00fba828;
    *piVar1 = (int)FoxUI::FXUIBackgroundColor::vftable;
    piVar1[3] = -0x1000000;
    piVar2 = piVar1;
  }
  (**(code **)(*piVar2 + 0x34))();
  piVar2[1] = *(int *)(in_ECX + 4);
  piVar2[2] = *(int *)(in_ECX + 8);
  piVar2[3] = *(int *)(in_ECX + 0xc);
  (**(code **)(*piVar2 + 0x38))();
  return piVar2;
}

