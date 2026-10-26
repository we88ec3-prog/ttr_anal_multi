
void FUN_00626f30(int param_1)

{
  code *pcVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int in_EDX;
  undefined4 uVar7;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009333fc;
  local_10 = ExceptionList;
  iVar5 = *(int *)(in_EDX + 8);
  if (iVar5 == *(int *)(*(int *)(param_1 + 0xfc) + 0x20)) {
    ExceptionList = &local_10;
    puVar3 = (undefined4 *)FUN_00891268(0x18);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0xf43cc;
      *puVar3 = FoxUI::FXUIEventI1::vftable;
      puVar3[5] = 0;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    local_14 = 0x196;
    FUN_005740f0(&local_14);
    if (local_18 == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(uint *)(local_18 + 0x24) < 8) {
      iVar5 = local_18 + 0x10;
    }
    else {
      iVar5 = *(int *)(local_18 + 0x10);
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 1;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    local_18 = 0x19f;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    puVar4 = (undefined4 *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      puVar4 = (undefined4 *)*puVar4;
    }
  }
  else if (iVar5 == *(int *)(*(int *)(param_1 + 0x100) + 0x20)) {
    ExceptionList = &local_10;
    puVar3 = (undefined4 *)FUN_00891268(0x18);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0xf43cc;
      *puVar3 = FoxUI::FXUIEventI1::vftable;
      puVar3[5] = 1;
    }
    local_18 = 0x196;
    iVar5 = FUN_005854b0();
    FUN_005740f0(&local_18);
    if (local_14 == *(int *)(iVar5 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(uint *)(local_14 + 0x24) < 8) {
      iVar5 = local_14 + 0x10;
    }
    else {
      iVar5 = *(int *)(local_14 + 0x10);
    }
    local_18 = 0x19e;
    iVar6 = FUN_005854b0();
    FUN_005740f0(&local_18);
    if (local_14 == *(int *)(iVar6 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    puVar4 = (undefined4 *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      puVar4 = (undefined4 *)*puVar4;
    }
  }
  else {
    if (iVar5 == *(int *)(*(int *)(param_1 + 0x104) + 0x20)) {
      ExceptionList = &local_10;
      puVar3 = (undefined4 *)FUN_00891268(0x18);
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3[1] = 0xffffffff;
        puVar3[2] = 0xffffffff;
        puVar3[3] = 0;
        puVar3[4] = 0xf43cc;
        *puVar3 = FoxUI::FXUIEventI1::vftable;
        puVar3[5] = 2;
      }
      uVar7 = 0x196;
      FUN_005854b0(0x196,puVar3,param_1);
      iVar5 = FUN_00585330(uVar7);
      uVar7 = 0x1a0;
    }
    else {
      if (iVar5 != *(int *)(*(int *)(param_1 + 0x108) + 0x20)) {
        return;
      }
      ExceptionList = &local_10;
      cVar2 = FUN_0062a850(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      if (cVar2 == '\0') {
        ExceptionList = local_10;
        return;
      }
      puVar3 = (undefined4 *)FUN_00891268(0x14);
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        *puVar3 = FoxUI::FXUIEvent::vftable;
        puVar3[1] = 0xffffffff;
        puVar3[2] = 0xffffffff;
        puVar3[3] = 0;
        puVar3[4] = 0xf43cd;
      }
      uVar7 = 0x196;
      FUN_005854b0(0x196,puVar3,param_1);
      iVar5 = FUN_00585330(uVar7);
      uVar7 = 0x1a1;
    }
    FUN_005854b0(uVar7,iVar5);
    puVar4 = (undefined4 *)FUN_00585330(uVar7);
  }
  FUN_00404b10(0xcf,puVar4,iVar5,puVar3,param_1);
  ExceptionList = local_10;
  return;
}

