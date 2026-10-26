
void FUN_008e69e0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int local_110;
  int local_10c;
  int local_104;
  int local_100;
  int local_fc;
  undefined4 local_f8 [48];
  undefined4 local_38 [12];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  (*(code *)param_2[0xf])(param_2,local_f8,0x10,&local_100);
  if (local_100 < 0) {
    param_2[3] = 0xa2;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if ((local_100 != 0) && (local_100 < 0x11)) {
    uVar1 = *param_2;
    uVar2 = param_2[2];
    local_110 = *(int *)(param_1 + 0x210);
    local_10c = 0;
    local_104 = 0;
    if (0 < local_100) {
      do {
        uVar4 = local_f8[local_104 * 3 + 1];
        *param_2 = local_f8[local_104 * 3];
        param_2[2] = uVar4;
        (*(code *)param_2[0xf])(param_2,local_38,4,&local_fc);
        if (local_104 == 0) {
          if ((local_fc < 1) || (4 < local_fc)) goto LAB_008e6ba5;
          local_10c = local_fc;
          iVar3 = FUN_008e5ee0(param_1,local_fc);
          if (iVar3 != 0) goto LAB_008e6baa;
          local_110 = *(int *)(param_1 + 0x210);
        }
        else if (local_fc != local_10c) goto LAB_008e6ba5;
        iVar3 = 0;
        if (0 < local_fc) {
          puVar5 = local_38;
          do {
            uVar4 = puVar5[1];
            *param_2 = *puVar5;
            param_2[2] = uVar4;
            uVar4 = (*(code *)param_2[10])(param_2,0);
            *(undefined4 *)(*(int *)(local_110 + 0x18 + local_104 * 4) + iVar3 * 4) = uVar4;
            iVar3 = iVar3 + 1;
            puVar5 = puVar5 + 3;
          } while (iVar3 < local_fc);
        }
        local_104 = local_104 + 1;
      } while (local_104 < local_100);
    }
    *param_2 = uVar1;
    param_2[2] = uVar2;
    param_2[3] = 0;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_008e6ba5:
  iVar3 = 3;
LAB_008e6baa:
  param_2[3] = iVar3;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

