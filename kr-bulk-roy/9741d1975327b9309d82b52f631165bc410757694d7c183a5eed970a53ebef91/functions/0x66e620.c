
void FUN_0066e620(int param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if ((*(int *)(param_1 + 0x10) == 0x578) &&
     (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x80) + 0x20))) {
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf43fe;
      FUN_004072a0();
      return;
    }
    FUN_004072a0();
  }
  return;
}

