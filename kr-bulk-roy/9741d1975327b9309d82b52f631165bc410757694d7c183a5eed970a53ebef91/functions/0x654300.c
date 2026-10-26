
byte * FUN_00654300(byte *param_1,byte param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  float in_XMM0_Da;
  byte bStack0000000b;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00904996;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[0] = 4;
  param_1[1] = 0;
  param_1[2] = param_2;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  *(float *)(param_1 + 8) = in_XMM0_Da;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  local_8 = 1;
  bVar1 = *param_1;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  if ((((bVar1 != 0) && (2 < param_1[2])) && (0.01 <= in_XMM0_Da)) && (in_XMM0_Da <= 1.0)) {
    uVar3 = FUN_0087dc3d((uint)bVar1 * 4,uVar2);
    *(undefined4 *)(param_1 + 4) = uVar3;
    bStack0000000b = 0;
    if (*param_1 != 0) {
      do {
        uVar3 = FUN_0087dc3d((uint)param_1[2] * 4,uVar2);
        *(undefined4 *)((uint)bStack0000000b * 4 + *(int *)(param_1 + 4)) = uVar3;
        uVar4 = 0;
        if (param_1[2] != 0) {
          do {
            bVar1 = (char)uVar4 + 1;
            *(undefined4 *)(*(int *)((uint)bStack0000000b * 4 + *(int *)(param_1 + 4)) + uVar4 * 4)
                 = 0;
            uVar4 = (uint)bVar1;
          } while (bVar1 < param_1[2]);
        }
        bStack0000000b = bStack0000000b + 1;
      } while (bStack0000000b < *param_1);
    }
  }
  ExceptionList = local_10;
  return param_1;
}

