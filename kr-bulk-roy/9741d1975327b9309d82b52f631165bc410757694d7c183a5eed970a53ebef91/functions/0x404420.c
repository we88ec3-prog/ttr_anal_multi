
void FUN_00404420(void)

{
  short sVar1;
  short *psVar2;
  short *in_EDX;
  
  psVar2 = in_EDX;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  FUN_00404300(in_EDX,(int)psVar2 - (int)(in_EDX + 1) >> 1);
  return;
}

