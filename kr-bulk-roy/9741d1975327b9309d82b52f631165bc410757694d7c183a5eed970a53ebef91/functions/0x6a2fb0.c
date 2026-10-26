
void FUN_006a2fb0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  
  puVar4 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar4 != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(unaff_EDI + 0x120);
    uVar2 = *(undefined4 *)(unaff_EDI + 0x11c);
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[3] = 0;
    puVar4[4] = 0xf4369;
    *puVar4 = FoxUI::FXUIEventI2::vftable;
    puVar4[5] = uVar2;
    puVar4[6] = uVar1;
  }
  FUN_004072a0();
  *(undefined4 *)(unaff_EDI + 0x128) = 0;
  (**(code **)(**(int **)(unaff_EDI + 0x108) + 0x90))(0);
  *(undefined4 *)(unaff_EDI + 0x11c) = 0;
  *(undefined4 *)(unaff_EDI + 0x120) = 0;
  iVar3 = *(int *)(unaff_EDI + 0xf4);
  if (*(char *)(iVar3 + 0x141) == '\0') {
    FUN_00757710();
  }
  else {
    FUN_006edb10("Not supported operation");
  }
  *(undefined4 *)(iVar3 + 0x168) = 0;
  *(undefined4 *)(iVar3 + 0x160) = 0;
  *(undefined4 *)(iVar3 + 0x164) = 0;
  *(undefined4 *)(iVar3 + 0x14c) = 0;
  (**(code **)(**(int **)(unaff_EDI + 0xf4) + 200))();
  FUN_006a1960(unaff_EDI,0,0,0);
  return;
}

