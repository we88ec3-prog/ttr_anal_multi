
void FUN_0045d640(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  char cVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 in_EDX;
  undefined1 auStack_84 [4];
  undefined4 local_80;
  int local_7c;
  undefined1 local_78 [24];
  uint local_60;
  undefined4 local_50;
  uint local_4c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009450d6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_84;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xffffff70;
  ExceptionList = &local_14;
  cVar4 = FUN_0045dcc0(in_EDX);
  if (cVar4 == '\0') {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 0;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_c = 0xffffffff;
    }
    local_80 = 0x1b2;
    FUN_005740f0(&local_80);
    if (local_7c == DAT_00fe5b10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    if (*(uint *)(local_7c + 0x24) < 8) {
      FUN_00609a60();
    }
    else {
      FUN_00609a60();
    }
  }
  else {
    puVar6 = (undefined4 *)FUN_00891268(0x1c,uVar5);
    if (puVar6 != (undefined4 *)0x0) {
      uVar1 = *(undefined4 *)(param_1 + 0x10c);
      uVar2 = *(undefined4 *)(param_1 + 0x108);
      puVar6[1] = 0xffffffff;
      puVar6[2] = 0xffffffff;
      puVar6[3] = 0;
      puVar6[4] = 0xf4369;
      *puVar6 = FoxUI::FXUIEventI2::vftable;
      puVar6[5] = uVar2;
      puVar6[6] = uVar1;
    }
    FUN_004072a0();
    puVar6 = (undefined4 *)FUN_00891268(0x1c,uVar5);
    if (puVar6 != (undefined4 *)0x0) {
      puVar6[1] = 0xffffffff;
      puVar6[2] = 0xffffffff;
      puVar6[3] = 0;
      puVar6[4] = 0xf4368;
      *puVar6 = FoxUI::FXUIEventI2::vftable;
      puVar6[5] = in_EDX;
      puVar6[6] = local_80;
    }
    FUN_004072a0();
    FUN_0045d930(local_78,in_EDX);
    local_c = 1;
    FUN_0045d560();
    local_c = 0xffffffff;
    if (7 < local_4c) {
      FUN_0089120c(local_60);
    }
    local_4c = 7;
    local_50 = 0;
    local_60 = local_60 & 0xffff0000;
    FUN_0045d840();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_84);
  return;
}

