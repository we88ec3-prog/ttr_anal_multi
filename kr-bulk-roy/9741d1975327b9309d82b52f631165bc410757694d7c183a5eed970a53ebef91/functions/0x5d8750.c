
void FUN_005d8750(void)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093f1de;
  local_10 = ExceptionList;
  if (*(int *)(in_ECX + 0x25c) == 0) {
    return;
  }
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x2b0) == -1) {
LAB_005d887a:
    if (*(char *)(in_ECX + 0x2c0) == '\0') {
      if ((*(int *)(in_ECX + 0x2b4) == 0) ||
         (iVar2 = FUN_00404ba0(), *(int *)(in_ECX + 0x2b4) <= *(int *)(iVar2 + 0x68cc))) {
        puVar4 = (undefined4 *)FUN_00891268(0x18);
        if (puVar4 != (undefined4 *)0x0) {
          uVar5 = *(undefined4 *)(in_ECX + 0x254);
          puVar4[1] = 0xffffffff;
          puVar4[2] = 0xffffffff;
          puVar4[3] = 0;
          puVar4[4] = 0xf43ab;
          *puVar4 = FoxUI::FXUIEventI1::vftable;
          puVar4[5] = uVar5;
        }
        FUN_00748900();
        ExceptionList = local_10;
        return;
      }
      uVar7 = 0;
      uVar6 = 0;
      uVar5 = 0x196;
      FUN_005854b0(0x196,0,0);
      iVar2 = FUN_00585330(uVar5);
      uVar5 = 0x8f;
      FUN_005854b0(0x8f,iVar2);
      puVar4 = (undefined4 *)FUN_00585330(uVar5);
      goto LAB_005d885a;
    }
    local_18 = 0x196;
    iVar2 = FUN_005854b0();
    FUN_005740f0(&local_18);
    if (local_14 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(uint *)(local_14 + 0x24) < 8) {
      iVar2 = local_14 + 0x10;
    }
    else {
      iVar2 = *(int *)(local_14 + 0x10);
    }
    local_18 = 0xe4;
    iVar3 = FUN_005854b0();
    FUN_005740f0(&local_18);
    if (local_14 == *(int *)(iVar3 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  else {
    if ((DAT_00fbad10 & 1) == 0) {
      DAT_00fbad10 = DAT_00fbad10 | 1;
      local_8 = 0;
      FUN_004e8010(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcd6b0);
    }
    local_8 = 0xffffffff;
    if ((DAT_00fc0bd8 != 0) &&
       (iVar2 = FUN_0044fd50(), *(int *)(in_ECX + 0x2b0) <= *(int *)(iVar2 + 0x5ed0)))
    goto LAB_005d887a;
    local_14 = 0x196;
    iVar2 = FUN_005854b0();
    FUN_005740f0(&local_14);
    if (local_18 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(uint *)(local_18 + 0x24) < 8) {
      iVar2 = local_18 + 0x10;
    }
    else {
      iVar2 = *(int *)(local_18 + 0x10);
    }
    local_18 = 0x8e;
    iVar3 = FUN_005854b0();
    FUN_005740f0(&local_18);
    if (local_14 == *(int *)(iVar3 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  puVar4 = (undefined4 *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    puVar4 = (undefined4 *)*puVar4;
  }
  uVar7 = 0;
  uVar6 = 0;
LAB_005d885a:
  FUN_00404b10(0xca,puVar4,iVar2,uVar6,uVar7);
  ExceptionList = local_10;
  return;
}

