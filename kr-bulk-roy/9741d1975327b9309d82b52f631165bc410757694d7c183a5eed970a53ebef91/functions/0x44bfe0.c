
void FUN_0044bfe0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(*(int *)(in_ECX + 0xf0) + 0x20) == iVar1) {
      puVar2 = (undefined4 *)FUN_00891268(0x18);
      if (puVar2 != (undefined4 *)0x0) {
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf4331;
        *puVar2 = FoxUI::FXUIEventI1::vftable;
        puVar2[5] = 0;
        FUN_004072a0();
        return;
      }
    }
    else if (*(int *)(*(int *)(in_ECX + 0xf4) + 0x20) == iVar1) {
      puVar2 = (undefined4 *)FUN_00891268(0x18);
      if (puVar2 != (undefined4 *)0x0) {
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf4331;
        *puVar2 = FoxUI::FXUIEventI1::vftable;
        puVar2[5] = 1;
        FUN_004072a0();
        return;
      }
    }
    else if (*(int *)(*(int *)(in_ECX + 0xf8) + 0x20) == iVar1) {
      puVar2 = (undefined4 *)FUN_00891268(0x18);
      if (puVar2 != (undefined4 *)0x0) {
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf4331;
        *puVar2 = FoxUI::FXUIEventI1::vftable;
        puVar2[5] = 2;
        FUN_004072a0();
        return;
      }
    }
    else if (*(int *)(*(int *)(in_ECX + 0xfc) + 0x20) == iVar1) {
      puVar2 = (undefined4 *)FUN_00891268(0x18);
      if (puVar2 != (undefined4 *)0x0) {
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf4331;
        *puVar2 = FoxUI::FXUIEventI1::vftable;
        puVar2[5] = 3;
        FUN_004072a0();
        return;
      }
    }
    else if (*(int *)(*(int *)(in_ECX + 0x100) + 0x20) == iVar1) {
      puVar2 = (undefined4 *)FUN_00891268(0x18);
      if (puVar2 != (undefined4 *)0x0) {
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf4331;
        *puVar2 = FoxUI::FXUIEventI1::vftable;
        puVar2[5] = 4;
        FUN_004072a0();
        return;
      }
    }
    else if (*(int *)(*(int *)(in_ECX + 0x104) + 0x20) == iVar1) {
      puVar2 = (undefined4 *)FUN_00891268(0x18);
      if (puVar2 != (undefined4 *)0x0) {
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf4331;
        *puVar2 = FoxUI::FXUIEventI1::vftable;
        puVar2[5] = 5;
        FUN_004072a0();
        return;
      }
    }
    else if (*(int *)(*(int *)(in_ECX + 0x108) + 0x20) == iVar1) {
      puVar2 = (undefined4 *)FUN_00891268(0x18);
      if (puVar2 != (undefined4 *)0x0) {
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf4331;
        *puVar2 = FoxUI::FXUIEventI1::vftable;
        puVar2[5] = 6;
        FUN_004072a0();
        return;
      }
    }
    else {
      if (*(int *)(*(int *)(in_ECX + 0x10c) + 0x20) != iVar1) {
        return;
      }
      puVar2 = (undefined4 *)FUN_00891268(0x18);
      if (puVar2 != (undefined4 *)0x0) {
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf4331;
        *puVar2 = FoxUI::FXUIEventI1::vftable;
        puVar2[5] = 7;
        FUN_004072a0();
        return;
      }
    }
    FUN_004072a0();
  }
  return;
}

