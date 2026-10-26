
undefined4 FUN_0083a5b0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090e4fb;
  local_10 = ExceptionList;
  if ((((*(int *)(in_ECX + 0xec) != 0) && (param_1 != 0)) && (*(int *)(param_1 + 0x40) != 0)) &&
     (*(int *)(param_1 + 0x44) != 0)) {
    ExceptionList = &local_10;
    iVar1 = FUN_00891268(0x24,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    local_8 = 0;
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_00864900(iVar1,*(undefined4 *)(in_ECX + 0xec));
    }
    local_8 = 0xffffffff;
    if (*(undefined4 **)(param_1 + 0x68) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x68))(1);
      *(undefined4 *)(param_1 + 0x68) = 0;
    }
    *(undefined4 *)(param_1 + 0x68) = uVar2;
    if (*(int *)(param_1 + 0x3c) == 0) {
      FUN_0084dfe0();
      FUN_0084e030();
    }
    ExceptionList = local_10;
    return 1;
  }
  return 0;
}

