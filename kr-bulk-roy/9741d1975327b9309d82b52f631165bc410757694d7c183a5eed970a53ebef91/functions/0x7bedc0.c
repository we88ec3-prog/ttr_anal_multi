
void FUN_007bedc0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  int iVar2;
  char *unaff_ESI;
  
  iVar2 = FUN_00891268(0x5c);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    *(undefined4 *)(iVar2 + 0x40) = 0x3f800000;
    *(undefined4 *)(iVar2 + 0x44) = 0x3f800000;
    *(undefined4 *)(iVar2 + 0x48) = 0;
    *(undefined4 *)(iVar2 + 0x4c) = 0;
    *(undefined4 *)(iVar2 + 0x50) = 0;
    *(undefined4 *)(iVar2 + 0x58) = 0;
  }
  *(undefined4 *)(iVar2 + 0x40) = param_3;
  *(undefined4 *)(iVar2 + 0x44) = param_4;
  *(undefined4 *)(iVar2 + 0x48) = param_5;
  *(undefined4 *)(iVar2 + 0x4c) = param_6;
  *(undefined4 *)(iVar2 + 0x50) = param_7;
  *(undefined4 *)(iVar2 + 0x54) = param_2;
  iVar2 = iVar2 - (int)unaff_ESI;
  do {
    cVar1 = *unaff_ESI;
    unaff_ESI[iVar2] = cVar1;
    unaff_ESI = unaff_ESI + 1;
  } while (cVar1 != '\0');
  FUN_007bb350();
  return;
}

