
undefined4 FUN_00496550(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = FUN_0048a740();
  FUN_006ab9a0(uVar1);
  puVar2 = (undefined4 *)FUN_00891268(0x14);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = FoxUI::FXUIEvent::vftable;
    puVar2[1] = 0xffffffff;
    puVar2[2] = 0xffffffff;
    puVar2[3] = 0;
    puVar2[4] = 0xf425a;
    FUN_004072a0();
    return 0;
  }
  FUN_004072a0();
  return 0;
}

