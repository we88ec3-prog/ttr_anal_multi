
void FUN_00414850(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x260) + 0x20)) {
      puVar2 = (undefined4 *)FUN_00891268(0x24);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf4308;
        *puVar2 = FUI::FXUICashShopCartOpen::vftable;
        puVar2[5] = 0;
        puVar2[6] = 0;
        puVar2[7] = 0;
      }
      FUN_004a8680();
      FUN_004054c0();
      FUN_0058aa50(puVar2);
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x264) + 0x20)) {
      FUN_004054c0();
      FUN_0058b0a0(0xf43bc,*(undefined4 *)(*(int *)(in_ECX + 0x248) + 0x254));
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x248) + 0x20)) {
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0x578;
        FUN_00748900();
        return;
      }
      FUN_00748900();
    }
  }
  else if (*(int *)(param_1 + 0x10) == 0x58c) {
    iVar1 = *(int *)(*(int *)(in_ECX + 0x248) + 0x260);
    if (iVar1 == 0x1d) {
      puVar2 = (undefined4 *)FUN_00891268(0x20);
      if (puVar2 != (undefined4 *)0x0) {
        uVar4 = *(undefined4 *)(*(int *)(in_ECX + 0x248) + 0x254);
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf4324;
        *(undefined1 *)(puVar2 + 5) = 1;
        *puVar2 = FoxUI::FXUIEventB1I2::vftable;
        puVar2[6] = uVar4;
        puVar2[7] = 1;
        FUN_00404aa0();
        FUN_00750020();
        return;
      }
      FUN_00404aa0();
      FUN_00750020();
      return;
    }
    if (iVar1 == 0x1f) {
      uVar4 = *(undefined4 *)(*(int *)(in_ECX + 0x248) + 0x250);
      uVar3 = *(undefined4 *)(*(int *)(in_ECX + 0x248) + 0x254);
      FUN_00414720(uVar3,uVar4);
      FUN_00571580(uVar3,uVar4);
      return;
    }
  }
  return;
}

