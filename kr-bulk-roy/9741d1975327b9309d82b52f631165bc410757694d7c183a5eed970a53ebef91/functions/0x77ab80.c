
int * FUN_0077ab80(void)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = _malloc(0x54);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2[2] = 0;
    *piVar2 = (int)FoxUI::FXUIBackgroundPattern::vftable;
    DAT_00fba828 = DAT_00fba828 + 1;
    piVar2[1] = DAT_00fba828;
    piVar2[4] = 0;
    piVar2[3] = (int)FoxUI::FXUIImageSetItemLink::vftable;
    piVar2[9] = 0;
    piVar2[10] = 7;
    *(undefined2 *)(piVar2 + 5) = 0;
    piVar2[0x11] = 7;
    piVar2[0x10] = 0;
    *(undefined2 *)(piVar2 + 0xc) = 0;
    piVar2[0x14] = 0;
    *(undefined1 *)(piVar2 + 0x13) = 0;
  }
  (**(code **)(*piVar2 + 0x34))();
  piVar2[1] = *(int *)(in_ECX + 4);
  piVar2[2] = *(int *)(in_ECX + 8);
  FUN_00776790(in_ECX + 0xc);
  *(undefined1 *)(piVar2 + 0x13) = *(undefined1 *)(in_ECX + 0x4c);
  pcVar1 = *(code **)(*piVar2 + 0x38);
  piVar2[0x14] = *(int *)(in_ECX + 0x50);
  (*pcVar1)();
  return piVar2;
}

