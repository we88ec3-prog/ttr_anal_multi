
undefined4 FUN_004e7170(int param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x68f9) = *(undefined1 *)(param_1 + 2);
  puVar1 = (undefined4 *)FUN_00891268(0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = FoxUI::FXUIEvent::vftable;
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[3] = 0;
    puVar1[4] = 0xf42d4;
    FUN_004072a0();
    return 0;
  }
  FUN_004072a0();
  return 0;
}

