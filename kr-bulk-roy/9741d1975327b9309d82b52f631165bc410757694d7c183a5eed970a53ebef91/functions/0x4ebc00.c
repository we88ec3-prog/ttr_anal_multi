
undefined4 FUN_004ebc00(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00929afc;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar2 = DAT_00fb75b0 & 1;
  *(uint *)(in_ECX + 0x5edc) = (uint)*(byte *)(param_1 + 2);
  if (uVar2 == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0;
    FUN_004f3d80(uVar3);
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_8 = 0xffffffff;
  param_1 = *(undefined4 *)(in_ECX + 0x5ec4);
  uVar1 = *(undefined4 *)(in_ECX + 0x5edc);
  FUN_008438c0(&param_1);
  if (in_ECX != DAT_00fb7594) {
    *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x1c) = uVar1;
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf4259);
  ExceptionList = local_10;
  return 0;
}

