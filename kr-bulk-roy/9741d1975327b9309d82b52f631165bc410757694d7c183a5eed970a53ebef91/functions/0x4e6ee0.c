
undefined4 FUN_004e6ee0(int param_1)

{
  byte bVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)FUN_00891268(0x28);
  if (puVar5 != (undefined4 *)0x0) {
    uVar3 = *(undefined4 *)(param_1 + 9);
    sVar2 = *(short *)(param_1 + 7);
    uVar4 = *(undefined4 *)(param_1 + 3);
    bVar1 = *(byte *)(param_1 + 2);
    puVar5[9] = *(undefined4 *)(param_1 + 0xd);
    puVar5[1] = 0xffffffff;
    puVar5[2] = 0xffffffff;
    puVar5[3] = 0;
    puVar5[4] = 0xf42ce;
    *puVar5 = FoxUI::FXUIEventI3BI1::vftable;
    puVar5[5] = (uint)bVar1;
    puVar5[6] = uVar4;
    puVar5[7] = (int)sVar2;
    puVar5[8] = uVar3;
    FUN_004072a0();
    return 0;
  }
  FUN_004072a0();
  return 0;
}

