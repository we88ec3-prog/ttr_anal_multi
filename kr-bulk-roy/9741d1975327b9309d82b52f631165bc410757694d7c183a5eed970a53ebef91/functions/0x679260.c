
void FUN_00679260(void)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  int *unaff_EDI;
  
  puVar4 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar4 != (undefined4 *)0x0) {
    iVar1 = unaff_EDI[0x47];
    iVar2 = unaff_EDI[0x46];
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[3] = 0;
    puVar4[4] = 0xf4369;
    *puVar4 = FoxUI::FXUIEventI2::vftable;
    puVar4[5] = iVar2;
    puVar4[6] = iVar1;
  }
  FUN_004072a0();
  (**(code **)(*(int *)unaff_EDI[0x3e] + 0x19c))(0xffffffff,0xffffffff,0,0);
  (**(code **)(*(int *)unaff_EDI[0x3e] + 200))();
  FUN_00757710();
  (**(code **)(*(int *)unaff_EDI[0x3f] + 200))();
  pcVar3 = *(code **)(*unaff_EDI + 0x16c);
  *(undefined2 *)(unaff_EDI + 0x49) = 0;
  (*pcVar3)(1);
  return;
}

