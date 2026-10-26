
void FUN_005c36d0(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int unaff_ESI;
  
  if (*(int *)(in_EAX + 0x14) != 0) {
    FUN_006bf310(*(undefined4 *)(unaff_ESI + 0x230));
    FUN_00596e00(unaff_ESI,*(undefined4 *)(unaff_ESI + 0x230));
    puVar1 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf43fd;
      *puVar1 = FoxUI::FXUIEventI2::vftable;
      puVar1[5] = 0;
      puVar1[6] = 10;
      FUN_006c0170(puVar1);
      return;
    }
    FUN_006c0170(0);
  }
  return;
}

