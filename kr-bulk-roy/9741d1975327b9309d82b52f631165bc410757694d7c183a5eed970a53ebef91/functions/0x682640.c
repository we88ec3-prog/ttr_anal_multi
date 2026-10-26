
void FUN_00682640(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined1 auStack_64 [3];
  char local_61;
  int local_60;
  int local_5c;
  int local_58;
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093ca88;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_64;
  ExceptionList = &local_14;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 0;
    FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xffffff90);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_c = 0xffffffff;
  local_60 = param_1;
  FUN_008438c0();
  if ((local_5c == DAT_00f8d91c) || (iVar4 = *(int *)(local_5c + 0x10), iVar4 == 0))
  goto LAB_006829dc;
  FUN_00759ac0();
  FUN_007597b0();
  if (*(int *)(local_58 + 0xd0) == 3) {
    iVar2 = FUN_00404ba0();
    iVar4 = *(int *)(iVar4 + 0x30) * param_2;
    local_61 = iVar4 - *(int *)(iVar2 + 0x6868) == 0 || iVar4 < *(int *)(iVar2 + 0x6868);
    local_5c = 0xf4;
    iVar4 = FUN_005854b0();
    FUN_005740f0();
    if (local_60 == *(int *)(iVar4 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_00759ac0();
LAB_00682876:
    FUN_007597b0();
  }
  else {
    if (*(int *)(local_58 + 0xd0) == 4) {
      iVar2 = FUN_00404ba0();
      iVar4 = *(int *)(iVar4 + 0x2c) * param_2;
      local_61 = iVar4 - *(int *)(iVar2 + 0x6870) == 0 || iVar4 < *(int *)(iVar2 + 0x6870);
      local_5c = 0xf5;
      iVar4 = FUN_005854b0();
      FUN_005740f0();
      if (local_60 == *(int *)(iVar4 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      FUN_00759ac0();
      goto LAB_00682876;
    }
    iVar2 = FUN_00404ba0();
    iVar6 = *(int *)(iVar4 + 0x24) * param_2;
    local_61 = iVar6 - *(int *)(iVar2 + 0x6864) == 0 || iVar6 < *(int *)(iVar2 + 0x6864);
    local_5c = 0xf3;
    iVar2 = FUN_005854b0();
    FUN_005740f0();
    if (local_60 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_00759ac0();
    FUN_007599b0((longlong)*(int *)(iVar4 + 0x24) * (longlong)param_2);
  }
  if (local_61 == '\0') {
    local_5c = 0x196;
    iVar4 = FUN_005854b0();
    FUN_005740f0();
    if (local_60 == *(int *)(iVar4 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(uint *)(local_60 + 0x24) < 8) {
      iVar4 = local_60 + 0x10;
    }
    else {
      iVar4 = *(int *)(local_60 + 0x10);
    }
    local_5c = 0xf;
    iVar2 = FUN_005854b0();
    FUN_005740f0();
    if (local_60 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    puVar5 = (undefined4 *)(local_60 + 0x10);
    if (7 < *(uint *)(local_60 + 0x24)) {
      puVar5 = (undefined4 *)*puVar5;
    }
    FUN_00404b10(0xca,puVar5,iVar4,0,0);
  }
  else {
    puVar3 = (undefined4 *)FUN_00891268();
    puVar5 = (undefined4 *)0x0;
    if (puVar3 != (undefined4 *)0x0) {
      puVar3[3] = 0;
      *puVar3 = FoxUI::FXUIEvent::vftable;
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[4] = 0xf43ac;
      puVar5 = puVar3;
    }
    local_5c = 0x196;
    iVar4 = FUN_005854b0();
    FUN_005740f0();
    if (local_60 == *(int *)(iVar4 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_007572f0();
    local_c = 1;
    FUN_00407330(0xcf,local_58 + 0x128,local_54,puVar5,local_58);
    local_c = 0xffffffff;
    FUN_00757640();
    *(int *)(local_58 + 0x160) = param_1;
    *(int *)(local_58 + 0x164) = param_2;
  }
LAB_006829dc:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_64);
  return;
}

