
void FUN_00676750(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_EAX;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)FUN_00891268(0x2c);
  if (puVar3 != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(in_EAX + 0x1cc);
    uVar2 = *(undefined4 *)(in_EAX + 0x1d0);
    puVar3[10] = in_EAX;
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0xffffffff;
    puVar3[3] = 0;
    puVar3[4] = 0xf4310;
    *puVar3 = FoxUI::FXUIEventI4P2::vftable;
    puVar3[5] = 0xf43a4;
    puVar3[6] = uVar2;
    puVar3[7] = 1;
    puVar3[8] = uVar1;
    puVar3[9] = 0;
    FUN_004072a0();
    return;
  }
  FUN_004072a0();
  return;
}

