
void FUN_00650820(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  undefined4 uVar4;
  undefined2 *puVar5;
  undefined4 *local_8;
  
  iVar2 = *(int *)(in_EAX + 8);
  if (iVar2 == *(int *)(*(int *)(in_ECX + 0xec) + 0x20)) {
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf42dc;
      FUN_004072a0();
      return;
    }
LAB_00650a52:
    FUN_004072a0();
    return;
  }
  if (iVar2 == *(int *)(*(int *)(in_ECX + 0xf0) + 0x20)) {
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf42f7;
      FUN_004072a0();
      return;
    }
    goto LAB_00650a52;
  }
  if (iVar2 == *(int *)(*(int *)(in_ECX + 0xf4) + 0x20)) {
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf42f8;
      FUN_004072a0();
      return;
    }
    goto LAB_00650a52;
  }
  if (iVar2 == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)) {
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf42f9;
      FUN_004072a0();
      return;
    }
    goto LAB_00650a52;
  }
  if (iVar2 == *(int *)(*(int *)(in_ECX + 0xfc) + 0x20)) {
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf42fd;
      FUN_004072a0();
      return;
    }
    goto LAB_00650a52;
  }
  if (iVar2 == *(int *)(*(int *)(in_ECX + 0x100) + 0x20)) {
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf430d;
      FUN_004072a0();
      return;
    }
    goto LAB_00650a52;
  }
  if (iVar2 == *(int *)(*(int *)(in_ECX + 0x104) + 0x20)) {
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf430e;
      FUN_004072a0();
      return;
    }
    goto LAB_00650a52;
  }
  if (iVar2 == *(int *)(*(int *)(in_ECX + 0x108) + 0x20)) {
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf430f;
      FUN_004072a0();
      return;
    }
    goto LAB_00650a52;
  }
  if (iVar2 == *(int *)(*(int *)(in_ECX + 0x10c) + 0x20)) {
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
      puVar5 = &DAT_00bed1fc;
      uVar4 = 0x1bd;
    }
    else {
      puVar5 = &DAT_00bed1fc;
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf43d2;
      uVar4 = 0x1bd;
    }
LAB_00650bc8:
    FUN_005854b0(uVar4,puVar5,puVar1);
    uVar4 = FUN_00585330(uVar4);
    FUN_00404b10(0xcf,uVar4);
    return;
  }
  if (iVar2 == *(int *)(*(int *)(in_ECX + 0x110) + 0x20)) {
    iVar2 = FUN_00404ba0();
    switch(*(undefined4 *)(iVar2 + 0x5f4c)) {
    case 7:
    case 0x15:
    case 0x17:
    case 0x18:
      FUN_00414680();
      FUN_004a3bc0();
      return;
    }
    iVar2 = FUN_0041a4d0();
    if ((*(int *)(iVar2 + 0x5ed8) == 0) || (uVar3 = FUN_00539a70(), uVar3 < 2)) {
      iVar2 = FUN_0041a4d0();
      if (*(int *)(iVar2 + 0x5ed8) == 0) {
        return;
      }
      FUN_0053ba20();
      return;
    }
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf4409;
    }
    uVar4 = 0x196;
    FUN_005854b0(0x196,puVar1);
    puVar5 = (undefined2 *)FUN_00585330(uVar4);
    uVar4 = 0x3b;
    goto LAB_00650bc8;
  }
  if (iVar2 == *(int *)(*(int *)(in_ECX + 0x114) + 0x20)) {
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf440a;
    }
    uVar4 = 0x196;
    FUN_005854b0(0x196,puVar1);
    puVar5 = (undefined2 *)FUN_00585330(uVar4);
    uVar4 = 0x1bb;
    goto LAB_00650bc8;
  }
  if (iVar2 == *(int *)(*(int *)(in_ECX + 0x118) + 0x20)) {
    local_8 = (undefined4 *)FUN_00891268(0x18);
    if (local_8 != (undefined4 *)0x0) {
      local_8[1] = 0xffffffff;
      local_8[2] = 0xffffffff;
      local_8[3] = 0;
      local_8[4] = 0xf433b;
      *local_8 = FoxUI::FXUIEventB1::vftable;
      *(undefined1 *)(local_8 + 5) = 0;
      goto LAB_00650c5d;
    }
  }
  else {
    if (iVar2 != *(int *)(*(int *)(in_ECX + 0x11c) + 0x20)) {
      return;
    }
    local_8 = (undefined4 *)FUN_00891268(0x14);
    if (local_8 != (undefined4 *)0x0) {
      *local_8 = FoxUI::FXUIEvent::vftable;
      local_8[1] = 0xffffffff;
      local_8[2] = 0xffffffff;
      local_8[3] = 0;
      local_8[4] = 0xf433f;
      goto LAB_00650c5d;
    }
  }
  local_8 = (undefined4 *)0x0;
LAB_00650c5d:
  FUN_00404aa0();
  FUN_00804260(&local_8);
  return;
}

