
undefined4 FUN_00689ca0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *in_ECX;
  
  if (param_1 == 0xd) {
    puVar3 = (undefined4 *)FUN_00891268(0x20);
    if (puVar3 != (undefined4 *)0x0) {
      iVar1 = in_ECX[0x48];
      iVar2 = in_ECX[0x41];
      puVar3[4] = in_ECX[0x3d];
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      *puVar3 = FoxUI::FXUIEventI2P1::vftable;
      puVar3[5] = 0xf43a5;
      puVar3[6] = iVar2;
      puVar3[7] = iVar1;
      FUN_00689c00();
      return 1;
    }
  }
  else {
    if (param_1 != 0xe) {
      if (param_1 == 0x2af9) {
        (**(code **)(*in_ECX + 0xd4))();
        return 1;
      }
      return 0;
    }
    puVar3 = (undefined4 *)FUN_00891268(0x20);
    if (puVar3 != (undefined4 *)0x0) {
      iVar1 = in_ECX[0x48];
      iVar2 = in_ECX[0x41];
      puVar3[4] = in_ECX[0x3d];
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      *puVar3 = FoxUI::FXUIEventI2P1::vftable;
      puVar3[5] = 0xf43a6;
      puVar3[6] = iVar2;
      puVar3[7] = iVar1;
      FUN_00689c00();
      return 1;
    }
  }
  FUN_00689c00();
  return 1;
}

