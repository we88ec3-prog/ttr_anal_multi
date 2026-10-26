
void FUN_00447f50(void)

{
  short sVar1;
  short *psVar2;
  undefined4 uVar3;
  short *in_EDX;
  undefined2 *unaff_ESI;
  
  psVar2 = in_EDX;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  uVar3 = FUN_00448090(0,in_EDX,(int)psVar2 - (int)(in_EDX + 1) >> 1);
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  FUN_00402800(uVar3);
  return;
}

