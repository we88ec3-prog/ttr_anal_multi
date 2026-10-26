
void FUN_008e4c10(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  char extraout_DL;
  undefined4 *in_EDX;
  undefined4 *puVar4;
  undefined4 local_40 [2];
  int local_38;
  int local_30;
  undefined1 local_2c [4];
  int local_28;
  char local_22;
  char local_21 [25];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_28 = *in_EDX;
  local_30 = 0;
  puVar4 = *(undefined4 **)(in_EDX[0x13] + 0xb9c);
  if (puVar4 == (undefined4 *)0x0) {
    *(code **)(in_EDX[0x13] + 0xba0) = FUN_005f5d10;
    uVar1 = FUN_008baee0(local_28,0x1f8,&local_30);
    *(undefined4 *)(in_EDX[0x13] + 0xb9c) = uVar1;
    if (local_30 != 0) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    puVar4 = *(undefined4 **)(in_EDX[0x13] + 0xb9c);
    *puVar4 = local_28;
    FUN_008e0af0(local_28);
  }
  puVar4[0x21] = in_EDX;
  puVar4[0x20] = in_EDX;
  local_28 = *(int *)(in_EDX[1] + 0x60);
  local_38 = in_ECX + param_1;
  local_40[0] = 0;
  local_21[1] = '\0';
  local_21[2] = '\0';
  local_21[3] = '\0';
  local_21[4] = '\0';
  local_21[5] = '\0';
  local_21[6] = '\0';
  local_21[7] = '\0';
  local_21[8] = '\0';
  local_21[9] = '\0';
  local_21[10] = '\0';
  local_21[0xb] = '\0';
  local_21[0xc] = '\0';
  local_21[0xd] = '\0';
  local_21[0xe] = '\0';
  local_21[0xf] = '\0';
  local_21[0x10] = '\0';
  local_21[0x11] = '\0';
  local_21[0x12] = '\0';
  local_21[0x13] = '\0';
  local_21[0x14] = '\0';
  local_21[0x15] = '\0';
  local_21[0x16] = '\0';
  local_21[0x17] = '\0';
  local_21[0x18] = '\0';
  FUN_008e0b20(local_21);
  puVar4[2] = 0;
  if (local_22 != '\0') {
    puVar4[2] = 1;
  }
  if ((local_21[0] != '\0') && (*(char *)(local_28 + 0x20) == '\0')) {
    puVar4[2] = puVar4[2] | 2;
  }
  puVar4[0x24] = *(undefined4 *)(local_28 + 0x24);
  puVar4[0x25] = *(undefined4 *)(local_28 + 0x28);
  puVar4[0x26] = *(undefined4 *)(local_28 + 0x2c);
  puVar4[0x27] = *(undefined4 *)(local_28 + 0x30);
  puVar4[0x28] = *(undefined4 *)(local_28 + 0x34);
  puVar4[0x29] = *(undefined4 *)(local_28 + 0x38);
  puVar4[0x2a] = *(undefined4 *)(local_28 + 0x3c);
  puVar4[0x2b] = *(undefined4 *)(local_28 + 0x40);
  uVar2 = FUN_008e0b90();
  puVar4[0x16] = uVar2 & 0xffff;
  if (extraout_DL != '\0') {
    iVar3 = FUN_008e09c0();
    if (iVar3 != 0) goto LAB_008e4dc3;
  }
  iVar3 = FUN_008e4b30(local_40,local_2c);
  if (iVar3 != 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_008e0a00();
LAB_008e4dc3:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

