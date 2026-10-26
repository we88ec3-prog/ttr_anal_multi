
void FUN_00461f90(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if ((*(int *)(param_1 + 0x10) == 0x578) &&
     (*(int *)(*(int *)(in_ECX + 0xf0) + 0x20) == *(int *)(param_1 + 8))) {
    puVar2 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar2 != (undefined4 *)0x0) {
      uVar1 = *(undefined4 *)(in_ECX + 0x100);
      puVar2[5] = *(undefined4 *)(in_ECX + 0xfc);
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf441b;
      *puVar2 = FoxUI::FXUIEventI2::vftable;
      puVar2[6] = uVar1;
      FUN_004072a0();
      return;
    }
    FUN_004072a0();
  }
  return;
}

