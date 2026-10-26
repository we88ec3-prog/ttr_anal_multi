
void FUN_0067f060(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  undefined4 *puVar5;
  int in_EDX;
  undefined1 auStack_84 [4];
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 local_78 [24];
  uint local_60;
  undefined4 local_50;
  uint local_4c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00942d78;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_84;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff70;
  ExceptionList = &local_14;
  local_7c = param_2;
  if ((in_EDX != -1) && (cVar3 = FUN_0067fea0(in_EDX,param_2), cVar3 != '\0')) {
    puVar5 = (undefined4 *)FUN_00891268(0x1c,uVar4);
    if (puVar5 != (undefined4 *)0x0) {
      uVar1 = *(undefined4 *)(in_EDX * 0x58 + 0x174 + param_1);
      uVar2 = *(undefined4 *)(in_EDX * 0x58 + 0x170 + param_1);
      puVar5[1] = 0xffffffff;
      puVar5[2] = 0xffffffff;
      puVar5[3] = 0;
      puVar5[4] = 0xf4369;
      *puVar5 = FoxUI::FXUIEventI2::vftable;
      puVar5[5] = uVar2;
      puVar5[6] = uVar1;
    }
    FUN_004072a0();
    puVar5 = (undefined4 *)FUN_00891268(0x1c,uVar4);
    if (puVar5 != (undefined4 *)0x0) {
      puVar5[1] = 0xffffffff;
      puVar5[2] = 0xffffffff;
      puVar5[3] = 0;
      puVar5[4] = 0xf4368;
      *puVar5 = FoxUI::FXUIEventI2::vftable;
      puVar5[5] = local_7c;
      puVar5[6] = local_80;
    }
    FUN_004072a0();
    FUN_0067f930(local_78,local_7c);
    local_c = 0;
    FUN_0045d560();
    local_c = 0xffffffff;
    if (7 < local_4c) {
      FUN_0089120c(local_60);
    }
    local_4c = 7;
    local_50 = 0;
    local_60 = local_60 & 0xffff0000;
    FUN_0067f310();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_84);
  return;
}

