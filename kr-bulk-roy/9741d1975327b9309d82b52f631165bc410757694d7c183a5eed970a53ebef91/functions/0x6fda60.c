
void FUN_006fda60(void)

{
  int iVar1;
  undefined4 in_EAX;
  undefined4 uVar2;
  undefined4 *in_ECX;
  int unaff_EDI;
  
  switch(in_EAX) {
  case 2:
  case 3:
    iVar1 = *(int *)(unaff_EDI + 8);
    *in_ECX = *(undefined4 *)(iVar1 + -0x10);
    in_ECX[1] = *(undefined4 *)(iVar1 + -0xc);
    in_ECX[2] = *(undefined4 *)(iVar1 + -8);
  default:
    *(undefined4 **)(unaff_EDI + 8) = in_ECX + 4;
    return;
  case 4:
    break;
  case 5:
  }
  uVar2 = FUN_006fec70();
  *in_ECX = uVar2;
  in_ECX[2] = 4;
  *(undefined4 **)(unaff_EDI + 8) = in_ECX + 4;
  return;
}

