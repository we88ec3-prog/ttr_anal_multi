
void FUN_00621ed0(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined4 *puVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093343c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar5 = (undefined4 *)0x0;
  if ((char)param_2 == '\0') {
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 1;
      FUN_0054f850(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    local_8 = 0xffffffff;
    if (DAT_00fb92e5 != '\x03') {
      ExceptionList = local_10;
      return;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x18);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[3] = 0;
      puVar2[5] = 0;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[4] = 0xf43c7;
      *puVar2 = FoxUI::FXUIEventI1::vftable;
      puVar5 = puVar2;
    }
    param_2 = 0x196;
    iVar3 = FUN_005854b0();
    FUN_005740f0(&param_2);
    if (in_ECX == *(int *)(iVar3 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(uint *)(in_ECX + 0x24) < 8) {
      iVar3 = in_ECX + 0x10;
    }
    else {
      iVar3 = *(int *)(in_ECX + 0x10);
    }
    param_2 = 0x19c;
    iVar4 = FUN_005854b0();
    FUN_005740f0(&param_2);
    if (in_ECX == *(int *)(iVar4 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  else {
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 0;
      FUN_0054f850(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    local_8 = 0xffffffff;
    if (DAT_00fb92e5 == '\x03') {
      ExceptionList = local_10;
      return;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x18);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[3] = 0;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[4] = 0xf43c7;
      *puVar2 = FoxUI::FXUIEventI1::vftable;
      puVar2[5] = 3;
      puVar5 = puVar2;
    }
    param_2 = 0x196;
    iVar3 = FUN_005854b0();
    FUN_005740f0(&param_2);
    if (in_ECX == *(int *)(iVar3 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(uint *)(in_ECX + 0x24) < 8) {
      iVar3 = in_ECX + 0x10;
    }
    else {
      iVar3 = *(int *)(in_ECX + 0x10);
    }
    param_2 = 0x19c;
    iVar4 = FUN_005854b0();
    FUN_005740f0(&param_2);
    if (in_ECX == *(int *)(iVar4 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  puVar2 = (undefined4 *)(in_ECX + 0x10);
  if (7 < *(uint *)(in_ECX + 0x24)) {
    puVar2 = (undefined4 *)*puVar2;
  }
  FUN_00404b10(0xcf,puVar2,iVar3,puVar5,param_1);
  ExceptionList = local_10;
  return;
}

