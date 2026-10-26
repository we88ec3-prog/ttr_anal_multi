
int * FUN_0077cb60(void)

{
  int *piVar1;
  
  piVar1 = _malloc(0x40);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    DAT_00fba828 = DAT_00fba828 + 1;
    piVar1[7] = 0;
    piVar1[9] = 0;
    piVar1[1] = DAT_00fba828;
    piVar1[2] = 0;
    piVar1[3] = 0;
    piVar1[4] = 0;
    piVar1[5] = 0;
    *(undefined1 *)(piVar1 + 6) = 0;
    *piVar1 = (int)FoxUI::FXUIBackgroundTextureAni::vftable;
    *(undefined1 *)(piVar1 + 0xf) = 1;
    *(undefined1 *)(piVar1 + 8) = 1;
    piVar1[10] = 0;
    piVar1[0xb] = 0;
    piVar1[0xc] = 0;
    piVar1[0xd] = 0;
    piVar1[0xe] = 0;
  }
  (**(code **)(*piVar1 + 0x34))();
  FUN_0077cc80();
  (**(code **)(*piVar1 + 0x38))();
  return piVar1;
}

