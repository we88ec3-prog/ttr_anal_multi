
void FUN_0059a620(void)

{
  int in_EAX;
  undefined4 *puVar1;
  
  FUN_00596e00(in_EAX,*(undefined4 *)(in_EAX + 0x1e0));
  puVar1 = (undefined4 *)FUN_00891268(0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = FoxUI::FXUIEvent::vftable;
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[3] = 0;
    puVar1[4] = 0xf4389;
    FUN_004072a0();
    return;
  }
  FUN_004072a0();
  return;
}

