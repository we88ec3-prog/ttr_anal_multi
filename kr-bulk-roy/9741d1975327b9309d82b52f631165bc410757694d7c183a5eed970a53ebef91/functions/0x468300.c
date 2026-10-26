
void FUN_00468300(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined1 auStack_9c [4];
  undefined4 *local_98;
  int local_94;
  int local_90;
  undefined1 local_8c [56];
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092a0d7;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_9c;
  ExceptionList = &local_14;
  if (param_1[4] == 0x578) {
    if (*(int *)(*(int *)(in_ECX + 0x250) + 0x20) == param_1[2]) {
      local_98 = *(undefined4 **)(in_ECX + 0x254);
      iVar4 = FUN_00461dd0(DAT_00d61f20 ^ (uint)&stack0xffffff58);
      FUN_00401280(&local_98);
      if (local_94 == *(int *)(iVar4 + 4)) {
        local_98 = (undefined4 *)0x0;
      }
      else {
        local_98 = (undefined4 *)(local_94 + 0x10);
      }
      FUN_00757200(local_8c);
      local_c = 0;
      local_94 = 0x1b1;
      iVar4 = FUN_005854b0();
      FUN_005740f0(&local_94);
      if (local_90 == *(int *)(iVar4 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      FUN_00757710();
      FUN_00759ac0(0);
      FUN_00759ac0(1);
      local_98 = (undefined4 *)FUN_00891268(0x14);
      if (local_98 == (undefined4 *)0x0) {
        local_98 = (undefined4 *)0x0;
      }
      else {
        *local_98 = FoxUI::FXUIEvent::vftable;
        local_98[1] = 0xffffffff;
        local_98[2] = 0xffffffff;
        local_98[3] = 0;
        local_98[4] = 0xf441b;
      }
      local_90 = 0x196;
      iVar4 = FUN_005854b0();
      FUN_005740f0(&local_90);
      if (local_94 == *(int *)(iVar4 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      puVar5 = (undefined4 *)(local_94 + 0x10);
      if (7 < *(uint *)(local_94 + 0x24)) {
        puVar5 = (undefined4 *)*puVar5;
      }
      FUN_007572f0(puVar5);
      local_c._0_1_ = 1;
      FUN_00407330(0xcf,local_8c,local_54,local_98);
      local_c = (uint)local_c._1_3_ << 8;
      FUN_00757640(local_54);
      local_c = 0xffffffff;
      FUN_00757640(local_8c);
    }
  }
  else if (param_1[4] == 0xf441b) {
    iVar4 = (**(code **)(*param_1 + 4))();
    if (iVar4 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      param_1 = (int *)0x0;
    }
    if (param_1[5] == 0x6a7) {
      puVar5 = (undefined4 *)FUN_00891268(0x1c);
      if (puVar5 == (undefined4 *)0x0) {
        FUN_004072a0();
      }
      else {
        uVar1 = *(undefined4 *)(in_ECX + 600);
        uVar2 = *(undefined4 *)(in_ECX + 0x254);
        puVar5[1] = 0xffffffff;
        puVar5[2] = 0xffffffff;
        puVar5[3] = 0;
        puVar5[4] = 0xf441b;
        *puVar5 = FoxUI::FXUIEventI2::vftable;
        puVar5[5] = uVar2;
        puVar5[6] = uVar1;
        FUN_004072a0();
      }
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_9c);
  return;
}

