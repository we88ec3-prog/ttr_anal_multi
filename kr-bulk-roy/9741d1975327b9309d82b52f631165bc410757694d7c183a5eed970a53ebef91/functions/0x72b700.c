
uint FUN_0072b700(uint param_1)

{
  uint in_EAX;
  uint uVar1;
  uint *in_ECX;
  uint *puVar2;
  uint uVar3;
  
  uVar1 = ~in_EAX;
  for (; (param_1 != 0 && (((uint)in_ECX & 3) != 0)); in_ECX = (uint *)((int)in_ECX + 1)) {
    uVar1 = uVar1 >> 8 ^ *(uint *)(&DAT_00c08ce8 + (((byte)*in_ECX ^ uVar1) & 0xff) * 4);
    param_1 = param_1 - 1;
  }
  if (0x1f < param_1) {
    uVar3 = param_1 >> 5;
    puVar2 = in_ECX;
    do {
      uVar1 = uVar1 ^ *puVar2;
      uVar1 = *(uint *)(&DAT_00c090e8 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_00c094e8 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_00c08ce8 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_00c098e8 + (uVar1 & 0xff) * 4) ^ puVar2[1];
      uVar1 = *(uint *)(&DAT_00c090e8 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_00c094e8 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_00c08ce8 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_00c098e8 + (uVar1 & 0xff) * 4) ^ puVar2[2];
      uVar1 = *(uint *)(&DAT_00c090e8 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_00c094e8 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_00c08ce8 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_00c098e8 + (uVar1 & 0xff) * 4) ^ puVar2[3];
      uVar1 = *(uint *)(&DAT_00c090e8 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_00c094e8 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_00c08ce8 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_00c098e8 + (uVar1 & 0xff) * 4) ^ puVar2[4];
      uVar1 = *(uint *)(&DAT_00c090e8 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_00c094e8 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_00c08ce8 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_00c098e8 + (uVar1 & 0xff) * 4) ^ puVar2[5];
      in_ECX = puVar2 + 8;
      uVar1 = *(uint *)(&DAT_00c090e8 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_00c094e8 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_00c08ce8 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_00c098e8 + (uVar1 & 0xff) * 4) ^ puVar2[6];
      param_1 = param_1 - 0x20;
      uVar1 = *(uint *)(&DAT_00c090e8 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_00c094e8 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_00c08ce8 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_00c098e8 + (uVar1 & 0xff) * 4) ^ puVar2[7];
      uVar1 = *(uint *)(&DAT_00c090e8 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_00c094e8 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_00c08ce8 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_00c098e8 + (uVar1 & 0xff) * 4);
      uVar3 = uVar3 - 1;
      puVar2 = in_ECX;
    } while (uVar3 != 0);
  }
  if (3 < param_1) {
    uVar3 = param_1 >> 2;
    do {
      uVar1 = uVar1 ^ *in_ECX;
      in_ECX = in_ECX + 1;
      uVar1 = *(uint *)(&DAT_00c090e8 + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_00c094e8 + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_00c08ce8 + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_00c098e8 + (uVar1 & 0xff) * 4);
      param_1 = param_1 - 4;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  for (; param_1 != 0; param_1 = param_1 - 1) {
    uVar1 = uVar1 >> 8 ^ *(uint *)(&DAT_00c08ce8 + (((byte)*in_ECX ^ uVar1) & 0xff) * 4);
    in_ECX = (uint *)((int)in_ECX + 1);
  }
  return ~uVar1;
}

