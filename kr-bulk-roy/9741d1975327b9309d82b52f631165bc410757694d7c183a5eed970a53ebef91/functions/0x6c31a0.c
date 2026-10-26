
void FUN_006c31a0(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)FUN_00891268(0x18);
  if (puVar2 != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(param_1 + 0xb4);
    puVar2[1] = 0xffffffff;
    puVar2[2] = 0xffffffff;
    puVar2[3] = 0;
    puVar2[4] = 0xf4316;
    *puVar2 = FoxUI::FXUIEventI1::vftable;
    puVar2[5] = uVar1;
    FUN_004072a0();
    return;
  }
  FUN_004072a0();
  return;
}

