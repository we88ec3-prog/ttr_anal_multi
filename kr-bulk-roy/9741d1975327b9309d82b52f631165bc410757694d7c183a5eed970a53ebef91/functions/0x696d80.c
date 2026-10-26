
void FUN_00696d80(int param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf0) + 0x20)) {
      if ((*(uint *)(*(int *)(in_ECX + 0xf0) + 0x28) >> 9 & 1) == 0) {
        FUN_0041a4d0();
        FUN_0053bad0();
      }
      else {
        FUN_0041a4d0();
        FUN_0053ba80();
      }
      puVar1 = (undefined4 *)FUN_00891268(0x14);
      if (puVar1 != (undefined4 *)0x0) {
        *puVar1 = FoxUI::FXUIEvent::vftable;
        puVar1[1] = 0xffffffff;
        puVar1[2] = 0xffffffff;
        puVar1[3] = 0;
        puVar1[4] = 0xf439c;
        FUN_004072a0();
        return;
      }
    }
    else {
      if (*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0xec) + 0x20)) {
        return;
      }
      puVar1 = (undefined4 *)FUN_00891268(0x18);
      if (puVar1 != (undefined4 *)0x0) {
        puVar1[1] = 0xffffffff;
        puVar1[2] = 0xffffffff;
        puVar1[3] = 0;
        puVar1[4] = 0xf42df;
        *puVar1 = FoxUI::FXUIEventI1::vftable;
        puVar1[5] = 0;
        FUN_004072a0();
        return;
      }
    }
    FUN_004072a0();
  }
  return;
}

