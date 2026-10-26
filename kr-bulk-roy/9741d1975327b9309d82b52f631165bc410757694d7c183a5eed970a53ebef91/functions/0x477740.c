
void FUN_00477740(int param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 in_AL;
  undefined4 *puVar3;
  undefined1 in_CL;
  
  *(undefined1 *)(param_1 + 0x168) = in_AL;
  *(undefined1 *)(param_1 + 0x169) = in_CL;
  puVar3 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar3 != (undefined4 *)0x0) {
    bVar1 = *(byte *)(param_1 + 0x169);
    bVar2 = *(byte *)(param_1 + 0x168);
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0xffffffff;
    puVar3[3] = 0;
    puVar3[4] = 0xf4368;
    *puVar3 = FoxUI::FXUIEventI2::vftable;
    puVar3[5] = (uint)bVar2;
    puVar3[6] = (uint)bVar1;
    FUN_004072a0();
    return;
  }
  FUN_004072a0();
  return;
}

