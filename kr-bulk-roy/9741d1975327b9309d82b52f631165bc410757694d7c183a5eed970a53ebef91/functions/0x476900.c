
void FUN_00476900(void)

{
  byte bVar1;
  byte bVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  FUN_004067f0();
  FUN_00476d10(in_ECX);
  puVar3 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar3 != (undefined4 *)0x0) {
    bVar1 = *(byte *)(in_ECX + 0x169);
    bVar2 = *(byte *)(in_ECX + 0x168);
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0xffffffff;
    puVar3[3] = 0;
    puVar3[4] = 0xf4369;
    *puVar3 = FoxUI::FXUIEventI2::vftable;
    puVar3[5] = (uint)bVar2;
    puVar3[6] = (uint)bVar1;
    FUN_004072a0();
    return;
  }
  FUN_004072a0();
  return;
}

