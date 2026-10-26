
void FUN_00689a50(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  iVar4 = *(int *)(param_1 + 0x10);
  if (iVar4 == 0x578) {
    iVar4 = *(int *)(param_1 + 8);
    if (iVar4 == *(int *)(*(int *)(in_ECX + 0x108) + 0x20)) {
      FUN_006899f0(in_ECX);
      return;
    }
    if (iVar4 == *(int *)(*(int *)(in_ECX + 0x10c) + 0x20)) {
      FUN_006899f0(in_ECX);
      return;
    }
    if (iVar4 == *(int *)(*(int *)(in_ECX + 0x118) + 0x20)) {
      FUN_006899f0(in_ECX);
      return;
    }
    if (iVar4 == *(int *)(*(int *)(in_ECX + 0x110) + 0x20)) {
      iVar4 = FUN_00891268(0x20);
      if (iVar4 != 0) {
        FUN_00753dc0(*(undefined4 *)(in_ECX + 0xf4),*(undefined4 *)(in_ECX + 0x104),
                     *(undefined4 *)(in_ECX + 0x120));
        FUN_00689c00();
        return;
      }
    }
    else {
      if (iVar4 != *(int *)(*(int *)(in_ECX + 0x114) + 0x20)) {
        return;
      }
      iVar4 = FUN_00891268(0x20);
      if (iVar4 != 0) {
        FUN_00753dc0(*(undefined4 *)(in_ECX + 0xf4),*(undefined4 *)(in_ECX + 0x104),
                     *(undefined4 *)(in_ECX + 0x120));
        FUN_00689c00();
        return;
      }
    }
  }
  else {
    if (iVar4 == 0x3e9) {
      if (*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0x11c) + 0x20)) {
        return;
      }
      FUN_0068ace0();
      FUN_006899f0(in_ECX);
      return;
    }
    if (iVar4 != 0x387) {
      return;
    }
    puVar5 = (undefined4 *)FUN_00891268(0x20);
    if (puVar5 != (undefined4 *)0x0) {
      uVar1 = *(undefined4 *)(in_ECX + 0xf4);
      uVar2 = *(undefined4 *)(in_ECX + 0x120);
      uVar3 = *(undefined4 *)(in_ECX + 0x104);
      puVar5[1] = 0xffffffff;
      puVar5[2] = 0xffffffff;
      puVar5[4] = uVar1;
      puVar5[3] = 0;
      *puVar5 = FoxUI::FXUIEventI2P1::vftable;
      puVar5[5] = 0xf43a6;
      puVar5[6] = uVar3;
      puVar5[7] = uVar2;
      FUN_00689c00();
      return;
    }
  }
  FUN_00689c00();
  return;
}

