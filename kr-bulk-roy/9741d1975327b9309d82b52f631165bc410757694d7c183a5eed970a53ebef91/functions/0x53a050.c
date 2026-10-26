
undefined4 FUN_0053a050(int param_1)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  
  iVar2 = FUN_0053a960();
  psVar3 = (short *)(param_1 + 2);
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  FUN_00402160((short *)(param_1 + 2),(int)psVar3 - (param_1 + 4) >> 1);
  *(uint *)(iVar2 + 0x20) = (uint)*(byte *)(param_1 + 0x2c);
  *(uint *)(iVar2 + 0x24) = (uint)*(ushort *)(param_1 + 0x2d);
  return 0;
}

