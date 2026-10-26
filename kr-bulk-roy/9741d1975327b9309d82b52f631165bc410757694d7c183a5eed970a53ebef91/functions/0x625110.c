
void FUN_00625110(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0xec) + 0x20)) {
      FUN_006252f0(in_ECX);
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0xf0) + 0x20)) {
      FUN_006254f0();
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0xf4) + 0x20)) {
      FUN_00625660(1);
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)) {
      FUN_00625660(0);
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0xfc) + 0x20)) {
      FUN_006256f0(1);
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x100) + 0x20)) {
      FUN_006256f0(0);
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x104) + 0x20)) {
      FUN_004054c0();
      puVar2 = (undefined4 *)FUN_00891268(0x18);
      if (puVar2 != (undefined4 *)0x0) {
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf4429;
        *puVar2 = FoxUI::FXUIEventB1::vftable;
        *(undefined1 *)(puVar2 + 5) = 1;
      }
      FUN_004072a0();
      uVar3 = 1;
      FUN_004096b0(1);
      FUN_0058f000(uVar3);
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x108) + 0x20)) {
      FUN_004054c0();
      puVar2 = (undefined4 *)FUN_00891268(0x18);
      if (puVar2 != (undefined4 *)0x0) {
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf4429;
        *puVar2 = FoxUI::FXUIEventB1::vftable;
        *(undefined1 *)(puVar2 + 5) = 0;
      }
      FUN_004072a0();
      uVar3 = 0;
      FUN_004096b0(0);
      FUN_0058f000(uVar3);
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x114) + 0x20)) {
      FUN_00444ad0();
      FUN_00498000();
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x118) + 0x20)) {
      FUN_00444ad0();
      FUN_00498000();
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x10c) + 0x20)) {
      FUN_00444ad0();
      FUN_00498000();
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x110) + 0x20)) {
      FUN_00444ad0();
      FUN_00498000();
    }
  }
  return;
}

