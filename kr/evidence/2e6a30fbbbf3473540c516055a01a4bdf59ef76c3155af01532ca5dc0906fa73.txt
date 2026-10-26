
void FUN_006c0053(void)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  
  FUN_006d1be0(in_EAX + 0x504);
  iVar1 = FUN_0048a590();
  if (iVar1 + 0x24 != iVar1 + 0x14) {
    FUN_0085e680(**(undefined4 **)(iVar1 + 0x28));
    FUN_006d4530();
  }
  puVar2 = (undefined4 *)FUN_00891268();
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = 0xffffffff;
    puVar2[2] = 0xffffffff;
    puVar2[3] = 0;
    puVar2[4] = 0xf43cc;
    *puVar2 = FoxUI::FXUIEventI1::vftable;
    puVar2[5] = 1;
  }
  FUN_004072a0();
  (**(code **)(**(int **)(*(int *)(unaff_EBP + -4) + 0xc4) + 0x94))();
  if (DAT_00fba7a4 != 0) {
    *(undefined4 *)(DAT_00fba7a4 + 0x134) = 1;
  }
  puVar2 = (undefined4 *)FUN_00891268(0x14);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = FoxUI::FXUIEvent::vftable;
    puVar2[1] = 0xffffffff;
    puVar2[2] = 0xffffffff;
    puVar2[3] = 0;
    puVar2[4] = 0xf43cd;
  }
  FUN_004072a0();
  puVar2 = (undefined4 *)FUN_00891268(0x14);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_004072a0();
    return;
  }
  *puVar2 = FoxUI::FXUIEvent::vftable;
  puVar2[1] = 0xffffffff;
  puVar2[2] = 0xffffffff;
  puVar2[3] = 0;
  puVar2[4] = 0xf4403;
  FUN_004072a0();
  return;
}

