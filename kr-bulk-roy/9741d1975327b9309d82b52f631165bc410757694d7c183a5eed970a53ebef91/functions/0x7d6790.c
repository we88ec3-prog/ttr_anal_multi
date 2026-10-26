
void FUN_007d6790(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,char param_10,char param_11,undefined4 param_12)

{
  char *unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x40) = param_2;
  *(undefined4 *)(unaff_ESI + 0x48) = param_4;
  *(undefined4 *)(unaff_ESI + 0x44) = param_3;
  *(undefined4 *)(unaff_ESI + 0x4c) = param_5;
  *(undefined4 *)(unaff_ESI + 100) = param_12;
  *(undefined4 *)(unaff_ESI + 0x50) = param_6;
  *(undefined4 *)(unaff_ESI + 0x54) = param_7;
  *(undefined4 *)(unaff_ESI + 0x58) = param_8;
  *(undefined4 *)(unaff_ESI + 0x5c) = param_9;
  unaff_ESI[0x60] = param_10;
  unaff_ESI[0x61] = param_11;
  _strncpy(unaff_ESI,param_1,0x40);
  return;
}

