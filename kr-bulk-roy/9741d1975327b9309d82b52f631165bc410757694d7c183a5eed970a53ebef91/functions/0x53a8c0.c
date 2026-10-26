
undefined4 FUN_0053a8c0(int param_1)

{
  short sVar1;
  short *psVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x5ed8) != 0) {
    psVar2 = (short *)(param_1 + 2);
    do {
      sVar1 = *psVar2;
      psVar2 = psVar2 + 1;
    } while (sVar1 != 0);
    FUN_00402160((short *)(param_1 + 2),(int)psVar2 - (param_1 + 4) >> 1);
    *(uint *)(*(int *)(in_ECX + 0x5ed8) + 0x20) = (uint)*(byte *)(param_1 + 0x2c);
  }
  return 0;
}

