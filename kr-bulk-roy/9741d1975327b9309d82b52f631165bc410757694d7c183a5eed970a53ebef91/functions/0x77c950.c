
int * FUN_0077c950(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = _malloc(0x1c);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    DAT_00fba828 = DAT_00fba828 + 1;
    piVar1[1] = DAT_00fba828;
    piVar1[2] = 0;
    *piVar1 = (int)FoxUI::FXUIBackgroundTexture::vftable;
    piVar1[3] = 0;
    piVar1[4] = 0;
    piVar1[5] = 0;
    *(undefined1 *)(piVar1 + 6) = 0;
  }
  (**(code **)(*piVar1 + 0x34))();
  piVar1[1] = *(int *)(in_ECX + 4);
  piVar1[2] = *(int *)(in_ECX + 8);
  piVar1[3] = *(int *)(in_ECX + 0xc);
  piVar1[4] = *(int *)(in_ECX + 0x10);
  piVar1[5] = *(int *)(in_ECX + 0x14);
  *(undefined1 *)(piVar1 + 6) = *(undefined1 *)(in_ECX + 0x18);
  (**(code **)(*piVar1 + 0x38))();
  return piVar1;
}

