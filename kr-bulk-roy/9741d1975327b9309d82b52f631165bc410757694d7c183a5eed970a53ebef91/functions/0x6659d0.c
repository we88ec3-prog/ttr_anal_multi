
void FUN_006659d0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 auStack_6c [20];
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined1 auStack_50 [20];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined2 *puStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined2 local_22;
  undefined1 *local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009331d8;
  local_14 = ExceptionList;
  uStack_2c = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if (*(int *)(param_1 + 0x10) == 0x578) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)) {
      uStack_30 = *(undefined4 *)(in_ECX + 0x108);
      puStack_34 = (undefined2 *)0x665a26;
      FUN_006669b0();
      ExceptionList = local_14;
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0xfc) + 0x20)) {
      uStack_30 = 0x665a49;
      FUN_004054c0();
      uStack_30 = 0;
      puStack_34 = (undefined2 *)0x0;
      uStack_38 = 0xf4315;
      uStack_3c = 0x665a57;
      FUN_0058aee0();
      ExceptionList = local_14;
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x100) + 0x20)) {
      uStack_30 = 0x665a81;
      FUN_004054c0();
      uStack_30 = 0;
      puStack_34 = (undefined2 *)0x0;
      uStack_38 = 0x196;
      uStack_3c = 0x665a8f;
      FUN_005854b0();
      uStack_3c = 0x665a96;
      uStack_54 = FUN_00585330();
      local_20 = auStack_50;
      uStack_58 = 0x665aa5;
      FUN_00402250();
      uStack_54 = 0x143;
      local_c = 0;
      uStack_58 = 0x665ab7;
      FUN_005854b0();
      uStack_58 = 0x665abe;
      uVar2 = FUN_00585330();
      local_1c = auStack_6c;
      FUN_00402250(uVar2);
      local_c = 0xffffffff;
      FUN_0058b270(0xc9);
      local_22 = 0x97;
      if (DAT_00fba798 == 0) {
        uStack_30 = 2;
        puStack_34 = &local_22;
        uStack_38 = 0;
        uStack_3c = 0x665b0b;
        (**(code **)(*DAT_00fba854 + 0x10))();
      }
    }
  }
  ExceptionList = local_14;
  return;
}

