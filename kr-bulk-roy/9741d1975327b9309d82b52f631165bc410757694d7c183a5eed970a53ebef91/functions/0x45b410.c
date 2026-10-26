
void FUN_0045b410(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar3 != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x2a4);
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x2a0);
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0xffffffff;
    puVar3[3] = 0;
    puVar3[4] = 0xf4369;
    *puVar3 = FoxUI::FXUIEventI2::vftable;
    puVar3[5] = uVar2;
    puVar3[6] = uVar1;
  }
  FUN_004072a0();
  (**(code **)(**(int **)(param_1 + 0xfc) + 0x90))(0);
  FUN_00459470();
  FUN_0045a5f0();
  FUN_00757710();
  (**(code **)(**(int **)(param_1 + 0xf4) + 0x94))(0);
  return;
}

