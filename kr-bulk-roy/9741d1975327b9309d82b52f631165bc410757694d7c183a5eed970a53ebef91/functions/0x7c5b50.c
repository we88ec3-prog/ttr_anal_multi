
void FUN_007c5b50(uint param_1,char param_2)

{
  short *psVar1;
  byte bVar2;
  int in_EAX;
  int iVar3;
  uint in_ECX;
  byte *pbVar4;
  
  iVar3 = param_1;
  param_1 = in_EAX << 0x10 | in_ECX & 0xffff;
  FUN_0082ef00(&param_1);
  if (in_ECX != *(uint *)(iVar3 + 0xb8)) {
    param_1 = *(int *)(in_ECX + 0x10);
    pbVar4 = *(byte **)(param_1 + 0x28);
    if (pbVar4 != *(byte **)(param_1 + 0x2c)) {
      do {
        bVar2 = *pbVar4;
        iVar3 = FUN_007c4af0(pbVar4 + 1);
        if ((iVar3 != 0) &&
           ((uint)bVar2 < (uint)(*(int *)(iVar3 + 0x24) - *(int *)(iVar3 + 0x20) >> 2))) {
          psVar1 = (short *)(*(int *)(*(int *)(iVar3 + 0x20) + (uint)bVar2 * 4) + 0x54);
          *psVar1 = *psVar1 + (short)param_2;
        }
        pbVar4 = pbVar4 + 0x68;
      } while (pbVar4 != *(byte **)(param_1 + 0x2c));
    }
  }
  return;
}

