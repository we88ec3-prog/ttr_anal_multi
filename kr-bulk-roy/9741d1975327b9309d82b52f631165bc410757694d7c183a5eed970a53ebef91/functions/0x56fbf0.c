
void FUN_0056fbf0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  undefined4 *in_EAX;
  short *psVar2;
  undefined4 *in_ECX;
  undefined4 *unaff_ESI;
  short *unaff_EDI;
  
  *unaff_ESI = param_1;
  unaff_ESI[1] = param_2;
  unaff_ESI[2] = param_3;
  *(undefined1 *)(unaff_ESI + 3) = 1;
  unaff_ESI[4] = *in_ECX;
  unaff_ESI[5] = in_ECX[1];
  unaff_ESI[6] = param_4;
  unaff_ESI[7] = *in_EAX;
  unaff_ESI[8] = in_EAX[1];
  unaff_ESI[0xe] = 7;
  unaff_ESI[0xd] = 0;
  *(undefined2 *)(unaff_ESI + 9) = 0;
  psVar2 = unaff_EDI;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  FUN_00402160(unaff_EDI,(int)psVar2 - (int)(unaff_EDI + 1) >> 1);
  unaff_ESI[0x10] = 0;
  unaff_ESI[0x11] = 0;
  return;
}

