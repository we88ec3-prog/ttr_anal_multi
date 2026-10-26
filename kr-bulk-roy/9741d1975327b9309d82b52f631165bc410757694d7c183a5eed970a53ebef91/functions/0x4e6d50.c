
undefined4 FUN_004e6d50(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x68e8) = *(undefined2 *)(param_1 + 2);
  puVar2 = (undefined4 *)FUN_00891268(0x18);
  if (puVar2 != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(param_1 + 4);
    puVar2[1] = 0xffffffff;
    puVar2[2] = 0xffffffff;
    puVar2[3] = 0;
    puVar2[4] = 0xf4437;
    *puVar2 = FoxUI::FXUIEventI1::vftable;
    puVar2[5] = uVar1;
    FUN_004072a0();
    return 0;
  }
  FUN_004072a0();
  return 0;
}

