
void FUN_004d7ab0(void)

{
  undefined4 in_EAX;
  undefined4 *puVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x11c) = in_EAX;
  FUN_004d4fa0();
  puVar1 = (undefined4 *)FUN_00891268(0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = FoxUI::FXUIEvent::vftable;
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[3] = 0;
    puVar1[4] = 0xf4366;
    FUN_004072a0();
    return;
  }
  FUN_004072a0();
  return;
}

