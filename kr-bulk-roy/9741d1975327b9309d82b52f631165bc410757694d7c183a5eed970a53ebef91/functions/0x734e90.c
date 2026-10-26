
void FUN_00734e90(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  short *psVar2;
  undefined4 *unaff_ESI;
  short *unaff_EDI;
  
  *unaff_ESI = param_1;
  unaff_ESI[6] = 7;
  unaff_ESI[5] = 0;
  *(undefined2 *)(unaff_ESI + 1) = 0;
  psVar2 = unaff_EDI;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  FUN_00402160(unaff_EDI,(int)psVar2 - (int)(unaff_EDI + 1) >> 1);
  unaff_ESI[8] = param_2;
  unaff_ESI[0xd] = param_3;
  unaff_ESI[9] = 0;
  unaff_ESI[10] = 0;
  unaff_ESI[0xb] = 0;
  unaff_ESI[0xc] = 0;
  return;
}

