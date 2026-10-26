
void FUN_008407e0(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *in_ECX;
  undefined1 local_130 [284];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090bd2d;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar3;
  if (*(int *)(param_1 + 0x20) == *(int *)(param_1 + 0x24)) {
    DAT_00fe34e8 = DAT_00fe34e8 + 1;
    if (0xffff < DAT_00fe34e8) {
      DAT_00fe34e8 = 1;
    }
    uVar2 = DAT_00fe34e8;
    *in_ECX = (short)(*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10) >> 2);
    in_ECX[1] = (short)uVar2;
    FUN_00842f30(local_130);
    local_8 = 0;
    FUN_00866530(uVar3);
    local_8 = 0xffffffff;
    FUN_00843340(local_130);
    FUN_006de9c0();
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 0x24) + -4);
    DAT_00fe34e8 = DAT_00fe34e8 + 1;
    if (0xffff < DAT_00fe34e8) {
      DAT_00fe34e8 = 1;
    }
    uVar3 = DAT_00fe34e8;
    *in_ECX = (short)iVar1;
    in_ECX[1] = (short)uVar3;
    if (*(int *)(param_1 + 0x20) != *(int *)(param_1 + 0x24)) {
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -4;
    }
    *(uint *)(*(int *)(param_1 + 0x10) + iVar1 * 4) = (uint)(ushort)in_ECX[1];
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

