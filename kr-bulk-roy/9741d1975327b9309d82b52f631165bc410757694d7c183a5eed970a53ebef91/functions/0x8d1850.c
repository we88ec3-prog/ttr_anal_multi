
uint FUN_008d1850(uint *param_1,uint param_2,ushort *param_3)

{
  uint uVar1;
  uint uVar2;
  uint in_ECX;
  byte *in_EDX;
  int iVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = *param_3;
  uVar5 = (uint)uVar4;
  uVar1 = *param_1;
  if (uVar1 < in_ECX) {
    if (in_ECX - uVar1 < param_2) {
      param_2 = in_ECX - uVar1;
    }
    uVar6 = 0;
    if (param_2 != 0) {
      iVar3 = uVar1 - (int)in_EDX;
      uVar2 = param_2;
      do {
        uVar6 = (in_EDX[iVar3] + uVar5) * -0x3193 + 0x58bf;
        *in_EDX = (byte)(uVar5 >> 8) ^ in_EDX[iVar3];
        uVar5 = uVar6 & 0xffff;
        uVar4 = (ushort)uVar6;
        in_EDX = in_EDX + 1;
        uVar2 = uVar2 - 1;
        uVar6 = param_2;
      } while (uVar2 != 0);
    }
    *param_1 = uVar1 + param_2;
    *param_3 = uVar4;
    return uVar6;
  }
  return 0;
}

