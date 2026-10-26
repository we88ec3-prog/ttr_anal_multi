
void FUN_00571b20(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 *in_EDX;
  int unaff_EBX;
  int unaff_ESI;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uStack_5c;
  int iStack_4c;
  int iStack_48;
  int local_44;
  int iStack_40;
  uint local_2c;
  undefined4 local_28;
  void *local_24;
  undefined4 local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00921d08;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_4c;
  uStack_5c = DAT_00d61f20 ^ (uint)&stack0xffffffa8;
  ExceptionList = &local_14;
  local_2c = 0;
  local_28 = 0;
  local_24 = (void *)0x80;
  local_20 = 0x100;
  (**(code **)(*(int *)*in_EDX + 0x20))(param_1);
  FUN_00571930(param_1 + 0x28,in_ECX + 0x1a);
  iStack_4c = param_1 + 0xe;
  iStack_48 = in_ECX + 0x5e;
  local_44 = param_1 + 0x73;
  iStack_40 = in_ECX + 0xa7;
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_1c = 0;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_1c = 0xffffffff;
  }
  uVar3 = DAT_00fb7b90;
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_1c = 1;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_1c = 0xffffffff;
  }
  uVar1 = *(undefined4 *)(unaff_ESI + 0x24);
  FUN_00736180(&stack0xffffffac);
  if ((unaff_EBX == DAT_00fb7b80) || (DAT_00fb7b90 = uVar1, unaff_EBX == -0x10)) {
    DAT_00fb7b90 = DAT_00fb7b8c;
  }
  puVar2 = *(undefined4 **)(unaff_ESI + 0x2c);
  for (puVar4 = *(undefined4 **)(unaff_ESI + 0x28); puVar4 != puVar2; puVar4 = puVar4 + 7) {
    puVar5 = puVar4;
    if (7 < (uint)puVar4[5]) {
      puVar5 = (undefined4 *)*puVar4;
    }
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_1c = 2;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_1c = 0xffffffff;
    }
    FUN_00735c90(&iStack_4c,puVar5,0xffffffff,0xff000000);
    iStack_48 = iStack_48 + 0xe;
  }
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_1c = 3;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
  }
  FUN_00736180(&stack0xffffffa8);
  if ((unaff_EBX == DAT_00fb7b80) || (DAT_00fb7b90 = uVar3, unaff_EBX == -0x10)) {
    DAT_00fb7b90 = DAT_00fb7b8c;
  }
  ExceptionList = local_24;
  __security_check_cookie(local_2c ^ (uint)&uStack_5c);
  return;
}

