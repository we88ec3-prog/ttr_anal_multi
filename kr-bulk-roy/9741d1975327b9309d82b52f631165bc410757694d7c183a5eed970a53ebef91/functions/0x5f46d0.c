
void FUN_005f46d0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x578) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 != *(int *)(*(int *)(in_ECX + 0xbc) + 0x20)) {
      if (iVar1 == *(int *)(*(int *)(in_ECX + 0xb4) + 0x20)) {
        if (*(char *)(in_ECX + 0xcc) != '\0') {
          return;
        }
        FUN_00414680();
        uVar3 = 0;
      }
      else {
        if (iVar1 == *(int *)(*(int *)(in_ECX + 0xc0) + 0x20)) {
          puVar2 = (undefined4 *)FUN_00891268(0x14);
          if (puVar2 == (undefined4 *)0x0) {
            FUN_004072a0();
            return;
          }
          *puVar2 = FoxUI::FXUIEvent::vftable;
          puVar2[1] = 0xffffffff;
          puVar2[2] = 0xffffffff;
          puVar2[3] = 0;
          puVar2[4] = 0xf43fe;
          FUN_004072a0();
          return;
        }
        if (iVar1 != *(int *)(*(int *)(in_ECX + 0xb8) + 0x20)) {
          return;
        }
        if (*(char *)(in_ECX + 0xcc) != '\0') {
          return;
        }
        FUN_00414680();
        uVar3 = 2;
      }
      FUN_004a3b80(*(undefined4 *)(in_ECX + 200),uVar3);
      *(undefined1 *)(in_ECX + 0xcc) = 1;
      return;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = FoxUI::FXUIEvent::vftable;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf4248;
      FUN_00404aa0();
      FUN_00750020();
      return;
    }
  }
  else {
    if (iVar1 == 0x70a) {
      if (*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0x84) + 0x20)) {
        return;
      }
      iVar1 = *(int *)(*(int *)(in_ECX + 0x84) + 0xcc);
      if ((iVar1 == 0) || (iVar1 = *(int *)(iVar1 + 0xdc), iVar1 == 0)) {
        iVar1 = -1;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0x20);
      }
      *(int *)(in_ECX + 200) = iVar1 + 1;
      iVar1 = FUN_00404ba0();
      if (9 < *(uint *)(in_ECX + 200)) {
        return;
      }
      iVar1 = *(uint *)(in_ECX + 200) * 0x210 + *(int *)(iVar1 + 0x6924);
      if (*(int *)(iVar1 + 0x5c) == 0) {
        return;
      }
      if (iVar1 == 0) {
        return;
      }
      FUN_00414680();
      FUN_004a3b80(*(undefined4 *)(in_ECX + 200),0);
      return;
    }
    if (iVar1 != 0x70b) {
      return;
    }
    if (*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0x84) + 0x20)) {
      return;
    }
    iVar1 = *(int *)(*(int *)(in_ECX + 0x84) + 0xcc);
    if ((iVar1 == 0) || (iVar1 = *(int *)(iVar1 + 0xdc), iVar1 == 0)) {
      iVar1 = -1;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x20);
    }
    *(int *)(in_ECX + 200) = iVar1 + 1;
    puVar2 = (undefined4 *)FUN_00891268(0x18);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[5] = *(undefined4 *)(in_ECX + 200);
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf4246;
      *puVar2 = FoxUI::FXUIEventI1::vftable;
      FUN_00404aa0();
      FUN_00750020();
      return;
    }
  }
  FUN_00404aa0();
  FUN_00750020();
  return;
}

