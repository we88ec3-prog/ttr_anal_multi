
undefined4 * FUN_00580d10(int param_1)

{
  int iVar1;
  int in_EAX;
  undefined4 *in_ECX;
  int iVar2;
  
  if (in_EAX != param_1) {
    iVar2 = in_EAX + 8;
    do {
      *in_ECX = *(undefined4 *)(iVar2 + -8);
      in_ECX[1] = *(undefined4 *)(iVar2 + -4);
      FUN_00403040(iVar2,0,0xffffffff);
      FUN_00571f70(iVar2 + 0x1c);
      iVar1 = iVar2 + 0x2c;
      in_ECX = in_ECX + 0xd;
      iVar2 = iVar2 + 0x34;
    } while (iVar1 != param_1);
  }
  return in_ECX;
}

