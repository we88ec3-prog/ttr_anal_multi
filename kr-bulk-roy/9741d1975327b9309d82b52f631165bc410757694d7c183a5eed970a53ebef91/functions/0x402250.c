
void FUN_00402250(short *param_1)

{
  short sVar1;
  short *psVar2;
  undefined2 *in_ECX;
  
  *(undefined4 *)(in_ECX + 10) = 7;
  *(undefined4 *)(in_ECX + 8) = 0;
  *in_ECX = 0;
  psVar2 = param_1;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  FUN_00402160(param_1,(int)psVar2 - (int)(param_1 + 1) >> 1);
  return;
}

