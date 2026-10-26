
int * FUN_00777b20(void)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  int *piVar3;
  
  piVar2 = _malloc(0x18);
  piVar3 = (int *)0x0;
  if (piVar2 != (int *)0x0) {
    DAT_00fba828 = DAT_00fba828 + 1;
    piVar2[2] = 0;
    piVar2[1] = DAT_00fba828;
    *piVar2 = (int)FoxUI::FXUIBackgroundColorLine::vftable;
    piVar2[3] = -0x1000000;
    piVar2[4] = -0x10000;
    piVar2[5] = 1;
    piVar3 = piVar2;
  }
  (**(code **)(*piVar3 + 0x34))();
  piVar3[1] = *(int *)(in_ECX + 4);
  piVar3[2] = *(int *)(in_ECX + 8);
  piVar3[3] = *(int *)(in_ECX + 0xc);
  piVar3[4] = *(int *)(in_ECX + 0x10);
  pcVar1 = *(code **)(*piVar3 + 0x38);
  piVar3[5] = *(int *)(in_ECX + 0x14);
  (*pcVar1)();
  return piVar3;
}

