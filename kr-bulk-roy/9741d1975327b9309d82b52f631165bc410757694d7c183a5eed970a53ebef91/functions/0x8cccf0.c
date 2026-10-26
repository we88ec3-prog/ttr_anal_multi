
uint FUN_008cccf0(void)

{
  uint uVar1;
  uint uVar2;
  int in_EAX;
  uint *puVar3;
  int in_ECX;
  uint *puVar4;
  int in_EDX;
  byte *pbVar5;
  byte *pbVar6;
  
  puVar3 = (uint *)(in_EAX * 0x10 + *(int *)(in_EDX + 8));
  puVar4 = (uint *)(in_ECX * 0x10 + *(int *)(in_EDX + 8));
  pbVar5 = (byte *)puVar4[2];
  uVar1 = *puVar4;
  pbVar6 = (byte *)puVar3[2];
  uVar2 = *puVar3;
  if (uVar2 <= uVar1) {
    uVar1 = uVar2;
  }
  for (; 7 < uVar1; uVar1 = uVar1 - 8) {
    if ((*pbVar5 & *pbVar6) != 0) {
      return 1;
    }
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  }
  if (uVar1 == 0) {
    return 0;
  }
  return (uint)(*pbVar6 & *pbVar5) & ~(0xff >> ((byte)uVar1 & 0x1f));
}

