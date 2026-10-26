
void FUN_008e66d0(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int local_18 [4];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (param_2 - 1 < 4) {
    uVar2 = 0;
    if (param_2 != 0) {
      do {
        iVar1 = FUN_008b7c80(*(undefined4 *)(param_3 + uVar2 * 4));
        local_18[uVar2] = iVar1 >> 0x10;
        uVar2 = uVar2 + 1;
      } while (uVar2 < param_2);
    }
    FUN_008e65b0(param_1,param_2,local_18);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

