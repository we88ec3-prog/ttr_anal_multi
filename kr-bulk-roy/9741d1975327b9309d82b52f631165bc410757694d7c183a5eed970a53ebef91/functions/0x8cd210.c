
void FUN_008cd210(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_1c;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (param_1[1] == 0) {
    uVar1 = *param_1;
    if (((int)param_2 < 0) || (1 < (int)param_2)) {
      param_2 = (uint)(param_2 != 0);
    }
    if (param_1[3] != 1) {
      param_1[1] = 6;
      __security_check_cookie
                (local_8 ^ (uint)&stack0xfffffffc,param_1 + param_2 * 9 + 4,param_1,
                 param_1 + param_2 * 9 + 4);
      return;
    }
    local_1c = 0;
    puVar3 = &local_14;
    do {
      FUN_008b7c80(param_3[1],uVar1,puVar3);
      iVar2 = FUN_008b7c80(*param_3);
      iVar2 = FUN_008ccf90(iVar2 >> 0x10);
      if (iVar2 != 0) goto LAB_008cd2d3;
      local_1c = local_1c + 1;
      puVar3 = puVar3 + 1;
      param_3 = param_3 + 2;
    } while (local_1c < 3);
    iVar2 = FUN_008cd050(local_14,local_10,local_c,uVar1);
    if (iVar2 != 0) {
LAB_008cd2d3:
      param_1[1] = iVar2;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

