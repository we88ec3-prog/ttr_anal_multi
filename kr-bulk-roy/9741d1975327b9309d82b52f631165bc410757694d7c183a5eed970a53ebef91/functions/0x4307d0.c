
undefined2 * FUN_004307d0(undefined2 *param_1)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  int in_ECX;
  
  psVar2 = *(short **)(in_ECX + 0x14);
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  psVar3 = psVar2;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar2,(int)psVar3 - (int)(psVar2 + 1) >> 1);
  return param_1;
}

