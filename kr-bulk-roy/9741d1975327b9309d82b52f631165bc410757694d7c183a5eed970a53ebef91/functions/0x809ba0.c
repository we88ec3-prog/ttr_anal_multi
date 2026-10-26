
void FUN_00809ba0(int *param_1)

{
  uint uVar1;
  int iVar2;
  int *in_EAX;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = param_1[1];
  uVar6 = param_1[2];
  uVar5 = (~uVar1 & param_1[3] | uVar6 & uVar1) + *in_EAX + -0x28955b88 + *param_1;
  uVar3 = (uVar5 * 0x80 | uVar5 >> 0x19) + uVar1;
  uVar5 = (~uVar3 & uVar6 | uVar1 & uVar3) + in_EAX[1] + -0x173848aa + param_1[3];
  uVar4 = (uVar5 * 0x1000 | uVar5 >> 0x14) + uVar3;
  uVar6 = (~uVar4 & uVar1 | uVar4 & uVar3) + in_EAX[2] + 0x242070db + uVar6;
  uVar6 = (uVar6 >> 0xf | uVar6 * 0x20000) + uVar4;
  uVar5 = (~uVar6 & uVar3 | uVar4 & uVar6) + in_EAX[3] + -0x3e423112 + param_1[1];
  uVar5 = (uVar5 >> 10 | uVar5 * 0x400000) + uVar6;
  uVar3 = (~uVar5 & uVar4 | uVar6 & uVar5) + in_EAX[4] + -0xa83f051 + uVar3;
  uVar3 = (uVar3 * 0x80 | uVar3 >> 0x19) + uVar5;
  uVar4 = (~uVar3 & uVar6 | uVar5 & uVar3) + in_EAX[5] + 0x4787c62a + uVar4;
  uVar4 = (uVar4 * 0x1000 | uVar4 >> 0x14) + uVar3;
  uVar6 = (~uVar4 & uVar5 | uVar4 & uVar3) + in_EAX[6] + -0x57cfb9ed + uVar6;
  uVar6 = (uVar6 >> 0xf | uVar6 * 0x20000) + uVar4;
  uVar5 = (~uVar6 & uVar3 | uVar4 & uVar6) + in_EAX[7] + -0x2b96aff + uVar5;
  uVar5 = (uVar5 >> 10 | uVar5 * 0x400000) + uVar6;
  uVar3 = (~uVar5 & uVar4 | uVar6 & uVar5) + in_EAX[8] + 0x698098d8 + uVar3;
  uVar3 = (uVar3 * 0x80 | uVar3 >> 0x19) + uVar5;
  uVar4 = (~uVar3 & uVar6 | uVar5 & uVar3) + in_EAX[9] + -0x74bb0851 + uVar4;
  uVar4 = (uVar4 * 0x1000 | uVar4 >> 0x14) + uVar3;
  uVar6 = (~uVar4 & uVar5 | uVar4 & uVar3) + in_EAX[10] + -0xa44f + uVar6;
  uVar6 = (uVar6 >> 0xf | uVar6 * 0x20000) + uVar4;
  uVar5 = (~uVar6 & uVar3 | uVar4 & uVar6) + in_EAX[0xb] + -0x76a32842 + uVar5;
  uVar5 = (uVar5 >> 10 | uVar5 * 0x400000) + uVar6;
  uVar3 = (~uVar5 & uVar4 | uVar6 & uVar5) + in_EAX[0xc] + 0x6b901122 + uVar3;
  uVar3 = (uVar3 * 0x80 | uVar3 >> 0x19) + uVar5;
  uVar4 = (~uVar3 & uVar6 | uVar5 & uVar3) + in_EAX[0xd] + -0x2678e6d + uVar4;
  uVar4 = (uVar4 * 0x1000 | uVar4 >> 0x14) + uVar3;
  uVar6 = (~uVar4 & uVar5 | uVar4 & uVar3) + in_EAX[0xe] + -0x5986bc72 + uVar6;
  uVar6 = (uVar6 >> 0xf | uVar6 * 0x20000) + uVar4;
  uVar5 = (~uVar6 & uVar3 | uVar4 & uVar6) + in_EAX[0xf] + 0x49b40821 + uVar5;
  uVar5 = (uVar5 >> 10 | uVar5 * 0x400000) + uVar6;
  uVar3 = (~uVar4 & uVar6 | uVar4 & uVar5) + in_EAX[1] + -0x9e1da9e + uVar3;
  uVar3 = (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar5;
  uVar4 = (~uVar6 & uVar5 | uVar6 & uVar3) + in_EAX[6] + -0x3fbf4cc0 + uVar4;
  uVar4 = (uVar4 * 0x200 | uVar4 >> 0x17) + uVar3;
  uVar6 = (~uVar5 & uVar3 | uVar4 & uVar5) + in_EAX[0xb] + 0x265e5a51 + uVar6;
  uVar6 = (uVar6 * 0x4000 | uVar6 >> 0x12) + uVar4;
  uVar5 = (~uVar3 & uVar4 | uVar6 & uVar3) + *in_EAX + -0x16493856 + uVar5;
  uVar5 = (uVar5 >> 0xc | uVar5 * 0x100000) + uVar6;
  uVar3 = (~uVar4 & uVar6 | uVar4 & uVar5) + in_EAX[5] + -0x29d0efa3 + uVar3;
  uVar3 = (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar5;
  uVar4 = (~uVar6 & uVar5 | uVar6 & uVar3) + in_EAX[10] + 0x2441453 + uVar4;
  uVar4 = (uVar4 * 0x200 | uVar4 >> 0x17) + uVar3;
  uVar6 = (~uVar5 & uVar3 | uVar4 & uVar5) + in_EAX[0xf] + -0x275e197f + uVar6;
  uVar6 = (uVar6 * 0x4000 | uVar6 >> 0x12) + uVar4;
  uVar5 = (~uVar3 & uVar4 | uVar6 & uVar3) + in_EAX[4] + -0x182c0438 + uVar5;
  uVar5 = (uVar5 >> 0xc | uVar5 * 0x100000) + uVar6;
  uVar3 = (~uVar4 & uVar6 | uVar4 & uVar5) + in_EAX[9] + 0x21e1cde6 + uVar3;
  uVar3 = (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar5;
  uVar4 = (~uVar6 & uVar5 | uVar6 & uVar3) + in_EAX[0xe] + -0x3cc8f82a + uVar4;
  uVar4 = (uVar4 * 0x200 | uVar4 >> 0x17) + uVar3;
  uVar6 = (~uVar5 & uVar3 | uVar4 & uVar5) + in_EAX[3] + -0xb2af279 + uVar6;
  uVar6 = (uVar6 * 0x4000 | uVar6 >> 0x12) + uVar4;
  uVar5 = (~uVar3 & uVar4 | uVar6 & uVar3) + in_EAX[8] + 0x455a14ed + uVar5;
  uVar5 = (uVar5 >> 0xc | uVar5 * 0x100000) + uVar6;
  uVar3 = (~uVar4 & uVar6 | uVar4 & uVar5) + in_EAX[0xd] + -0x561c16fb + uVar3;
  uVar3 = (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar5;
  iVar2 = in_EAX[2];
  uVar4 = (~uVar6 & uVar5 | uVar6 & uVar3) + iVar2 + -0x3105c08 + uVar4;
  uVar4 = (uVar4 * 0x200 | uVar4 >> 0x17) + uVar3;
  uVar6 = (~uVar5 & uVar3 | uVar4 & uVar5) + in_EAX[7] + 0x676f02d9 + uVar6;
  uVar6 = (uVar6 * 0x4000 | uVar6 >> 0x12) + uVar4;
  uVar5 = (~uVar3 & uVar4 | uVar6 & uVar3) + in_EAX[0xc] + -0x72d5b376 + uVar5;
  uVar5 = (uVar5 >> 0xc | uVar5 * 0x100000) + uVar6;
  uVar3 = (uVar4 ^ uVar6 ^ uVar5) + in_EAX[5] + -0x5c6be + uVar3;
  uVar3 = (uVar3 * 0x10 | uVar3 >> 0x1c) + uVar5;
  uVar4 = (uVar6 ^ uVar5 ^ uVar3) + in_EAX[8] + -0x788e097f + uVar4;
  uVar4 = (uVar4 * 0x800 | uVar4 >> 0x15) + uVar3;
  uVar6 = (uVar4 ^ uVar5 ^ uVar3) + in_EAX[0xb] + 0x6d9d6122 + uVar6;
  uVar6 = (uVar6 * 0x10000 | uVar6 >> 0x10) + uVar4;
  uVar5 = (uVar4 ^ uVar6 ^ uVar3) + in_EAX[0xe] + -0x21ac7f4 + uVar5;
  uVar5 = (uVar5 >> 9 | uVar5 * 0x800000) + uVar6;
  uVar3 = (uVar4 ^ uVar6 ^ uVar5) + in_EAX[1] + -0x5b4115bc + uVar3;
  uVar3 = (uVar3 * 0x10 | uVar3 >> 0x1c) + uVar5;
  uVar4 = (uVar6 ^ uVar5 ^ uVar3) + in_EAX[4] + 0x4bdecfa9 + uVar4;
  uVar4 = (uVar4 * 0x800 | uVar4 >> 0x15) + uVar3;
  uVar6 = (uVar4 ^ uVar5 ^ uVar3) + in_EAX[7] + -0x944b4a0 + uVar6;
  uVar6 = (uVar6 * 0x10000 | uVar6 >> 0x10) + uVar4;
  uVar5 = (uVar4 ^ uVar6 ^ uVar3) + in_EAX[10] + -0x41404390 + uVar5;
  uVar5 = (uVar5 >> 9 | uVar5 * 0x800000) + uVar6;
  uVar3 = (uVar4 ^ uVar6 ^ uVar5) + in_EAX[0xd] + 0x289b7ec6 + uVar3;
  uVar3 = (uVar3 * 0x10 | uVar3 >> 0x1c) + uVar5;
  uVar4 = (uVar6 ^ uVar5 ^ uVar3) + *in_EAX + -0x155ed806 + uVar4;
  uVar4 = (uVar4 * 0x800 | uVar4 >> 0x15) + uVar3;
  uVar6 = (uVar4 ^ uVar5 ^ uVar3) + in_EAX[3] + -0x2b10cf7b + uVar6;
  uVar6 = (uVar6 * 0x10000 | uVar6 >> 0x10) + uVar4;
  uVar5 = (uVar4 ^ uVar6 ^ uVar3) + in_EAX[6] + 0x4881d05 + uVar5;
  uVar5 = (uVar5 >> 9 | uVar5 * 0x800000) + uVar6;
  uVar3 = (uVar4 ^ uVar6 ^ uVar5) + in_EAX[9] + -0x262b2fc7 + uVar3;
  uVar3 = (uVar3 * 0x10 | uVar3 >> 0x1c) + uVar5;
  uVar4 = (uVar6 ^ uVar5 ^ uVar3) + in_EAX[0xc] + -0x1924661b + uVar4;
  uVar4 = (uVar4 * 0x800 | uVar4 >> 0x15) + uVar3;
  uVar6 = (uVar4 ^ uVar5 ^ uVar3) + in_EAX[0xf] + 0x1fa27cf8 + uVar6;
  uVar6 = (uVar6 * 0x10000 | uVar6 >> 0x10) + uVar4;
  uVar5 = (uVar4 ^ uVar6 ^ uVar3) + iVar2 + -0x3b53a99b + uVar5;
  uVar5 = (uVar5 >> 9 | uVar5 * 0x800000) + uVar6;
  uVar3 = ((~uVar4 | uVar5) ^ uVar6) + *in_EAX + -0xbd6ddbc + uVar3;
  uVar3 = (uVar3 * 0x40 | uVar3 >> 0x1a) + uVar5;
  uVar4 = ((~uVar6 | uVar3) ^ uVar5) + in_EAX[7] + 0x432aff97 + uVar4;
  uVar4 = (uVar4 * 0x400 | uVar4 >> 0x16) + uVar3;
  uVar6 = ((~uVar5 | uVar4) ^ uVar3) + in_EAX[0xe] + -0x546bdc59 + uVar6;
  uVar6 = (uVar6 * 0x8000 | uVar6 >> 0x11) + uVar4;
  uVar5 = ((~uVar3 | uVar6) ^ uVar4) + in_EAX[5] + -0x36c5fc7 + uVar5;
  uVar5 = (uVar5 >> 0xb | uVar5 * 0x200000) + uVar6;
  uVar3 = ((~uVar4 | uVar5) ^ uVar6) + in_EAX[0xc] + 0x655b59c3 + uVar3;
  uVar3 = (uVar3 * 0x40 | uVar3 >> 0x1a) + uVar5;
  uVar4 = ((~uVar6 | uVar3) ^ uVar5) + in_EAX[3] + -0x70f3336e + uVar4;
  uVar4 = (uVar4 * 0x400 | uVar4 >> 0x16) + uVar3;
  uVar6 = ((~uVar5 | uVar4) ^ uVar3) + in_EAX[10] + -0x100b83 + uVar6;
  uVar6 = (uVar6 * 0x8000 | uVar6 >> 0x11) + uVar4;
  uVar5 = ((~uVar3 | uVar6) ^ uVar4) + in_EAX[1] + -0x7a7ba22f + uVar5;
  uVar5 = (uVar5 >> 0xb | uVar5 * 0x200000) + uVar6;
  uVar3 = ((~uVar4 | uVar5) ^ uVar6) + in_EAX[8] + 0x6fa87e4f + uVar3;
  uVar3 = (uVar3 * 0x40 | uVar3 >> 0x1a) + uVar5;
  uVar4 = ((~uVar6 | uVar3) ^ uVar5) + in_EAX[0xf] + -0x1d31920 + uVar4;
  uVar4 = (uVar4 * 0x400 | uVar4 >> 0x16) + uVar3;
  uVar6 = ((~uVar5 | uVar4) ^ uVar3) + in_EAX[6] + -0x5cfebcec + uVar6;
  uVar6 = (uVar6 * 0x8000 | uVar6 >> 0x11) + uVar4;
  uVar5 = ((~uVar3 | uVar6) ^ uVar4) + in_EAX[0xd] + 0x4e0811a1 + uVar5;
  uVar5 = (uVar5 >> 0xb | uVar5 * 0x200000) + uVar6;
  uVar3 = ((~uVar4 | uVar5) ^ uVar6) + in_EAX[4] + -0x8ac817e + uVar3;
  uVar3 = (uVar3 * 0x40 | uVar3 >> 0x1a) + uVar5;
  uVar4 = ((~uVar6 | uVar3) ^ uVar5) + in_EAX[0xb] + -0x42c50dcb + uVar4;
  uVar4 = (uVar4 * 0x400 | uVar4 >> 0x16) + uVar3;
  uVar6 = ((~uVar5 | uVar4) ^ uVar3) + iVar2 + 0x2ad7d2bb + uVar6;
  uVar6 = (uVar6 * 0x8000 | uVar6 >> 0x11) + uVar4;
  uVar5 = ((~uVar3 | uVar6) ^ uVar4) + in_EAX[9] + -0x14792c6f + uVar5;
  param_1[1] = param_1[1] + (uVar5 >> 0xb | uVar5 * 0x200000) + uVar6;
  param_1[2] = param_1[2] + uVar6;
  *param_1 = *param_1 + uVar3;
  param_1[3] = param_1[3] + uVar4;
  return;
}

