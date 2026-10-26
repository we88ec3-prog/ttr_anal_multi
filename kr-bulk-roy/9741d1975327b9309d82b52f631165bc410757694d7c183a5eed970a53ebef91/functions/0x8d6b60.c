
void FUN_008d6b60(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar2 = (**(code **)(param_2 + 0x34))(param_2,6,&local_20,3);
  if (iVar2 < 6) {
    *(undefined4 *)(param_2 + 0xc) = 3;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  iVar2 = (local_14 ^ (int)local_14 >> 0x1f) - ((int)local_14 >> 0x1f);
  if (iVar2 != 0) {
    uVar1 = FUN_008b7f40(1000,iVar2);
    *(undefined2 *)(param_1 + 0x44) = uVar1;
    if (iVar2 != 0x10000) {
      local_20 = FUN_008b7f40(local_20,iVar2);
      local_1c = FUN_008b7f40(local_1c,iVar2);
      local_18 = FUN_008b7f40(local_18,iVar2);
      local_10 = FUN_008b7f40(local_10,iVar2);
      local_c = FUN_008b7f40(local_c,iVar2);
      local_14 = ((-1 < (int)local_14) - 1 & 0xfffe0000) + 0x10000;
    }
    *(undefined4 *)(param_1 + 0x1b4) = local_20;
    *(uint *)(param_1 + 0x1c0) = local_14;
    *(undefined4 *)(param_1 + 0x1bc) = local_1c;
    *(undefined4 *)(param_1 + 0x1b8) = local_18;
    *(int *)(param_1 + 0x1c4) = local_10 >> 0x10;
    *(int *)(param_1 + 0x1c8) = local_c >> 0x10;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(undefined4 *)(param_2 + 0xc) = 3;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

