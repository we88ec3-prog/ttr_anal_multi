
void FUN_0042c070(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00891268(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[3] = 0;
    puVar1[4] = 0xf42e8;
    *puVar1 = FoxUI::FXUIEventB1::vftable;
    *(undefined1 *)(puVar1 + 5) = 1;
    FUN_004072a0();
    return;
  }
  FUN_004072a0();
  return;
}

