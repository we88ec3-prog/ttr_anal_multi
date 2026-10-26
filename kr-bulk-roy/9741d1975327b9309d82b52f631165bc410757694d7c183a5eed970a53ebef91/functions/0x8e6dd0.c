
void FUN_008e6dd0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *local_d4;
  int local_cc;
  undefined4 local_c8 [48];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_d4 = *(int **)(param_1 + 0x210);
  (*(code *)param_2[0xf])(param_2,local_c8,0x10,&local_cc);
  if (local_cc < 0) {
    param_2[3] = 0xa2;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if ((local_cc != 0) && (local_cc < 0x11)) {
    if ((local_d4 == (int *)0x0) || (*local_d4 == 0)) {
      iVar3 = FUN_008e5ee0(param_1,0);
      if (iVar3 == 0) {
        local_d4 = *(int **)(param_1 + 0x210);
        goto LAB_008e6e93;
      }
      goto LAB_008e6e58;
    }
    if (*local_d4 == local_cc) {
LAB_008e6e93:
      uVar1 = *param_2;
      uVar2 = param_2[2];
      iVar3 = 0;
      if (0 < local_cc) {
        puVar5 = local_c8;
        do {
          uVar4 = puVar5[1];
          *param_2 = *puVar5;
          param_2[2] = uVar4;
          uVar4 = (*(code *)param_2[10])(param_2,0);
          *(undefined4 *)(local_d4[0x22] + iVar3 * 4) = uVar4;
          *(undefined4 *)(local_d4[0x23] + iVar3 * 4) = uVar4;
          iVar3 = iVar3 + 1;
          puVar5 = puVar5 + 3;
        } while (iVar3 < local_cc);
      }
      param_2[3] = 0;
      *param_2 = uVar1;
      param_2[2] = uVar2;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  iVar3 = 3;
LAB_008e6e58:
  param_2[3] = iVar3;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

