
undefined4 FUN_006b5760(int param_1)

{
  undefined4 *puVar1;
  int *in_ECX;
  
  if (param_1 == 0x2afa) {
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf43e5;
      FUN_004072a0();
      return 0;
    }
    FUN_004072a0();
  }
  else if (param_1 == 0x2af9) {
    (**(code **)(*in_ECX + 0xd4))();
    return 1;
  }
  return 0;
}

