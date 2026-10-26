
void FUN_00640890(int param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if ((*(int *)(param_1 + 0x10) == 0x578) &&
     (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x248) + 0x20))) {
    puVar1 = (undefined4 *)FUN_00891268(0x18);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[5] = in_ECX + 0xe8;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf42b1;
      *puVar1 = FoxUI::FXUIEventP1::vftable;
      FUN_004072a0();
      return;
    }
    FUN_004072a0();
  }
  return;
}

