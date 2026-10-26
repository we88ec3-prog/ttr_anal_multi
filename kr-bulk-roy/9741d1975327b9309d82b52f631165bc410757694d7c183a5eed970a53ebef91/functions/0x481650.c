
void FUN_00481650(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  
  puVar4 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar4 != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(unaff_EDI + 0x130);
    uVar2 = *(undefined4 *)(unaff_EDI + 300);
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[3] = 0;
    puVar4[4] = 0xf4369;
    *puVar4 = FoxUI::FXUIEventI2::vftable;
    puVar4[5] = uVar2;
    puVar4[6] = uVar1;
  }
  FUN_004072a0();
  (**(code **)(**(int **)(unaff_EDI + 0xfc) + 0x19c))(0xffffffff,0xffffffff,0,0);
  (**(code **)(**(int **)(unaff_EDI + 0xfc) + 200))();
  (**(code **)(**(int **)(unaff_EDI + 0x10c) + 0x94))(0);
  FUN_007597b0(0);
  (**(code **)(**(int **)(unaff_EDI + 0x110) + 200))();
  *(undefined4 *)(unaff_EDI + 300) = 0xffffffff;
  *(undefined4 *)(unaff_EDI + 0x130) = 0xffffffff;
  iVar3 = *(int *)(*(int *)(unaff_EDI + 0x100) + 0xcc);
  if (iVar3 != 0) {
    FUN_006438f0(iVar3);
  }
  (**(code **)(**(int **)(unaff_EDI + 0x100) + 200))();
  return;
}

