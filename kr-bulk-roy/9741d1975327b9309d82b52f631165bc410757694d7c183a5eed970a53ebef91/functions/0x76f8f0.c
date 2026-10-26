
void FUN_0076f8f0(void)

{
  undefined4 *puVar1;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xbc))
            (in_ECX[2],in_ECX[3],in_ECX[0x38] + in_ECX[2],in_ECX[0x39] + in_ECX[3]);
  puVar1 = (undefined4 *)FUN_00891268(0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = FoxUI::FXUIEvent::vftable;
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[3] = 0;
    puVar1[4] = 0x12f;
    FUN_00748900();
    return;
  }
  FUN_00748900();
  return;
}

