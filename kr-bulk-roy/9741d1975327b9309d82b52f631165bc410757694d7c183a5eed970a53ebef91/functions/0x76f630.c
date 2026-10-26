
void FUN_0076f630(void)

{
  undefined4 *puVar1;
  
  FUN_0076f680();
  puVar1 = (undefined4 *)FUN_00891268(0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = FoxUI::FXUIEvent::vftable;
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[3] = 0;
    puVar1[4] = 0x12d;
    FUN_00748900();
    return;
  }
  FUN_00748900();
  return;
}

