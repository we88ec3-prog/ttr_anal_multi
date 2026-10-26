
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_005cc140(void)

{
  short *psVar1;
  short sVar2;
  short *psVar3;
  
  if ((_DAT_00fc183c & 1) == 0) {
    _DAT_00fc183c = _DAT_00fc183c | 1;
    FUN_006f1ff0();
    DAT_00fc18d8 = 1;
    _atexit((_func_4879 *)&LAB_00bce3a0);
  }
  psVar3 = DAT_00fc186c;
  if (DAT_00fc1880 < 8) {
    psVar3 = (short *)&DAT_00fc186c;
  }
  psVar1 = psVar3 + 1;
  do {
    sVar2 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar2 != 0);
  return (int)psVar3 - (int)psVar1 >> 1 == 0;
}

