
void FUN_00481250(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  
  cVar3 = FUN_004821a0(unaff_EDI,param_2,*(undefined4 *)(unaff_EDI + 0xf8));
  if (cVar3 != '\0') {
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
    puVar4 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf4368;
      *puVar4 = FoxUI::FXUIEventI2::vftable;
      puVar4[5] = param_1;
      puVar4[6] = param_2;
    }
    FUN_004072a0();
    *(undefined4 *)(unaff_EDI + 300) = param_1;
    *(undefined4 *)(unaff_EDI + 0x130) = param_2;
    FUN_004817c0(unaff_EDI);
  }
  return;
}

