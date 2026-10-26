
void FUN_00698770(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined4 uVar4;
  undefined4 local_10;
  undefined4 *local_c;
  
  iVar3 = *(int *)(param_1 + 0x10);
  if (iVar3 == 0x578) {
    if (*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0x254) + 0x20)) {
      return;
    }
    if (*(int *)(in_ECX + 600) == 0) {
      return;
    }
    puVar1 = (undefined4 *)FUN_00891268(0x18);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      uVar2 = *(undefined4 *)(in_ECX + 0x20);
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf43be;
      *puVar1 = FoxUI::FXUIEventI1::vftable;
      puVar1[5] = uVar2;
    }
    uVar2 = *(undefined4 *)(in_ECX + 600);
    FUN_00404aa0();
  }
  else {
    if (iVar3 == 0x58c) {
      iVar3 = *(int *)(in_ECX + 0x248);
      if (*(int *)(iVar3 + 0x260) == 0x1d) {
        iVar3 = FUN_00891268(0x20);
        if (iVar3 != 0) {
          FUN_00753d00(1,1);
          FUN_00404aa0();
          FUN_00750020();
          return;
        }
        FUN_00404aa0();
        FUN_00750020();
        return;
      }
      if (*(int *)(iVar3 + 0x260) != 0x1f) {
        return;
      }
      uVar2 = *(undefined4 *)(iVar3 + 0x250);
      uVar4 = *(undefined4 *)(iVar3 + 0x254);
      FUN_00414720(uVar4,uVar2);
      FUN_00571580(uVar4,uVar2);
      return;
    }
    if (iVar3 != 0x641) {
      return;
    }
    if (*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0x24c) + 0x20)) {
      if (*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0x250) + 0x20)) {
        return;
      }
      if (*(int *)(in_ECX + 600) == 0) {
        return;
      }
      puVar1 = (undefined4 *)FUN_00891268(0x14);
      if (puVar1 != (undefined4 *)0x0) {
        *puVar1 = FoxUI::FXUIEvent::vftable;
        puVar1[1] = 0xffffffff;
        puVar1[2] = 0xffffffff;
        puVar1[3] = 0;
        puVar1[4] = 0xf43bf;
      }
      uVar2 = FUN_00404aa0();
      FUN_0074fff0(uVar2);
      return;
    }
    if (*(int *)(in_ECX + 600) == 0) {
      return;
    }
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = *(undefined4 *)(in_ECX + 600);
      puVar1 = (undefined4 *)0x0;
      FUN_00404aa0();
    }
    else {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf43bf;
      uVar2 = *(undefined4 *)(in_ECX + 600);
      FUN_00404aa0();
    }
  }
  local_10 = uVar2;
  local_c = puVar1;
  FUN_007b6e80(&local_10);
  return;
}

