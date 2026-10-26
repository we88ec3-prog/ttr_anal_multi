
void FUN_008db420(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar2 = *(int *)(param_2 + 0x60);
  if ((-1 < iVar2) && (iVar2 < *(int *)(param_1 + 300))) {
    iVar2 = iVar2 * 0xfc + *(int *)(param_1 + 0x130);
    iVar3 = (**(code **)(param_2 + 0x34))(param_2,6,&local_20,3);
    if (5 < iVar3) {
      iVar3 = (local_14 ^ (int)local_14 >> 0x1f) - ((int)local_14 >> 0x1f);
      if (iVar3 != 0) {
        uVar1 = FUN_008b7f40(1000,iVar3);
        *(undefined2 *)(param_1 + 0x44) = uVar1;
        if (iVar3 != 0x10000) {
          local_20 = FUN_008b7f40(local_20,iVar3);
          local_1c = FUN_008b7f40(local_1c,iVar3);
          local_18 = FUN_008b7f40(local_18,iVar3);
          local_10 = FUN_008b7f40(local_10,iVar3);
          local_c = FUN_008b7f40(local_c,iVar3);
          local_14 = ((-1 < (int)local_14) - 1 & 0xfffe0000) + 0x10000;
        }
        *(undefined4 *)(iVar2 + 0xd8) = local_20;
        *(undefined4 *)(iVar2 + 0xe0) = local_1c;
        *(undefined4 *)(iVar2 + 0xdc) = local_18;
        *(uint *)(iVar2 + 0xe4) = local_14;
        *(int *)(iVar2 + 0xe8) = local_10 >> 0x10;
        *(int *)(iVar2 + 0xec) = local_c >> 0x10;
        goto LAB_008db548;
      }
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_008db548:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

