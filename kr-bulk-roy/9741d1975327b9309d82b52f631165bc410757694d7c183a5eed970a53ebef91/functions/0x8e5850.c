
void FUN_008e5850(short *param_1)

{
  short sVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *unaff_EBX;
  
  *param_1 = 0;
  *unaff_EBX = 0;
  sVar1 = FUN_008b9ab0();
  if (in_ECX == 0) {
    if ((sVar1 == -0x7fff) || (sVar1 == -0x7ffe)) {
      uVar2 = FUN_008b9c70();
      *unaff_EBX = uVar2;
    }
    *param_1 = sVar1;
  }
  return;
}

